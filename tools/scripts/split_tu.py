#!/usr/bin/env python3
"""split a dump into named objects at given <address>:<name> boundaries"""

import argparse
import fnmatch
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import split_dump as sd

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SYM_GLOBS_RE = re.compile(r'^SYM_GLOBS\s*:=\s*(.*)$', re.M)


def sym_globs():
    """the asm patterns the Makefile keeps functions from"""
    try:
        m = SYM_GLOBS_RE.search(open(os.path.join(ROOT, 'Makefile')).read())
    except OSError:
        return []
    return re.findall(r"'([^']+)'", m.group(1)) if m else []


WORD_REF_RE = re.compile(r'^(\w+:\s*\.word\s+)(\w+)\s*(?:([+-])\s*(\d+|0x[0-9A-Fa-f]+))?(\s*(?:[;@].*)?)$')


def thumb_data_labels(body):
    """non-function labels assembled in thumb mode, which the assembler gives the thumb bit"""
    out = set()
    mode = None
    funcs = set()
    for l in body:
        m = sd.FUNC_START_RE.match(l)
        if m:
            mode = 'thumb' if 'thumb' in m.group(1) else 'arm'
            funcs.update(l.split()[1:2])
            continue
        m = re.match(r'^(\w+):', l)
        if m and mode == 'thumb' and m.group(1) not in funcs:
            out.add(m.group(1))
    return out


def rebase_thumb_refs(lines, imported):
    """keep .word references to imported thumb-mode labels at the value they had in one object"""
    out = []
    for l in lines:
        m = WORD_REF_RE.match(l)
        if m and m.group(2) in imported:
            offset = int(m.group(4), 0) * (-1 if m.group(3) == '-' else 1) if m.group(3) else 0
            offset += 1
            tail = f' + {offset}' if offset > 0 else f' - {-offset}' if offset < 0 else ''
            l = f'{m.group(1)}{m.group(2)}{tail}{m.group(5)}'
        out.append(l)
    return out


def already_global(lines, sym):
    """whether the piece already exports sym through a func_start macro or .global"""
    for l in lines:
        m = sd.FUNC_START_RE.match(l)
        if m and sym in l.split():
            return True
        if l.strip() == f'.global {sym}':
            return True
    return False


def candidates(lines):
    """index -> address for every legal boundary candidate"""
    out = {}
    for i, l in enumerate(lines):
        if sd.FUNC_START_RE.match(l):
            for nxt in lines[i:i + 3]:
                m = sd.LABEL_ADDR_RE.match(nxt) or sd.BARE_LABEL_RE.match(nxt)
                if m:
                    out[i] = int(m.group(1), 16)
                    break
        else:
            m = sd.LABEL_ADDR_RE.match(l) or sd.BARE_LABEL_RE.match(l)
            if m:
                out.setdefault(i, int(m.group(1), 16))
    return out


def valid_points(lines):
    """indices where an object boundary may legally fall (see split_dump)"""
    cand = candidates(lines)
    definition = {}
    for i, l in enumerate(lines):
        m = re.match(r'^(\w+):', l)
        if m:
            definition.setdefault(m.group(1), i)
    reach = [0] * (len(lines) + 1)
    for i, l in enumerate(lines):
        code = re.split(r'[;@]', l)[0]
        operands = code.split(':', 1)[1] if ':' in code else code
        hit = sd.PC_RELATIVE_RE.match(operands.strip()) or \
              sd.LOCAL_BRANCH_RE.match(operands.strip())
        if not hit:
            continue
        where = definition.get(hit.group(2))
        if where is None:
            continue
        lo, hi = min(i, where), max(i, where) + 1
        reach[lo] = max(reach[lo], hi)
    furthest = 0
    valid = set()
    for i in range(len(lines)):
        if i >= furthest and i in cand and cand[i] % 4 == 0:
            valid.add(i)
        furthest = max(furthest, reach[i])
    return valid


def index_of_address(lines, addr):
    """index of the boundary candidate that begins at addr"""
    for i, a in sorted(candidates(lines).items()):
        if a == addr:
            return i
    return None


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('source')
    p.add_argument('--outdir', required=True)
    p.add_argument('--boundary', action='append', required=True,
                   metavar='ADDR:NAME', help="0x021B6100:battle_server")
    p.add_argument('--macros', default='macros/function.inc')
    p.add_argument('--lsf')
    p.add_argument('--dry-run', action='store_true')
    args = p.parse_args()

    raw = open(args.source).read().splitlines()
    tstart = next(i for i, l in enumerate(raw) if l.strip() == '.text')
    dstart = next((i for i, l in enumerate(raw) if '.section .data' in l), len(raw))
    body = raw[tstart + 1:dstart]
    trailer = raw[dstart:]

    valid = valid_points(body)
    thumb_labels = thumb_data_labels(body)
    bounds = []
    for spec in args.boundary:
        a, name = spec.split(':')
        bounds.append((int(a, 16), name))
    bounds.sort()

    cuts = []
    for addr, name in bounds:
        if addr == sd.first_address(body):
            cuts.append((0, name)); continue
        i = index_of_address(body, addr)
        if i is None:
            sys.exit(f"error: address {addr:#010x} not found")
        if i not in valid:
            near = sorted(valid, key=lambda v: abs(v - i))[:3]
            hint = ", ".join(f"{sd.first_address(body[v:v+4]):#010x}" for v in near)
            sys.exit(f"error: {addr:#010x} ({name}) is not a legal split point; "
                     f"nearest legal: {hint}")
        cuts.append((i, name))

    ranges = []
    for k, (i, name) in enumerate(cuts):
        end = cuts[k + 1][0] if k + 1 < len(cuts) else len(body)
        ranges.append((i, end, name))

    all_defined = sd.defined_symbols(raw)
    header_externs = [l for l in raw[:tstart] if l.strip().startswith('.extern')]
    TOKEN = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')

    def refs(chunk):
        out = set()
        for l in chunk:
            code = re.split(r'[;@]', l)[0]
            toks = code.split()
            if toks and toks[0] in sd.DIRECTIVES:
                continue
            if ':' in code:
                code = code.split(':', 1)[1]
            out.update(TOKEN.findall(code))
        return out
    pieces = []
    for k, (s, e, name) in enumerate(ranges):
        chunk = body[s:e]
        if not any(x.strip() for x in chunk):
            continue
        full = chunk + trailer if k == len(ranges) - 1 else chunk
        local = sd.defined_symbols(full)
        need = {x for x in refs(full) if x not in local and x in all_defined}
        pieces.append((k, name, chunk, full, local, need))

    globs = sym_globs()
    for _, name, _, _, _, _ in pieces:
        path = f'asm/{name}.s'
        if globs and not any(fnmatch.fnmatch(path, g) for g in globs):
            print(f"warning: {path} matches no SYM_GLOBS pattern in the Makefile, "
                  f"so the linker will drop its functions", file=sys.stderr)

    os.makedirs(args.outdir, exist_ok=True)
    written = []
    for k, name, chunk, full, local, need in pieces:
        wanted = set().union(*(p[5] for p in pieces if p[1] != name))
        exports = sorted(x for x in local & wanted if not already_global(full, x))
        out = [f'\t.include "{args.macros}"', '']
        out += header_externs
        for sym in sorted(need):
            out.append(f'\t.extern {sym}')
        for sym in exports:
            out.append(f'\t.global {sym}')
        out += ['', '\t.text', '']
        if not any(sd.FUNC_START_RE.match(x) for x in chunk):
            out += [f'\t.global {name}', f'{name}:']
        out += rebase_thumb_refs(chunk, need & thumb_labels)
        if k == len(ranges) - 1:
            out += [''] + rebase_thumb_refs(trailer, need & thumb_labels)
        if not args.dry_run:
            open(os.path.join(args.outdir, name + '.s'), 'w').write("\n".join(out) + "\n")
        written.append((sd.first_address(chunk), name, len(chunk)))

    for a, n, c in written:
        print(f"  {a:#010x}  {n+'.s':<26} {c:6d} lines")
    print(f"{len(written)} objects -> {args.outdir}")
    if args.lsf and not args.dry_run:
        with open(args.lsf, 'w') as h:
            for _, n, _ in written:
                h.write(f"\tObject\t\tasm/{n}.o\n")
        print(f"lsf block -> {args.lsf}")
    return 0


if __name__ == '__main__':
    sys.exit(main())

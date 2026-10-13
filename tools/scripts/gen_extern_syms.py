#!/usr/bin/env python3
"""emit LCF symbol definitions for addresses the ARM9 calls but does not define"""

import argparse
import bisect
import glob
import os
import re
import sys

EXTERN_RE = re.compile(r'^\s*\.extern\s+(\S+)\s*$')
LABEL_RE = re.compile(r'^(\w+):')
ADDRESSED_RE = re.compile(r'^(?:FUN_|ADDR_|_)([0-9A-Fa-f]{8})(?:_dup\d+)?(?:_o(\d+))?$')

# libsyscall.a types these thumb, an absolute LCF symbol cannot and blx needs it
PROVIDED_RE = re.compile(r'^SVC_\w+$')

# decompiled functions get renamed off FUN_<addr>, so match any call target
C_SYMBOL_RE = re.compile(r'\b([A-Za-z_]\w*)\s*\(')

# a GLOBAL_ASM block defines its symbol in the .s it names, not in the C
GLOBAL_ASM_RE = re.compile(r'GLOBAL_ASM\("([^"]+)"\)')
GLABEL_RE = re.compile(r'^\s*glabel(?:_arm)?\s+(\S+)')


def main():
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('sources', nargs='+')
    parser.add_argument('--provided', nargs='*', default=[], help="linked C sources; the symbols they define are resolved by the linker, not by an LCF address")
    parser.add_argument('--overlay-delta', help="file of '<overlay id> <delta>' lines, names ending in _o<id> move by that delta in this version")
    parser.add_argument('--overlay-shift', help="file of '<overlay id> <start> <delta>' lines, piecewise moves inside one overlay")
    parser.add_argument('--shift', help="file of '<start> <delta>' lines, addresses from start on move by delta in this version")
    parser.add_argument('-o', '--output', required=True)
    args = parser.parse_args()

    steps = []
    if args.shift:
        for line in open(args.shift):
            fields = line.split()
            if len(fields) == 2:
                steps.append((int(fields[0], 16), int(fields[1], 16)))
        steps.sort()

    deltas = {}
    if args.overlay_delta:
        for line in open(args.overlay_delta):
            fields = line.split()
            if len(fields) == 2:
                deltas[int(fields[0])] = int(fields[1], 16)

    pieces = {}
    if args.overlay_shift:
        for line in open(args.overlay_shift):
            fields = line.split()
            if len(fields) == 3:
                pieces.setdefault(int(fields[0]), []).append((int(fields[1], 16), int(fields[2], 16)))
        for table in pieces.values():
            table.sort()

    def inside(overlay, address):
        table = pieces[overlay]
        index = bisect.bisect_right([start for start, _ in table], address) - 1
        return address + (table[index][1] if index >= 0 else 0)

    def moved(address):
        index = bisect.bisect_right([start for start, _ in steps], address) - 1
        return address + steps[index][1] if index >= 0 else address

    paths = []
    for pattern in args.sources:
        paths.extend(sorted(glob.glob(pattern)) or [pattern])

    defined = set()
    referenced = set()
    for path in paths:
        if not os.path.exists(path):
            continue
        for line in open(path):
            m = LABEL_RE.match(line)
            if m:
                defined.add(m.group(1))
                continue
            m = EXTERN_RE.match(line)
            if m:
                referenced.add(m.group(1))

    # carved functions are .extern in asm but defined in C, so the linker supplies them
    provided = set()
    for path in args.provided:
        if not os.path.exists(path):
            continue
        text = open(path).read()
        provided.update(C_SYMBOL_RE.findall(text))
        for asm in GLOBAL_ASM_RE.findall(text):
            if os.path.exists(asm):
                provided.update(m.group(1) for line in open(asm) if (m := GLABEL_RE.match(line)))

    undefined = sorted(referenced - defined - provided)
    resolvable = []
    unresolvable = []
    for name in undefined:
        if PROVIDED_RE.match(name):
            continue
        m = ADDRESSED_RE.match(name)
        if m:
            overlay = int(m.group(2)) if m.group(2) else None
            address = int(m.group(1), 16)
            if overlay is not None and overlay in pieces:
                resolvable.append((name, inside(overlay, address)))
            elif overlay is not None and overlay in deltas:
                resolvable.append((name, address + deltas[overlay]))
            else:
                resolvable.append((name, moved(address)))
        else:
            unresolvable.append(name)

    with open(args.output, 'w') as handle:
        for name, address in resolvable:
            handle.write(f"\t{name} = 0x{address:08X};\n")

    print(f"{len(resolvable)} symbols -> {args.output}")
    if unresolvable:
        print(f"warning: {len(unresolvable)} references carry no address and "
              f"cannot be defined: {', '.join(unresolvable[:8])}")
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())

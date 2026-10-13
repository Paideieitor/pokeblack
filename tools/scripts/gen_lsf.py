#!/usr/bin/env python3
"""rewrite the overlay load addresses of a linker spec for one version"""

import argparse
import re
import sys

BLOCK = re.compile(r'^(Overlay OVY_(\d+)\s*\n\{\s*\n\s*Address\s+)(0x[0-9A-Fa-f]+)', re.M)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('lsf')
    parser.add_argument('bases', help="file of '<overlay id> <address>' lines")
    parser.add_argument('-o', '--output', required=True)
    args = parser.parse_args()

    bases = {}
    for line in open(args.bases):
        fields = line.split()
        if len(fields) == 2:
            bases[int(fields[0])] = fields[1]

    text = open(args.lsf).read()
    missing = []

    def swap(match):
        index = int(match.group(2))
        if index not in bases:
            return match.group(0)
        return match.group(1) + bases[index].lower()

    result = BLOCK.sub(swap, text)
    for index in bases:
        if f"Overlay OVY_{index}\n" not in text:
            missing.append(index)
    if missing:
        sys.exit(f"error: overlays not in {args.lsf}: {missing}")

    with open(args.output, 'w') as handle:
        handle.write(result)
    print(f"{len(bases)} overlay bases -> {args.output}")
    return 0


if __name__ == '__main__':
    sys.exit(main())

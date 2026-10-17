# Contributing to pokeblack

## Submitting changes

To contribute to this repo, fork it to your account, make changes in your fork, then make a pull request back to the main repo.

Any change must keep the ROMs matching, such that `make` and `make white` build the same ROMs as the original Pokémon Black and Pokémon White. Each build ends with `ROM matches <version>.us/rom.sha1` when it does. If it fails with `sha1sum: WARNING: 1 computed checksum did NOT match`, or fails to build at all, fix your changes before submitting them.

Hash checking is on by default. Do not switch it off with `COMPARE=0` in order to get a clean build.

## What can I help out with?

The ROM is fully reproduced from the assembly in this repo, but nearly all of that assembly is still raw disassembly under placeholder names. The work from here is turning it into something readable:

- Decompiling functions from `asm/` into C in `src/`. 28,721 functions are dumped, so there is no shortage.
- Naming symbols. `ndsdisasm_config/arm9_config.cfg` for example still calls 1,270 of its 1,302 functions `FUN_<address>`.
- Separating data from code in the dumps. `tools/scripts/find_holes.py` reports function prologues still sitting inside runs the disassembler treated as data.
- Extracting game data from the packed archives in `files/` into source under `res/`.

Read [INSTALL.md](INSTALL.md) first and get a matching build before starting.

## AI Policy

pokeblack does not accept submissions that were written in part or whole by an LLM agent. The only permitted exception is menial repetitive work that does not involve any kind of direct reverse engineering or "prose"/documentation/comments. PRs that contain an AI agent as a coauthor will be automatically rejected. Please visit our Discord for more information on this policy. 

## Decompiling

Decompile one original source file at a time. Most of `asm/` is still cut into runs by address, so first split a module into one `.s` per source file:

1. Find the files. Assert macros leave GameFreak's filenames in `.data`, and a function that loads one belongs to that file. In overlay 93 the order of these strings was also the link order.
2. Narrow each file's start to a window between those anchors. A drop in object size in `.rodata` also marks a new file, since CodeWarrior sorts each file's `.rodata` small to large.
3. Within a window, cut where the fewest calls cross. Name a stretch with no evidence after its address instead of guessing.
4. Split with `tools/scripts/split_tu.py`, running `--dry-run` first. Output names must match `SYM_GLOBS` in the Makefile. Replace the module's object in `main.lsf` with the `--lsf` block, delete `build/`, and check `make` and `make white`.

Any legal cut builds a matching ROM, so the match does not prove the boundaries. Give your evidence in the commit message. All `.data` and `.rodata` lands in the last file, to be moved to its owners afterwards.

Then replace a whole `.s` with C in `src/`, keeping the symbol names, and swap its object for yours in `main.lsf` and `LINKED_C_SRCS`. `src/battle_record.c` is one such file. Every source file includes a header of the same name declaring what it defines, since `MWCFLAGS` passes `-W error`. Check it with `make compare-overlays`, or `make compare-arm9` for the ARM9.

## Functions that will not match

A function that resists matching in C can be supplied as assembly in place with `GLOBAL_ASM`, which keeps it in its original object so the surrounding layout does not shift. Three things to know before you use it:

- Write Metrowerks mnemonics rather than GNU ones. `lsl`, not `lsls`.
- A block has to be at least three Thumb instructions.
- `tools/asm_processor/compile.sh` strips `-sym on` for these compiles, because `asm_processor` cannot remap CodeWarrior's debug relocations.

## Naming symbols

Anything the disassembler could not identify is named `FUN_<address>` after where it sits in memory. When you work out what one does, rename it both in the assembly and in the matching `ndsdisasm_config/*.cfg` entry, so that if a dump is regenerated it agrees with the tree.

Only name something you have evidence for, from the code, the game's text, or a decompiled equivalent that agrees. Otherwise keep `FUN_<address>` or `unk_<offset>`.

Preferably keep renames in commits of their own, separate from decompilation work. They touch a great many files and are much easier to review on their own.

## Game data

Species data lives in `res/pokemon/<species>/data.json` and text in `res/text/`, with constants listed in `generated/*.txt`. The build packs these into the archives they came from, used in place of the copies in `files/`. Run `make check-data` after changing them.
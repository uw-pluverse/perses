# Guidelines for Claude

## Branching

- Do all work directly on the `master` branch. Do not create new branches, and do
  not switch to other branches, unless I explicitly ask you to.

## Committing

- Never commit code without my review. Make the changes, run the relevant
  tests, show me what changed, and wait for my explicit "commit" before running
  `git commit`.

## Generated docs

- Put every doc you generate (design notes, findings, investigations, handoffs)
  under `internal_doc/`. Do not scatter generated docs across `doc/` or other
  directories.

## Comments

- Do not write comments that merely restate what the code does when the behavior
  is easily inferred from the code itself (the function name, signature, or a
  short delegating body). Delete such comments.
- Keep comments that explain non-obvious "why": design rationale, lifetimes,
  invariants, trade-offs, or consequences that are not visible in the code.
- When trimming, do not duplicate rationale that already lives in a nearby
  KDoc/class comment; keep the explanation in one place and let the other spot
  point to it.

## Running benchmarks

- Before running anything in `//benchmark_v2/`, read `//benchmark_v2/README.md`
  and drive the benchmarks through the scripts it documents
  (`run_experiment.py` → `perses_benchmark.py` → `run_benchmark.py`). Do not
  invoke a reducer against a benchmark directly from the host.
- The reason is not style: the benchmarks run inside a docker image that carries
  the compiler versions their `r.sh` needs (`clang-3.4.2`, `clang-7.1.0`,
  `gcc-4.8.0`, ...). On the host most of those oracles fail on the *unreduced*
  program, so a host-driven run silently covers only the subjects whose toolchain
  happens to be installed, and its results are not what the documented command
  reproduces.
- Extra reducer flags belong in `--perses-flags`, which every layer forwards.

## Reusing utilities

- Before implementing something that looks like a common helper (file/directory
  operations, copying, string/collection helpers, time formatting, etc.), check
  `//src/org/perses/util/` (especially `Util.kt`) for an existing utility method
  and use it instead of reimplementing the logic. For example, prefer
  `Util.ensureDirExists`, `Util.copyDirectory`, and `Util.copyFileToDirectory`
  over hand-rolled `Files.*` sequences.

- Do not generate comments that explain what the code is doing. Assume the
  reader is an expert engineer who can read self-documenting code. Only include
  comments if they explain a non-obvious why (e.g., handling an edge case, a
  workaround for a known bug, or complex mathematical formulas).

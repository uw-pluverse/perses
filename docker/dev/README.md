# Dev image: building and testing perses in docker

`scripts/presubmit.sh` is the one command that builds and tests this repo, but it needs a long
tool chain: everything `scripts/check_prerequisite.sh` gates on (`clangd-18`, `creduce`, `scala`,
`wasmedge`, `wat2wasm`, `rustc`, `gcovr`, ...) plus `bazelisk`, a JDK, and
`git`/`curl`/`wget`/`maven`.
This directory packages that environment so a contributor needs only docker and a checkout.

Running presubmit on the host stays fully supported; the image is an alternative, not a
replacement.

## Quick start

```bash
./docker/dev/build_image.sh     # builds cnsun/perses:dev_v1 (~5 min, ~3.5 GB)
./docker/dev/test_image.sh      # asserts the tool chain is what presubmit expects
./docker/dev/run.sh             # runs ./scripts/presubmit.sh inside the image
```

Other entry points:

```bash
./docker/dev/run.sh --shell                       # interactive bash in the workspace
./docker/dev/run.sh --exec bazelisk test //src/... # one command instead of presubmit
./docker/dev/run.sh -- ./scripts/build-binaries.sh # extra command presubmit runs when it passes
./docker/dev/run.sh --debug --shell               # ... with docker's ptrace limits lifted (see README)
./docker/dev/run.sh --root --shell                # ... as root, to apt-get a tool into the session
```

## Debugging inside the image

A container is where the failure is, so the image is set up to be debugged in rather than only run.

Three things you get for free. The workspace is bind-mounted at its **host path**, so you edit in
your normal host editor and rerun in the container with no copy step in between. The container runs
as your uid, so everything a run leaves behind -- `bazel-testlogs/`, regenerated goldens, staged
jars -- is yours to read and delete without `sudo`. And `$HOME` is a persistent volume, so the
bazel cache survives between runs: only the first one is a cold build.

The usual loop is therefore:

```bash
./docker/dev/run.sh --shell
# inside:
bazelisk test //test/org/perses/...:SomeTest --test_output=all
```

`gdb`, `strace`, `less`, `file`, `jq`, `tree` and `vim.tiny` are in the image. Running something
*under* them needs no special flags -- `gdb --args ./some_oracle_binary` works in a plain
container. Two things do need flags, because docker restricts ptrace:

| you want to | run |
| --- | --- |
| launch a process under gdb/strace | nothing extra |
| ...with ASLR off, so addresses repeat between runs | `--debug` |
| attach to an already-running process (`gdb -p`) | `--root --debug` |

The last row is not a typo. `--cap-add=SYS_PTRACE` only widens the *bounding* set, and the
container's non-root uid holds no effective capabilities, so `--debug` on its own still cannot
attach -- you need the root session too. Without `--debug`, gdb also warns `Error disabling address
space randomization` and every run reports different addresses, which is merely annoying rather
than fatal.

For a tool the image does not carry, `--root` starts the session as root. The Dockerfile drops the
apt lists, so update first:

```bash
./docker/dev/run.sh --root --shell
# inside:
apt-get update && apt-get install -y ltrace
```

The container is `--rm`, so the install lasts only as long as that shell -- a tool worth keeping
belongs in the Dockerfile's debug layer instead. `--root` is refused for a presubmit run, since
presubmit rewrites the working tree and would leave the checkout root-owned.

Anything else `docker run` can do goes through `PERSES_DOCKER_ARGS`, which is appended verbatim to
the command line. Attaching a host IDE to a JVM under test is the common case:

```bash
PERSES_DOCKER_ARGS='--publish 5005:5005' ./docker/dev/run.sh --exec \
  bazelisk test //test/...:SomeTest \
  --jvmopt=-agentlib:jdwp=transport=dt_socket,server=y,address=*:5005,suspend=y
```

The value is split on whitespace, so no single flag value may contain a space; for that, call
`docker run` directly.

## Why the versions are pinned

Several toy oracles decide interestingness by grepping compiler diagnostics --
`test/org/perses/benchmark_toys/delta_1/r.sh` looks for `-Wimplicit-int`, `Wmain-return-type` and
friends in `gcc`/`clang` output, `cpp_print/r.sh` does the same for `g++`/`clang++`. The golden
files those tests compare against therefore encode the behaviour of one specific gcc and one
specific clang. Run presubmit with different compilers and it will "fix" the goldens on every run,
producing a diff that has nothing to do with your change.

So the image matches the reference host exactly: `ubuntu:24.04` for gcc 13.3.0 (and wabt, creduce,
lcov, gcovr, scala, ruby, go at the same versions Ubuntu 24.04 ships), apt.llvm.org for clang
**18.1.8** -- Ubuntu's own `clang-18` is 18.1.3 and is not a substitute -- and the pinned rust
release tarballs from static.rust-lang.org. `test_image.sh` asserts every one of those, and the
Dockerfile asserts them again at build time, so a drift fails loudly instead of turning into golden
churn.

Rust goes through rustup, with a pinned stable as the default plus a nightly, because
`//kitten/test/org/perses/fuzzer/rust:RustcVersionTest` runs `rustc +nightly --version --verbose`
and the `+toolchain` syntax only exists in the rustup shim. That shim resolves toolchains through
`$RUSTUP_HOME`, which `.bazelrc` does **not** forward into a test action (only `PATH` and `HOME`
are), so `run.sh` points `$HOME/.rustup` at the baked `/opt/rustup` -- the same indirection the
reference host relies on. Without it, every rust action dies with "could not choose a version of
rustc to run".

`scripts/check_prerequisite.sh` is the authoritative list of tools, with one exception: `valgrind`,
which it does not gate on but which
`//test/org/perses/reduction/reducer/vulcan/expr_stmt_for_tokenpattern_system_test` needs.

## Version-pinned compilers the image cannot bake (`PERSES_DOCKER_MOUNTS`)

Fourteen oracles under `test/` use a compiler *older* than any distribution ships, and pick it up
opportunistically:

```bash
if command -v gcc-7.1.0; then GCC="gcc-7.1.0"; else GCC="gcc"; fi
```

On a machine that has `gcc-7.1.0`/`clang-7.1.0` on the PATH the oracle uses those; everywhere else
it silently falls back to the system compiler. The committed goldens encode whichever one produced
them, and for `test/org/perses/benchmark_toys/delta_1` the two disagree: with gcc 7.1.0 the reducer
stops at `int main (int argc, char *argv[])`, with gcc 13 / clang 18 it gets one step further to
`int main (                      )`. So a presubmit run without the pinned compilers rewrites five
`delta_1` goldens, and a run with them rewrites them back. (The other thirteen reduce identically
under both, so only `delta_1` is affected today.)

A 7.1.0 toolchain is ~3.5 GB unstripped and gcc 7.1.0 has no prebuilt Ubuntu 24.04 binary, so the
image does not carry it. Instead, if you already have those compilers, mount them in:

```bash
export PERSES_DOCKER_MOUNTS=/home/me/software:/home/me/usr/bin  # ':'-separated, mounted read-only
export PERSES_DOCKER_PATH_PREPEND=/home/me/usr/bin              # prepended to the container PATH
./docker/dev/run.sh
```

Each path is mounted read-only at the same absolute path it has on the host, and the PATH entry
reaches the oracles because `.bazelrc` forwards `PATH` into every action. Note that changing
`PERSES_DOCKER_PATH_PREPEND` changes the action environment and so invalidates the bazel cache.

Without these variables the container is self-consistent and everything passes -- you will just see
those five `delta_1` goldens rewritten, and should `git checkout` them rather than commit them.

## What is baked in, and what is not

Baked into the image: the apt tool chain, clang 18, rustup with its toolchains under `/opt/rustup`,
wasmedge, `bazelisk` with the `.bazelversion` release pre-warmed under `/opt/bazelisk`
(`build_image.sh` reads `.bazelversion`, so the image never lags behind a bump), and the debug
tools above.

Not baked: `benchmark_v2/binaries/{jdk21,clangd-18,jdtls-1.33.0,java-language-server}`. Those live
*inside* the workspace, which is bind-mounted, so `check_prerequisite.sh` installs them into your
checkout on first run through the existing `benchmark_v2/install_*.sh` scripts -- exactly as it
does on a host, and only once. That first run downloads a few hundred MB and builds the
java-language-server with maven, so budget a few extra minutes for it.

## File ownership

presubmit rewrites the working tree: `scripts/cleanup.sh` updates copyright headers and runs
buildifier, ktlint and google-java-format in place; presubmit regenerates the golden files of any
golden test that failed; `scripts/build-binaries.sh` stages jars into `bin/`.

`run.sh` therefore starts the container with `--user $(id -u):$(id -g)`, the same technique
`benchmark_v2/perses_benchmark.py` uses, so all of that comes out owned by you rather than by
root. `/etc/passwd` and `/etc/group` are mounted read-only so the uid still resolves to your
username inside the container (bazel needs a username for its output base, and `whoami` would
otherwise fail).

## Caches and the `bazel-*` symlinks

The workspace is mounted at its **host path**, and the container's `$HOME` is a named volume
(`perses-dev-home-<uid>`) mounted at your **host home path**. Bazel derives its output base from
`$HOME` and the workspace path and writes `bazel-bin`/`bazel-out` symlinks into the workspace, so
keeping both paths identical means those symlinks are byte-identical whether presubmit last ran on
the host or in the container -- switching back and forth never invalidates them.

The *contents* are deliberately separate: the host and the container have different compilers, and
sharing one bazel disk cache between them would let one's action results be reused by the other.
The practical consequence is that the first container run is a cold build.

On that first run `check_prerequisite.sh` is also still installing the Java language servers while
the tests execute, which is enough to make `//test/org/perses/mimir/lsp:JavaLanguageServerTest` fail
and `//test/org/perses/mimir:MimirSemanticsProviderTest` hit its 300s timeout. presubmit's own rerun
covers this -- both pass on the second pass and the run exits 0 -- so no action is needed.

To start over from a clean container cache:

```bash
docker volume rm "perses-dev-home-$(id -u)"
```

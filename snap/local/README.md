# Perses snap packaging

Builds and publishes Perses as a [snap](https://snapcraft.io/) so users can
install it with `sudo snap install perses` on Ubuntu and any distro running
`snapd`.

## What gets produced

A single `perses_<version>_<arch>.snap` that bundles:

- the Bazel fat jar `//src/org/perses:perses_deploy.jar`,
- a full **JDK 17** (`openjdk-17-jdk-headless`) so no Java is needed on the host,
- a launcher (`snap/local/wrapper/perses`) that runs the jar with the bundled JDK.

The snap uses **classic confinement**: Perses executes the user's test script,
which invokes arbitrary host toolchains (`gcc`, `clang`, `javac`, ...) and reads
and writes files at arbitrary paths — none of which strict confinement permits.

A full JDK (not just a JRE) is bundled because Perses calls the in-process JDK
compiler API (`ToolProvider.getSystemJavaCompiler()` / `com.sun.source.*` in
`JavacWrapper` and the mimir javac path), which lives in the `jdk.compiler`
module absent from a headless JRE. The jlink-only `jmods/` directory is trimmed
to keep the snap small; `javac` and the compiler API still work without it.

## Quick start: publish a release

After the GitHub release for the current `VERSION` exists:

```bash
snap/local/build-and-verify-snap.sh   # build from the release jar, install-test (sudo), cross-distro check
snap/local/upload-snap.sh             # upload the verified snap; prints the release command
```

`build-and-verify-snap.sh` stops at the first failure and, only when every
check passes, writes `<snap>.verified`. `upload-snap.sh` refuses a snap without
a matching marker or whose jar is not the release jar. It uploads without
releasing; run the `snapcraft release` command it prints once the revision is
approved. The sections below describe each step.

## Layout

```
snap/
├── snapcraft.yaml              # the recipe (must live in snap/, repo root, or build-aux/snap/)
└── local/                      # snapcraft-recognized dir; left untouched, referenced via source:
    ├── README.md               # this file
    ├── build-and-verify-snap.sh    # release build → verify-snap → verify-distros → .verified marker
    ├── upload-snap.sh              # checks the marker and release jar, then snapcraft upload
    ├── lib.sh                      # paths, version and release-digest lookup shared by the scripts
    ├── build-snap-from-release.sh  # download release jar → check digest → snapcraft pack
    ├── build-snap-from-source.sh   # bazelisk build → stage jar → snapcraft pack (testing only)
    ├── verify-snap.sh          # real install + functional checks on this host
    ├── verify-distros.sh       # ELF audit + run in 17 distro containers
    ├── wrapper/perses          # launcher → bundled JDK runs the fat jar
    └── dist/perses_deploy.jar  # staged build output (gitignored)
```

## Prerequisites

- [`gh`](https://cli.github.com/) and `curl` — fetch the release jar and its digest.
- [`bazelisk`](https://github.com/bazelbuild/bazelisk) — builds the fat jar (source builds only).
- [`snapcraft`](https://snapcraft.io/snapcraft) — `sudo snap install snapcraft --classic`.
- A build backend for the `core22` build VM: **LXD** (`sudo snap install lxd && lxd init --auto`)
  or **Multipass** (`sudo snap install multipass`).

## Build

Both scripts stage a jar into `snap/local/dist/` and pack the snap into the repo
root. On a host without LXD, prefix either with
`SNAPCRAFT_BUILD_ENVIRONMENT=multipass`.

```bash
snap/local/build-snap-from-release.sh   # the GitHub release jar; the only build you may upload
snap/local/build-snap-from-source.sh    # bazelisk build of the working tree; for testing unreleased changes
```

`build-snap-from-release.sh` packs the `perses_deploy.jar` of release
`v<VERSION>` and refuses to pack if the release or its digest is missing or the
download does not match it.

### Versioning

`snapcraft.yaml` reads the snap version from
`version/org/perses/version/VERSION`, the same file the jar's `Version` class is
generated from, so the snap's version and `perses --version` cannot disagree as
long as the jar and the snap come from the same VERSION (which both build
scripts guarantee). There is no override: to change the version, run
`scripts/bump_version.py` and rebuild. `verify-snap.sh` checks that the
installed snap's version equals what the binary reports.

Snap versions are capped at 32 characters and a restricted charset; the
`MAJOR.MINOR` form of the VERSION file fits comfortably.

## Install and test locally

`--dangerous` allows installing an unsigned local file; `--classic` matches the
snap's confinement:

```bash
sudo snap install --classic --dangerous ./perses_*.snap
perses --help
sudo snap remove perses          # when done
```

### Automated smoke test

`verify-snap.sh` installs the snap (sudo), runs functional checks, and removes
it again. It verifies the launcher runs, the bundled JDK's `javac` /
`jdk.compiler` are present, an end-to-end out-of-place reduction produces a
smaller result that still passes its interestingness test, and the snap's
version equals what `perses --version` reports:

```bash
snap/local/verify-snap.sh                 # verifies the newest perses_*.snap
snap/local/verify-snap.sh path/to.snap    # or a specific file
KEEP=1 snap/local/verify-snap.sh          # leave the snap installed afterward
```

Exits non-zero if any check fails.

### Cross-distro check

A classic snap sees the host's root filesystem, so a bundled binary that was not
ELF-patched silently loads the host's `ld.so` and `libc`. It then works on the
build host and fails with ``version `GLIBC_2.34' not found`` on every distro
whose glibc is older than core22's. `verify-snap.sh` cannot see this, because
the host it runs on is new enough. `verify-distros.sh` can:

```bash
snap/local/verify-distros.sh                 # newest perses_*.snap, 17 distros
DISTROS="debian:11 centos:7" snap/local/verify-distros.sh path/to.snap
```

It audits every ELF file in the snap (core22 loader, RPATH set), then mounts the
unpacked snap and the host's core22 at their `/snap/...` paths inside a
container of each distro and runs `perses --version`, the bundled `javac` and an
end-to-end reduction. It needs docker and no sudo. The containers have no
snapd, so it validates the payload, not the install path.

Run both scripts on every snap before uploading it.

## Publish to the Snap Store

First-time publishers must create a Snap Store developer account — see
`internal_doc/snap_publishing_account_setup.md`.

### Always package the GitHub release jar

A store revision must contain exactly the `perses_deploy.jar` attached to the
matching GitHub release, never a jar built from the working tree. The snap and
the release are then the same bytes, the snap's version (read from `VERSION`)
names the release it was built from, and the revision is reproducible from the
public artifact alone. Build store snaps with `build-snap-from-release.sh`.
`build-snap-from-source.sh` is only for testing unreleased changes locally; a
jar it produces reports `Git Status: Modified` in `perses --version` and must
not be uploaded.

Publish only after `scripts/bump_version.py` and the GitHub release for that
version exist, in that order, so the VERSION file and the tag agree.

1. Reserve the name (one-time):

   ```bash
   snapcraft login
   snapcraft register perses      # if taken, pick e.g. perses-reducer and update name: in snapcraft.yaml
   ```

2. Upload, then release to a channel:

   ```bash
   snap/local/upload-snap.sh                        # snapcraft upload; prints the revision number
   snapcraft release perses <revision> stable
   ```

   Keep the two steps separate: a classic revision waits in manual review
   until the store grants it, and `--release` would only fail at that step.

   Channels: `stable`, `candidate`, `beta`, `edge`. Use `edge`/`beta` for
   pre-releases and promote later with
   `snapcraft release perses <revision> stable`.

### One-time: classic-confinement approval

A classic snap cannot be released until a store reviewer approves it. Post the
justification in `internal_doc/snap_classic_confinement_request.md` to the
[Snapcraft forum](https://forum.snapcraft.io/c/store-requests/classic-confinement/26)
under *store-requests / classic-confinement*, using the mandatory template that
doc already follows. This is a one-time gate, not per-release. The forum does not accept
Ubuntu One logins; it needs its own account, and new sign-ups wait for moderator
approval.

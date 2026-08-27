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

## Layout

```
snap/
├── snapcraft.yaml              # the recipe (must live in snap/, repo root, or build-aux/snap/)
└── local/                      # snapcraft-recognized dir; left untouched, referenced via source:
    ├── README.md               # this file
    ├── build-snap.sh           # bazelisk build → stage jar → snapcraft pack
    ├── wrapper/perses          # launcher → bundled JDK runs the fat jar
    └── dist/perses_deploy.jar  # staged build output (gitignored)
```

## Prerequisites

- [`bazelisk`](https://github.com/bazelbuild/bazelisk) — builds the fat jar.
- [`snapcraft`](https://snapcraft.io/snapcraft) — `sudo snap install snapcraft --classic`.
- A build backend for the `core22` build VM: **LXD** (`sudo snap install lxd && lxd init --auto`)
  or **Multipass** (`sudo snap install multipass`).

## Build

From the repo root:

```bash
snap/local/build-snap.sh
```

This runs `bazelisk build`, stages the jar into `snap/local/dist/`, and packs the
snap into the repo root. On a host without LXD, select the Multipass backend:

```bash
SNAPCRAFT_BUILD_ENVIRONMENT=multipass snap/local/build-snap.sh
```

### Versioning

The version defaults to `2.5`. Override it at build time (e.g. to match a release
tag):

```bash
SNAPCRAFT_PERSES_VERSION=2.6 snap/local/build-snap.sh
```

Snap versions are capped at 32 characters and a restricted charset, so keep it a
short, clean string (not a raw `git describe`).

## Install and test locally

`--dangerous` allows installing an unsigned local file; `--classic` matches the
snap's confinement:

```bash
sudo snap install --classic --dangerous ./perses_2.5_amd64.snap
perses --help
sudo snap remove perses          # when done
```

### Automated smoke test

`verify-snap.sh` installs the snap (sudo), runs functional checks, and removes
it again. It verifies the launcher runs, the bundled JDK's `javac` /
`jdk.compiler` are present, and an end-to-end out-of-place reduction produces a
smaller result that still passes its interestingness test:

```bash
snap/local/verify-snap.sh                 # verifies the newest perses_*.snap
snap/local/verify-snap.sh path/to.snap    # or a specific file
KEEP=1 snap/local/verify-snap.sh          # leave the snap installed afterward
```

Exits non-zero if any check fails.

## Publish to the Snap Store

First-time publishers must create a Snap Store developer account — see
`internal_doc/snap_publishing_account_setup.md`.

1. Reserve the name (one-time):

   ```bash
   snapcraft login
   snapcraft register perses      # if taken, pick e.g. perses-reducer and update name: in snapcraft.yaml
   ```

2. Upload and release to a channel:

   ```bash
   snapcraft upload --release=stable ./perses_2.5_amd64.snap
   ```

   Channels: `stable`, `candidate`, `beta`, `edge`. Use `edge`/`beta` for
   pre-releases and promote later with
   `snapcraft release perses <revision> stable`.

### One-time: classic-confinement approval

A classic snap cannot be released until a store reviewer approves it. Post the
justification in `internal_doc/snap_classic_confinement_request.md` to the
[Snapcraft forum](https://forum.snapcraft.io/) under the *store-requests*
category. This is a one-time gate, not per-release.

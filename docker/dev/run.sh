#!/usr/bin/env bash
#
# Run scripts/presubmit.sh (or any command) inside the perses dev image, against this checkout.
#
#   ./docker/dev/run.sh                      # the full presubmit
#   ./docker/dev/run.sh -- ./scripts/x.sh    # presubmit, then run ./scripts/x.sh (presubmit's "$@")
#   ./docker/dev/run.sh --shell              # interactive bash in the workspace
#   ./docker/dev/run.sh --exec <cmd> [args]  # run one command instead of presubmit
#   ./docker/dev/run.sh -t my-tag ...        # use a different image
#   ./docker/dev/run.sh --debug --shell      # ... with docker's ptrace limits lifted (see README)
#   ./docker/dev/run.sh --root --shell       # ... as root, to apt-get a tool into the session
#
# --shell and --exec consume the rest of the command line, so -t/--debug/--root come before them.
# PERSES_DOCKER_ARGS passes arbitrary extra flags on to `docker run`; see the block below.
#
# presubmit REWRITES THE WORKING TREE: it reformats sources, updates copyright headers,
# regenerates golden files and stages jars into bin/. The container therefore runs as the invoking
# host user, so every one of those files stays host-owned instead of turning up root-owned.
set -o errexit
set -o nounset
set -o pipefail

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly WORKSPACE="$(git -C "${SCRIPT_DIR}" rev-parse --show-toplevel)"
readonly DEFAULT_TAG="cnsun/perses:dev_v1"

# The container's home lives in a named volume rather than in the host home. The mount point is
# the host's $HOME path all the same: bazel derives its output base from $HOME and the workspace
# path, and writes bazel-bin/bazel-out symlinks pointing at it into the (bind-mounted) workspace.
# Identical paths on both sides mean those symlinks are byte-identical whether presubmit last ran
# on the host or in the container, so switching between the two never invalidates them. The
# contents stay separate on purpose: the two bazel servers see different compilers.
readonly HOME_VOLUME="perses-dev-home-$(id -u)"

tag="${DEFAULT_TAG}"
mode="presubmit"
debug_mode=0
run_as_root=0
while [[ $# -gt 0 ]]; do
  case "$1" in
    -t | --tag)
      tag="$2"
      shift 2
      ;;
    --debug)
      debug_mode=1
      shift
      ;;
    --root)
      run_as_root=1
      shift
      ;;
    --shell)
      mode="shell"
      shift
      break
      ;;
    --exec)
      mode="exec"
      shift
      break
      ;;
    -h | --help)
      sed -n '2,18p' "${BASH_SOURCE[0]}"
      exit 0
      ;;
    --)
      shift
      break
      ;;
    *)
      echo "unexpected argument: $1 (did you mean '-- $*'?)" >&2
      exit 2
      ;;
  esac
done

# presubmit rewrites the working tree, so running it as root leaves the checkout full of
# root-owned sources, goldens and bin/ jars -- the exact outcome --user exists to prevent. --root
# is for a debugging session; refuse the combination rather than let it be discovered afterwards.
if [[ "${run_as_root}" -eq 1 && "${mode}" == "presubmit" ]]; then
  echo "ERROR: --root would run presubmit as root and leave root-owned files in the checkout." >&2
  echo "       Use '--root --shell' to debug, or drop --root to run presubmit." >&2
  exit 2
fi

if ! docker image inspect "${tag}" > /dev/null 2>&1; then
  echo "ERROR: image ${tag} not found. Build it with ${SCRIPT_DIR}/build_image.sh" >&2
  exit 1
fi

# A named volume is created root-owned, which the unprivileged container user cannot write, so it
# has to be handed over by a privileged one-shot container. The workspace path is created inside
# the volume in the same step: it sits *under* $HOME, so the workspace bind mount is nested inside
# the home volume, and when docker has to create that nested mount point itself it resets the
# volume root back to root-owned -- silently undoing the chown. Pre-creating the path leaves
# docker nothing to create. Both operations are idempotent, so this also repairs a clobbered
# volume rather than only running at creation time.
if ! docker volume inspect "${HOME_VOLUME}" > /dev/null 2>&1; then
  echo "Creating home volume ${HOME_VOLUME} for $(id -un)."
fi
docker volume create "${HOME_VOLUME}" > /dev/null
# The same container also points $HOME/.rustup at the image's baked rustup. Bazel forwards only
# PATH and HOME into a test action, so the rustup shim cannot see $RUSTUP_HOME there and would fail
# to choose a toolchain; going through $HOME/.rustup is how the reference host resolves it too.
docker run --rm --user 0:0 \
  --volume "${HOME_VOLUME}:${HOME}" \
  --env "HOME_DIR=${HOME}" \
  --env "WORKSPACE_DIR=${WORKSPACE}" \
  --env "OWNER=$(id -u):$(id -g)" \
  "${tag}" bash -c '
    mkdir -p "${WORKSPACE_DIR}"
    ln -sfn "${RUSTUP_HOME}" "${HOME_DIR}/.rustup"
    chown "${OWNER}" "${HOME_DIR}"'

docker_args=(
  --rm
  # PID 1 must reap orphans: the oracles run compilers under `timeout`, which leaves cc1/rustc
  # descendants behind (see the test-script guidance in README.md).
  --init
)

if [[ "${run_as_root}" -eq 1 ]]; then
  # --root exists for one thing: `apt-get install <tool>` inside a --shell session, when something
  # has to be diagnosed with a tool the image does not carry. The container is --rm, so the install
  # lives only as long as that shell; a tool worth keeping belongs in the Dockerfile's debug layer.
  #
  # No passwd/group mounts here. Their only job is to give an arbitrary host uid a name, and uid 0
  # already has one -- mounting the host's files read-only would just get in apt's way. The cost is
  # that bazel names its output base _bazel_root, so a root session neither shares nor disturbs the
  # cache of a normal one. Anything it does write into the workspace comes out root-owned, which is
  # why this is not a mode to run presubmit in.
  docker_args+=(
    --user 0:0
    --env "USER=root"
  )
else
  docker_args+=(
    --user "$(id -u):$(id -g)"
    # An arbitrary uid has no passwd entry, so `whoami` fails and bazel cannot name its output base
    # (~/.cache/bazel/_bazel_<user>). Mapping the host's passwd/group in read-only makes the
    # container resolve the same username, keeping the bazel-* symlink targets identical.
    --volume /etc/passwd:/etc/passwd:ro
    --volume /etc/group:/etc/group:ro
    --env "USER=$(id -un)"
  )
fi

docker_args+=(
  --volume "${WORKSPACE}:${WORKSPACE}"
  --volume "${HOME_VOLUME}:${HOME}"
  --env "HOME=${HOME}"
  --workdir "${WORKSPACE}"
)

if [[ "${debug_mode}" -eq 1 ]]; then
  # Loosens the two restrictions docker puts on ptrace. Neither is needed to *launch* a process
  # under gdb or strace -- that works in a plain container -- but:
  #
  #   seccomp=unconfined  lets gdb disable ASLR. The default profile blocks the personality()
  #                       call it uses, so gdb warns and every run reports different addresses.
  #   SYS_PTRACE          is required to attach to an already-running process (gdb -p). Note that
  #                       --cap-add only widens the bounding set, and a non-root uid holds no
  #                       effective capabilities, so attaching needs --root --debug together;
  #                       --debug alone still cannot attach.
  #
  # Off by default because it widens what the container may do and presubmit never needs it.
  docker_args+=(
    --cap-add=SYS_PTRACE
    --security-opt seccomp=unconfined
  )
fi

# Escape hatch for host toolchains the image cannot reasonably bake. Some oracles prefer a
# version-pinned compiler when one is on the PATH and silently fall back to the system one
# otherwise -- test/org/perses/benchmark_toys/delta_1/r.sh picks `gcc-7.1.0`/`clang-7.1.0` if
# present -- and the committed goldens of such a test encode whichever compiler produced them. To
# reproduce those goldens, mount the trees holding the pinned compilers and put their bin directory
# on the PATH (bazel forwards PATH into every action, so the oracles see it too):
#
#   export PERSES_DOCKER_MOUNTS=/home/me/software:/home/me/usr/bin
#   export PERSES_DOCKER_PATH_PREPEND=/home/me/usr/bin
#
# Each path is mounted read-only at the same absolute path it has on the host. See README.md.
if [[ -n "${PERSES_DOCKER_MOUNTS:-}" ]]; then
  IFS=':' read -r -a mount_paths <<< "${PERSES_DOCKER_MOUNTS}"
  for mount_path in "${mount_paths[@]}"; do
    [[ -z "${mount_path}" ]] && continue
    if [[ ! -e "${mount_path}" ]]; then
      echo "ERROR: PERSES_DOCKER_MOUNTS entry does not exist: ${mount_path}" >&2
      exit 1
    fi
    docker_args+=(--volume "${mount_path}:${mount_path}:ro")
  done
fi
if [[ -n "${PERSES_DOCKER_PATH_PREPEND:-}" ]]; then
  # Prepend, never replace: the image's PATH carries the JDK, rustup shims and bazelisk.
  image_path="$(docker image inspect --format \
    '{{range .Config.Env}}{{if eq (slice . 0 5) "PATH="}}{{slice . 5}}{{end}}{{end}}' "${tag}")"
  docker_args+=(--env "PATH=${PERSES_DOCKER_PATH_PREPEND}:${image_path}")
fi

# Escape hatch for the rest of `docker run`, which this script deliberately does not model flag by
# flag. Typically a port, so a host IDE can attach to a JVM under test:
#
#   PERSES_DOCKER_ARGS='--publish 5005:5005' ./docker/dev/run.sh --exec \
#     bazelisk test //test/...:SomeTest --jvmopt=-agentlib:jdwp=transport=dt_socket,server=y,address=*:5005,suspend=y
#
# Appended last, so a flag here wins over the same flag set above. Split on whitespace: a value
# containing a space cannot be passed this way -- use `docker run` directly for that.
if [[ -n "${PERSES_DOCKER_ARGS:-}" ]]; then
  read -r -a extra_docker_args <<< "${PERSES_DOCKER_ARGS}"
  docker_args+=("${extra_docker_args[@]}")
fi

case "${mode}" in
  shell)
    # Only allocate a tty when there is one; `--shell -c '<command>'` from a script must not die
    # with "the input device is not a TTY".
    tty_args=(--interactive)
    [[ -t 0 ]] && tty_args+=(--tty)
    docker run "${tty_args[@]}" "${docker_args[@]}" "${tag}" bash "$@"
    ;;
  exec)
    docker run "${docker_args[@]}" "${tag}" "$@"
    ;;
  presubmit)
    docker run "${docker_args[@]}" "${tag}" ./scripts/presubmit.sh "$@"
    ;;
esac

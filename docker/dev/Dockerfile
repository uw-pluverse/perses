# Build-and-test image for the perses repo: everything `scripts/presubmit.sh` needs.
#
# presubmit runs `scripts/check_prerequisite.sh`, which gates on ~18 host tools, then builds and
# tests every bazel target, then formats and regenerates goldens. This image carries that whole
# tool chain so a contributor needs only docker and a checkout.
#
# The versions here are not arbitrary. Several toy oracles decide interestingness by grepping
# compiler diagnostics -- test/org/perses/benchmark_toys/delta_1/r.sh greps gcc/clang warning
# names, cpp_print/r.sh does the same for g++/clang++ -- so the committed golden files encode the
# behaviour of one specific gcc and one specific clang. An image with different compilers would
# make presubmit "fix" those goldens on every run. ubuntu:24.04 supplies gcc 13.3.0 (and the
# matching wabt/creduce/lcov/gcovr/scala/ruby/go), and apt.llvm.org supplies clang 18.1.8, which
# is what the goldens were generated with; Ubuntu's own clang-18 is 18.1.3 and is NOT equivalent.
# Each pinned version is asserted at build time so a drift fails here rather than in a golden diff.
#
# Deliberately not baked: benchmark_v2/binaries/{jdk21,clangd-18,jdtls-1.33.0,java-language-server}.
# Those live inside the workspace, which is bind-mounted at run time, so check_prerequisite.sh
# installs them into the checkout on first run exactly as it does on a host -- which is why curl,
# git and maven are installed below.
#
# Build with ./build_image.sh; verify with ./test_image.sh; run presubmit with ./run.sh.

FROM ubuntu:24.04

# Deterministic formatter/compiler output regardless of the host locale, and no tzdata prompt.
ENV LANG=C.UTF-8 \
    LC_ALL=C.UTF-8 \
    DEBIAN_FRONTEND=noninteractive

# build-essential: gcc/g++ 13.3.0, the C/C++ oracles' compiler, and the linker rustc shells out to.
# procps: check_prerequisite.sh requires `ps`.
# golang-go, ruby, python3, scala: the go/ruby/python3 toy oracles and check_prerequisite.sh.
# creduce, wabt, lcov, gcovr, clang-format: required by check_prerequisite.sh.
# maven: benchmark_v2/install_jls.sh builds the java-language-server with `mvn package`.
# git: changed_files.sh diffs against master; install_jls.sh clones from GitHub.
# wget: benchmark_v2/install_{jdk21,clangd,jdtls}.sh download their tarballs with it, and
#   check_prerequisite.sh runs those three on a checkout whose benchmark_v2/binaries/ is empty.
#   curl is not a substitute -- the scripts hard-code `wget --output-document`.
# valgrind: the oracle of //test/org/perses/reduction/reducer/vulcan/expr_stmt_for_tokenpattern_system_test
#   is a valgrind exit code. It is the one test tool check_prerequisite.sh does not gate on.
RUN apt-get update \
  && apt-get install --yes --no-install-recommends \
    build-essential \
    ca-certificates \
    creduce \
    curl \
    gcovr \
    git \
    golang-go \
    gnupg \
    lcov \
    maven \
    openjdk-17-jdk \
    procps \
    python3 \
    ruby \
    scala \
    unzip \
    valgrind \
    wabt \
    wget \
    xz-utils \
    zip \
  && rm -rf /var/lib/apt/lists/*

# `scala` pulls in its own default JRE, so pin java/javac/javap to 17 by PATH rather than relying
# on whatever update-alternatives ends up preferring. Bazel itself uses remotejdk_17 (see
# .bazelrc), so this JDK only serves `java -jar bazel-bin/google_java_format_deploy.jar` in
# run_ktlint.sh and the java_print toy oracle.
ENV JAVA_HOME=/usr/lib/jvm/java-17-openjdk-amd64
ENV PATH=${JAVA_HOME}/bin:${PATH}

# clang from apt.llvm.org, not from Ubuntu: see the header comment on golden fidelity.
# check_prerequisite.sh looks up `clangd-18` under that exact name, while the oracles call the
# unsuffixed `clang`/`clang++`, hence the symlinks.
ARG CLANG_VERSION=18.1.8
RUN curl --fail --silent --show-error --location https://apt.llvm.org/llvm-snapshot.gpg.key \
    --output /usr/share/keyrings/llvm-snapshot.asc \
  && echo "deb [signed-by=/usr/share/keyrings/llvm-snapshot.asc] http://apt.llvm.org/noble/ llvm-toolchain-noble-18 main" \
    > /etc/apt/sources.list.d/llvm-toolchain-18.list \
  && apt-get update \
  && apt-get install --yes --no-install-recommends \
    clang-18 \
    clang-format-18 \
    clangd-18 \
  && rm -rf /var/lib/apt/lists/* \
  && ln -s /usr/bin/clang-18 /usr/bin/clang \
  && ln -s /usr/bin/clang++-18 /usr/bin/clang++ \
  && ln -s /usr/bin/clang-format-18 /usr/bin/clang-format \
  && clang --version | grep --quiet "clang version ${CLANG_VERSION}" \
  && clangd-18 --version | grep --quiet "clangd version ${CLANG_VERSION}"

# rustup, with a pinned stable as the default and a nightly alongside it.
#
# A plain rustc would be simpler, but //kitten/test/org/perses/fuzzer/rust:RustcVersionTest runs
# `rustc +nightly --version --verbose` and requires the reply to say "nightly", so the `+toolchain`
# syntax has to work -- which means the rustup shim. Ubuntu's own rustc (1.75) is too old anyway.
#
# The shim finds its toolchains through $RUSTUP_HOME, and .bazelrc forwards only PATH and HOME into
# the build sandbox, so RUSTUP_HOME is stripped from every test action and the shim would fail with
# "could not choose a version of rustc to run". run.sh works around that the way the reference host
# does: it points $HOME/.rustup at this directory, and HOME *is* forwarded. RUSTUP_HOME is still set
# here so a bare `docker run` (no run.sh, no home volume) also works.
#
# Left writable because rustup writes into RUSTUP_HOME for anything beyond resolving a toolchain,
# and the container runs as an arbitrary host uid.
#
# The nightly is intentionally unpinned: the test asserts only that the version string says
# "nightly", and a dated nightly installs under its dated name, which `+nightly` would not select.
ARG RUST_VERSION=1.96.1
ENV RUSTUP_HOME=/opt/rustup \
    CARGO_HOME=/opt/cargo
ENV PATH=${CARGO_HOME}/bin:${PATH}
RUN curl --fail --silent --show-error --location \
    https://static.rust-lang.org/rustup/dist/x86_64-unknown-linux-gnu/rustup-init \
    --output /tmp/rustup-init \
  && chmod +x /tmp/rustup-init \
  && /tmp/rustup-init -y --no-modify-path --profile minimal \
    --default-toolchain "${RUST_VERSION}" --component rustfmt \
  && rm /tmp/rustup-init \
  && rustup toolchain install nightly --profile minimal \
  && chmod -R a+rwX "${RUSTUP_HOME}" "${CARGO_HOME}" \
  && rustc --version | grep --quiet "rustc ${RUST_VERSION}" \
  && rustc +nightly --version | grep --quiet "nightly" \
  && rustfmt --version > /dev/null

# wasmedge runs the reduced .wasm in the wasm toy oracles. check_prerequisite.sh additionally
# requires `wasmedge -v` to succeed, so assert that here rather than discovering it at run time.
ARG WASMEDGE_VERSION=0.14.1
RUN curl --fail --silent --show-error --location \
    https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install_v2.sh \
    --output /tmp/install_wasmedge.sh \
  && bash /tmp/install_wasmedge.sh --version="${WASMEDGE_VERSION}" --path=/usr/local \
  && rm /tmp/install_wasmedge.sh \
  && ldconfig \
  && wasmedge -v | grep --quiet "${WASMEDGE_VERSION}"

# BAZELISK_HOME is baked (not under $HOME) so the pre-warmed bazel is shared by every uid that
# runs the image. It stays writable because a future .bazelversion bump makes bazelisk fetch a new
# release into it at run time.
ARG BAZELISK_VERSION=v1.29.0
ARG BAZEL_VERSION=9.1.0
ENV BAZELISK_HOME=/opt/bazelisk
RUN curl --fail --silent --show-error --location \
    "https://github.com/bazelbuild/bazelisk/releases/download/${BAZELISK_VERSION}/bazelisk-linux-amd64" \
    --output /usr/local/bin/bazelisk \
  && chmod +x /usr/local/bin/bazelisk \
  && ln -s /usr/local/bin/bazelisk /usr/local/bin/bazel \
  && USE_BAZEL_VERSION="${BAZEL_VERSION}" bazelisk --version | grep --quiet "bazel ${BAZEL_VERSION}" \
  && chmod -R a+rwX "${BAZELISK_HOME}"

# Interactive debugging. Nothing here is needed to build or test perses -- these exist because the
# container is where a failure has to be diagnosed, and the alternative was `echo`. gdb backtraces
# a crashing oracle, strace shows which file or exec a test script actually reached, and less/file/
# jq make bazel-testlogs/ and the microbenchmarking .jsonl output readable in place.
#
# Deliberately the last layer, and deliberately its own: adding or dropping a tool here reruns only
# this apt call, leaving the clang/rust/wasmedge/bazel downloads above cached.
#
# gdb and strace both work as-is on a process they launch themselves. Disabling ASLR needs run.sh --debug, and
# attaching to an already-running process needs --root --debug; see the --debug block in run.sh.
RUN apt-get update \
  && apt-get install --yes --no-install-recommends \
    file \
    gdb \
    jq \
    less \
    strace \
    tree \
    vim-tiny \
  && rm -rf /var/lib/apt/lists/*

# No USER and no baked home: run.sh supplies --user <host uid>:<host gid> so everything presubmit
# writes into the bind-mounted workspace stays host-owned, and mounts a volume for that user's
# home. WORKDIR is set at run time to the workspace path.

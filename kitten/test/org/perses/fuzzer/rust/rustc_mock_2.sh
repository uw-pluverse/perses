#!/usr/bin/env bash

set -o pipefail
set -o nounset

if [[ "$@" == *"--version"* ]] ; then
  echo "rustc mock 1"
  exit 0
fi

cat 1>&2 <<- EOF
thread 'rustc' panicked at 'cannot use the \`#[rustc_if_this_changed]\` or \`#[rustc_then_this_would_need]\` annotations without supplying \`-Z query-dep-graph\`', compiler/rustc_incremental/src/assert_dep_graph.rs:77:13
note: run with \`RUST_BACKTRACE=1\` environment variable to display a backtrace

error: internal compiler error: unexpected panic

note: the compiler unexpectedly panicked. this is a bug.

note: we would appreciate a bug report: https://github.com/rust-lang/rust/issues/new?labels=C-bug%2C+I-ICE%2C+T-compiler&template=ice.md

note: rustc 1.48.0-nightly (7f7a1cbfd 2020-09-27) running on x86_64-unknown-linux-gnu

note: compiler flags: --crate-type staticlib

thread '<unnamed>' panicked at 'assertion failed: \`(left == right)\`
  left: \`LLVMing\`,
 right: \`Codegenning\`', /rustc/7f7a1cbfd3b55daee191247770627afab09eece2/compiler/rustc_codegen_ssa/src/back/write.rs:1435:21

error: internal compiler error: unexpected panic

note: the compiler unexpectedly panicked. this is a bug.

note: we would appreciate a bug report: https://github.com/rust-lang/rust/issues/new?labels=C-bug%2C+I-ICE%2C+T-compiler&template=ice.md

note: rustc 1.48.0-nightly (7f7a1cbfd 2020-09-27) running on x86_64-unknown-linux-gnu

note: compiler flags: --crate-type staticlib
EOF

exit 1
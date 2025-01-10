#!/usr/bin/env bash

set -o nounset
set -o xtrace
set -o pipefail
set -o errexit

bazelisk build test/org/perses/grammar/rust:generate_rust_parser_faillist
cp bazel-bin/test/org/perses/grammar/rust/rust_parser_failed_files.txt test/org/perses/grammar/rust/golden_fail_list.txt

bazelisk build //test/org/perses/grammar/rust:cp_pnf_rust_grammar
cp bazel-bin/test/org/perses/grammar/rust/pnf_rust_grammar.g4 test/org/perses/grammar/rust/golden_pnf_rust.g4

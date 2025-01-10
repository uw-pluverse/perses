#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "llvm::LazyCallGraph::SCC& updateCGAndAnalysisManagerForPass(llvm::LazyCallGraph&, llvm::LazyCallGraph::SCC&, llvm::LazyCallGraph::Node&, llvm::CGSCCAnalysisManager&, llvm::CGSCCUpdateResult&, llvm::FunctionAnalysisManager&, bool): Assertion \`(E || !FunctionPass) && \"No function transformations should introduce *new* \" \"call edges! Any new calls should be modeled as \" \"promoted existing ref edges!\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0
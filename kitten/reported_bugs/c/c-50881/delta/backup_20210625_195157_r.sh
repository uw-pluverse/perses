#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "updateCGAndAnalysisManagerForPass(llvm::LazyCallGraph&, llvm::LazyCallGraph::SCC&, llvm::LazyCallGraph::Node&, llvm::CGSCCAnalysisManager&, llvm::CGSCCUpdateResult&, llvm::FunctionAnalysisManager&, bool)::<lambda(llvm::Function&)>: Assertion \`(E || !FunctionPass) && \"No function transformations should introduce *new* ref \" \"edges! Any new ref edges would require IPO which \" \"function passes aren't allowed to do!\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0
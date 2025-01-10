#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "void getCopyToParts(llvm::SelectionDAG&, const llvm::SDLoc&, llvm::SDValue, llvm::SDValue*, unsigned int, llvm::MVT, const llvm::Value*, llvm::Optional<unsigned int>, llvm::ISD::NodeType): Assertion \`DAG.getTargetLoweringInfo().isTypeLegal(PartVT) && \"Copying to an illegal type!\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE submit a bug report to" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0
#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "void DoMarkVarDeclReferenced(clang::Sema&, clang::SourceLocation, clang::VarDecl*, clang::Expr*, llvm::DenseMap<const clang::VarDecl*, int>&): Assertion \`(!E || isa<FunctionParmPackExpr>(E)) && \"missing non-odr-use marking for unevaluated decl ref\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0
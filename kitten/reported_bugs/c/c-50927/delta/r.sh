#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if [[ "$(gcc-trunk -w mutant.c 2>&1 | grep 'error:' | wc -l )" -gt 1 ]] ; then
  exit 1
fi

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "bool clang::Expr::EvaluateWithSubstitution(clang::APValue&, clang::ASTContext&, const clang::FunctionDecl*, llvm::ArrayRef<const clang::Expr*>, const clang::Expr*) const: Assertion \`!isValueDependent() && \"Expression evaluator can't be called on a dependent expression.\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE submit a bug report to" "${OUTPUT}" ; then
  exit 1
fi
exit 0

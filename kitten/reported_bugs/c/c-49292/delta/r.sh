#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

readonly ERROR_COUNT=$(gcc-trunk -fsyntax-only mutant.c 2>&1 | grep ": error" | wc -l )
[[ "${ERROR_COUNT}" == 1 ]] || exit 1

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "clang::ExprResult clang::Sema::BuildCallExpr(clang::Scope*, clang::Expr*, clang::SourceLocation, clang::MultiExprArg, clang::SourceLocation, clang::Expr*, bool, bool): Assertion \`(Fn->containsErrors() || llvm::any_of(ArgExprs, [](clang::Expr *E) { return E->containsErrors(); })) && \"should only occur in error-recovery path.\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE submit a bug report to" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0

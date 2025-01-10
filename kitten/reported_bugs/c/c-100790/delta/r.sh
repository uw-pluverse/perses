#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in verify_range, at value-range.cc" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "irange::verify_range()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_using_range::range_of_builtin_call(irange&, gcall*, fur_source&)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_using_range::range_of_call(irange&, gcall*, fur_source&)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_using_range::fold_stmt(irange&, gimple*, fur_source&, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_ranger::fold_range_internal(irange&, gimple*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_ranger::range_of_stmt(irange&, gimple*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_ranger::range_of_expr(irange&, tree_node*, gimple*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "range_query::value_of_expr(tree_node*, gimple*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "hybrid_folder::value_of_expr(tree_node*, gimple*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "substitute_and_fold_dom_walker::before_dom_children(basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "dom_walker::walk(basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "substitute_and_fold_engine::substitute_and_fold(basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_early_vrp" "${OUTPUT}" ; then
  exit 1
fi
exit 0
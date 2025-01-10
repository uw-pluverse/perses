#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in verify_hash_value, at fold-const.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "operand_compare::verify_hash_value(tree_node const*, tree_node const*, unsigned int, bool*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf_gimple::func_checker::operand_equal_p(tree_node const*, tree_node const*, unsigned int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf_gimple::func_checker::compare_operand(tree_node*, tree_node*, ipa_icf_gimple::func_checker::operand_access_type)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf::sem_function::compare_phi_node(basic_block_def*, basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf::sem_function::equals_private(ipa_icf::sem_item*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf::sem_function::equals(ipa_icf::sem_item*, hash_map<symtab_node*, ipa_icf::sem_item*, simple_hashmap_traits<default_hash_traits<symtab_node*>, ipa_icf::sem_item*> >&)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf::sem_item_optimizer::subdivide_classes_by_equality(bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf::sem_item_optimizer::execute()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf_driver" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_icf::pass_ipa_icf::execute(function*)" "${OUTPUT}" ; then
  exit 1
fi
exit 0
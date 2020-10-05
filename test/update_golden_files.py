#!/usr/bin/env python

import subprocess


class Target:

    def __init__(self, target_name, output_file, golden_file):
        self.target_name = target_name
        self.output_file = output_file
        self.golden_file = golden_file


targets = [
    Target(
        target_name="//src/org/perses/grammar/c:normalize_c_to_pnf",
        output_file="bazel-bin/src/org/perses/grammar/c/PnfC.g4",
        golden_file="test/org/perses/grammar/c/golden_pnf_c.g4"),

    Target(
        target_name="//test/org/perses/antlr/pnf:dump_pnf_pass_manager_log",
        output_file="bazel-bin/test/org/perses/antlr/pnf/pnf_pass_manager_log.txt",
        golden_file="test/org/perses/antlr/pnf/golden_pnf_pass_manager_log.txt"),

    Target(
        target_name="//test/org/perses/reduction/reducer:genlog_for_delta_1_without_caching",
        output_file="bazel-bin/test/org/perses/reduction/reducer/reduction_log_of_delta_1_wo_cache.txt",
        golden_file="test/org/perses/reduction/reducer/golden_reduction_log_of_delta_1_without_cache.txt"),

    Target(
        target_name="//test/org/perses/reduction/reducer:genlog_for_delta_1_with_caching",
        output_file="bazel-bin/test/org/perses/reduction/reducer/reduction_log_of_delta_1_with_caching.txt",
        golden_file="test/org/perses/reduction/reducer/golden_reduction_log_of_delta_1_with_cache.txt"),

    Target(
        target_name="//test/org/perses/antlr:dump_pnf_rule_hierarchy",
        output_file="bazel-bin/test/org/perses/antlr/pnfc_rule_hierarchy.txt",
        golden_file="test/org/perses/antlr/golden_pnfc_rule_hierarchy.txt"),

    Target(
        target_name="//test/org/perses/antlr:dump_pnf_rule_hierarchy",
        output_file="bazel-bin/test/org/perses/antlr/pnfgo_rule_hierarchy.txt",
        golden_file="test/org/perses/antlr/golden_pnfgo_rule_hierarchy.txt"),

    Target(
        target_name="//test/org/perses/antlr:dump_pnf_rule_hierarchy",
        output_file="bazel-bin/test/org/perses/antlr/pnfscala_rule_hierarchy.txt",
        golden_file="test/org/perses/antlr/golden_pnfscala_rule_hierarchy.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/delta_1:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/delta_1/result_reduction_golden_test_perses_node_priority_with_dfs_delta_t.c",
        golden_file="test/org/perses/benchmark_toys/delta_1/golden_reduced_t.c"),

    Target(
        target_name="//test/org/perses/benchmark_toys/delta_1:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/delta_1/reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/delta_1/golden_reduction_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/parentheses:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/parentheses/result_reduction_golden_test_perses_node_priority_with_dfs_delta_t.c",
        golden_file="test/org/perses/benchmark_toys/parentheses/golden_reduced_t.c"),

    Target(
        target_name="//test/org/perses/benchmark_toys/parentheses:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/parentheses/reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/parentheses/golden_reduction_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/go_print:reduction_golden_test_reduction",
        output_file="bazel-bin/test/org/perses/benchmark_toys/go_print/reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/go_print/golden_reduction_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/go_print:reduction_golden_test_reduction",
        output_file="bazel-bin/test/org/perses/benchmark_toys/go_print/result_reduction_golden_test_perses_node_priority_with_dfs_delta_small.go",
        golden_file="test/org/perses/benchmark_toys/go_print/golden_reduced_small.go"),

    Target(
        target_name="//test/org/perses/benchmark_toys/scala_print:reduction_golden_test_reduction",
        output_file="bazel-bin/test/org/perses/benchmark_toys/scala_print/reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/scala_print/golden_reduction_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/scala_print:reduction_golden_test_reduction",
        output_file="bazel-bin/test/org/perses/benchmark_toys/scala_print/result_reduction_golden_test_perses_node_priority_with_dfs_delta_Hello.sc",
        golden_file="test/org/perses/benchmark_toys/scala_print/golden_reduced_Hello.sc"),

    Target(
        target_name="//test/org/perses/benchmark_toys/scala_print:reduce_scala_print_with_token_slicer",
        output_file="bazel-bin/test/org/perses/benchmark_toys/scala_print/Hello_reduced_with_token_slicer.sc",
        golden_file="test/org/perses/benchmark_toys/scala_print/golden_reduced_hello_with_token_slicer.sc"),

    Target(
        target_name="//test/org/perses/benchmark_toys/scala_print:reduce_scala_print_with_token_slicer",
        output_file="bazel-bin/test/org/perses/benchmark_toys/scala_print/reduce_scala_print_with_token_slicer_reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/scala_print/gold_test_reduce_scala_print_with_token_slicer_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/scala_print:reduce_scala_print_with_tree_slicer",
        output_file="bazel-bin/test/org/perses/benchmark_toys/scala_print/Hello_reduced_with_tree_slicer.sc",
        golden_file="test/org/perses/benchmark_toys/scala_print/golden_reduced_hello_with_tree_slicer.sc"),

    Target(
        target_name="//test/org/perses/benchmark_toys/scala_print:reduce_scala_print_with_tree_slicer",
        output_file="bazel-bin/test/org/perses/benchmark_toys/scala_print/reduce_scala_print_with_tree_slicer_reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/scala_print/gold_test_reduce_scala_print_with_tree_slicer_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/rs_print:reduction_golden_test_reduction",
        output_file="bazel-bin/test/org/perses/benchmark_toys/rs_print/reduction_progress.txt",
        golden_file="test/org/perses/benchmark_toys/rs_print/golden_reduction_progress.txt"),

    Target(
        target_name="//test/org/perses/benchmark_toys/rs_print:reduction_golden_test_reduction",
        output_file="bazel-bin/test/org/perses/benchmark_toys/rs_print/result_reduction_golden_test_perses_node_priority_with_dfs_delta_hello.rs",
        golden_file="test/org/perses/benchmark_toys/rs_print/golden_reduced_hello.rs"),

    Target(
        target_name="//test/org/perses:gen_token_counter_file",
        output_file="bazel-bin/test/org/perses/token_count.txt",
        golden_file="test/org/perses/golden_token_count_for_delta1.txt"),

    Target(
        target_name="//test/org/perses:get_perses_cmd_usage",
        output_file="bazel-bin/test/org/perses/perses_cmd_usage.txt",
        golden_file="test/org/perses/golden_perses_cmd_usage.txt"
    ),

    Target(
        target_name="//test/org/perses:get_perses_cmd_usage_verbosity_level",
        output_file="bazel-bin/test/org/perses/perses_cmd_usage_list_verbosity_levels.txt",
        golden_file="test/org/perses/golden_perses_cmd_usage_list_verbosity_levels.txt"
    ),

    Target(
        target_name="//test/org/perses/grammar/go:cp_pnf_go_grammar",
        output_file="bazel-bin/test/org/perses/grammar/go/pnf_go_grammar.g4",
        golden_file="test/org/perses/grammar/go/golden_pnf_go.g4"),

    Target(
        target_name="//test/org/perses/grammar/scala:cp_pnf_scala_grammar",
        output_file="bazel-bin/test/org/perses/grammar/scala/pnf_scala_grammar.g4",
        golden_file="test/org/perses/grammar/scala/golden_pnf_scala.g4"),

    Target(
        target_name="//test/org/perses/grammar/rust:cp_pnf_rust_grammar",
        output_file="bazel-bin/test/org/perses/grammar/rust/pnf_rust_grammar.g4",
        golden_file="test/org/perses/grammar/rust/golden_pnf_rust.g4"),
]

for target in targets:
    subprocess.check_call(["bazel", "build", target.target_name])
    content = None
    with open(target.output_file, "r") as f:
        content = f.read()
    with open(target.golden_file, "w") as f:
        f.write(content)

#!/usr/bin/env python

import subprocess


class Target:

    def __init__(self, target_name, output_file, golden_file):
        self.target_name = target_name
        self.output_file = output_file
        self.golden_file = golden_file


targets = [
    Target(target_name="//src/org/perses/grammar/c:normalize_c_to_pnf",
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
        target_name="//benchmark/toys/delta_1:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/delta_1/result_reduction_golden_test_perses_node_priority_with_dfs_delta_t.c",
        golden_file="benchmark/toys/delta_1/golden_reduced_t.c"),
    Target(
        target_name="//benchmark/toys/delta_1:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/delta_1/reduction_progress.txt",
        golden_file="benchmark/toys/delta_1/golden_reduction_progress.txt"),
    Target(
        target_name="//benchmark/toys/parentheses:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/parentheses/result_reduction_golden_test_perses_node_priority_with_dfs_delta_t.c",
        golden_file="benchmark/toys/parentheses/golden_reduced_t.c"),
    Target(
        target_name="//benchmark/toys/parentheses:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/parentheses/reduction_progress.txt",
        golden_file="benchmark/toys/parentheses/golden_reduction_progress.txt"),
    Target(
        target_name="//benchmark/toys/go_print:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/go_print/reduction_progress.txt",
        golden_file="benchmark/toys/go_print/golden_reduction_progress.txt"),
    Target(
        target_name="//benchmark/toys/go_print:reduction_golden_test_reduction",
        output_file="bazel-bin/benchmark/toys/go_print/result_reduction_golden_test_perses_node_priority_with_dfs_delta_small.go",
        golden_file="benchmark/toys/go_print/golden_reduced_small.go"),
    Target(
        target_name="//test/org/perses:gen_token_counter_file",
        output_file="bazel-bin/test/org/perses/token_count.txt",
        golden_file="test/org/perses/golden_token_count_for_delta1.txt"),
    Target(
        target_name="//test/org/perses/grammar/go:cp_pnf_go_grammar",
        output_file="bazel-bin/test/org/perses/grammar/go/pnf_go_grammar.g4",
        golden_file="test/org/perses/grammar/go/golden_pnf_go.g4"),
]

for target in targets:
    subprocess.check_call(["bazel", "build", target.target_name])
    content = None
    with open(target.output_file, "r") as f:
        content = f.read()
    with open(target.golden_file, "w") as f:
        f.write(content)

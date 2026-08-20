load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//test/org/perses:__subpackages__",
])

kt_jvm_test(
    name = "RecordedProgramTokenizerTest",
    srcs = [
        "RecordedProgramTokenizerTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/listminimizer/microbenchmark:recorded_program_tokenizer",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/program/printer",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:tree_node",
        "//src/org/perses/util:Interval",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "ListMinimizationMicrobenchmarkTest",
    srcs = [
        "ListMinimizationMicrobenchmarkTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer/microbenchmark:list_minimization_microbenchmark",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_test(
    name = "ListMinimizationMicrobenchmarkWriterTest",
    srcs = [
        "ListMinimizationMicrobenchmarkWriterTest.kt",
    ],
    # Associate (not just depend) so the test can reach computeTokenRanges, which is internal.
    associates = [
        "//src/org/perses/listminimizer/microbenchmark:list_minimization_microbenchmark_writer",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/listminimizer/microbenchmark:list_minimization_microbenchmark",
        "//src/org/perses/listminimizer/microbenchmark:recorded_program_tokenizer",
        "//src/org/perses/program",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/program/printer",
        "//src/org/perses/reduction/io",
        "//src/org/perses/util",
        "//src/org/perses/util:AtomicSequenceGenerator",
        "//src/org/perses/util:Interval",
        "//src/org/perses/util/shell",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "ListMinimizerMetricsCollectorTest",
    srcs = [
        "ListMinimizerMetricsCollectorTest.kt",
    ],
    deps = [
        "//:guava",
        "//:jackson",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer/microbenchmark:list_minimizer_metrics_collector",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util:Serialization",
        "//src/org/perses/util/shell",
        "//test/org/perses/listminimizer:AbstractListMinimizerTest",
    ],
)

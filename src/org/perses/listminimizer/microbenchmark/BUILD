load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "recorded_program_tokenizer",
    srcs = [
        "RecordedProgramTokenizer.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/flattokenlist:parser_facade",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/spartree:tree_node",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "list_minimization_microbenchmark",
    srcs = [
        "ListMinimizationMicrobenchmark.kt",
    ],
    deps = [
        "//:guava",
        "//:jackson",
        "//src/org/perses/util:Interval",
        "//src/org/perses/util:Serialization",
    ],
)

kt_jvm_library(
    name = "list_minimization_microbenchmark_writer",
    srcs = [
        "ListMinimizationMicrobenchmarkWriter.kt",
    ],
    deps = [
        ":list_minimization_microbenchmark",
        ":recorded_program_tokenizer",
        "//:antlr_runtime",
        "//:flogger",
        "//src/org/perses/program",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "list_minimizer_metrics_collector",
    srcs = [
        "ListMinimizerMetricsCollector.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/listminimizer",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util:Serialization",
        "//src/org/perses/util:timeutil",
    ],
)

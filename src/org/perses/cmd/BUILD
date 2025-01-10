load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "LanguageControlFlagGroup",
    srcs = [
        "LanguageControlFlagGroup.kt",
    ],
    deps = [
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "reduction_flags",
    srcs = [
        "CacheControlFlagGroup.kt",
        "ExperimentFlagGroup.kt",
        "InputFlagGroup.kt",
        "OutputFlagGroup.kt",
        "OutputRefiningFlagGroup.kt",
        "ProfilingFlagGroup.kt",
        "ReductionAlgorithmControlFlagGroup.kt",
        "ReductionControlFlagGroup.kt",
        "VulcanFlagGroup.kt",
    ],
    exports = [
        ":LanguageControlFlagGroup",
    ],
    deps = [
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/reduction/cache:enum_query_caching_control",
        "//src/org/perses/reduction/cache:test_execution_cache_type",
        "//src/org/perses/util:percentage",
        "//src/org/perses/util/cmd",
        "//src/org/perses/util/shell",
    ],
)

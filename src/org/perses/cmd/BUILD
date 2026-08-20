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
        "EnumListMinimizerMicrobenchmarkingMode.kt",
        "EnumPassMode.kt",
        "ExperimentFlagGroup.kt",
        "InputFlagGroup.kt",
        "LPRFlagGroup.kt",
        "LatraFlagGroup.kt",
        "ListMinimizerMicrobenchmarkingFlagGroup.kt",
        "MimirFlagGroup.kt",
        "OutputFlagGroup.kt",
        "OutputRefiningFlagGroup.kt",
        "PersesFlagGroup.kt",
        "ProfilingFlagGroup.kt",
        "ReductionAlgorithmControlFlagGroup.kt",
        "ReductionControlFlagGroup.kt",
        "TRecFlagGroup.kt",
        "VulcanFlagGroup.kt",
    ],
    exports = [
        ":LanguageControlFlagGroup",
    ],
    deps = [
        "//:guava",
        "//:jackson",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/reduction/reducer:enum_mimir_reduction_algorithm",
        "//src/org/perses/util",
        "//src/org/perses/util:percentage",
        "//src/org/perses/util/cmd",
        "//src/org/perses/util/hashing",
        "//src/org/perses/util/shell",
    ],
)

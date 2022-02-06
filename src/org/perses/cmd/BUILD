package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "LanguageExtFlags",
    srcs = [
        "LanguageExtFlags.kt",
    ],
    deps = [
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "reduction_flags",
    srcs = [
        "CacheControlFlags.kt",
        "ExperimentFlags.kt",
        "InputFlags.kt",
        "LanguageExtFlags.kt",
        "OutputFlags.kt",
        "OutputRefiningFlags.kt",
        "ProfilingFlags.kt",
        "ReductionAlgorithmControlFlags.kt",
        "ReductionControlFlags.kt",
    ],
    exports = [
        ":LanguageExtFlags",
    ],
    deps = [
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/reduction/cache:enum_query_caching_control",
        "//src/org/perses/reduction/cache:test_execution_cache_type",
        "//src/org/perses/util:percentage",
        "//src/org/perses/util:shell",
        "//src/org/perses/util/cmd",
    ],
)

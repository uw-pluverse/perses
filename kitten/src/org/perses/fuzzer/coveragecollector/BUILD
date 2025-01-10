package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_library(
    name = "coverage_collector",
    srcs = [
        "AFLCoverageCollector.kt",
        "CoverageCollectorFactory.kt",
        "GccCoverageCollector.kt",
        "GcovCoverageCollector.kt",
        "ICoverageCollector.kt",
        "LcovCoverageCollector.kt",
        "NullCoverageCollector.kt",
        "RustcCoverageCollector.kt",
    ],
    resource_strip_prefix = "kitten/src/",
    resources = [
        ":libafl_coverage_jni.so",
    ],
    deps = [
        "//:guava",
        "//:jackson",
        "//kitten/src/org/perses/fuzzer:command_options",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//src/org/perses/util",
        "//src/org/perses/util/shell",
    ],
)

cc_library(
    name = "afl_coverage_jni_lib",
    srcs = ["afl_coverage_jni.cc"],
    hdrs = ["afl_coverage_jni.h"],
    includes = [
        "external/local_jdk/include",
        "external/local_jdk/include/linux",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "@bazel_tools//tools/jdk:jni",
    ],
    alwayslink = True,
)

cc_binary(
    name = "libafl_coverage_jni.so",
    linkshared = True,
    visibility = ["//visibility:private"],
    deps = [":afl_coverage_jni_lib"],
)

package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "XCovCoverageCollectorTest",
    srcs = ["XCovCoverageCollectorTest.kt"],
    data = ["//kitten/test/fuzzer_test_data"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/coveragecollector:coverage_collector",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "AFLCoverageCollectorTest",
    srcs = ["AFLCoverageCollectorTest.kt"],
    data = [
        "//kitten/test/fuzzer_test_data",
        "//kitten/test/fuzzer_test_data/coverage_collector_test:files",
    ],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/coveragecollector:coverage_collector",
        "//test/org/perses:test_util",
    ],
)

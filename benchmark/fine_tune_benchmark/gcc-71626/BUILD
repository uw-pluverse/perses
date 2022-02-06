package(default_visibility = ["//visibility:public"])

load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

filegroup(
    name = "gcc71626",
    srcs = [
        "r.sh",
        "small.c",
    ],
)

sanity_test(
    name = "sanity_test",
    source_files = ["small.c"],
    test_script = "r.sh",
)

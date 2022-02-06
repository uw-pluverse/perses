package(default_visibility = ["//visibility:public"])

load("//benchmark:benchmark.bzl", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["small.c"],
    test_script = "r.sh",
)

filegroup(
    name = "gcc59903",
    srcs = [
        "orig.c",
        "r.sh",
        "small.c",
    ],
)

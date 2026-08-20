package(default_visibility = ["//visibility:public"])

exports_files(["test.bzl"])

# The harness the sanity_test macro in test.bzl stages and runs. It lives here, next to
# the macro that consumes it, rather than in //benchmark: its callers are spread across
# //test, //ppr, //astra and //fision, and only some of them are benchmarks.
filegroup(
    name = "sanity_test",
    srcs = ["sanity_test.sh"],
)

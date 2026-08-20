load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_test",
)

package(default_visibility = ["//test/org/perses:__subpackages__"])

kt_jvm_test(
    name = "PassLevelCacheTest",
    srcs = [
        "PassLevelCacheTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/reduction/cache:PassLevelCache",
        "//src/org/perses/reduction/reducer:node_based_reducer",
    ],
)

kt_jvm_test(
    name = "LogicalSizedArrayTest",
    srcs = ["LogicalSizedArrayTest.kt"],
    deps = [
        "//:asm",
        "//:truth",
        "//src/org/perses/reduction/cache:LogicalSizedArray",
    ],
)

kt_jvm_test(
    name = "NullQueryCacheTest",
    srcs = ["NullQueryCacheTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/reduction/cache:null_query_cache",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction/io:CommonReductionIOManagerData",
    ],
)

kt_jvm_test(
    name = "IntervalArrayExpanderTest",
    srcs = ["IntervalArrayExpanderTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction/cache:interval_expander",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)

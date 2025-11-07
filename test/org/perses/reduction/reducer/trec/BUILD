load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_test(
    name = "TokenCanonicalizerFunctionalTest",
    srcs = [
        "TokenCanonicalizerFunctionalTest.kt",
    ],
    data = [
        "//test/org/perses/benchmark_toys/python3_print:files_for_testing_TRec",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/reduction/reducer/trec",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "TokenCanonicalizerTest",
    srcs = ["TokenCanonicalizerTest.kt"],
    associates = [
        "//src/org/perses/reduction/reducer/trec",
    ],
    data = [
        "//test/org/perses/benchmark_toys/wasm:files",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/spartree",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

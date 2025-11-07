load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "WasmParserFacadeTest",
    srcs = ["WasmParserFacadeTest.kt"],
    data = [
        "//test_data/wat_programs",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/wasm:parser_facade",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ReductionScriptGeneratorTest",
    srcs = ["ReductionScriptGeneratorTest.kt"],
    test_class = "org.perses.fuzzer.reduction.ReductionScriptGeneratorTest",
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/compilers/c",
        "//kitten/src/org/perses/fuzzer/reduction",
    ],
)

kt_jvm_test(
    name = "DeltaFolderTest",
    srcs = ["DeltaFolderTest.kt"],
    test_class = "org.perses.fuzzer.reduction.DeltaFolderTest",
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/reduction",
        "//kitten/test/org/perses/fuzzer:FakeCompilationAction",
    ],
)

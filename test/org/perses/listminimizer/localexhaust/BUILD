load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_test(
    name = "UniformLengthDeletionPatternSetTest",
    srcs = ["UniformLengthDeletionPatternSetTest.kt"],
    associates = [
        "//src/org/perses/listminimizer/localexhaust",
    ],
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "LocalExhaustWindowedMinimizerTest",
    srcs = ["LocalExhaustWindowedMinimizerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:interfaces",
        "//test/org/perses/listminimizer:AbstractListMinimizerTest",
    ],
)

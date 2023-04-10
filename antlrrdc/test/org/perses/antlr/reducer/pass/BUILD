load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ActionNodeCollectorTest",
    srcs = [
        "ActionNodeCollectorTest.kt",
    ],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//antlrrdc/src/org/perses/antlr/reducer/pass:action_node_collector",
        "//src/org/perses/util",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)

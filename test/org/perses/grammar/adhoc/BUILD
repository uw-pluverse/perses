load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "AdhocGrammarUtilTest",
    srcs = ["AdhocGrammarUtilTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_util",
    ],
)

kt_jvm_test(
    name = "AdhocGrammarInstallerTest",
    srcs = ["AdhocGrammarInstallerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses:perses_contants",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_inaller_lib",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_util",
        "//src/org/perses/grammar/adhoc:command_options",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)

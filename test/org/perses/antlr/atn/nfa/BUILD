load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load("@rules_java//java:defs.bzl", "java_binary")
load(
    "//test:test.bzl",
    "golden_test",
)

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_test(
    name = "NfaTest",
    srcs = [
        "NfaTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:truth",
        "//src/org/perses/antlr/atn:lexer_wrapper",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
        "//test/org/perses/antlr/atn:OrigC",
        "//test/org/perses/antlr/atn:TestLexer",
    ],
)

kt_jvm_test(
    name = "ConcatenatedNfaViewTest",
    srcs = [
        "ConcatenatedNfaViewTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:truth",
        "//src/org/perses/antlr/atn/nfa",
    ],
)

kt_jvm_library(
    name = "NfaDumpMain",
    srcs = [
        "NfaDumpMain.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//src/org/perses/antlr/atn:lexer_wrapper",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
        "//test/org/perses/antlr/atn:OrigC",
    ],
)

BIN_NAME = "dump_nfa_or_OrigCLexer_BIN"

java_binary(
    name = BIN_NAME,
    main_class = "org.perses.antlr.atn.nfa.NfaDumpMain",
    runtime_deps = [
        ":NfaDumpMain",
    ],
)

OUT_FILE = "all_NFAs_of_OrigCLexer.txt"

genrule(
    name = "dump_all_nfas_of_OrigC",
    outs = [OUT_FILE],
    cmd = "$(location :%s) $(location %s)" % (BIN_NAME, OUT_FILE),
    tools = [
        ":" + BIN_NAME,
    ],
)

golden_test(
    name = "golden_test_all_NFAs_of_OrigCLexer",
    golden_file = "golden_all_NFAs_of_OrigCLexer.txt",
    test_file = OUT_FILE,
)

package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load(
    "//test/org/perses:test.bzl",
    "golden_test",
)

kt_jvm_test(
    name = "NFATest",
    srcs = [
        "NFATest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:truth",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/antlr/atn/nfa",
        "//test/org/perses/antlr/atn:OrigC",
        "//test/org/perses/antlr/atn:RandomMock",
        "//test/org/perses/antlr/atn:TestLexer",
        "//test/org/perses/antlr/atn:TestUtil",
    ],
)

kt_jvm_library(
    name = "NFADumpMain",
    srcs = [
        "NFADumpMain.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/antlr/atn/nfa",
        "//test/org/perses/antlr/atn:OrigC",
    ],
)

BIN_NAME = "dump_nfa_or_OrigCLexer_BIN"

java_binary(
    name = BIN_NAME,
    main_class = "org.perses.antlr.atn.nfa.NFADumpMain",
    runtime_deps = [
        ":NFADumpMain",
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

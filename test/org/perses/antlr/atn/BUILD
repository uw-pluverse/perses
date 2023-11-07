package(default_visibility = [
    "//visibility:public",
])

load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
    "antlr_codegen_lexer",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

antlr_codegen_lexer(
    name = "TestLexer",
    java_pkg_name = "org.perses.antlr.atn",
    lexer_grammar_file = "TestLexer.g4",
    lexer_java_file_name = "TestLexer.java",
)

kt_jvm_library(
    name = "TestUtil",
    srcs = ["TestUtil.kt"],
    deps = [
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/simulator/ast",
    ],
)

kt_jvm_test(
    name = "LexerAtnWrapperTest",
    srcs = ["LexerAtnWrapperTest.kt"],
    jvm_flags = ["-javaagent:$(location //third_party/memory_measurer:object_explorer)"],
    deps = [
        ":TestLexer",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/antlr/atn:OrigC",
        "//third_party/memory_measurer:object_explorer",
    ],
)

java_binary(
    name = "antlr_tool_test",
    args = [
        "$(location TestLexer.g4)",
        "-atn",
    ],
    data = [
        "TestLexer.g4",
    ],
    main_class = "org.antlr.v4.Tool",
    visibility = ["//visibility:public"],
    runtime_deps = ["//:antlr_tool"],
)

antlr_codegen_combined(
    name = "OrigC",
    grammar_file = "OrigC.g4",
    java_pkg_name = "org.perses.antlr.atn",
    lexer_java_file_name = "OrigCLexer.java",
    parser_java_file_name = "OrigCParser.java",
)

kt_jvm_library(
    name = "RandomMock",
    srcs = [
        "DecisionMakerMock.kt",
    ],
    deps = [
        "//src/org/perses/antlr/atn:AbstractRandom",
    ],
)

kt_jvm_test(
    name = "AtnTest",
    srcs = [
        "AtnTest.kt",
    ],
    associates = ["//src/org/perses/antlr/atn"],
    deps = [
        ":OrigC",
        ":RandomMock",
        ":TestLexer",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:truth",
        "//src/org/perses/antlr/atn/simulator/ast",
    ],
)

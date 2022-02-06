package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "util",
    srcs = ["Util.kt"],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
    ],
)

#java_library(
#    name = "lexer_parser_combiner",
#    srcs = ["LexerParserCombiner.java"],
#    deps = [
#        ":util",
#        "//antlropt/src/org/perses/antlr/ast",
#        "@maven//:com_beust_jcommander",
#
#    "//:guava",
#    ],
#)

#java_binary(
#    name = "combine_lexer_parser_bin",
#    jvm_flags = ["-ea"],
#    main_class = "org.perses.antlr.util.LexerParserCombiner",
#    runtime_deps = [":lexer_parser_combiner"],
#)

kt_jvm_library(
    name = "antlr_tool_wrapper",
    srcs = ["AntlrToolWrapper.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
        "//src/org/perses/util:file_name_content_pair",
        "@maven//:org_antlr_antlr4",
    ],
)

package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
    "antlr_codegen_parser",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageSolidity.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

filegroup(
    name = "grammar_files",
    srcs = [
        "Solidity.g4",
        "SolidityLexer.g4",
    ],
)

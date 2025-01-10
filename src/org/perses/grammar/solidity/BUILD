load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

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

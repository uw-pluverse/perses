package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "testing_configuration",
    srcs = [
        "TestingConfiguration.kt",
    ],
    deps = [
        "//:flogger",
        "//:jackson",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/c:pnf_c_grammar_lexer_",
        "//src/org/perses/grammar/go:go_lexer",
        "//src/org/perses/grammar/go:language_kind",
        "//src/org/perses/grammar/javascript:javascript_lexer",
        "//src/org/perses/grammar/javascript:language_kind",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/grammar/rust:pnf_rust_grammar_lexer_",
        "//src/org/perses/grammar/scala:language_kind",
        "//src/org/perses/grammar/scala:pnf_scala_grammar_lexer_",
        "//src/org/perses/grammar/solidity:language_kind",
        "//src/org/perses/grammar/solidity/preprocessed:solidity_lexer",
        "//src/org/perses/grammar/sysverilog:language_kind",
        "//src/org/perses/grammar/sysverilog:sysverilog_lexer",
        "//src/org/perses/util:YamlUtil",
    ],
)

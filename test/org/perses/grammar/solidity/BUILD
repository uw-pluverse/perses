load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

#genrule(
#    name = "cp_pnf_solidity_grammar",
#    srcs = ["//src/org/perses/grammar/solidity:normalize_solidity_to_pnf"],
#    outs = ["pnf_solidity_grammar.g4"],
#    cmd = "cp \"$<\" \"$@\"",
#)
#
#golden_test(
#    name = "test_pnf_solidity_grammar",
#    golden_file = "golden_pnf_solidity.g4",
#    test_file = "pnf_solidity_grammar.g4",
#)

kt_jvm_test(
    name = "PnfSolidityParserFacadeTest",
    srcs = [
        "PnfSolidityParserFacadeTest.kt",
    ],
    data = [
        "//test/org/perses/benchmark_toys/solidity:solidity_program",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/solidity/preprocessed:orig_solidity_parser",
        "//src/org/perses/grammar/solidity/preprocessed:parser_facade",
        "//src/org/perses/grammar/solidity/preprocessed:solidity_lexer",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "OrigSolidityParserTest",
    srcs = [
        "OrigSolidityParserTest.kt",
    ],
    data = [
        "parsable_solidity_programs.txt",
        "//test/org/perses/benchmark_toys/solidity:solidity_program",
        "//test_data/solidity_programs",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/solidity/preprocessed:orig_solidity_parser",
        "//src/org/perses/grammar/solidity/preprocessed:solidity_lexer",
        "//test/org/perses:test_util",
    ],
)

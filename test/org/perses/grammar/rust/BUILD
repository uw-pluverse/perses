load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

genrule(
    name = "cp_pnf_rust_grammar",
    srcs = ["//src/org/perses/grammar/rust:normalize_rust_to_pnf"],
    outs = ["pnf_rust_grammar.g4"],
    cmd = "cp \"$<\" \"$@\"",
)

golden_test(
    name = "test_pnf_rust_grammar",
    golden_file = "golden_pnf_rust.g4",
    test_file = "pnf_rust_grammar.g4",
)

kt_jvm_test(
    name = "PnfRustParserFacadeTest",
    size = "enormous",  # This is a slow test.
    srcs = ["PnfRustParserFacadeTest.kt"],
    data = ["golden_fail_list.txt"],
    shard_count = 7,
    test_class = "org.perses.grammar.rust.PnfRustParserFacadeTest",
    deps = [
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/rust:pnfrust_parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

java_binary(
    name = "RustParserFailListGenerator",
    srcs = ["RustParserFailListGenerator.java"],
    main_class = "org.perses.grammar.rust.RustParserFailListGenerator",
    deps = [
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/rust:pnfrust_parser_facade",
        "//test/org/perses:test_util",
        "@maven//:com_google_guava_guava",
    ],
)

genrule(
    name = "generate_rust_parser_faillist",
    srcs = ["//test_data/rust_programs:rust_testsuite"],
    outs = ["rust_parser_failed_files.txt"],
    cmd = "$(location :RustParserFailListGenerator) $@",
    tools = [":RustParserFailListGenerator"],
)

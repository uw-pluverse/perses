load("//test/org/perses:test.bzl", "copy", "cross_folder_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//:perses.bzl", "kt_binary_for_genrule")

cross_folder_golden_test(
    name = "test_pnf_rust_grammar",
    golden_file = "golden_pnf_rust.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/rust:normalize_rust_to_pnf",
)

kt_jvm_test(
    name = "PnfRustParserFacadeTest",
    size = "enormous",  # This is a slow test.
    srcs = ["PnfRustParserFacadeTest.kt"],
    data = [
        "golden_fail_list.txt",
        "//test_data/rust_programs:whole_rust_repo",
    ],
    shard_count = 7,
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/rust:orig_parser_facade",
        "//src/org/perses/grammar/rust:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)

kt_binary_for_genrule(
    name = "RustParserFailListGenerator",
    srcs = ["RustParserFailListGenerator.kt"],
    jvm_flags = ["-ea"],
    main_class = "org.perses.grammar.rust.RustParserFailListGenerator",
    deps = [
        "//:guava",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/rust:orig_parser_facade",
        "//src/org/perses/grammar/rust:parser_facade",
        "//test/org/perses:test_util",
    ],
)

# cnsun: disabled now, and will need to investigate the rust grammar again.
#genrule(
#    name = "generate_rust_parser_faillist",
#    testonly = True,
#    srcs = ["//test_data/rust_programs:rust_testsuite"],
#    outs = ["rust_parser_failed_files.txt"],
#    cmd = "$(location :RustParserFailListGenerator) $@",
#    tools = [":RustParserFailListGenerator"],
#)

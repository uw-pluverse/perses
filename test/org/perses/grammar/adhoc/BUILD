load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load(
    "//test/org/perses:test.bzl",
    "golden_test",
)

kt_jvm_test(
    name = "AdhocGrammarUtilTest",
    srcs = ["AdhocGrammarUtilTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_util",
    ],
)

kt_jvm_test(
    name = "AdhocGrammarInstallerTest",
    srcs = ["AdhocGrammarInstallerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses:perses_contants",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_inaller_lib",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_util",
        "//src/org/perses/grammar/adhoc:command_options",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)

kt_jvm_library(
    name = "facade_dump_main_lib",
    srcs = [
        "ExistingLangParserFacadeStubTemplateDumpMain.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/grammar/adhoc:parser_facade_template",
        "//src/org/perses/util",
    ],
)

java_binary(
    name = "facade_dump_bin",
    main_class = "org.perses.grammar.adhoc.ExistingLangParserFacadeStubTemplateDumpMain",
    runtime_deps = [
        ":facade_dump_main_lib",
    ],
)

generated_facade_for_combined_grammar = "generated_facade_for_combined_grammar_file"

genrule(
    name = "gen_generated_facade_for_combined_grammar",
    outs = [generated_facade_for_combined_grammar],
    cmd = "$(location facade_dump_bin) $(location %s)" % generated_facade_for_combined_grammar,
    tools = [
        ":facade_dump_bin",
    ],
)

golden_test(
    name = "golden_test_generated_facade_for_combined_grammar",
    golden_file = "golden_generated_facade_for_combined_grammar.txt",
    test_file = generated_facade_for_combined_grammar,
)

generated_facade_for_separate_grammar = "generated_facade_for_separate_grammar_file"

genrule(
    name = "gen_generated_facade_for_separate_grammar",
    outs = [generated_facade_for_separate_grammar],
    cmd = "$(location facade_dump_bin) $(location %s) fake_lexer_file.g4" % generated_facade_for_separate_grammar,
    tools = [
        ":facade_dump_bin",
    ],
)

golden_test(
    name = "golden_test_generated_facade_for_separate_grammar",
    golden_file = "golden_generated_facade_for_separate_grammar.txt",
    test_file = generated_facade_for_separate_grammar,
)

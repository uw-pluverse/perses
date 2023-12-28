package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "adhoc_grammar_util",
    srcs = ["AdhocGrammarUtil.kt"],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
    ],
)

kt_jvm_library(
    name = "adhoc_grammar_configuration",
    srcs = [
        "AdhocGrammarConfiguration.kt",
        "GrammarFlagGroup.kt",
    ],
    deps = [
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses:perses_contants",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/util:YamlUtil",
        "//src/org/perses/util/cmd",
        "//src/org/perses/util/java",
    ],
)

kt_jvm_library(
    name = "command_options",
    srcs = ["CommandOptions.kt"],
    deps = [
        ":adhoc_grammar_configuration",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "adhoc_grammar_inaller_lib",
    srcs = [
        "AdhocGrammarInstaller.kt",
        "InstallerMain.kt",
        "OrigGrammar.kt",
    ],
    deps = [
        ":adhoc_grammar_util",
        ":command_options",
        ":parser_facade_template",
        "//:kotlin_stdib",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//antlropt/src/org/perses/antlr/pnf:pnf_normalizer",
        "//src/org/perses:perses_contants",
        "//src/org/perses/antlr:antlr_compiler",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageAdhoc.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program:serializable_language_kind",
    ],
)

kt_jvm_library(
    name = "parser_facade_template",
    srcs = [
        "AbstractParserFacadeStubTemplate.kt",
        "ExistingLangParserFacadeStubTemplate.kt",
        "ParserFacadeStubFactory.kt",
        "YamlParserFacadeStubTemplate.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/antlr:abstract_grammar_stub",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_configuration",
        "//src/org/perses/program:serializable_language_kind",
    ],
)

kt_jvm_library(
    name = "adhoc_parser_facade_factory_util",
    srcs = [
        "AdhocParserFacadeFactoryUtil.kt",
    ],
    deps = [
        ":adhoc_grammar_configuration",
        "//src/org/perses/grammar:facade_factory",
    ],
)

java_binary(
    name = "perses_adhoc_installer",
    jvm_flags = ["-ea"],
    main_class = "org.perses.grammar.adhoc.InstallerMain",
    runtime_deps = [
        ":adhoc_grammar_inaller_lib",
        ":command_options",
        ":language_kind",
        "//:guava",
        "//src/org/perses:perses_contants",
        "//src/org/perses/util:default_logging_configurations",
        "//src/org/perses/util/cmd",
        "//version/org/perses/version",
    ],
)

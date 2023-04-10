package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//third_party/proguard:proguard.bzl", "proguard_strip")

kt_jvm_library(
    name = "perses_contants",
    srcs = ["PersesConstants.kt"],
    deps = [
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "command_options",
    srcs = ["CommandOptions.kt"],
    deps = [
        "//:flogger",
        "//:guava",
        "//:jcommander",
        "//src/org/perses/cmd:reduction_flags",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_configuration",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/reduction/cache:enum_query_caching_control",
        "//src/org/perses/reduction/cache:test_execution_cache_type",
        "//src/org/perses/util:percentage",
        "//src/org/perses/util/cmd",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_library(
    name = "abstract_reduction_main",
    srcs = ["AbstractMain.kt"],
    deps = [
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/cpp:language_kind",
        "//src/org/perses/grammar/cpp:parser_facade",
        "//src/org/perses/grammar/go:language_kind",
        "//src/org/perses/grammar/go:parser_facade",
        "//src/org/perses/grammar/java:language_kind",
        "//src/org/perses/grammar/java:parser_facade",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/grammar/rust:parser_facade",
        "//src/org/perses/grammar/scala:language_kind",
        "//src/org/perses/grammar/scala:parser_facade",
        "//src/org/perses/grammar/solidity:language_kind",
        "//src/org/perses/grammar/solidity/preprocessed:parser_facade",
        "//src/org/perses/grammar/sysverilog:language_kind",
        "//src/org/perses/grammar/sysverilog:parser_facade",
        "//src/org/perses/reduction:reduction_driver_interface",
        "//src/org/perses/util:default_logging_configurations",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "perses_lib",
    srcs = ["Main.kt"],
    deps = [
        ":abstract_reduction_main",
        ":command_options",
        ":perses_contants",
        "//:antlr_tool",
        "//:guava",
        "//:jcommander",
        "//:kotlin_stdib",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_configuration",
        "//src/org/perses/grammar/adhoc:adhoc_parser_facade_factory_util",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/cpp:language_kind",
        "//src/org/perses/grammar/cpp:parser_facade",
        "//src/org/perses/grammar/go:language_kind",
        "//src/org/perses/grammar/go:parser_facade",
        "//src/org/perses/grammar/java:language_kind",
        "//src/org/perses/grammar/java:parser_facade",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/grammar/rust:parser_facade",
        "//src/org/perses/grammar/scala:language_kind",
        "//src/org/perses/grammar/scala:parser_facade",
        "//src/org/perses/grammar/solidity:language_kind",
        "//src/org/perses/grammar/solidity/preprocessed:parser_facade",
        "//src/org/perses/grammar/sysverilog:language_kind",
        "//src/org/perses/grammar/sysverilog:parser_facade",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction:reduction_driver_interface",
        "//src/org/perses/util:default_logging_configurations",
        "//src/org/perses/util/cmd",
        "//version/org/perses/version",
    ],
)

java_binary(
    name = "perses",
    jvm_flags = ["-ea"],
    main_class = "org.perses.Main",
    runtime_deps = [
        ":perses_lib",
    ],
)

proguard_strip(
    name = "strip_perses",
    input_jar = "perses_deploy.jar",
    main_class = "public class org.perses.Main",
    output_jar = "stripped_perses.jar",
)

java_import(
    name = "stripped_perses_lib",
    jars = ["stripped_perses.jar"],
)

# FIXME: does not work.
java_binary(
    name = "stripped_perses_bin",
    main_class = "org.perses.Main",
    runtime_deps = [
        ":stripped_perses_lib",
    ],
)

java_binary(
    name = "token_counter",
    jvm_flags = ["-ea"],
    main_class = "org.perses.TokenCounterMain",
    runtime_deps = [
        ":token_counter_lib",
    ],
)

kt_jvm_library(
    name = "token_counter_lib",
    srcs = ["TokenCounterMain.kt"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:jcommander",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/cmd:LanguageControlFlags",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/adhoc:adhoc_parser_facade_factory_util",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/util/cmd",
    ],
)

proguard_strip(
    name = "stripped_token_counter_deploy",
    input_jar = "token_counter_deploy.jar",
    main_class = "public class org.perses.TokenCounterMain",
    output_jar = "stripped_token_counter_deploy.jar",
)

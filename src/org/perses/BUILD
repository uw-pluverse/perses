package(default_visibility = [
    "//visibility:public",
])

java_library(
    name = "perses_exception",
    srcs = ["PersesRuntimeException.java"],
)

java_library(
    name = "command_options",
    srcs = ["CommandOptions.java"],
    deps = [
        ":perses_exception",
        "@maven//:com_beust_jcommander",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "language_kind",
    srcs = ["LanguageKind.java"],
    deps = ["@maven//:com_google_guava_guava"],
)

java_binary(
    name = "perses",
    srcs = ["Main.java"],
    main_class = "org.perses.Main",
    resources = ["logging.properties"],
    runtime_deps = [
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
    deps = [
        ":command_options",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/reduction:reduction_driver",
        "@maven//:com_beust_jcommander",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

java_binary(
    name = "token_counter",
    srcs = ["TokenCounterMain.java"],
    main_class = "org.perses.TokenCounterMain",
    runtime_deps = [
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
    deps = [
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_factory",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

DEFAULT_DEPS = [
    "//src/org/perses/program",
    "//test/org/perses:test_util",
    "//test/org/perses:truth",
    "@maven//:com_google_guava_guava",
]

java_test(
    name = "TokenizedProgramTest",
    srcs = ["TokenizedProgramTest.java"],
    data = [
        "//test_data/delta_1",
        "//test_data/java_helloworld",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.program.TokenizedProgramTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "SourceFileTest",
    srcs = ["SourceFileTest.java"],
    data = [
        "//test_data/delta_1",
    ],
    test_class = "org.perses.program.SourceFileTest",
    deps = DEFAULT_DEPS + [
        "//src/org/perses:language_kind",
    ],
)

java_test(
    name = "TokenizedProgramFactoryTest",
    srcs = ["TokenizedProgramFactoryTest.java"],
    data = [
        "clang-27747.c",
    ],
    test_class = "org.perses.program.TokenizedProgramFactoryTest",
    deps = DEFAULT_DEPS + [
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

package(default_visibility = ["//kitten/test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_library(
    name = "RustTestUtil",
    testonly = True,
    srcs = ["RustTestUtil.kt"],
    data = ["//kitten/test/mock_scripts:mock_rustc.py"],
    deps = [
        ":FuzzerDriverTest",
        "//:flogger",
        "//:guava",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/compilers/rust",
        "//kitten/src/org/perses/fuzzer/config:testing_configuration",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
        "//src/org/perses/util",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_test(
    name = "SparTreeFuzzerTest",
    srcs = ["SparTreeFuzzerTest.kt"],
    data = [
        "//kitten/test/fuzzer_test_data",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/go:language_kind",
        "//src/org/perses/grammar/java:language_kind",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "CrashClusterIndexTest",
    srcs = ["CrashClusterIndexTest.kt"],
    deps = [
        ":RustTestUtil",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
    ],
)

kt_jvm_test(
    name = "FuzzerDriverTest",
    srcs = ["FuzzerDriverTest.kt"],
    associates = [
        "//kitten/src/org/perses/fuzzer:command_options",
    ],
    data = ["//kitten/test/org/perses/fuzzer/rust:rustc_mocks"],
    test_class = "org.perses.fuzzer.FuzzerDriverTest",
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_test(
    name = "CrashInstanceFolderTest",
    srcs = ["CrashInstanceFolderTest.kt"],
    test_class = "org.perses.fuzzer.CrashInstanceFolderTest",
    deps = [
        ":FakeCompilationAction",
        ":FuzzerDriverTest",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/compilers/c",
    ],
)

kt_jvm_test(
    name = "FindingFolderTest",
    srcs = ["FindingFolderTest.kt"],
    test_class = "org.perses.fuzzer.FindingFolderTest",
    deps = [
        ":RustTestUtil",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//src/org/perses/util:timeutil",
    ],
)

kt_jvm_test(
    name = "CommandOptionsTest",
    srcs = ["CommandOptionsTest.kt"],
    test_class = "org.perses.fuzzer.CommandOptionsTest",
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//src/org/perses/util:timeutil",
    ],
)

kt_jvm_library(
    name = "FakeCompilationAction",
    srcs = ["FakeCompilationAction.kt"],
    deps = [
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
    ],
)

kt_jvm_test(
    name = "ProcessingFolderTest",
    srcs = ["ProcessingFolderTest.kt"],
    deps = [
        ":RustTestUtil",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
    ],
)

kt_jvm_test(
    name = "ReportedBugFolderTest",
    srcs = ["ReportedBugFolderTest.kt"],
    data = [
        "//kitten/reported_bugs/c:reported_c_bugs",
        "//kitten/reported_bugs/rust:reported_rust_bugs",
        "//kitten/reported_bugs/scala:reported_scala_bugs",
        "//kitten/reported_bugs/solidity:reported_solidity_bugs",
    ],
    deps = [
        ":RustTestUtil",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/c",
        "//kitten/src/org/perses/fuzzer/compilers/scala",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
    ],
)

kt_jvm_test(
    name = "ExtensionScriptTest",
    srcs = ["ExtensionScriptTest.kt"],
    deps = [
        ":RustTestUtil",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:kira_lib",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "DistributionTableTest",
    srcs = ["DistributionTableTest.kt"],
    deps = [
        ":RustTestUtil",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:kira_lib",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "SystemTest",
    srcs = ["SystemTest.kt"],
    data = [
        "//kitten/reported_bugs/c:reported_c_bugs",
        "//kitten/reported_bugs/rust:reported_rust_bugs",
        "//kitten/reported_bugs/scala:reported_scala_bugs",
    ],
    deps = [
        ":RustTestUtil",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:kira_lib",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "LanguageModelTest",
    srcs = ["LanguageModelTest.kt"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TreeToSequenceConverterTest",
    srcs = ["TreeToSequenceConverterTest.kt"],
    data = ["//kitten/test/fuzzer_test_data"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/languagemodel:node_representation",
        "//test/org/perses:test_util",
    ],
)

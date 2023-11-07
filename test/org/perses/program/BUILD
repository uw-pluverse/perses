DEFAULT_DEPS = [
    "//src/org/perses/program",
    "//test/org/perses:test_util",
    "//:truth",
    "//src/org/perses/program/printer",
    "//:guava",
]

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "LanguageKindTest",
    srcs = ["LanguageKindTest.kt"],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "TokenizedProgramTest",
    srcs = ["TokenizedProgramTest.kt"],
    data = [
        "//test_data/delta_1",
        "//test_data/java_helloworld",
        "//test_data/parentheses",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "SourceFileTest",
    srcs = ["SourceFileTest.kt"],
    data = [
        "//test_data/delta_1",
    ],
    deps = DEFAULT_DEPS + [
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_test(
    name = "ScriptFileTest",
    srcs = ["ScriptFileTest.kt"],
    data = [
        "//test_data/delta_1",
    ],
    deps = DEFAULT_DEPS + [
        "//:kotlin_stdib",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "LanguageKindTestUtil",
    srcs = ["LanguageKindTestUtil.kt"],
    visibility = ["//visibility:public"],
    deps = DEFAULT_DEPS + [
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_test(
    name = "TokenizedProgramFactoryTest",
    srcs = ["TokenizedProgramFactoryTest.kt"],
    deps = DEFAULT_DEPS + [
        "//:antlr_runtime",
        "//src/org/perses/grammar/c:language_kind",
    ],
)

kt_jvm_test(
    name = "SerializableLanguageKindTest",
    srcs = ["SerializableLanguageKindTest.kt"],
    associates = ["//src/org/perses/program:serializable_language_kind"],
    deps = [
        "//:jackson",
        "//:truth",
    ],
)

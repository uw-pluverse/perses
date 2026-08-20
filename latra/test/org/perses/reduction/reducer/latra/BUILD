load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "LatraArgumentsTest",
    srcs = [
        "LatraArgumentsTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
    ],
)

kt_jvm_test(
    name = "WatFineGritTransformationListTest",
    srcs = ["WatFineGritTransformationListTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra/wat",
        "//latra/test/org/perses/reduction/reducer/latra:AbstractTransformationTest",
    ],
)

kt_jvm_test(
    name = "WatCoarseGritTransformationListTest",
    srcs = ["WatCoarseGritTransformationListTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra/wat",
        "//latra/test/org/perses/reduction/reducer/latra:AbstractTransformationTest",
    ],
)

kt_jvm_library(
    name = "AbstractTransformationTest",
    srcs = [
        "AbstractTransformationTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TransformationUtilityForWATTest",
    srcs = [
        "TransformationUtilityForWATTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/grammar/wasm:parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TransformationUtilityForSmtTest",
    srcs = [
        "TransformationUtilityForSmtTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TransformationUtilityForCTest",
    srcs = [
        "TransformationUtilityForCTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_library(
    name = "LatraTestUtil",
    srcs = [
        "LatraTestUtil.kt",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_test(
    name = "CLatraTransformationTest",
    srcs = [
        "CLatraTransformationTest.kt",
    ],
    associates = ["//latra/src/org/perses/reduction/reducer/latra/c"],
    deps = [
        ":AbstractTransformationTest",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "FullFunctionalLatraRewriterBuilderTest",
    srcs = [
        "FullFunctionalLatraRewriterBuilderTest.kt",
    ],
    associates = [
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
    ],
    deps = [
        ":LatraTestUtil",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "SMTLatraTransformationTest",
    srcs = [
        "SMTLatraTransformationTest.kt",
    ],
    associates = ["//latra/src/org/perses/reduction/reducer/latra/smt"],
    deps = [
        ":AbstractTransformationTest",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "RustLatraTransformationTest",
    srcs = [
        "RustLatraTransformationTest.kt",
    ],
    associates = ["//latra/src/org/perses/reduction/reducer/latra/rust"],
    deps = [
        ":AbstractTransformationTest",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:orig_c_grammar",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

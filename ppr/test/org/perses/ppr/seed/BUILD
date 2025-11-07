load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

PERSES_SEED_REDUCER_BIN = "//ppr/src/org/perses/ppr/seed:main"

kt_jvm_test(
    name = "SeedOutputManagerFactoryTest",
    srcs = ["SeedOutputManagerFactoryTest.kt"],
    deps = [
        "//:truth",
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//ppr/src/org/perses/ppr/seed:output_manager",
        "//ppr/src/org/perses/ppr/seed:reduction_inputs",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/program/printer",
        "//src/org/perses/util:perses_diffutil",
        "//test/org/perses:test_util",
    ],
)

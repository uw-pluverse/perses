package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_binary(
    name = "main",
    main_class = "org.perses.ppr.seed.SeedMain",
    runtime_deps = [
        ":seed_main_lib",
    ],
)

kt_jvm_library(
    name = "seed_main_lib",
    srcs = [
        "SeedMain.kt",
    ],
    deps = [
        ":cmd_options",
        ":reduction_driver",
        "//:flogger",
        "//:guava",
        "//src/org/perses:abstract_reduction_main",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_driver_interface",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "reduction_driver",
    srcs = [
        "SeedReductionDriver.kt",
    ],
    deps = [
        ":cmd_options",
        ":output_manager",
        ":reduction_inputs",
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
    ],
)

kt_jvm_library(
    name = "output_manager",
    srcs = ["SeedOutputManagerFactory.kt"],
    deps = [
        ":reduction_inputs",
        "//src/org/perses/program",
        "//src/org/perses/reduction/io/token:token_output_manager_factory_interface",
        "//src/org/perses/util:perses_diffutil",
    ],
)

kt_jvm_library(
    name = "reduction_inputs",
    srcs = ["SeedReductionInputs.kt"],
    deps = [
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/reduction/io:reduction_inputs_interface",
    ],
)

kt_jvm_library(
    name = "cmd_options",
    srcs = [
        "SeedCmdOptions.kt",
    ],
    deps = [
        "//src/org/perses:command_options",
        "//src/org/perses/reduction:reducer_factory",
    ],
)

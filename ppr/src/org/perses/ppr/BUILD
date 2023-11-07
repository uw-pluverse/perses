package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_binary(
    name = "main",
    main_class = "org.perses.ppr.Main",
    runtime_deps = [
        ":main_lib",
    ],
)

kt_jvm_library(
    name = "main_lib",
    srcs = [
        "Main.kt",
    ],
    deps = [
        ":cmd_options",
        ":reduction_driver",
    ],
)

kt_jvm_library(
    name = "cmd_options",
    srcs = [
        "CmdOptions.kt",
    ],
    deps = [
        "//src/org/perses:command_options",
        "//src/org/perses/reduction:reducer_factory",
    ],
)

kt_jvm_library(
    name = "reduction_driver",
    srcs = [
        "PPRMetaReductionDriver.kt",
    ],
    deps = [
        ":cmd_options",
        "//ppr/src/org/perses/ppr/diff/list:list_diff_main_lib",
        "//ppr/src/org/perses/ppr/diff/tree:tree_diff_main_lib",
        "//ppr/src/org/perses/ppr/seed:seed_main_lib",
        "//src/org/perses:abstract_reduction_main",
        "//src/org/perses:token_counter_lib",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction:reduction_driver_interface",
    ],
)

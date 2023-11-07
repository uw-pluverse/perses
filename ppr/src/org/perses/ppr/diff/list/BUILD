package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_binary(
    name = "main",
    main_class = "org.perses.ppr.diff.list.ListDiffMain",
    runtime_deps = [
        ":list_diff_main_lib",
    ],
)

kt_jvm_library(
    name = "list_diff_main_lib",
    srcs = [
        "ListDiffMain.kt",
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
        "ListDiffReductionDriver.kt",
        "ProgressMonitor.kt",
    ],
    deps = [
        ":cmd_options",
        ":diff_reducer",
        ":output_manager",
        ":reduction_inputs",
        ":reduction_io_manager",
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
    ],
)

kt_jvm_library(
    name = "cmd_options",
    srcs = [
        "ListDiffCmdOptions.kt",
    ],
    deps = [
        "//src/org/perses:command_options",
        "//src/org/perses/reduction:reducer_factory",
    ],
)

kt_jvm_library(
    name = "output_manager",
    srcs = [
        "ListDiffOutputManagerFactory.kt",
    ],
    deps = [
        ":reduction_inputs",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/io/token:token_output_manager_factory_interface",
        "//src/org/perses/util:perses_diffutil",
    ],
)

kt_jvm_library(
    name = "reduction_inputs",
    srcs = [
        "ListDiffReductionInputs.kt",
    ],
    deps = [
        "//src/org/perses/reduction/io:reduction_inputs",
    ],
)

kt_jvm_library(
    name = "reduction_io_manager",
    srcs = ["ListDiffReductionIOManager.kt"],
    deps = [
        ":output_manager",
        ":reduction_inputs",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
    ],
)

kt_jvm_library(
    name = "diff_reducer",
    srcs = [
        "AbstractListDiffReducer.kt",
        "ListDiffDdmin.kt",
        "ListDiffSlicer.kt",
    ],
    deps = [
        ":diff_reduction_state",
        ":reduction_io_manager",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "diff_reduction_state",
    srcs = ["ListDiffReductionState.kt"],
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/util:perses_diffutil",
    ],
)

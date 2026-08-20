load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("@rules_java//java:defs.bzl", "java_binary")

package(default_visibility = [
    "//visibility:public",
])

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
        "//src/org/perses:HelperForPersesMain",
        "//src/org/perses:abstract_reduction_main",
        "//src/org/perses:perses_listener_manager_creator",
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
    ],
    deps = [
        ":cmd_options",
        ":diff_reducer",
        ":output_manager",
        ":reduction_io_manager",
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//ppr/src/org/perses/ppr/diff:reduction_inputs",
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
        "//ppr/src/org/perses/ppr:AbstractPPRCommandOptions",
        "//src/org/perses:perses_command_options",
    ],
)

kt_jvm_library(
    name = "output_manager",
    srcs = [
        "ListDiffOutputManagerFactory.kt",
    ],
    deps = [
        "//ppr/src/org/perses/ppr/diff:reduction_inputs",
        "//src/org/perses/reduction/io/token:token_output_manager_factory_interface",
        "//src/org/perses/util:perses_diffutil",
    ],
)

kt_jvm_library(
    name = "reduction_io_manager",
    srcs = ["ListDiffReductionIOManager.kt"],
    deps = [
        ":output_manager",
        "//ppr/src/org/perses/ppr/diff:reduction_inputs",
        "//src/org/perses/reduction/io",
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
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
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

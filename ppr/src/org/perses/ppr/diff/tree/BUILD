load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("@rules_java//java:defs.bzl", "java_binary")

package(default_visibility = [
    "//visibility:public",
])

java_binary(
    name = "main",
    main_class = "org.perses.ppr.diff.tree.TreeDiffMain",
    runtime_deps = [
        ":tree_diff_main_lib",
    ],
)

kt_jvm_library(
    name = "tree_diff_main_lib",
    srcs = [
        "TreeDiffMain.kt",
    ],
    deps = [
        ":reduction_driver",
        "//src/org/perses:HelperForPersesMain",
        "//src/org/perses:abstract_reduction_main",
        "//src/org/perses:perses_listener_manager_creator",
    ],
)

kt_jvm_library(
    name = "reduction_driver",
    srcs = [
        "TreeDiffReductionDriver.kt",
    ],
    deps = [
        ":cmd_options",
        ":customized_tree_node_reducer",
        ":output_manager",
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//ppr/src/org/perses/ppr/diff:reduction_inputs",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction/io:reduction_inputs",
    ],
)

kt_jvm_library(
    name = "cmd_options",
    srcs = [
        "TreeDiffCmdOptions.kt",
    ],
    deps = [
        "//ppr/src/org/perses/ppr:AbstractPPRCommandOptions",
        "//src/org/perses:perses_command_options",
    ],
)

kt_jvm_library(
    name = "output_manager",
    srcs = [
        "TreeDiffOutputManagerFactory.kt",
    ],
    deps = [
        "//ppr/src/org/perses/ppr/diff:reduction_inputs",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/io:reduction_inputs",
    ],
)

kt_jvm_library(
    name = "customized_tree_node_reducer",
    srcs = [
        "CustomizedTreeNodesReducer.kt",
    ],
    deps = [
        "//src/org/perses/reduction/reducer:node_based_reducer",
    ],
)

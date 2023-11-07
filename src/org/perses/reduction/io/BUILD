package(default_visibility = [
    "//antlrrdc:__subpackages__",
    "//buildopt:__subpackages__",
    "//ppr/src/org/perses:__subpackages__",
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "reduction_inputs_interface",
    srcs = [
        "AbstractReductionInputs.kt",
        "AbstractSingleFileReductionInputs.kt",
    ],
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "reduction_inputs",
    srcs = [
        "RegularReductionInputs.kt",
    ],
    deps = [
        ":reduction_inputs_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
    ],
)

kt_jvm_library(
    name = "reduction_folder",
    srcs = [
        "ReductionFolder.kt",
        "ReductionFolderManager.kt",
    ],
    deps = [
        ":reduction_inputs",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "output_manager_interface",
    srcs = [
        "AbstractOutputManager.kt",
        "AbstractOutputManagerFactory.kt",
    ],
    deps = [
        ":reduction_folder",
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "io",
    srcs = [
        "AbstractReductionIOManager.kt",
        "ReductionFolder.kt",
        "ReductionFolderManager.kt",
    ],
    deps = [
        ":output_manager_interface",
        ":reduction_folder",
        ":reduction_inputs",
        ":reduction_inputs_interface",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/util:auto_increment_dir",
        "//src/org/perses/util:timeutil",
    ],
)

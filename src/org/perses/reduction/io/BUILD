load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//antlrrdc:__subpackages__",
    "//buildopt:__subpackages__",
    "//ppr/src/org/perses:__subpackages__",
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_library(
    name = "reduction_inputs",
    srcs = [
        "AbstractOriginalReductionInputs.kt",
        "DefaultLanguageOriginalReductionInputs.kt",
        "PerFileSizeMetrics.kt",
    ],
    deps = [
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/util",
        "//src/org/perses/util:immutable_int_array",
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
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "output_manager_interface",
    srcs = [
        "AbstractOutputManager.kt",
        "AbstractOutputManagerFactory.kt",
        "SuppliedContentOutputManager.kt",
    ],
    deps = [
        ":reduction_folder",
        ":reduction_inputs",
        "//src/org/perses/util:file_name_content_pair",
        "//src/org/perses/util/hashing",
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
        "//:guava",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/util:auto_increment_dir",
        "//src/org/perses/util:timeutil",
    ],
)

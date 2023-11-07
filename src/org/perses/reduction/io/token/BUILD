package(default_visibility = [
    "//ppr/src/org/perses:__subpackages__",
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "token_output_manager_factory_interface",
    srcs = [
        "AbstractTokenOutputManagerFactory.kt",
    ],
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//src/org/perses/reduction/io:output_manager_interface",
    ],
)

kt_jvm_library(
    name = "token_reduction_io_manager",
    srcs = [
        "TokenReductionIOManager.kt",
    ],
    deps = [
        ":token_output_manager_factory_interface",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io:output_manager_interface",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_library(
    name = "regular_output_manager_factory",
    srcs = [
        "RegularOutputManagerFactory.kt",
    ],
    deps = [
        ":token_output_manager_factory_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction/io:reduction_folder",
    ],
)

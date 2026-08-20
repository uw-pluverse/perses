load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "ppr_diff_utils",
    srcs = ["PPRDiffUtils.kt"],
    deps = [
        "//:gumtree",
        "//src/org/perses/spartree",
        "//src/org/perses/util:perses_diffutil",
    ],
)

kt_jvm_library(
    name = "reduction_inputs",
    srcs = [
        "DiffOriginalReductionInputs.kt",
    ],
    deps = [
        "//src/org/perses/reduction/io:reduction_inputs",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "reduction",
    srcs = [
        "DeltaFolder.kt",
        "ReductionScriptGenerator.kt",
    ],
    deps = [
        "//:guava",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//src/org/perses:perses_lib",
        "//src/org/perses/grammar/adhoc:language_kind",
        "@maven//:org_apache_commons_commons_text",
    ],
)

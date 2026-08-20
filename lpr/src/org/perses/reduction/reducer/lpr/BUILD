load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//:perses.bzl", "copy")

package(default_visibility = [
    "//visibility:public",
])

copy(
    name = "copy_default_llm_client_script",
    src = "//lpr/scripts:llm_client.py",
    dest = "default_llm_client.py",
)

kt_jvm_library(
    name = "lpr",
    srcs = [
        "AbstractLlmBasedReducer.kt",
        "LargeLanguageModel.kt",
        "LlmBasedDataTypeEliminationReducer.kt",
        "LlmBasedDataTypeSimplificationReducer.kt",
        "LlmBasedFunctionInliningReducer.kt",
        "LlmBasedLoopUnrollingReducer.kt",
        "LlmBasedVariableEliminationReducer.kt",
    ],
    resources = [
        "default_llm_client.py",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/grammar/onetoken:parser_facade",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reducer_context_interface",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/util:Serialization",
        "//src/org/perses/util/markdown",
    ],
)

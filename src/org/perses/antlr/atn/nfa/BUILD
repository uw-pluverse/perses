load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "nfa",
    srcs = [
        "ATNConstructorFromRegex.kt",
        "ATNDummyState.kt",
        "AbstractNfa.kt",
        "AbstractNfaBasedOnJGraphT.kt",
        "ConcatenatedNfaView.kt",
        "ImmutableNfa.kt",
        "MutableNfa.kt",
        "NonRegexException.kt",
        "PersesATNState.kt",
        "PersesTransitionAst.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:jgrapht",
        "//antlropt/src/org/perses/antlr/pnf:mutable_ast_and_util",
        "//src/org/perses/antlr:antlr_type_wrappers",
        "//src/org/perses/antlr/atn:atn_kt_utils",
    ],
)

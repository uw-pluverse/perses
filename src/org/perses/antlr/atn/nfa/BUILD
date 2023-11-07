package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "nfa",
    srcs = [
        "ATNConstructorFromRegex.kt",
        "ATNDummyState.kt",
        "AbstractNFA.kt",
        "AbstractNFABasedOnJGraphT.kt",
        "ImmutableNFA.kt",
        "MutableNFA.kt",
        "NonRegexException.kt",
        "PersesATNState.kt",
        "PersesTransitionAst.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:jgrapht",
        "//src/org/perses/antlr/atn:AbstractRandom",
        "//src/org/perses/antlr/atn:atn_kt_utils",
        "//src/org/perses/antlr/atn/tdtree",
    ],
)

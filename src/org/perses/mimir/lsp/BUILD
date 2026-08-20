load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "lsp",
    srcs = [
        "JavacDependencyAnalyzer.kt",
        "LspSemanticToken.kt",
        "MimirDependencyAnalyzer.kt",
        "MimirLanguageServerClient.kt",
    ],
    deps = [
        "//:guava",
        "//:lsp4j",
        "//src/org/perses/grammar/java:parser_facade_java8",
        "//src/org/perses/program",
        "//src/org/perses/reduction/semantics",
        "//src/org/perses/util:auto_deletable_folder",
        "//src/org/perses/util:simple_stack_and_queue",
        "//src/org/perses/util/java",
        "//src/org/perses/util/shell",
    ],
)

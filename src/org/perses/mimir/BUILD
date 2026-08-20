load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("@rules_java//java:defs.bzl", "java_binary")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "semantics_provider",
    srcs = [
        "AbstractMimirSemanticProviderCreator.kt",
        "MimirJavacSemanticProviderCreator.kt",
        "MimirSemanticsProvider.kt",
        "MimirSemanticsProviderCreator.kt",
    ],
    deps = [
        "//:guava",
        "//:lsp4j",
        "//src/org/perses/mimir/lsp",
        "//src/org/perses/reduction/semantics",
        "//src/org/perses/spartree",
    ],
)

java_binary(
    name = "mimir",
    jvm_flags = ["-ea"],
    main_class = "org.perses.Main",
    runtime_deps = [
        ":semantics_provider",
        "//src/org/perses:perses_lib",
        "//src/org/perses/mimir/lsp",
    ],
)

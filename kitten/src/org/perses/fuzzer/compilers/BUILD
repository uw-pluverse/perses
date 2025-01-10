package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "compiler_configuration",
    srcs = [
        "AbstractCompilationAction.kt",
        "AbstractCompilerConfigurationFacade.kt",
        "AbstractCompilerCrashDetector.kt",
        "CommonCompilationAction.kt",
        "DefaultCompilationConfigurationFacade.kt",
        "ICompilationAction.kt",
        "ICompilerCrashDetector.kt",
        "SanitizerCrashSignatureExtractor.kt",
    ],
    deps = [
        "//kitten/src/org/perses/fuzzer/config:testing_configuration",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/util",
        "//src/org/perses/util/shell",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

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
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/util",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//:perses.bzl", "kt_binary_for_genrule")
load("//test/org/perses/mimir:mimir_test.bzl", "javac_mimir_analyzer_golden_test", "mimir_analyzer_golden_test")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_test(
    name = "ClangDLanguageServerTest",
    srcs = [
        "ClangDLanguageServerTest.kt",
    ],
    data = [
        "cyclic-deps.c",
        "large.c",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/mimir/lsp",
        "//src/org/perses/util",
    ],
)

mimir_analyzer_golden_test(
    name = "golden_test_mimir_analysis_for_recursive",
    extra_deps = [
        ":files",
    ],
    golden_file = "golden_mimir_analysis_for_recursive.txt",
    test_source_file = "recursive.c",
)

mimir_analyzer_golden_test(
    name = "golden_test_mimir_analysis_for_cyclic_deps",
    extra_deps = [
        ":files",
    ],
    golden_file = "golden_mimir_analysis_for_cyclic_deps.txt",
    test_source_file = "cyclic-deps.c",
)

mimir_analyzer_golden_test(
    name = "golden_test_mimir_analysis_for_simple",
    extra_deps = [
        ":files",
    ],
    golden_file = "golden_mimir_analysis_for_simple.txt",
    test_source_file = "simple.c",
)

kt_binary_for_genrule(
    name = "MimirDependencyAnalyzerDumpMain",
    srcs = [
        "MimirDependencyAnalyzerDumpMain.kt",
    ],
    jvm_flags = [
        "-ea",
    ],
    main_class = "org.perses.mimir.lsp.MimirDependencyAnalyzerDumpMain",
    deps = [
        "//:guava",
        "//src/org/perses/mimir:semantics_provider",
        "//src/org/perses/util/cmd",
        "//test/org/perses:test_util",
    ],
)

filegroup(
    name = "files",
    srcs = [
        "cyclic-deps.c",
        "large.c",
        "recursive.c",
    ],
    visibility = [
        "//visibility:public",
    ],
)

kt_jvm_test(
    name = "JavaLanguageServerTest",
    srcs = [
        "JavaLanguageServerTest.kt",
    ],
    data = [
        "//benchmark_v2/benchmark_java/checkerframework-691:files",
        "//benchmark_v2/binaries:jdtls_binaries",
        "//benchmark_v2/binaries:jdtls_scripts",
        "//benchmark_v2/binaries:jls_binaries",
        "//benchmark_v2/binaries:jls_scripts",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/mimir/lsp",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "JavacDependencyAnalyzerTest",
    srcs = [
        "JavacDependencyAnalyzerTest.kt",
    ],
    data = [
        "//benchmark_v2/binaries:jdtls_binaries",
        "//benchmark_v2/binaries:jdtls_scripts",
        "//benchmark_v2/binaries:jls_binaries",
        "//benchmark_v2/binaries:jls_scripts",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/mimir/lsp",
        "//src/org/perses/util",
        "//src/org/perses/util/java",
    ],
)

kt_binary_for_genrule(
    name = "MimirJavacDependencyAnalyzerDumpMain",
    srcs = [
        "MimirJavacDependencyAnalyzerDumpMain.kt",
    ],
    jvm_flags = [
        "-ea",
    ],
    main_class = "org.perses.mimir.lsp.MimirJavacDependencyAnalyzerDumpMain",
    deps = [
        "//:guava",
        "//:lsp4j",
        "//src/org/perses/mimir/lsp",
        "//src/org/perses/util/cmd",
        "//test/org/perses:test_util",
    ],
)

javac_mimir_analyzer_golden_test(
    name = "golden_test_mimir_javac_analysis_for_simple",
    golden_file = "golden_mimir_javac_analysis_for_simple.txt",
    test_source_file = "Simple.java",
)

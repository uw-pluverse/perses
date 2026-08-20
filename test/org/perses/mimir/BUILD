load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//:perses.bzl", "kt_binary_for_genrule")
load("//test/org/perses/mimir:mimir_test.bzl", "graph_golden_test")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_test(
    name = "MimirSemanticsProviderTest",
    srcs = [
        "MimirSemanticsProviderTest.kt",
    ],
    data = [
        "//benchmark_v2/benchmark_java/checkerframework-577:files",
        "//benchmark_v2/benchmark_java/checkerframework-691:files",
        "//benchmark_v2/binaries:jls_binaries",
        "//benchmark_v2/binaries:jls_scripts",
        "//test/org/perses/mimir/lsp:files",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/mimir:semantics_provider",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)

graph_golden_test(
    name = "recursive_graph_golden_test",
    extra_deps = [
        "//test/org/perses/mimir/lsp:files",
    ],
    golden_file = "golden_graph_recursive.txt",
    test_source_file = "//test/org/perses/mimir/lsp:recursive.c",
)

kt_binary_for_genrule(
    name = "ScopedGraphDumpMain",
    srcs = [
        "ScopedGraphDumpMain.kt",
    ],
    jvm_flags = [
        "-ea",
    ],
    main_class = "org.perses.mimir.ScopedGraphDumpMain",
    deps = [
        "//:guava",
        "//src/org/perses/mimir:semantics_provider",
        "//src/org/perses/util/cmd",
        "//test/org/perses:test_util",
    ],
)

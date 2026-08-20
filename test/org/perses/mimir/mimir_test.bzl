load("//test:test.bzl", "golden_test")

SCOPED_GRAPH_DUMP_MAIN = "//test/org/perses/mimir:ScopedGraphDumpMain"

MIMIR_DEPS_ANALYZER_DUMP_MAIN = "//test/org/perses/mimir/lsp:MimirDependencyAnalyzerDumpMain"
JAVAC_MIMIR_DEPS_ANALYZER_DUMP_MAIN = "//test/org/perses/mimir/lsp:MimirJavacDependencyAnalyzerDumpMain"

def mimir_analyzer_golden_test(name, golden_file, test_source_file, extra_deps = None):
    _common_golden_test(
        name = name,
        golden_file = golden_file,
        test_source_file = test_source_file,
        dump_main = MIMIR_DEPS_ANALYZER_DUMP_MAIN,
        extra_deps = extra_deps,
    )

def javac_mimir_analyzer_golden_test(name, golden_file, test_source_file, extra_deps = None):
    _common_golden_test(
        name = name,
        golden_file = golden_file,
        test_source_file = test_source_file,
        dump_main = JAVAC_MIMIR_DEPS_ANALYZER_DUMP_MAIN,
        extra_deps = extra_deps,
    )

def graph_golden_test(name, golden_file, test_source_file, extra_deps = None):
    _common_golden_test(
        name = name,
        golden_file = golden_file,
        test_source_file = test_source_file,
        dump_main = SCOPED_GRAPH_DUMP_MAIN,
        extra_deps = extra_deps,
    )

def _common_golden_test(
        name,
        golden_file,
        test_source_file,
        dump_main,
        extra_deps = None):
    genrule_name = name + "_graph_gen"
    output_file_name = name + "_actual_output.txt"
    args = [
        "$(location %s)" % dump_main,
        "--input",
        "$(location %s)" % test_source_file,
        "--output",
        "$(location %s)" % output_file_name,
    ]
    if not extra_deps:
        extra_deps = []
    native.genrule(
        name = genrule_name,
        srcs = [
            test_source_file,
        ] + extra_deps,
        outs = [
            output_file_name,
        ],
        tools = [
            dump_main,
        ],
        cmd = " ".join(args),
    )
    golden_test(
        name = name,
        golden_file = golden_file,
        test_file = output_file_name,
    )

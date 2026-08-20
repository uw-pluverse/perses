load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

# t.c is not valid C (a brace block in expression position), but its delimiters are balanced. With
# --enable-error-tolerant-grammar the file's spine is an error-tolerant parse of its real (C) grammar,
# so --dyck-node-reducer=auto schedules the extra Dyck pass: it reparses under the Dyck grammar (all
# three delimiter kinds here, since all of them pair) and deletes the balanced-but-grammar-illegal
# { ... } group as one subtree -- structure the tolerant-real parse leaves as flat sibling leaves.
# See internal_doc/error_tolerant_multi_grammar_passes.md.
sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

sanity_test(
    name = "sanity_test_unbalanced",
    source_files = ["t_unbalanced.c"],
    test_script = "r_unbalanced.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--enable-error-tolerant-grammar": "true",
        "--dyck-node-reducer": "auto",
        "--fully-deterministic-mode": "true",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "t.c",
    test_script = "r.sh",
)

# t_unbalanced.c has an unbalanced brace, so the real C grammar rejects it and the Dyck pass has to
# reparse it. The pass derives an adaptive Dyck facade, which drops the braces (they do not pair) and
# nests what is left, so the reparse succeeds and the pass runs on the recovered tree instead of
# being skipped. A fixed brace+parenthesis+bracket facade has no parse for this file at all.
reduction_golden_test(
    name = "reduction_golden_test_unbalanced",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_unbalanced_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t_unbalanced.c",
    other_flags = {
        "--enable-error-tolerant-grammar": "true",
        "--dyck-node-reducer": "auto",
        # Isolate the Dyck pass so the progress golden is specifically about it reparsing the
        # unbalanced best; the line slicer would otherwise also run on this tolerant-real file.
        "--line-slicer": "off",
        "--fully-deterministic-mode": "true",
    },
    progress_dump_file = "unbalanced_reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "t_unbalanced.c",
    test_script = "r_unbalanced.sh",
)

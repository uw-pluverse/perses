load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

# End-to-end check that AdaptiveDyckParserFacade adapts inside a real reduction, on a file whose
# delimiter kinds disagree.
#
# t.c is not parseable as C, and its braces do not pair: the `{` guarded by `#if 0` is never closed,
# so the `}` of `{ 5 }` matches it instead and the file ends one `{` deep. Its parentheses and
# brackets do pair. A fixed brace+parenthesis+bracket Dyck facade -- what dyck_node_reducer derived
# before -- has no parse for that at all, since the Dyck grammars accept a brace only in a matched
# pair; it can be read only by ANTLR error recovery fabricating the missing symbol.
#
# The adaptive facade demotes the braces to plain text and keeps the two kinds that do nest. What
# the progress golden pins is that tree: `{` and `}` recorded as OTHER, while `(` and `[` open real
# subtrees -- `( dead_a , g ( dead_b ) )` and `[ 4 ]` -- that the pass can delete in one edit each.
# Stop adapting and that tree becomes whatever error recovery invents, which the golden catches.
#
# The reduced file is deliberately the weaker of the two goldens: the oracle only asks that MARKER
# survive, and on a toy this small the pass reaches `keep_MARKER` either way. It guards the coarser
# failure -- a tree that no longer reconstructs, or a pass that stops running at all.
sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "adaptive_dyck_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_adaptive_dyck_progress.txt",
    golden_reduced_file = "golden_adaptive_dyck_reduced_t.c",
    other_flags = {
        "--enable-error-tolerant-grammar": "true",
        "--fully-deterministic-mode": "true",
        "--enable-latra": "false",
    },
    progress_dump_file = "adaptive_dyck_progress.txt",
    reduction_algorithm = "dyck_node_reducer",
    source_file = "t.c",
    test_script = "r.sh",
)

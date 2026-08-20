load("//:perses.bzl", "reduce")
load("//test:test.bzl", "golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

# The single source file lives in a subdirectory (src/t.c), so the reduction folder is nested. This
# pins that FormatReducer runs the formatter with the file's *root-relative* path (src/t.c), not its
# bare base name -- the latter would not be found with the folder as the working directory, so
# formatting would be skipped and the result would stay unformatted. See
# AbstractReductionIOManager.getExistingInputFileRelativePathsIn.

sanity_test(
    name = "sanity_test",
    source_files = ["src/t.c"],
    test_script = "r.sh",
)

output_dir_reduce_with_formatter = "output_dir_reduce_with_formatter"

reduce(
    name = "reduce_with_formatter",
    call_formatter = True,
    enable_edit_caching = True,
    enable_query_caching = True,
    output_dir = output_dir_reduce_with_formatter,
    reduction_algorithm = "node_priority",
    source_file = "src/t.c",
    test_script = "r.sh",
)

# The reduced result (unformatted), then run through clang-format: the formatted result the reduction
# above must produce, since FormatReducer formats the same reduced program with clang-format.
genrule(
    name = "format_golden_reduced_src_t_c",
    srcs = ["golden_reduced_src_t.c"],
    outs = ["formatted_golden_reduced_src_t.c"],
    cmd = "cat $(location golden_reduced_src_t.c) | clang-format > $@",
)

golden_test(
    name = "golden_test_format_reducer_on_nested_file",
    golden_file = "formatted_golden_reduced_src_t.c",
    test_file = "%s/src/t.c" % output_dir_reduce_with_formatter,
)

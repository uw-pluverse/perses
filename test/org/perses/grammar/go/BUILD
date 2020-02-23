load("//test/org/perses:test.bzl", "golden_test")

genrule(
    name = "cp_pnf_go_grammar",
    outs = ["pnf_go_grammar.g4"],
    srcs = ["//src/org/perses/grammar/go:normalize_go_to_pnf"],
    cmd = "cp \"$<\" \"$@\""
)

golden_test(
    name = "test_pnf_go_grammar",
    test_file = "pnf_go_grammar.g4",
    golden_file = "golden_pnf_go.g4"
)
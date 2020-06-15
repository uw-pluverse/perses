load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

genrule(
    name = "cp_pnf_scala_grammar",
    srcs = ["//src/org/perses/grammar/scala:normalize_scala_to_pnf"],
    outs = ["pnf_scala_grammar.g4"],
    cmd = "cp \"$<\" \"$@\"",
)

golden_test(
    name = "test_pnf_scala_grammar",
    golden_file = "golden_pnf_scala.g4",
    test_file = "pnf_scala_grammar.g4",
)

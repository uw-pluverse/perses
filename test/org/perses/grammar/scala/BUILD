load("//test/org/perses:test.bzl", "cross_folder_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

cross_folder_golden_test(
    name = "test_pnf_scala_grammar",
    golden_file = "golden_pnf_scala.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/scala:normalize_scala_to_pnf",
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "VariousDyckParserFacadeTest",
    srcs = [
        "VariousDyckParserFacadeTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:opt_c_grammar",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/spartree:tree_node",
    ],
)

kt_jvm_test(
    name = "AdaptiveDyckParserFacadeTest",
    srcs = [
        "AdaptiveDyckParserFacadeTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:opt_c_grammar",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/grammar/dyck:pnf_line_aware_dyck_parser_codegen",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/spartree:tree_node",
    ],
)

kt_jvm_test(
    name = "PristineDyckParserFacadeTest",
    srcs = [
        "PristineDyckParserFacadeTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:opt_c_grammar",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/grammar/dyck:pnf_line_aware_dyck_parser_codegen",
        "//src/org/perses/grammar/dyck:pnf_pristine_dyck_parser_codegen",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/spartree:tree_node",
    ],
)

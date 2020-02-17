package(default_visibility = [
    "//src/org/perses/grammar:__pkg__",
    "//test/org/perses:__subpackages__",
])

load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen", "antlr_merge_grammar")

antlr_merge_grammar(
    name = "merge_go_lexer_and_parser",
    lexer_grammar = "GoLexer.g4",
    parser_grammar = "GoParser.g4",
    target_grammar = "OrigGo.g4"
)

antlr_codegen(
    name = "orig_go_grammar",
    grammar_file = "OrigGo.g4",
    java_pkg_name = "org.perses.grammar.go",
)

pnf_convert(
    name = "normalize_go_to_pnf",
    src = "OrigGo.g4",
    out = "PnfGo.g4",
    start_rule_name = "sourceFile",
)

antlr_codegen(
    name = "pnf_go_grammar",
    grammar_file = "PnfGo.g4",
    java_pkg_name = "org.perses.grammar.go",
)

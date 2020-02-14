def extract_grammar_name(grammar_file):
    if not grammar_file.endswith(".g4"):
        fail("The grammar file name has to end with '.g4'.")
    grammar_file = grammar_file[:-3]
    last_index = grammar_file.rfind("/")
    if last_index == -1:
        return grammar_file
    else:
        fail("The grammar file must be in the current package.")

def antlr_merge_grammar(name, lexer_grammar, parser_grammar, target_grammar):
    mergerule_name = "%s_merge" % name
    grammar_name = extract_grammar_name(target_grammar)

    commands = [
       "echo 'grammar %s;' > $@" % (grammar_name,),
       "$(location //src/org/perses/grammar:antlr_merge_grammar) $(location %s) $(location %s) >> $@" % \
         (parser_grammar, lexer_grammar)
    ]
  

    native.genrule(
        name = mergerule_name,
        outs = [target_grammar],
        srcs = [lexer_grammar, parser_grammar], # "//src/org/perses/grammar:antlr_remove_grammer.sed", "//src/org/perses/grammar:antlr_remove_options.sed"],
        cmd = " ; \\\n".join(commands),
        tools = ["//src/org/perses/grammar:antlr_merge_grammar"],
    )

def antlr_codegen(name, grammar_file, java_pkg_name):
    genrule_name = "%s_gen" % name
    grammar_name = extract_grammar_name(grammar_file)

    generated_parser_name = "%sParser.java" % grammar_name
    generated_lexer_name = "%sLexer.java" % grammar_name

    current_pkg_name = native.package_name()
    java_pkg_folder = java_pkg_name.replace(".", "/")
    if not current_pkg_name.endswith(java_pkg_folder):
        fail("The current pkg name '%s' should end with %s" % (current_pkg_name, java_pkg_folder))
    commands = [
        "GRAMMAR_FILE=$(location %s)" % grammar_file,
        "GRAMMAR_FILE_NAME=$$(basename $${GRAMMAR_FILE})",
        "TMP=$$(mktemp -d)",
        "cp $${GRAMMAR_FILE} $${TMP}",
        " ".join([
            "\"$(location //src/org/perses/grammar:antlr_tool)\"",
            "-no-listener",
            "-no-visitor",
            "-package %s" % java_pkg_name,
            "\"$${TMP}/$${GRAMMAR_FILE_NAME}\"",
        ]),
        "cp \"$${TMP}/%s\" $(location %s)" % (generated_parser_name, generated_parser_name),
        "cp \"$${TMP}/%s\" $(location %s)" % (generated_lexer_name, generated_lexer_name),
        "",
    ]
    native.genrule(
        name = genrule_name,
        outs = [generated_lexer_name, generated_parser_name],
        srcs = [grammar_file],
        cmd = " ; \\\n".join(commands),
        tools = ["//src/org/perses/grammar:antlr_tool"],
    )

    native.java_library(
        name = name,
        srcs = [
            generated_lexer_name,
            generated_parser_name,
        ],
        resources = [grammar_file],
        deps = ["@maven//:org_antlr_antlr4_runtime"],
    )

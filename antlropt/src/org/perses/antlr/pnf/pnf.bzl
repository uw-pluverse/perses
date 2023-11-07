def pnf_convert(
        name,
        src,
        out,
        start_rule_name,
        lexer_grammar = None):
    if not start_rule_name:
        fail("start_rule_name cannot be empty.")
    tool = "//antlropt/src/org/perses/antlr/pnf:pnf_main"
    log_file = "%s_conversion_log.txt" % name
    args = [
        "$(location %s)" % tool,
        "--source $(location %s)" % src,
        "--start_rule_name %s" % start_rule_name,
        "--output $(location %s)" % out,
        " > %s 2>&1" % log_file,
    ]
    srcs = [src]
    if lexer_grammar:
        args.append("--lexer $(location %s)" % lexer_grammar)
        srcs.append(lexer_grammar)
    native.genrule(
        name = name,
        outs = [out],
        srcs = srcs,
        cmd = " ".join(args),
        tools = [tool],
    )

def outline_implicit_token_defs(
        name,
        parser_input,
        parser_output,
        start_rule_name,
        lexer_input = None,
        lexer_output = None):
    if not start_rule_name:
        fail("start_rule_name cannot be empty.")
    tool = "//antlropt/src/org/perses/antlr/pnf:outline_implicit_token_def_bin"
    log_file = "%s_outline_implicit_token_defs.log" % name
    args = [
        "$(location %s)" % tool,
        "--start_rule_name %s" % start_rule_name,
        "--parser-input $(location %s)" % parser_input,
        "--parser-output $(location %s)" % parser_output,
    ]
    srcs = [parser_input]
    outs = [parser_output]
    if (lexer_input == None) != (lexer_output == None):
        fail("lexer_input and lexer_output should be specified at the same time.")
    if lexer_input and lexer_output:
        srcs.append(lexer_input)
        outs.append(lexer_output)
        args.append("--lexer-input $(location %s)" % lexer_input)
        args.append("--lexer-output $(location %s)" % lexer_output)

    native.genrule(
        name = name,
        outs = outs,
        srcs = srcs,
        tools = [tool],
        cmd = " ".join(args),
    )

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

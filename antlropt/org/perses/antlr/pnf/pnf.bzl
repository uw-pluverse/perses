def pnf_convert(name, src, out, start_rule_name):
    if not start_rule_name:
        fail("start_rule_name cannot be empty.")
    tool = "//antlropt/org/perses/antlr/pnf:pnf_main"
    args = [
        "$(location %s)" % tool,
        "--source $(location %s)" % src,
        "--start_rule_name %s" % start_rule_name,
        "--output $(location %s)" % out,
    ]
    native.genrule(
        name = name,
        outs = [out],
        srcs = [src],
        cmd = " ".join(args),
        tools = [tool],
    )

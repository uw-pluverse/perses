load("//test/org/perses:test.bzl", "golden_test")

def pnf_pass_golden_test(
        name,
        input_file,
        golden_file,
        pnf_pass_name,
        start_rule_name = None):
    output_file = name + "_output.g4"
    tool = "//antlropt/test/org/perses/antlr/pnf:pnf_pass_command_line"
    cmd = [
        "$(location %s)" % tool,
        "--input $(location %s)" % input_file,
        "--output $(location %s)" % output_file,
        "--pass %s" % pnf_pass_name,
    ]
    if start_rule_name != None:
        cmd.append("--start-rule-name %s" % start_rule_name)

    native.genrule(
        name = "%s_gen_output" % name,
        outs = [output_file],
        srcs = [input_file],
        tools = [tool],
        cmd = " ".join(cmd),
    )

    golden_test(
        name = name,
        test_file = output_file,
        golden_file = golden_file,
    )

def pnf_pass_manager_golden_test(
        name,
        input_file,
        golden_file,
        start_rule_name):
    output_file = name + "_output.g4"
    tool = "//antlropt/src/org/perses/antlr/pnf:pnf_main"
    cmd = [
        "$(location %s)" % tool,
        "--source $(location %s)" % input_file,
        "--output $(location %s)" % output_file,
        "--start_rule_name %s" % start_rule_name,
    ]
    native.genrule(
        name = "%s_gen_output" % name,
        outs = [output_file],
        srcs = [input_file],
        tools = [tool],
        cmd = " ".join(cmd),
    )

    golden_test(
        name = name,
        test_file = output_file,
        golden_file = golden_file,
    )

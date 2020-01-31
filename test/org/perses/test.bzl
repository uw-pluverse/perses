def golden_test(name, golden_file, test_file):
    rule_cp_diff_sh = "%s_cp_diff" % name
    diff_script = "%s_diff.sh" % name

    orig_diff_script = "//test/org/perses:diff.sh"
    native.genrule(
        name = rule_cp_diff_sh,
        outs = [diff_script],
        srcs = [orig_diff_script],
        cmd = "cp $(location %s) $(location %s)" % (orig_diff_script, diff_script),
    )

    native.sh_test(
        name = name,
        srcs = [diff_script],
        args = [
            "$(location %s)" % golden_file,
            "$(location %s)" % test_file,
        ],
        data = [
            golden_file,
            test_file,
        ],
    )

def copy(name, src, dest):
    native.genrule(
        name = name,
        outs = [
            dest,
        ],
        srcs = [
            src,
        ],
        cmd = "cp $< $@",
    )

def golden_test(name, golden_file, test_file):
    rule_cp_diff_sh = "%s_copy_diff_script" % name
    diff_script = "%s_diff.sh" % name

    orig_diff_script = "//test/org/perses:diff.sh"
    copy(
        name = rule_cp_diff_sh,
        src = orig_diff_script,
        dest = diff_script,
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

    # The following targets are used to update the golden file.
    #    gen_update_script_rule_name = name + "_gen_update_script"
    #    update_script_name = gen_update_script_rule_name + ".sh"
    #    native.genrule(
    #        name = gen_update_script_rule_name,
    #        outs = [update_script_name],
    #        cmd = "",
    #    )
    rule_cp_copy_sh = "%s_copy_copy_script" % name
    copy_script = "%s_copy.sh" % name
    orig_copy_script = "//test/org/perses:copy.sh"
    copy(
        name = rule_cp_copy_sh,
        src = orig_copy_script,
        dest = copy_script,
    )
    native.sh_binary(
        name = "%s_update" % name,
        srcs = [copy_script],
        data = [
            golden_file,
            test_file,
        ],
        tags = ["golden_file_update_target"],
        args = [
            "$(location %s)" % test_file,
            "$(location %s)" % golden_file,
        ],
    )

def cross_folder_golden_test(
        name,
        test_file_in_other_folders,
        golden_file):
    copy_genrule_name = name + "_copy_gen"
    test_file = name + "_test_file"

    copy(
        name = copy_genrule_name,
        src = test_file_in_other_folders,
        dest = test_file,
    )

    golden_test(
        name = name,
        golden_file = golden_file,
        test_file = test_file,
    )

perses_bin = "//src/org/perses:perses_deploy.jar"

adhoc_bin = "//src/org/perses/grammar/adhoc:perses_adhoc_installer_deploy.jar"

yaml_file = ":language_kind.yaml"

grammar_file = "//src/org/perses/grammar/c:OrigC.g4"

sh_test(
    name = "system_test_of_adhoc_fuzz_testing",
    srcs = ["system_test.sh"],
    args = [
        "$(location %s)" % adhoc_bin,
        "$(location %s)" % grammar_file,
        "$(location %s)" % yaml_file,
        "$(location %s)" % perses_bin,
    ],
    data = [
        perses_bin,
        grammar_file,
        yaml_file,
        adhoc_bin,
    ],
)

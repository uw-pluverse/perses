package(
    default_visibility = ["//visibility:public"],
)

perses_cmd_usage_file = "perses_cmd_usage.txt"

genrule(
    name = "get_perses_cmd_usage",
    outs = [perses_cmd_usage_file],
    cmd = "$(location //src/org/perses:perses) --help > \"$@\"",
    tools = [
        "//src/org/perses",
    ],
)

genrule(
    name = "formatted_perses_cmd_usage",
    srcs = [perses_cmd_usage_file],
    outs = ["formatted_perses_cmd_usage.txt"],
    cmd = """echo '```' > $@ && cat $(location %s) >> $@ && echo -e '```\n' >> $@""" % perses_cmd_usage_file,
)

genrule(
    name = "generate_readme",
    srcs = [
        "header.segment.md",
        "license.segment.md",
        "publication.segment.md",
        "formatted_perses_cmd_usage.txt",
        "acknowledgement.md",
        "build_and_use.segment.md",
        "//readme_generator/org/pluverse/perses:supported_languages_segment",
    ],
    outs = ["generated_readme.md"],
    cmd = "cat $(location header.segment.md) " +
          "$(location //readme_generator/org/pluverse/perses:supported_languages_segment) " +
          "$(location build_and_use.segment.md) " +
          "$(location formatted_perses_cmd_usage.txt) " +
          "$(location license.segment.md) " +
          "$(location publication.segment.md) " +
          "$(location acknowledgement.md)" +
          "> $@",
)

genrule(
    name = "generate_build_and_use_segment",
    srcs = [
        "build_and_use.template.md",
    ],
    outs = ["build_and_use.segment.md"],
    cmd = "$(location //readme_generator/org/pluverse/perses:DownloadLinkDumpMain) --input $< --output \"$@\"",
    tools = ["//readme_generator/org/pluverse/perses:DownloadLinkDumpMain"],
)

filegroup(
    name = "build_and_use_template",
    srcs = ["build_and_use.template.md"],
)

filegroup(
    name = "command_line_help_message",
    srcs = [perses_cmd_usage_file],
)

filegroup(
    name = "readme",
    srcs = ["generated_readme.md"],
)

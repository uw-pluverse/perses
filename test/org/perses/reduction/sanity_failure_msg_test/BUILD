genrule(
    name = "generate_sanity_failure_log",
    srcs = [
        "r.sh",
        "t.c",
    ],
    outs = ["sanity_failure_log.txt"],
    cmd = "$(location //src/org/perses) --input-file $(location t.c) --test-script $(location r.sh) &> $@ || true",
    tools = [
        "//src/org/perses",
    ],
)

py_test(
    name = "sanity_failure_msg_should_be_pretty_printed",
    srcs = ["sanity_failure_msg_should_be_pretty_printed.py"],
    data = ["sanity_failure_log.txt"],
)

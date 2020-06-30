py_library(
    name = "check_copyright",
    srcs = ["check_copyright.py"],
    data = [
        "copyright.txt",
    ],
)

py_binary(
    name = "check_copyright_main",
    srcs = ["check_copyright_main.py"],
    data = ["copyright.txt"],
    deps = [":check_copyright"],
)

py_test(
    name = "check_copyright_test",
    srcs = ["check_copyright_test.py"],
    deps = [
        ":check_copyright",
    ],
)

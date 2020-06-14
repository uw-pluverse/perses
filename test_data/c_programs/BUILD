package(default_visibility = ["//test/org/perses:__subpackages__"])

filegroup(
    name = "clang_testsuite",
    srcs = glob(
        ["clang_testsuite/*.c"],
        exclude = [
            "clang_testsuite/00143.c",  # invalid syntax
            "clang_testsuite/00152.c",  # unknown file encoding
            "clang_testsuite/01730.c",  # invalid syntax
            "clang_testsuite/01763.c",  # invalid syntax
            "clang_testsuite/00156.c",  # unknown file encoding
            "clang_testsuite/00741.c",  # invalid syntax: case 1 ... 2:
            "clang_testsuite/00718.c",  # invalid syntax: case 1 ... 2:
            "clang_testsuite/00725.c",  # invalid syntax: case 1 ... 2:
        ],
    ),
)

filegroup(
    name = "gcc_testsuite",
    srcs = glob(["gcc_testsuite/*.c"]),
)

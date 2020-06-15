package(default_visibility = ["//test/org/perses:__subpackages__"])

filegroup(
    name = "go_testsuite",
    srcs = glob(
        ["go_testsuite/**/*.go"],
        exclude = [
            "go_testsuite/fixedbugs/issue27836.dir/*.go",
            "go_testsuite/torture.go",
        ],
    ),
)

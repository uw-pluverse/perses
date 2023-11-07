load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "ShellTest",
    srcs = ["ShellTest.kt"],
    data = ["fake_creduce.sh"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_test(
    name = "ShellCommandOnPathTest",
    srcs = ["ShellCommandOnPathTest.kt"],
    associates = [
        "//src/org/perses/util/shell",
    ],
    data = ["fake_executable.sh"],
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "ShellOutputStreamTest",
    srcs = ["ShellOutputStreamTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_test(
    name = "ShellOutputLinesTest",
    srcs = ["ShellOutputLinesTest.kt"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_test(
    name = "ExitCodeTest",
    srcs = [":ExitCodeTest.kt"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util/shell:ExitCode",
    ],
)

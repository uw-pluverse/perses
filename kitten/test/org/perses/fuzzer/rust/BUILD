package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "RustcCrashDetectorTest",
    srcs = ["RustcCrashDetectorTest.kt"],
    data = [
        "crashoutput/crash_output_1.txt",
        "crashoutput/crash_output_2.txt",
        "crashoutput/crash_output_3.txt",
        "crashoutput/crash_output_5.txt",
        "crashoutput/non_crash_output.txt",
        "rustc_mock_1.sh",
        "rustc_mock_2.sh",
    ],
    test_class = "org.perses.fuzzer.rust.RustcCrashDetectorTest",
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/rust",
    ],
)

kt_jvm_test(
    name = "RustcVersionTest",
    srcs = ["RustcVersionTest.kt"],
    test_class = "org.perses.fuzzer.rust.RustcVersionTest",
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/rust",
    ],
)

filegroup(
    name = "rustc_mocks",
    srcs = [
        "rustc_mock_1.sh",
        "rustc_mock_2.sh",
    ],
)

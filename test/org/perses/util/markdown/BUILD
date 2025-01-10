load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//test/org/perses:test.bzl", "golden_test")

kt_jvm_test(
    name = "MarkdownToHTMLConverterTest",
    srcs = ["MarkdownToHTMLConverterTest.kt"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util/markdown",
    ],
)

genrule(
    name = "generate_html_from_readme",
    srcs = ["//:README.md"],
    outs = ["generated_readme.html"],
    cmd = "$(location //src/org/perses/util/markdown:MarkdownToHTMLConverter_bin) $(location //:README.md) $(location generated_readme.html)",
    tools = ["//src/org/perses/util/markdown:MarkdownToHTMLConverter_bin"],
)

golden_test(
    name = "readme_to_html_test",
    golden_file = "golden_readme.html",
    test_file = "generated_readme.html",
)

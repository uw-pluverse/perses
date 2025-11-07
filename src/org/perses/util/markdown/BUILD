load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")
load("//:perses.bzl", "kt_binary_for_genrule")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "markdown",
    srcs = ["MarkdownToHTMLConverter.kt"],
    deps = [
        "@maven//:org_commonmark_commonmark",
    ],
)

kt_binary_for_genrule(
    name = "MarkdownToHTMLConverter_bin",
    srcs = ["MarkdownToHTMLConverter.kt"],
    main_class = "org.perses.util.markdown.MarkdownToHTMLConverter",
    deps = [
        "@maven//:org_commonmark_commonmark",
    ],
)

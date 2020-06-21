load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

java_test(
    name = "UtilTest",
    srcs = ["UtilTest.java"],
    test_class = "org.perses.util.UtilTest",
    deps = [
        "//src/org/perses/util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "AutoDeletableFolderTest",
    srcs = ["AutoDeletableFolderTest.java"],
    test_class = "org.perses.util.AutoDeletableFolderTest",
    deps = [
        "//src/org/perses/util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "TimeSpanTest",
    srcs = ["TimeSpanTest.java"],
    test_class = "org.perses.util.TimeSpanTest",
    deps = [
        "//src/org/perses/util",
        "//test/org/perses:truth",
    ],
)

java_test(
    name = "FastStringBuilderTest",
    srcs = ["FastStringBuilderTest.java"],
    test_class = "org.perses.util.FastStringBuilderTest",
    deps = [
        "//src/org/perses/util",
        "//test/org/perses:truth",
    ],
)

java_test(
    name = "PercentageTest",
    srcs = ["PercentageTest.java"],
    test_class = "org.perses.util.PercentageTest",
    deps = [
        "//src/org/perses/util:percentage",
        "//test/org/perses:truth",
    ],
)

kt_jvm_test(
    name = "DoubleLinkedListTest",
    srcs = ["DoubleLinkedListTest.kt"],
    test_class = "org.perses.util.DoubleLinkedListTest",
    deps = [
        "//src/org/perses/util:double_linked_list",
        "//test/org/perses:truth"
    ]
)
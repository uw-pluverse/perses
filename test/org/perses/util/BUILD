load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

# kt_jvm_test cannot have resources. Have to define this library with resources.
kt_jvm_library(
    name = "dummy_class_with_resources",
    srcs = ["DummyClassWithResource.kt"],
    resource_strip_prefix = "test",
    resources = ["test_data.txt"],
    deps = [
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "UtilTest",
    srcs = ["UtilTest.kt"],
    deps = [
        ":dummy_class_with_resources",
        "//:guava",
        "//:truth",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
    ],
)

kt_jvm_test(
    name = "YamlUtilTest",
    srcs = [
        "YamlUtilTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/util:YamlUtil",
    ],
)

kt_jvm_test(
    name = "SimpleStackAndSimpleQueueTest",
    srcs = ["SimpleStackAndSimpleQueueTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)

kt_jvm_test(
    name = "PersesKtExtsTest",
    srcs = [
        "PersesKtExtsTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/util:perses_kt_exts",
    ],
)

kt_jvm_test(
    name = "TinyListMapTest",
    srcs = ["TinyListMapTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:tiny_list_map",
    ],
)

kt_jvm_test(
    name = "FileNameContentPairTest",
    srcs = [
        "FileNameContentPairTest.kt",
    ],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_test(
    name = "MutableIntTest",
    srcs = ["MutableIntTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:mutable_int",
    ],
)

kt_jvm_test(
    name = "AutoIncrementDirectoryTest",
    srcs = ["AutoIncrementDirectoryTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:auto_increment_dir",
    ],
)

kt_jvm_test(
    name = "GuavaExtsTest",
    srcs = ["GuavaExtsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:perses_kt_exts",
    ],
)

kt_jvm_test(
    name = "PersesDiffUtilTest",
    srcs = ["PersesDiffUtilTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:perses_diffutil",
    ],
)

kt_jvm_test(
    name = "ListAlignmentTest",
    srcs = ["ListAlignmentTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:perses_diffutil",
    ],
)

kt_jvm_test(
    name = "TimeUtilTest",
    srcs = ["TimeUtilTest.kt"],
    test_class = "org.perses.util.TimeUtilTest",
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:timeutil",
    ],
)

kt_jvm_test(
    name = "AutoDeletableFolderTest",
    srcs = ["AutoDeletableFolderTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util:auto_deltable_folder",
    ],
)

java_test(
    name = "TimeSpanTest",
    srcs = ["TimeSpanTest.java"],
    test_class = "org.perses.util.TimeSpanTest",
    deps = [
        "//:truth",
        "//src/org/perses/util:timeutil",
    ],
)

kt_jvm_test(
    name = "FastStringBuilderTest",
    srcs = ["FastStringBuilderTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/util:fast_string_builder",
    ],
)

java_test(
    name = "PercentageTest",
    srcs = ["PercentageTest.java"],
    test_class = "org.perses.util.PercentageTest",
    deps = [
        "//:truth",
        "//src/org/perses/util:percentage",
    ],
)

kt_jvm_test(
    name = "DoubleLinkedListTest",
    srcs = ["DoubleLinkedListTest.kt"],
    test_class = "org.perses.util.DoubleLinkedListTest",
    deps = [
        "//:truth",
        "//src/org/perses/util:double_linked_list",
    ],
)

kt_jvm_test(
    name = "DefaultLoggingConfigurationsTest",
    srcs = ["DefaultLoggingConfigurationsTest.kt"],
    data = ["golden_SimpleFormatter.format.txt"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util:default_logging_configurations",
    ],
)

kt_jvm_test(
    name = "ShellTest",
    srcs = ["ShellTest.kt"],
    data = ["fake_creduce.sh"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util:shell",
    ],
)

kt_jvm_test(
    name = "ShellCommandOnPathTest",
    srcs = ["ShellCommandOnPathTest.kt"],
    associates = [
        "//src/org/perses/util:shell",
    ],
    data = ["fake_executable.sh"],
    test_class = "org.perses.util.ShellCommandOnPathTest",
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "ShellOutputStreamTest",
    srcs = ["ShellOutputStreamTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/util:shell",
    ],
)

kt_jvm_test(
    name = "ShellOutputLinesTest",
    srcs = ["ShellOutputLinesTest.kt"],
    deps = [
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util:shell",
    ],
)

kt_jvm_test(
    name = "PerformanceMonitorTest",
    srcs = ["PerformanceMonitorTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/util:performance_monitor",
    ],
)

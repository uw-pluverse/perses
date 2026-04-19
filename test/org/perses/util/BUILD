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
    name = "ReflectionUtilTest",
    srcs = [
        "ReflectionUtilTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "AssertionCanBeDisabledTest",
    srcs = ["AssertionCanBeDisabledTest.kt"],
    jvm_flags = [
        "-da",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/util",
        "//src/org/perses/util:mutable_int",
    ],
)

kt_jvm_test(
    name = "TruthExtensionTest",
    srcs = [
        "TruthExtensionTest.kt",
    ],
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "FileContentTest",
    srcs = ["FileContentTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
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
        "//src/org/perses/util/hashing",
    ],
)

kt_jvm_test(
    name = "SerializationTest",
    srcs = [
        "SerializationTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/util:Serialization",
    ],
)

kt_jvm_test(
    name = "SimpleStackAndSimpleQueueTest",
    srcs = ["SimpleStackAndSimpleQueueTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
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
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "TinyListMapTest",
    srcs = ["TinyListMapTest.kt"],
    deps = [
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
        "//:truth",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_test(
    name = "MutableIntTest",
    srcs = ["MutableIntTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/util:mutable_int",
    ],
)

kt_jvm_test(
    name = "AutoIncrementDirectoryTest",
    srcs = ["AutoIncrementDirectoryTest.kt"],
    deps = [
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
        "//src/org/perses/util",
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
    name = "StringListToByteFunnelTest",
    srcs = [
        "StringListToByteFunnelTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util/hashing",
    ],
)

kt_jvm_test(
    name = "GCMonitoringTest",
    srcs = ["GCMonitoringTest.kt"],
    jvm_flags = [
        "-Xmx10m",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/util:GCMonitoring",
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
        "//:truth",
        "//src/org/perses/util:auto_deltable_folder",
    ],
)

kt_jvm_test(
    name = "TimeSpanTest",
    srcs = ["TimeSpanTest.kt"],
    associates = [
        "//src/org/perses/util:timeutil",
    ],
    deps = [
        "//:truth",
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

kt_jvm_test(
    name = "PercentageTest",
    srcs = ["PercentageTest.kt"],
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
    deps = [
        "//:flogger",
        "//:truth",
        "//src/org/perses/util:default_logging_configurations",
    ],
)

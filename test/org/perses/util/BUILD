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

kt_jvm_test(
    name = "TimeUtilTest",
    srcs = ["TimeUtilTest.kt"],
    test_class = "org.perses.util.TimeUtilTest",
    deps = [
        "//src/org/perses/util:timeutil",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_test(
    name = "AutoDeletableFolderTest",
    srcs = ["AutoDeletableFolderTest.kt"],
    deps = [
        "//src/org/perses/util:auto_deltable_folder",
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
        "//src/org/perses/util:fast_string_builder",
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
        "//test/org/perses:truth",
    ],
)

kt_jvm_test(
    name = "DefaultLoggingConfigurationsTest",
    srcs = ["DefaultLoggingConfigurationsTest.kt"],
    data = ["golden_SimpleFormatter.format.txt"],
    deps = [
        "//src/org/perses/util:default_logging_configurations",
        "//test/org/perses:truth",
    ],
)

kt_jvm_test(
    name = "ShellTest",
    srcs = ["ShellTest.kt"],
    data = ["fake_creduce.sh"],
    deps = [
        "//src/org/perses/util:shell",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)

kt_jvm_test(
    name = "ShellCommandOnPathTest",
    srcs = ["ShellCommandOnPathTest.kt"],
    data = ["fake_executable.sh"],
    test_class = "org.perses.util.ShellCommandOnPathTest",
    deps = [
        "//src/org/perses/util:shell",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_truth_truth",
    ],
)

kt_jvm_test(
    name = "ShellOutputStreamTest",
    srcs = ["ShellOutputStreamTest.kt"],
    deps = [
        "//src/org/perses/util:shell",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)

kt_jvm_test(
    name = "ShellOutputLinesTest",
    srcs = ["ShellOutputLinesTest.kt"],
    deps = [
        "//src/org/perses/util:shell",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)

kt_jvm_test(
    name = "PerformanceMonitorTest",
    srcs = ["PerformanceMonitorTest.kt"],
    deps = [
        "//src/org/perses/util:performance_monitor",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)

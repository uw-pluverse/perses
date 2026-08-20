load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//:perses.bzl", "kt_binary_for_genrule")
load("//test/org/perses/analyzer/differential:event_diff_test.bzl", "event_diff_golden_test")

kt_binary_for_genrule(
    name = "EventDiffTreeModelDumpMain",
    srcs = ["EventDiffTreeModelDumpMain.kt"],
    main_class = "org.perses.analyzer.differential.EventDiffTreeModelDumpMain",
    deps = [
        "//src/org/perses/analyzer/differential",
        "//src/org/perses/listener:differential_events",
        "//src/org/perses/util/cmd",
    ],
)

kt_binary_for_genrule(
    name = "EventDiffTestDataGenerator",
    srcs = ["EventDiffTestDataGenerator.kt"],
    main_class = "org.perses.analyzer.differential.EventDiffTestDataGenerator",
    deps = [
        "//:guava",
        "//src/org/perses/listener:differential_events",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util/cmd",
        "//src/org/perses/util/shell:ExitCode",
    ],
)

genrule(
    name = "generate_sample_events",
    outs = ["sample_events.yaml"],
    cmd = "$(location :EventDiffTestDataGenerator) --output $@",
    tools = [":EventDiffTestDataGenerator"],
)

kt_jvm_test(
    name = "EventDiffStatisticsTest",
    srcs = ["EventDiffStatisticsTest.kt"],
    test_class = "org.perses.analyzer.differential.EventDiffStatisticsTest",
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/analyzer/differential",
        "//src/org/perses/listener:differential_events",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util/shell:ExitCode",
    ],
)

kt_jvm_test(
    name = "EventDiffTreeModelBuilderTest",
    srcs = ["EventDiffTreeModelBuilderTest.kt"],
    test_class = "org.perses.analyzer.differential.EventDiffTreeModelBuilderTest",
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/analyzer/differential",
        "//src/org/perses/listener:differential_events",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util/shell:ExitCode",
    ],
)

event_diff_golden_test(
    name = "EventDiffTreeModelGoldenTest",
    golden_file = "golden_event_tree.txt",
    run_yaml = ":generate_sample_events",
)

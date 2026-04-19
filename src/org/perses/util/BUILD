load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_binary",
    "kt_jvm_library",
)

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "GCMonitoring",
    srcs = [
        "GCMonitoring.kt",
    ],
    deps = [
        ":util",
        "//:flogger",
    ],
)

kt_jvm_binary(
    name = "antlr_parse_tree_pdfier_main",
    srcs = [
        "AntlrParseTreePdfierMain.kt",
    ],
    main_class = "org.perse.util.AntlrParseTreePdfierMain",
    deps = [
        "//src/org/perses/dotgraph",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "truth_extension",
    srcs = [
        "TruthExt.kt",
    ],
    deps = [
        "@maven//:com_google_truth_truth",
    ],
)

kt_jvm_library(
    name = "file_content",
    srcs = [
        "AbstractFileContent.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/util/hashing",
    ],
)

kt_jvm_library(
    name = "util",
    srcs = [
        "DaemonThreadPool.kt",
        "FileStreamPool.kt",
        "GlobalSequenceGenerator.kt",
        "PersesKtExts.kt",
        "ReflectionUtil.kt",
        "TableForTextPrinting.kt",
        "Util.kt",
    ],
    exports = [
        ":file_content",
    ],
    deps = [
        "//:guava",
    ],
)

kt_jvm_library(
    name = "simple_stack_and_queue",
    srcs = [
        "SimpleStackAndQueue.kt",
    ],
    deps = [
        "//:guava",
    ],
)

kt_jvm_library(
    name = "Serialization",
    srcs = [
        "Serialization.kt",
    ],
    deps = [
        "//:jackson",
    ],
)

kt_jvm_library(
    name = "AbstractBashScriptGenerator",
    srcs = [
        "AbstractBashScriptGenerator.kt",
    ],
    deps = [
        "//src/org/perses/program:source_file",
    ],
)

kt_jvm_library(
    name = "perses_diffutil",
    srcs = [
        "AbstractEditOperation.kt",
        "ListAlignment.kt",
        "PersesDiffUtil.kt",
    ],
    deps = [
        ":util",
        "//:guava",
        "@maven//:com_googlecode_java_diff_utils_diffutils",
    ],
)

kt_jvm_library(
    name = "tiny_list_map",
    srcs = [
        "TinyListMap.kt",
    ],
)

kt_jvm_library(
    name = "file_name_content_pair",
    srcs = [
        "FileNameContentLinesPair.kt",
        "FileNameContentPair.kt",
    ],
    deps = [
        ":file_content",
    ],
)

kt_jvm_library(
    name = "mutable_int",
    srcs = ["MutableInt.kt"],
)

kt_jvm_library(
    name = "fast_string_builder",
    srcs = ["FastStringBuilder.kt"],
    deps = [
        "//:fastutil",
    ],
)

sh_binary(
    name = "migrate_from_maven_jar",
    srcs = [":migrate_from_maven_jar.sh"],
)

kt_jvm_library(
    name = "percentage",
    srcs = ["Fraction.kt"],
)

kt_jvm_library(
    name = "double_linked_list",
    srcs = ["DoubleLinkedList.kt"],
)

kt_jvm_library(
    name = "default_logging_configurations",
    srcs = [
        "DefaultLoggingConfigurations.kt",
        "RelativeTimeFormatter.kt",
    ],
    deps = [
        ":timeutil",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "timeutil",
    srcs = [
        "TimeSpan.kt",
        "TimeUtil.kt",
    ],
    deps = [
        "//:guava",
    ],
)

kt_jvm_library(
    name = "auto_increment_dir",
    srcs = [
        "AutoIncrementDirectory.kt",
    ],
    deps = [
    ],
)

kt_jvm_library(
    name = "Interval",
    srcs = ["Interval.kt"],
)

kt_jvm_library(
    name = "flogger_kt_exts",
    srcs = ["FloggerKtExts.kt"],
    exports = [
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
    deps = [
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)

kt_jvm_library(
    name = "auto_deltable_folder",
    srcs = ["AutoDeletableFolder.kt"],
    deps = [
    ],
)

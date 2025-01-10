package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_library(
    name = "command_options",
    srcs = ["CommandOptions.java"],
    deps = [
        "//:flogger",
        "//:guava",
        "//:jcommander",
        "//kitten/src/org/perses/fuzzer/config:testing_configuration",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "organizer_lib",
    srcs = [
        "BugOrganizer.kt",
        "OrganizerDriver.kt",
        "TextUI.kt",
    ],
    deps = [
        ":command_options",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
    ],
)

java_binary(
    name = "main",
    srcs = ["Main.java"],
    main_class = "org.perses.fuzzer.organizer.Main",
    deps = [
        ":command_options",
        ":organizer_lib",
        "//:guava",
        "//:jcommander",
        "//src/org/perses/util:default_logging_configurations",
        "//src/org/perses/util/cmd",
    ],
)

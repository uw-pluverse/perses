package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_binary", "kt_jvm_library")

java_binary(
    name = "version_class_generator",
    srcs = ["VersionClassGenerator.java"],
    main_class = "org.perses.version.VersionClassGenerator",
    visibility = ["//visibility:private"],
    deps = [
        "@maven//:com_google_guava_guava",
    ]
)

genrule(
    name = "generate_version_class",
    srcs = ["@local_jdk//:jdk"],
    outs = ["Version.kt"],
    cmd = "$(location :version_class_generator) bazel-out/volatile-status.txt $@",
    stamp = True,
    tools = [":version_class_generator"],
)

kt_jvm_library(
    name ="version",
    srcs = ["Version.kt"]
)
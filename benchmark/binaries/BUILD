load("@rules_java//java:defs.bzl", "java_binary", "java_library", "java_test")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "jdtls_binaries",
    srcs = glob(["jdtls-1.33.0/**"]) + glob(["jdk21/**"]),
)

filegroup(
    name = "jls_binaries",
    srcs = glob(
        ["java-language-server/**"],
        exclude = [
            "java-language-server/**/BUILD",
            "java-language-server/**/WORKSPACE",
        ],
    ) + glob(["jdk21/**"]),
)

filegroup(
    name = "jdtls_scripts",
    srcs = [
        "start_jdtls.sh",
    ],
)

filegroup(
    name = "jls_scripts",
    srcs = [
        "start_jls.sh",
    ],
)

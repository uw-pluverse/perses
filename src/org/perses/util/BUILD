package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

java_library(
    name = "util",
    srcs = glob(
        ["*.java"],
        exclude = ["AntlrParseTreePdfier.java"],
    ),
    deps = [
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
        "@maven//:org_apache_commons_commons_exec",
    ],
)

sh_binary(
    name = "migrate_from_maven_jar",
    srcs = [":migrate_from_maven_jar.sh"],
)

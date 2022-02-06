load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

RULES_JVM_EXTERNAL_TAG = "2.6"

RULES_JVM_EXTERNAL_SHA = "064b9085b21c349c8bd8be015a73efd6226dd2ff7d474797b3507ceca29544bb"

http_archive(
    name = "rules_jvm_external",
    sha256 = RULES_JVM_EXTERNAL_SHA,
    strip_prefix = "rules_jvm_external-%s" % RULES_JVM_EXTERNAL_TAG,
    url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % RULES_JVM_EXTERNAL_TAG,
)

load("@rules_jvm_external//:defs.bzl", "maven_install")

maven_install(
    name = "maven",
    artifacts = [
        "com.beust:jcommander:1.81",
        "com.fasterxml.jackson.core:jackson-core:2.12.3",
        "com.fasterxml.jackson.core:jackson-databind:2.12.3",
        "com.fasterxml.jackson.core:jackson-annotations:2.12.3",
        "com.fasterxml.jackson.dataformat:jackson-dataformat-yaml:2.12.3",
        "com.fasterxml.jackson.datatype:jackson-datatype-guava:2.12.3",
        "com.fasterxml.jackson.module:jackson-module-kotlin:2.12.3",
        "com.google.errorprone:error_prone_annotations:2.3.4",
        "com.google.flogger:flogger-system-backend:0.5.1",
        "com.google.flogger:flogger:0.5.1",
        "com.google.googlejavaformat:google-java-format:1.7",
        "com.google.guava:guava:30.1-jre",
        "com.google.truth:truth:1.1.2",
        "com.googlecode.java-diff-utils:diffutils:1.3.0",
        "com.pinterest:ktlint:0.42.1",
        "io.gitlab.arturbosch.detekt:detekt-cli:1.16.0",
        "it.unimi.dsi:fastutil:8.5.2",
        "me.lemire.integercompression:JavaFastPFOR:0.1.9",
        "org.antlr:antlr4-runtime:4.9.3",
        "org.antlr:antlr4:4.9.3",
        "org.apache.commons:commons-exec:1.3",
        "org.apache.commons:commons-lang3:3.9",
        "org.apache.commons:commons-text:1.9",
        "org.checkerframework:checker-qual:2.11.0",
        "org.jetbrains.kotlin:kotlin-stdlib-jdk8:1.5.31",
        "org.jfree:jfreechart:1.5.0",
        "org.jgrapht:jgrapht-core:1.3.0",
        "org.ow2.asm:asm-all:5.2",
        "junit:junit:4.13.2",
        # Do not include org.jgrapht:jgrapht-io. It depends on antlr4-runtime:4.7.1
    ],
    fetch_sources = True,
    repositories = [
        "https://jcenter.bintray.com",
        "https://maven.google.com",
        "https://repo1.maven.org/maven2",
    ],
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

rules_kotlin_version = "v1.5.0-beta-4"

rules_kotlin_sha = "6cbd4e5768bdfae1598662e40272729ec9ece8b7bded8f0d2c81c8ff96dc139d"

http_archive(
    name = "io_bazel_rules_kotlin",
    sha256 = rules_kotlin_sha,
    urls = ["https://github.com/bazelbuild/rules_kotlin/releases/download/%s/rules_kotlin_release.tgz" % rules_kotlin_version],
)

#https://github.com/bazelbuild/rules_kotlin/releases/download/v1.5.0-beta-3/rules_kotlin_release.tgz
load("@io_bazel_rules_kotlin//kotlin:repositories.bzl", "kotlin_repositories")

kotlin_repositories()  # if you want the default. Otherwise see custom kotlinc distribution below

#kt_register_toolchains()  # to use the default toolchain, otherwise see toolchains below
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_register_toolchains")

register_toolchains("//:kotlin_toolchain")

###################################################################################################
#
# The following is copied from
#        https://github.com/bazelbuild/rules_go/.
#
###################################################################################################
# buildifier is written in Go and hence needs rules_go to be built.
# See https://github.com/bazelbuild/rules_go for the up to date setup instructions.
http_archive(
    name = "io_bazel_rules_go",
    sha256 = "2b1641428dff9018f9e85c0384f03ec6c10660d935b750e3fa1492a281a53b0f",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.29.0/rules_go-v0.29.0.zip",
        "https://github.com/bazelbuild/rules_go/releases/download/v0.29.0/rules_go-v0.29.0.zip",
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")

go_rules_dependencies()

go_register_toolchains(version = "1.17.1")

http_archive(
    name = "bazel_gazelle",
    sha256 = "de69a09dc70417580aabf20a28619bb3ef60d038470c7cf8442fafcf627c21cb",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v0.24.0/bazel-gazelle-v0.24.0.tar.gz",
        "https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.24.0/bazel-gazelle-v0.24.0.tar.gz",
    ],
)

load("@bazel_gazelle//:deps.bzl", "gazelle_dependencies")

gazelle_dependencies()

###################################################################################################
#
# The following is copied from
#        https://github.com/bazelbuild/buildtools/tree/master/buildifier
#
###################################################################################################
http_archive(
    name = "com_google_protobuf",
    sha256 = "985bb1ca491f0815daad825ef1857b684e0844dc68123626a08351686e8d30c9",
    strip_prefix = "protobuf-3.15.6",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.15.6.zip"],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

http_archive(
    name = "com_github_bazelbuild_buildtools",
    strip_prefix = "buildtools-4.0.1",
    url = "https://github.com/bazelbuild/buildtools/archive/4.0.1.zip",
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

RULES_JVM_EXTERNAL_TAG = "4.4.2"

RULES_JVM_EXTERNAL_SHA = "735602f50813eb2ea93ca3f5e43b1959bd80b213b836a07a62a29d757670b77b"

http_archive(
    name = "rules_jvm_external",
    sha256 = RULES_JVM_EXTERNAL_SHA,
    strip_prefix = "rules_jvm_external-%s" % RULES_JVM_EXTERNAL_TAG,
    url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % RULES_JVM_EXTERNAL_TAG,
)

load("@rules_jvm_external//:defs.bzl", "maven_install")

jackson_version = "2.14.2"

antlr_version = "4.12.0"

flogger_version = "0.7.4"

maven_install(
    name = "maven",
    artifacts = [
        "com.beust:jcommander:1.82",
        "com.fasterxml.jackson.core:jackson-core:%s" % jackson_version,
        "com.fasterxml.jackson.core:jackson-databind:%s" % jackson_version,
        "com.fasterxml.jackson.core:jackson-annotations:%s" % jackson_version,
        "com.fasterxml.jackson.dataformat:jackson-dataformat-yaml:%s" % jackson_version,
        "com.fasterxml.jackson.datatype:jackson-datatype-guava:%s" % jackson_version,
        "com.fasterxml.jackson.module:jackson-module-kotlin:%s" % jackson_version,
        "com.google.errorprone:error_prone_annotations:2.3.4",
        "com.google.flogger:flogger-system-backend:%s" % flogger_version,
        "com.google.flogger:flogger:%s" % flogger_version,
        "com.google.googlejavaformat:google-java-format:1.15.0",
        "com.google.guava:guava:31.1-jre",
        "com.google.truth:truth:1.1.3",
        "com.googlecode.java-diff-utils:diffutils:1.3.0",
        "com.guardsquare:proguard-base:7.2.1",
        "com.github.gumtreediff:core:3.0.0",
        "com.pinterest:ktlint:0.48.2",
        "io.gitlab.arturbosch.detekt:detekt-cli:1.16.0",
        "it.unimi.dsi:fastutil:8.5.2",
        "me.lemire.integercompression:JavaFastPFOR:0.1.9",
        "org.antlr:antlr4-runtime:%s" % antlr_version,
        "org.antlr:antlr4:%s" % antlr_version,
        "org.apache.commons:commons-exec:1.3",
        "org.apache.commons:commons-lang3:3.9",
        "org.apache.commons:commons-text:1.9",
        "org.jetbrains.kotlin:kotlin-scripting-jsr223:1.8.20",  # Delete this. @TODO(gaosen)
        "org.jetbrains.kotlin:kotlin-stdlib-jdk8:1.8.20",
        "org.jfree:jfreechart:1.5.0",
        "org.jgrapht:jgrapht-core:1.3.0",
        "org.ow2.asm:asm:9.3",
        "org.ow2.asm:asm-commons:9.3",
        "org.ow2.asm:asm-util:9.3",
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

rules_kotlin_version = "v1.8-RC-1"

rules_kotlin_sha = "1779628569eb3b0fe97a3fb5c3ed8090e6503e425600b401c7b1afb6b23a3098"

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
# Configure rules for rust
###################################################################################################
rust_rules_version = "0.6.0"

rust_rules_sha256 = "872b04538ca20dad94791c348623f079ba93daf274c1d57ae6bfe0930ec77f0d"

# To find additional information on this release or newer ones visit:
# https://github.com/bazelbuild/rules_rust/releases
http_archive(
    name = "rules_rust",
    sha256 = rust_rules_sha256,
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_rust/releases/download/%s/rules_rust-v%s.tar.gz" % (rust_rules_version, rust_rules_version),
        "https://github.com/bazelbuild/rules_rust/releases/download/%s/rules_rust-v%s.tar.gz" % (rust_rules_version, rust_rules_version),
    ],
)

load(
    "@rules_rust//rust:repositories.bzl",
    "rules_rust_dependencies",
    "rust_register_toolchains",
)

rules_rust_dependencies()

rust_register_toolchains(
    edition = "2018",
    rustfmt_version = "1.59.0",
    version = "1.59.0",
)

load("@rules_rust//proto:repositories.bzl", "rust_proto_repositories")

rust_proto_repositories()

load("@rules_rust//proto:transitive_repositories.bzl", "rust_proto_transitive_repositories")

###################################################################################################
#
# The following is copied from
#        https://github.com/bazelbuild/rules_go/.
#
###################################################################################################
# buildifier is written in Go and hence needs rules_go to be built.
# See https://github.com/bazelbuild/rules_go for the up to date setup instructions.
go_rules_version = "0.31.0"

go_rules_sha = "f2dcd210c7095febe54b804bb1cd3a58fe8435a909db2ec04e31542631cf715c"

http_archive(
    name = "io_bazel_rules_go",
    sha256 = go_rules_sha,
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v%s/rules_go-v%s.zip" % (go_rules_version, go_rules_version),
        "https://github.com/bazelbuild/rules_go/releases/download/v%s/rules_go-v%s.zip" % (go_rules_version, go_rules_version),
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")

go_rules_dependencies()

go_register_toolchains(version = "1.18.1")

bazel_gazelle_version = "0.24.0"

bazel_gazelle_sha = "de69a09dc70417580aabf20a28619bb3ef60d038470c7cf8442fafcf627c21cb"

http_archive(
    name = "bazel_gazelle",
    sha256 = bazel_gazelle_sha,
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v%s/bazel-gazelle-v%s.tar.gz" % (bazel_gazelle_version, bazel_gazelle_version),
        "https://github.com/bazelbuild/bazel-gazelle/releases/download/v%s/bazel-gazelle-v%s.tar.gz" % (bazel_gazelle_version, bazel_gazelle_version),
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
protobuf_rules_version = "3.20.1"

protobuf_rules_sha256 = "662879e41508a5ecce3be2c65563a8fac3301a48adef3113913ec4010f405a33"

http_archive(
    name = "com_google_protobuf",
    sha256 = protobuf_rules_sha256,
    strip_prefix = "protobuf-%s" % protobuf_rules_version,
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v%s.zip" % protobuf_rules_version],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

buildtools_version = "5.1.0"

http_archive(
    name = "com_github_bazelbuild_buildtools",
    strip_prefix = "buildtools-%s" % buildtools_version,
    url = "https://github.com/bazelbuild/buildtools/archive/%s.zip" % buildtools_version,
)

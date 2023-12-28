load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

RULES_JVM_EXTERNAL_TAG = "5.3"

RULES_JVM_EXTERNAL_SHA = "d31e369b854322ca5098ea12c69d7175ded971435e55c18dd9dd5f29cc5249ac"

http_archive(
    name = "rules_jvm_external",
    sha256 = RULES_JVM_EXTERNAL_SHA,
    strip_prefix = "rules_jvm_external-%s" % RULES_JVM_EXTERNAL_TAG,
    url = "https://github.com/bazelbuild/rules_jvm_external/releases/download/%s/rules_jvm_external-%s.tar.gz" % (RULES_JVM_EXTERNAL_TAG, RULES_JVM_EXTERNAL_TAG),
)

load("@rules_jvm_external//:repositories.bzl", "rules_jvm_external_deps")

rules_jvm_external_deps()

load("@rules_jvm_external//:setup.bzl", "rules_jvm_external_setup")

rules_jvm_external_setup()

load("@rules_jvm_external//:defs.bzl", "maven_install")

jackson_version = "2.15.2"

antlr_version = "4.13.0"

flogger_version = "0.7.4"

kotlin_lib_version = "1.9.10"

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
        "com.google.guava:guava:32.0.0-jre",
        "com.google.truth:truth:1.1.4",
        "com.googlecode.java-diff-utils:diffutils:1.3.0",
        "com.guardsquare:proguard-base:7.2.1",
        "com.github.gumtreediff:core:3.0.0",
        "com.pinterest:ktlint:0.50.0",
        "io.gitlab.arturbosch.detekt:detekt-cli:1.23.1",
        "io.netty:netty-all:4.1.66.Final",
        "it.unimi.dsi:fastutil:8.5.12",
        "me.lemire.integercompression:JavaFastPFOR:0.1.9",
        "org.antlr:antlr4-runtime:%s" % antlr_version,
        "org.antlr:antlr4:%s" % antlr_version,
        "org.apache.commons:commons-csv:1.10.0",
        "org.apache.commons:commons-exec:1.3",
        "org.apache.commons:commons-lang3:3.9",
        "org.apache.commons:commons-text:1.9",
        "org.jetbrains.kotlin:kotlin-stdlib-jdk8:%s" % kotlin_lib_version,
        "org.jetbrains.kotlin:kotlin-reflect:%s" % kotlin_lib_version,
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

rules_kotlin_version = "v1.9.0"

rules_kotlin_sha = "5766f1e599acf551aa56f49dab9ab9108269b03c557496c54acaf41f98e2b8d6"

http_archive(
    name = "io_bazel_rules_kotlin",
    sha256 = rules_kotlin_sha,
    urls = ["https://github.com/bazelbuild/rules_kotlin/releases/download/%s/rules_kotlin-%s.tar.gz" % (rules_kotlin_version, rules_kotlin_version)],
)

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
go_rules_version = "0.40.1"

go_rules_sha = "51dc53293afe317d2696d4d6433a4c33feedb7748a9e352072e2ec3c0dafd2c6"

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

go_register_toolchains(version = "1.20.7")

bazel_gazelle_version = "0.30.0"

bazel_gazelle_sha = "727f3e4edd96ea20c29e8c2ca9e8d2af724d8c7778e7923a854b2c80952bc405"

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

###################################################################################################
#
# The following is copied from
#        https://github.com/bazelbuild/buildtools/tree/master/buildifier
#
###################################################################################################
load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")

buildifier(
    name = "buildifier",
)

java_binary(
    name = "ktlint",
    main_class = "com.pinterest.ktlint.Main",
    runtime_deps = [
        "@maven//:com_pinterest_ktlint",
    ],
)

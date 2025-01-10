load("//test/org/perses:test.bzl", "copy")

package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

copy(
    name = "copy_perses_deploy",
    src = "//src/org/perses:perses_deploy.jar",
    dest = "perses_deploy.jar",
)

sh_test(
    name = "Issue240",
    timeout = "short",  # refer to issue 240 on github.
    srcs = ["Issue240.sh"],
    args = [
        "$(location perses_deploy.jar)",
    ],
    data = [
        "perses_deploy.jar",
    ],
)

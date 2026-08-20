load("@rules_java//java:defs.bzl", "java_binary", "java_library", "java_test")

package(default_visibility = ["//visibility:public"])

load("//test:test.bzl", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["small.c"],
    test_script = "r.sh",
)

java_binary(
    name = "profiling_main_compact_query_cache",
    args = [
        "--test-script",
        "$(location r.sh)",
        "--input-file",
        "$(location small.c)",
        "--threads",
        "1",
    ],
    data = [
        "r.sh",
        "small.c",
    ],
    jvm_flags = ["-ea"],
    main_class = "org.perses.Main",
    runtime_deps = [
        "//src/org/perses:perses_lib",
    ],
)

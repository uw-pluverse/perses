package(default_visibility = ["//visibility:public"])

load("//benchmark:benchmark.bzl", "sanity_test")

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
        "--query-cache-type",
        "COMPACT_QUERY_CACHE",
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

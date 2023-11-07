package(default_visibility = ["//test/org/perses:__subpackages__"])

load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_binary",
    "kt_jvm_library",
    "kt_jvm_test",
)
load("//:perses.bzl", "kt_binary_for_genrule")

kt_jvm_test(
    name = "PassLevelCacheTest",
    srcs = [
        "PassLevelCacheTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/reduction/cache:PassLevelCache",
        "//src/org/perses/reduction/reducer:node_based_reducer",
    ],
)

kt_jvm_test(
    name = "LogicalSizedArrayTest",
    srcs = ["LogicalSizedArrayTest.kt"],
    deps = [
        "//:asm",
        "//:truth",
        "//src/org/perses/reduction/cache:LogicalSizedArray",
    ],
)

kt_jvm_test(
    name = "EnumQueryCachingControlTest",
    srcs = ["EnumQueryCachingControlTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/reduction/cache:enum_query_caching_control",
    ],
)

kt_jvm_test(
    name = "CompactProgramEncodingTest",
    srcs = ["CompactProgramEncodingTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction/cache:query_cache",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "NullQueryCacheTest",
    srcs = ["NullQueryCacheTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction/cache:query_cache",
        "//test/org/perses:test_util",
    ],
)

kt_binary_for_genrule(
    name = "CompactQueryCacheBenchmark",
    srcs = ["CompactQueryCacheBenchmark.kt"],
    data = [
        "clang-22704.c",
    ],
    jvm_flags = [
        "-da",
    ],
    main_class = "org.perses.reduction.cache.CompactQueryCacheBenchmark",
    deps = [
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction/cache:linear_scan_cache",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/reduction/cache:query_cache_configuration",
        "//src/org/perses/reduction/cache:query_cache_interface",
        "//src/org/perses/util:percentage",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "ContentSHA512BasedQueryCacheTest",
    srcs = [
        "ContentSHA512BasedQueryCacheTest.kt",
    ],
    associates = [
        "//src/org/perses/reduction/cache:sha512_cache",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/reduction/cache:query_cache",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "LinearScanEncoderTest",
    srcs = [
        "LinearScanEncoderTest.kt",
    ],
    associates = [
        "//src/org/perses/reduction/cache:linear_scan_cache",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/reduction/cache:query_cache",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "LinearScanFormatSensitiveEncoderTest",
    srcs = [
        "LinearScanFormatSensitiveEncoderTest.kt",
    ],
    associates = [
        "//src/org/perses/reduction/cache:linear_scan_cache",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/reduction/cache:query_cache",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TokenizedProgramEncoderTest",
    srcs = ["TokenizedProgramEncoderTest.kt"],
    data = [
        "clang-22704.c",
        "//test_data/delta_1",
        "//test_data/java_helloworld",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.reduction.cache.TokenizedProgramEncoderTest",
    deps = [
        "//:antlr_runtime",
        "//:fastutil",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/cache:linear_scan_cache",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "IntervalArrayExpanderTest",
    srcs = ["IntervalArrayExpanderTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "QueryCacheMemoryProfilerTest",
    srcs = ["QueryCacheMemoryProfilerTest.kt"],
    jvm_flags = ["-javaagent:$(location //third_party/memory_measurer:object_explorer)"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction/cache:content_based_cache",
        "//src/org/perses/reduction/cache:linear_scan_cache",
        "//src/org/perses/reduction/cache:query_cache_memory_profiler",
        "//src/org/perses/reduction/cache:sha512_cache",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//third_party/memory_measurer:object_explorer",
    ],
)

kt_jvm_test(
    name = "ConfigBasedTestScriptExecutionCacheTest",
    srcs = ["ConfigBasedTestScriptExecutionCacheTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)

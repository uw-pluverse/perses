package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "zip_cache",
    srcs = [
        "ContentZipBasedQueryCache.kt",
    ],
    deps = [
        ":query_cache",
    ],
)

kt_jvm_library(
    name = "sha512_cache",
    srcs = [
        "ContentSHA512BasedQueryCache.kt",
    ],
    deps = [
        ":query_cache",
    ],
)

kt_jvm_library(
    name = "query_cache_configuration",
    srcs = [
        "QueryCacheConfiguration.kt",
    ],
    deps = [
        "//src/org/perses/util:percentage",
    ],
)

kt_jvm_library(
    name = "enum_query_caching_control",
    srcs = ["EnumQueryCachingControl.kt"],
)

kt_jvm_library(
    name = "program_encoding_interface",
    srcs = ["AbstractProgramEncoding.kt"],
)

kt_jvm_library(
    name = "test_execution_cache_type",
    srcs = ["QueryCacheType.kt"],
)

kt_jvm_library(
    name = "interval_expander",
    srcs = ["IntervalArrayExpander.kt"],
    deps = [
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "query_cache_factory",
    srcs = [
        "QueryCacheFactory.kt",
    ],
    deps = [
        ":content_based_cache",
        ":linear_scan_cache",
        ":query_cache",
        ":sha512_cache",
        ":test_execution_cache_type",
        ":zip_cache",
    ],
)

kt_jvm_library(
    name = "query_cache_interface",
    srcs = [
        "AbstractCacheRetrievalResult.kt",
        "AbstractQueryCache.kt",
    ],
    deps = [
        ":program_encoding_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
    ],
)

kt_jvm_library(
    name = "null_query_cache",
    srcs = [
        "NullQueryCache.kt",
    ],
    deps = [
        ":query_cache_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
    ],
)

kt_jvm_library(
    name = "LogicalSizedArray",
    srcs = [
        "LogicalSizedArray.kt",
    ],
    deps = [
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "query_cache",
    srcs = [
        "AbstractCompactProgramEncoder.kt",
        "AbstractQueryCacheProfiler.kt",
        "AbstractRealQueryCache.kt",
        "AbstractTokenizedProgramEncoder.kt",
        "CompactProgramEncoding.kt",
        "ConfigBasedQueryCache.kt",
        "NullQueryCacheProfiler.kt",
    ],
    deps = [
        ":int_array_compressor",
        ":interval_expander",
        ":null_query_cache",
        ":program_encoding_interface",
        ":query_cache_configuration",
        ":query_cache_interface",
        "//:fastutil",
        "//:flogger",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/util:percentage",
        "@maven//:com_google_errorprone_error_prone_annotations",
    ],
)

kt_jvm_library(
    name = "int_array_compressor",
    srcs = [
        "CompressorForIntArrayList.kt",
    ],
    deps = [
        "//:fastutil",
        "@maven//:me_lemire_integercompression_JavaFastPFOR",
    ],
)

kt_jvm_library(
    name = "content_based_cache",
    srcs = [
        "ContentLexemeIdQueryCache.kt",
        "ContentLexemeListQueryCache.kt",
        "ContentStringBasedQueryCache.kt",
    ],
    deps = [
        ":program_encoding_interface",
        ":query_cache_configuration",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction/cache:query_cache",
    ],
)

kt_jvm_library(
    name = "PassLevelCache",
    srcs = [
        "PassLevelCache.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_library(
    name = "linear_scan_cache",
    srcs = [
        "AbstractLinearScanEncoder.kt",
        "CompactQueryCache.kt",
        "CompactQueryCacheFormatSensitive.kt",
        "LinearScanFormatSensitiveEncoder.kt",
        "LinearScanTokenizedProgramEncoder.kt",
        "QueryCacheWithFastLinearScanWithoutCompression.kt",
        "RccMemLitQueryCache.kt",
        "RccMemoryLitProgramEncoder.kt",
    ],
    deps = [
        ":LogicalSizedArray",
        ":query_cache",
        ":query_cache_configuration",
        "//:fastutil",
        "//:guava",
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "query_cache_profiler",
    srcs = [
        "QueryCacheTimeProfiler.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction/cache:query_cache",
    ],
)

kt_jvm_library(
    name = "query_cache_memory_profiler",
    srcs = ["QueryCacheMemoryProfiler.kt"],
    deps = [
        "//src/org/perses/reduction/cache:query_cache",
        "//third_party/memory_measurer:object_explorer",
    ],
)

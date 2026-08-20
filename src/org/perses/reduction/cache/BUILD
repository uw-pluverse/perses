load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "sha_hash_cache",
    srcs = [
        "ContentShaHashBasedFormatQueryCache.kt",
    ],
    deps = [
        ":query_cache",
        ":query_cache_interface",
        "//src/org/perses/util:immutable_int_array",
        "@maven//:com_github_ben_manes_caffeine_caffeine",
    ],
)

kt_jvm_library(
    name = "interval_expander",
    srcs = ["IntervalArrayExpander.kt"],
    deps = [
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "query_cache_interface",
    srcs = [
        "AbstractQueryCache.kt",
        "CacheLookupResult.kt",
    ],
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction/io:output_manager_interface",
        "//src/org/perses/util:immutable_int_array",
        "//src/org/perses/util/hashing",
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
        "//src/org/perses/util:immutable_int_array",
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
        "AbstractQueryCacheProfiler.kt",
        "NullQueryCacheProfiler.kt",
    ],
    deps = [
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
    name = "query_cache_profiler",
    srcs = [
        "QueryCacheMemoryProfiler.kt",
        "QueryCacheTimeCsvProfiler.kt",
        "QueryCacheTimeProfiler.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/reduction/cache:sha_hash_cache",
        "//third_party/memory_measurer:object_explorer",
    ],
)

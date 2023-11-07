load(
    "//test/org/perses:test.bzl",
    "copy",
    "cross_folder_golden_test",
    "golden_test",
)
load("//src/org/perses:reduction.bzl", "reduce")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "PersesNodeReducerFunctionalTest",
    srcs = ["PersesNodeReducerFunctionalTest.kt"],
    data = [
        "dummy-creduce.sh",
        "//test_data/creduce_example",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "PersesNodeReducerJavaFunctionalTest",
    srcs = ["PersesNodeReducerJavaFunctionalTest.kt"],
    data = ["//test_data/java_helloworld"],
    test_class = "org.perses.reduction.reducer.PersesNodeReducerJavaFunctionalTest",
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "TreeSlicerTest",
    timeout = "long",
    srcs = ["TreeSlicerTest.kt"],
    data = [
        "//test_data/delta_1",
        "//test_data/scala_helloworld",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "PersesNodeReducerTest",
    srcs = ["PersesNodeReducerTest.kt"],
    test_class = "org.perses.reduction.reducer.PersesNodeReducerTest",
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_fast_linear_scan_caching",
    golden_file = "golden_progress_dump_t_with_fast_linear_scan_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_fast_linear_scan_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_fast_linear_scan_without_compression_caching",
    golden_file = "golden_progress_dump_t_with_fast_linear_scan_without_compression_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_fast_linear_scan_without_compression_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_lexeme_id_caching",
    golden_file = "golden_progress_dump_t_with_lexeme_id_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_lexeme_id_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_content_string_based_caching",
    golden_file = "golden_progress_dump_t_with_content_string_based_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_content_string_based_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_content_sha512_based_caching",
    golden_file = "golden_progress_dump_t_with_content_sha512_based_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_content_sha512_based_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_rcc_mem_caching",
    golden_file = "golden_progress_dump_t_with_fast_linear_scan_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_rcc_mem_lit_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_content_zip_based_caching",
    golden_file = "golden_progress_dump_t_with_content_zip_based_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_content_zip_based_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_content_lexeme_list_caching",
    golden_file = "golden_progress_dump_t_with_content_lexeme_list_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_content_lexeme_list_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_delta_1_with_config_based_caching",
    golden_file = "golden_progress_dump_t_with_config_based_cache_process.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_config_based_cache_process",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_1_with_cache",
    golden_file = "golden_reduction_log_of_delta_1_with_cache.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_with_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_1_without_cache",
    golden_file = "golden_reduction_log_of_delta_1_without_cache.txt",
    test_file_in_other_folders = "//test_data/delta_1:progress_dump_t_wo_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_3_with_cache",
    golden_file = "golden_test_reduction_process__delta_3_with_cache.txt",
    test_file_in_other_folders = "//test_data/delta_3:progress_dump_t_with_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_3_without_cache",
    golden_file = "golden_test_reduction_process__delta_3_without_cache.txt",
    test_file_in_other_folders = "//test_data/delta_3:progress_dump_t_without_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_3_hdd_with_cache",
    golden_file = "golden_test_reduction_process__detal_3_hdd_with_cache.txt",
    test_file_in_other_folders = "//test_data/delta_3:progress_dump_t_hdd_with_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_3_hdd_without_cache",
    golden_file = "golden_test_reduction_process__detal_3_hdd_without_cache.txt",
    test_file_in_other_folders = "//test_data/delta_3:progress_dump_t_hdd_without_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_3_pristine_hdd_without_cache",
    golden_file = "golden_test_reduction_process__detal_3_pristine_hdd_without_cache.txt",
    test_file_in_other_folders = "//test_data/delta_3:progress_dump_t_pristine_hdd_without_cache.c",
)

cross_folder_golden_test(
    name = "golden_test_reduction_process__delta_3_pristine_hdd_with_cache",
    golden_file = "golden_test_reduction_process__detal_3_pristine_hdd_with_cache.txt",
    test_file_in_other_folders = "//test_data/delta_3:progress_dump_t_pristine_hdd_with_cache.c",
)

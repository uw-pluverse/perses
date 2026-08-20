load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load(
    "//test:test.bzl",
    "cross_folder_golden_test",
)

kt_jvm_test(
    name = "PersesNodeReducerFunctionalTest",
    srcs = ["PersesNodeReducerFunctionalTest.kt"],
    data = [
        "dummy-creduce.sh",
        "dummy-creduce-fail.sh",
        "//test_data/creduce_example",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/reducer:node_based_reducer",
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
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "NonSyntacticSingleTreeNodeReducerTest",
    timeout = "long",
    srcs = ["NonSyntacticSingleTreeNodeReducerTest.kt"],
    data = [
        "//test_data/delta_1",
        "//test_data/scala_helloworld",
    ],
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "DyckNodeReducerTest",
    srcs = ["DyckNodeReducerTest.kt"],
    test_class = "org.perses.reduction.reducer.DyckNodeReducerTest",
    deps = [
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/reduction/reducer:node_based_reducer",
    ],
)

kt_jvm_test(
    name = "PristineDyckNodeReducerTest",
    srcs = ["PristineDyckNodeReducerTest.kt"],
    test_class = "org.perses.reduction.reducer.PristineDyckNodeReducerTest",
    deps = [
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/reduction/reducer:node_based_reducer",
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
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
    ],
)

kt_jvm_test(
    name = "MimirStrategyFinerDagAsListTest",
    srcs = ["MimirStrategyFinerDagAsListTest.kt"],
    deps = [
        "//:guava",
        "//:jgrapht",
        "//:truth",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/semantics",
        "//src/org/perses/spartree",
    ],
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

package(default_visibility = ["//visibility:public"])

java_binary(
    name = "proguard",
    main_class = "proguard.ProGuard",
    runtime_deps = [
        "@maven//:com_guardsquare_proguard_base",
    ],
)

filegroup(
    name = "rt_jar",
    srcs = ["rt.jar"],
)

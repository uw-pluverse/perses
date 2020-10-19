package(default_visibility = ["//visibility:public"])

java_library(
    name = "pnf",
    srcs = glob(
        ["*.java"],
        exclude = ["Main.java"],
    ),
    deps = [
        "//antlropt/org/perses/antlr:enum_rule_type",
        "//antlropt/org/perses/antlr/ast",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_jgrapht_jgrapht_core",
    ],
)

java_binary(
    name = "pnf_main",
    srcs = ["Main.java"],
    jvm_flags = ["-ea"],
    main_class = "org.perses.antlr.pnf.Main",
    deps = [
        ":pnf",
        "//antlropt/org/perses/antlr/ast",
        "//antlropt/org/perses/antlr/util",
        "@maven//:com_beust_jcommander",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
    ],
)

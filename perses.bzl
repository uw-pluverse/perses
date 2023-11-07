load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_library",
)

def kt_binary_for_genrule(
        name,
        srcs,
        main_class,
        deps,
        data = None,
        jvm_flags = None,
        args = None):
    lib_name = "kt_aux_lib_" + name
    if not data:
        data = []
    kt_jvm_library(
        name = lib_name,
        srcs = srcs,
        deps = deps,
        data = data,
    )
    if not jvm_flags:
        jvm_flags = []
    if not args:
        args = []
    native.java_binary(
        name = name,
        main_class = main_class,
        runtime_deps = [
            lib_name,
        ],
        jvm_flags = jvm_flags,
        args = args,
    )

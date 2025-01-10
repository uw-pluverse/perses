# Disabled for now, due to breakage.
# This test only works on Linux. MacOS does not have objdump.
sh_test(
    name = "validate_compilation_consistency_test",
    srcs = [
        "validate_compilation_consistency_test.sh",
    ],
    data = [
        "mock_compilers/ccmd_buggy/clang-trunk",
        "mock_compilers/ccmd_buggy/gcc-trunk",
        "mock_compilers/ccmd_correct/clang-trunk",
        "mock_compilers/ccmd_correct/gcc-trunk",
        "validate_ccmd.sh",
    ],
)

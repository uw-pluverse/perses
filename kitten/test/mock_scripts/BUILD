sh_test(
    name = "test_mock_rustc",
    srcs = ["mock_rustc_test.sh"],
    args = ["$(location mock_rustc.py)"],
    data = ["mock_rustc.py"],
)

filegroup(
    name = "mock_rustc_file",
    srcs = ["mock_rustc.py"],
)

exports_files(["mock_rustc.py"])

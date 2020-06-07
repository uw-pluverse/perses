py_library(
	name = "check_copyright"
	srcs = ["check_copyright.py"],
	data = [
        "copyright.txt"
    ],
)

py_test(
    name = "check_copyright_test.py",
    srcs = ["check_copyright_test.py"],
    data = [
        "check_copyright"
    ],
    deps = [    
    	":check_copyright"
    ],
)

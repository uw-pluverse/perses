py_library(
	name = "check_copyright"
	srcs = ["check_copyright.py"],
	data = [
        "copyright.txt"
    ],
)

py_test(
    name = "check_copyright_up_to_date",
    srcs = ["check_copyright_test.py"],
    data = [
        "check_copyright"
    ],
    deps = [    
    	"check_copyright.py"
    ],
)

package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "printer",
    srcs = [
        "AbstractOrigFormatVisitor.kt",
        "OrigFormatPrinter.kt",
        "OrigFormatPrintingVisitor.kt",
        "PrinterRegistry.kt",
        "SingleTokenPerLinePrinter.kt",
    ],
    deps = [
        ":orig_format_visitor_interface",
        ":python_format_printer",
        "//:guava",
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "abstract_tokenized_program_printer",
    srcs = ["AbstractTokenizedProgramPrinter.kt"],
    deps = [
        "//:antlr_runtime",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "python_format_printer",
    srcs = [
        "PythonFormatPrintingVisitor.kt",
        "PythonPrinter.kt",
    ],
    deps = [
        ":abstract_tokenized_program_printer",
        ":orig_format_visitor_interface",
        "//src/org/perses/grammar/python3:python3_lexer",
    ],
)

kt_jvm_library(
    name = "orig_format_visitor_interface",
    srcs = [
        "AbstractOrigFormatPrintingVisitor.kt",
        "AbstractOrigFormatVisitor.kt",
    ],
    deps = [
        ":abstract_tokenized_program_printer",
        "//src/org/perses/program",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "YamlTokenizedProgramPrinter",
    srcs = [
        "YamlTokenizedProgramPrinter.kt",
    ],
    deps = [
        ":abstract_tokenized_program_printer",
        "//:jackson",
        "//src/org/perses/grammar/jackson:pnf_jackson_parser_codegen",
    ],
)

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
        ":YamlTokenizedProgramPrinter",
        ":orig_format_visitor_interface",
        ":python_format_printer",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/util:mutable_int",
    ],
)

kt_jvm_library(
    name = "abstract_tokenized_program_printer",
    srcs = [
        "AbstractTokenPlacementListener.kt",
        "AbstractTokenPositionProvider.kt",
        "AbstractTokenizedProgramPrinter.kt",
        "DeducedPositionProvider.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//src/org/perses/antlr/atn:lexer_wrapper",
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

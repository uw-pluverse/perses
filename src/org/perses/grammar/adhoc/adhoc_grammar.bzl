def orig_parser_facade_library(
        name,
        output_jar_file_name,
        java_package_name,
        parser_facade_class_simple_name,
        parser_file_name,
        start_rule_name,
        token_names_of_identifiers,
        language_kind_full_name = None,
        language_kind_yaml_file = None,
        deps = None,
        lexer_file_name = None):
    _parser_facade_library(
        name,
        output_jar_file_name,
        java_package_name,
        parser_facade_class_simple_name,
        parser_file_name,
        start_rule_name,
        token_names_of_identifiers,
        enable_pnf_normalization = False,
        language_kind_full_name = language_kind_full_name,
        language_kind_yaml_file = language_kind_yaml_file,
        deps = deps,
        lexer_file_name = lexer_file_name,
    )

def pnf_parser_facade_library(
        name,
        output_jar_file_name,
        java_package_name,
        parser_facade_class_simple_name,
        parser_file_name,
        start_rule_name,
        token_names_of_identifiers,
        language_kind_full_name = None,
        language_kind_yaml_file = None,
        deps = None,
        lexer_file_name = None):
    _parser_facade_library(
        name,
        output_jar_file_name,
        java_package_name,
        parser_facade_class_simple_name,
        parser_file_name,
        start_rule_name,
        token_names_of_identifiers,
        enable_pnf_normalization = True,
        language_kind_full_name = language_kind_full_name,
        language_kind_yaml_file = language_kind_yaml_file,
        deps = deps,
        lexer_file_name = lexer_file_name,
    )

def _parser_facade_library(
        name,
        output_jar_file_name,
        java_package_name,
        parser_facade_class_simple_name,
        parser_file_name,
        start_rule_name,
        token_names_of_identifiers,
        enable_pnf_normalization,
        language_kind_full_name = None,
        language_kind_yaml_file = None,
        deps = None,
        lexer_file_name = None):
    jar_gen_rule_name = "%s_gen" % name
    tool = "//src/org/perses/grammar/adhoc:perses_adhoc_installer"
    adhoc_logfile = "%s_adhoc_installer.log" % name
    args = [
        "$(location %s)" % tool,
        "--output",
        "$(location %s)" % output_jar_file_name,
        "--package-name",
        java_package_name,
        "--parser-facade-class-simple-name",
        parser_facade_class_simple_name,
        "--parser-grammar",
        "$(location %s)" % parser_file_name,
        "--start-rule",
        start_rule_name,
        "--enable-pnf-normalization",
        "true" if enable_pnf_normalization else "false",
        "--token-names-of-identifiers",
        ",".join(token_names_of_identifiers),
        "> $(location %s) 2>&1" % adhoc_logfile,
    ]
    genrule_srcs = [parser_file_name]
    if lexer_file_name:
        args += [
            "--lexer-grammar",
            "$(location %s)" % lexer_file_name,
        ]
        genrule_srcs.append(lexer_file_name)

    if language_kind_full_name and language_kind_yaml_file:
        fail("language_kind_full_name and language_kind_yaml_file cannot be both specified.")
    elif not language_kind_full_name and not language_kind_yaml_file:
        fail("language_kind_full_name and language_kind_yaml_file are both empty.")
    if language_kind_full_name:
        args += [
            "--existing-language-full-class-name",
            language_kind_full_name,
        ]
    if language_kind_yaml_file:
        args += [
            "--language-kind-yaml-file",
            "$(location %s)" % language_kind_yaml_file,
        ]
        genrule_srcs.append(language_kind_yaml_file)
    native.genrule(
        name = jar_gen_rule_name,
        outs = [output_jar_file_name, adhoc_logfile],
        srcs = genrule_srcs,
        tools = [tool],
        cmd = " ".join(args),
    )
    deps = deps or []
    native.java_import(
        name = name,
        jars = [
            output_jar_file_name,
        ],
        srcjar = output_jar_file_name,
        deps = [
            "//:antlr_runtime",
            "//:flogger",
            "//src/org/perses/antlr:parse_tree_with_parser",
            "//src/org/perses/grammar:grammar_facade",
            "//src/org/perses/program:language_kind",
        ] + deps,
    )

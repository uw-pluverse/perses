# Install a New Language

This document describes how to use Perses to reduce a program
written in a language which Perses does not have built-in support.

## Prerequisite

To use this adhoc language support in Perses, the user needs to
prepare the following two things:

 * The grammar of the language written in Antlr.
   
   The grammar needs to be specified in Antlr. The grammar file
   can be a single, combined grammar, or separate lexer and parser
   grammars.
   
 * The description of the language in a YAML file.

   The following shows an example of such a YAML file `language_kind.yaml`.

   ```yaml
   ---
   name: "cpp"
   extensions:
      - "c"
      - "cpp"
      - "cc"
      - "h"
   defaultCodeFormatControl: "ORIG_FORMAT"
   origCodeFormatControl: "ORIG_FORMAT"
   allowedCodeFormatControl:
      - "SINGLE_TOKEN_PER_LINE"
      - "ORIG_FORMAT"
      - "COMPACT_ORIG_FORMAT"
   defaultFormatterCommands:
      - command: "clang-format"
        defaultFlags:
           - "-i"
   ```

## Generate a Language JAR File

Now we can use the following commands to generate a JAR file
```bash
readonly PARSER_GRAMMAR_FILE="Parser.g4"
readonly OPTIONAL_LEXER_GRAMMAR_FILE="Lexer.g4" # This is optional
readonly START_RULE_NAME="compilationUnit" # The start rule of the grammar
readonly LANGUAGE_KIND_YAML_FILE="language_kind.yaml"
readonly IDENTIFIER_TOKEN_NAMES="IDENTIFIER" # The name of the token type Identifier
readonly PACKAGE_NAME="org.perses.grammar.adhoc.mygrammar" # Name your own package
readonly OUTPUT_JAR="my_grammar.jar"

bazel build //src/org/perses/grammar/adhoc:perses_adhoc_installer_deploy.jar
java -jar bazel-bin/src/org/perses/grammar/adhoc/perses_adhoc_installer_deploy.jar \
    --parser-grammar "${PARSER_GRAMMAR_FILE}" \
    --lexer-grammar "${OPTIONAL_LEXER_GRAMMAR_FILE}" \
    --start-rule "${START_RULE_NAME}" \
    --token-names-of-identifiers "${IDENTIFIER_TOKEN_NAMES}" \
    --package-name "${PACKAGE_NAME}" \
    --language-kind-yaml-file "${LANGUAGE_KIND_YAML_FILE}" \
    --output "${OUTPUT_JAR}"
```

Now the generated JAR file pointed by `OUTPUT_JAR` should be created if the command
run successfully.

## Use the Language JAR File for Reduction

With the generated JAR file, now you can run Perses to reduce programs
written in the new language specified in your grammar.

```bash
bazel build //src/org/perses:perses_deploy.jar
java -jar bazel-bin/src/org/perses/perses_deploy.jar \
    --input-file <the input file to be reduced> \
    --test-script <the script which specifies the property> \
    --language-ext-jars "${OUTPUT_JAR}"
```
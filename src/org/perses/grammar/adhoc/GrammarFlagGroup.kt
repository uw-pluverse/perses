/*
 * Copyright (C) 2018-2024 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.grammar.adhoc

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Files
import java.nio.file.Path

class GrammarFlagGroup : AbstractCommandLineFlagGroup(groupName = "") {

  @JvmField
  @Parameter(
    names = ["--parser-grammar"],
    description = "The parser grammar",
    required = false,
    order = 0,
  )
  var parserGrammar: Path? = null

  @JvmField
  @Parameter(
    names = ["--start-rule"],
    description = "The start rule of the grammar",
    required = false,
    order = 100,
  )
  var startRuleName: String? = null

  @JvmField
  @Parameter(
    names = ["--token-names-of-identifiers"],
    description = "The token names of identifiers",
    required = false,
    order = 200,
  )
  var tokenNamesOfIdentifiers: List<String> = listOf()

  @JvmField
  @Parameter(
    names = ["--lexer-grammar"],
    description = "The lexer grammar",
    required = false,
    order = 300,
  )
  var lexerGrammar: Path? = null

  @Parameter(
    names = ["--package-name"],
    description = "The package name of the generated classes in the generated Jar file.",
    required = false,
    order = 400,
  )
  var packageName: String? = null

  @Parameter(
    names = ["--parser-facade-class-simple-name"],
    description = "The simple class name of the generated parser facade",
    required = false,
    order = 500,
  )
  var parserFacadeClassSimpleName: String? = null

  @Parameter(
    names = ["--language-kind-yaml-file"],
    description = "The YAML file which defines the language kind for this grammar",
    required = false,
    order = 600,
  )
  var languageKindYamlFile: Path? = null

  @Parameter(
    names = ["--existing-language-full-class-name"],
    description = "The full class name of the existing language kind",
    required = false,
    order = 700,
  )
  var existingLanguageKindClassFullName: String? = null

  @Parameter(
    names = ["--parser-base-file"],
    description = "The file for the parse base",
    required = false,
    order = 800,
  )
  var parserBase: Path? = null

  @Parameter(
    names = ["--lexer-base-file"],
    description = "The file for the lexer base",
    required = false,
    order = 900,
  )
  var lexerBase: Path? = null

  @Parameter(
    names = ["--enable-pnf-normalization"],
    description = "whether to enable PNF normalization on the parser grammar",
    required = false,
    arity = 1,
    order = 1000,
  )
  var enablePnfNormalization = false

  @Parameter(
    names = ["--extra-libs"],
    description = "the extra libs for compiling the grammar",
    required = false,
    arity = 1,
    order = 2000,
  )
  var extraLibs: List<Path> = listOf()

  fun createAdhocGrammarConfiguration(): AdhocGrammarConfiguration {
    return AdhocGrammarConfiguration(
      parserFile = parserGrammar!!,
      lexerFile = lexerGrammar,
      parserBase = parserBase,
      lexerBase = lexerBase,
      packageName = packageName,
      parserFacadeClassSimpleName = parserFacadeClassSimpleName,
      languageKindYamlFile = languageKindYamlFile,
      existingLanguageKindClassFullName = existingLanguageKindClassFullName,
      startRuleName = startRuleName!!,
      tokenNamesOfIdentifiers = tokenNamesOfIdentifiers,
    )
  }

  fun isAnyFlagSet(): Boolean {
    return parserGrammar != null ||
      startRuleName != null ||
      tokenNamesOfIdentifiers.isNotEmpty() ||
      lexerGrammar != null ||
      packageName != null ||
      parserFacadeClassSimpleName != null ||
      languageKindYamlFile != null ||
      existingLanguageKindClassFullName != null
  }

  override fun validate() {
    check(parserGrammar != null)
    check(Files.isRegularFile(parserGrammar)) {
      "The $parserGrammar is not a file."
    }
    check(startRuleName != null) {
      "The start rule name cannot be empty."
    }
    if (lexerGrammar != null) {
      check(Files.isRegularFile(lexerGrammar)) {
        "The $lexerGrammar is not a file"
      }
    }
    if (parserBase != null) {
      check(Files.isRegularFile(parserBase)) {
        "The $parserBase is not a file"
      }
    }
    if (lexerBase != null) {
      check(Files.isRegularFile(lexerBase)) {
        "The $lexerBase is not a file"
      }
    }
    when {
      languageKindYamlFile != null -> {
        check(existingLanguageKindClassFullName == null)
        check(Files.isRegularFile(languageKindYamlFile)) {
          "The $languageKindYamlFile is not a file."
        }
      }
      existingLanguageKindClassFullName != null -> {
        check(languageKindYamlFile == null)
      }
      else -> {
        error(
          "Unreachable. You need to specify --language-kind-yaml-file or " +
            "--existing-language-full-class-name",
        )
      }
    }
    extraLibs.forEach {
      require(Files.isRegularFile(it))
    }
    createAdhocGrammarConfiguration() // Make sure does not crash
  }
}

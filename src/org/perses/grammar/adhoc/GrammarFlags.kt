/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.util.cmd.CommonCmdOptionGroupOrder
import org.perses.util.cmd.ICommandLineFlags
import java.nio.file.Files
import java.nio.file.Path

class GrammarFlags : ICommandLineFlags {

  @JvmField
  @Parameter(
    names = ["--parser-grammar"],
    description = "The parser grammar",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL,
  )
  var parserGrammar: Path? = null

  @JvmField
  @Parameter(
    names = ["--start-rule"],
    description = "The start rule of the grammar",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 100,
  )
  var startRuleName: String? = null

  @JvmField
  @Parameter(
    names = ["--token-names-of-identifiers"],
    description = "The token names of identifiers",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 200,
  )
  var tokenNamesOfIdentifiers: List<String> = listOf()

  @JvmField
  @Parameter(
    names = ["--lexer-grammar"],
    description = "The lexer grammar",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 300,
  )
  var lexerGrammar: Path? = null

  @Parameter(
    names = ["--package-name"],
    description = "The package name of the generated classes in the generated Jar file.",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 400,
  )
  var packageName: String? = null

  @Parameter(
    names = ["--parser-facade-class-simple-name"],
    description = "The simple class name of the generated parser facade",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 500,
  )
  var parserFacadeClassSimpleName: String? = null

  @Parameter(
    names = ["--language-kind-yaml-file"],
    description = "The YAML file which defines the language kind for this grammar",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 600,
  )
  var languageKindYamlFile: Path? = null

  @Parameter(
    names = ["--existing-language-full-class-name"],
    description = "The full class name of the existing language kind",
    required = false,
    order = CommonCmdOptionGroupOrder.GRAMMAR_CONTROL + 700,
  )
  var existingLanguageKindClassFullName: String? = null

  fun createAdhocGrammarConfiguration(): AdhocGrammarConfiguration {
    return AdhocGrammarConfiguration(
      parserFile = parserGrammar!!,
      lexerFile = lexerGrammar,
      packageName = packageName,
      parserFacadeClassSimpleName = parserFacadeClassSimpleName,
      languageKindYamlFile = languageKindYamlFile,
      existingLanguageKindClassFullName = existingLanguageKindClassFullName,
      startRuleName = startRuleName!!,
      tokenNamesOfIdentifiers = tokenNamesOfIdentifiers
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
            "--existing-language-full-class-name"
        )
      }
    }
    check(tokenNamesOfIdentifiers.isNotEmpty()) {
      "You need to specify --token-names-of-identifiers"
    }
    createAdhocGrammarConfiguration() // Make sure does not crash
  }
}

/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.spartree

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.c.LanguageC
import org.perses.grammar.cpp.LanguageCpp
import org.perses.grammar.go.LanguageGo
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.javascript.LanguageJavaScript
import org.perses.grammar.php.LanguagePhp
import org.perses.grammar.python3.LanguagePython3
import org.perses.grammar.ruby.LanguageRuby
import org.perses.grammar.rust.LanguageRust
import org.perses.grammar.scala.LanguageScala
import org.perses.grammar.smtlibv2.LanguageSmtLibV2
import org.perses.grammar.solidity.LanguageSolidity
import org.perses.grammar.sysverilog.LanguageSystemVerilog
import java.util.Random

@RunWith(JUnit4::class)
class RuleGenerationInfoTest {
  private val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()

  @Test
  fun testComputeStartSymbol() {
    for (language in languageToStartSymbolMap.keys) {
      val parserFacade = factory.getParserFacadeListForOrNull(language)!!
        .defaultParserFacade.create()
      val generator = RandomSparTreeGenerator(
        parserFacade,
        Random(0),
      )
      Truth.assertThat(generator.ruleGenerationInfo.startSymbol.ruleName)
        .isEqualTo(languageToStartSymbolMap[language]!!)
    }
  }

  companion object {
    val languageToStartSymbolMap = mapOf(
      LanguageC to "compilationUnit",
      LanguageCpp to "translationUnit",
      LanguageGo to "sourceFile",
      LanguageRust to "crate",
      LanguageJava to "compilationUnit",
      LanguageJavaScript to "program",
      LanguageScala to "compilationUnit",
      LanguageSystemVerilog to "source_text",
      LanguageRuby to "compilation_unit",
      LanguagePhp to "htmlDocument",
      LanguageSolidity to "sourceUnit",
      LanguagePython3 to "file_input",
      LanguageSmtLibV2 to "start",
    )
  }
}

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
package org.perses.grammar

import com.google.common.collect.ImmutableMap
import org.perses.grammar.SingleParserFacadeFactory.ParserFacadeFactoryCustomizer
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.cpp.LanguageCpp
import org.perses.grammar.cpp.PnfCppParserFacade
import org.perses.grammar.go.LanguageGo
import org.perses.grammar.go.PnfGoParserFacade
import org.perses.grammar.java.JavaParserFacade
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.javascript.JavaScriptParserFacade
import org.perses.grammar.javascript.LanguageJavaScript
import org.perses.grammar.php.LanguagePhp
import org.perses.grammar.php.PhpParserFacade
import org.perses.grammar.python3.LanguagePython3
import org.perses.grammar.python3.Python3ParserFacade
import org.perses.grammar.ruby.LanguageRuby
import org.perses.grammar.ruby.PnfRubyParserFacade
import org.perses.grammar.rust.LanguageRust
import org.perses.grammar.rust.PnfRustParserFacade
import org.perses.grammar.scala.LanguageScala
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.grammar.smtlibv2.LanguageSmtLibV2
import org.perses.grammar.smtlibv2.SmtLibV2ParserFacade
import org.perses.grammar.solidity.LanguageSolidity
import org.perses.grammar.solidity.preprocessed.PnfSolidityParserFacade
import org.perses.grammar.sqlite.LanguageSQLite
import org.perses.grammar.sqlite.SQLiteParserFacade
import org.perses.grammar.sysverilog.LanguageSystemVerilog
import org.perses.grammar.sysverilog.PnfSysverilogParserFacade
import org.perses.program.LanguageKind

/** Creates a parser facade, based on the type of language kind.  */
class SingleParserFacadeFactory private constructor(
  private val language2FacadeMap: ImmutableMap<LanguageKind, ParserFacadeCreator>
) : AbstractParserFacadeFactory() {

  init {
    if (language2FacadeMap.keys
      .asSequence()
      .map { it.name.lowercase() }
      .distinct().count() != language2FacadeMap.size
    ) {
      reportError("The names of the languages should be distinct by ignoring cases.")
    }
  }

  override fun createParserFacade(languageKind: LanguageKind): AbstractParserFacade {
    require(containsLanguage(languageKind)) {
      "Unrecognized language kind $languageKind"
    }
    return language2FacadeMap[languageKind]!!.create().also {
      check(it.language == languageKind) {
        "${it.language} != $languageKind"
      }
    }
  }

  override fun languageSequence(): Sequence<LanguageKind> {
    return language2FacadeMap.keys.asSequence()
  }

  fun interface ParserFacadeCreator {
    fun create(): AbstractParserFacade
  }

  fun interface ParserFacadeFactoryCustomizer {
    fun customize(
      language: LanguageKind,
      defaultParserFacadeCreator: ParserFacadeCreator
    ): ParserFacadeCreator
  }

  companion object {

    @JvmField
    val IDENTITY_CUSTOMIZER =
      ParserFacadeFactoryCustomizer { _, facadeCreator -> facadeCreator }

    @JvmStatic
    fun builderWithBuiltinLanguages(
      customizer: ParserFacadeFactoryCustomizer = IDENTITY_CUSTOMIZER
    ): Builder {
      val builder = Builder()
      builder.add(LanguageGo, { PnfGoParserFacade() }, customizer)
      builder.add(LanguageRust, { PnfRustParserFacade() }, customizer)
      builder.add(LanguageScala, { PnfScalaParserFacade() }, customizer)
      builder.add(LanguageJava, { JavaParserFacade() }, customizer)
      builder.add(LanguageC, { PnfCParserFacade() }, customizer)
      builder.add(LanguageSystemVerilog, { PnfSysverilogParserFacade() }, customizer)
      builder.add(LanguageSolidity, { PnfSolidityParserFacade() }, customizer)
      builder.add(LanguageCpp, { PnfCppParserFacade() }, customizer)
      builder.add(LanguageJavaScript, { JavaScriptParserFacade() }, customizer)
      builder.add(LanguagePhp, { PhpParserFacade() }, customizer)
      builder.add(LanguageSmtLibV2, { SmtLibV2ParserFacade() }, customizer)
      builder.add(LanguageSQLite, { SQLiteParserFacade() }, customizer)
      builder.add(LanguagePython3, { Python3ParserFacade() }, customizer)
      builder.add(LanguageRuby, { PnfRubyParserFacade() }, customizer)
      return builder
    }

    fun createEmptyFactory() = SingleParserFacadeFactory(ImmutableMap.of())
  }

  class Builder {
    private val language2FacadeMap =
      ImmutableMap.builder<LanguageKind, ParserFacadeCreator>()

    fun add(
      language: LanguageKind,
      facadeCreator: ParserFacadeCreator,
      customizer: ParserFacadeFactoryCustomizer = IDENTITY_CUSTOMIZER
    ): Builder {
      val customizedFacadeCreator = customizer.customize(language, facadeCreator)
      language2FacadeMap.put(language, customizedFacadeCreator)
      return this
    }

    fun build() = SingleParserFacadeFactory(language2FacadeMap.build())
  }
}

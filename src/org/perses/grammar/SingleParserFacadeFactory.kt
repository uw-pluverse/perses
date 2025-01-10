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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.cpp.LanguageCpp
import org.perses.grammar.cpp.PnfCppParserFacade
import org.perses.grammar.glsl.GlslParserFacade
import org.perses.grammar.glsl.LanguageGlsl
import org.perses.grammar.go.LanguageGo
import org.perses.grammar.go.PnfGoParserFacade
import org.perses.grammar.java.Java20ParserFacade
import org.perses.grammar.java.Java8ParserFacade
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.javascript.JavaScriptParserFacade
import org.perses.grammar.javascript.LanguageJavaScript
import org.perses.grammar.line.LanguageLine
import org.perses.grammar.line.LineParserFacade
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
import org.perses.grammar.sql.mysql.LanguageMySQL
import org.perses.grammar.sql.mysql.MySQLParserFacade
import org.perses.grammar.sql.sqlite.LanguageSQLite
import org.perses.grammar.sql.sqlite.SQLiteParserFacade
import org.perses.grammar.sql.tidb.LanguageTiDB
import org.perses.grammar.sysverilog.LanguageSystemVerilog
import org.perses.grammar.sysverilog.PnfSysverilogParserFacade
import org.perses.grammar.xml.LanguageXML
import org.perses.grammar.xml.PnfXMLParserFacade
import org.perses.program.LanguageKind
import org.perses.util.ktSevere
import org.perses.util.transformToImmutableList
import kotlin.reflect.KClass

/** Creates a parser facade, based on the type of language kind.  */
class SingleParserFacadeFactory private constructor(
  private val language2FacadeMap: ImmutableMap<LanguageKind, ParserFacadeList>,
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

  override fun getParserFacadeListForOrNull(languageKind: LanguageKind): ParserFacadeList? {
    return language2FacadeMap[languageKind]
  }

  override fun languageSequence(): Sequence<LanguageKind> {
    return language2FacadeMap.keys.asSequence()
  }

  companion object {

    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun builderWithBuiltinLanguages(): Builder {
      val builder = Builder()
      builder.add(LanguageGlsl, GlslParserFacade::class)
      builder.add(LanguageGo, PnfGoParserFacade::class)
      builder.add(LanguageRust, PnfRustParserFacade::class)
      builder.add(LanguageScala, PnfScalaParserFacade::class)
      builder.add(
        LanguageJava,
        defaultFacadeClass = Java8ParserFacade::class,
        otherParserFacades = ImmutableList.of(Java20ParserFacade::class),
      )
      builder.add(
        LanguageC,
        PnfCParserFacade::class,
        otherParserFacades = ImmutableList.of(CParserFacade::class),
      )
      builder.add(LanguageSystemVerilog, PnfSysverilogParserFacade::class)
      builder.add(LanguageSolidity, PnfSolidityParserFacade::class)
      builder.add(LanguageCpp, PnfCppParserFacade::class)
      builder.add(LanguageXML, PnfXMLParserFacade::class)
      builder.add(LanguageJavaScript, JavaScriptParserFacade::class)
      builder.add(LanguagePhp, PhpParserFacade::class)
      builder.add(LanguageSmtLibV2, SmtLibV2ParserFacade::class)
      builder.add(LanguageSQLite, SQLiteParserFacade::class)
      builder.add(LanguageMySQL, MySQLParserFacade::class)
      builder.add(LanguagePython3, Python3ParserFacade::class)
      builder.add(LanguageRuby, PnfRubyParserFacade::class)
      builder.add(LanguageLine, LineParserFacade::class)
      tryToDynamicallyLoadParserFacades(builder)
      return builder
    }

    @Suppress("UNCHECKED_CAST")
    private fun tryToDynamicallyLoadParserFacades(builder: Builder) {
      val className = "org.perses.grammar.sql.tidb.TiDBParserFacade"
      try {
        val javaClass = Class.forName(className)
          as Class<out AbstractParserFacade>
        val klass = javaClass.kotlin
        builder.add(LanguageTiDB, defaultFacadeClass = klass)
      } catch (e: ClassNotFoundException) {
        logger.ktSevere {
          """Failed to load the class of the parser facade $className for $LanguageTiDB
            |${e.message}
          """.trimMargin()
        }
      }
    }

    fun createEmptyFactory() = SingleParserFacadeFactory(ImmutableMap.of())
  }

  class Builder {
    private val language2FacadeMap =
      ImmutableMap.builder<LanguageKind, ParserFacadeList>()

    fun add(
      language: LanguageKind,
      defaultFacadeClass: KClass<out AbstractParserFacade>,
      otherParserFacades: ImmutableList<KClass<out AbstractParserFacade>> = ImmutableList.of(),
    ): Builder {
      language2FacadeMap.put(
        language,
        ParserFacadeList(
          defaultParserFacade = ParserFacadeCreator(defaultFacadeClass),
          otherParserFacades = otherParserFacades.transformToImmutableList {
            ParserFacadeCreator(it)
          },
        ),
      )
      return this
    }

    fun build() = SingleParserFacadeFactory(language2FacadeMap.build())
  }
}

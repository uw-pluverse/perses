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
import org.perses.grammar.dyck.AbstractDyckParserFacade
import org.perses.grammar.dyck.BraceDyckParserFacade
import org.perses.grammar.dyck.BraceParenthesisDyckParserFacade
import org.perses.grammar.dyck.LanguageBraceDyck
import org.perses.grammar.dyck.LanguageBraceParenthesisDyck
import org.perses.grammar.glsl.GlslParserFacade
import org.perses.grammar.glsl.LanguageGlsl
import org.perses.grammar.go.LanguageGo
import org.perses.grammar.go.PnfGoParserFacade
import org.perses.grammar.jackson.JacksonParserFacade
import org.perses.grammar.jackson.LanguageJackson
import org.perses.grammar.java.Java20ParserFacade
import org.perses.grammar.java.Java8ParserFacade
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.javascript.JavaScriptParserFacade
import org.perses.grammar.javascript.LanguageJavaScript
import org.perses.grammar.line.LanguageLine
import org.perses.grammar.line.LineParserFacade
import org.perses.grammar.onetoken.LanguageOneToken
import org.perses.grammar.onetoken.OneTokenParserFacade
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
import org.perses.grammar.wasm.LanguageWebAssembly
import org.perses.grammar.wasm.WebAssemblyParserFacade
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
        .distinct()
        .count() != language2FacadeMap.size
    ) {
      reportError("The names of the languages should be distinct by ignoring cases.")
    }
  }

  override fun getParserFacadeListForOrNull(languageKind: LanguageKind): ParserFacadeList? =
    language2FacadeMap[languageKind]

  // TODO(cnsun): need tests.
  override fun getParserFacadeClassForClassNameOrNull(
    className: String,
  ): Pair<LanguageKind, ParserFacadeCreator>? =
    language2FacadeMap
      .entries
      .flatMap { entry ->
        entry.value.sequenceOfCreators().map { entry.key to it }
      }.firstOrNull { pair ->
        pair.second.klass.qualifiedName == className
      }

  override fun languageSequence(): Sequence<LanguageKind> = language2FacadeMap.keys.asSequence()

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun builderWithBuiltinLanguages(): Builder {
      val builder =
        Builder()
          .add(LanguageGlsl, GlslParserFacade::class)
          .add(LanguageGo, PnfGoParserFacade::class)
          .add(LanguageRust, PnfRustParserFacade::class)
          .add(LanguageScala, PnfScalaParserFacade::class)
          .add(
            LanguageJava,
            defaultFacadeClass = Java8ParserFacade::class,
            otherParserFacades = ImmutableList.of(Java20ParserFacade::class),
          ).add(
            LanguageC,
            PnfCParserFacade::class,
            otherParserFacades = ImmutableList.of(CParserFacade::class),
          ).add(LanguageSystemVerilog, PnfSysverilogParserFacade::class)
          .add(LanguageSolidity, PnfSolidityParserFacade::class)
          .add(LanguageCpp, PnfCppParserFacade::class)
          .add(LanguageXML, PnfXMLParserFacade::class)
          .add(LanguageJavaScript, JavaScriptParserFacade::class)
          .add(LanguagePhp, PhpParserFacade::class)
          .add(LanguageSmtLibV2, SmtLibV2ParserFacade::class)
          .add(LanguageSQLite, SQLiteParserFacade::class)
          .add(LanguageMySQL, MySQLParserFacade::class)
          .add(LanguagePython3, Python3ParserFacade::class)
          .add(LanguageRuby, PnfRubyParserFacade::class)
          .add(LanguageLine, LineParserFacade::class)
          .add(LanguageOneToken, OneTokenParserFacade::class)
          .add(LanguageJackson, JacksonParserFacade::class)
          .add(LanguageWebAssembly, WebAssemblyParserFacade::class)
      tryToDynamicallyLoadParserFacades(builder)

      builder.add(LanguageBraceDyck, BraceDyckParserFacade::class)
      builder.add(LanguageBraceParenthesisDyck, BraceParenthesisDyckParserFacade::class)
      return builder
    }

    @Suppress("UNCHECKED_CAST")
    private fun tryToDynamicallyLoadParserFacades(builder: Builder) {
      val className = "org.perses.grammar.sql.tidb.TiDBParserFacade"
      try {
        val javaClass =
          Class.forName(className)
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
          otherParserFacades =
            otherParserFacades.transformToImmutableList {
              ParserFacadeCreator(it)
            },
        ),
      )
      return this
    }

    fun add(
      language: LanguageKind,
      dyckParserFacadeClass: KClass<out AbstractDyckParserFacade>,
    ): Builder {
      language2FacadeMap.put(
        language,
        ParserFacadeList(
          defaultParserFacade = DyckParserFacadeCreator(dyckParserFacadeClass),
        ),
      )
      return this
    }

    fun build() = SingleParserFacadeFactory(language2FacadeMap.build())
  }
}

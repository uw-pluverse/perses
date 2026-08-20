/*
 * Copyright (C) 2018-2026 University of Waterloo.
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

import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.OptCLexer
import org.perses.grammar.c.PnfCLexer
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.cpp.CPP14Lexer
import org.perses.grammar.cpp.PnfCppParserFacade
import org.perses.grammar.dyck.BraceDyckParserFacade
import org.perses.grammar.dyck.BraceParenthesisDyckParserFacade
import org.perses.grammar.glsl.GlslParserFacade
import org.perses.grammar.glsl.PnfGLSLLexer
import org.perses.grammar.go.GoLexer
import org.perses.grammar.go.PnfGoParserFacade
import org.perses.grammar.jackson.JacksonParserFacade
import org.perses.grammar.jackson.PnfJacksonParser
import org.perses.grammar.java.Java20Lexer
import org.perses.grammar.java.Java20ParserFacade
import org.perses.grammar.java.Java8Lexer
import org.perses.grammar.java.Java8ParserFacade
import org.perses.grammar.javascript.JavaScriptLexer
import org.perses.grammar.javascript.JavaScriptParserFacade
import org.perses.grammar.line.LineParserFacade
import org.perses.grammar.makefile.MakefileParserFacade
import org.perses.grammar.onetoken.OneTokenParserFacade
import org.perses.grammar.php.PhpLexer
import org.perses.grammar.php.PhpParserFacade
import org.perses.grammar.python3.Python3Lexer
import org.perses.grammar.python3.Python3ParserFacade
import org.perses.grammar.ruby.PnfRubyParserFacade
import org.perses.grammar.ruby.RubyLexer
import org.perses.grammar.rust.PnfRustLexer
import org.perses.grammar.rust.PnfRustParserFacade
import org.perses.grammar.scala.PnfScalaLexer
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.grammar.smtlibv2.PnfSMTLIBv2Lexer
import org.perses.grammar.smtlibv2.SmtLibV2ParserFacade
import org.perses.grammar.solidity.preprocessed.PnfSolidityParserFacade
import org.perses.grammar.solidity.preprocessed.SolidityLexer
import org.perses.grammar.sql.mysql.MySQLParserFacade
import org.perses.grammar.sql.mysql.MySqlLexer
import org.perses.grammar.sql.sqlite.SQLiteLexer
import org.perses.grammar.sql.sqlite.SQLiteParserFacade
import org.perses.grammar.sysverilog.PnfSysverilogParserFacade
import org.perses.grammar.sysverilog.SV3_1aLexer
import org.perses.grammar.wasm.WatLexer
import org.perses.grammar.wasm.WebAssemblyParserFacade
import org.perses.grammar.xml.PnfXMLParserFacade
import org.perses.grammar.xml.XMLLexer
import kotlin.reflect.KClass

/**
 * Pins, for every built-in parser facade, the effective identifier-token set
 * ([org.perses.grammar.AbstractParserFacade.fusedIdentifierTokenTypes]).
 * That set drives every identifier-aware reducer (TRec canonicalization, vulcan
 * identifier replacement, kitten generation), so a silent change to either a
 * grammar's `token_names_of_identifiers` config or the detector heuristic would
 * change reduction behavior across languages. This test makes such a change fail
 * with an explicit per-facade diff.
 *
 * Every built-in facade is authoritative (constructed with
 * `includeAutoDetectedIdentifierTokenTypes = false`), so each effective set is
 * exactly its curated config and auto-detection contributes nothing here. The
 * detector only runs for ad-hoc grammars that declare no tokens.
 *
 * Expected values are typed lexer/parser token constants (e.g. [OptCLexer.Identifier]),
 * not strings, so a renamed or deleted token breaks compilation rather than
 * silently drifting.
 *
 * TiDB is intentionally absent: its facade is loaded dynamically and is not on
 * this test target's classpath, so the builtin factory does not surface it here.
 */
@RunWith(JUnit4::class)
class IdentifierTokenAuditTest {
  private val expectedIdentifierTokenTypes: Map<KClass<out AbstractParserFacade>, List<Int>> =
    mapOf(
      WebAssemblyParserFacade::class to listOf(WatLexer.VAR),
      PnfCParserFacade::class to listOf(PnfCLexer.Identifier),
      CParserFacade::class to listOf(OptCLexer.Identifier),
      PnfCppParserFacade::class to listOf(CPP14Lexer.Identifier),
      BraceDyckParserFacade::class to emptyList(),
      BraceParenthesisDyckParserFacade::class to emptyList(),
      GlslParserFacade::class to listOf(PnfGLSLLexer.IDENTIFIER),
      PnfGoParserFacade::class to listOf(GoLexer.IDENTIFIER),
      JacksonParserFacade::class to listOf(PnfJacksonParser.FIELD_NAME),
      Java8ParserFacade::class to listOf(Java8Lexer.Identifier),
      Java20ParserFacade::class to listOf(Java20Lexer.Identifier),
      JavaScriptParserFacade::class to listOf(JavaScriptLexer.Identifier),
      LineParserFacade::class to emptyList(),
      // WORD is a catch-all run of non-whitespace characters, not a clean identifier.
      MakefileParserFacade::class to emptyList(),
      MySQLParserFacade::class to listOf(MySqlLexer.ID),
      OneTokenParserFacade::class to emptyList(),
      // VarName ($x) and Label (barewords: function/class/const names) are both
      // identifiers; both declared explicitly.
      PhpParserFacade::class to listOf(PhpLexer.VarName, PhpLexer.Label),
      Python3ParserFacade::class to listOf(Python3Lexer.NAME),
      // Authoritative: the detector would also flag HereDocEnd1 (a heredoc terminator),
      // but authoritative mode excludes that false positive.
      PnfRubyParserFacade::class to listOf(RubyLexer.Identifier),
      PnfRustParserFacade::class to listOf(PnfRustLexer.Ident),
      PnfScalaParserFacade::class to
        listOf(PnfScalaLexer.Id, PnfScalaLexer.BoundVarid, PnfScalaLexer.Varid),
      SmtLibV2ParserFacade::class to listOf(PnfSMTLIBv2Lexer.UndefinedSymbol),
      // Authoritative: the detector would also flag the fixed-point type keywords
      // Fixed/Ufixed, but authoritative mode excludes those false positives.
      PnfSolidityParserFacade::class to
        listOf(SolidityLexer.Identifier, SolidityLexer.YulIdentifier),
      SQLiteParserFacade::class to listOf(SQLiteLexer.IDENTIFIER),
      PnfSysverilogParserFacade::class to
        listOf(SV3_1aLexer.Escaped_identifier, SV3_1aLexer.Simple_identifier),
      PnfXMLParserFacade::class to listOf(XMLLexer.Name),
    )

  @Test
  fun identifierTokenSpecificationPerLanguage() {
    val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
    val visited = mutableSetOf<KClass<out AbstractParserFacade>>()
    factory.languageSequence().forEach { lang ->
      factory.getParserFacadeListForOrNull(lang)!!.sequenceOfCreators().forEach { creator ->
        val facadeClass = creator.klass
        visited.add(facadeClass)
        val expected =
          expectedIdentifierTokenTypes[facadeClass]
            ?: error(
              "No expected identifier token types pinned for facade " +
                "${facadeClass.qualifiedName}. Add an entry to expectedIdentifierTokenTypes.",
            )
        val actual = creator.create().fusedIdentifierTokenTypes.map { it.antlrTokenType }
        assertWithMessage("identifier token types for ${facadeClass.simpleName} (${lang.name})")
          .that(actual)
          .containsExactlyElementsIn(expected)
      }
    }
    assertWithMessage("expectedIdentifierTokenTypes has stale entries not produced by the factory")
      .that(expectedIdentifierTokenTypes.keys)
      .containsExactlyElementsIn(visited)
  }

  /**
   * Asserts which built-in facades exclude an auto-detected token from their
   * authoritative specification. The only two are the known detector false positives;
   * a new entry here means either an identifier a curated list forgot or a new false
   * positive -- both worth review.
   */
  @Test
  fun autoDetectedIdentifierTokenTypesNotSpecified() {
    val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
    val warnings = LinkedHashMap<KClass<out AbstractParserFacade>, List<String>>()
    factory.languageSequence().forEach { lang ->
      factory.getParserFacadeListForOrNull(lang)!!.sequenceOfCreators().forEach { creator ->
        val excluded = creator.create().warnAboutAutoDetectedIdentifierTokenTypesNotSpecified()
        if (excluded.isNotEmpty()) {
          warnings[creator.klass] = excluded
        }
      }
    }
    assertThat(warnings)
      .containsExactlyEntriesIn(
        mapOf(
          PnfRubyParserFacade::class to listOf("HereDocEnd1"),
          PnfSolidityParserFacade::class to listOf("Fixed", "Ufixed"),
        ),
      )
  }
}

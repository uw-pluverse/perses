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
package org.perses.reduction.reducer.latra.language

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.smtlibv2.SmtLibV2ParserFacade
import org.perses.grammar.wasm.WebAssemblyParserFacade
import org.perses.program.TokenPosition
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.ConcreteToken
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Trivia

@RunWith(JUnit4::class)
class LatraPatternTest {
  private val cParserFacade = CParserFacade()
  private val smtParserFacade = SmtLibV2ParserFacade()

  @Test
  fun testHoleReplacement() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent = "a :[name] b",
        parserFacade = cParserFacade,
      )
    val transformed =
      pattern.replaceHolesWithHoles { it ->
        Hole.create(
          holeName = it.holeName.name,
          greedyKleenePlusMatching = true,
          tokenPosition = TokenPosition(line = 1, charPositionInLine = 1),
        )
      }
    assertThat(transformed.originalSourceCode).isEqualTo("a :[name+] b")
  }

  @Test
  fun testParseInvalidHoles() {
    val patternContent =
      """
        ( func :[funcName] (param :[argName1] :[argType1]) (param: [argName2] :[argType2]) 
          (result :[return_type])
          :[body+]
        )
      """
    Assert.assertThrows(Exception::class.java) {
      AbstractLatraPattern.parseMatchingPattern(
        patternContent = patternContent,
        parserFacade = WebAssemblyParserFacade(),
      )
    }
  }

  @Test
  fun testParsingSuchAsWithRangeMarkers() {
    val clause = SuchAsClause("( assert {g: ( = false ( _ bv1 123 )) :} )")
    assertThat(clause.isEmpty()).isFalse()
  }

  @Test
  fun testParseWatPattern() {
    val patternContent =
      """
        ( func :[funcName] (param :[argName1] :[argType1]) (param :[argName2] :[argType2]) 
          (result :[return_type])
          :[body+]
        )
      """
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent = patternContent,
        parserFacade = WebAssemblyParserFacade(),
      )
    assertThat(pattern.holes.map { it.holeName.name }).containsExactly(
      "funcName",
      "argName1",
      "argType1",
      "argName2",
      "argType2",
      "return_type",
      "body",
    )
  }

  @Test
  fun testHasNoHoles() {
    AbstractLatraPattern
      .parseMatchingPattern(
        patternContent = "a b c",
        parserFacade = cParserFacade,
      ).let { pattern ->
        assertThat(pattern.hasNoHoles()).isTrue()
      }
    AbstractLatraPattern
      .parseMatchingPattern(
        patternContent = ":[a]",
        cParserFacade,
      ).let { pattern ->
        assertThat(pattern.hasNoHoles()).isFalse()
      }
  }

  @Test
  fun testOriginalSourceCode() {
    ConcreteToken(
      token = cParserFacade.tokenizeString(content = "a", fileName = "empty").single(),
    ).let {
      assertThat(it.originalSourceCode).isEqualTo("a")
    }

    val position = TokenPosition(line = 1, charPositionInLine = 1)

    Hole.create(holeName = "a", greedyKleenePlusMatching = false, position).let {
      assertThat(it.originalSourceCode).isEqualTo(":[a]")
    }
    Hole.create(holeName = "a", greedyKleenePlusMatching = true, position).let {
      assertThat(it.originalSourceCode).isEqualTo(":[a+]")
    }

    Trivia(originalSourceCode = " \t", position).let {
      assertThat(it.originalSourceCode).isEqualTo(" \t")
    }
  }

  @Test
  fun testLatterPatternToOriginalSourceCode() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent = "int a = :[ a + ] ; ",
        cParserFacade,
      )
    assertThat(pattern.originalSourceCode).isEqualTo("int a = :[a+] ; ")
    pattern.replaceHolesWith(mapOf(Hole.HoleName("a") to "b")).let {
      assertThat(it).isEqualTo("int a = b ; ")
    }
  }

  @Test
  fun testLatterPatternToOriginalSourceCodeMultiLine() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent =
          """
          int main() {
            int a = :[ a + ] ; 
            return 0;
          }
          """.trimIndent(),
        cParserFacade,
      )
    assertThat(pattern.originalSourceCode).isEqualTo(
      """
      int main() {
        int a = :[a+] ; 
        return 0;
      }
      """.trimIndent(),
    )
  }

  @Test
  fun testParsingPattern() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent =
          """
          typedef :[ type +] :[ name ];
          """.trimIndent(),
        cParserFacade,
      )

    pattern.elements.let { result ->
      assertThat((result[0] as ConcreteToken).token.text).isEqualTo("typedef")
      assertThat((result[1] as Trivia).originalSourceCode).isEqualTo(" ")
      (result[2] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("type")
        assertThat(it.greedyKleenePlusMatching).isTrue()
      }
      assertThat((result[3] as Trivia).originalSourceCode).isEqualTo(" ")
      (result[4] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("name")
        assertThat(it.greedyKleenePlusMatching).isFalse()
      }
      assertThat((result[5] as ConcreteToken).token.text).isEqualTo(";")
    }
  }

  @Test
  fun testParsingPatternNoHole() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent =
          """
          typedef int ll;
          """.trimIndent(),
        cParserFacade,
      )

    pattern.elements.let { result ->
      assertThat((result[0] as ConcreteToken).token.text).isEqualTo("typedef")
      assertThat((result[1] as Trivia).originalSourceCode).isEqualTo(" ")
      assertThat((result[2] as ConcreteToken).token.text).isEqualTo("int")
      assertThat((result[3] as Trivia).originalSourceCode).isEqualTo(" ")
      assertThat((result[4] as ConcreteToken).token.text).isEqualTo("ll")
      assertThat((result[5] as ConcreteToken).token.text).isEqualTo(";")
    }
  }

  @Test
  fun testParsingPatternOnlyHoles() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent =
          """
          :[typedef] :[type+] :[name]:[semicolon]
          """.trimIndent(),
        cParserFacade,
      )

    pattern.elements.let { result ->
      (result[0] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("typedef")
        assertThat(it.greedyKleenePlusMatching).isFalse()
      }
      assertThat((result[1] as Trivia).originalSourceCode).isEqualTo(" ")
      (result[2] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("type")
        assertThat(it.greedyKleenePlusMatching).isTrue()
      }
      assertThat((result[3] as Trivia).originalSourceCode).isEqualTo(" ")
      (result[4] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("name")
        assertThat(it.greedyKleenePlusMatching).isFalse()
      }
      (result[5] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("semicolon")
        assertThat(it.greedyKleenePlusMatching).isFalse()
      }
    }
  }

  @Test
  fun testParsingPatternOnlyWhiteSpace() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent = "  ",
        cParserFacade,
      )

    assertThat(pattern.elements).hasSize(1)
    assertThat((pattern.elements[0] as Trivia).originalSourceCode).isEqualTo("  ")
  }

  @Test
  fun testParsingPatternOnlyComment() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent = "// Hello",
        cParserFacade,
      )

    assertThat(pattern.elements).hasSize(1)
    assertThat((pattern.elements[0] as Trivia).originalSourceCode).isEqualTo("// Hello")
  }

  @Test
  fun testParsingPatternMix() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent =
          """
          typedef /* comment */ :[ type +] :[ name ];
          """.trimIndent(),
        cParserFacade,
      )
//    val typeHole = Hole.create(holeName = "type", greedyKleenePlusMatching = true)
//    val nameHole = Hole.create(holeName = "name", greedyKleenePlusMatching = false)

    pattern.elements.let { result ->
      assertThat((result[0] as ConcreteToken).token.text).isEqualTo("typedef")
      assertThat((result[1] as Trivia).originalSourceCode).isEqualTo(" /* comment */ ")
      (result[2] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("type")
        assertThat(it.greedyKleenePlusMatching).isTrue()
      }
      assertThat((result[3] as Trivia).originalSourceCode).isEqualTo(" ")
      (result[4] as Hole).let {
        assertThat(it.holeName.name).isEqualTo("name")
        assertThat(it.greedyKleenePlusMatching).isFalse()
      }
      assertThat((result[5] as ConcreteToken).token.text).isEqualTo(";")
    }
  }

  @Test
  fun testParsingPatternMultipleTokens() {
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent =
          """
          typedef long long int ll;
          """.trimIndent(),
        cParserFacade,
      )

    pattern.elements.let { result ->
      assertThat((result[0] as ConcreteToken).token.text).isEqualTo("typedef")
      assertThat((result[1] as Trivia).originalSourceCode).isEqualTo(" ")
      assertThat((result[2] as ConcreteToken).token.text).isEqualTo("long")
      assertThat((result[3] as Trivia).originalSourceCode).isEqualTo(" ")
      assertThat((result[4] as ConcreteToken).token.text).isEqualTo("long")
      assertThat((result[5] as Trivia).originalSourceCode).isEqualTo(" ")
      assertThat((result[6] as ConcreteToken).token.text).isEqualTo("int")
      assertThat((result[7] as Trivia).originalSourceCode).isEqualTo(" ")
      assertThat((result[8] as ConcreteToken).token.text).isEqualTo("ll")
      assertThat((result[9] as ConcreteToken).token.text).isEqualTo(";")
    }
  }
}

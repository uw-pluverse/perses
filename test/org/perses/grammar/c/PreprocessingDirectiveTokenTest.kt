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
package org.perses.grammar.c

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling

/**
 * Covers the preprocessing-directive tokens in OrigC.g4. The grammar keeps [PnfCLexer.IncludeDirective]
 * (only `#include`) and adds [PnfCLexer.PreprocessingDirective] for every other directive, lexed as ONE
 * token. The new token is deliberately absent from every parser rule: the point is to stop directives
 * from being un-lexable and dropped character by character, NOT to make them parse -- so the strict C
 * grammar still rejects them and the //benchmark_v2/benchmark_c_unparseable corpus stays unparseable.
 */
@RunWith(JUnit4::class)
class PreprocessingDirectiveTokenTest {

  private val facade = PnfCParserFacade()

  private fun single(input: String): org.antlr.v4.runtime.Token {
    val tokens = facade.tokenizeString(input)
    assertThat(tokens).hasSize(1)
    return tokens.single()
  }

  @Test
  fun includeIsStillItsOwnToken() {
    val token = single("#include <stdio.h>")
    assertThat(token.type).isEqualTo(PnfCLexer.IncludeDirective)
    assertThat(token.text).isEqualTo("#include <stdio.h>")
  }

  @Test
  fun everyOtherDirectiveIsOnePreprocessingDirectiveToken() {
    for (directive in listOf(
      "#if defined(A) && !defined(B)",
      "#ifdef DEBUG",
      "#ifndef GUARD",
      "#elif defined(C)",
      "#else",
      "#endif",
      "#define X 0",
      "#undef X",
      "#pragma once",
      "#error nope",
    )) {
      val token = single(directive)
      assertThat(token.type).isEqualTo(PnfCLexer.PreprocessingDirective)
      assertThat(token.text).isEqualTo(directive)
    }
  }

  @Test
  fun aSplicedDirectiveIsOneToken() {
    // `#def\<newline>ine X 0` -- the backslash-newline continuation is absorbed, so the whole spliced
    // directive is a single token (the mutation in the unparseable splice benchmarks).
    val token = single("#def\\\nine X 0")
    assertThat(token.type).isEqualTo(PnfCLexer.PreprocessingDirective)
    assertThat(token.text).isEqualTo("#def\\\nine X 0")
  }

  @Test
  fun aDirectiveDoesNotConsumeTheFollowingLine() {
    // The directive stops at the (unescaped) newline; the next line lexes normally.
    val texts = facade.tokenizeString("#endif\nint x;").map { it.text }
    assertThat(texts).containsExactly("#endif", "int", "x", ";").inOrder()
  }

  @Test
  fun aNonIncludeDirectiveMakesTheProgramUnparseable() {
    // PreprocessingDirective is in no parser rule, so a program containing one does not parse under
    // the strict C grammar -- which is exactly why recognizing the token does not rescue the
    // unparseable benchmarks. (This relies on the facade parsing from compilationUnit, which anchors
    // to EOF; translationUnit would silently accept the prefix and drop a trailing directive.)
    for (program in listOf(
      "#if 0\nint x;\n#endif\n",
      "int x;\n#define Y 1\n",
      "#def\\\nine Z 2\nint keep;\n",
      "#define X 0\nint y;\n",
    )) {
      assertThat(facade.isSourceCodeParsable(program)).isFalse()
    }
  }

  @Test
  fun includeStillParsesAtTopLevel() {
    // Contrast: #include IS wired into externalDeclaration, so it parses strictly.
    val tree = facade.parseString("#include <stdio.h>\n", errorMode = ParseErrorHandling.STRICT).tree
    assertThat(tree).isNotNull()
  }
}

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
package org.perses.grammar.makefile

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import java.nio.file.Paths
import kotlin.io.path.readText

/**
 * Stress-tests the Makefile grammar against a corpus of real-world Makefile constructs (variable
 * flavors, `define`/`endef`, conditionals, functions, `\`-continuations, pattern and static-pattern
 * rules, `include`/`.PHONY`/special targets, recipe prefixes, CRLF line endings). Each file must
 * parse (parsing throws on any syntax error, and the start rule requires EOF) and the parse tree must
 * preserve the file's content: concatenating the parse-tree tokens reproduces the original, compared
 * on non-blank characters only -- the grammar's NEWLINE is skipped, so inter-token whitespace differs
 * but no non-blank byte may be lost.
 */
@RunWith(JUnit4::class)
class MakefileParserFacadeTest {
  private val facade = MakefileParserFacade()

  @Test
  fun parseClassicProject() = parseAndCheckContent("classic_project.mk")

  @Test
  fun parseVariablesAndDefine() = parseAndCheckContent("variables_define.mk")

  @Test
  fun parseConditionals() = parseAndCheckContent("conditionals.mk")

  @Test
  fun parseFunctionsAndContinuations() = parseAndCheckContent("functions_continuations.mk")

  @Test
  fun parseIncludesAndSpecialTargets() = parseAndCheckContent("includes_special.mk")

  @Test
  fun parseExtensionlessMakefile() = parseAndCheckContent("Makefile")

  @Test
  fun parseCrlfEndings() = parseAndCheckContent("crlf_endings.mk")

  private fun parseAndCheckContent(fileName: String) {
    val source = getFile(fileName)
    val tokensFromTree =
      TestUtility.extractTokenTexts(facade.parseFile(source).tree).joinToString(separator = "")
    assertThat(tokensFromTree.nonBlankCharacters())
      .isEqualTo(source.readText().nonBlankCharacters())
  }

  private fun String.nonBlankCharacters(): String = filterNot { it.isWhitespace() }

  private fun getFile(fileName: String) =
    Paths.get("test/org/perses/grammar/makefile/real_world_makefiles/$fileName")
}

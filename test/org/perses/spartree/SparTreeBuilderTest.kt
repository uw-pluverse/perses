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
package org.perses.spartree
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.tree.ParseTree
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.OrigCParserFacade
import org.perses.grammar.xml.PnfXMLParserFacade
import org.perses.program.EnumFormatControl
import org.perses.program.printer.PrinterRegistry
import org.perses.util.SimpleStack
import java.io.File
import java.nio.charset.StandardCharsets

@RunWith(JUnit4::class)
class SparTreeBuilderTest {
  private fun treeComparison(
    builder: SparTreeBuilder,
    parseTreeRoot: ParseTree,
    sparTreeRoot: AbstractSparTreeNode,
  ) {
    assertThat(builder.getMappedNodeFor(parseTreeRoot)).isSameInstanceAs(sparTreeRoot)
    val sparStack = SimpleStack<AbstractSparTreeNode>()
    val parseStack = SimpleStack<ParseTree>()
    sparStack.add(sparTreeRoot)
    parseStack.add(parseTreeRoot)
    while (sparStack.isNotEmpty() && parseStack.isNotEmpty()) {
      val parseNode = parseStack.remove()
      val sparNode = sparStack.remove()
      assertThat(builder.getMappedNodeFor(parseNode)).isSameInstanceAs(sparNode)
      val childCount = parseNode.childCount
      var counter = 0
      for (i in 0 until childCount) {
        val child = parseNode.getChild(i)
        if (SparTreeBuilder.isEmptyRuleNode(child) || SparTreeBuilder.isEOFToken(child)) {
          continue
        }
        parseStack.add(child)
        counter += 1
      }
      for (i in 0 until sparNode.childCount) {
        sparStack.add(sparNode.getChild(i))
        counter -= 1
      }
      assertThat(counter).isEqualTo(0)
    }
    assertThat(sparStack.isEmpty() && parseStack.isEmpty()).isTrue()
  }

  @Test
  fun testBuildSparTreeWithOrigParserFacade() {
    val facade: AbstractParserFacade = OrigCParserFacade()
    val sourceCode =
      """
      |int main() {
      |    return 0;
      |}
      """.trimMargin()
    val tree =
      TestUtility.createSparTreeFromString(
        sourceCode.trimIndent(),
        facade,
        simplifyTree = false,
      )
    val printedProgram =
      PrinterRegistry
        .getPrinter(
          EnumFormatControl.COMPACT_ORIG_FORMAT,
          facade.lexerAtnWrapper,
        ).print(
          tree.programSnapshot.payload,
        ).sourceCode
    assertThat(sourceCode.trim()).isEqualTo(printedProgram.trim())
  }

  @Test
  fun testSpar2AntlrMap() {
    val filename = "test_data/parentheses/t.c"
    val source = File(filename).readText(StandardCharsets.UTF_8)
    val facade = CParserFacade()

    val parseTreeWithParser = TestUtility.parseString(source, LanguageC)
    val sparTreeNodeFactory = SparTreeNodeFactory(facade)
    val builder =
      SparTreeBuilder(
        sparTreeNodeFactory,
        parseTreeWithParser,
        simplifyTree = false,
        canonicalTokenCountComputer = { null },
      )
    val sparTree = builder.result
    treeComparison(builder, parseTreeWithParser.tree, sparTree.realRoot)
  }

  /**
   * XML lexes the whitespace between elements as tokens. Left out, they are not leaves, while
   * whitespace inside a text token is part of that token; printing in the original format puts the
   * layout back from the positions.
   */
  @Test
  fun testWhitespaceOnlyTokensCanBeLeftOutOfTheTree() {
    val sourceCode = "<a>\n  <b>x</b>\n  text\n</a>\n"

    fun tokensOf(excludeWhitespaceOnlyTokens: Boolean) =
      SparTreeParserUtility
        .buildSparTree(
          sourceCode = sourceCode,
          parserFacade = PnfXMLParserFacade(),
          specifiedSparTreeNodeFactory = null,
          simplifyTree = true,
          canonicalTokenCountComputer = { null },
          errorMode = ParseErrorHandling.STRICT,
          excludeWhitespaceOnlyTokens = excludeWhitespaceOnlyTokens,
        ).programSnapshot.payload

    val kept = tokensOf(excludeWhitespaceOnlyTokens = false)
    val excluded = tokensOf(excludeWhitespaceOnlyTokens = true)

    assertThat(kept.tokens.map { it.lexemeText }).contains("\n  ")
    assertThat(excluded.tokens.map { it.lexemeText })
      .containsExactlyElementsIn(kept.tokens.map { it.lexemeText }.filter { it.isNotBlank() })
      .inOrder()
    assertThat(excluded.tokens.map { it.lexemeText }).contains("\n  text\n")
    assertThat(PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT).print(excluded).sourceCode)
      .isEqualTo(sourceCode)
  }
}

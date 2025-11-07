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
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.tree.ParseTree
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.ParseTreeUtil
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.OrigCParserFacade
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgramFactory
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
          tree.programSnapshot,
        ).sourceCode
    assertThat(sourceCode.trim()).isEqualTo(printedProgram.trim())
  }

  @Test
  fun testSpar2AntlrMap() {
    val filename = "test_data/parentheses/t.c"
    val source = File(filename).readText(StandardCharsets.UTF_8)
    val facade = CParserFacade()

    val parseTreeWithParser = TestUtility.parseString(source, LanguageC)
    val factory =
      TokenizedProgramFactory.createFactory(
        ParseTreeUtil.getTokens(parseTreeWithParser.tree),
        LanguageC,
      )
    val sparTreeNodeFactory =
      SparTreeNodeFactory(
        facade.metaTokenInfoDb,
        factory,
        facade.ruleHierarchy,
      )
    val builder =
      SparTreeBuilder(
        sparTreeNodeFactory,
        parseTreeWithParser,
        simplifyTree = false,
      )
    val sparTree = builder.result
    treeComparison(builder, parseTreeWithParser.tree, sparTree.realRoot)
  }
}

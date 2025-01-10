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
package org.perses.dotgraph

import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.antlr.RuleType
import org.perses.dotgraph.DotGraph.NodeLabelProvider
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.program.SourceFile
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.PlaceholderSparTreeNode
import org.perses.util.ktInfo
import java.io.IOException
import java.nio.file.Path
import java.nio.file.Paths
import java.util.LinkedList
import java.util.Queue

object TreeDotifier {
  private val logger = FluentLogger.forEnclosingClass()
  private val DEFAULT_ANTLR_PARSE_TREE_LABEL_PROVIDER: NodeLabelProvider<ParseTree> =
    object : NodeLabelProvider<ParseTree>() {
      protected override fun computeNodeLabel(node: ParseTree): String? {
        return if (node is TerminalNode) node.getText() else node.javaClass.simpleName
      }
    }
  private val DEFAULT_RUNTIME_TREE_LABEL_PROVIDER: NodeLabelProvider<AbstractSparTreeNode> =
    object : NodeLabelProvider<AbstractSparTreeNode>() {
      protected override fun computeNodeLabel(node: AbstractSparTreeNode): String {
        return (node as? LexerRuleSparTreeNode)?.asLexerRule()?.token?.text
          ?: when (node) {
            is ParserRuleSparTreeNode -> {
              when (node.ruleType) {
                RuleType.KLEENE_PLUS -> "(+)"
                RuleType.KLEENE_STAR -> "(*)"
                RuleType.OPTIONAL -> "(?)"
                RuleType.ALT_BLOCKS -> "(|)" + node.antlrRule!!.ruleName
                RuleType.OTHER_RULE -> {
                  assert(node.antlrRule != null)
                  node.antlrRule!!.ruleName
                }

                else -> throw AssertionError("Cannot reach here")
              }
            }

            is PlaceholderSparTreeNode -> {
              "placeholder"
            }

            else -> {
              throw RuntimeException("unreachable.")
            }
          }
      }
    }

  @JvmStatic
  fun main(args: Array<String>) {
    dotifyAntlrParseTree(
      Paths.get("test-programs/t6.c"),
      Paths.get("temp.pdf"),
    )
  }

  fun dotifyAntlrParseTree(sourceFile: Path, pdfFile: Path) {
    try {
      val factory = builderWithBuiltinLanguages().build()
      val source = SourceFile(
        sourceFile,
        factory.computeLanguageKindWithFileName(sourceFile)!!,
      )
      val (tree) = factory.getParserFacadeListForOrNull(source.dataKind)!!
        .defaultParserFacade.create().parseFile(sourceFile)
      convertTreeToDotGraph(tree)
        .dotify(pdfFile, DEFAULT_ANTLR_PARSE_TREE_LABEL_PROVIDER)
    } catch (e: Exception) {
      throw RuntimeException(e)
    }
  }

  @JvmStatic
  @JvmOverloads
  fun dotifyAntlrParseTree(
    root: ParseTree,
    pdfFile: Path,
    labelProvider: NodeLabelProvider<ParseTree> = DEFAULT_ANTLR_PARSE_TREE_LABEL_PROVIDER,
  ) {
    try {
      convertTreeToDotGraph(root).dotify(pdfFile, labelProvider)
    } catch (e: Exception) {
      throw RuntimeException(e)
    }
  }

  fun dotifyRuntimeMutableTree(root: AbstractSparTreeNode, pdfFile: Path) {
    val dotGraph = convertTreeToDotGraph(root)
    try {
      dotGraph.dotify(pdfFile, DEFAULT_RUNTIME_TREE_LABEL_PROVIDER)
      logger.ktInfo { "save dot graph to pdfFile" }
    } catch (e: IOException) {
      throw RuntimeException(e)
    }
  }

  fun convertTreeToDotGraph(root: AbstractSparTreeNode): DotGraph<AbstractSparTreeNode> {
    val graph = DotGraph<AbstractSparTreeNode>()
    val queue: Queue<AbstractSparTreeNode> = LinkedList()
    queue.add(root)
    while (queue.size > 0) {
      val node = queue.remove()
      val childCount = node.childCount
      for (i in 0 until childCount) {
        val child = node.getChild(i)
        graph.addEdge(node, child)
        queue.add(child)
      }
    }
    return graph
  }

  fun convertTreeToDotGraph(root: ParseTree): DotGraph<ParseTree> {
    val graph = DotGraph<ParseTree>()
    val queue: Queue<ParseTree> = LinkedList()
    queue.add(root)
    while (queue.size > 0) {
      val node = queue.remove()
      val childCount = node.childCount
      for (i in 0 until childCount) {
        val child = node.getChild(i)
        graph.addEdge(node, child)
        queue.add(child)
      }
    }
    return graph
  }
}

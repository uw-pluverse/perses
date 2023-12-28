/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr

import com.google.common.base.Joiner
import com.google.common.base.Splitter
import com.google.common.collect.Comparators
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.jgrapht.Graph
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.RuleNameRegistry
import org.perses.antlr.pnf.RuleTransitionGraph
import org.perses.util.toImmutableList
import java.nio.charset.StandardCharsets
import java.nio.file.Path
import java.nio.file.Paths
import java.util.ArrayList
import java.util.Comparator
import java.util.stream.Collectors
import kotlin.io.path.readText

object GrammarTestingUtility {
  @JvmStatic
  fun loadGrammarFromString(antlrGrammarContent: String): PersesGrammar {
    return PersesAstBuilder(
      AntlrGrammarParser.parseRawGrammarASTFromString(antlrGrammarContent),
    ).grammar
  }

  @JvmStatic
  fun loadGrammarFromFile(filenameInTestDataAntlrGrammarFolder: String): PersesGrammar {
    return PersesAstBuilder(
      AntlrGrammarParser.parseRawGrammarASTFromString(
        readAntlrFileToString(filenameInTestDataAntlrGrammarFolder),
      ),
    ).grammar
  }

  @JvmStatic
  fun loadGrammarFromFile(path: Path): PersesGrammar {
    return PersesAstBuilder(
      AntlrGrammarParser.parseRawGrammarASTFromString(path.readText()),
    ).grammar
  }

  fun checkWithGoldenGrammar(grammar: String, goldenGrammarString: String) {
    val trimmedGoldenGrammarString = deepTrim(goldenGrammarString)
    val valTrimmedGrammar = deepTrim(grammar)
    val goldenGrammar = loadGrammarFromString(trimmedGoldenGrammarString)
    val goldenTestString = deepTrim(goldenGrammar.sourceCode)
    assertThat(goldenTestString).isEqualTo(trimmedGoldenGrammarString)
    assertThat(valTrimmedGrammar).isEqualTo(goldenTestString)
  }

  private fun deepTrim(string: String): String {
    return Joiner.on('\n').join(Splitter.on('\n').trimResults().omitEmptyStrings().split(string))
  }

  @JvmStatic
  fun computeAltblockRuleName(suffix: String): String {
    return RuleType.ALT_BLOCKS.signaturePrefix + suffix
  }

  @JvmStatic
  fun readAntlrFileToString(filename: String): String {
    return Paths.get("test_data/antlr_grammars/$filename").readText(StandardCharsets.UTF_8)
  }

  @JvmStatic
  fun createPersesGrammarFromString(vararg lines: String): PersesGrammar {
    val list = ArrayList<String>()
    list.add("grammar Temp;")
    lines.forEach { list.add(it) }
    return PersesAstBuilder.loadGrammarFromString(list.joinToString("\n"))
  }

  fun createSeqOfTerminals(terminals: List<String>): PersesSequenceAst {
    return createSeqOfTerminals(*terminals.toTypedArray())
  }

  @JvmStatic
  fun createSeqOfTerminals(vararg terminals: String): PersesSequenceAst {
    val astList = createTerminalList(*terminals)
    return PersesSequenceAst(astList)
  }

  @JvmStatic
  fun createSeqOfTerminalsFromChars(terminals: String): PersesSequenceAst {
    return createSeqOfTerminals(terminals.toCharArray().map { it.toString() }.toList())
  }

  @JvmStatic
  fun createTerminal(text: String): PersesTerminalAst {
    return PersesTerminalAst(text, 0)
  }

  @JvmStatic
  fun createTerminalList(vararg terminals: String): ImmutableList<AbstractPersesRuleElement> {
    return terminals.asSequence()
      .map { createTerminal(it) }
      .toImmutableList()
  }

  @JvmStatic
  fun getSortedSccList(
    graph: RuleTransitionGraph,
  ): List<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> {
    return graph.computeSccSet().asSequence().sortedWith(GraphOrder()).toList()
  }

  fun toSortedEdges(edges: Set<AbstractPersesRuleElement>): List<String> {
    return edges.stream()
      .map { it.sourceCode }
      .sorted()
      .collect(Collectors.toList())
  }

  fun toSortedVertices(
    vertices: Set<RuleNameRegistry.RuleNameHandle>,
  ): List<RuleNameRegistry.RuleNameHandle> {
    return vertices.stream()
      .sorted(Comparator.comparingInt(RuleNameRegistry.RuleNameHandle::id))
      .collect(Collectors.toList())
  }

  class GraphOrder : Comparator<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> {
    override fun compare(
      o1: Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>,
      o2: Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>,
    ): Int {
      val v1 = toSortedVertices(o1.vertexSet())
      val v2 = toSortedVertices(o2.vertexSet())
      var result = compareVertices(v1, v2)
      if (result != 0) {
        return result
      }
      var i = 0
      val size = v1.size
      while (i < size) {
        val n1 = v1[i]
        val n2 = v2[i]
        val e1 = toSortedEdges(o1.outgoingEdgesOf(n1))
        val e2 = toSortedEdges(o2.outgoingEdgesOf(n2))
        result = Comparators.lexicographical { a: String, b: String ->
          a.compareTo(b)
        }.compare(e1, e2)
        if (result != 0) {
          return result
        }
        ++i
      }
      return 0
    }

    companion object {
      private fun compareVertices(
        v1: List<RuleNameRegistry.RuleNameHandle>,
        v2: List<RuleNameRegistry.RuleNameHandle>,
      ): Int {
        return Comparators.lexicographical(
          Comparator.comparingInt(RuleNameRegistry.RuleNameHandle::id),
        )
          .compare(v1, v2)
      }
    }
  }
}

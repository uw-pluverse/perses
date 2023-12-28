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
package org.perses.antlr.pnf

import org.jgrapht.Graph
import org.jgrapht.alg.connectivity.KosarajuStrongConnectivityInspector
import org.jgrapht.graph.DirectedMultigraph
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

class RuleTransitionGraph private constructor(
  val graph: Graph<RuleNameHandle, AbstractPersesRuleElement>,
) {

  fun computeSccSet(): List<Graph<RuleNameHandle, AbstractPersesRuleElement>> {
    // The scc set here is just a view of the graph.
    return KosarajuStrongConnectivityInspector(graph).stronglyConnectedComponents
  }

  fun duplicateGraph(
    scc: Graph<RuleNameHandle, AbstractPersesRuleElement>,
  ): DirectedMultigraph<RuleNameHandle, AbstractPersesRuleElement> {
    val subgraph = createGraph()
    val vertices = scc.vertexSet()
    for (node in vertices) {
      subgraph.addVertex(node)
    }
    val edges = scc.edgeSet()
    for (edge in edges) {
      val source = scc.getEdgeSource(edge)
      val target = scc.getEdgeTarget(edge)
      subgraph.addEdge(source, target, edge)
    }
    return subgraph
  }

  companion object {
    @JvmStatic
    fun createForLeftmostTransition(grammar: PersesGrammar): RuleTransitionGraph {
      return create(grammar) {
        it.firstChild
      }
    }

    @JvmStatic
    fun createForRightmostTransition(grammar: PersesGrammar): RuleTransitionGraph {
      return create(grammar) { it.lastChild }
    }

    private fun create(
      grammar: PersesGrammar,
      childSelector: (PersesSequenceAst) -> AbstractPersesRuleElement,
    ): RuleTransitionGraph {
      val graph = createGraph()
      grammar.parserRules.forEach {
        graph.addVertex(it.ruleNameHandle)
      }
      grammar.flattenedParserRulesSequence().forEach { (ruleName, alt) ->
        check(alt !is PersesAlternativeBlockAst) { "$ruleName : $alt" }
        addEdge(graph, ruleName, alt, alt, childSelector)
      }
      return RuleTransitionGraph(graph)
    }

    private fun createGraph(): DirectedMultigraph<RuleNameHandle, AbstractPersesRuleElement> {
      return DirectedMultigraph(AbstractPersesRuleElement::class.java)
    }

    private fun addEdge(
      graph: DirectedMultigraph<RuleNameHandle, AbstractPersesRuleElement>,
      ruleName: RuleNameHandle,
      edgeLabel: AbstractPersesRuleElement,
      ast: AbstractPersesRuleElement,
      childSelector: (PersesSequenceAst) -> AbstractPersesRuleElement,
    ) {
      when (ast.tag) {
        AstTag.ALTERNATIVE_BLOCK -> ast.childSequence().forEach { child ->
          addEdge(graph, ruleName, edgeLabel, child, childSelector)
        }
        AstTag.RULE_REF -> {
          val targetVertex = (ast as PersesRuleReferenceAst).ruleNameHandle
          if (ruleName != targetVertex) {
            graph.addEdge(ruleName, targetVertex, edgeLabel)
          }
        }
        AstTag.OPTIONAL -> {
          addEdge(graph, ruleName, edgeLabel, (ast as PersesOptionalAst).body, childSelector)
        }
        AstTag.SEQUENCE -> {
          val seq = ast as PersesSequenceAst
          addEdge(graph, ruleName, edgeLabel, childSelector(seq), childSelector)
        }
        else -> {
          /* do nothing */
        }
      }
    }
  }
}

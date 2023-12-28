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

import com.google.common.truth.Truth.assertThat
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.ast.AbstractPersesAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.pnf.RuleTransitionGraph.Companion.createForLeftmostTransition
import java.util.stream.Collectors

open class PnfLeftTestGrammar {
  @JvmField
  protected val grammar = GrammarTestingUtility.loadGrammarFromString(
    """
      grammar pnf_test;

      a
          : b c
          | d
          |
          ;

      b
          : a d
          | c d
          ;

      c
          : 'c'
          ;

      d
          : 'd'
          ;
    """.trimIndent(),
  )

  protected val graph = createForLeftmostTransition(grammar)

  @JvmField
  protected val a: RuleNameHandle

  @JvmField
  protected val b: RuleNameHandle

  @JvmField
  protected val c: RuleNameHandle

  @JvmField
  protected val d: RuleNameHandle

  @JvmField
  protected val edge_a: AbstractPersesRuleElement

  @JvmField
  protected val edge_ad: AbstractPersesRuleElement

  @JvmField
  protected val edge_cd: AbstractPersesRuleElement

  init {
    val nodes = graph.graph.vertexSet().stream()
      .sorted(Comparator.comparingInt(RuleNameHandle::id))
      .collect(Collectors.toList())
    assertThat(nodes).hasSize(4)
    a = nodes[0]
    b = nodes[1]
    c = nodes[2]
    d = nodes.get(3)

    val edgesOfA = graph.graph.outgoingEdgesOf(a).stream()
      .sorted(Comparator.comparing(AbstractPersesAst::sourceCode))
      .collect(Collectors.toList())
    assertThat(edgesOfA).hasSize(1)
    edge_a = edgesOfA.single()

    val edges = graph.graph.outgoingEdgesOf(b).stream()
      .sorted(Comparator.comparing(AbstractPersesAst::sourceCode))
      .collect(Collectors.toList())
    assertThat(edges).hasSize(2)
    edge_ad = edges.get(0)!!
    edge_cd = edges.get(1)!!
  }
}

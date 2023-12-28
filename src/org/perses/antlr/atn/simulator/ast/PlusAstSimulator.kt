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
package org.perses.antlr.atn.simulator.ast

import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.antlr.atn.AbstractDecisionMaker.EnumKleeneDecision
import org.perses.antlr.atn.tdtree.AbstractTDTreeNode
import org.perses.antlr.atn.tdtree.TDTree

class PlusAstSimulator(
  ast: PersesPlusAst,
  val bodySimulator: AbstractASTSimulator<*>,
) : AbstractASTSimulator<PersesPlusAst>(ast) {

  override fun simulate(
    decisionMaker: AbstractDecisionMaker,
    tree: TDTree,
    parent: AbstractTDTreeNode,
  ) {
    val node = tree.createPlusTDTreeNode()
    parent.addChild(node)
    var decision: EnumKleeneDecision
    do {
      bodySimulator.simulate(decisionMaker, tree, node)
      decision = decisionMaker.decideOnKleene()
      assert(decision in EnumKleeneDecision.ALL_DECISIONS)
    } while (decision == EnumKleeneDecision.TAKE)
  }
}

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

import org.perses.antlr.ast.AbstractAstVisitor
import org.perses.antlr.ast.AbstractPersesAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesFragmentLexerRuleAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesLexerCharSet
import org.perses.antlr.ast.PersesLexerCommandAst
import org.perses.antlr.ast.PersesLexerRuleAst
import org.perses.antlr.ast.PersesNotAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesRangeAst
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.PersesRuleElementOption
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.PersesTokenSetAst
import org.perses.antlr.atn.AbstractDecisionMaker
import org.perses.antlr.atn.nfa.PersesTransitionAst
import org.perses.antlr.atn.tdtree.AbstractTDTreeNode
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.util.toImmutableList

abstract class AbstractASTSimulator<T : AbstractPersesRuleElement>(val ast: T) {

  fun simulate(decisionMaker: AbstractDecisionMaker): TDTree {
    val tree = TDTree()
    simulate(decisionMaker, tree, tree.root)
    return tree
  }

  abstract fun simulate(
    decisionMaker: AbstractDecisionMaker,
    tree: TDTree,
    parent: AbstractTDTreeNode,
  )

  companion object {
    fun create(ast: AbstractPersesRuleElement): AbstractASTSimulator<*> {
      val constructor = SimulatorConstructor()
      constructor.postorder(ast)
      return constructor.map[ast]!!
    }
  }

  class SimulatorConstructor : AbstractAstVisitor() {

    internal val map = HashMap<AbstractPersesAst, AbstractASTSimulator<*>>()

    override fun visit(ast: PersesTokenSetAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesTerminalAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesSequenceAst) {
      map[ast] = SequenceASTSimulator(
        ast,
        ast.children.asSequence().map { map[it]!! }.toImmutableList(),
      )
    }

    override fun visit(ast: PersesPlusAst) {
      map[ast] = PlusAstSimulator(
        ast,
        map[ast.body]!!,
      )
    }

    override fun visit(ast: PersesStarAst) {
      map[ast] = StarAstSimulator(ast, map[ast.body]!!)
    }

    override fun visit(ast: PersesOptionalAst) {
      val child = map[ast.body]!!
      val simulator = OptionalAstSimulator(ast, child)
      map[ast] = simulator
    }

    override fun visit(ast: PersesNotAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesLexerCommandAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesLexerCharSet) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesEpsilonAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesAlternativeBlockAst) {
      map[ast] = AltBlockAstSimulator(
        ast,
        ast.alternatives.asSequence()
          .map { map[it]!! }.toImmutableList(),
      )
    }

    override fun visit(ast: PersesActionAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesRuleElementOption) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesFragmentLexerRuleAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesParserRuleAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesLexerRuleAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesRuleReferenceAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesGrammar) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesRuleElementLabel) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesRangeAst) {
      TODO("Not yet implemented")
    }

    override fun visitOthers(ast: AbstractPersesAst) {
      if (ast is PersesTransitionAst) {
        map[ast] = TransitionASTSimulator(ast)
      } else {
        super.visitOthers(ast)
      }
    }
  }
}

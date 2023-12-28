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
package org.perses.antlr.atn.nfa

import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.AtomTransition
import org.antlr.v4.runtime.atn.BasicBlockStartState
import org.antlr.v4.runtime.atn.BasicState
import org.antlr.v4.runtime.atn.BlockEndState
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.LoopEndState
import org.antlr.v4.runtime.atn.NotSetTransition
import org.antlr.v4.runtime.atn.PlusBlockStartState
import org.antlr.v4.runtime.atn.PlusLoopbackState
import org.antlr.v4.runtime.atn.RangeTransition
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.atn.StarBlockStartState
import org.antlr.v4.runtime.atn.StarLoopEntryState
import org.antlr.v4.runtime.atn.StarLoopbackState
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.atn.WildcardTransition
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
import org.perses.antlr.atn.transitionSequence

class ATNConstructorFromRegex {

  fun construct(regex: AbstractPersesRuleElement): RuleStartState {
    val constructor = ATNConstructor()
    constructor.postorder(regex)
    val bothEnds = constructor.ast2AtnEnds[regex]!!
    val ruleEnd = RuleStopState().apply {
      stateNumber = constructor.nextStateId()
    }
    val ruleStart = RuleStartState().apply {
      stateNumber = constructor.nextStateId()
      stopState = ruleEnd
    }
    val startEpsilon = EpsilonTransition(bothEnds.start)
    ruleStart.addTransition(startEpsilon)

    val endEpsilon = EpsilonTransition(ruleEnd)
    bothEnds.end.addTransition(endEpsilon)
    return ruleStart
  }

  private class ATNConstructor : AbstractAstVisitor() {

    private var _stateIdGenerator = 0

    fun nextStateId() = ++_stateIdGenerator

    val ast2AtnEnds = HashMap<AbstractPersesRuleElement, AtnEnds>()

    private fun createBasicState() = BasicState().apply {
      stateNumber = nextStateId()
    }

    override fun visit(ast: PersesTokenSetAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesTerminalAst) {
      TODO("Not yet implemented")
    }

    override fun visit(ast: PersesSequenceAst) {
      val childAtns = ast.children.asSequence()
        .map { ast2AtnEnds[it] ?: error("$it") }
        .toList()
      assert(childAtns.size > 1)
      val start = childAtns.first().start
      val end = childAtns.last().end
      childAtns.zipWithNext().forEach { (first, second) ->
        val firstEnd = first.end
        val secondStart = second.start
        assert(firstEnd.numberOfTransitions == 0)
        if (firstEnd is BasicState && secondStart is BasicState) {
          second.start
            .transitionSequence()
            .withIndex()
            .forEach { (index, secondTransition) ->
              firstEnd.addTransition(secondTransition)
              secondStart.removeTransition(index)
            }
        } else {
          val epsilon = EpsilonTransition(secondStart)
          firstEnd.addTransition(epsilon)
        }
      }
      ast2AtnEnds[ast] = AtnEnds(start, end)
      ast.children.forEach { ast2AtnEnds.remove(it) }
    }

    override fun visit(ast: PersesPlusAst) {
      val start = PlusBlockStartState().apply {
        stateNumber = nextStateId()
      }
      val end = LoopEndState().apply {
        stateNumber = nextStateId()
      }
      val blockEndState = BlockEndState().apply {
        stateNumber = nextStateId()
      }
      val loopbackState = PlusLoopbackState().apply {
        stateNumber = nextStateId()
      }

      loopbackState.addTransition(EpsilonTransition(start))
      loopbackState.addTransition(EpsilonTransition(end))
      blockEndState.addTransition(EpsilonTransition(loopbackState))

      val bodyEnds = ast2AtnEnds[ast.body]!!
      start.addTransition(EpsilonTransition(bodyEnds.start))
      bodyEnds.end.addTransition(EpsilonTransition(blockEndState))

      start.loopBackState = loopbackState
      start.endState = blockEndState

      ast2AtnEnds[ast] = AtnEnds(start, end)
    }

    override fun visit(ast: PersesStarAst) {
      // FIXME: handle greedy version.
      val entryState = StarLoopEntryState().apply {
        stateNumber = nextStateId()
        this.nonGreedy = false // FIXME: need to handle greedy version
      }
      val loopbackState = StarLoopbackState().apply {
        stateNumber = nextStateId()
      }
      entryState.loopBackState = loopbackState
      val endState = LoopEndState().apply {
        stateNumber = nextStateId()
      }
      entryState.addTransition(EpsilonTransition(endState))
      loopbackState.addTransition(EpsilonTransition(entryState))
      val blockStartState = StarBlockStartState().apply {
        stateNumber = nextStateId()
      }
      entryState.addTransition(EpsilonTransition(blockStartState))
      val blockEndState = BlockEndState().apply {
        stateNumber = nextStateId()
      }
      blockEndState.addTransition(EpsilonTransition(loopbackState))
      blockStartState.endState = blockEndState
      val bodyEnds = ast2AtnEnds[ast.body]!!
      blockStartState.addTransition(EpsilonTransition(bodyEnds.start))
      bodyEnds.end.addTransition(EpsilonTransition(blockEndState))

      ast2AtnEnds[ast] = AtnEnds(entryState, endState)
    }

    override fun visit(ast: PersesOptionalAst) {
      val start = BasicBlockStartState().apply {
        stateNumber = nextStateId()
      }
      val end = BlockEndState().apply {
        stateNumber = nextStateId()
      }
      start.endState = end
      start.addTransition(EpsilonTransition(end))
      val bodyEnds = ast2AtnEnds[ast.body]!!
      start.addTransition(EpsilonTransition(bodyEnds.start))
      bodyEnds.end.addTransition(EpsilonTransition(end))
      ast2AtnEnds[ast] = AtnEnds(start, end)
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
      val start = BasicBlockStartState().apply {
        stateNumber = nextStateId()
      }
      val end = BlockEndState().apply {
        stateNumber = nextStateId()
      }
      start.endState = end
      ast.foreachChildRuleElement {
        val childEnds = ast2AtnEnds[it]!!
        start.addTransition(EpsilonTransition(childEnds.start))
        childEnds.end.addTransition(EpsilonTransition(end))
      }
      ast2AtnEnds[ast] = AtnEnds(start, end)
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
        val start = createBasicState()
        val end = createBasicState()
        val transition = copyTransition(ast.atnTransition)
        transition.target = end
        start.addTransition(transition)

        assert(start.numberOfTransitions == 1)
        assert(start.transition(0) === transition)
        assert(transition.target === end)
        ast2AtnEnds[ast] = AtnEnds(start, end)
      } else {
        super.visitOthers(ast)
      }
    }

    private fun copyTransition(t: Transition): Transition {
      return when (t::class.java) {
        // Note that we have to use the class equality,
        // as NotSetTransition is a subclass of SetTransition
        SetTransition::class.java -> SetTransition(t.target, (t as SetTransition).set)
        NotSetTransition::class.java -> NotSetTransition(t.target, (t as NotSetTransition).set)
        AtomTransition::class.java -> AtomTransition(t.target, (t as AtomTransition).label)
        WildcardTransition::class.java -> WildcardTransition(t.target)
        RangeTransition::class.java -> RangeTransition(t.target, (t as RangeTransition).from, t.to)
        else -> error("Unhandled transition $t of ${t::class}")
      }
    }
  }

  private data class AtnEnds(val start: ATNState, val end: ATNState)
}

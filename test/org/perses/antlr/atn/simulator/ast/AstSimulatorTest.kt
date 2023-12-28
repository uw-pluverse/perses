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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.atn.NotSetTransition
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.misc.Interval
import org.antlr.v4.runtime.misc.IntervalSet
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.atn.DecisionMakerMock
import org.perses.antlr.atn.TestUtil.createAtomAst
import org.perses.antlr.atn.TestUtil.createAtomTransition
import org.perses.antlr.atn.TestUtil.createSimulatorForTransition
import org.perses.antlr.atn.TestUtil.dummyState
import org.perses.antlr.atn.nfa.PersesTransitionAst
import org.perses.antlr.atn.simulator.ast.AbstractASTSimulator.Companion.create

@RunWith(JUnit4::class)
class AstSimulatorTest {

  private val defaultRandom = DecisionMakerMock(listOf(), (0..1000).toList())

  @Test
  fun testAltSimulator() {
    val altBlock = PersesAlternativeBlockAst(
      ImmutableList.of(
        createAtomAst('A'),
        createAtomAst('B'),
        createAtomAst('C'),
      ),
    )
    val simulator = create(altBlock)
    DecisionMakerMock(listOf(), listOf(0, 1, 2)).let {
      simulator.simulate(it).toLexeme().let { lexeme ->
        assertThat(lexeme).isEqualTo("A")
      }
      simulator.simulate(it).toLexeme().let { lexeme ->
        assertThat(lexeme).isEqualTo("B")
      }
      simulator.simulate(it).toLexeme().let { lexeme ->
        assertThat(lexeme).isEqualTo("C")
      }
    }
  }

  @Test
  fun testStarSimulator() {
    val star = PersesStarAst.createGreedy(
      PersesSequenceAst(
        ImmutableList.of(
          createAtomAst('A'),
          createAtomAst('B'),
        ),
      ),
    )
    val simulator = create(star)
    DecisionMakerMock(listOf(false), listOf()).let {
      simulator.simulate(it).toLexeme()
    }.let {
      assertThat(it).isEmpty()
    }
    DecisionMakerMock(listOf(true, false), listOf()).let {
      simulator.simulate(it).toLexeme()
    }.let {
      assertThat(it).isEqualTo("AB")
    }
    DecisionMakerMock(listOf(true, true, false), listOf()).let {
      simulator.simulate(it).toLexeme()
    }.let {
      assertThat(it).isEqualTo("ABAB")
    }
  }

  @Test
  fun testPlusSimulator() {
    val plus = PersesPlusAst.createGreedy(
      PersesSequenceAst(
        ImmutableList.of(
          createAtomAst('A'),
          createAtomAst('B'),
        ),
      ),
    )
    val simulator = create(plus)
    DecisionMakerMock(listOf(false), listOf()).let {
      simulator.simulate(it).toLexeme()
    }.let {
      assertThat(it).isEqualTo("AB")
    }
    DecisionMakerMock(listOf(true, false), listOf()).let {
      simulator.simulate(it).toLexeme()
    }.let {
      assertThat(it).isEqualTo("ABAB")
    }
  }

  @Test
  fun testSequence() {
    val seq = PersesSequenceAst(
      ImmutableList.of(
        createAtomAst('A'),
        createAtomAst('B'),
      ),
    )
    val simulator = create(seq)
    val value = simulator.simulate(defaultRandom)
    assertThat(value.toLexeme()).isEqualTo("AB")
  }

  @Test
  fun testOptionalSingleChar() {
    val simulator = createSimulatorForOptionalTransition(
      createAtomTransition('A'),
    )
    val decisionMaker = DecisionMakerMock(
      listOf(true, false),
      listOf(),
    )
    val value = simulator.simulate(decisionMaker)
    assertThat(value.toLexeme()).isEqualTo("A")

    assertThat(simulator.simulate(decisionMaker).toLexeme()).isEqualTo("")
  }

  @Test
  fun testAtomTransition() {
    val simulator = createSimulatorForTransition(
      createAtomTransition('A'),
    )

    val value = simulator.simulate(defaultRandom)
    assertThat(value.toLexeme()).isEqualTo("A")
  }

  @Test
  fun testSetTransition() {
    val simulator = createSimulatorForTransition(
      SetTransition(dummyState, IntervalSet.of('A'.code, 'B'.code)),
    )

    val value = simulator.simulate(defaultRandom)
    assertThat(value.toLexeme()).isEqualTo("A")
  }

  @Test
  fun testNotSetTransition() {
    val intervalSet = IntervalSet(
      listOf(
        Interval.of(0, 'A'.code - 1),
        Interval.of('B'.code, 1000),
      ),
    )
    val simulator = createSimulatorForTransition(
      NotSetTransition(dummyState, intervalSet),
    )
    val value = simulator.simulate(defaultRandom)
    assertThat(value.toLexeme()).isEqualTo("A")
  }

  private fun createSimulatorForOptionalTransition(
    transition: Transition,
  ): AbstractASTSimulator<*> {
    val ast = PersesOptionalAst.createGreedy(
      PersesTransitionAst(transition),
    )
    return create(ast)
  }
}

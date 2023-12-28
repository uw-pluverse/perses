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
package org.perses.antlr.atn

import org.antlr.v4.runtime.atn.AtomTransition
import org.antlr.v4.runtime.atn.Transition
import org.perses.antlr.atn.nfa.ATNDummyState
import org.perses.antlr.atn.nfa.PersesTransitionAst
import org.perses.antlr.atn.simulator.ast.AbstractASTSimulator

object TestUtil {

  val dummyState = ATNDummyState(stateNumber = 1)

  fun createSimulatorForTransition(transition: Transition): AbstractASTSimulator<*> {
    val ast = PersesTransitionAst(transition)
    return AbstractASTSimulator.create(ast)
  }

  fun createAtomAst(char: Char): PersesTransitionAst {
    return PersesTransitionAst(createAtomTransition(char))
  }

  fun createAtomTransition(char: Char): AtomTransition {
    return AtomTransition(dummyState, char.code)
  }
}

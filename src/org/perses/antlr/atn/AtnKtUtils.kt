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

import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.Transition
import org.perses.util.AbstractStackOrQueue
import org.perses.util.SimpleQueue
import org.perses.util.SimpleStack

fun ATNState.transitionSequence(): Sequence<Transition> {
  return (0 until numberOfTransitions).asSequence().map { transition(it) }
}

fun dfsATN(
  startState: ATNState,
  stateVisitor: (ATNState) -> Unit,
  transitionVisitor: (sourceState: ATNState, Transition) -> Unit,
) {
  val worklist = SimpleStack<ATNState>()
  worklist.add(startState)
  traverseATN(worklist, stateVisitor, transitionVisitor)
}

fun bfsATN(
  startState: ATNState,
  stateVisitor: (ATNState) -> Unit,
  transitionVisitor: (sourceState: ATNState, Transition) -> Unit,
) {
  val worklist = SimpleQueue<ATNState>()
  worklist.add(startState)
  traverseATN(worklist, stateVisitor, transitionVisitor)
}

private fun traverseATN(
  worklist: AbstractStackOrQueue<ATNState, *>,
  stateVisitor: (ATNState) -> Unit,
  transitionVisitor: (sourceState: ATNState, Transition) -> Unit,
) {
  val visited = HashSet<ATNState>()
  while (worklist.isNotEmpty()) {
    val state = worklist.remove()
    if (!visited.add(state)) {
      continue
    }
    stateVisitor(state)
    state.transitionSequence()
      .sortedBy { it.target.stateNumber } // For deterministic traversal
      .forEach {
        transitionVisitor(state, it)
        worklist.add(it.target)
      }
  }
}

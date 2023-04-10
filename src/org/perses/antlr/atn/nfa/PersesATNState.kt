/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.antlr.v4.runtime.atn.Transition

class PersesATNState : ATNState {
  constructor(stateNumber: Int) : super() {
    this.stateNumber = stateNumber
  }

  override fun getStateType(): Int {
    return -1
  }

  @Deprecated("getTransisitons clones the transitions, which might be costly")
  override fun getTransitions(): Array<Transition> {
    return super.getTransitions()
  }

  override fun hashCode(): Int {
    return System.identityHashCode(this)
  }

  override fun equals(other: Any?): Boolean {
    return this === other
  }
}

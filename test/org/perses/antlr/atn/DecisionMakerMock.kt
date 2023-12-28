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

class DecisionMakerMock(
  private val boolSequence: List<Boolean>,
  private val intSequence: List<Int>,
) : AbstractDecisionMaker() {

  private val intIterator = intSequence.iterator()
  private val boolIterator = boolSequence.iterator()

  override fun nextBoolean(): Boolean {
    return boolIterator.next()
  }

  override fun nextInt(bound: Int): Int {
    return intIterator.next() % bound
  }

  fun copyAndStartOver(): DecisionMakerMock {
    return DecisionMakerMock(boolSequence, intSequence)
  }

  companion object {
    fun createEmpty() = DecisionMakerMock(listOf(), listOf())
  }
}

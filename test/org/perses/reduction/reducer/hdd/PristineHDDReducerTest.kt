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
package org.perses.reduction.reducer.hdd

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.spartree.SparTree
import java.util.concurrent.atomic.AtomicInteger

@RunWith(JUnit4::class)
class PristineHDDReducerTest {

  @Test
  fun test() {
//    val tree = TestUtility.createSparTreeFromFile("test_data/delta_3/t.c")
//    val origNodeCount = countNodes(tree)
//    PrestineHDDReducer.simplifySparTreeForHDD(tree)
//    val afterNodeCount = countNodes(tree)
//    Truth.assertThat(origNodeCount).isEqualTo(afterNodeCount)
  }

  private fun countNodes(tree: SparTree): Int {
    val counter = AtomicInteger(0)
    tree.root.postOrderVisit { counter.incrementAndGet() }
    return counter.get()
  }
}

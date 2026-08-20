/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.antlr

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class RuleReachabilityGraphTest {
  @Test
  fun testReachabilityGraph() {
    val hierarchy =
      GrammarHierarchy.createFromString(
        startRuleName = "a",
        content =
          """
          grammar graph;
          
          a : (b | c) + c | b a;
          b : b c | c;
          c : 'c';
          
          d : d c | c;
          e : e c | c;
          f : f b | b;
          
          g : c g | c h | c;
          h : c g | c h | c;
          """.trimIndent(),
      )
    val pathCounts = hierarchy.reachabilityGraph.numOfIncomingPathsPerNode

    val a = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
    val b = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
    val c = hierarchy.getRuleHierarchyEntryWithNameOrThrow("c")
    val d = hierarchy.getRuleHierarchyEntryWithNameOrThrow("d")
    val e = hierarchy.getRuleHierarchyEntryWithNameOrThrow("e")
    val f = hierarchy.getRuleHierarchyEntryWithNameOrThrow("f")

    assertThat(pathCounts[a]).isEqualTo(1)
    assertThat(pathCounts[b]).isEqualTo(3)
    assertThat(pathCounts[c]).isEqualTo(12)
    assertThat(pathCounts[d]).isEqualTo(1)
    assertThat(pathCounts[e]).isEqualTo(1)
    assertThat(pathCounts[f]).isEqualTo(1)
  }
}

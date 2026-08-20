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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.perses.listminimizer.AbstractListMinimizer.Companion.NoPayload
import org.perses.listminimizer.AbstractSearchSpaceNode.Companion.computeSearchSpace

class SearchSpaceTreeTest {
  private val weightProvider =
    IWeightProvider<String> { element ->
      when (element) {
        "A" -> 1
        "B" -> 2
        "C" -> 3
        else -> error("not possible")
      }
    }

  private fun createElements(vararg items: String): ImmutableList<ElementWrapper<String>> {
    val builder = ImmutableList.builder<ElementWrapper<String>>()
    items.forEachIndexed { index, item ->
      builder.add(ElementWrapper(index = index, element = item, elementPayload = NoPayload))
    }
    return builder.build()
  }

  @Test
  fun testEmptyElements() {
    val elements = ImmutableList.of<ElementWrapper<String>>()
    val root = computeSearchSpace(elements = elements)
    assertThat(root).isNull()
  }

  @Test
  fun testSingleElement() {
    val elements = createElements("A")
    val root = computeSearchSpace(elements = elements)
    assertThat(root).isNotNull()
    assertThat(root is AbstractSearchSpaceNode.Leaf).isTrue()
    root as AbstractSearchSpaceNode.Leaf
    assertThat(root.elements!!.size).isEqualTo(1)
    assertThat(root.elements!![0].element).isEqualTo("A")
  }

  @Test
  fun testTwoElements() {
    val elements = createElements("A", "B")
    val root = computeSearchSpace(elements = elements)
    assertThat(root).isNotNull()
    assertThat(root is AbstractSearchSpaceNode.Intermediate).isTrue()
    root as AbstractSearchSpaceNode.Intermediate
    assertThat(root.elements!!.size).isEqualTo(2)
    assertThat(root.childCount).isEqualTo(2)

    assertThat(root.getChild(0) is AbstractSearchSpaceNode.Leaf).isTrue()
    assertThat(root.getChild(1) is AbstractSearchSpaceNode.Leaf).isTrue()

    assertThat(
      (root.getChild(0) as AbstractSearchSpaceNode.Leaf).elementWrapper.element,
    ).isEqualTo("A")
    assertThat(
      (root.getChild(1) as AbstractSearchSpaceNode.Leaf).elementWrapper.element,
    ).isEqualTo("B")
  }

  @Test
  fun testThreeElements() {
    val elements = createElements("A", "B", "C")
    val root = computeSearchSpace(elements = elements)
    assertThat(root).isNotNull()
    assertThat(root is AbstractSearchSpaceNode.Intermediate).isTrue()
    root as AbstractSearchSpaceNode.Intermediate
    assertThat(root.elements!!.size).isEqualTo(3)
    assertThat(root.childCount).isEqualTo(2)

    // Split at index 1: left [A], right [B, C]
    assertThat(root.getChild(0) is AbstractSearchSpaceNode.Leaf).isTrue()
    assertThat(root.getChild(1) is AbstractSearchSpaceNode.Intermediate).isTrue()

    assertThat(
      (root.getChild(0) as AbstractSearchSpaceNode.Leaf).elementWrapper.element,
    ).isEqualTo("A")

    val right = root.getChild(1) as AbstractSearchSpaceNode.Intermediate
    assertThat(right.elements!!.size).isEqualTo(2)
    assertThat(right.childCount).isEqualTo(2)
    assertThat(right.getChild(0) is AbstractSearchSpaceNode.Leaf).isTrue()
    assertThat(right.getChild(1) is AbstractSearchSpaceNode.Leaf).isTrue()
    assertThat(
      (right.getChild(0) as AbstractSearchSpaceNode.Leaf).elementWrapper.element,
    ).isEqualTo("B")
    assertThat(
      (right.getChild(1) as AbstractSearchSpaceNode.Leaf).elementWrapper.element,
    ).isEqualTo("C")
  }

  @Test
  fun testUpdateExpectedGainAndElements() {
    val elements = createElements("A", "B", "C")
    val root = computeSearchSpace(elements = elements)!!

    root.updateExpectedGainAndElements(
      probabilityOfRelevance = 0.1,
      weightProvider = weightProvider,
    )

    // A: 1, (1-0.1)^1 = 0.9. gain = 1 * 0.9 = 0.9
    // B: 2, (1-0.1)^2 = 0.81. gain = 2 * 0.81 = 1.62
    // C: 3, (1-0.1)^3 = 0.729. gain = 3 * 0.729 = 2.187

    val rootIntermediate = root as AbstractSearchSpaceNode.Intermediate<String>
    val leafA = rootIntermediate.getChild(0) as AbstractSearchSpaceNode.Leaf<String>
    assertThat(leafA.weight).isEqualTo(1)
    assertThat(leafA.expectedGain).isWithin(0.0001).of(0.9)

    val intermediateBC =
      rootIntermediate.getChild(
        1,
      ) as AbstractSearchSpaceNode.Intermediate<String>
    // weight = 2 + 3 = 5
    // gain = 5 * (0.9)^5 = 5 * 0.59049 = 2.95245
    assertThat(intermediateBC.weight).isEqualTo(5)
    assertThat(intermediateBC.expectedGain).isWithin(0.0001).of(2.95245)

    val leafB = intermediateBC.getChild(0) as AbstractSearchSpaceNode.Leaf<String>
    assertThat(leafB.weight).isEqualTo(2)
    assertThat(leafB.expectedGain).isWithin(0.0001).of(1.62)

    val leafC = intermediateBC.getChild(1) as AbstractSearchSpaceNode.Leaf<String>
    assertThat(leafC.weight).isEqualTo(3)
    assertThat(leafC.expectedGain).isWithin(0.0001).of(2.187)

    // root: weight = 1 + 5 = 6
    // gain = 6 * (0.9)^6 = 6 * 0.531441 = 3.188646
    assertThat(root.weight).isEqualTo(6)
    assertThat(root.expectedGain).isWithin(0.0001).of(3.188646)
  }

  @Test
  fun testDeletionLeafNode() {
    val elements = createElements("A", "B", "C")
    val root = computeSearchSpace(elements = elements)!!

    val rootIntermediate = root as AbstractSearchSpaceNode.Intermediate<String>
    val intermediateBC =
      rootIntermediate.getChild(
        1,
      ) as AbstractSearchSpaceNode.Intermediate<String>
    val leafB = intermediateBC.getChild(0) as AbstractSearchSpaceNode.Leaf<String>

    // Delete leaf B
    intermediateBC.removeChild(leafB)
    leafB.delete()

    root.updateExpectedGainAndElements(
      probabilityOfRelevance = 0.1,
      weightProvider = weightProvider,
    )

    // A: 1, (0.9)^1 = 0.9.
    // C: 3, (0.9)^3 = 0.729.
    // weight = 1 + 3 = 4
    // gain = 4 * (0.9)^4 = 4 * 0.6561 = 2.6244
    assertThat(root.elements!!.map { it.element }).containsExactly("A", "C").inOrder()
    assertThat(intermediateBC.elements!!.map { it.element }).containsExactly("C")
  }

  @Test
  fun testDeletionIntermediateNode() {
    val elements = createElements("A", "B", "C")
    val root = computeSearchSpace(elements = elements)!!

    val rootIntermediate = root as AbstractSearchSpaceNode.Intermediate<String>
    val intermediateBC =
      rootIntermediate.getChild(
        1,
      ) as AbstractSearchSpaceNode.Intermediate<String>

    // Delete intermediate BC
    rootIntermediate.removeChild(intermediateBC)
    intermediateBC.delete()

    root.updateExpectedGainAndElements(
      probabilityOfRelevance = 0.1,
      weightProvider = weightProvider,
    )

    // A: 1, (0.9)^1 = 0.9.
    // weight = 1
    // gain = 1 * (0.9)^1 = 0.9
    assertThat(root.elements!!.map { it.element }).containsExactly("A")
  }
}

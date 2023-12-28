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
package org.perses.util

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.AbstractEditOperation.Delete
import org.perses.util.AbstractEditOperation.Insert
import org.perses.util.AbstractEditOperation.Keep
import java.lang.RuntimeException

@RunWith(JUnit4::class)
class ListAlignmentTest {

  val equalizer = { e1: Char, e2: Char -> e1 == e2 }

  @Test
  fun test_insert_at_the_beginning() {
    val alignment = create("ab", "cab")
    assertThat(alignment).containsExactly(
      Pair(null, 'c'),
      Pair('a', 'a'),
      Pair('b', 'b'),
    ).inOrder()
  }

  @Test
  fun test_insert_in_the_middle() {
    val alignment = create("ac", "abc")
    assertThat(alignment).containsExactly(
      Pair('a', 'a'),
      Pair(null, 'b'),
      Pair('c', 'c'),
    ).inOrder()
  }

  @Test
  fun test_insert_at_the_end() {
    val alignment = create("ab", "abc")
    assertThat(alignment).containsExactly(
      Pair('a', 'a'),
      Pair('b', 'b'),
      Pair(null, 'c'),
    ).inOrder()
  }

  @Test
  fun test_insert_into_empty() {
    val diff = create("", "a")
    assertThat(diff).containsExactly(
      Pair(null, 'a'),
    ).inOrder()
  }

  @Test
  fun test_delete_the_first() {
    val diff = create("ab", "b")
    assertThat(diff).containsExactly(
      Pair('a', null),
      Pair('b', 'b'),
    ).inOrder()
  }

  @Test
  fun test_delete_the_last() {
    val diff = create("ab", "a")
    assertThat(diff).containsExactly(
      Pair('a', 'a'),
      Pair('b', null),
    ).inOrder()
  }

  @Test
  fun test_delete_the_middle() {
    val diff = create("abcd", "ad")
    assertThat(diff).containsExactly(
      Pair('a', 'a'),
      Pair('b', null),
      Pair('c', null),
      Pair('d', 'd'),
    ).inOrder()
  }

  @Test
  fun test_delete_all() {
    val diff = create("ab", "")
    assertThat(diff).containsExactly(
      Pair('a', null),
      Pair('b', null),
    ).inOrder()
  }

  @Test
  fun test_change_single_char() {
    val diff = create("a", "b")
    assertThat(diff).containsExactly(
      Pair('a', null),
      Pair(null, 'b'),
    ).inOrder()
  }

  @Test
  fun test_change_head() {
    val diff = create("ab", "bb")
    assertThat(diff).containsExactly(
      Pair('a', null),
      Pair('b', 'b'),
      Pair(null, 'b'),
    ).inOrder()
  }

  @Test
  fun test_change_tail() {
    val diff = create("ab", "ac")
    assertThat(diff).containsExactly(
      Pair('a', 'a'),
      Pair('b', null),
      Pair(null, 'c'),
    ).inOrder()
  }

  @Test
  fun test_change_middle() {
    val diff = create("abc", "adec")
    assertThat(diff).containsExactly(
      Pair('a', 'a'),
      Pair('b', null),
      Pair(null, 'd'),
      Pair(null, 'e'),
      Pair('c', 'c'),
    ).inOrder()
  }

  val insertA = Insert("a")
  val insertA1 = Insert("a")
  val insertC = Insert("c")

  val deleteA = Delete("a")
  val deleteA1 = Delete("a")
  val deleteC = Delete("c")

  val keepA = Keep("a")
  val keepA1 = Keep("a")
  val keepC = Keep("c")

  @Test
  fun test_equals_insert() {
    assertThat(insertA).isEqualTo(insertA)
    assertThat(insertA).isEqualTo(insertA1)
    assertThat(insertA).isNotEqualTo(insertC)

    assertThat(insertA.hashCode()).isEqualTo(insertA1.hashCode())
    assertThat(insertA.hashCode()).isNotEqualTo(insertC.hashCode())
  }

  @Test
  fun test_equals_delete() {
    assertThat(deleteA).isEqualTo(deleteA)
    assertThat(deleteA).isEqualTo(deleteA1)
    assertThat(deleteA).isNotEqualTo(deleteC)

    assertThat(deleteA.hashCode()).isEqualTo(deleteA1.hashCode())
    assertThat(deleteA.hashCode()).isNotEqualTo(deleteC.hashCode())
  }

  @Test
  fun test_equals_keep() {
    assertThat(keepA).isEqualTo(keepA)
    assertThat(keepA).isEqualTo(keepA1)
    assertThat(keepA).isNotEqualTo(keepC)

    assertThat(keepA.hashCode()).isEqualTo(keepA1.hashCode())
    assertThat(keepA.hashCode()).isNotEqualTo(deleteC.hashCode())
  }

  @Test
  fun test_inequality_between_different_operations() {
    assertThat(keepA).isNotEqualTo(insertA)
    assertThat(keepA).isNotEqualTo(deleteA)
    assertThat(insertA).isNotEqualTo(deleteA)
  }

  @Test
  fun test_computeRevision_delete_tail() {
    val alignment = ListAlignment.create("abc".toList(), "ab".toList(), equalizer)

    test(alignment, "a", "a")
    test(alignment, "ab", "ab")
    test(alignment, "abc", "ab")
    test(alignment, "bc", "b")
    test(alignment, "c", "")
  }

  @Test
  fun test_computeRevision_delete_head() {
    val alignment = ListAlignment.create("abc".toList(), "bc".toList(), equalizer)
    test(alignment, "a", "")
    test(alignment, "ab", "b")
    test(alignment, "abc", "bc")
    test(alignment, "b", "b")
    test(alignment, "bc", "bc")
    test(alignment, "c", "c")
  }

  @Test
  fun test_computeRevision_delete_middle() {
    val alignment = ListAlignment.create("abcd".toList(), "abd".toList(), equalizer)
    test(alignment, "a", "a")
    test(alignment, "ab", "ab")
    test(alignment, "abc", "ab")
    test(alignment, "abcd", "abd")
    test(alignment, "b", "b")
    test(alignment, "bc", "b")
    test(alignment, "bcd", "bd")
    test(alignment, "c", "")
    test(alignment, "cd", "d")
    test(alignment, "d", "d")
  }

  @Test
  fun test_computeRevision_insert_head() {
    val alignment = ListAlignment.create("cd".toList(), "abcd".toList(), equalizer)
    test(alignment, "c", "abc")
    test(alignment, "d", "abd")
    test(alignment, "", "ab")
  }

  @Test
  fun test_computeRevision_insert_middle() {
    val alignment = ListAlignment.create("abd".toList(), "abcd".toList(), equalizer)

    test(alignment, "a", "ac")
    test(alignment, "ab", "abc")
    test(alignment, "abd", "abcd")
  }

  @Test
  fun test_computeRevision_insert_tail() {
    val alignment = ListAlignment.create("ab".toList(), "abcd".toList(), equalizer)

    test(alignment, "a", "acd")
    test(alignment, "ab", "abcd")
    test(alignment, "b", "bcd")
  }

  @Test
  fun test_computeRevision_replace_head() {
    val alignment = ListAlignment.create("ab".toList(), "cdb".toList(), equalizer)

    test(alignment, "", "cd")
    test(alignment, "a", "cd")
    test(alignment, "b", "cdb")
  }

  @Test
  fun test_computeRevision_replace_middle() {
    val alignment = ListAlignment.create("abc".toList(), "adc".toList(), equalizer)

    test(alignment, "", "d")
    test(alignment, "a", "ad")
    test(alignment, "ab", "ad")
    test(alignment, "abc", "adc")
    test(alignment, "c", "dc")
    test(alignment, "bc", "dc")
  }

  @Test
  fun test_computeRevision_replace_tail() {
    val alignment = ListAlignment.create("abc".toList(), "ade".toList(), equalizer)

    test(alignment, "", "de")
    test(alignment, "a", "ade")
    test(alignment, "bc", "de")
    test(alignment, "abc", "ade")
  }

  @Test
  fun test_computeRevision_throw_exception() {
    val alignment = ListAlignment.create("abcd".toList(), "abd".toList(), equalizer)

    Assert.assertThrows(RuntimeException::class.java) {
      alignment.computeRevision("e".toList())
    }
  }

  @Test
  fun testDiff() {
    val alignment = ListAlignment.create("abc".toList(), "abd".toList(), equalizer)

    assertThat(alignment.alignment.size).isEqualTo(4)
    assertThat(alignment.onlyDiffs.get(0).base).isEqualTo('c')
    assertThat(alignment.onlyDiffs.get(1).revision).isEqualTo('d')
  }

  @Test
  fun testInsert() {
    val alignment = ListAlignment.create("ab".toList(), "abc".toList(), equalizer)

    assertThat(alignment.alignment.size).isEqualTo(3)
    assertThat(alignment.onlyInserts.get(0).revision).isEqualTo('c')
  }

  @Test
  fun testDelete() {
    val alignment = ListAlignment.create("abc".toList(), "a".toList(), equalizer)

    assertThat(alignment.alignment.size).isEqualTo(3)
    assertThat(alignment.onlyDeletes.get(0).base).isEqualTo('b')
    assertThat(alignment.onlyDeletes.get(1).base).isEqualTo('c')
  }

  @Test
  fun testKeep() {
    val alignment = ListAlignment.create("abcd".toList(), "ad".toList(), equalizer)

    assertThat(alignment.alignment.size).isEqualTo(4)
    assertThat(alignment.onlyKeeps.get(0).base).isEqualTo('a')
    assertThat(alignment.onlyKeeps.get(1).base).isEqualTo('d')
  }

  @Test
  fun testMergeIntoReplace() {
    val alignment1 = ListAlignment.create("abcd".toList(), "aBcd".toList(), equalizer)
    val alignmentWithReplace1 = ListAlignment.mergeIntoReplace(alignment1)

    assertThat(alignmentWithReplace1.alignment.size).isEqualTo(4)
    assertThat(alignmentWithReplace1.onlyKeeps.size).isEqualTo(3)
    assertThat(alignmentWithReplace1.onlyDiffs.size).isEqualTo(1)
    assertThat(alignmentWithReplace1.onlyReplaces.size).isEqualTo(1)
    assertThat(alignmentWithReplace1.onlyKeeps.get(0).base).isEqualTo('a')
    assertThat(alignmentWithReplace1.onlyKeeps.get(1).base).isEqualTo('c')
    assertThat(alignmentWithReplace1.onlyKeeps.get(2).base).isEqualTo('d')
    assertThat(alignmentWithReplace1.onlyReplaces.get(0).base).isEqualTo('b')
    assertThat(alignmentWithReplace1.onlyReplaces.get(0).revision).isEqualTo('B')

    val alignment2 = ListAlignment.create("abcdefg".toList(), "abefg".toList(), equalizer)
    val alignmentWithReplace2 = ListAlignment.mergeIntoReplace(alignment2)

    assertThat(alignmentWithReplace2.alignment.size).isEqualTo(7)
    assertThat(alignmentWithReplace2.onlyKeeps.size).isEqualTo(5)
    assertThat(alignmentWithReplace2.onlyDiffs.size).isEqualTo(2)
    assertThat(alignmentWithReplace2.onlyInserts.size).isEqualTo(0)
    assertThat(alignmentWithReplace2.onlyDeletes.size).isEqualTo(2)
    assertThat(alignmentWithReplace2.onlyReplaces.size).isEqualTo(0)
    assertThat(alignmentWithReplace2.onlyKeeps.get(0).base).isEqualTo('a')
    assertThat(alignmentWithReplace2.onlyKeeps.get(1).base).isEqualTo('b')
    assertThat(alignmentWithReplace2.onlyKeeps.get(2).base).isEqualTo('e')
    assertThat(alignmentWithReplace2.onlyKeeps.get(3).base).isEqualTo('f')
    assertThat(alignmentWithReplace2.onlyKeeps.get(4).base).isEqualTo('g')
    assertThat(alignmentWithReplace2.onlyDeletes.get(0).base).isEqualTo('c')
    assertThat(alignmentWithReplace2.onlyDeletes.get(1).base).isEqualTo('d')

    val alignment3 = ListAlignment.create("abc".toList(), "abd".toList(), equalizer)
    val alignmentWithReplace3 = ListAlignment.mergeIntoReplace(alignment3)

    assertThat(alignmentWithReplace3.alignment.size).isEqualTo(4)
    assertThat(alignmentWithReplace3.onlyKeeps.size).isEqualTo(2)
    assertThat(alignmentWithReplace3.onlyDiffs.size).isEqualTo(2)
    assertThat(alignmentWithReplace3.onlyInserts.size).isEqualTo(1)
    assertThat(alignmentWithReplace3.onlyDeletes.size).isEqualTo(1)
    assertThat(alignmentWithReplace3.onlyReplaces.size).isEqualTo(0)
    assertThat(alignmentWithReplace3.onlyKeeps.get(0).base).isEqualTo('a')
    assertThat(alignmentWithReplace3.onlyKeeps.get(1).base).isEqualTo('b')
    assertThat(alignmentWithReplace3.onlyDeletes.get(0).base).isEqualTo('c')
    assertThat(alignmentWithReplace3.onlyInserts.get(0).revision).isEqualTo('d')
  }

  @Test
  fun testSplitReplace() {
    val alignment1 = ListAlignment.create("abcd".toList(), "aBcd".toList(), equalizer)
    val alignmentWithReplace1 = ListAlignment.mergeIntoReplace(alignment1)
    val alignmentWithoutReplace1 = ListAlignment.splitReplace(alignmentWithReplace1)

    assertThat(alignmentWithoutReplace1.alignment.size).isEqualTo(5)
    assertThat(alignmentWithoutReplace1.onlyKeeps.size).isEqualTo(3)
    assertThat(alignmentWithoutReplace1.onlyDiffs.size).isEqualTo(2)
    assertThat(alignmentWithoutReplace1.onlyReplaces.size).isEqualTo(0)
    assertThat(alignmentWithoutReplace1.onlyKeeps.get(0).base).isEqualTo('a')
    assertThat(alignmentWithoutReplace1.onlyKeeps.get(1).base).isEqualTo('c')
    assertThat(alignmentWithoutReplace1.onlyKeeps.get(2).base).isEqualTo('d')
    assertThat(alignmentWithoutReplace1.onlyDeletes.get(0).base).isEqualTo('b')
    assertThat(alignmentWithoutReplace1.onlyInserts.get(0).revision).isEqualTo('B')

    val alignmentManual = ListAlignment(
      ImmutableList.of(
        AbstractEditOperation.Replace('a', 'A'),
        AbstractEditOperation.Replace('b', 'B'),
        AbstractEditOperation.Replace('c', 'C'),
      ),
    )
    val alignmentManualWithoutReplace = ListAlignment.splitReplace(alignmentManual)

    assertThat(alignmentManualWithoutReplace.alignment.size).isEqualTo(6)
    assertThat(alignmentManualWithoutReplace.onlyKeeps.size).isEqualTo(0)
    assertThat(alignmentManualWithoutReplace.onlyDiffs.size).isEqualTo(6)
    assertThat(alignmentManualWithoutReplace.onlyInserts.size).isEqualTo(3)
    assertThat(alignmentManualWithoutReplace.onlyDeletes.size).isEqualTo(3)
    assertThat(alignmentManualWithoutReplace.onlyReplaces.size).isEqualTo(0)
    assertThat(alignmentManualWithoutReplace.alignment.get(0).base).isEqualTo('a')
    assertThat(alignmentManualWithoutReplace.alignment.get(1).revision).isEqualTo('A')
    assertThat(alignmentManualWithoutReplace.alignment.get(2).base).isEqualTo('b')
    assertThat(alignmentManualWithoutReplace.alignment.get(3).revision).isEqualTo('B')
    assertThat(alignmentManualWithoutReplace.alignment.get(4).base).isEqualTo('c')
    assertThat(alignmentManualWithoutReplace.alignment.get(5).revision).isEqualTo('C')
  }

  private fun createRevision(alignment: ListAlignment<Char>, newBase: String): String {
    return String(alignment.computeRevision(newBase.toList()).toTypedArray().toCharArray())
  }

  private fun create(baseList: String, revision: String): ImmutableList<Pair<Char?, Char?>> {
    return ListAlignment.create(baseList.toList(), revision.toList(), equalizer).toPairList()
  }

  private fun test(alignment: ListAlignment<Char>, newBase: String, expected: String) {
    assertThat(createRevision(alignment, newBase)).isEqualTo(expected)
  }
}

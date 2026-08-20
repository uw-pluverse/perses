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
package org.perses.reduction.reducer.trec

import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class CanonicalIdPoolTest {
  // -------------------- CanonicalIdPool --------------------

  @Test
  fun testEmptyLowerCasePoolOffersSingleFreshCandidate() {
    val pool = TokenCanonicalizer.CanonicalIdPool(baseChar = 'a')
    assertThat(pool.candidates()).containsExactly("a").inOrder()
  }

  @Test
  fun testEmptyUpperCasePoolOffersSingleFreshCandidate() {
    val pool = TokenCanonicalizer.CanonicalIdPool(baseChar = 'A')
    assertThat(pool.candidates()).containsExactly("A").inOrder()
  }

  @Test
  fun testCommittingFreshIdExtendsCandidates() {
    val pool = TokenCanonicalizer.CanonicalIdPool(baseChar = 'a')
    pool.commit("a")
    assertThat(pool.candidates()).containsExactly("a", "b").inOrder()
    pool.commit("b")
    assertThat(pool.candidates()).containsExactly("a", "b", "c").inOrder()
  }

  @Test
  fun testCommittingFreshUpperCaseIdExtendsCandidates() {
    val pool = TokenCanonicalizer.CanonicalIdPool(baseChar = 'A')
    pool.commit("A")
    pool.commit("B")
    assertThat(pool.candidates()).containsExactly("A", "B", "C").inOrder()
  }

  @Test
  fun testMergingOntoAssignedIdDoesNotConsumeFreshId() {
    val pool = TokenCanonicalizer.CanonicalIdPool(baseChar = 'a')
    pool.commit("a")
    // "a" is already assigned, "b" is the fresh candidate.
    assertThat(pool.candidates()).containsExactly("a", "b").inOrder()
    // A later identifier merges onto the already-assigned "a".
    pool.commit("a")
    // The fresh candidate "b" is still available.
    assertThat(pool.candidates()).containsExactly("a", "b").inOrder()
  }

  @Test
  fun testCommittingIdThatIsNeitherFreshNorAssignedThrows() {
    val pool = TokenCanonicalizer.CanonicalIdPool(baseChar = 'a')
    // "z" is neither the fresh candidate ("a") nor an assigned name.
    assertThrows(IllegalStateException::class.java) {
      pool.commit("z")
    }
  }

  // -------------------- CanonicalIdPoolManager --------------------

  @Test
  fun testUpperCaseLexemeUsesUpperCasePool() {
    val manager = TokenCanonicalizer.CanonicalIdPoolManager()
    assertThat(manager.getPoolFor("Foo").candidates()).containsExactly("A").inOrder()
  }

  @Test
  fun testLowerCaseLexemeUsesLowerCasePool() {
    val manager = TokenCanonicalizer.CanonicalIdPoolManager()
    assertThat(manager.getPoolFor("foo").candidates()).containsExactly("a").inOrder()
  }

  @Test
  fun testEmptyLexemeUsesLowerCasePool() {
    val manager = TokenCanonicalizer.CanonicalIdPoolManager()
    assertThat(manager.getPoolFor("").candidates()).containsExactly("a").inOrder()
  }

  @Test
  fun testSamePoolInstanceReturnedForSameCase() {
    val manager = TokenCanonicalizer.CanonicalIdPoolManager()
    assertThat(manager.getPoolFor("Foo")).isSameInstanceAs(manager.getPoolFor("Bar"))
    assertThat(manager.getPoolFor("foo")).isSameInstanceAs(manager.getPoolFor("bar"))
  }

  @Test
  fun testUpperAndLowerPoolsAreDistinct() {
    val manager = TokenCanonicalizer.CanonicalIdPoolManager()
    assertThat(manager.getPoolFor("Foo")).isNotSameInstanceAs(manager.getPoolFor("foo"))
  }

  @Test
  fun testPoolStatePersistsAcrossLookups() {
    val manager = TokenCanonicalizer.CanonicalIdPoolManager()
    manager.getPoolFor("Foo").commit("A")
    // The same uppercase pool is returned, so the assigned "A" is remembered.
    assertThat(manager.getPoolFor("Baz").candidates()).containsExactly("A", "B").inOrder()
    // The lowercase pool is untouched.
    assertThat(manager.getPoolFor("baz").candidates()).containsExactly("a").inOrder()
  }
}

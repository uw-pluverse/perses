/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFactory.isValidReducerName
import org.perses.reduction.reducer.NonSyntacticSingleTreeNodeReducer
import org.perses.reduction.reducer.PersesNodeBfsReducer
import org.perses.reduction.reducer.PersesNodeDfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedBfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.reduction.reducer.hdd.HDDReducer
import org.perses.reduction.reducer.hdd.PristineHDDReducer
import org.perses.reduction.reducer.token.ConcurrentStateBasedDeltaReducer
import org.perses.reduction.reducer.token.ConcurrentStateBasedLineSlicer
import org.perses.reduction.reducer.token.ConcurrentStateBasedTokenSlicer
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.reduction.reducer.token.DeltaDebuggingReducer
import org.perses.reduction.reducer.token.LineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.token.TokenSlicer
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class ReducerFactoryTest {
  /**
   * Note that the following is intended to be a class but not an object.
   */
  class TestReducerAnnotationAsClass :
    ReducerAnnotation(
      shortName = "test annotation that is a class but not an object",
      description = "Test reducer annotation",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
      TODO("not meant to be called.")
    }
  }

  class TestReducerAnnotationAsObject :
    ReducerAnnotation(
      shortName = "test annotation that is an object but not a class",
      description = "Test reducer annotation",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE,
    ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
      TODO("not meant to be called.")
    }
  }

  @Test
  fun testAnnotationClassCanBeLoadedWithName() {
    val annotation =
      ReducerFactory.getReducerAnnotationWithReducerClassName(
        TestReducerAnnotationAsClass::class.java.name,
      )
    assertThat(annotation).isInstanceOf(TestReducerAnnotationAsClass::class.java)
  }

  @Test
  fun testAnnotationObjectCanBeLoadedWithName() {
    val annotation =
      ReducerFactory.getReducerAnnotationWithReducerClassName(
        TestReducerAnnotationAsObject::class.java.name,
      )
    assertThat(annotation).isInstanceOf(TestReducerAnnotationAsObject::class.java)
  }

  @Test
  fun testGetAnnotationWithSimpleName() {
    testGetAnnotationWithName(HDDReducer.NAME)
    testGetAnnotationWithName(PersesNodeBfsReducer.NAME)
    testGetAnnotationWithName(PersesNodeDfsReducer.NAME)
    testGetAnnotationWithName(PersesNodePrioritizedBfsReducer.NAME)
    testGetAnnotationWithName(PersesNodePrioritizedDfsReducer.NAME)
  }

  @Test
  fun testGetAnnotationWithAnnotationClassName() {
    val klass = PersesNodeBfsReducer.META::class
    val result = ReducerFactory.getReductionAlgorithm(klass.java.name)
    assertThat(result).isSameInstanceAs(PersesNodeBfsReducer.META)
  }

  @Test
  fun testAllReducerAnnotationsCanBeLoadedWithClassNames() {
    ReducerFactory.registeredReductionAlgorithms.values.forEach { alg ->
      assertWithMessage(alg::class.toString()).that(alg::class.qualifiedName).isNotNull()
    }
  }

  @Test
  fun testIsValidReducerName() {
    assertThat(isValidReducerName("dd")).isFalse()
    assertThat(isValidReducerName(HDDReducer.NAME))
      .isTrue()
  }

  @Test
  fun testGetReductionAlgorithm() {
    val hdd = ReducerFactory.getReductionAlgorithm(HDDReducer.NAME)
    assertThat(hdd).isEqualTo(HDDReducer.META)
  }

  @Test
  fun testGetAllReducerAlgorithms() {
    val names =
      ReducerFactory.registeredReductionAlgorithms.values
        .map { it.shortName }
        .toImmutableList()
    assertThat(names)
      .containsAtLeast(
        DeltaDebuggingReducer.NAME,
        HDDReducer.NAME,
        PristineHDDReducer.NAME,
        TokenSlicer.NAME,
        NonSyntacticSingleTreeNodeReducer.NAME,
        PersesNodeBfsReducer.NAME,
        PersesNodeDfsReducer.NAME,
        PersesNodePrioritizedBfsReducer.NAME,
        PersesNodePrioritizedDfsReducer.NAME,
        ConcurrentStateBasedDeltaReducer.NAME,
      )
    assertThat(names).containsAtLeastElementsIn(
      ConcurrentTokenSlicer.REDUCER_ANNOTATIONS.map { it.shortName }.toList(),
    )
    assertThat(names).containsAtLeastElementsIn(
      LineBasedConcurrentTokenSlicer.REDUCER_ANNOTATIONS.map { it.shortName }.toList(),
    )
    assertThat(names).containsAtLeastElementsIn(
      ConcurrentStateBasedTokenSlicer.REDUCER_ANNOTATIONS.map { it.shortName }.toList(),
    )
    assertThat(names).containsAtLeastElementsIn(
      ConcurrentStateBasedLineSlicer.REDUCER_ANNOTATIONS.map { it.shortName }.toList(),
    )
  }

  companion object {
    private fun testGetAnnotationWithName(name: String) {
      val annotation = ReducerFactory.registeredReductionAlgorithms[name]!!
      assertThat(annotation.shortName).isEqualTo(name)
    }
  }
}

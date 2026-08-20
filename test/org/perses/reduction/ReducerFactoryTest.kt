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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.reducer.NonSyntacticSingleTreeNodeReducer
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.reduction.reducer.hdd.HDDReducerAnnotations
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
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> {
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
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> {
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
    testGetAnnotationWithName(HDDReducerAnnotations.Hdd.shortName)
    testGetAnnotationWithName(PersesNodeReducerAnnotations.Bfs.shortName)
    testGetAnnotationWithName(PersesNodeReducerAnnotations.Dfs.shortName)
    testGetAnnotationWithName(PersesNodeReducerAnnotations.PrioritizedBfs.shortName)
    testGetAnnotationWithName(PersesNodeReducerAnnotations.PrioritizedDfs.shortName)
  }

  @Test
  fun testGetAnnotationWithAnnotationClassName() {
    val klass = PersesNodeReducerAnnotations.Bfs::class
    val result = ReducerFactory.DEFAULT.getReductionAlgorithm(klass.java.name)
    assertThat(result).isSameInstanceAs(PersesNodeReducerAnnotations.Bfs)
  }

  @Test
  fun testAllReducerAnnotationsCanBeLoadedWithClassNames() {
    ReducerFactory.DEFAULT.registeredReductionAlgorithms.values.forEach { alg ->
      assertWithMessage(alg::class.toString()).that(alg::class.qualifiedName).isNotNull()
    }
  }

  @Test
  fun testIsValidReducerName() {
    assertThat(ReducerFactory.DEFAULT.isValidReducerName("dd")).isFalse()
    assertThat(ReducerFactory.DEFAULT.isValidReducerName(HDDReducerAnnotations.Hdd.shortName))
      .isTrue()
  }

  @Test
  fun testGetReductionAlgorithm() {
    val hdd = ReducerFactory.DEFAULT.getReductionAlgorithm(HDDReducerAnnotations.Hdd.shortName)
    assertThat(hdd).isEqualTo(HDDReducerAnnotations.Hdd)
  }

  @Test
  fun testGetAllReducerAlgorithms() {
    val names =
      ReducerFactory.DEFAULT.registeredReductionAlgorithms.values
        .map { it.shortName }
        .toImmutableList()
    assertThat(names)
      .containsAtLeast(
        DeltaDebuggingReducer.NAME,
        HDDReducerAnnotations.Hdd.shortName,
        PristineHDDReducer.NAME,
        TokenSlicer.NAME,
        NonSyntacticSingleTreeNodeReducer.NAME,
        PersesNodeReducerAnnotations.Bfs.shortName,
        PersesNodeReducerAnnotations.Dfs.shortName,
        PersesNodeReducerAnnotations.PrioritizedBfs.shortName,
        PersesNodeReducerAnnotations.PrioritizedDfs.shortName,
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

  @Test
  fun testCreateThrowsOnDuplicateAnnotation() {
    val duplicateBuiltin =
      object : ReducerAnnotation(
        shortName = "hdd",
        description = "Duplicate HDD",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
        override fun create(
          reducerContext: ReducerContext,
        ): ImmutableList<AbstractSparTreeReducer> {
          TODO("Not yet implemented")
        }
      }

    val exception =
      assertThrows(IllegalStateException::class.java) {
        ReducerFactory.createWithExtra(listOf(duplicateBuiltin))
      }
    assertThat(exception.message).contains("Duplicate reduction algorithm registration: hdd")
  }

  @Test
  fun testCopyWithExtra() {
    val newAnnotation =
      object : ReducerAnnotation(
        shortName = "custom_test_reducer",
        description = "Custom test reducer",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
        override fun create(
          reducerContext: ReducerContext,
        ): ImmutableList<AbstractSparTreeReducer> {
          TODO("Not yet implemented")
        }
      }
    val originalFactory = ReducerFactory.DEFAULT
    val extendedFactory = originalFactory.copyWithExtra(listOf(newAnnotation))

    assertThat(extendedFactory.isValidReducerName("custom_test_reducer")).isTrue()
    assertThat(originalFactory.isValidReducerName("custom_test_reducer")).isFalse()
  }

  companion object {
    private fun testGetAnnotationWithName(name: String) {
      val annotation = ReducerFactory.DEFAULT.registeredReductionAlgorithms[name]!!
      assertThat(annotation.shortName).isEqualTo(name)
    }
  }
}

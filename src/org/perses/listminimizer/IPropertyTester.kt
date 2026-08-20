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

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.reduction.PropertyTestResult
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import org.perses.util.isSortedAscendinglyBy
import org.perses.util.transformToImmutableList

sealed class Candidate<T : Any> {
  val deletedWrappers: ImmutableList<ElementWrapper<T>> by lazy {
    computeDeletedWrappers()
  }

  val deletedElements: ImmutableList<T> by lazy {
    deletedWrappers.transformToImmutableList { it.element }
  }

  protected abstract fun computeDeletedWrappers(): ImmutableList<ElementWrapper<T>>

  abstract val candidateWrappers: ImmutableList<ElementWrapper<T>>

  abstract fun getCandidateOrFail(): ImmutableList<T>

  abstract fun getOriginalOrNull(): ImmutableList<ElementWrapper<T>>?

  class DeletionsFromOriginal<T : Any>(
    private val original: ImmutableList<ElementWrapper<T>>,
    private val deleted_: ImmutableList<ElementWrapper<T>>,
  ) : Candidate<T>() {
    init {
      require(original.isNotEmpty()) {
        "The original is empty."
      }
      require(deleted_.isNotEmpty()) {
        "The deleted is empty."
      }
      lazyAssert {
        original.isSortedAscendinglyBy { it.index }
      }
      lazyAssert {
        deleted_.isSortedAscendinglyBy { it.index }
      }
    }

    override fun getOriginalOrNull(): ImmutableList<ElementWrapper<T>> = original

    override fun computeDeletedWrappers(): ImmutableList<ElementWrapper<T>> = deleted_

    val candidateElements: ImmutableList<T> by lazy {
      candidateWrappers.transformToImmutableList { it.element }
    }

    override val candidateWrappers: ImmutableList<ElementWrapper<T>> by lazy {
      Util.computeDifference(superList = original, subList = deleted_)
    }

    override fun getCandidateOrFail(): ImmutableList<T> = candidateElements
  }

  class SublistFromOriginal<T : Any>(
    private val original: ImmutableList<ElementWrapper<T>>,
    private val candidate_: ImmutableList<ElementWrapper<T>>,
  ) : Candidate<T>() {
    init {
      require(original.isNotEmpty()) {
        "The original is empty."
      }
      lazyAssert({ original.isSortedAscendinglyBy { it.index } }) {
        "The original list is not sorted"
      }
      lazyAssert({ candidate_.isSortedAscendinglyBy { it.index } }) {
        "The candidate list is not sorted"
      }
    }

    override fun computeDeletedWrappers(): ImmutableList<ElementWrapper<T>> =
      Util.computeDifference(
        superList = original,
        subList = candidate_,
      )

    override val candidateWrappers: ImmutableList<ElementWrapper<T>>
      get() = candidate_

    val candidate: ImmutableList<T> by lazy {
      candidate_.transformToImmutableList { it.element }
    }

    override fun getCandidateOrFail(): ImmutableList<T> = candidate

    override fun getOriginalOrNull(): ImmutableList<ElementWrapper<T>> = original
  }
}

fun interface IPropertyTester<T : Any, Payload> {
  /**
   * Submits [configuration] for testing and returns a handle whose [PropertyTestHandle.get] yields
   * the result. A synchronous tester returns the [ListMinimizerPropertyTestResult] directly (it is its own
   * handle); a concurrency-capable tester runs the test off-thread so [SpeculativeGreedyDriver] can
   * keep several in flight. Submission runs on the minimizer's single orchestration thread.
   */
  fun testProperty(configuration: Candidate<T>): PropertyTestHandle<T, Payload>
}

/** A handle to a (possibly speculative) property test that has been submitted for a candidate. */
interface PropertyTestHandle<T : Any, Payload> {
  fun get(): ListMinimizerPropertyTestResult<T, Payload>

  fun requestToCancel()
}

sealed class ListMinimizerPropertyTestResult<T : Any, Payload>(
  val staleElementsToRemove: ImmutableList<ElementWrapper<T>>,
) : PropertyTestHandle<T, Payload> {
  // A completed result is its own handle: a synchronous tester returns the result directly.
  final override fun get(): ListMinimizerPropertyTestResult<T, Payload> = this

  final override fun requestToCancel() {
  }

  abstract fun toShortString(): String

  class Skipped<T : Any, Payload>(
    private val result: String,
    staleElementsToRemove: ImmutableList<ElementWrapper<T>> = ImmutableList.of(),
  ) : ListMinimizerPropertyTestResult<T, Payload>(staleElementsToRemove) {
    override fun toShortString(): String = result

    override fun toString(): String = MoreObjects.toStringHelper(this).addValue(result).toString()
  }

  class Completed<T : Any, Payload>(
    val result: PropertyTestResult,
    val payload: Payload,
    staleElementsToRemove: ImmutableList<ElementWrapper<T>> = ImmutableList.of(),
  ) : ListMinimizerPropertyTestResult<T, Payload>(
      staleElementsToRemove,
    ) {
    override fun toShortString(): String =
      if (result.isInteresting) {
        "Interesting"
      } else {
        "Uninteresting"
      }

    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .add("interesting", result.isInteresting)
        .toString()
  }
}

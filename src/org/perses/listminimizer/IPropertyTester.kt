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

  abstract fun getCandidateOrFail(): ImmutableList<T>

  class DeletionOnly<T : Any>(
    private val deleted_: ImmutableList<ElementWrapper<T>>,
  ) : Candidate<T>() {
    init {
      require(deleted_.isNotEmpty()) {
        "There is no deletion set in $this"
      }
      lazyAssert { deleted_.isSortedAscendinglyBy { it.index } }
    }

    override fun computeDeletedWrappers(): ImmutableList<ElementWrapper<T>> = deleted_

    override fun getCandidateOrFail(): ImmutableList<T> {
      error("This configuration does not have a candidate.")
    }
  }

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

    override fun computeDeletedWrappers(): ImmutableList<ElementWrapper<T>> = deleted_

    val candidateElements: ImmutableList<T> by lazy {
      candidateWrappers.transformToImmutableList { it.element }
    }

    val candidateWrappers: ImmutableList<ElementWrapper<T>> by lazy {
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

    val candidate: ImmutableList<T> by lazy {
      candidate_.transformToImmutableList { it.element }
    }

    override fun getCandidateOrFail(): ImmutableList<T> = candidate
  }
}

fun interface IPropertyTester<T : Any, Payload> {
  fun testProperty(configuration: Candidate<T>): LMPropertyTestResult<T, Payload>
}

sealed class LMPropertyTestResult<T : Any, Payload>(
  val staleElementsToRemove: ImmutableList<ElementWrapper<T>>,
) {
  abstract fun toShortString(): String

  class Skipped<T : Any, Payload>(
    private val result: String,
    staleElementsToRemove: ImmutableList<ElementWrapper<T>> = ImmutableList.of(),
  ) : LMPropertyTestResult<T, Payload>(staleElementsToRemove) {
    override fun toShortString(): String = result

    override fun toString(): String = MoreObjects.toStringHelper(this).addValue(result).toString()
  }

  class Completed<T : Any, Payload>(
    val result: PropertyTestResult,
    val payload: Payload,
    staleElementsToRemove: ImmutableList<ElementWrapper<T>> = ImmutableList.of(),
  ) : LMPropertyTestResult<T, Payload>(
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

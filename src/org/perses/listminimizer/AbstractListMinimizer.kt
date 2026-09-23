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
import com.google.common.collect.Sets
import org.perses.reduction.CandidateOutcome
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

abstract class AbstractListMinimizer<T : Any, PropertyPayload>(
  protected val arguments: ListMinimizerArguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) {
  init {
    arguments.input.let { input ->
      require(Sets.newIdentityHashSet<T>().apply { addAll(input) }.size == input.size) {
        "The elements in input have to be distinct objects. $input"
      }
    }
  }

  protected lateinit var best: ImmutableList<ElementWrapper<T>>
    private set

  protected fun convertBestAsRawElements(): ImmutableList<T> =
    best.transformToImmutableList {
      it.element
    }

  val originalWrappedInput: ImmutableList<ElementWrapper<T>> by lazy {
    createWrappedElementList(arguments.input)
  }

  protected val cache: AbstractConfigCache<T> by lazy {
    if (enableCache) {
      RccConfigCache(originalWrappedInput)
    } else {
      NullConfigCache()
    }
  }

  private fun createWrappedElementList(
    originalInput: ImmutableList<out T>,
  ): ImmutableList<ElementWrapper<T>> =
    originalInput.withIndex().transformToImmutableList {
      createElementWrapperFor(it.index, it.value)
    }

  protected open fun createElementWrapperFor(
    index: Int,
    element: T,
  ): ElementWrapper<T> = ElementWrapper(index, element, NoPayload)

  protected fun updateBest(
    newBest: ImmutableList<ElementWrapper<T>>,
    payload: PropertyPayload,
  ) {
    val elementsDeletedElsewhere =
      newBest.any {
        arguments.isElementDeletedElsewhere(it.element)
      }
    best =
      if (elementsDeletedElsewhere) {
        val builder = ImmutableList.builder<ElementWrapper<T>>()
        for (elementWrapper in newBest) {
          if (arguments.isElementDeletedElsewhere(elementWrapper.element)) {
            elementWrapper.markAsDeleted()
          } else {
            builder.add(elementWrapper)
          }
        }
        builder.build()
      } else {
        newBest
      }
    // [best], not [newBest]: an element reported deleted elsewhere is not part of the new best, and
    // announcing it would tell a handler something the minimizer does not itself believe. ppr's
    // handler records the reported list as its best diff, and everything else here -- the size
    // passed to onPropertyTest, the config cache below -- already reads [best].
    arguments.onBestUpdate(best, payload)
    cache.refreshAndUpdateBest(best)
  }

  /**
   * Returns the handle rather than the outcome, because [AbstractCursorDrivenMinimizer] hands this
   * straight to [SpeculativeGreedyDriver] as its sequential `submit`, which submits now and reads
   * later. A caller that wants the answer immediately calls [PropertyTestHandle.get] on it.
   */
  protected fun testProperty(configuration: Candidate<T>): PropertyTestHandle<T, PropertyPayload> {
    val cacheKey = configuration.candidateWrappers
    if (cache.contains(cacheKey)) {
      return ImmediatePropertyTestHandle(CandidateOutcome.Uninteresting.NotTested("Cached"))
    }
    cache.add(cacheKey)
    return arguments.submitProperty(
      configuration,
      sizeOfCurrentMinimizationResult = best.size,
    )
  }

  /**
   * Tries deleting each block from [best] in turn, keeping every deletion that preserves the
   * property and moving on to the next block without restarting (the "full complement scan" of
   * drdd). The blocks must be contiguous in [best] when the scan starts. Returns the number of
   * blocks deleted.
   */
  protected fun deleteRemovableBlocksInOnePass(blocks: List<List<ElementWrapper<T>>>): Int {
    var countOfDeletedBlocks = 0
    for (block in blocks) {
      // [best] may have lost elements of this block to deletions elsewhere since the scan started.
      val liveBlock = block.filter { !it.deleted }.toImmutableList()
      // A block covering the whole list would only test the empty list, which reduce() owns.
      if (liveBlock.isEmpty() || liveBlock.size == best.size) {
        continue
      }
      val candidate = Candidate.DeletionsFromOriginal(original = best, deleted_ = liveBlock)
      val outcome = testProperty(candidate).get()
      if (outcome !is CandidateOutcome.Interesting) {
        continue
      }
      candidate.deletedWrappers.forEach { it.markAsDeleted() }
      updateBest(candidate.candidateWrappers, outcome.payload)
      ++countOfDeletedBlocks
    }
    return countOfDeletedBlocks
  }

  /**
   * Tries deleting each element of [best] alone, continuing past a deletion and wrapping around
   * rather than restarting from the front: the elements before a deletion must be retested anyway,
   * but once, a lap later, instead of after every deletion. A full lap of failures against an
   * unchanged best means every element has failed alone against it, i.e. [best] is 1-minimal.
   */
  protected fun ensureOneMinimal() {
    var position = 0
    var countOfConsecutiveFailures = 0
    // Deleting the last element tests the empty list, which reduce() owns.
    while (best.size > 1 && countOfConsecutiveFailures < best.size) {
      position %= best.size
      val element = best[position]
      val complement = best.filter { it != element }.toImmutableList()
      val outcome =
        testProperty(
          Candidate.SublistFromOriginal(original = best, candidate_ = complement),
        ).get()
      // A NotTested complement is skipped like a rejected one, which means the one-minimality
      // this function is named for is not actually established for that element: nothing ran to
      // establish it. Pre-existing, and left alone here because closing it changes behaviour --
      // but it is only expressible at all because the result type reaches this call site.
      if (outcome is CandidateOutcome.Interesting<PropertyPayload>) {
        updateBest(complement, outcome.payload)
        countOfConsecutiveFailures = 0
      } else {
        ++countOfConsecutiveFailures
        ++position
      }
    }
  }

  fun reduce(): ImmutableList<out T> {
    if (originalWrappedInput.isEmpty()) {
      best = originalWrappedInput
      return arguments.input
    }
    check(originalWrappedInput.isNotEmpty()) {
      "The input is empty, but the following code assumes the original input is non-empty."
    }
    try {
      arguments.startReduction(originalWrappedInput, this::class)
      best = originalWrappedInput
      // test whether the entire input can be deleted.
      if (arguments.needToTestEmpty) {
        arguments.log { "Testing the empty input." }
        val empty = ImmutableList.of<ElementWrapper<T>>()
        testProperty(
          Candidate.SublistFromOriginal(original = best, candidate_ = empty),
        ).get().let {
          if (it is CandidateOutcome.Interesting) {
            updateBest(empty, it.payload)
            return convertBestAsRawElements()
          }
        }
        if (best.size == 1) {
          arguments.log {
            "There is only one element in the input, and the empty input has been tested."
          }
          return convertBestAsRawElements()
        }
      } else {
        arguments.log { "Testing the empty input is disabled." }
      }
      if (best.isNotEmpty()) {
        reduceNonEmptyInput()
      }
      return convertBestAsRawElements()
    } finally {
      arguments.endReduction(
        minimizationResult = best,
        listMinimizerClass = this::class,
      )
    }
  }

  protected abstract fun reduceNonEmptyInput()

  companion object {
    object NoPayload {
      override fun toString(): String = this::class.simpleName!!
    }
  }
}

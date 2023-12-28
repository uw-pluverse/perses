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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.EmptyResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.ProceedResult
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.cache.AbstractCacheRetrievalResult.CacheMiss
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert

abstract class AbstractStateBasedConcurrentReducer<
  ConcurrentState : IConcurrentState<ConcurrentState>,
  Element,
  >(
  meta: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenSlicerReducer(meta, reducerContext) {

  abstract val parseCheckNeeded: Boolean

  private var state: ConcurrentState? = null

  private val numWorkers: Int
    get() = executorService.specifiedNumOfThreads

  private val activeFutures =
    LinkedHashSet<TestScriptExecResult<ConcurrentStateEditTestPayload<ConcurrentState>>>(numWorkers)

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    state = createInitialState(tree)

    // schedule concurrent transformation+test tasks until:
    // 1. an interesting variant is found
    // 2. no more valid state
    while (state != null) {
      val sequence = createInputSequence(tree)
      val best = scheduleAndFindBestOrNull(tree, sequence) ?: return
      applyTreeEdit(tree, best.payload)
      state = getStateOnSuccess(tree, best.payload!!.concurrentState)
    }
  }

  private fun scheduleAndFindBestOrNull(
    tree: SparTree,
    sequence: ImmutableList<Element>,
  ): TestScriptExecResult<ConcurrentStateEditTestPayload<ConcurrentState>>? {
    while (true) {
      if (activeFutures.size >= numWorkers) {
        // arbitrarily complete the first/the oldest future and free its resource
        activeFutures.first().getWithTimeoutWarnings()
      }

      val bestFound = peekAtActiveFuturesForBest()
      if (bestFound) {
        val best = waitForFirstInterestingTestToFinishOrNull()
        cancelAllTests()
        return best!!
      }

      activeFutures.add(
        executorService.testProgramAsync(
          ALWAYS_TRUE_PRECHECK,
          if (parseCheckNeeded) createParsabilityPostCheck() else IDENTITY_POST_CHECK,
          outputManagerCreator(state!!, tree, sequence),
        ),
      )

      state = state!!.advance()
      if (state == null) {
        val best = waitForFirstInterestingTestToFinishOrNull()
        cancelAllTests()
        return best
      }
    }
  }

  private fun waitForFirstInterestingTestToFinishOrNull(): TestScriptExecResult<
    ConcurrentStateEditTestPayload<ConcurrentState>,
    >? {
    // About Determinism:
    // activeFutures arranges futures in time ascending order
    // new future tasks are always added to the end of the deque
    // finding the first task ensures the determinism
    return activeFutures.firstOrNull {
      it.getWithTimeoutWarnings().isInteresting
    }
  }

  private fun peekAtActiveFuturesForBest(): Boolean {
    var bestFound = false
    val doneFutures = ArrayList<
      TestScriptExecResult<
        ConcurrentStateEditTestPayload<ConcurrentState>,
        >,
      >()
    activeFutures.forEach { future ->
      if (!future.isDone()) {
        return@forEach
      }
      val testResult = future.getWithTimeoutWarnings()
      notifyListenerOnTestScriptExecution(testResult, future.payload)
      if (testResult.isInteresting) {
        bestFound = true
      } else {
        doneFutures.add(future)
        cacheResultIfNotInteresting(testResult, future.payload)
      }
    }
    doneFutures.forEach {
      activeFutures.remove(it)
      it.cancelWithInterruption()
    }
    return bestFound
  }

  private fun cancelAllTests() {
    val futureIterator = activeFutures.iterator()
    while (futureIterator.hasNext()) {
      futureIterator.next().cancelWithInterruption()
      futureIterator.remove()
    }
    lazyAssert { activeFutures.isEmpty() }
  }

  private fun applyTreeEdit(
    tree: SparTree,
    statePayload: ConcurrentStateEditTestPayload<ConcurrentState>?,
  ) {
    check(statePayload != null) { "unexpected. null payload cannot apply edit" }
    tree.applyEdit(statePayload.edit)
  }

  private fun notifyListenerOnTestScriptExecution(
    testResult: PropertyTestResult,
    statePayload: ConcurrentStateEditTestPayload<ConcurrentState>?,
  ) {
    statePayload?.let {
      listenerManager.onTestScriptExecution(
        testResult,
        it.program.program,
        it.edit,
      )
    }
  }

  private fun cacheResultIfNotInteresting(
    testResult: PropertyTestResult,
    statePayload: ConcurrentStateEditTestPayload<ConcurrentState>?,
  ) {
    if (statePayload != null) {
      queryCache.addResult(statePayload.program, testResult)
    }
  }

  abstract fun createInputSequence(tree: SparTree): ImmutableList<Element>

  abstract fun createInitialState(tree: SparTree): ConcurrentState?

  abstract fun getStateOnSuccess(tree: SparTree, state: ConcurrentState): ConcurrentState?

  abstract fun computeNodeActionSet(
    state: ConcurrentState,
    sequence: ImmutableList<Element>,
  ): NodeDeletionActionSet

  private fun outputManagerCreator(
    state: ConcurrentState,
    tree: SparTree,
    inputSequence: ImmutableList<Element>,
  ) = Creator@{
    // partition
    val actionSet = computeNodeActionSet(state, inputSequence)
    // edit cache
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      return@Creator EmptyResult<ConcurrentStateEditTestPayload<ConcurrentState>>()
    }
    // transform
    val treeEdit = tree.createNodeDeletionEdit(actionSet)
    val testProgram = treeEdit.program
    val cachedResult = queryCache.getCachedResult(testProgram)
    return@Creator if (cachedResult.isHit()) {
      val testResult = cachedResult.asCacheHit().testResult
      check(testResult.isNotInteresting) { "Only failed programs can be cached." }
      listenerManager.onTestResultCacheHit(testResult, testProgram, treeEdit)
      // TODO(cnsun): need to pass a StopResult here which can carry the payload.
      EmptyResult()
    } else {
      val payload = ConcurrentStateEditTestPayload(state, treeEdit, cachedResult.asCacheMiss())
      ProceedResult(
        ioManager.createOutputManager(testProgram),
        payload,
      )
    }
  }

  private fun createParsabilityPostCheck(): (
    existingResult: PropertyTestResult,
    payload: ConcurrentStateEditTestPayload<ConcurrentState>,
  ) -> PropertyTestResult =
    { existing, payload ->
      if (existing.isNotInteresting || isProgramParsable(payload.program.program)) {
        existing
      } else {
        PropertyTestResult(
          exitCode = AbstractSlicingTask.INVALID_SYNTAX_EXIT_CODE,
          elapsedMilliseconds = -1,
        )
      }
    }

  private fun isProgramParsable(testProgram: TokenizedProgram) =
    configuration.parserFacade.isSourceCodeParsable(
      PrinterRegistry.getPrinter(ioManager.getDefaultProgramFormat())
        .print(testProgram).sourceCode,
    )

  data class ConcurrentStateEditTestPayload<state : IConcurrentState<state>>(
    val concurrentState: state,
    val edit: AbstractSparTreeEdit<*>,
    val program: CacheMiss,
  )
}

interface IConcurrentState<T> {
  /*
    advance() determines the next proper concurrent state to be scheduled.
    e.g., for tokenSlicer, it increments the sliding window index;
    for ddmin, it increments the partition index, or increment granularity and reset index to 0.

    advanceOnSuccess() determines the next concurrent state when a new min is found;
    thus, it should be called iff its corresponding variant program is interesting.
    e.g., for tokenSlicer, it set the index to the same index of the interesting state,
    such that no tokens are skipped.
    for ddmin, it updates the field, tokenSize, which is used
    to calculate when to increase the granularity.
   */
  fun advance(): T?
  fun advanceOnSuccess(newSequenceSize: Int): T?
}

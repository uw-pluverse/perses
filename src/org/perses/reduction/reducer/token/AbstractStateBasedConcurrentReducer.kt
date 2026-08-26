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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.EditTestPayload
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.TestScriptExecutorService.OutputManagerCreatorResult.Proceed
import org.perses.reduction.TestScriptExecutorService.OutputManagerCreatorResult.Skip
import org.perses.reduction.TestScriptVerdict
import org.perses.spartree.NodeActionSetCacheResult
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.lazyAssert
import org.perses.util.shell.ExitCode

abstract class AbstractStateBasedConcurrentReducer<
  ConcurrentState : IConcurrentState<ConcurrentState>,
  Element : Any,
>(
  meta: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(meta, reducerContext) {
  abstract val parseCheckNeeded: Boolean

  private var state: ConcurrentState? = null

  private val numWorkers: Int
    get() = executorService.specifiedNumOfThreads

  private val activeFutures =
    LinkedHashSet<TestScriptExecResult<ConcurrentStateEditTestPayload<ConcurrentState>>>(numWorkers)

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
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
    val doneFutures =
      ArrayList<
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
    applyEditToTree(statePayload.editTestPayload.edit, statePayload.editTestPayload.outputManager)
  }

  private fun notifyListenerOnTestScriptExecution(
    testResult: TestScriptVerdict,
    statePayload: ConcurrentStateEditTestPayload<ConcurrentState>?,
  ) {
    statePayload?.let {
      reducerContext.listenerManager.onTestScriptExecution(
        testResult,
        it.editTestPayload.edit.program,
        it.editTestPayload.edit,
        outputManager = it.editTestPayload.outputManager,
      )
    }
  }

  private fun cacheResultIfNotInteresting(
    testResult: TestScriptVerdict,
    statePayload: ConcurrentStateEditTestPayload<ConcurrentState>?,
  ) {
    if (statePayload != null) {
      val editTestPayload = statePayload.editTestPayload
      reducerContext.queryCache.recordUninteresting(
        editTestPayload.outputManager,
        reducerContext.perFileNonBlankCharacterCountsForCandidate(editTestPayload.edit.program),
        testResult,
      )
    }
  }

  abstract fun createInputSequence(tree: SparTree): ImmutableList<Element>

  abstract fun createInitialState(tree: SparTree): ConcurrentState?

  abstract fun getStateOnSuccess(
    tree: SparTree,
    state: ConcurrentState,
  ): ConcurrentState?

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
    val listenerManager = reducerContext.listenerManager
    // edit cache
    if (tree.isNodeActionSetCachedOrCacheIt(actionSet) == NodeActionSetCacheResult.HIT) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      return@Creator Skip<ConcurrentStateEditTestPayload<ConcurrentState>>()
    }
    // transform
    val treeEdit = tree.createNodeDeletionEdit(actionSet)
    val testProgram = treeEdit.program
    val outputManager = reducerContext.createOutputManager(testProgram)
    val cachedResult =
      reducerContext.queryCache.lookUp(outputManager)
    return@Creator if (cachedResult.isHit) {
      listenerManager.onTestResultCacheHit(
        testProgram,
        treeEdit,
        outputManager = outputManager,
      )
      // TODO(cnsun): let Skip carry the payload so the cache-hit result is not dropped here.
      Skip()
    } else {
      val payload =
        ConcurrentStateEditTestPayload(
          state,
          EditTestPayload(treeEdit, outputManager),
        )
      Proceed(
        outputManager,
        payload,
      )
    }
  }

  private fun createParsabilityPostCheck(): (
    existingResult: TestScriptVerdict,
    payload: ConcurrentStateEditTestPayload<ConcurrentState>,
  ) -> TestScriptVerdict =
    { existing, payload ->
      if (existing.isNotInteresting || isProgramParsable(payload.editTestPayload.edit.program)) {
        existing
      } else {
        TestScriptVerdict(
          exitCode = INVALID_SYNTAX_EXIT_CODE,
          elapsedMillis = -1,
        )
      }
    }

  private fun isProgramParsable(testProgram: TokenizedProgram) =
    reducerContext.configuration.canonicalParserFacade.isSourceCodeParsable(
      PrinterRegistry
        .getPrinter(reducerContext.getDefaultProgramFormat())
        .print(testProgram)
        .sourceCode,
    )

  data class ConcurrentStateEditTestPayload<State : IConcurrentState<State>>(
    val concurrentState: State,
    val editTestPayload: EditTestPayload,
  )

  companion object {
    val INVALID_SYNTAX_EXIT_CODE = ExitCode(99)
  }
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

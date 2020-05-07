/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import java.io.IOException
import java.util.LinkedList
import java.util.Optional
import java.util.concurrent.ExecutionException
import org.perses.program.TokenizedProgram
import org.perses.reduction.TestScriptExecutorService.FutureTestScriptExecutionTask
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.SparTree
import org.perses.tree.spar.SparTreeSimplifier

/** The base class for reducer. Both hdd and perses algorithms extend this class.  */
abstract class AbstractReducer protected constructor(
  val redcucerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext
) {
  @JvmField
  protected val configuration: ReductionConfiguration
  protected val executorService: TestScriptExecutorService
  protected val queryCache: AbstractTestScriptExecutionCache
  @JvmField
  protected val listenerManager: ReductionListenerManager
  @JvmField
  protected val nodeActionSetCache: AbstractNodeActionSetCache
  @JvmField
  protected val actionSetProfiler: AbstractActionSetProfiler

  protected fun testProgramAsynchronously(program: TokenizedProgram) =
    executorService.testProgram(program, configuration.programFormatControl)

  private class FutureExecutionResultInfo(
    val edit: AbstractSparTreeEdit,
    val program: TokenizedProgram,
    val future: FutureTestScriptExecutionTask
  ) {
    val result: TestScript.TestResult
      get() = try {
        future.get()
      } catch (e: Exception) {
        throw RuntimeException(e)
      }

    fun cancel() {
      future.cancel(true)
    }
  }

  protected fun testAllTreeEditsAndReturnTheBest(
    editList: List<AbstractSparTreeEdit>
  ): Optional<TreeEditWithItsResult> {
    if (editList.isEmpty()) {
      return Optional.empty()
    }
    val futureList = asyncApplyEditsInOrderOfProgramSizeFromLeast(editList)
    val best = analyzeResultsAndGetBest(futureList)
    assert(!best.isPresent ||
      configuration.parserFacade.isSourceCodeParsable(best.get().edit.program))
    return best.map { b: FutureExecutionResultInfo -> TreeEditWithItsResult(b.edit, b.result) }
  }

  private fun isFutureListSortedFromLeastProgramSizeToGreatest(
    futureList: ArrayList<FutureExecutionResultInfo>
  ): Boolean {
    val size = futureList.size
    if (size < 2) {
      return true
    }
    for (i in 1 until size) {
      val prev = futureList[i - 1]
      val current = futureList[i]
      if (prev.program.tokenCount() > current.program.tokenCount()) {
        return false
      }
    }
    return true
  }

  private fun analyzeResultsAndGetBest(
    futureList: ArrayList<FutureExecutionResultInfo>
  ): Optional<FutureExecutionResultInfo> {
    assert(isFutureListSortedFromLeastProgramSizeToGreatest(futureList)) { futureList }
    var best: FutureExecutionResultInfo? = null
    for (executionResultInfo in futureList) {
      if (best != null) {
// The best is already found, then it is safe to cancel all the remaining testing tasks, as
// none of these tasks will beat the current best one. Moreover, the tasks are not useful
// for future cache testing, as all future programs will be smaller than the programs
// represented by these tasks.
        val start = System.currentTimeMillis()
        executionResultInfo.cancel()
        val duration = (System.currentTimeMillis() - start).toInt()
        listenerManager.onTestScriptExecutionCancelled(
          executionResultInfo.program, executionResultInfo.edit, duration)
        continue
      }
      val testResult = executionResultInfo.result
      queryCache.addResult(executionResultInfo.program, executionResultInfo.result)
      listenerManager.onTestScriptExecution(
        testResult, executionResultInfo.program, executionResultInfo.edit)
      if (testResult.isPass) {
        best = executionResultInfo
      }
    }
    return Optional.ofNullable(best)
  }

  private fun asyncApplyEditsInOrderOfProgramSizeFromLeast(
    editList: List<AbstractSparTreeEdit>
  ): ArrayList<FutureExecutionResultInfo> {
    val futureList = ArrayList<FutureExecutionResultInfo>(editList.size)
    editList.stream()
      .sorted()
      .filter { edit: AbstractSparTreeEdit ->
        assert(!edit.isEmpty) { "Edit cannot be empty." }
        val program = edit.program
        val cachedResult = queryCache.getCachedResult(program)
        if (cachedResult.isPresent) {
          assert(!cachedResult.get().isPass) { "It should be failure all the time." }
          listenerManager.onTestResultCacheHit(cachedResult.get(), program, edit)
          return@filter false
        } else {
          return@filter true
        }
      }
      .forEach { edit: AbstractSparTreeEdit ->
        assert(!edit.isEmpty) { "Edit cannot be empty." }
        val program = edit.program
        val future = testProgramAsynchronously(program)
        futureList.add(FutureExecutionResultInfo(edit, program, future))
      }
    return futureList
  }

  @Throws(IOException::class, ExecutionException::class, InterruptedException::class)
  fun reduce(state: ReductionState) {
    val tree = state.sparTree
    assert(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.root))
    internalReduce(tree)
  }

  @Throws(IOException::class, ExecutionException::class, InterruptedException::class)
  protected abstract fun internalReduce(tree: SparTree)

  companion object {
    private fun removePermanentlyDeletedNodes(partition: LinkedList<AbstractSparTreeNode>) {
      val iter = partition.iterator()
      while (iter.hasNext()) {
        val node = iter.next()
        if (node.isPermanentlyDeleted) {
          iter.remove()
        }
      }
    }
  }

  init {
    configuration = reducerContext.configuration
    executorService = reducerContext.executorService
    queryCache = reducerContext.queryCache
    listenerManager = reducerContext.listenerManager
    nodeActionSetCache = reducerContext.nodeActionSetCache
    actionSetProfiler = reducerContext.actionSetProfiler
  }
}

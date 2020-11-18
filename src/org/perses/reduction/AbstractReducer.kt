/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

import org.perses.antlr.RuleType
import org.perses.program.TokenizedProgram
import org.perses.reduction.TestScript.TestResult
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.SparTree
import org.perses.tree.spar.SparTreeSimplifier
import java.io.IOException
import java.util.LinkedList
import java.util.concurrent.ExecutionException

/** The base class for reducer. Both hdd and perses algorithms extend this class.  */
abstract class AbstractReducer protected constructor(
  val redcucerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext
) {
  @JvmField
  protected val configuration: ReductionConfiguration = reducerContext.configuration
  protected val executorService: TestScriptExecutorService = reducerContext.executorService
  protected val queryCache: AbstractTestScriptExecutionCache = reducerContext.queryCache

  @JvmField
  protected val listenerManager: ReductionListenerManager = reducerContext.listenerManager

  @JvmField
  protected val nodeActionSetCache: AbstractNodeActionSetCache = reducerContext.nodeActionSetCache

  @JvmField
  protected val actionSetProfiler: AbstractActionSetProfiler = reducerContext.actionSetProfiler

  protected fun testProgramAsynchronously(
    precheck: () -> TestResult,
    program: TokenizedProgram
  ) =
    executorService.testProgramAsync(
      precheck,
      program, configuration.programFormatControl
    )

  protected fun testAllTreeEditsAndReturnTheBest(
    editList: List<AbstractSparTreeEdit>
  ): TreeEditWithItsResult? {
    if (editList.isEmpty()) {
      return null
    }
    val futureList = asyncApplyEditsInOrderOfProgramSizeFromLeast(editList)
    val best = analyzeResultsAndGetBest(futureList)
    assert(
      best == null ||
        configuration.parserFacade.isSourceCodeParsable(
          best.edit.program.toCompactSourceCode()
        )
    )
    return if (best == null) {
      null
    } else {
      TreeEditWithItsResult(best.edit, best.result)
    }
  }

  private fun isFutureListSortedFromLeastProgramSizeToGreatest(
    futureList: List<FutureExecutionResultInfo>
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

  protected fun analyzeResultsAndGetBest(
    futureList: List<FutureExecutionResultInfo>
  ): FutureExecutionResultInfo? {
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
          executionResultInfo.program, executionResultInfo.edit, duration
        )
        continue
      }
      val testResult = executionResultInfo.result
      cacheTestResult(executionResultInfo.program, executionResultInfo.result)
      listenerManager.onTestScriptExecution(
        testResult, executionResultInfo.program, executionResultInfo.edit
      )
      if (testResult.isPass) {
        best = executionResultInfo
      }
    }
    return best
  }

  private fun cacheTestResult(program: TokenizedProgram, result: TestResult) {
    queryCache.addResult(program, result)
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
        val future = testProgramAsynchronously(ALWAYS_TRUE_PRECHECK, program)
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
  protected fun canBeEpsilon(nodeForTest: AbstractSparTreeNode): Boolean {
    var node: AbstractSparTreeNode? = nodeForTest
    while (node != null) {
      if (node.antlrRule.get().canRuleBeEpsilon()) {
        // If the rule of the current node can be epsilon.
        return true
      }
      val parent = node.parentInfo ?: return false
      if (parent.antlrRuleForTheChild.get().canRuleBeEpsilon()) {
        // If the EXPECTED rule of the current node can be epsilon.
        return true
      }
      val parentNode: AbstractSparTreeNode = parent.node
      val childCount = parentNode.childCount
      return if (childCount == 1) {
        // Only the current node, then check whether the parent node rule can be epsilon.
        node = parentNode
        continue
      } else if (childCount > 1) {
        val parentNodeType = parentNode.nodeType
        when (parentNodeType) {
          RuleType.KLEENE_PLUS, RuleType.KLEENE_STAR -> true
          RuleType.OPTIONAL -> throw RuntimeException(
            "Optional should have a single child. " + node.printTreeStructure()
          )
          else -> false
        }
      } else {
        throw RuntimeException("Unreachable. " + node.printTreeStructure())
      }
    }
    return false
  }

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
}

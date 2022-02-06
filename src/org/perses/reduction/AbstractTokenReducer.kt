/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.antlr.RuleType
import org.perses.delta.AbstractPropertyTestResultWithPayload
import org.perses.delta.IPropertyTest
import org.perses.delta.PristineDeltaDebugger
import org.perses.delta.PropertyTestResultWithPayload
import org.perses.delta.SkipPropertyTestResult
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.cache.AbstractCacheRetrievalResult
import org.perses.reduction.cache.AbstractProgramEncoding
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeEditListener
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeDeletionTreeEdit
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.Util
import java.util.LinkedList

/** The base class for reducer. Both hdd and perses algorithms extend this class.
 *
 * Note that a token reducer does not mean it works on token sequences. Instead,
 * it means the reducer works on token granularity.
 */
abstract class AbstractTokenReducer protected constructor(
  val redcucerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext
) : AbstractReducer<TokenizedProgram, TokenReductionIOManager>(
  reducerContext.ioManager,
  reducerContext.executorService
) {

  @JvmField
  protected val configuration = reducerContext.configuration
  protected val queryCache = reducerContext.queryCache

  @JvmField
  protected val listenerManager = reducerContext.listenerManager

  @JvmField
  protected val nodeActionSetCache = reducerContext.nodeActionSetCache

  @JvmField
  protected val actionSetProfiler = reducerContext.actionSetProfiler

  protected fun testAllTreeEditsAndReturnTheBest(
    editList: List<AbstractSparTreeEdit<*>>
  ): TreeEditWithItsResult? {
    if (editList.isEmpty()) {
      return null
    }
    val futureList = asyncApplyEditsInOrderOfProgramSizeFromLeast(editList)
    val best = analyzeResultsAndGetBest(futureList)
    assert(
      best == null ||
        configuration.parserFacade.isSourceCodeParsable(
          PrinterRegistry.getPrinter(
            ioManager.getDefaultProgramFormat()
          ).print(best.edit.program).sourceCode
        )
    )
    return best?.let { TreeEditWithItsResult(it.edit, it.result) }
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
      if (prev.program.program.tokenCount() > current.program.program.tokenCount()) {
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
          executionResultInfo.program.program, executionResultInfo.edit, duration
        )
        continue
      }
      val testResult = executionResultInfo.result
      cacheTestResultIfNotInteresting(executionResultInfo.program, executionResultInfo.result)
      listenerManager.onTestScriptExecution(
        testResult, executionResultInfo.program.program, executionResultInfo.edit
      )
      if (testResult.isInteresting) {
        best = executionResultInfo
      }
    }
    return best
  }

  private fun cacheTestResultIfNotInteresting(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult
  ) {
    if (result.isNotInteresting) {
      queryCache.addResult(program, result)
    }
  }

  private fun asyncApplyEditsInOrderOfProgramSizeFromLeast(
    editList: List<AbstractSparTreeEdit<*>>
  ): ArrayList<FutureExecutionResultInfo> {
    val futureList = ArrayList<FutureExecutionResultInfo>(editList.size)
    val visitedCacheKeys = HashSet<AbstractProgramEncoding<*>>()
    editList.asSequence().sorted().forEach { edit: AbstractSparTreeEdit<*> ->
      val outputManager = ioManager.createOutputManager(edit.program)
      val program = edit.program
      val cachedResult = queryCache.getCachedResult(program)
      if (cachedResult.hasEncoding() && !visitedCacheKeys.add(cachedResult.getEncodingOrFail())) {
        // This program has been added before.
        return@forEach
      }
      if (cachedResult.isHit()) {
        val testResult = cachedResult.asCacheHit().testResult
        assert(!testResult.isInteresting) { "It should be failure all the time." }
        listenerManager.onTestResultCacheHit(testResult, program, edit)
        return@forEach
      }
      val future = testProgramAsynchronously(
        ALWAYS_TRUE_PRECHECK,
        IDENTITY_POST_CHECK,
        outputManager
      )
      futureList.add(FutureExecutionResultInfo(edit, cachedResult.asCacheMiss(), future))
    }
    return futureList
  }

  fun reduce(state: FixpointReductionState) {
    val sparTree = state.sparTree
    assert(
      SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(
        sparTree.getTreeRegardlessOfParsability().root
      )
    )
    state.fixpointIterationStartEvent

    val loggingListener = object : AbstractSparTreeEditListener() {
      override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
        listenerManager.onBestProgramUpdated(
          state.fixpointIterationStartEvent.createBestProgramUpdatedEvent(
            currentTimeMillis = System.currentTimeMillis(),
            programSizeBefore = event.programSizeBefore,
            programSizeAfter = event.program.tokenCount()
          )
        )
      }
    }
    try {
      sparTree.getTreeRegardlessOfParsability().registerSparTreeEditListener(loggingListener)
      internalReduce(state)
    } finally {
      sparTree.getTreeRegardlessOfParsability().removeSparTreeEditListener(loggingListener)
    }
  }

  protected abstract fun internalReduce(fixpointReductionState: FixpointReductionState)

  protected fun canBeEpsilon(nodeForTest: AbstractSparTreeNode): Boolean {
    var node: AbstractSparTreeNode? = nodeForTest
    while (node != null) {
      if (node.antlrRule!!.canRuleBeEpsilon()) {
        // If the rule of the current node can be epsilon.
        return true
      }
      val parent = node.parent ?: return false
      val payload = node.payload!!
      val antlrRuleForTheChild = payload.expectedAntlrRuleType!!
      if (antlrRuleForTheChild.canRuleBeEpsilon()) {
        // If the EXPECTED rule of the current node can be epsilon.
        return true
      }
      val childCount = parent.childCount
      return if (childCount == 1) {
        // Only the current node, then check whether the parent node rule can be epsilon.
        node = parent
        continue
      } else if (childCount > 1) {
        val parentNodeType = parent.nodeType
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

  protected class Payload(
    val tree: SparTree,
    val edit: NodeDeletionTreeEdit,
    val cacheResult: AbstractCacheRetrievalResult
  )

  protected fun createPristineDeltaDebugger(
    input: ImmutableList<AbstractSparTreeNode>,
    tree: SparTree
  ): PristineDeltaDebugger<AbstractSparTreeNode, Payload> {

    val onBestUpdateHandler =
      { _: ImmutableList<AbstractSparTreeNode>, payload: Payload ->
        payload.tree.applyEdit(payload.edit)
      }

    fun createNodeDeletionActionSetReverse(
      originalInput: ImmutableList<AbstractSparTreeNode>,
      input: ImmutableList<AbstractSparTreeNode>
    ): NodeDeletionActionSet {
      val actionSetBuilder =
        NodeDeletionActionSet.Builder("delta debugger@${input.size}")
      Util.visitDifference(superList = originalInput, subList = input) {
        assert(!it.isPermanentlyDeleted)
        actionSetBuilder.deleteNode(it)
      }
      return actionSetBuilder.build()
    }

    val propertyTest = object : IPropertyTest<AbstractSparTreeNode, Payload> {

      override fun testProperty(
        currentBest: ImmutableList<AbstractSparTreeNode>,
        candidate: ImmutableList<AbstractSparTreeNode>
      ): AbstractPropertyTestResultWithPayload<Payload> {

        val actionSet = createNodeDeletionActionSetReverse(
          currentBest, candidate
        )
        val treeEdit = tree.createNodeDeletionEdit(actionSet)
        val testProgram = treeEdit.program
        val cachedResult = queryCache.getCachedResult(testProgram)
        if (cachedResult.isHit()) {
          val testResult = cachedResult.asCacheHit().testResult
          assert(testResult.isNotInteresting) { "Only failed programs can be cached." }
          listenerManager.onTestResultCacheHit(testResult, testProgram, treeEdit)
          return SkipPropertyTestResult()
        }
        val payload = Payload(tree, treeEdit, cachedResult)
        val testTask = testProgramAsynchronously(
          ALWAYS_TRUE_PRECHECK,
          IDENTITY_POST_CHECK,
          ioManager.createOutputManager(testProgram)
        )
        val executionResultInfo = FutureExecutionResultInfo(
          treeEdit,
          cachedResult.asCacheMiss(),
          testTask
        )
        // result is ignored, and will be handled by the delta debugger.
        analyzeResultsAndGetBest(listOf(executionResultInfo))
        return PropertyTestResultWithPayload(executionResultInfo.result, payload)
      }
    }
    return PristineDeltaDebugger(
      input,
      propertyTest,
      onBestUpdateHandler
    )
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

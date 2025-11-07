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
import com.google.common.flogger.FluentLogger
import com.google.common.hash.HashCode
import org.perses.antlr.RuleType
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.Candidate
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.IPropertyTester
import org.perses.listminimizer.LMPropertyTestResult
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.ListMinimizerFactory
import org.perses.listminimizer.ListMinimizerListenerAdaptor
import org.perses.listminimizer.LocalExhaustMinimizerArguments
import org.perses.listminimizer.OnBestUpdateHandler
import org.perses.listminimizer.WindowedSlicerSpecificArguments
import org.perses.program.LanguageKind
import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractTokenReducer.NodeContainerForListMinimizer.MultiNodesContainerForListMinimizer
import org.perses.reduction.AbstractTokenReducer.NodeContainerForListMinimizer.SingleNodeContainerForListMinimizer
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.EmptyResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.ProceedResult
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.cache.AbstractCacheRetrievalResult
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeDeletionTreeEdit
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.AbstractFileContent
import org.perses.util.FileNameContentPair
import org.perses.util.TimeUtil
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import org.perses.util.ktFine
import org.perses.util.transformToImmutableList
import java.lang.RuntimeException

/** The base class for reducer. Both hdd and perses algorithms extend this class.
 *
 * Note that a token reducer does not mean it works on token sequences. Instead,
 * it means the reducer works on token granularity.
 */
abstract class AbstractTokenReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  protected val reducerContext: ReducerContext,
) : AbstractReducer<TokenizedProgram, LanguageKind, TokenReductionIOManager>(
    nameAndDesc = reducerAnnotation,
    ioManager = reducerContext.ioManager,
    executorService = reducerContext.executorService,
  ) {
  private var used = false

  protected open fun computeListMinimizerType(): EnumListMinimizerType =
    reducerContext.configuration.listMinimizerConfig.defaultListMinimizerTypeForKleene

  val reducerAnnotation: ReducerAnnotation
    get() = nameAndDesc as ReducerAnnotation

  fun reduce(state: FixpointReductionState) {
    check(!used) { "A reducer is not designed to be reused." }
    used = true
    val sparTree = state.sparTree
    lazyAssert(
      test = {
        SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(
          sparTree.getTreeRegardlessOfParsability().realRoot,
        )
      },
      message = {
        "The spar tree does not satisfy the single-entry-single-exit property\n\n" +
          sparTree.getTreeRegardlessOfParsability().printTreeStructure()
      },
    )
    try {
      internalReduce(state)
    } catch (e: Exception) {
      // To print out the reducer class for better debugging information.
      throw RuntimeException("Exception in ${this::class}", e)
    } catch (oom: OutOfMemoryError) {
      oom.printStackTrace()
      reducerContext.queryCache.clearCache()
      repeat(3) { Runtime.getRuntime().gc() }
      throw RuntimeException("Exception in ${this::class}", oom)
    }
  }

  protected abstract fun internalReduce(fixpointReductionState: FixpointReductionState)

  protected fun testAllTreeEditsAndReturnTheBest(
    editList: List<AbstractSparTreeEdit<*>>,
  ): TreeEditWithItsResult? {
    if (editList.isEmpty()) {
      return null
    }
    logger.ktFine { "The edit list has ${editList.size} edits." }
    if (editList.size == 1) {
      return testOneTreeEditAndReturnTheBest(editList.single())
    }
    val futureList = asyncApplyEditsInOrderOfProgramSizeFromLeast(editList)
    val result = analyzeResultsAndGetBest(futureList)
    futureList.forEach { it.close() }
    return result
  }

  protected fun testOneTreeEditAndReturnTheBest(
    edit: AbstractSparTreeEdit<*>,
  ): TreeEditWithItsResult? {
    asyncTestOneEdit(edit, visitedCacheKeys = null).use {
      return analyzeOneTestFutureAndGetBest(it)
    }
  }

  private fun isFutureListSortedFromLeastProgramSizeToGreatest(
    futureList: List<TestScriptExecResult<EditTestPayload>>,
  ): Boolean {
    val size = futureList.size
    if (size < 2) {
      return true
    }
    var prevTokenCount = Integer.MIN_VALUE
    futureList.forEach {
      it.payload?.let { current ->
        val curTokenCount = current.program.program.tokenCount
        if (prevTokenCount > curTokenCount) {
          return false
        }
        prevTokenCount = curTokenCount
      }
    }
    return true
  }

  protected fun analyzeResultsAndGetBest(
    futureList: List<TestScriptExecResult<EditTestPayload>>,
  ): TreeEditWithItsResult? {
    lazyAssert({ isFutureListSortedFromLeastProgramSizeToGreatest(futureList) }) { futureList }
    var best: TestScriptExecResult<EditTestPayload>? = null
    val iterator = futureList.iterator()
    while (iterator.hasNext()) {
      lazyAssert { best == null }
      val future = iterator.next()
      val foundInterestingResult = analyzeOneTestFutureAndGetBest(future)
      if (foundInterestingResult != null) {
        best = future
        break
      }
    }
    if (reducerContext.configuration.fullyDeterministicMode) {
      // As the fully deterministic mode is enabled, we need to make sure all remaining tasks
      // as finished as well for determinism. The cancelllation might affect the global cache
      // and the progress file.
      while (iterator.hasNext()) {
        iterator.next().getWithTimeoutWarnings()
      }
    } else {
      while (iterator.hasNext()) {
        val future = iterator.next()
        lazyAssert { best != null }
        // The best is already found, then it is safe to cancel all the remaining testing tasks, as
        // none of these tasks will beat the current best one. Moreover, the tasks are not useful
        // for future cache testing, as all future programs will be smaller than the programs
        // represented by these tasks.
        val start = System.currentTimeMillis()
        future.cancelWithInterruption()
        val duration = (System.currentTimeMillis() - start).toInt()
        future.payload?.let { payload ->
          reducerContext.listenerManager.onTestScriptExecutionCancelled(
            payload.program.program,
            payload.edit,
            duration,
            outputCreator = ::computeFileContentListForProgram,
          )
        }
      }
    }
    return if (best != null) {
      TreeEditWithItsResult(edit = best.payload!!.edit, testResult = best.getWithTimeoutWarnings())
    } else {
      null
    }
  }

  protected fun analyzeOneTestFutureAndGetBest(
    future: TestScriptExecResult<EditTestPayload>,
  ): TreeEditWithItsResult? {
    val payload = future.payload
    if (payload != null) {
      val testResult = future.getWithTimeoutWarnings()
      cacheTestResultIfNotInteresting(payload.program, testResult)
      reducerContext.listenerManager.onTestScriptExecution(
        testResult,
        payload.program.program,
        payload.edit,
        outputCreator = ::computeFileContentListForProgram,
      )
      if (testResult.isInteresting) {
        return TreeEditWithItsResult(edit = payload.edit, testResult = testResult)
      }
    }
    return null
  }

  private fun cacheTestResultIfNotInteresting(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult,
  ) {
    if (result.isNotInteresting) {
      reducerContext.queryCache.cacheProgramAndResult(program, result)
    }
  }

  private fun asyncApplyEditsInOrderOfProgramSizeFromLeast(
    editList: List<AbstractSparTreeEdit<*>>,
  ): List<TestScriptExecResult<EditTestPayload>> {
    val visitedCacheKeys = Util.createConcurrentSet<HashCode>()
    logger.ktFine {
      "Start to sort the tree edits. ${TimeUtil.formatDateForDisplay(System.currentTimeMillis())}"
    }
    // TODO(cnsun): we should get rid of sorting. We should make sure the edits are put into the
    //              edit list in the expected order.
    val sorted = editList.sorted()
    return sorted.map { asyncTestOneEdit(it, visitedCacheKeys) }.toList()
  }

  protected fun asyncTestOneEdit(
    edit: AbstractSparTreeEdit<*>,
    visitedCacheKeys: MutableSet<HashCode>?,
  ): TestScriptExecResult<EditTestPayload> {
    return executorService.testProgramAsync(
      ALWAYS_TRUE_PRECHECK,
      IDENTITY_POST_CHECK,
    ) {
      val program = edit.program
      val outputManager = ioManager.createOutputManager(program)
      if (visitedCacheKeys != null && !visitedCacheKeys.add(outputManager.shaHashCode.digest)) {
        // This program has been added before.
        return@testProgramAsync EmptyResult()
      }
      val queryCachedResult = reducerContext.queryCache.getCachedResult(program, outputManager)
      if (queryCachedResult.isHit()) {
        reducerContext.listenerManager.onTestResultCacheHit(
          program,
          edit,
          outputCreator = ::computeFileContentListForProgram,
        )
        // TODO(cnsun): need to use StopResult here.
        return@testProgramAsync EmptyResult()
      }
      // TODO(cnsun): add the TestScriptHistory here.
      return@testProgramAsync ProceedResult(
        outputManager,
        EditTestPayload(edit, queryCachedResult.asCacheMiss()),
      )
    }
  }

  protected fun computeFileContentListForProgram(
    program: TokenizedProgram,
  ): ImmutableList<FileNameContentPair<String>> {
    val contentList =
      ioManager.outputManagerFactory
        .createManagerFor(program)
        .fileContentList
    val builder =
      ImmutableList.builderWithExpectedSize<FileNameContentPair<String>>(
        contentList.size + 1,
      )
    contentList.forEach {
      builder.add(
        FileNameContentPair(
          fileName = it.fileName.baseName,
          content = it.content,
        ),
      )
    }
    builder.add(
      FileNameContentPair(
        fileName = "<formatted tokenized program in its original format>",
        content =
          AbstractFileContent.TextFileContent(
            text =
              reducerContext.configuration.originalFormatPrinter
                .print(program)
                .sourceCode,
          ),
      ),
    )
    return builder.build()
  }

  // TODO(cnsun): might consider moving this method to AbstractSparTreeNode
  protected fun canBeEpsilon(nodeForTest: AbstractSparTreeNode): Boolean {
    require(nodeForTest.isParserRuleNode() || nodeForTest.isTokenNode())
    var node: AbstractSparTreeNode? = nodeForTest
    while (node != null) {
      check(node.antlrRule != null) { node!! }
      if (node.antlrRule!!.canRuleBeEpsilon()) {
        // If the rule of the current node can be epsilon.
        return true
      }
      val parent = node.parent
      if (parent == null || parent.isSentinelRoot()) {
        // The root node.
        return false
      }
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
        check(parent is ParserRuleSparTreeNode)
        when (parent.ruleType) {
          RuleType.KLEENE_PLUS, RuleType.KLEENE_STAR -> true
          RuleType.OPTIONAL ->
            error(
              "Optional should have a single child. " + node.printTreeStructure(),
            )

          else -> false
        }
      } else {
        error("Unreachable. " + node.printTreeStructure())
      }
    }
    return false
  }

  private fun createNodeDeletionActionSetInverse(
    originalInput: ImmutableList<AbstractSparTreeNode>,
    input: ImmutableList<AbstractSparTreeNode>,
  ): NodeDeletionActionSet {
    val actionSetBuilder =
      NodeDeletionActionSet.Builder("list minimizer@${input.size}")
    Util.visitDifference(superList = originalInput, subList = input) {
      lazyAssert { !it.isPermanentlyDeleted }
      actionSetBuilder.deleteNode(it)
    }
    return actionSetBuilder.build()
  }

  private fun <T : NodeContainerForListMinimizer> createPropertyTester(
    actionSetDescriptionPrefix: String,
    tree: SparTree,
  ) = object : IPropertyTester<T, SparTreeListMinimizerPayload> {
    override fun testProperty(
      configuration: Candidate<T>,
    ): LMPropertyTestResult<T, SparTreeListMinimizerPayload> {
      val allDeletedNodes =
        configuration.deletedElements
          .asSequence()
          .flatMap { it.asSequence() }
          .toList()
      val actionSet =
        NodeDeletionActionSet
          .Builder(
            "${actionSetDescriptionPrefix}dd@${allDeletedNodes.size}",
          ).deleteNodes(allDeletedNodes)
          .build()
      if (reducerContext.nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
        reducerContext.listenerManager.onNodeEditActionSetCacheHit(actionSet)
        return LMPropertyTestResult.Skipped(result = "Skipped")
      }
      val treeEdit = tree.createNodeDeletionEdit(actionSet)
      val result =
        testOneTreeEditAndReturnTheBest(treeEdit)
          ?: return LMPropertyTestResult.Skipped(result = "Uninteresting")
      return LMPropertyTestResult.Completed(
        result.testResult,
        SparTreeListMinimizerPayload(
          tree,
          result.edit as NodeDeletionTreeEdit,
        ),
      )
    }
  }

  protected fun createListMinimizerListenerAdaptor(
    fixpointReductionState: FixpointReductionState,
    minimizerType: EnumListMinimizerType,
  ): ListMinimizerListenerAdaptor {
    val event = fixpointReductionState.fixpointIterationStartEvent
    return ListMinimizerListenerAdaptor { message ->
      val prefix = event.prefixLabelFromRootToHere + "[$minimizerType]"
      val programSize = fixpointReductionState.sparTree.programSnapshot.tokenCount
      val initialSize = event.initialProgramSize()
      val globalPercentage = Util.computePercentage(programSize, denominator = initialSize)
      val wholeMessage = "$message Global ratio:$globalPercentage"
      reducerContext.listenerManager.onAdHocMessageEvent(
        event.createAdHocMessageEvent(
          programSize = fixpointReductionState.sparTree.programSnapshot.tokenCount,
          newPrefixLabelFromRootToHere = prefix,
          messageComputer = { wholeMessage },
        ),
      )
    }
  }

  private fun <T : NodeContainerForListMinimizer> createOnBestUpdateHandler() =
    OnBestUpdateHandler<T, SparTreeListMinimizerPayload> { _, payload ->
      payload.tree.applyEdit(payload.edit)
    }

  sealed class NodeContainerForListMinimizer {
    abstract fun asSequence(): Sequence<AbstractSparTreeNode>

    abstract val tokenCount: Int

    class SingleNodeContainerForListMinimizer(
      val node: AbstractSparTreeNode,
    ) : NodeContainerForListMinimizer() {
      override fun asSequence(): Sequence<AbstractSparTreeNode> = sequenceOf(node)

      override val tokenCount: Int
        get() = node.leafTokenCount

      override fun toString(): String = node.toString()
    }

    class MultiNodesContainerForListMinimizer(
      val nodes: ImmutableList<out AbstractSparTreeNode>,
    ) : NodeContainerForListMinimizer() {
      override fun asSequence(): Sequence<AbstractSparTreeNode> = nodes.asSequence()

      override val tokenCount: Int = nodes.sumOf { it.leafTokenCount }

      override fun toString(): String = nodes.toString()
    }
  }

  protected fun runListMinimizerOverNodes(
    tree: SparTree,
    input: ImmutableList<out AbstractSparTreeNode>,
    fixpointReductionState: FixpointReductionState,
    actionsDescriptionPostfix: String = "",
  ): ImmutableList<out AbstractSparTreeNode> =
    genericRunListMinimizer(
      tree = tree,
      input = input.transformToImmutableList { SingleNodeContainerForListMinimizer(it) },
      fixpointReductionState = fixpointReductionState,
      actionsDescriptionPostfix = actionsDescriptionPostfix,
    ).transformToImmutableList { it.node }

  protected fun runListMinimizerOverListsOfNodes(
    tree: SparTree,
    input: ImmutableList<out ImmutableList<out AbstractSparTreeNode>>,
    fixpointReductionState: FixpointReductionState,
    actionsDescriptionPostfix: String = "",
  ): ImmutableList<ImmutableList<out AbstractSparTreeNode>> =
    genericRunListMinimizer(
      tree = tree,
      input = input.transformToImmutableList { MultiNodesContainerForListMinimizer(it) },
      fixpointReductionState = fixpointReductionState,
      actionsDescriptionPostfix = actionsDescriptionPostfix,
    ).transformToImmutableList { it.nodes }

  private fun <T : NodeContainerForListMinimizer> genericRunListMinimizer(
    tree: SparTree,
    input: ImmutableList<out T>,
    fixpointReductionState: FixpointReductionState,
    actionsDescriptionPostfix: String = "",
  ): ImmutableList<out T> {
    if (input.isEmpty()) {
      return input
    }
    val minimizerType = computeListMinimizerType()
    val finalActionDescription =
      "$minimizerType in ${this::class.qualifiedName!!}" + actionsDescriptionPostfix
    val arguments =
      createListMinimizerArguments(
        needToTestEmpty = true,
        tree = tree,
        logger = createListMinimizerListenerAdaptor(fixpointReductionState, minimizerType),
        actionsDescription = finalActionDescription,
        input = input,
      )
    val listMinimizer = ListMinimizerFactory.create(minimizerType, arguments)
    return listMinimizer.reduce()
  }

  private fun <T : NodeContainerForListMinimizer> createListMinimizerArguments(
    needToTestEmpty: Boolean,
    tree: SparTree,
    logger: ListMinimizerListenerAdaptor?,
    actionsDescription: String,
    input: ImmutableList<out T>,
  ): ListMinimizerArguments<T, SparTreeListMinimizerPayload> {
    val listMinimizerConfig = reducerContext.configuration.listMinimizerConfig
    return ListMinimizerArguments<T, SparTreeListMinimizerPayload>(
      needToTestEmpty = needToTestEmpty,
      input = input,
      propertyTester = createPropertyTester(actionSetDescriptionPrefix = actionsDescription, tree),
      onBestUpdateHandler = createOnBestUpdateHandler(),
      descriptionPrefix = actionsDescription,
      weightProvider = { it.tokenCount },
      listener =
        AbstractListMinimizerListener.smartCombine(reducerContext.listMinimizerListener, logger),
      windowedSlicerSpecificArguments =
        WindowedSlicerSpecificArguments(
          minSlidingWindowSize = listMinimizerConfig.minSlidingWindowSize,
          maxSlidingWindowSize = listMinimizerConfig.maxSlidingWindowSize,
        ),
      localExhaustMinimizerArguments =
        LocalExhaustMinimizerArguments(
          windowSize =
            reducerContext
              .configuration
              .vulcanConfig
              .windowSizeForLocalExhaustivePatternReduction,
        ),
    )
  }

  companion object {
    @JvmStatic
    protected val logger = FluentLogger.forEnclosingClass()
  }
}

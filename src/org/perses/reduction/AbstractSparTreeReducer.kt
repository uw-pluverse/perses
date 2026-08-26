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
import com.google.common.flogger.FluentLogger
import com.google.common.hash.HashCode
import org.apache.commons.text.StringEscapeUtils
import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.AdaptiveGainDrivenMinimizerArguments
import org.perses.listminimizer.Candidate
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.IPropertyTester
import org.perses.listminimizer.ImmediatePropertyTestHandle
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.ListMinimizerFactory
import org.perses.listminimizer.ListMinimizerListenerAdaptor
import org.perses.listminimizer.LocalExhaustMinimizerArguments
import org.perses.listminimizer.OnBestUpdateHandler
import org.perses.listminimizer.PropertyTestHandle
import org.perses.listminimizer.WindowedSlicerSpecificArguments
import org.perses.listminimizer.microbenchmark.RecordingContext
import org.perses.program.TokenizedProgram
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.TestScriptExecutorService.OutputManagerCreatorResult.Proceed
import org.perses.reduction.TestScriptExecutorService.OutputManagerCreatorResult.Skip
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ContextDescription
import org.perses.spartree.DescendantHoistingTreeEdit
import org.perses.spartree.EmptySparTreeEdit
import org.perses.spartree.LatraGeneralActionSet
import org.perses.spartree.LatraGeneralTreeEdit
import org.perses.spartree.NodeActionSetCacheResult
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeDeletionTreeEdit
import org.perses.spartree.NodeReplacementActionSet
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.AbstractFileContent
import org.perses.util.CollectionUtil
import org.perses.util.FileNameContentPair
import org.perses.util.FileNameContentPairList
import org.perses.util.StringUtil
import org.perses.util.TimeUtil
import org.perses.util.ktFine
import org.perses.util.lazyAssert
import org.perses.util.transformToImmutableList
import java.lang.RuntimeException
import java.util.HashSet

/**
 * The base class for reducers that reduce by editing a [SparTree] in place: the reducer proposes
 * candidate tree edits ([AbstractSparTreeEdit]) -- node deletions/replacements, list minimization,
 * literal replacement -- the framework tests them, and the best property-preserving edit is applied
 * to the tree. The hdd and perses node reducers, the concurrent token/line slicers, and delta
 * debugging all extend this.
 *
 * Contrast [AbstractWholeProgramReducer], whose reducers test whole candidate programs instead of
 * tree edits.
 */
abstract class AbstractSparTreeReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  protected val reducerContext: ReducerContext,
) : AbstractReducer<TokenizedProgram, TokenReductionIOManager>(
    nameAndDesc = reducerAnnotation,
    ioManager = reducerContext.ioManager,
    executorService = reducerContext.executorService,
  ) {
  private var used = false

  protected val persesConfig = reducerContext.configuration.persesConfig

  protected open fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    persesConfig.listMinimizerTypeForKleene

  /**
   * The window range for the windowed slicer, or null to use the configured default. Only consulted
   * when the minimizer is [EnumListMinimizerType.WINDOWED_SLICER]; a reducer that slices at a fixed
   * window size (e.g. a per-granularity slicer) overrides this.
   */
  protected open fun computeWindowedSlicerArguments(): WindowedSlicerSpecificArguments? = null

  val reducerAnnotation: ReducerAnnotation
    get() = nameAndDesc as ReducerAnnotation

  /**
   * The (surrogate) parser facade this reducer prefers to operate on, or null to use the canonical
   * facade. The driver only rebuilds the spar-tree when the preferred facade differs (by type) from
   * the current one, so a reducer can simply return its preferred facade unconditionally.
   */
  open fun getPreferredParserFacade(): AbstractParserFacade? = null

  fun reduce(state: FixpointReductionState) {
    check(!used) { "A reducer is not designed to be reused." }
    used = true
    val inputRepresentation = state.inputRepresentation
    lazyAssert(
      test = {
        SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(
          inputRepresentation.tree.realRoot,
        )
      },
      message = {
        "The spar tree does not satisfy the single-entry-single-exit property\n\n" +
          inputRepresentation.tree.printTreeStructure()
      },
    )
    try {
      internalReduce(state)
    } catch (e: Exception) {
      // To print out the reducer class for better debugging information.
      throw RuntimeException("Exception ${e::class.simpleName} in ${this::class}", e)
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
  ): EditTestPayload? {
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

  protected fun testOneTreeEditAndGetOutcome(
    edit: AbstractSparTreeEdit<*>,
  ): CandidateOutcome<EditTestPayload> {
    asyncTestOneEdit(edit, visitedCacheKeys = null).use { future ->
      return analyzeOneTestFuture(future)
    }
  }

  protected fun testOneTreeEditAndReturnTheBest(edit: AbstractSparTreeEdit<*>): EditTestPayload? {
    asyncTestOneEdit(edit, visitedCacheKeys = null).use { future ->
      return analyzeOneTestFutureAndGetBest(future)
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
        val curTokenCount = current.edit.program.tokenCount
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
  ): EditTestPayload? {
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
            payload.edit.program,
            payload.edit,
            duration,
          )
        }
      }
    }
    return best?.payload
  }

  /**
   * What became of one submitted edit. [analyzeOneTestFutureAndGetBest] collapses both uninteresting
   * cases to null, which discards the one fact a cost model needs: whether a script ran at all.
   *
   * A null `future.payload` is not "no edit could be built". The executor returns
   * [TestScriptExecutorService.OutputManagerCreatorResult] `Skip` when the query cache already holds
   * the verdict or the program repeats one already submitted in this batch, and a cancelled test
   * resolves the same way -- so it means no script ran, and "Uninteresting" is the label that case
   * has always printed.
   */
  protected fun analyzeOneTestFuture(
    future: TestScriptExecResult<EditTestPayload>,
  ): CandidateOutcome<EditTestPayload> {
    val payload =
      future.payload ?: return CandidateOutcome.Uninteresting.NotTested("Uninteresting")

    val testResult = future.getWithTimeoutWarnings()
    cacheTestResultIfNotInteresting(payload, testResult)
    reducerContext.listenerManager.onTestScriptExecution(
      testResult,
      payload.edit.program,
      payload.edit,
      outputManager = payload.outputManager,
    )
    return if (testResult.isInteresting) {
      CandidateOutcome.Interesting(payload = payload, testScriptVerdict = testResult)
    } else {
      CandidateOutcome.Uninteresting.Rejected(testResult)
    }
  }

  protected fun analyzeOneTestFutureAndGetBest(
    future: TestScriptExecResult<EditTestPayload>,
  ): EditTestPayload? = (analyzeOneTestFuture(future) as? CandidateOutcome.Interesting)?.payload

  private fun cacheTestResultIfNotInteresting(
    payload: EditTestPayload,
    result: TestScriptVerdict,
  ) {
    if (result.isNotInteresting) {
      reducerContext.queryCache.recordUninteresting(
        payload.outputManager,
        reducerContext.perFileNonBlankCharacterCountsForCandidate(payload.edit.program),
        result,
      )
    }
  }

  private fun asyncApplyEditsInOrderOfProgramSizeFromLeast(
    editList: List<AbstractSparTreeEdit<*>>,
  ): List<TestScriptExecResult<EditTestPayload>> {
    val visitedCacheKeys = CollectionUtil.createConcurrentSet<HashCode>()
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
      preCheck = ALWAYS_TRUE_PRECHECK,
      postCheck = IDENTITY_POST_CHECK,
      outputManagerCreator = {
        val program = edit.program
        val outputManager = reducerContext.createOutputManager(program)
        if (visitedCacheKeys != null && !visitedCacheKeys.add(outputManager.shaHashCode.digest)) {
          // This program has been added before.
          return@testProgramAsync Skip()
        }
        val queryCachedResult =
          reducerContext.queryCache.lookUp(outputManager)
        if (queryCachedResult.isHit) {
          reducerContext.listenerManager.onTestResultCacheHit(
            program,
            edit,
            outputManager = outputManager,
          )
          return@testProgramAsync Skip()
        }
        // TODO(cnsun): add the TestScriptHistory here.
        return@testProgramAsync Proceed(
          outputManager,
          payload =
            EditTestPayload(
              edit,
              outputManager = outputManager,
            ),
        )
      },
    )
  }

  protected fun computeFileContentListForProgram(
    program: TokenizedProgram,
  ): FileNameContentPairList<String> {
    val contentList =
      reducerContext
        .createOutputManager(program)
        .fileContentList
    val builder =
      ImmutableList.builderWithExpectedSize<FileNameContentPair<String>>(
        contentList.size + 1,
      )
    contentList.pairs.forEach {
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
    return FileNameContentPairList(
      pairs = builder.build(),
      fileNameExtractor = { it },
    )
  }

  /** The content of the file under reduction, as rendered by [outputManager]. */
  protected fun fileUnderReductionContent(
    outputManager: AbstractOutputManager,
  ): AbstractFileContent.TextFileContent =
    outputManager
      .fileContentList
      .pairs
      .single { it.fileName === reducerContext.fileUnderReduction }
      .content
      .asTextFileContent

  /**
   * An output creator for node-reduction events: maps a candidate program to the per-file
   * (base name, rendered content) pairs of its output.
   */
  protected fun createOutputCreator():
    (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>> =
    { program ->
      reducerContext
        .createOutputManager(program)
        .fileContentList
        .pairs
        .transformToImmutableList { pair ->
          FileNameContentPair(
            fileName = pair.fileName.baseName,
            content = pair.content,
          )
        }
    }

  private fun createNodeDeletionActionSetInverse(
    originalInput: ImmutableList<AbstractSparTreeNode>,
    input: ImmutableList<AbstractSparTreeNode>,
  ): NodeDeletionActionSet {
    val actionSetBuilder =
      NodeDeletionActionSet.Builder("list minimizer@${input.size}")
    CollectionUtil.visitDifference(superList = originalInput, subList = input) {
      lazyAssert { !it.isPermanentlyDeleted }
      actionSetBuilder.deleteNode(it)
    }
    return actionSetBuilder.build()
  }

  protected fun createTreeEditForLiteralReplacement(
    tree: SparTree,
    allNodesToBeDeleted: ImmutableList<AbstractSparTreeNode>,
    actionSetDescriptionPrefix: String,
    fixpointReductionState: FixpointReductionState,
  ): LatraGeneralTreeEdit? {
    val actionSetBuilder =
      LatraGeneralActionSet.Builder(
        contextDescription =
          actionSetDescriptionPrefix +
            "LiteralReplacement@${allNodesToBeDeleted.size}",
        transformationName = "LiteralReplacement",
      )
    val orderedImportantLiterals =
      reducerContext
        .configuration.canonicalParserFacade.language.orderedImportantLiterals
    for (targetNode in allNodesToBeDeleted) {
      val rule = targetNode.payload?.expectedAntlrRuleType ?: continue
      if (rule.transitiveStringLiterals.isEmpty()) {
        continue
      }
      val literalCandidate =
        getMostImportantLiteral(
          allLiterals = rule.transitiveStringLiterals,
          order = orderedImportantLiterals,
        )
      val leafSequence =
        targetNode.leafNodeSequence().filter {
          it.token.lexemeText.isNotBlank()
        }
      val firstToken = leafSequence.firstOrNull() ?: continue
      if (leafSequence.count() == 1 && allNodesToBeDeleted.size == 1) {
        /* Our goal in the main reducer is to reduce the size of the program, so
         * if we cannot reduce the size, we skip the node.
         * We need to rely on other reducers, such as Vulcan, TRec and Latra to
         * create transformations that do not reduce program size.
         */
        continue
      }
      val antlrToken =
        runCatching {
          reducerContext.configuration.canonicalParserFacade.transformLiteralIntoSingleToken(
            literalCandidate,
          )
        }.onFailure { exception ->
          reducerContext.listenerManager.onAdHocMessageEvent(
            fixpointReductionState.createAdHocMessageEvent {
              """Exception occurred: 
                  |  The literal candidate is [$literalCandidate].
                  |  The expected rule type is ${rule.ruleName}.
                  |  The current node is of type ${targetNode.payload?.actualAntlrRuleType?.ruleName}
                  |  $exception
                  |
              """.trimMargin()
            },
          )
        }.getOrNull() ?: continue
      actionSetBuilder.replaceNode(
        targetNode,
        replacingNode =
          reducerContext.sparTreeNodeFactory.createLexerRuleSparTreeNodeForAntlrToken(
            antlrToken,
            overridingPosition = firstToken.token.asAntlrToken().position,
          ),
        extraActionsDescription =
          ",${rule.ruleName}->" +
            "${StringEscapeUtils.escapeJava(literalCandidate)}",
      )
    }
    val actionSet =
      actionSetBuilder.buildOrNull()
        ?: return null
    return tree.createLatraGeneralEdit(actionSet)
  }

  private fun getMostImportantLiteral(
    allLiterals: Collection<String>,
    order: List<String>,
  ): String {
    val result = order.firstOrNull { it in allLiterals }
    return result ?: allLiterals.first()
  }

  private fun createPropertyTester(
    actionSetDescriptionPrefix: String,
    tree: SparTree,
    fixpointReductionState: FixpointReductionState,
  ) = object : IPropertyTester<NodeContainerForListMinimizer, SparTreeListMinimizerPayload> {
    private fun testPropertyByLiteralReplacement(
      allNodesToBeDeleted: ImmutableList<AbstractSparTreeNode>,
      fixpointReductionState: FixpointReductionState,
    ): CandidateOutcome<SparTreeListMinimizerPayload> {
      val treeEdit =
        createTreeEditForLiteralReplacement(
          tree,
          allNodesToBeDeleted,
          actionSetDescriptionPrefix,
          fixpointReductionState,
        ) ?: return CandidateOutcome.Uninteresting.NotTested(
          "Skipped LiteralReplacement",
        )
      return testOneTreeEditAsCandidateOutcome(treeEdit)
    }

    private fun createDeletionEditOrNullOnCacheHit(
      allNodesToBeDeleted: ImmutableList<AbstractSparTreeNode>,
      partitionCount: Int,
      originalTotalPartitionCount: Int?,
    ): AbstractSparTreeEdit<*>? {
      val contextDescription =
        buildString {
          append(actionSetDescriptionPrefix).append("dd@")
          append("#nodes=${allNodesToBeDeleted.size},")
          append("#parts=$partitionCount")
          if (originalTotalPartitionCount != null) {
            append("#total-parts=$originalTotalPartitionCount")
          }
        }
      val actionSet =
        NodeDeletionActionSet
          .Builder(
            contextDescription =
            contextDescription,
          ).deleteNodes(allNodesToBeDeleted)
          .build()
      if (tree.isNodeActionSetCachedOrCacheIt(actionSet) == NodeActionSetCacheResult.HIT) {
        reducerContext.listenerManager.onNodeEditActionSetCacheHit(actionSet)
        return null
      }
      return tree.createNodeDeletionEdit(actionSet)
    }

    // Prepares the deletion (extracting nodes, building the action set, the node-action-set cache
    // check) synchronously on the caller's thread and dispatches only the test-script execution
    // off-thread, so a concurrency-capable minimizer can keep several in flight. When run to
    // completion via the returned handle's get(), it is equivalent to the sequential test.
    override fun testProperty(
      configuration: Candidate<NodeContainerForListMinimizer>,
    ): PropertyTestHandle<NodeContainerForListMinimizer, SparTreeListMinimizerPayload> {
      val allDeletedNodes = extractNonPermanentlyDeletedNodes(configuration.deletedElements)
      if (allDeletedNodes.isEmpty()) {
        // Deleting nothing yields the current best program, which is interesting. No script runs,
        // so there is no oracle verdict and no cost to attribute to this query.
        return ImmediatePropertyTestHandle(
          CandidateOutcome.Interesting(
            payload =
              SparTreeListMinimizerPayload(
                tree = tree,
                edit = EmptySparTreeEdit(tree, "$actionSetDescriptionPrefix[Empty]"),
                outputManager = null,
              ),
            testScriptVerdict = null,
          ),
        )
      }
      val treeEdit =
        createDeletionEditOrNullOnCacheHit(
          allDeletedNodes,
          partitionCount = configuration.deletedElements.size,
          originalTotalPartitionCount = configuration.getOriginalOrNull()?.size,
        ) ?: return ImmediatePropertyTestHandle(
          uninterestingDeletionResult(
            allDeletedNodes,
            // "Skipped" is what this case has always printed: the same deletion was tried before.
            CandidateOutcome.Uninteresting.NotTested("Skipped"),
          ),
        )
      val future = asyncTestOneEdit(treeEdit, visitedCacheKeys = null)
      return object :
        PropertyTestHandle<NodeContainerForListMinimizer, SparTreeListMinimizerPayload> {
        override fun get(): CandidateOutcome<SparTreeListMinimizerPayload> {
          val outcome = analyzeOneTestFuture(future)
          future.close()
          val result = outcome.withListMinimizerPayload()
          // Only a deletion that did not survive is eligible for the literal-replacement fallback.
          return if (result is CandidateOutcome.Uninteresting) {
            uninterestingDeletionResult(allDeletedNodes, result)
          } else {
            result
          }
        }

        override fun requestToCancel() {
          future.cancelWithInterruption()
          future.close()
        }
      }
    }

    // What a deletion that did not survive resolves to: the literal-replacement fallback if
    // enabled, otherwise [outcome] -- which says *why* it did not survive, and so whether the query
    // cost a script execution.
    //
    // The fallback discards [outcome]: when literal replacement is enabled and the deletion was
    // rejected, the cost of that first rejected test is not attributed to the query, because the
    // returned result carries the replacement's verdict instead. That path is off by default
    // (--enable-literal-replacement-for-list-minimizer).
    private fun uninterestingDeletionResult(
      allDeletedNodes: ImmutableList<AbstractSparTreeNode>,
      outcome: CandidateOutcome<SparTreeListMinimizerPayload>,
    ): CandidateOutcome<SparTreeListMinimizerPayload> =
      if (persesConfig.enableLiteralReplacementForListMinimizer) {
        testPropertyByLiteralReplacement(allDeletedNodes, fixpointReductionState)
      } else {
        outcome
      }

    private fun testOneTreeEditAsCandidateOutcome(
      treeEdit: AbstractSparTreeEdit<*>,
    ): CandidateOutcome<SparTreeListMinimizerPayload> =
      testOneTreeEditAndGetOutcome(treeEdit).withListMinimizerPayload()

    /**
     * Restates the reducer's outcome in the payload a list minimizer adopts. Only the interesting
     * case is rebuilt: an uninteresting outcome carries no payload, so it already *is* an outcome of
     * every payload type, and passes through untouched. Building the payload has to happen here
     * because it needs the captured [tree].
     */
    private fun CandidateOutcome<EditTestPayload>.withListMinimizerPayload():
      CandidateOutcome<SparTreeListMinimizerPayload> =
      when (this) {
        is CandidateOutcome.Interesting ->
          CandidateOutcome.Interesting(
            payload =
              SparTreeListMinimizerPayload(
                tree,
                payload.edit,
                outputManager = payload.outputManager,
              ),
            testScriptVerdict = testScriptVerdict,
          )
        is CandidateOutcome.Uninteresting -> this
      }
  }

  protected fun createListMinimizerListenerAdaptor(
    fixpointReductionState: FixpointReductionState,
    minimizerType: EnumListMinimizerType,
  ): ListMinimizerListenerAdaptor {
    val event = fixpointReductionState.fixpointIterationStartEvent
    return ListMinimizerListenerAdaptor { message ->
      val prefix = event.prefixLabelFromRootToHere + "[$minimizerType]"
      val perFileSizeMetrics =
        fixpointReductionState.inputRepresentation
          .computePerFileSizeMetrics()
      val initialMetrics = event.initialPerFileSizeMetrics()
      val globalPercentage =
        StringUtil.computePercentage(
          perFileSizeMetrics.totalCanonicalTokenCount,
          denominator = initialMetrics.totalCanonicalTokenCount,
        )
      val wholeMessage = "$message Global ratio:$globalPercentage"
      reducerContext.listenerManager.onAdHocMessageEvent(
        event.createAdHocMessageEvent(
          perFileSizeMetrics = perFileSizeMetrics,
          newPrefixLabelFromRootToHere = prefix,
          messageComputer = { wholeMessage },
        ),
      )
    }
  }

  private fun createOnBestUpdateHandler() =
    OnBestUpdateHandler<NodeContainerForListMinimizer, SparTreeListMinimizerPayload> { _, payload ->
      val tree = payload.tree
      val outputManager = payload.outputManager
      tree.applyEdit(
        payload.edit,
        canonicalTokenCount = computeCanonicalTokenCount(outputManager),
      )
    }

  private fun extractNonPermanentlyDeletedNodes(
    containers: Collection<NodeContainerForListMinimizer>,
  ): ImmutableList<AbstractSparTreeNode> {
    val resultNodes = HashSet<AbstractSparTreeNode>()
    val resultBuilder = ImmutableList.builder<AbstractSparTreeNode>()
    for (container in containers) {
      for (node in container.nodes) {
        if (!node.isPermanentlyDeleted && resultNodes.add(node)) {
          resultBuilder.add(node)
        }
      }
    }
    return resultBuilder.build()
  }

  protected fun runListMinimizerOverNodes(
    needToTestEmpty: Boolean,
    tree: SparTree,
    input: ImmutableList<out AbstractSparTreeNode>,
    fixpointReductionState: FixpointReductionState,
    actionsDescriptionPostfix: ContextDescription,
    specifiedMinimizerType: EnumListMinimizerType? = null,
  ): ImmutableList<out AbstractSparTreeNode> {
    val listInput =
      input.transformToImmutableList {
        NodeContainerForListMinimizer.of(it)
      }
    val result =
      genericRunListMinimizer(
        needToTestEmpty = needToTestEmpty,
        tree = tree,
        input = listInput,
        fixpointReductionState = fixpointReductionState,
        actionsDescriptionPostfix = actionsDescriptionPostfix,
        specifiedMinimizerType = specifiedMinimizerType,
      )
    return result.transformToImmutableList { it.nodes.single() }
  }

  protected fun runListMinimizerOverListsOfNodes(
    needToTestEmpty: Boolean,
    tree: SparTree,
    input: ImmutableList<out ImmutableList<out AbstractSparTreeNode>>,
    fixpointReductionState: FixpointReductionState,
    actionsDescriptionPostfix: ContextDescription,
    specifiedMinimizerType: EnumListMinimizerType?,
  ): ImmutableList<ImmutableList<out AbstractSparTreeNode>> {
    val listInput =
      input.transformToImmutableList {
        NodeContainerForListMinimizer(it)
      }

    val result =
      genericRunListMinimizer(
        needToTestEmpty = needToTestEmpty,
        tree = tree,
        input = listInput,
        fixpointReductionState = fixpointReductionState,
        actionsDescriptionPostfix = actionsDescriptionPostfix,
        specifiedMinimizerType = specifiedMinimizerType,
      )
    return result.transformToImmutableList { it.nodes }
  }

  private fun genericRunListMinimizer(
    needToTestEmpty: Boolean,
    tree: SparTree,
    input: ImmutableList<NodeContainerForListMinimizer>,
    fixpointReductionState: FixpointReductionState,
    actionsDescriptionPostfix: ContextDescription,
    specifiedMinimizerType: EnumListMinimizerType?,
  ): ImmutableList<out NodeContainerForListMinimizer> {
    if (input.isEmpty()) {
      return input
    }
    val minimizerType = specifiedMinimizerType ?: computeDefaultListMinimizerType()
    val reducerClassName = firstNonNullSimpleName(this::class.java)
    val finalActionDescription =
      "$minimizerType in ${reducerAnnotation.shortName}($reducerClassName)" +
        actionsDescriptionPostfix
    val arguments =
      createListMinimizerArguments(
        needToTestEmpty = needToTestEmpty,
        tree = tree,
        logger = createListMinimizerListenerAdaptor(fixpointReductionState, minimizerType),
        contextDescription = finalActionDescription,
        input = input,
        fixpointReductionState = fixpointReductionState,
      )
    recordProblemIfRequested(
      tree = tree,
      input = input,
      minimizerType = minimizerType,
      contextDescription = finalActionDescription,
      fixpointReductionState = fixpointReductionState,
    )
    val listMinimizer = ListMinimizerFactory.create(minimizerType, arguments)
    return listMinimizer.reduce()
  }

  /**
   * Captures this minimization problem when running in RECORD mode. A no-op otherwise -- the writer
   * is null on the normal path, so this costs one null check per list minimization and cannot alter
   * the reduction: it only reads the tree and prints a copy of the current program.
   */
  private fun recordProblemIfRequested(
    tree: SparTree,
    input: ImmutableList<NodeContainerForListMinimizer>,
    minimizerType: EnumListMinimizerType,
    contextDescription: String,
    fixpointReductionState: FixpointReductionState,
  ) {
    val writer = reducerContext.listMinimizationMicrobenchmarkWriter ?: return
    val baseProgram = tree.programSnapshot.payload
    val canonicalParserFacade = reducerContext.configuration.canonicalParserFacade
    val originalReductionInputs = reducerContext.ioManager.originalReductionInputs
    writer.writeProblem(
      baseProgramTokens = baseProgram.tokens,
      // The leaf tokens of each element. These are the very token objects the program snapshot
      // holds -- SparTree builds it from the same leaf sequence -- so looking their ranges up by
      // identity resolves for every one of them.
      elementTokenGroups =
        input.map { container ->
          container.nodes.flatMap { node -> node.leafNodeSequence().map { it.token } }
        },
      targetFilePath =
        originalReductionInputs
          .getRelativePathForOrigFile(reducerContext.fileUnderReduction)
          .toString(),
      recordingContext =
        RecordingContext(
          languageName = canonicalParserFacade.language.name,
          parserFacadeClassName = canonicalParserFacade::class.java.name,
          reducerClassName = this::class.java.name,
          minimizerType = minimizerType.name,
          contextDescription = contextDescription,
          fixpointIteration = fixpointReductionState.fixpointIterationStartEvent.iteration,
          commandLineOptions = writer.commandLineOptions,
        ),
    ) { inputDirectory ->
      // Constructing the folder is what writes the test script and every immutable dependency file;
      // rendering the mutable files then fills in the rest.
      reducerContext
        .createOutputManager(baseProgram)
        .write(ReductionFolder(originalReductionInputs, inputDirectory))
    }
  }

  private fun createListMinimizerArguments(
    needToTestEmpty: Boolean,
    tree: SparTree,
    logger: ListMinimizerListenerAdaptor?,
    contextDescription: String,
    input: ImmutableList<out NodeContainerForListMinimizer>,
    fixpointReductionState: FixpointReductionState,
  ): ListMinimizerArguments<NodeContainerForListMinimizer, SparTreeListMinimizerPayload> {
    val listMinimizerConfig = reducerContext.configuration.listMinimizerConfig
    val propertyTester =
      createPropertyTester(
        actionSetDescriptionPrefix = contextDescription,
        tree,
        fixpointReductionState,
      )
    return ListMinimizerArguments(
      needToTestEmpty = needToTestEmpty,
      input = input,
      isElementDeletedElsewhere = { nodeContainer ->
        nodeContainer.areAllNodesPermanentlyDeleted()
      },
      propertyTester = propertyTester,
      // Concurrency-capable minimizers keep up to one test per worker thread in flight; the tree
      // evolves through the same committed sequence, so the result matches the sequential run. At a
      // single thread this is 1, i.e. the plain sequential path (goldens run single-threaded).
      concurrency = executorService.specifiedNumOfThreads,
      onBestUpdateHandler = createOnBestUpdateHandler(),
      descriptionPrefix = contextDescription,
      weightProvider = { it.tokenCount },
      listener =
        AbstractListMinimizerListener.smartCombine(reducerContext.listMinimizerListener, logger),
      windowedSlicerSpecificArguments =
        computeWindowedSlicerArguments()
          ?: WindowedSlicerSpecificArguments(
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
      adaptiveGainDrivenMinimizerArguments =
        AdaptiveGainDrivenMinimizerArguments(
          getCurrentTotalTokenCount = {
            tree.programSnapshot.canonicalTokenCount
          },
          anticipatedTokenCountInResult = persesConfig.anticipatedFinalTokenCount,
        ),
    )
  }

  protected fun optionallyCreateDeletionEditAndLog(
    actionSet: NodeDeletionActionSet,
    tree: SparTree,
  ): NodeDeletionTreeEdit? =
    if (tree.isNodeActionSetCachedOrCacheIt(actionSet) == NodeActionSetCacheResult.HIT) {
      reducerContext.listenerManager.onNodeEditActionSetCacheHit(actionSet)
      null
    } else {
      tree.createNodeDeletionEdit(actionSet)
    }

  protected fun optionallyCreateReplacementEditAndLog(
    actionSet: NodeReplacementActionSet,
    tree: SparTree,
  ): DescendantHoistingTreeEdit? =
    if (tree.isNodeActionSetCachedOrCacheIt(actionSet) == NodeActionSetCacheResult.HIT) {
      reducerContext.listenerManager.onNodeEditActionSetCacheHit(actionSet)
      null
    } else {
      tree.createDescendantHoistingEdit(actionSet)
    }

  enum class EditApplicationResult {
    APPLIED,
    NO,
  }

  protected fun testAndApplyEditIfInteresting(
    edit: AbstractSparTreeEdit<*>,
    tree: SparTree,
  ): EditApplicationResult {
    val result = testOneTreeEditAndReturnTheBest(edit) ?: return EditApplicationResult.NO
    tree.applyEdit(
      result.edit,
      canonicalTokenCount = computeCanonicalTokenCount(result.outputManager),
    )
    return EditApplicationResult.APPLIED
  }

  protected fun applyEditToTree(payload: EditTestPayload) {
    applyEditToTree(payload.edit, payload.outputManager)
  }

  protected fun applyEditToTree(
    edit: AbstractSparTreeEdit<*>,
    outputManager: AbstractOutputManager,
  ) {
    val tree = edit.tree
    tree.applyEdit(
      treeEdit = edit,
      canonicalTokenCount = computeCanonicalTokenCount(outputManager),
    )
  }

  /**
   * Computes the canonical token count of the program produced by an edit, by lexing the output
   * manager's content with the canonical parser facade. This runs once per applied edit, i.e. once
   * per program change.
   *
   * The count is deliberately NOT taken from the spar-tree's own token count, which is the leaf
   * count of the incrementally edited in-memory tree. For some grammars (notably Python, whose
   * printer/parser round-trip is not token-count preserving) that leaf count drifts from the token
   * count of the program the tree serializes to; a later spar-tree rebuild then recomputes the
   * fresh value, so the size appears to jump and trips the monotonicity check in
   * ReducerScheduler.SchedulerEventHistory.add(). Lexing the output manager's content keeps the
   * canonical token count a stable, correct function of the actual program, and is correct for
   * surrogate-facade reductions too because it always lexes with the canonical facade.
   */
  protected fun computeCanonicalTokenCount(outputManager: AbstractOutputManager?): Int? {
    if (outputManager == null) {
      return null
    }
    return reducerContext.configuration.canonicalParserFacade
      .countTokensInString(fileUnderReductionContent(outputManager).text)
  }

  protected fun testAndApplyDeletionEditIfInteresting(
    actionSet: NodeDeletionActionSet,
    tree: SparTree,
  ): EditApplicationResult {
    val edit =
      optionallyCreateDeletionEditAndLog(actionSet, tree) ?: return EditApplicationResult.NO
    return testAndApplyEditIfInteresting(edit, tree)
  }

  companion object {
    @JvmStatic
    protected val logger = FluentLogger.forEnclosingClass()

    /**
     * An anonymous reducer subclass (e.g. the `object : PersesNodeReducer(...)` node annotations)
     * has a null `simpleName`, so walk up the superclass chain to the first named class instead.
     */
    private fun firstNonNullSimpleName(clazz: Class<*>): String {
      var current: Class<*>? = clazz
      while (current != null) {
        current.kotlin.simpleName?.let { return it }
        current = current.superclass
      }
      return clazz.name
    }
  }
}

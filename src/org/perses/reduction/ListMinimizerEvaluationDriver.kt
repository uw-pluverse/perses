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
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.PersesCommandOptions
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.flattokenlist.FlatTokenListParserFacade
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.microbenchmark.ListMinimizationMicrobenchmark
import org.perses.listminimizer.microbenchmark.ListMinimizerMetricsCollector
import org.perses.program.AbstractReductionFile
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.reduction.scheduler.ReducerExecutionPlan
import org.perses.reduction.scheduler.ReducerExecutionPlan.AtomicReducerStep
import org.perses.util.ktFine
import java.nio.file.Path

/**
 * The [IReductionDriver] of evaluation mode: it runs exactly one list minimizer over exactly one
 * recorded microbenchmark and writes what that minimizer did.
 *
 * A driver rather than a function on the main class, for the same reason ppr's diff reducers are
 * drivers: it is an alternative reduction strategy, selected by [createReductionDriver], with a
 * lifetime the pipeline already knows how to manage. What it reduces is a recorded list rather than
 * a program, and what it produces is metrics rather than a smaller program, but the shape -- run
 * until done, then close -- is the pipeline's.
 *
 * One driver means one (microbenchmark x minimizer) measurement. Evaluating several minimizers in one
 * process would blend them: the executor's statistics accumulate process-wide and the reduction
 * lifecycle fires once, so the statistics summary and progress dump would describe an average of
 * several algorithms rather than any one of them.
 *
 * The program itself comes from the result folder, through the base class's
 * [inputRepresentation] -- the same place every other driver reads its starting program.
 */
class ListMinimizerEvaluationDriver private constructor(
  globalContext: GlobalContext,
  cmd: PersesCommandOptions,
  ioManager: TokenReductionIOManager,
  mainFile: AbstractReductionFile<*, *>,
  configuration: ReductionConfiguration,
  listenerManager: AsyncReductionListenerManager,
  languageProfile: LanguageProfile,
  reducerFactory: ReducerFactory,
  queryCache: AbstractQueryCache,
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  reductionStartEvent: ReductionStartEvent,
  executorService: TestScriptExecutorService,
  otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
  private val microbenchmark: ListMinimizationMicrobenchmark,
  private val minimizerType: EnumListMinimizerType,
  private val outputDirectory: Path,
) : AbstractProgramReductionDriver(
    globalContext = globalContext,
    cmd = cmd,
    ioManager = ioManager,
    mainFile = mainFile,
    configuration = configuration,
    listenerManager = listenerManager,
    // Inert here: evaluation runs one list minimizer, never the reducer pipeline. Threaded through
    // anyway so the driver is configured from the same params as every other one.
    languageProfile = languageProfile,
    reducerFactory = reducerFactory,
    queryCache = queryCache,
    outputManagerFactory = outputManagerFactory,
    reductionStartEvent = reductionStartEvent,
    executorService = executorService,
  ) {
  /**
   * Built by the *surrogate* facade, not the canonical one -- the same split the tolerant Dyck and
   * Line fallbacks use. `FlatTokenList` (`start : TOKEN* EOF`) cannot reject anything the real lexer
   * emits, so a recorded mid-reduction program that no longer parses under its real grammar still
   * yields a tree. The canonical facade still decides the token counts and, through
   * [outputManagerFactory], how candidates are printed.
   */
  override var inputRepresentation: InputRepresentation =
    createInputRepresentation(
      sourceFile = ioManager.resultFolder.computeAbsPathForOrigFile(mainFile),
      fileRepresentedByTree = mainFile,
      otherMutableFileContents = otherMutableFileContents,
      surrogateParserFacade =
        FlatTokenListParserFacade(configuration.canonicalParserFacade.realLexerClass),
      canonicalParserFacade = configuration.canonicalParserFacade,
      specifiedSparTreeNodeFactory = null,
      semanticsProviderCreator = null,
      enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
      originalReductionInputs = ioManager.originalReductionInputs,
    )

  /**
   * The metrics collector, combined with whatever human-readable trace `--profile-list-minimizer`
   * asked for, so both observe the same event stream. Registered for close by the base class.
   */
  private val metricsCollector =
    ListMinimizerMetricsCollector(
      microbenchmarkId = microbenchmark.microbenchmarkId,
      // The listener API is erased. The reducers wrap each element in a NodeContainer whose
      // tokenCount is exactly the weight the production arguments hand the minimizer, so
      // deletedWeight is reported in the units the weighted minimizers actually optimized.
      weightProvider = { (it as NodeContainerForListMinimizer).tokenCount },
      hideTimings = cmd.verbosityFlags.hideTimestamps,
      minimizerTypeName = minimizerType.name,
      scriptExecutionCountSupplier = {
        executorService.statistics.scriptExecutionNumber - scriptExecutionsBeforeReduce
      },
      queryJsonlFile =
        outputDirectory.resolve(ListMinimizerMetricsCollector.QUERY_JSONL_FILE_NAME),
      summaryJsonlFile =
        outputDirectory.resolve(ListMinimizerMetricsCollector.SUMMARY_JSONL_FILE_NAME),
    )

  override fun createListMinimizerListener() =
    AbstractListMinimizerListener.smartCombine(
      super.createListMinimizerListener(),
      registerToClose(metricsCollector),
    )

  /**
   * The injection point for the recorded list. The scheduler instantiates a reducer from its
   * annotation, so the annotation is an instance field of this driver, closing over the microbenchmark --
   * which is also why this reducer can never be reached by `--alg`.
   */
  private val evaluationReducerAnnotation =
    object : ReducerAnnotation(
      shortName = "list_minimizer_evaluation",
      description = "Runs one list minimizer over one recorded list, to measure it.",
      deterministic = false,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext) =
        ImmutableList.of<AbstractSparTreeReducer>(
          ListMinimizerEvaluationReducer(
            reducerAnnotation = this,
            reducerContext = reducerContext,
            rangesPerElement = microbenchmark.inputList.elements.map { it.ranges },
            minimizerType = minimizerType,
          ),
        )
    }

  /**
   * One pass of one reducer: no cleanup step, no fixpoint, none of the pipeline stages the default
   * plan weaves in. A measurement is of one minimizer on one list, so anything else running would
   * both change the program and add script executions the minimizer never asked for.
   */
  override fun createReducerExecutionPlan(
    atomicMainReducerStep: AtomicReducerStep,
    cleanupReducerStep: AtomicReducerStep,
  ) = ReducerExecutionPlan(steps = AtomicReducerStep(evaluationReducerAnnotation))

  /**
   * The executor's count before this measurement started. The executor is shared across the whole
   * reduction, so its statistic is cumulative; the collector reports the difference.
   */
  private var scriptExecutionsBeforeReduce = 0

  override fun reduce() {
    warnIfTheRecordedLanguageDisagrees()
    scriptExecutionsBeforeReduce = executorService.statistics.scriptExecutionNumber
    logger.ktFine { "Evaluating $minimizerType on ${microbenchmark.microbenchmarkId}." }
    // The base class saves the starting program, registers the tree-edit listeners and drives the
    // plan above; the collector has written summary.jsonl by the time this returns.
    super.reduce()
    checkTheMinimizerRanExactlyOnce()
  }

  /**
   * A measurement is of one minimizer on one list. Nothing in the reduction machinery enforces
   * that: [createReducerExecutionPlan] below drops the fixpoint, but a loop reinstated there would
   * call the annotation's `create` afresh each iteration, so [AbstractSparTreeReducer]'s
   * "not designed to be reused" check -- which guards an *instance* -- would never fire. The
   * failure mode is silent: each extra run appends another well-formed `summary.jsonl` record, and the
   * sweep would average several runs of one (microbenchmark, minimizer) pair as if they were one.
   */
  private fun checkTheMinimizerRanExactlyOnce() {
    val runCount = metricsCollector.completedReductionCount
    check(runCount == 1) {
      "Evaluating $minimizerType on ${microbenchmark.microbenchmarkId} ran the minimizer " +
        "$runCount time(s), but a measurement requires exactly one run."
    }
  }

  /**
   * The lexer decides what the recorded ranges resolve to, so a facade other than the recorded one
   * is the single most likely cause of a resolution failure. Warn rather than fail: the recorded
   * name is a label, and the flags the binary was given stay authoritative.
   */
  private fun warnIfTheRecordedLanguageDisagrees() {
    val actual = configuration.canonicalParserFacade::class.qualifiedName
    val recorded = microbenchmark.recordingContext.parserFacadeClassName
    if (actual != recorded) {
      logger.atWarning().log(
        "Problem %s was recorded with %s but is being evaluated with %s. " +
          "If range resolution fails, this is why.",
        microbenchmark.microbenchmarkId,
        recorded,
        actual,
      )
    }
  }

  companion object {
    // The production defaults of --min-slicing-window-size, --max-slicing-window-size, Vulcan's
    // --window-size and --anticipated-result-token-count, so an evaluated minimizer behaves as it
    // does inside a real reduction.
    private const val MIN_SLIDING_WINDOW_SIZE = 1
    private const val MAX_SLIDING_WINDOW_SIZE = 14
    private const val LOCAL_EXHAUST_WINDOW_SIZE = 4
    private const val ANTICIPATED_TOKEN_COUNT_IN_RESULT = 150

    private val logger = FluentLogger.forEnclosingClass()

    /**
     * Assembles the driver from the same [ReductionDriverParams] every other driver is built from,
     * so the IO manager, the renderer and the reduction configuration are the production ones.
     */
    fun create(
      params: ReductionDriverParams,
      mainFile: AbstractReductionFile<*, *>,
      resolvedParserFacade: AbstractParserFacade,
      microbenchmark: ListMinimizationMicrobenchmark,
      minimizerType: EnumListMinimizerType,
      outputDirectory: Path,
    ): ListMinimizerEvaluationDriver {
      val components =
        RegularProgramReductionDriver.buildComponents(params, mainFile, resolvedParserFacade)
      return ListMinimizerEvaluationDriver(
        globalContext = params.globalContext,
        cmd = params.cmd,
        ioManager = components.ioManager,
        mainFile = mainFile,
        configuration = components.configuration,
        listenerManager = params.listenerManager,
        languageProfile = params.languageProfile,
        reducerFactory = params.reducerFactory,
        queryCache = params.queryCache,
        outputManagerFactory = components.outputManagerFactory,
        reductionStartEvent = params.reductionStartEvent,
        executorService = params.executorService,
        otherMutableFileContents = components.otherMutableFileContents,
        microbenchmark = microbenchmark,
        minimizerType = minimizerType,
        outputDirectory = outputDirectory,
      )
    }
  }
}

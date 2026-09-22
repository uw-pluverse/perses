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
 * One driver means one (microbenchmark x minimizer) measurement, but a process runs several of
 * them in turn -- setup is what a process per measurement was paying for, not isolation. What
 * keeps two measurements from blending is threefold: each driver builds its own tree (copied from
 * the first, since a minimizer commits its accepted bests into the tree it is given), clears the
 * query cache when it starts, and writes into a directory named after its minimizer. The reducer
 * annotation carries the minimizer's name too, so the statistics tables, which key on it, report a
 * row per measurement rather than an average.
 *
 * What genuinely remains process-wide is the reduction lifecycle: `onReductionStart`/`onReductionEnd`
 * fire once, so the progress dump interleaves the measurements and the end-of-run size metrics
 * describe only the last. The per-minimizer numbers anyone analyses are in `summary.jsonl` and
 * `queries.jsonl`, which are fully separated; the blended files are diagnostics.
 *
 * The program itself comes from the recorded input, through [inputRepresentation] -- not from the
 * result folder that every other driver starts from, for the reason given there.
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
  /**
   * A pristine representation of the recorded program to copy, or null to build one by parsing.
   *
   * Only the first measurement of a process parses; the rest copy, which is what keeps the lexing
   * and the tree build off the per-measurement bill. See [InputRepresentation.withPrivateTreeCopy].
   */
  private val prototypeInputRepresentation: InputRepresentation?,
  /**
   * The `--profile-list-minimizer` trace, owned by the caller and shared by every measurement of
   * this process.
   *
   * Shared rather than built here, because [ListMinimizerProgressListener] truncates the file it
   * opens: one per driver would leave only the last measurement's trace at the path the user named.
   * One file is the better artifact anyway -- each run's block opens with its algorithm and its
   * description prefix, which carries the minimizer's name -- and it is the file the flag asked
   * for. Not registered for close here, for the same reason: it outlives this driver.
   */
  private val sharedProgressListener: AbstractListMinimizerListener,
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
   *
   * Read from the recorded input rather than from the result folder, which is where every other
   * driver reads its starting program. A measurement must start from the program the ranges were
   * recorded against, and the result folder does not stay that program: a committed best is written
   * there (`AbstractProgramReductionDriver`'s edit listener), so a second measurement in the same
   * process would start from the first one's reduced output and the recorded ranges would no longer
   * land on token boundaries. The input is the one copy nothing writes to --
   * [org.perses.reduction.io.AbstractOriginalReductionInputs.checkOutputDirectoryIsNotInPlace]
   * guarantees the output directory cannot overlap it. For the first measurement the two are
   * byte-identical, since the result folder is populated from these very bytes.
   */
  override var inputRepresentation: InputRepresentation =
    prototypeInputRepresentation?.withPrivateTreeCopy() ?: createInputRepresentation(
      sourceFile = mainFile.file,
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
      // The raw cumulative counter. The collector brackets it across the minimizer's own lifetime;
      // bracketing it here would start the window too early -- see the comment on reduce() below.
      scriptExecutionCountSupplier = { executorService.statistics.scriptExecutionNumber },
      queryJsonlFile =
        outputDirectory.resolve(ListMinimizerMetricsCollector.QUERY_JSONL_FILE_NAME),
      summaryJsonlFile =
        outputDirectory.resolve(ListMinimizerMetricsCollector.SUMMARY_JSONL_FILE_NAME),
    )

  override fun createListMinimizerListener() =
    AbstractListMinimizerListener.smartCombine(
      sharedProgressListener,
      registerToClose(metricsCollector),
    )

  /**
   * The injection point for the recorded list. The scheduler instantiates a reducer from its
   * annotation, so the annotation is an instance field of this driver, closing over the microbenchmark --
   * which is also why this reducer can never be reached by `--alg`.
   *
   * The minimizer is part of the short name because the statistics summary and the progress dump
   * key their per-reducer tables on it, and those are process-wide: several measurements sharing
   * one process would otherwise roll up into a single row describing none of them. Safe to vary
   * because nothing registers this annotation with [ReducerFactory], so no `--alg` or `--list-algs`
   * name changes with it.
   */
  private val evaluationReducerAnnotation =
    object : ReducerAnnotation(
      shortName = "list_minimizer_evaluation.$minimizerType",
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
   * The window the collector measures starts when the *minimizer* starts, not when this driver
   * does. super.reduce() runs a script before the reducer is invoked -- the Layer-2 check in
   * AbstractProgramReductionDriver.ensureInterestingCodeFormatOrThrow, which renders the tree under
   * the active code format and verifies it still passes the test. That execution bypasses
   * analyzeOneTestFuture, so it is not a query and never reaches the listener; counting it made
   * scriptExecutionCount exceed the observed queries by exactly one, which is the discrepancy the
   * field exists to detect.
   */
  override fun reduce() {
    warnIfTheRecordedLanguageDisagrees()
    // A measurement must not inherit another measurement's answers. The query cache is owned by the
    // main and outlives every driver, so a second evaluation in the same process would find the
    // previous minimizer's rejected candidates already recorded and skip executing them. The query
    // *counts* would survive that -- a cache hit still reaches the listener -- but
    // scriptExecutionCount and every oracle duration would describe whichever minimizer happened to
    // run first. Clearing here makes each run start as empty as a fresh process does, which is what
    // lets several runs share one process and stay comparable with runs that did not.
    queryCache.clearCache()
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
      sharedProgressListener: AbstractListMinimizerListener,
      prototypeInputRepresentation: InputRepresentation?,
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
        sharedProgressListener = sharedProgressListener,
        prototypeInputRepresentation = prototypeInputRepresentation,
      )
    }
  }
}

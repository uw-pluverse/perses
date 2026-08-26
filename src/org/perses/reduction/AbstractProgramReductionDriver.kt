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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.PersesCommandOptions
import org.perses.cmd.EnumListMinimizerMicrobenchmarkingMode
import org.perses.cmd.EnumPassMode
import org.perses.cmd.MimirFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AntlrFailureException
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.LanguageC
import org.perses.grammar.dyck.AbstractDyckParserFacade
import org.perses.grammar.java.LanguageJava
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.ListMinimizerProgressListener
import org.perses.listminimizer.NullListMinimizerListener
import org.perses.listminimizer.microbenchmark.ListMinimizationMicrobenchmarkWriter
import org.perses.mimir.MimirJavacSemanticProviderCreator
import org.perses.mimir.MimirSemanticsProviderCreator
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractActionSetProfiler.ActionSetProfiler
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.cache.PassLevelCache
import org.perses.reduction.cache.PassLevelCache.PassLevelCacheResult
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TestScriptExecutorServiceStatisticsSnapshot
import org.perses.reduction.io.AbstractOriginalReductionInputs
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.reduction.reducer.CReduceReducerAnnotation
import org.perses.reduction.reducer.FormatReducer
import org.perses.reduction.reducer.NonSyntacticSingleTreeNodeReducer
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.reduction.reducer.SparTreeRootReplacementReducer
import org.perses.reduction.reducer.hdd.HDDReducerAnnotations
import org.perses.reduction.reducer.latra.CoarseGritLatraReducerAnnotation
import org.perses.reduction.reducer.latra.FineGritLatraReducerAnnotation
import org.perses.reduction.reducer.lpr.LlmBasedDataTypeEliminationReducer
import org.perses.reduction.reducer.lpr.LlmBasedDataTypeSimplificationReducer
import org.perses.reduction.reducer.lpr.LlmBasedFunctionInliningReducer
import org.perses.reduction.reducer.lpr.LlmBasedLoopUnrollingReducer
import org.perses.reduction.reducer.lpr.LlmBasedVariableEliminationReducer
import org.perses.reduction.reducer.sfc.IdentifierUseEliminationReducer
import org.perses.reduction.reducer.sfc.SmallerStructureReplacementReducer
import org.perses.reduction.reducer.sfc.StructureCanonicalizationReducer
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.reduction.reducer.token.LineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.trec.TokenCanonicalizer
import org.perses.reduction.reducer.vulcan.IdentifierReplacementReducer
import org.perses.reduction.reducer.vulcan.SubTreeReplacementReducer
import org.perses.reduction.reducer.vulcan.pattern.LocalExhaustivePatternReducer
import org.perses.reduction.scheduler.ReducerExecutionPlan
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractCondition.ContinueOnChange
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractExecutionPlanStep
import org.perses.reduction.scheduler.ReducerExecutionPlan.AtomicReducerStep
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.concatenate
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.fixpoint
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.ifProgressed
import org.perses.reduction.scheduler.ReducerScheduler
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.reduction.semantics.ISemanticsProviderCreator
import org.perses.spartree.AbstractSparTreeEditListener
import org.perses.spartree.AbstractTreeNode
import org.perses.spartree.SparTreeNodeFactory
import org.perses.spartree.SparTreeParserUtility
import org.perses.util.FileSystemUtil
import org.perses.util.TimeSpan
import org.perses.util.ktFine
import org.perses.util.ktSevere
import org.perses.util.ktWarning
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap
import org.perses.util.transformToImmutableList
import java.lang.ref.WeakReference
import java.nio.file.Path
import kotlin.io.path.name
import kotlin.io.path.readText

abstract class AbstractProgramReductionDriver(
  globalContext: GlobalContext,
  protected val cmd: PersesCommandOptions,
  ioManager: TokenReductionIOManager,
  /** The reduction file this driver reduces. Specified at creation by the caller. */
  protected val mainFile: AbstractReductionFile<*, *>,
  val configuration: ReductionConfiguration,
  val listenerManager: AsyncReductionListenerManager,
  protected val languageProfile: LanguageProfile,
  protected val reducerFactory: ReducerFactory,
  /** The query cache, shared across every per-file driver of the reduction. */
  protected val queryCache: AbstractQueryCache,
  /** The initial output-manager factory (the renderer; carries the code format). The driver owns it
   * -- not the IO manager -- and may swap it during adaptive code-format selection. */
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  /** The single whole-reduction start event, created once by [org.perses.AbstractMain] and shared by
   * every driver. This driver uses it for its fixpoint-iteration and ad-hoc messages rather than
   * creating its own; the lifecycle onReductionStart/onReductionEnd are fired once by AbstractMain. */
  protected val reductionStartEvent: ReductionStartEvent,
  executorService: TestScriptExecutorService,
) : AbstractReductionDriver<TokenizedProgram, TokenReductionIOManager>(
    globalContext = globalContext,
    ioManager = ioManager,
    executorService = executorService,
    hideTimestampsInLog = cmd.verbosityFlags.hideTimestamps,
  ) {
  abstract var inputRepresentation: InputRepresentation

  // The driver owns the active output-manager factory (the renderer; carries the code format), so it
  // -- not the IO manager -- decides the format. Adaptive code-format selection swaps it in place
  // (to an immutable sibling) and every render flows through it: reducers via the reducer context's
  // provider, and saveBestProgram below. @Volatile + swapped only between reducer passes.
  @Volatile
  private var activeOutputManagerFactory: AbstractTokenOutputManagerFactory = outputManagerFactory

  init {
    // The format-sensitivity check formerly lived in TokenReductionIOManager; the code format is now
    // owned by the factory (the driver), so validate it here against the active file's own language.
    val languageKind = configuration.canonicalParserFacade.language
    require(languageKind.isCodeFormatAllowed(activeOutputManagerFactory.defaultCodeFormatControl)) {
      "The language $languageKind requires format sensitivity, " +
        "but the reducer is not told to keep its original format. " +
        "${activeOutputManagerFactory.defaultCodeFormatControl}"
    }
  }

  private val actionSetProfiler =
    if (cmd.profilingFlags.actionSetProfiler == null) {
      AbstractActionSetProfiler.NULL_PROFILER
    } else {
      ActionSetProfiler(cmd.profilingFlags.actionSetProfiler!!)
    }

  private val sparTreeEditListeners by lazy {
    createSparTreeEditListeners(
      ioManager = ioManager,
      renderBestProgram = { activeOutputManagerFactory.createManagerFor(it) },
      queryCache = queryCache,
      perFileSizeMetricsSupplier = { inputRepresentation.computePerFileSizeMetrics() },
      listenerManager = listenerManager,
    )
  }

  override fun reduce() {
    printStartTime()
    val parsableTree = inputRepresentation.tree
    // The whole-reduction lifecycle events (onReductionStart/onReductionEnd) are fired once by
    // AbstractMain.internalRun, not here: a single reduction runs many per-file drivers (warm-up and
    // full sweeps). This driver reuses the shared [reductionStartEvent] AbstractMain passed in for its
    // fixpoint-iteration and ad-hoc messages rather than creating its own.
    try {
      logCacheSettings()
      ioManager.saveBestProgram(
        activeOutputManagerFactory.createManagerFor(parsableTree.programSnapshot.payload),
      )
      parsableTree.registerSparTreeEditListeners(sparTreeEditListeners)
      val reducerExecutionPlan =
        run {
          val atomicMainReducerStep =
            AtomicReducerStep(
              reducer = createMainReducerCreator(),
            )
          val cleanupReducerAnnotation = createCleanupReducerCreator()
          val cleanupReducerStep =
            if (cleanupReducerAnnotation != null) {
              AtomicReducerStep(
                reducer = cleanupReducerAnnotation,
              )
            } else {
              atomicMainReducerStep
            }
          createReducerExecutionPlan(
            atomicMainReducerStep,
            cleanupReducerStep,
          )
        }
      listenerManager.onAdHocMessageEvent(
        reductionStartEvent.createAdHocMessageEvent(
          perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
          prefixLabelFromRootToHere = "",
        ) {
          buildString {
            append("The reducer execution plan is listed below.\n")
            reducerExecutionPlan.steps.toDefinition().prettyPrint().lines().forEach {
              append("    ").appendLine(it)
            }
            appendLine()
          }
        },
      )
      internalReduce(
        reductionStartEvent = reductionStartEvent,
        reducerExecutionPlan = reducerExecutionPlan,
      )
      // Format the final result before firing the reduction-end event, so the event reports the
      // formatted result. Formatting grows the character count, so unlike C-Reduce it is not woven
      // into the execution plan (the global-minimum restoration would revert it); it runs here,
      // after the plan has produced the smallest result.
      if (cmd.outputRefiningFlags.callFormatter) {
        callReducer(reductionStartEvent, FormatReducer(reducerContext))
      }
    } catch (e: Exception) {
      listenerManager.onCriticalException(e)
    }
  }

  private fun logCacheSettings() {
    listenerManager.notifyCacheSettings(
      queryCacheEnabled = configuration.enableDeprecatedQueryCaching,
      editCacheEnabled = cmd.cacheControlFlags.nodeActionSetCaching,
      queryCacheType = "CONTENT_SHA_HASH_FORMAT",
    )
  }

  // TODO(cnsun): need to add the coarse-grit latra reducer here.
  // Open so a subclass can substitute a different plan (e.g. a single pass of just the main reducer);
  // see MainReducerOnlyOnceProgramReductionDriver.
  protected open fun createReducerExecutionPlan(
    atomicMainReducerStep: AtomicReducerStep,
    cleanupReducerStep: AtomicReducerStep,
  ): ReducerExecutionPlan {
    // The built-in stages in EnumPipelineStage declaration (coarse-to-fine) order; an inactive stage is
    // still present, carrying a null step. The active LanguageProfile may reorder/drop these stages and
    // weave its own reducers (via createReductionStep) at any position; the default profile returns them
    // unchanged, leaving the core `perses` plan intact.
    val defaultPipeline =
      EnumPipelineStage.entries
        .map { stage ->
          LabeledPipelineStep(
            stage,
            buildBuiltinStage(stage, atomicMainReducerStep, cleanupReducerStep),
          )
        }.toImmutableList()
    // Wraps the given reducers as one medium-grit transformative step, skipping any reducer already
    // chosen as the main algorithm so it does not run twice; null when nothing is left to run.
    val createReductionStep: (ImmutableList<ReducerAnnotation>) -> AbstractExecutionPlanStep? =
      { reducers ->
        createExecutionPlanForLanguageSpecificTransformativeReducers(
          cleanupReducerStep = cleanupReducerStep,
          reducerAnnotations = reducers.filter { it != atomicMainReducerStep.reducer },
          overallFixpoint = true,
        )
      }
    val sequentialSteps =
      concatenate(
        languageProfile
          .customizeReductionPipeline(languageKind(), defaultPipeline, createReductionStep)
          .filterNotNull(),
      )
    val mainPlan =
      if (configuration.globalFixpoint) {
        ReducerExecutionPlan.makeSureToWrapWithFixpoint(sequentialSteps)
      } else {
        sequentialSteps
      }
    // C-Reduce refines the final result, so weave it in as the last step, after the global
    // fixpoint has converged. It runs only when the user asked for it on the command line.
    val creduceStep =
      CReduceReducerAnnotation(cmd.outputRefiningFlags.creduceCmd)
        .takeIf { cmd.outputRefiningFlags.callCReduce }
        ?.let { AtomicReducerStep(reducer = it) }
    return ReducerExecutionPlan(
      steps = concatenate(mainPlan, creduceStep),
    )
  }

  /**
   * Builds the execution-plan step for one built-in [stage], or null when that stage is inactive (e.g.
   * its reducers are disabled by a flag). Centralizing this in one exhaustive `when` keeps
   * [EnumPipelineStage] the single source of truth for the pipeline's stages and their order: there is
   * no parallel list of per-stage variables to drift, and adding a stage forces a branch here.
   */
  private fun buildBuiltinStage(
    stage: EnumPipelineStage,
    atomicMainReducerStep: AtomicReducerStep,
    cleanupReducerStep: AtomicReducerStep,
  ): AbstractExecutionPlanStep? =
    when (stage) {
      EnumPipelineStage.COARSE_GRIT_LATRA ->
        CoarseGritLatraReducerAnnotation
          .takeIf {
            cmd.latraFlags.enableLatra &&
              CoarseGritLatraReducerAnnotation.isLanguageSupported(languageKind())
          }?.let { AtomicReducerStep(reducer = it) }

      EnumPipelineStage.MAIN ->
        if (configuration.fixpointReductionForMainReducer) {
          if (atomicMainReducerStep.reducer == cleanupReducerStep.reducer) {
            fixpoint { atomicMainReducerStep }
          } else {
            concatenate(atomicMainReducerStep, fixpoint { cleanupReducerStep })
          }
        } else {
          atomicMainReducerStep
        }

      EnumPipelineStage.COARSE_GRIT -> buildCoarseGritStage(cleanupReducerStep)

      EnumPipelineStage.MEDIUM_GRIT_LPR ->
        createExecutionPlanForLanguageSpecificTransformativeReducers(
          cleanupReducerStep = cleanupReducerStep,
          reducerAnnotations =
            listOfNotNull(
              LlmBasedFunctionInliningReducer.META.takeIf { cmd.lprFlags.enableLPR },
              LlmBasedLoopUnrollingReducer.META.takeIf { cmd.lprFlags.enableLPR },
              LlmBasedDataTypeEliminationReducer.META.takeIf { cmd.lprFlags.enableLPR },
              LlmBasedDataTypeSimplificationReducer.META.takeIf { cmd.lprFlags.enableLPR },
              LlmBasedVariableEliminationReducer.META.takeIf { cmd.lprFlags.enableLPR },
            ).plus(
              cmd.experimentFlags.onDemandMediumGritReducerAnnotationClasses.map {
                reducerFactory.getReductionAlgorithm(it.name)
              },
            ),
          overallFixpoint = configuration.lprConfig.lprFixpoint,
        )

      EnumPipelineStage.MEDIUM_GRIT_LATRA ->
        createExecutionPlanForLanguageSpecificTransformativeReducers(
          cleanupReducerStep = cleanupReducerStep,
          reducerAnnotations =
            listOfNotNull(
              FineGritLatraReducerAnnotation.takeIf { cmd.latraFlags.enableLatra },
            ),
          overallFixpoint = cmd.latraFlags.enableFixpoint,
        )

      EnumPipelineStage.FINE_GRIT_VULCAN ->
        createExecutionPlanForFineGritReducers(
          cleanupReducerStep = cleanupReducerStep,
          reducerAnnotations =
            listOfNotNull(
              LocalExhaustivePatternReducer.META.takeIf { cmd.vulcanFlags.enableVulcan },
              IdentifierReplacementReducer.META.takeIf { cmd.vulcanFlags.enableVulcan },
              SubTreeReplacementReducer.META.takeIf { cmd.vulcanFlags.enableVulcan },
            ).plus(
              cmd.experimentFlags.onDemandFineGritReducerAnnotationClasses.map {
                reducerFactory.getReductionAlgorithm(it.name)
              },
            ),
          overallFixpoint = configuration.vulcanConfig.vulcanFixpoint,
        )

      EnumPipelineStage.FINE_GRIT_SFC ->
        createExecutionPlanForFineGritReducers(
          cleanupReducerStep = cleanupReducerStep,
          reducerAnnotations = sfcReducerAnnotations(),
          overallFixpoint = cmd.sfcFlags.enableFixpoint,
        )
    }

  /**
   * The auxiliary reducers of Figure 3 of the SFC paper, in its order: get rid of an identifier,
   * then replace a subtree with a smaller structure, then canonicalize.
   *
   * The paper's Identifier Elimination first renames the uses of an identifier onto another name,
   * which IdentifierReplacementReducer of Vulcan already does. It is listed here only when Vulcan
   * is off, so that enabling SFC brings the whole of that algorithm without running the same
   * reducer twice in one pipeline.
   */
  private fun sfcReducerAnnotations(): List<ReducerAnnotation> =
    if (!cmd.sfcFlags.enableSfc) {
      emptyList()
    } else {
      listOfNotNull(
        IdentifierReplacementReducer.META.takeIf { !cmd.vulcanFlags.enableVulcan },
        IdentifierUseEliminationReducer.META,
        SmallerStructureReplacementReducer.META,
        StructureCanonicalizationReducer.META,
      )
    }

  /** The [EnumPipelineStage.COARSE_GRIT] stage: the enabled coarse-grit slicers, t-rec, and any
   * on-demand coarse-grit reducers; null when none are enabled. */
  private fun buildCoarseGritStage(
    cleanupReducerStep: AtomicReducerStep,
  ): AbstractExecutionPlanStep? =
    createExecutionPlanForCoarseGritReducers(
      cleanupMainReducerStep = cleanupReducerStep,
      reducerAnnotations =
        listOfNotNull(
          // Finest-to-coarsest: the Dyck pass keeps delimiter nesting, so it runs before the
          // structure-blind Line slicer.
          PersesNodeReducerAnnotations.Dyck.takeIf { dyckPassEnabled },
          LineBasedConcurrentTokenSlicer.CompositeReducerAnnotation.takeIf { lineSlicerEnabled },
          NonSyntacticSingleTreeNodeReducer.META.takeIf {
            cmd.algorithmControlFlags.enableTreeSlicer
          },
          ConcurrentTokenSlicer.CompositeReducerAnnotation.takeIf {
            cmd.algorithmControlFlags.enableTokenSlicer
          },
          // t-rec does not further reduce tokens after vulcan, so run trec right after main
          if (cmd.trecFlags.enableTRec) {
            TokenCanonicalizer.META.takeUnless {
              configuration.canonicalParserFacade.lexerAtnWrapper.isATNEmpty().also { isEmpty ->
                if (isEmpty) {
                  logger.ktSevere {
                    val name = TokenCanonicalizer.META::class.qualifiedName
                    val parser = configuration.canonicalParserFacade::class.qualifiedName
                    "$name is disabled as the parser $parser has no ATN."
                  }
                }
              }
            }
          } else {
            null
          },
        ).plus(
          cmd.experimentFlags.onDemandCoarseGritReducerAnnotationClasses.map {
            reducerFactory.getReductionAlgorithm(it.name)
          },
        ),
    )

  private fun createExecutionPlanForCoarseGritReducers(
    cleanupMainReducerStep: AtomicReducerStep,
    reducerAnnotations: List<ReducerAnnotation>,
  ): AbstractExecutionPlanStep? {
    val reducers: ImmutableList<AbstractExecutionPlanStep> =
      reducerAnnotations
        .transformToImmutableList { reducer ->
          val condition =
            when (reducer.reductionResultSizeTrend) {
              ReducerAnnotation.ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE -> {
                ReducerExecutionPlan.AbstractCondition.ContinueOnSmallSize.INSTANCE
              }

              else -> {
                ContinueOnChange(
                  maxCountOfAllowedChanges = configuration.vulcanConfig.nonDeletionIterationLimit,
                )
              }
            }
          fixpoint(condition) {
            ifProgressed(reducer) {
              fixpoint { cleanupMainReducerStep }
            }
          }
        }
    return when (reducers.size) {
      0 -> null
      1 -> reducers.single()
      else -> ReducerExecutionPlan.UnconditionalSequentialSteps(reducers)
    }
  }

  private fun createExecutionPlanForLanguageSpecificTransformativeReducers(
    cleanupReducerStep: AtomicReducerStep,
    reducerAnnotations: List<ReducerAnnotation>,
    overallFixpoint: Boolean,
  ): AbstractExecutionPlanStep? {
    if (reducerAnnotations.isEmpty()) {
      return null
    }
    val reducers =
      reducerAnnotations.map {
        ifProgressed(it) {
          fixpoint { cleanupReducerStep }
        }
      }
    val concatenated = concatenate(reducers)
    return if (overallFixpoint) {
      fixpoint(ContinueOnChange(configuration.vulcanConfig.nonDeletionIterationLimit)) {
        concatenated
      }
    } else {
      concatenated
    }
  }

  private fun createExecutionPlanForFineGritReducers(
    cleanupReducerStep: AtomicReducerStep,
    reducerAnnotations: List<ReducerAnnotation>,
    overallFixpoint: Boolean,
  ): AbstractExecutionPlanStep? {
    if (reducerAnnotations.isEmpty()) {
      return null
    }
    val reducers =
      reducerAnnotations.map {
        fixpoint(ContinueOnChange(configuration.vulcanConfig.nonDeletionIterationLimit)) {
          ifProgressed(it) { cleanupReducerStep }
        }
      }
    val concatenated = concatenate(reducers)
    return if (overallFixpoint) {
      fixpoint { concatenated }
    } else {
      concatenated
    }
  }

  private fun internalReduce(
    reductionStartEvent: ReductionStartEvent,
    reducerExecutionPlan: ReducerExecutionPlan,
  ) {
    val reducerScheduler =
      ReducerScheduler(
        reducerExecutionPlan = reducerExecutionPlan,
        createReducers = { it.create(reducerContext) },
        reducerAnnotationOf = { it.reducerAnnotation },
        computeStatistics = this::computeStatistics,
        reducerRunner = { callReducer(reductionStartEvent, it) },
      )
    val minimalProgramSize =
      reducerScheduler
        .runAndGetGlobalMinimalProgramSize()
    val minimalSparTree = minimalProgramSize?.payload
    // Per-reducer statistics are no longer reported here, per driver: the scheduler lives for a
    // single internalReduce (one file, one sweep), so a summary printed here covers only that slice.
    // ReducerStatisticsSummaryListener aggregates the whole run instead, off the shared listener
    // manager, and prints once at onReductionEnd.
    if (minimalSparTree == null) {
      return
    }
    val bestTree = inputRepresentation.tree
    check(minimalSparTree.programSnapshot <= bestTree.programSnapshot) {
      """${minimalSparTree.programSnapshot}
        |${bestTree.programSnapshot}
        |
        |${minimalSparTree.printTreeStructure()}
        |
        |${bestTree.printTreeStructure()}
      """.trimMargin()
    }
    if (minimalSparTree.programSnapshot < bestTree.programSnapshot) {
      val minimalSize = minimalSparTree.programSnapshot
      callReducer(
        reductionStartEvent,
        SparTreeRootReplacementReducer(
          reducerContext = reducerContext,
          newRootNode = minimalSparTree.detachRootFromTree(),
          canonicalTokenCount = minimalSize.canonicalTokenCount,
        ),
      )
    }
  }

  // The canonical token count comes from inputRepresentation.tree.programSnapshot, which the
  // reducers keep correct by deriving it from the output manager on every applied edit (see
  // AbstractSparTreeReducer.computeCanonicalTokenCount). It is therefore a stable, correct function of
  // the program and does not need to be re-derived from the saved file here.
  private fun computeStatistics(): StatsOfFilesBeingReduced =
    StatsOfFilesBeingReduced(
      size = inputRepresentation.tree.programSnapshot.withoutPayload(),
      fileContents =
        ioManager.readAndTrimAllBestFiles().transformToImmutableList {
          StatsOfFilesBeingReduced.FileNameAndContentDigestPair(
            it.fileName,
            configuration.shaHashAlgorithm.createFromString(it.computeFileContent()),
          )
        },
    )

  /**
   * Rebuilds the [InputRepresentation] by re-parsing the best main file with [surrogateParserFacade]
   * (reusing [specifiedSparTreeNodeFactory] when one is given). Returns null if the program is not
   * parsable by that facade, leaving it to the caller to decide how to handle the failure -- skip
   * the reducer, or keep the current spar-tree.
   *
   * TODO(cnsun): the siblings are frozen for this driver's whole run, yet every rebuild re-reads
   *  them from the result folder and re-measures them. Reuse the current representation's sized
   *  sibling map instead.
   */
  private fun buildInputRepresentationFromBestMainFile(
    surrogateParserFacade: AbstractParserFacade,
    specifiedSparTreeNodeFactory: SparTreeNodeFactory?,
    errorMode: ParseErrorHandling = ParseErrorHandling.STRICT,
  ): InputRepresentation? =
    try {
      createInputRepresentation(
        sourceFile = ioManager.resultFolder.computeAbsPathForOrigFile(mainFile),
        fileRepresentedByTree = mainFile,
        otherMutableFileContents =
          ioManager.resultFolder.readLiveMutableFileContents(excluding = mainFile),
        surrogateParserFacade = surrogateParserFacade,
        canonicalParserFacade = configuration.canonicalParserFacade,
        specifiedSparTreeNodeFactory = specifiedSparTreeNodeFactory,
        semanticsProviderCreator = configuration.mimirConfig.semanticsProviderCreator,
        enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
        originalReductionInputs = ioManager.originalReductionInputs,
        errorMode = errorMode,
      )
    } catch (_: AntlrFailureException) {
      null
    }

  private fun rebuildSparTreeIfDirty(reductionStartEvent: ReductionStartEvent) {
    val message = StringBuilder("Rebuilding spar-tree: ")
    val oldSparTree = inputRepresentation.tree
    if (!oldSparTree.dirty) {
      message.append("The spartree is not dirty, and thus the rebuilding is skipped.")
    } else {
      val rebuilt =
        buildInputRepresentationFromBestMainFile(
          surrogateParserFacade = oldSparTree.sparTreeNodeFactory.parserFacade,
          specifiedSparTreeNodeFactory = oldSparTree.sparTreeNodeFactory,
        )
      if (rebuilt != null) {
        rebuilt.tree.copyListenersFrom(oldSparTree)
        inputRepresentation = rebuilt
        message.append("The spartree is rebuilt.")
      } else {
        // The program is not parsable by the current parser facade; keep reducing the current
        // spar-tree.
        message.append("The program is not parsable; the current spar-tree is kept.")
      }
    }
    listenerManager.onAdHocMessageEvent(
      reductionStartEvent.createAdHocMessageEvent(
        perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
        prefixLabelFromRootToHere = "",
        messageComputer = { message },
      ),
    )
  }

  // The Dyck pass reparses under a Dyck grammar and deletes balanced delimiter groups the real
  // grammar cannot place; gated auto/on/off via [passScheduled].
  private val dyckPassEnabled: Boolean
    get() = passScheduled(cmd.experimentFlags.dyckNodeReducer)

  // Same auto/on/off gating as the Dyck pass, plus a format guard: the line slicer needs each source
  // line kept intact, so it is soft-disabled (not scheduled) under SINGLE_TOKEN_PER_LINE regardless of
  // the flag. A getter (not a construction-time val) so `auto` reads the current tree's parse state.
  private val lineSlicerEnabled: Boolean
    get() {
      if (!passScheduled(cmd.algorithmControlFlags.lineSlicer)) {
        return false
      }
      val programFormat = activeOutputManagerFactory.defaultCodeFormatControl
      if (programFormat == EnumFormatControl.SINGLE_TOKEN_PER_LINE) {
        logger.ktWarning {
          "The program format is $programFormat, " +
            "incompatible with line slicer. Line slicer is disabled."
        }
        return false
      }
      return true
    }

  // auto runs the pass only when the file did not parse under its real grammar (its current tree was
  // recovered by tolerant parsing) -- exactly where a coarser grammar adds value; on always; off never.
  // Read off the current tree rather than a construction-time snapshot, so a mid-reduction reparse
  // keeps it accurate. Only consulted at plan-build time, by which point inputRepresentation is set.
  // See internal_doc/error_tolerant_multi_grammar_passes.md.
  private fun passScheduled(mode: EnumPassMode): Boolean =
    when (mode) {
      EnumPassMode.OFF -> false
      EnumPassMode.ON -> true
      EnumPassMode.AUTO -> inputRepresentation.tree.hasSyntaxErrors
    }

  /**
   * @return the result of the reducer pass.
   */
  protected fun callReducer(
    reductionStartEvent: ReductionStartEvent,
    reducer: AbstractSparTreeReducer,
  ): ReducerResult {
    val reducerName = reducer.reducerAnnotation.shortName
    val preferredParserFacade = reducer.getPreferredParserFacade()
    val targetParserFacade = preferredParserFacade ?: configuration.canonicalParserFacade
    if (cmd.cacheControlFlags.enablePassCache &&
      reducer.reducerAnnotation.deterministic &&
      updatePassLevelCache(reducer.reducerAnnotation, targetParserFacade.javaClass) ==
      PassLevelCacheResult.EXISTING_ALREADY
    ) {
      listenerManager.onAdHocMessageEvent(
        reductionStartEvent.createAdHocMessageEvent(
          perFileSizeMetrics = reductionStartEvent.perFileSizeMetrics,
          prefixLabelFromRootToHere = "",
          messageComputer = {
            "[Pass Caching]: The reducer $reducerName is skipped, " +
              "because the input has been reduced the reducer by before and" +
              "the input has not changed."
          },
        ),
      )
      return ReducerResult.Skipped
    }
    val currentParserFacade = inputRepresentation.tree.sparTreeNodeFactory.parserFacade
    if (currentParserFacade::class != targetParserFacade::class) {
      // The reducer prefers a parser facade different from the current one; rebuild the
      // spar-tree with the preferred facade.
      val newRepresentation =
        reducerContext.inputRepresentationCreator(preferredParserFacade)
          ?: run {
            // The current program was produced by a reducer that uses a different (surrogate)
            // parser facade -- e.g. the line slicer's LineParserFacade -- and the resulting program
            // is not parsable by this reducer's preferred facade. This reducer therefore cannot run
            // on it, so skip it gracefully and keep the current representation, instead of failing
            // with a parse exception.
            listenerManager.onAdHocMessageEvent(
              reductionStartEvent.createAdHocMessageEvent(
                perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
                prefixLabelFromRootToHere = "",
                messageComputer = {
                  "The reducer $reducerName is skipped, because the current program is not " +
                    "parsable by its preferred parser facade ${targetParserFacade::class.simpleName}."
                },
              ),
            )
            return ReducerResult.Skipped
          }
      newRepresentation.tree.copyListenersFrom(inputRepresentation.tree)
      inputRepresentation = newRepresentation
    } else if (cmd.algorithmControlFlags.rebuildParseTreeEachIteration) {
      // Rebuilding is necessary, to hop over different production rules.
      rebuildSparTreeIfDirty(reductionStartEvent)
    }
    if (!inputRepresentation.tree.hasRealRoot()) {
      // The file has been reduced to fully empty (only the sentinel root remains), so there is
      // nothing to reduce. Skip the whole per-file step here, before simplifySparTree() below and
      // the end-of-method deepCopy() -- both of which access realRoot and would otherwise throw
      // "This tree is empty and does not have a root". This happens in multi-file reduction once a
      // dependency file has been emptied and is awaiting whole-file deletion.
      listenerManager.onAdHocMessageEvent(
        reductionStartEvent.createAdHocMessageEvent(
          perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
          prefixLabelFromRootToHere = "",
          messageComputer = {
            "The reducer $reducerName skips " +
              "${inputRepresentation.fileRepresentedByTree.baseName}: " +
              "the spar-tree is empty (the file was reduced to nothing)."
          },
        ),
      )
      return ReducerResult.Skipped
    }
    check(inputRepresentation.tree.hasTheSameEditListeners(sparTreeEditListeners))
    inputRepresentation.simplifySparTree()
    ensureInterestingCodeFormatOrThrow(reductionStartEvent, reducerName)
    val fixpointIterationStartEvent =
      reductionStartEvent.nextFixpointIteration(
        perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
        reducerClass = reducer.reducerAnnotation,
        treeStructureDumper = {
          WeakReference(inputRepresentation.tree).get()?.printTreeStructure() ?: ""
        },
        testScriptStatistics = executorService.statistics.createSnapshot(),
        // The facade this iteration actually reduces with -- which a reducer may switch from the
        // canonical one (e.g. the line slicer's surrogate facade), so it is reported per iteration.
        extraData =
          "Parser Facade: ${inputRepresentation.tree.sparTreeNodeFactory.parserFacade::class}",
      )
    listenerManager.onFixpointIterationStart(fixpointIterationStartEvent)
    val reductionState = FixpointReductionState(fixpointIterationStartEvent, inputRepresentation)
    val loggingListener = createLoggingListener(reductionState)
    var exception: Exception? = null
    try {
      inputRepresentation.tree.registerSparTreeEditListener(loggingListener)
      reducer.reduce(reductionState)
    } catch (e: Exception) {
      // TODO(cnsun): need to dump the stack trace to a special file.
      e.printStackTrace()
      listenerManager.onCriticalException(e)
      exception = e
    } finally {
      inputRepresentation.tree.removeSparTreeEditListener(loggingListener)
    }
    listenerManager.onFixpointIterationEnd(
      fixpointIterationStartEvent.createEndEvent(
        currentTimeMillis = System.currentTimeMillis(),
        perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
        testScriptStatistics = executorService.statistics.createSnapshot(),
      ),
    )
    val treeCopy =
      inputRepresentation
        .tree
        .deepCopy(AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy)
        .result
    val size = treeCopy.programSnapshot
    return ReducerResult.Reduced(size.withNewPayload(treeCopy), exception)
  }

  /**
   * The Layer-2 sanity check for the per-file (spar-tree) stack: output the spar-tree the reducer is
   * about to mutate and verify the program still passes the property test.
   *
   * Adaptive code-format selection. The program reconstructed from the input representation is not
   * guaranteed to pass the test under the active code format (a different format prints it
   * differently -- e.g. SINGLE_TOKEN_PER_LINE splitting `<<` into `< <`, which does not compile). So
   * when the active format fails, search the facade's other allowed code formats
   * ([org.perses.program.LanguageKind.allowedCodeFormatControl]) for one under which the program IS
   * interesting, and -- if found -- **adopt** it for the rest of the reduction: every subsequent
   * render (this reducer's candidate tests and [saveBestProgram]) then uses the working format. A
   * warning is emitted, so a user-specified format that does not work is corrected on the fly rather
   * than aborting. Only if no allowed format works is the reduction stopped.
   *
   * A code format is carried by the output-manager *factory*, so adopting a format = switching the IO
   * manager's active factory to an immutable sibling
   * ([AbstractTokenOutputManagerFactory.cloneWithCodeFormat]); no factory is mutated in place.
   */
  private fun ensureInterestingCodeFormatOrThrow(
    reductionStartEvent: ReductionStartEvent,
    reducerName: String,
  ) {
    val program = inputRepresentation.tree.programSnapshot.payload
    val activeFactory = activeOutputManagerFactory
    if (testProgramWith(program, activeFactory)) {
      return
    }
    val facade = inputRepresentation.tree.sparTreeNodeFactory.parserFacade
    val workingFactory = findInterestingFactory(program, facade, activeFactory)
    if (workingFactory != null) {
      listenerManager.onAdHocMessageEvent(
        reductionStartEvent.createAdHocMessageEvent(
          perFileSizeMetrics = inputRepresentation.computePerFileSizeMetrics(),
          prefixLabelFromRootToHere = "",
          messageComputer = {
            "The code format ${activeFactory.defaultCodeFormatControl} does not pass " +
              "the property test for the program before reducer '$reducerName'. " +
              "Switching to ${workingFactory.defaultCodeFormatControl} " +
              "(an allowed format of ${facade.language}) under which the program is " +
              "interesting, for the rest of the reduction."
          },
        ),
      )
      activeOutputManagerFactory = workingFactory
      return
    }
    throw SanityCheckFailedException(
      "The per-reducer sanity check failed before running '$reducerName': the program " +
        "reconstructed from the current input representation is not interesting under any " +
        "allowed code format (${facade.language.allowedCodeFormatControl}); the reduction stops.",
    )
  }

  /** Whether [program], output by [factory] (which carries the code format), passes the property
   * test. Follows the [org.perses.reduction.AbstractWholeProgramReducer.testProgram] convention:
   * the returned Boolean is the interestingness of the program. */
  private fun testProgramWith(
    program: TokenizedProgram,
    factory: AbstractTokenOutputManagerFactory,
  ): Boolean =
    executorService
      .testProgramAsyncWithoutPayload(
        preCheck = TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
        postCheck = TestScriptExecutorService.IDENTITY_POST_CHECK,
        factory.createManagerFor(program),
      ).getWithTimeoutWarnings()
      .isInteresting

  /**
   * Find a sibling of [currentFactory] -- in a different code format -- under which [program] (parsed
   * by [facade]) passes the property test. Candidate formats are the facade's
   * [org.perses.program.LanguageKind.allowedCodeFormatControl] (the language is the source of truth
   * for valid formats), tried default-first and excluding the active format (already found failing).
   * Formats the factory cannot produce a sibling for are skipped. Returns null if none pass.
   */
  private fun findInterestingFactory(
    program: TokenizedProgram,
    facade: AbstractParserFacade,
    currentFactory: AbstractTokenOutputManagerFactory,
  ): AbstractTokenOutputManagerFactory? {
    val language = facade.language
    val activeFormat = currentFactory.defaultCodeFormatControl
    val candidates =
      (listOf(language.defaultCodeFormatControl) + language.allowedCodeFormatControl)
        .distinct()
        .filter { it != activeFormat }
    return candidates.firstNotNullOfOrNull { format ->
      currentFactory.cloneWithCodeFormat(format)?.takeIf { testProgramWith(program, it) }
    }
  }

  private fun createLoggingListener(reductionState: FixpointReductionState) =
    object : AbstractSparTreeEditListener() {
      override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
        reducerContext.listenerManager.onBestProgramUpdated(
          reductionState.fixpointIterationStartEvent.createBestProgramUpdatedEvent(
            currentTimeMillis = System.currentTimeMillis(),
            perFileSizeMetrics = reductionState.inputRepresentation.computePerFileSizeMetrics(),
            programSizeBefore = event.programSizeBefore,
            programSizeAfter = event.programSizeAfter,
            appliedEdit = event.edit,
          ),
        )
      }
    }

  private val passLevelCache = PassLevelCache()

  /** The single mutable file this driver reduces (the file the current [inputRepresentation]'s tree
   * represents). */
  private val fileUnderReduction get() = inputRepresentation.fileRepresentedByTree

  private fun updatePassLevelCache(
    reducerAnnotation: ReducerAnnotation,
    reducerParserFacadeClass: Class<*>,
  ): PassLevelCacheResult =
    passLevelCache.update(
      reducerAnnotation,
      // The grammar this reducer will run under (its preferred facade, or the canonical one) is part
      // of the key so the same (reducer, content) reduced under a different grammar is not skipped as
      // already-done. Keyed on the reducer's own facade -- not the current tree's, which is whatever
      // the previous reducer left and would vary with execution order.
      reducerParserFacadeClass,
    ) {
      activeOutputManagerFactory
        .createManagerFor(inputRepresentation.tree.programSnapshot.payload)
        .shaHashCode
    }

  private fun languageKind() = configuration.canonicalParserFacade.language

  override fun close() {
    // trigger the cache to do some profiling work, before profile is closed.
    queryCache.triggerHeartBeat()
    super.close()
  }

  open fun createMainReducerCreator(): ReducerAnnotation =
    resolveReducerAnnotation(configuration.mainReducerAnnotation)

  protected fun createCleanupReducerCreator(): ReducerAnnotation? =
    configuration.cleanupReducerAnnotation?.let(::resolveReducerAnnotation)

  private fun resolveReducerAnnotation(nameAndDesc: AbstractReducerNameAndDesc): ReducerAnnotation =
    nameAndDesc as? ReducerAnnotation
      ?: reducerFactory.getReductionAlgorithm(nameAndDesc.shortName)

  /**
   * The writer RECORD mode records through, or null on the normal path. Built per driver -- the
   * flags and the output directory are the same for all of them -- but sharing the reduction's
   * problem counter, which is the one piece that must not restart per file.
   */
  private fun createListMinimizationMicrobenchmarkWriterOrNull():
    ListMinimizationMicrobenchmarkWriter? {
    val flags = cmd.listMinimizerMicrobenchmarkingFlags
    if (flags.mode != EnumListMinimizerMicrobenchmarkingMode.RECORD) {
      return null
    }
    return ListMinimizationMicrobenchmarkWriter(
      rootDirectory =
        FileSystemUtil.ensureDirExists(
          checkNotNull(flags.microbenchmarkOutputDirectory) {
            "The problem output directory is null."
          },
        ),
      underlyingLexerClass = configuration.canonicalParserFacade.realLexerClass,
      minListSizeToRecord = flags.minListSizeToRecord,
      maxMicrobenchmarksToRecord = flags.maxMicrobenchmarksToRecord,
      microbenchmarkIdGenerator = globalContext.listMinimizationProblemIdGenerator,
      // The same rendering AbstractMain puts on the reduction start event: the options
      // serialized with paths reduced to their basenames, so a recording made on one machine
      // does not carry that machine's directory layout into the corpus.
      commandLineOptions = reductionStartEvent.commandLineOptions,
    )
  }

  /**
   * The listener every list minimizer this driver runs reports to. Overridable so a driver that
   * measures minimizers can combine its own collector with the human-readable trace, rather than
   * having to rebuild the arguments the reducers construct.
   */
  protected open fun createListMinimizerListener(): AbstractListMinimizerListener =
    if (cmd.profilingFlags.profileListMinimizer == null) {
      NullListMinimizerListener
    } else {
      registerToClose(ListMinimizerProgressListener(cmd.profilingFlags.profileListMinimizer!!))
    }

  internal val reducerContext by lazy {
    ReducerContext(
      ioManager = ioManager,
      configuration = configuration,
      executorService = executorService,
      fileUnderReduction = fileUnderReduction,
      perFileSizeMetricsSupplier = { inputRepresentation.computePerFileSizeMetrics() },
      listenerManager = listenerManager,
      queryCache = queryCache,
      globalQueryCache = globalContext.globalExecutionCache,
      actionSetProfiler = actionSetProfiler,
      sparTreeNodeFactory = inputRepresentation.tree.sparTreeNodeFactory,
      listMinimizerListener = createListMinimizerListener(),
      listMinimizationMicrobenchmarkWriter = createListMinimizationMicrobenchmarkWriterOrNull(),
      inputRepresentationCreator = { preferredParserFacade ->
        // Only the Dyck reparse is tolerant, so an unbalanced program still yields a Dyck tree to
        // reduce instead of throwing and being skipped. Every other preferred facade stays STRICT:
        // for a real-grammar facade (e.g. FineGritLatraReducer's), a failed strict parse is the
        // signal that the reducer cannot run on the current (surrogate-produced) program and must be
        // skipped -- a tolerant parse would wrongly let it proceed on an invalid tree.
        val errorMode =
          if (preferredParserFacade is AbstractDyckParserFacade) {
            ParseErrorHandling.TOLERANT
          } else {
            ParseErrorHandling.STRICT
          }
        buildInputRepresentationFromBestMainFile(
          surrogateParserFacade = preferredParserFacade ?: configuration.canonicalParserFacade,
          specifiedSparTreeNodeFactory = null,
          errorMode = errorMode,
        )
      },
      outputManagerFactoryProvider = { activeOutputManagerFactory },
    )
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    private fun createSparTreeEditListeners(
      ioManager: TokenReductionIOManager,
      renderBestProgram: (TokenizedProgram) -> AbstractOutputManager,
      queryCache: AbstractQueryCache,
      perFileSizeMetricsSupplier: () -> PerFileSizeMetrics,
      listenerManager: AsyncReductionListenerManager,
    ): ImmutableList<AbstractSparTreeEditListener> {
      val builder =
        ImmutableList
          .builder<AbstractSparTreeEditListener>()
          .add(
            object : AbstractSparTreeEditListener() {
              override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
                ioManager.saveBestProgram(renderBestProgram(event.program))
              }
            },
          ).add(
            object : AbstractSparTreeEditListener() {
              override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
                val sizeBefore = queryCache.cacheSize()
                queryCache.evictEntriesNotSmallerThan(
                  perFileSizeMetricsSupplier().perFileNonBlankCharacterCounts(),
                )
                val sizeAfter = queryCache.cacheSize()
                listenerManager.onTestScriptExecutionCacheEntryEviction(sizeBefore, sizeAfter)
              }
            },
          ).add(
            object : AbstractSparTreeEditListener() {
              override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
                listenerManager.onNodeActionSetClearance(event.cacheSizeBeforeClearance)
              }
            },
          )
      return builder.build()
    }

    internal fun createInputRepresentation(
      sourceFile: Path,
      fileRepresentedByTree: AbstractReductionFile<*, *>,
      otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
      surrogateParserFacade: AbstractParserFacade,
      canonicalParserFacade: AbstractParserFacade,
      specifiedSparTreeNodeFactory: SparTreeNodeFactory?,
      semanticsProviderCreator: ISemanticsProviderCreator?,
      enableNodeActionSetCache: Boolean = false,
      /** The whole mutable-file set this representation belongs to. */
      originalReductionInputs: AbstractOriginalReductionInputs,
      /**
       * How to handle a parse error while (re)building the tree. STRICT throws (the caller then skips
       * or falls back); TOLERANT recovers the tree with error-node leaves, which the Dyck reparse
       * needs so an unbalanced program still yields a tree to reduce instead of being skipped.
       */
      errorMode: ParseErrorHandling = ParseErrorHandling.STRICT,
    ): InputRepresentation {
      val originalSourceCode = sourceFile.readText()
      val sparTree =
        SparTreeParserUtility.buildSparTree(
          sourceCode = originalSourceCode,
          parserFacade = surrogateParserFacade,
          specifiedSparTreeNodeFactory = specifiedSparTreeNodeFactory,
          simplifyTree = true,
          canonicalTokenCountComputer = {
            if (surrogateParserFacade::class != canonicalParserFacade::class) {
              // countTokensInString tolerates lexer errors. It used to be strict, and the canonical
              // facade is the real grammar, so for a program that does not lex under it -- a stray
              // `@`, a `#` from a surviving preprocessor directive, a `\` line-continuation -- it
              // threw. That exception escaped as "the current program is not parsable by its
              // preferred parser facade" and skipped the very reducer the tolerant fallback exists
              // to run: the Dyck tree itself parses fine, only its canonical size could not be
              // measured. See //test/org/perses/benchmark_toys/c_unlexable_char_blocks_dyck.
              canonicalParserFacade.countTokensInString(originalSourceCode)
            } else {
              null
            }
          },
          enableNodeActionSetCache = enableNodeActionSetCache,
          errorMode = errorMode,
          precomputedParseTree =
            originalReductionInputs.retrieveCachedOriginalParseTreeOrNull(
              fileRepresentedByTree,
              originalSourceCode,
              surrogateParserFacade,
            ),
        )
      // Compute the semantics synchronously, here, rather than asynchronously while the driver runs.
      // The semantics provider analyzes [sourceFile] on disk (e.g. mimir runs clangd/javac on it) and
      // maps the result onto [sparTree] *by token position*, so it must see the exact bytes the tree
      // was parsed from ([originalSourceCode], which is [sourceFile]'s current content). Reducing the
      // file rewrites [sourceFile] (saveBestProgram re-renders it, changing token positions), so a
      // background computation would race that rewrite: read the original and the positions line up
      // (full def-use graph), read the re-rendered file and they do not (edges silently dropped),
      // yielding a different -- and machine-timing-dependent -- reduction. Computing it now, before
      // any reduction write, ties it to the matching content and makes the result deterministic.
      // Null creator (every non-mimir reduction) makes this a no-op.
      val semanticsProvider: ISemanticsProvider? =
        semanticsProviderCreator?.computeSemanticsForSparTree(
          sourceFilePath = sourceFile,
          sparTree = sparTree,
        )
      // Each sibling's size is lexed with that sibling's own canonical facade (mixed-language sets
      // may resolve siblings to different facades) from the same in-memory content the
      // representation carries (NOT re-read from the sibling's path, which may be stale with respect
      // to the result folder), so the size and the content cannot disagree.
      val sizedOtherMutableFileContents =
        otherMutableFileContents.entries
          .map { (file, content) ->
            val siblingFacade = originalReductionInputs.getCanonicalParserFacade(file)
            file to siblingFacade.computeProgramSizeOf(content).withNewPayload(content)
          }.toImmutableMap()
      return InputRepresentation(
        originalReductionInputs = originalReductionInputs,
        tree = sparTree,
        fileRepresentedByTree = fileRepresentedByTree,
        otherMutableFileContents = sizedOtherMutableFileContents,
        semantics = semanticsProvider,
      )
    }

    @JvmStatic
    fun createInputRepresentation(
      fileToReduce: SourceFile,
      parserFacade: AbstractParserFacade,
      hideTimeStampsInLog: Boolean,
      semanticsProviderCreator: ISemanticsProviderCreator?,
      enableNodeActionSetCache: Boolean = false,
      originalReductionInputs: AbstractOriginalReductionInputs,
    ): InputRepresentation {
      val timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis())
      logger.ktFine {
        "Tree Building: Start building spar-tree from input file ${fileToReduce.file.name}"
      }
      // This needs to be enabled, once isInputCompletelyConsumed support the Python grammar.
      // lazyAssert { parseTree.isInputCompletelyConsumed() }
      val sparTreeWithSemantics =
        createInputRepresentation(
          sourceFile = fileToReduce.file,
          fileRepresentedByTree = fileToReduce,
          // This overload only serves ppr (seed/variant trees), whose output managers derive both
          // mutable files from the diff, so no sibling content is carried; the sibling slots of
          // the size metrics are lexed from the sibling files' own content.
          otherMutableFileContents = ImmutableMap.of(),
          surrogateParserFacade = parserFacade,
          canonicalParserFacade = parserFacade,
          specifiedSparTreeNodeFactory =
            SparTreeNodeFactory(parserFacade),
          semanticsProviderCreator = semanticsProviderCreator,
          enableNodeActionSetCache = enableNodeActionSetCache,
          originalReductionInputs = originalReductionInputs,
        )

      val time =
        if (hideTimeStampsInLog) {
          "<time hidden>"
        } else {
          timeSpanBuilder.end(System.currentTimeMillis()).formattedElapsedTime
        }
      logger.ktFine { "Tree Building: Finished in $time" }
      return sparTreeWithSemantics
    }

    @JvmStatic
    @VisibleForTesting
    fun createConfiguration(
      cmd: PersesCommandOptions,
      parserFacade: AbstractParserFacade,
      defaultProgramFormat: EnumFormatControl,
      reducerFactory: ReducerFactory = ReducerFactory.DEFAULT,
    ): ReductionConfiguration {
      val mimirFlags = cmd.mimirFlags
      val mainReducerAnnotation =
        reducerFactory.getReductionAlgorithm(
          cmd.algorithmControlFlags.mainReductionAlgorithm.let { algName ->
            algName ?: PersesNodeReducerAnnotations.PrioritizedDfs.shortName
          },
        )
      val cleanupReducerAnnotation =
        cmd.algorithmControlFlags.cleanupReductionAlgorithm?.let { algorithm ->
          reducerFactory.getReductionAlgorithm(algorithm)
        }
      return ReductionConfiguration(
        globalFixpoint = cmd.reductionControlFlags.globalFixpoint,
        mainReducerAnnotation = mainReducerAnnotation,
        cleanupReducerAnnotation = cleanupReducerAnnotation,
        fixpointReductionForMainReducer = cmd.reductionControlFlags.fixpointForMainReducer,
        enableDeprecatedQueryCaching = cmd.cacheControlFlags.queryCaching,
        fullyDeterministicMode = cmd.verbosityFlags.fullyDeterministicMode,
        numOfReductionThreads = cmd.reductionControlFlags.getNumOfThreads(),
        canonicalParserFacade = parserFacade,
        persesConfig =
          cmd.persesFlags.let {
            ReductionConfiguration.PersesConfig(
              enableTopDownReduction = it.enableTopDownReduction,
              enableReducingRegularRuleNode = it.enableReductionOnRegularNodes,
              enableReducingKleeneOptionalNode = it.enableReductionOnKleeneAndOptionalNodes,
              maxEditCountForRegularRuleNode = it.maxEditCountForRegularRuleNode,
              maxBfsDepthForRegularRuleNode = it.maxBfsDepthForRegularRuleNode,
              stopAtFirstCompatibleChildren =
                it.stopAtFirstCompatibleChildForRegularRuleNode,
              enableLiteralReplacementForListMinimizer =
                it.enableLiteralReplacementForListMinimizer,
              enableLiteralReplacementForRegularRuleNode =
                it.enableLiteralReplacementForRegularRuleNode,
              listMinimizerTypeForKleene = it.listMinimizerTypeForKleene,
              anticipatedFinalTokenCount = it.anticipatedTokenCountInResult,
            )
          },
        listMinimizerConfig =
          cmd.algorithmControlFlags.let {
            ReductionConfiguration.ListMinimizerConfig(
              minSlidingWindowSize = it.minSlicingWindowSize,
              maxSlidingWindowSize = it.maxSlicingWindowSize,
            )
          },
        vulcanConfig =
          cmd.vulcanFlags.let {
            ReductionConfiguration.VulcanConfig(
              nonDeletionIterationLimit = it.nonDeletionIterationLimit,
              windowSizeForLocalExhaustivePatternReduction = it.windowSize,
              vulcanFixpoint = it.vulcanFixpoint,
            )
          },
        lprConfig =
          ReductionConfiguration.LPRConfig(
            llmClientPath = cmd.lprFlags.llmClientPath,
            lprFixpoint = cmd.lprFlags.lprFixpoint,
          ),
        latraConfig =
          ReductionConfiguration.LatraConfig(
            listMinimizerForTransformations = cmd.latraFlags.transformationListMinimizer,
          ),
        sfcConfig =
          ReductionConfiguration.SfcConfig(
            subtreeTokenCountLimit = cmd.sfcFlags.subtreeTokenCountLimit,
            candidateLimit = cmd.sfcFlags.candidateLimit,
          ),
        levelBasedReducerConfig =
          cmd.algorithmControlFlags.let {
            ReductionConfiguration.LevelBasedReducerConfig(
              defaultListMinimizerType = it.defaultListMinimizerTypeForHDD,
            )
          },
        mimirConfig =
          ReductionConfiguration.MimirConfig(
            semanticsProviderCreator =
              createSemanticsProviderCreator(
                enableMimir = computeWhetherToEnableMimir(mainReducerAnnotation),
                mimirFlagGroup = mimirFlags,
                languageKind = parserFacade.language,
              ),
            nodeCountThresholdToUseOneByOne = mimirFlags.nodeCountThresholdToUseOneByOne,
            enableBottomUpReductionAfterMainReductionLoop =
              mimirFlags.enableBottomUpReductionAfterMainReductionLoop,
            bottomUpReductionMaxDepth = mimirFlags.bottomUpReductionMaxDepth,
            mimirReductionAlgorithm = mimirFlags.mimirReductionAlgorithm,
            enableMimirForRegularRuleNodes = mimirFlags.enableMimirForRegularNode,
            deleteDefWithAllItsConcreteUses = mimirFlags.enableMimirDeleteDefWithAllItsConcreteUses,
          ),
        shaHashAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
      )
    }

    private fun computeWhetherToEnableMimir(mainReducerAnnotation: ReducerAnnotation): Boolean =
      mainReducerAnnotation == PersesNodeReducerAnnotations.Mimir ||
        mainReducerAnnotation == HDDReducerAnnotations.HddWithMimir

    internal fun createSemanticsProviderCreator(
      enableMimir: Boolean,
      mimirFlagGroup: MimirFlagGroup,
      languageKind: LanguageKind,
    ): ISemanticsProviderCreator? {
      if (!enableMimir) {
        return null
      }
      return when (languageKind) {
        LanguageC ->
          MimirSemanticsProviderCreator(ShellCommandOnPath(mimirFlagGroup.cLanguageServerCmd))

        LanguageJava -> {
          if (mimirFlagGroup.javaLanguageServerCmd?.lowercase() == "javac") {
            MimirJavacSemanticProviderCreator()
          } else {
            MimirSemanticsProviderCreator(
              ShellCommandOnPath(mimirFlagGroup.javaLanguageServerCmd!!),
            )
          }
        }

        else -> null
      }
    }
  }
}

fun TestScriptExecutorService.Statistics.createSnapshot() =
  TestScriptExecutorServiceStatisticsSnapshot(
    scriptExecutionNumber = this.scriptExecutionNumber,
    externalCacheHitNumber = this.externalCacheHitNumber,
  )

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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.CommandOptions
import org.perses.cmd.ExperimentFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.AbstractListInputMinimizerListener
import org.perses.listminimizer.ListInputMinimizerProgressListener
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractActionSetProfiler.ActionSetProfiler
import org.perses.reduction.AbstractExternalTestScriptExecutionCachePolicy.ExternalTestScriptExecutionCachePolicy
import org.perses.reduction.AbstractExternalTestScriptExecutionCachePolicy.NullExternalTestScriptExecutionCachePolicy
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.cache.AbstractQueryCacheProfiler
import org.perses.reduction.cache.EnumQueryCachingControl
import org.perses.reduction.cache.NullQueryCache
import org.perses.reduction.cache.PassLevelCache
import org.perses.reduction.cache.PassLevelCache.PassLevelCacheResult
import org.perses.reduction.cache.QueryCacheConfiguration
import org.perses.reduction.cache.QueryCacheFactory
import org.perses.reduction.cache.QueryCacheMemoryProfiler
import org.perses.reduction.cache.QueryCacheTimeCsvProfiler
import org.perses.reduction.cache.QueryCacheTimeProfiler
import org.perses.reduction.cache.QueryCacheType
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.SanityCheckEvent
import org.perses.reduction.event.TestScriptExecutorServiceStatisticsSnapshot
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.reduction.reducer.TreeSlicer
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.reduction.reducer.token.LineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.trec.TokenCanonicalizer
import org.perses.reduction.reducer.vulcan.IdentifierReplacementReducer
import org.perses.reduction.reducer.vulcan.SubTreeReplacementReducer
import org.perses.reduction.reducer.vulcan.pattern.LocalExhaustivePatternReducer
import org.perses.spartree.AbstractNodeActionSetCache
import org.perses.spartree.AbstractSparTreeEditListener
import org.perses.spartree.NodeActionSetCache
import org.perses.spartree.NullNodeActionSetCache
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.TimeSpan
import org.perses.util.TimeUtil
import org.perses.util.Util
import org.perses.util.YamlUtil
import org.perses.util.ktFine
import org.perses.util.ktInfo
import org.perses.util.ktSevere
import org.perses.util.ktWarning
import org.perses.util.shell.Shells
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList
import java.lang.ref.WeakReference

abstract class AbstractProgramReductionDriver(
  val globalContext: GlobalContext,
  protected val cmd: CommandOptions,
  ioManager: TokenReductionIOManager,
  private var tree: SparTreeWithParsability,
  val configuration: ReductionConfiguration,
  val listenerManager: AsyncReductionListenerManager,
) : AbstractReductionDriver<TokenizedProgram, LanguageKind, TokenReductionIOManager>(
  ioManager,
  cmd.reductionControlFlags.getNumOfThreads(),
  cmd.reductionControlFlags.testScriptExecutionTimeoutInSeconds,
  cmd.reductionControlFlags.testScriptExecutionKeepWaitingAfterTimeout,
  externalTestScriptExecutionCachePolicyCreator = {
    cmd.cacheControlFlags.globalCacheFile.let {
      if (it == null) {
        NullExternalTestScriptExecutionCachePolicy()
      } else {
        ExternalTestScriptExecutionCachePolicy(
          historyCsvFile = it,
          csvFileToSaveHistory = cmd.cacheControlFlags.pathToSaveUpdatedGlobalCache,
        )
      }
    }
  },
) {

  private fun createQueryCacheProfiler() =
    if (cmd.profilingFlags.profileQueryCacheTimeCSV != null) {
      QueryCacheTimeCsvProfiler(
        globalContext.fileStreamPool.rentStream(
          cmd.profilingFlags.profileQueryCacheTimeCSV!!,
          description = QueryCacheTimeCsvProfiler::class.qualifiedName,
        ),
      )
    } else if (cmd.profilingFlags.profileQueryCacheTime != null) {
      QueryCacheTimeProfiler(
        globalContext.fileStreamPool.rentStream(
          cmd.profilingFlags.profileQueryCacheTime!!,
          description = QueryCacheTimeProfiler::class.qualifiedName,
        ),
      )
    } else if (cmd.profilingFlags.profileQueryCacheMemory != null) {
      QueryCacheMemoryProfiler(
        globalContext.fileStreamPool.rentStream(
          cmd.profilingFlags.profileQueryCacheMemory!!,
          description = QueryCacheMemoryProfiler::class.qualifiedName,
        ),
      )
    } else {
      AbstractQueryCacheProfiler.NULL_PROFILER
    }

  private val queryCache =
    if (configuration.enableTestScriptExecutionCaching) {
      QueryCacheFactory.createQueryCache(
        computeQueryCacheType(cmd.experimentFlags.cacheType, ioManager.getDefaultProgramFormat()),
        tree.programSnapshot,
        registerToClose(createQueryCacheProfiler()),
        QueryCacheConfiguration(
          cmd.cacheControlFlags.queryCacheRefreshThresholdAsFraction(),
          enableLightweightRefreshing = cmd.cacheControlFlags.enableLightweightRefreshing,
        ),
      )
    } else {
      NullQueryCache()
    }

  val nodeActionSetCache =
    if (cmd.cacheControlFlags.nodeActionSetCaching) {
      NodeActionSetCache()
    } else {
      NullNodeActionSetCache()
    }
  private val actionSetProfiler =
    if (cmd.profilingFlags.actionSetProfiler == null) {
      AbstractActionSetProfiler.NULL_PROFILER
    } else {
      ActionSetProfiler(cmd.profilingFlags.actionSetProfiler!!)
    }
  private val onDemandReducerCreators = createOnDemandReducerCreators(
    cmd.experimentFlags,
  )

  private fun createOnDemandReducerCreators(
    experimentFlags: ExperimentFlagGroup,
  ): ImmutableList<ITokenReducerCreator> {
    val classes = experimentFlags.onDemandReducerClasses
    if (classes.isNullOrEmpty()) {
      return ImmutableList.of()
    }
    // TODO: support configuring via environment variables.
    return classes.asSequence()
      .onEach {
        require(AbstractTokenReducer::class.java.isAssignableFrom(it)) {
          it
        }
      }.map { klass ->
        ITokenReducerCreator { reducerContext ->
          ImmutableList.of(
            klass.getConstructor(ReducerContext::class.java)
              .newInstance(reducerContext) as AbstractTokenReducer,
          )
        }
      }.toImmutableList()
  }

  override fun getInitialProgram(): TokenizedProgram {
    return tree.programSnapshot
  }

  override fun reduce() {
    printStartTime()
    val parsableTree = tree.getParsableTreeOrFail()
    val reductionStartEvent = createReductionStartEvent(parsableTree)
    listenerManager.onReductionStart(reductionStartEvent)
    try {
      logCacheSettings()
      ioManager.backupAllMutableFiles()
      sanityCheckAndLogAndMayThrow()
      ioManager.updateBestResult(parsableTree.programSnapshot)
      val mainReducerAnnotation = createMainReducer()
      val sparTreeEditListeners = createSparTreeEditListeners(
        ioManager,
        queryCache,
        listenerManager,
        nodeActionSetCache,
      )
      parsableTree.registerSparTreeEditListeners(sparTreeEditListeners)
      val tokenizedProgramFactory = parsableTree.tokenizedProgramFactory
      val persesTokenFactory = tokenizedProgramFactory.tokenFactory
      logger.ktInfo {
        "The number of lexemes in the token factory is is ${persesTokenFactory.numOfLexemes()}"
      }

      val auxiliaryReducerCreators = createAuxiliaryReducerCreators()
      internalReduce(
        reductionStartEvent,
        sparTreeEditListeners,
        tokenizedProgramFactory,
        mainReducerAnnotation,
        auxiliaryReducerCreators,
      )
    } finally {
      // Just to make sure the onReductionEnd() can be called even in case of exceptions.
      val finalTokenCount = tree.updatetokenCountAndGet()
      val reductionEndEvent = reductionStartEvent.createEndEvent(
        programSize = finalTokenCount,
        testScriptStatistics = executorService.statistics.createSnapshot(),
      )
      listenerManager.onReductionEnd(reductionEndEvent)
    }
    callCreduceIfEnabled()
    formatBestFileIfEnabled()
  }

  private var sanityCheckResult: SanityCheckEvent? = null

  private fun sanityCheckAndLogAndMayThrow() {
    val result = cachedSanityCheckResult
    listenerManager.onSanityCheck(
      SanityCheckEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = getInitialProgram().tokenCount(),
        sanityCheckResult = result,
      ),
    )
    if (result is IReductionDriver.FailingSanityCheckResult) {
      throw result.exception
    }
  }

  private fun logCacheSettings() {
    logger.ktInfo {
      val queryCacheStatus = boolToString(configuration.enableTestScriptExecutionCaching)
      val editCacheStatus = boolToString(cmd.cacheControlFlags.nodeActionSetCaching)
      val queryCacheType = cmd.experimentFlags.cacheType.name.lowercase()
      "Cache setting: query-caching=$queryCacheStatus, " +
        "edit-caching=$editCacheStatus, query-cache=$queryCacheType"
    }
  }

  private fun createReductionStartEvent(parsableTree: SparTree) = ReductionStartEvent(
    System.currentTimeMillis(),
    WeakReference(parsableTree),
    parsableTree.tokenCount,
    commandLineOptions = YamlUtil.toYamlString(
      cmd,
      objectMapperCustomizer = YamlUtil::customizeObjectMapperByUsingBasenameForPath,
    ),
    extraData = "Parser Facade: ${configuration.parserFacade::class}",
  )

  private fun createAuxiliaryReducerCreators(): ImmutableList<ITokenReducerCreator> =
    ImmutableList
      .builder<ITokenReducerCreator>()
      .apply {
        if (lineSlicerEnabled) {
          add { LineBasedConcurrentTokenSlicer.COMPOSITE_REDUCER.create(it) }
        }
        if (treeSlicerEnabled) {
          add { TreeSlicer.META.create(it) }
        }
        if (tokenSlicerEnabled) {
          add { ConcurrentTokenSlicer.COMPOSITE_REDUCER.create(it) }
        }
        if (vulcanEnabled) {
          add { LocalExhaustivePatternReducer.META.create(it) }
          add { IdentifierReplacementReducer.META.create(it) }
          add { SubTreeReplacementReducer.META.create(it) }
        }
        if (trecEnabled) {
          add { TokenCanonicalizer.META.create(it) }
        }
        addAll(onDemandReducerCreators)
      }.build()

  private fun internalReduce(
    reductionStartEvent: ReductionStartEvent,
    sparTreeEditListeners: ImmutableList<AbstractSparTreeEditListener>,
    originalTokenizedProgramFactory: TokenizedProgramFactory,
    mainReducerAnnotation: ReducerAnnotation,
    auxiliaryReducerCreators: ImmutableList<ITokenReducerCreator>,
  ) {
    ReducerScheduler(
      fixpointMode = configuration.fixpointReduction,
      reducerContext = reducerContext,
      mainReducerCreator = mainReducerAnnotation,
      auxiliaryReducerCreators = auxiliaryReducerCreators,
      computeStatistics = this::computeStatistics,
      reducerRunner = { callReducer(reductionStartEvent, it) },
      actionBeforeNonFirstRunOfMainReducers = {
        updateTreeBeforeIteration { tree ->
          val sparTree = tree.getTreeRegardlessOfParsability()
          check(
            sparTree.tokenizedProgramFactory
              == originalTokenizedProgramFactory,
          ) { "The tokenized program factory should be unchanged during a reduction process." }
          check(
            sparTree.tokenizedProgramFactory.tokenFactory ==
              originalTokenizedProgramFactory.tokenFactory,
          ) { "The perses token factory should be unchanged during a reduction process." }
          check(sparTree.hasTheSameEditListeners(sparTreeEditListeners))
        }
      },
    ).run()
  }

  private fun computeStatistics(): StatsOfFilesBeingReduced {
    return StatsOfFilesBeingReduced(
      tree.updatetokenCountAndGet(),
      ioManager.readAndTrimAllBestFiles().transformToImmutableList {
        StatsOfFilesBeingReduced.FileNameAndContentDigestPair(
          it.fileName,
          Util.SHA512HashCode.createFromString(it.computeFileContent()),
        )
      },
    )
  }

  private fun updateTreeBeforeIteration(
    treeAssertion: (SparTreeWithParsability) -> Unit,
  ) {
    if (cmd.algorithmControlFlags.rebuildParseTreeEachIteration) {
      logger.ktInfo { "Rebuilding spar-tree." }
      // Rebuilding is necessary, to hop over different production rules.
      val oldSparTree = tree.getTreeRegardlessOfParsability()
      tree = reparseAndCreateSparTree(tree, configuration.parserFacade, ioManager)
      if (oldSparTree != tree.getTreeRegardlessOfParsability()) {
        // TODO: this branch needs testing. We currently have no test which can trigger this branch.
        tree.getTreeRegardlessOfParsability().copyListenersFrom(oldSparTree)
      }
    }
    treeAssertion(tree)
  }

  private fun simplifySparTree() {
    SparTreeSimplifier.simplify(tree.getTreeRegardlessOfParsability())
  }

  private fun callCreduceIfEnabled() {
    if (!cmd.outputRefiningFlags.callCReduce) {
      return
    }
    val program = tree.programSnapshot
    val origTokenCount = program.tokenCount()
    logger.ktInfo {
      "Calling C-Reduce to further refine the result. #tokens=$origTokenCount"
    }
    val creduceCmd = cmd.outputRefiningFlags.creduceCmd
    val reductionFolder = executorService.createReductionFolder(
      prefix = "creduce_at_the_end",
      suffix = TimeUtil.formatDateForFileName(System.currentTimeMillis()),
    )
    ioManager.createOutputManager(program)
      .write(reductionFolder)
    val cmdOutput = Shells.singleton.run(
      constructFullCreduceCommand(creduceCmd, reductionFolder),
      reductionFolder.folder,
      captureOutput = false,
      environment = Shells.CURRENT_ENV,
    )
    if (cmdOutput.exitCode.isNonZero()) {
      val tempDir = copyFilesToTempDir(reductionFolder.folder)
      logger.ktSevere {
        "C-Reduce failed to reduce the file. All files are copied to $tempDir"
      }
      return
    }
    try {
      /* TODO: we need to put the syntax checking into the reduction script, so that
       *       the result generated by c-reduce is still syntactical valid.
       */
      tree = ioManager.visitMainSourceFileIn(reductionFolder) {
        createSparTree(it, configuration.parserFacade)
      }
    } catch (e: java.lang.Exception) {
      logger.ktSevere { "The file produced by C-Reduce cannot be parsed: $e" }
      return
    }
    ioManager.updateBestResult(tree.programSnapshot)
    val tokenCount = tree.programSnapshot.tokenCount()
    logger.ktInfo {
      "C-Reduce reduced the file from $origTokenCount to $tokenCount tokens"
    }
  }

  private fun constructFullCreduceCommand(
    creduceCmd: String,
    reductionFolder: ReductionFolder,
  ) = buildString {
    append(creduceCmd)
    append(' ')
    append(ioManager.getScriptFileBaseNameIn(reductionFolder))
    append(' ')
    append(ioManager.getSingleSourceFileBaseName(reductionFolder))
  }

  private val treeSlicerEnabled: Boolean
    get() = cmd.algorithmControlFlags.enableTreeSlicer

  private val tokenSlicerEnabled: Boolean
    get() = cmd.algorithmControlFlags.enableTokenSlicer

  private val lineSlicerEnabled =
    if (!cmd.algorithmControlFlags.enableLineSlicer) {
      false
    } else {
      val programFormat = ioManager.getDefaultProgramFormat()
      if (programFormat == EnumFormatControl.SINGLE_TOKEN_PER_LINE) {
        logger.ktWarning {
          "The program format is $programFormat, " +
            "incompatible with line slicer. Line slicer is disabled."
        }
        false
      } else {
        true
      }
    }

  private val vulcanEnabled = cmd.vulcanFlags.enableVulcan
  private val trecEnabled = cmd.algorithmControlFlags.enableTrec

  private fun callReducer(
    reductionStartEvent: ReductionStartEvent,
    reducer: AbstractTokenReducer,
  ) {
    val reducerName = reducer.reducerAnnotation.shortName
    if (cmd.cacheControlFlags.enablePassCache && reducer.reducerAnnotation.deterministic &&
      updatePassLevelCache(reducer.reducerAnnotation) == PassLevelCacheResult.EXISTING_ALREADY
    ) {
      logger.ktInfo {
        "[Pass Caching]: The reducer $reducerName is skipped, " +
          "because the input has been reduced the reducer by before and" +
          "the input has not changed."
      }
      return
    }
    simplifySparTree()
    val preSize = tree.updatetokenCountAndGet()
    logger.ktInfo {
      val time = TimeUtil.formatDateForDisplay(System.currentTimeMillis())
      "$reducerName started at $time. #tokens=$preSize"
    }
    val currentStat = computeStatistics()
    val fixpointIterationStartEvent = reductionStartEvent.nextFixpointIteration(
      programSize = currentStat.tokenCount,

      reducerClass = reducer.reducerAnnotation,
      treeStructureDumper = {
        WeakReference(tree.getTreeRegardlessOfParsability()).get()?.printTreeStructure() ?: ""
      },
      testScriptStatistics = executorService.statistics.createSnapshot(),
    )
    listenerManager.onFixpointIterationStart(fixpointIterationStartEvent)
    reducer.reduce(FixpointReductionState(fixpointIterationStartEvent, tree))
    logger.ktInfo {
      val time = TimeUtil.formatDateForDisplay(System.currentTimeMillis())
      "$reducerName ended at $time. #old=$preSize, #new=${tree.updatetokenCountAndGet()}"
    }
    listenerManager.onFixpointIterationEnd(
      fixpointIterationStartEvent.createEndEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = tree.programSnapshot.tokenCount(),
        testScriptStatistics = executorService.statistics.createSnapshot(),
      ),
    )
  }

  private val passLevelCache = PassLevelCache()

  private fun updatePassLevelCache(reducerAnnotation: ReducerAnnotation): PassLevelCacheResult {
    return passLevelCache.update(reducerAnnotation) {
      ioManager.outputManagerFactory.createManagerFor(tree.programSnapshot).shA512HashCode
    }
  }

  // TODO: unit-test this function.
  private fun formatBestFileIfEnabled() {
    if (!cmd.outputRefiningFlags.callFormatter) {
      return
    }
    val formatCmd = configuration.parserFacade.language.getDefaultWorkingFormatter()
    if (formatCmd == null) {
      logger.ktSevere {
        "The default formatter is not working. cmd=" +
          configuration.parserFacade.language.getAllDefaultFormatterCommandStrings()
      }
      return
    }

    val formatFolder = executorService.createReductionFolder(
      prefix = "formatter_at_the_end_",
      suffix = TimeUtil.formatDateForFileName(System.currentTimeMillis()),
    )
    ioManager.createOutputManager(tree.programSnapshot)
      .write(formatFolder)
    logger.ktInfo {
      "Formatting the reduction result " +
        "in ${formatFolder.folder} with ${formatCmd.normalizedCommand}"
    }

    val sourceFileNames = ioManager.getAllSourceFileBaseNamesIn(formatFolder)

    for (sourceFileName in sourceFileNames) {
      val cmdOutput = formatCmd.runWith(
        ImmutableList.of(sourceFileName),
        workingDirectory = formatFolder.folder,
      )
      if (cmdOutput.exitCode.isNonZero()) {
        logger.ktSevere {
          "Failed to call formatter ${formatCmd.normalizedCommand} " +
            "on the final result ${formatFolder.folder}."
        }
        logger.ktSevere { "stdout: " + cmdOutput.stderr.combinedLines }
        logger.ktSevere { "stderr: " + cmdOutput.stdout.combinedLines }
        return
      }
    }

    val scriptTestResult = formatFolder.runTestScript()
    if (scriptTestResult.isNotInteresting) {
      logger.ktSevere {
        "The formatted file(s) failed the property test: " +
          "formatter=${formatCmd.normalizedCommand}, program(s)=$formatFolder/$sourceFileNames"
      }
      return
    }
    if (cmd.algorithmControlFlags.rebuildParseTreeEachIteration) {
      try {
        /* TODO: we need to put the syntax checking into the reduction script, so that
         *       the result generated by c-reduce is still syntactical valid.
         */
        tree = ioManager.visitMainSourceFileIn(formatFolder) {
          createSparTree(it, configuration.parserFacade)
        }
      } catch (e: java.lang.Exception) {
        logger.ktSevere {
          "The file produced by the formatter '$formatCmd' cannot be parsed. $e"
        }
        return
      }
      ioManager.updateBestResultInOrigFormat(tree.programSnapshot)
    } else {
      formatFolder.copyTo(ioManager.resultFolder)
    }
  }

  override fun close() {
    // trigger the cache to do some profiling work, before profile is closed.
    queryCache.triggerHeartBeat()
    super.close()
  }

  open fun createMainReducer(): ReducerAnnotation {
    val algorithmMeta = ReducerFactory.getReductionAlgorithm(
      cmd.algorithmControlFlags.reductionAlgorithm.let { algName ->
        algName ?: PersesNodePrioritizedDfsReducer.NAME
      },
    )
    logger.ktInfo {
      "Reduction algorithm is ${algorithmMeta.shortName}"
    }
    return algorithmMeta
  }

  private val reducerContext = ReducerContext(
    ioManager,
    configuration,
    executorService,
    listenerManager,
    queryCache,
    nodeActionSetCache,
    actionSetProfiler,
    sparTreeNodeFactory = tree.getTreeRegardlessOfParsability().sparTreeNodeFactory,
    deltaDebuggerListener = if (cmd.profilingFlags.profileDeltaDebugger == null) {
      AbstractListInputMinimizerListener.NullListInputMinimizerListener
    } else {
      ListInputMinimizerProgressListener(cmd.profilingFlags.profileDeltaDebugger!!)
    },
  )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    private fun reparseAndCreateSparTree(
      originalTree: SparTreeWithParsability,
      parserFacade: AbstractParserFacade,
      ioManager: TokenReductionIOManager,
    ): SparTreeWithParsability {
      return try {
        val parseTree = parserFacade.parseString(ioManager.readBestMainFile())
        val sparTree = SparTreeBuilder(
          originalTree.getTreeRegardlessOfParsability().sparTreeNodeFactory,
          parseTree,
        ).result
        SparTreeWithParsability(sparTree, parsable = true)
      } catch (e: Exception) {
        logger.ktWarning { "Fail to re-parse the best program." }
        SparTreeWithParsability(
          originalTree.getTreeRegardlessOfParsability(),
          parsable = false,
        )
      }
    }

    internal fun computeQueryCacheType(
      specifiedQueryType: QueryCacheType,
      defaultProgramFormat: EnumFormatControl,
    ): QueryCacheType {
      val cacheType = if (specifiedQueryType == QueryCacheType.AUTO) {
        if (defaultProgramFormat == EnumFormatControl.SINGLE_TOKEN_PER_LINE) {
          QueryCacheType.COMPACT_QUERY_CACHE
        } else {
          QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE
        }
      } else {
        specifiedQueryType
      }
      require(
        cacheType != QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE ||
          defaultProgramFormat != EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      ) {
        "Cache type ${QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE} " +
          "is not compatible with the code format ${EnumFormatControl.SINGLE_TOKEN_PER_LINE}"
      }
      return cacheType
    }

    @JvmStatic
    private fun createSparTreeEditListeners(
      ioManager: TokenReductionIOManager,
      queryCache: AbstractQueryCache,
      listenerManager: AsyncReductionListenerManager,
      nodeActionSetCache: AbstractNodeActionSetCache,
    ): ImmutableList<AbstractSparTreeEditListener> {
      val builder = ImmutableList.builder<AbstractSparTreeEditListener>()
      builder.add(
        object : AbstractSparTreeEditListener() {
          override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
            ioManager.updateBestResult(event.program)
            logger.ktFine {
              "An edit is applied to the spar-tree. New #tokens=${event.program.tokenCount()}"
            }
          }
        },
      )
      builder.add(
        object : AbstractSparTreeEditListener() {
          override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
            val sizeBefore = queryCache.size()
            queryCache.evictEntriesLargerThan(event.program)
            val sizeAfter = queryCache.size()
            listenerManager.onTestScriptExecutionCacheEntryEviction(sizeBefore, sizeAfter)
          }
        },
      )
      builder.add(
        object : AbstractSparTreeEditListener() {
          override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
            val originalSize = nodeActionSetCache.size
            nodeActionSetCache.clear()
            listenerManager.onNodeActionSetClearance(originalSize)
          }
        },
      )
      return builder.build()
    }

    @JvmStatic
    fun createSparTree(
      fileToReduce: SourceFile,
      parserFacade: AbstractParserFacade,
    ): SparTreeWithParsability {
      val timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis())
      logger.ktInfo { "Tree Building: Start building spar-tree from input file $fileToReduce" }
      val hierarchy = parserFacade.ruleHierarchy
      logger.ktInfo { "Tree Building: Step 1: Antlr parsing." }
      val parseTree = parserFacade.parseString(fileToReduce.textualFileContent)
      val tokenizedProgramFactory = createTokenizedProgramFactory(
        parseTree.tree,
        parserFacade.language,
      )
      val sparTreeNodeFactory = SparTreeNodeFactory(
        parserFacade.metaTokenInfoDb,
        tokenizedProgramFactory,
        hierarchy,
      )
      logger.ktInfo { "Tree Building: Step 2: Converting parse tree to spar-tree" }
      val sparTree = SparTreeBuilder(sparTreeNodeFactory, parseTree).result
      logger.ktInfo { "Tree Building: Step 3: Simplifying spar-tree" }
      val time = timeSpanBuilder.end(System.currentTimeMillis())
      logger.ktInfo { "Tree Building: Finished in $time" }
      return SparTreeWithParsability(sparTree, parsable = true)
    }

    @JvmStatic
    @VisibleForTesting
    fun createConfiguration(
      cmd: CommandOptions,
      parserFacade: AbstractParserFacade,
      defaultProgramFormat: EnumFormatControl,
    ): ReductionConfiguration {
      return ReductionConfiguration(
        fixpointReduction = cmd.reductionControlFlags.fixpoint,
        enableTestScriptExecutionCaching = computeWhetherToEnableQueryCaching(
          cmd.cacheControlFlags.queryCaching,
          defaultProgramFormat,
        ),
        defaultDeltaDebuggerTypeForKleene =
        cmd.algorithmControlFlags.defaultDeltaDebuggerTypeForKleene,
        numOfReductionThreads = cmd.reductionControlFlags.getNumOfThreads(),
        parserFacade = parserFacade,
        persesNodeReducerConfig = ReductionConfiguration.PersesNodeReducerConfiguration(
          maxEditCountForRegularRuleNode = cmd.algorithmControlFlags.maxEditCountForRegularRuleNode,
          maxBfsDepthForRegularRuleNode = cmd.algorithmControlFlags.maxBfsDepthForRegularRuleNode,
          stopAtFirstCompatibleChildren = cmd
            .algorithmControlFlags.stopAtFirstCompatibleChildForRegularRuleNode,
        ),
        vulcanConfig = ReductionConfiguration.VulcanConfig(
          nonDeletionIterationLimit = cmd.vulcanFlags.nonDeletionIterationLimit,
          windowSizeForLocalExhaustivePatternReduction = cmd.vulcanFlags.windowSize,
          vulcanFixpoint = cmd.vulcanFlags.vulcanFixpoint,
        ),
      )
    }

    fun boolToString(value: Boolean) = if (value) "enabled" else "disabled"

    private fun computeWhetherToEnableQueryCaching(
      userSpecified: EnumQueryCachingControl,
      programFormatControl: EnumFormatControl,
    ) = when (userSpecified) {
      EnumQueryCachingControl.TRUE -> true
      EnumQueryCachingControl.FALSE -> false
      EnumQueryCachingControl.AUTO ->
        programFormatControl == EnumFormatControl.SINGLE_TOKEN_PER_LINE
    }

    private fun createTokenizedProgramFactory(
      originalTree: ParseTree,
      languageKind: LanguageKind,
    ): TokenizedProgramFactory {
      val tokens = AbstractParserFacade.getTokens(originalTree)
      return TokenizedProgramFactory.createFactory(tokens, languageKind)
    }
  }

  data class StatsOfFilesBeingReduced(
    val tokenCount: Int,
    val fileContents: ImmutableList<FileNameAndContentDigestPair>,
  ) {
    data class FileNameAndContentDigestPair(
      val fileName: String,
      val contentDigest: Util.SHA512HashCode,
    )
  }
}

fun TestScriptExecutorService.Statistics.createSnapshot() =
  TestScriptExecutorServiceStatisticsSnapshot(
    scriptExecutionNumber = this.scriptExecutionNumber,
    externalCacheHitNumber = this.externalCacheHitNumber,
  )

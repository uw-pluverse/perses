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

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.Strings
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import com.google.common.io.Files
import com.google.common.io.MoreFiles
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.CommandOptions
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParserFacadeFactory
import org.perses.listener.LoggingListener
import org.perses.listener.ProgressMonitorForNodeReducer
import org.perses.listener.ReductionProfileListener
import org.perses.listener.StatisticsListener
import org.perses.listener.TestScriptExecutionListener
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractActionSetProfiler.ActionSetProfiler
import org.perses.reduction.AbstractTestScriptExecutionCacheProfiler.TestScriptExecutionCacheProfiler
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.reducer.TokenSlicer
import org.perses.reduction.reducer.TreeSlicer
import org.perses.tree.spar.AbstractSparTreeEditListener
import org.perses.tree.spar.NodeActionSetCache
import org.perses.tree.spar.NullNodeActionSetCache
import org.perses.tree.spar.SparTree
import org.perses.tree.spar.SparTreeBuilder
import org.perses.tree.spar.SparTreeSimplifier
import org.perses.util.Shell
import org.perses.util.TimeSpan
import org.perses.util.TimeUtil
import java.io.Closeable
import java.io.File
import java.io.IOException
import java.nio.charset.StandardCharsets

/**
 * This is the main entry to invoke Perses reducer. It does not have a main, but is the main entry
 * as a reduction library.
 */
class ReductionDriver(
  private val cmd: CommandOptions,
  private val parserFacadeFactory: ParserFacadeFactory,
  vararg extraListeners: AbstractReductionListener
) : Closeable {

  val configuration = createConfiguration(cmd, parserFacadeFactory)

  private val executorService = TestScriptExecutorService(
    configuration.tempRootFolder,
    configuration.numOfReductionThreads,
    configuration.testScript,
    configuration.fileToReduce.baseName,
    cmd.profilingFlags.testScriptExecutionPerformanceMonitorIntervalMillis
  )
  private val listenerManager = ReductionListenerManager(
    createListeners(cmd.profilingFlags.profile, configuration, extraListeners)
  )
  private var tree = createSparTree(configuration.fileToReduce)
  private val cacheProfiler =
    if (Strings.isNullOrEmpty(cmd.profilingFlags.profileTestExecutionCache))
      AbstractTestScriptExecutionCacheProfiler.NULL_PROFILER
    else TestScriptExecutionCacheProfiler(
      File(cmd.profilingFlags.profileTestExecutionCache)
    )
  val queryCache =
    if (configuration.enableTestScriptExecutionCaching)
      TestScriptExecutionCache(
        tree.programSnapshot,
        cacheProfiler,
        cmd.cacheControlFlags.getQueryCacheRefreshThreshold()
      )
    else NullTestScriptExecutionCache()
  val nodeActionSetCache =
    if (cmd.cacheControlFlags.nodeActionSetCaching) NodeActionSetCache()
    else NullNodeActionSetCache()
  val actionSetProfiler =
    if (Strings.isNullOrEmpty(cmd.profilingFlags.actionSetProfiler))
      AbstractActionSetProfiler.NULL_PROFILER
    else ActionSetProfiler(File(cmd.profilingFlags.actionSetProfiler))

  fun reduce() {
    logger.atInfo().log(
      "The reduction process started at %s",
      TimeUtil.formatDateForDisplay(System.currentTimeMillis())
    )
    backupFile(configuration)
    val worker = createMainReducer()
    val sparTreeEditListeners = createSparTreeEditListeners(configuration)
    tree.registerSparTreeEditListeners(sparTreeEditListeners)
    sanityCheck(tree)
    val tokenizedProgramFactory = tree.tokenizedProgramFactory
    val persesTokenFactory = tokenizedProgramFactory.tokenFactory
    logger.atInfo().log(
      "The number of lexemes in the token factory is is %s",
      persesTokenFactory.numOfLexemes()
    )
    run {
      val fileToReduce = configuration.fileToReduce
      val bestFile = configuration.bestResultFile
      if (fileToReduce.file.canonicalPath != bestFile.canonicalPath) {
        MoreFiles.asCharSink(bestFile.toPath(), StandardCharsets.UTF_8)
          .write(fileToReduce.fileContent)
      }
    }
    listenerManager.onReductionStart(tree, tree.originalTokenCount)
    reduce(sparTreeEditListeners, tokenizedProgramFactory, worker)
    run {
      val countOfTestScriptExecutions = executorService.statistics.getScriptExecutionNumber()
      val finalTokenCount = tree.tokenCount
      listenerManager.onReductionEnd(finalTokenCount, countOfTestScriptExecutions)
    }
    callCreduceIfEnabled()
    formatBestFileIfEnabled()
  }

  private fun reduce(
    sparTreeEditListeners: ImmutableList<AbstractSparTreeEditListener>,
    originalTokenizedProgramFactory: TokenizedProgramFactory,
    mainReducer: AbstractReducer
  ) {
    var fixpointIteration = 1
    while (true) {
      val currentFixpointIteration = fixpointIteration
      if (currentFixpointIteration > 1) {
        logger.atInfo().log(
          "The fixpoint mode is enabled. This is iteration %s", fixpointIteration
        )
        if (cmd.algorithmControlFlags.rebuildParseTreeEachIteration) {
          logger.atInfo().log("Rebuilding spar-tree.")
          // Rebuilding is necessary, to hop over different production rules.
          tree = reparseAndCreateSparTree(tree)
          tree.registerSparTreeEditListeners(sparTreeEditListeners)
        } else {
          SparTreeSimplifier.simplify(tree)
        }
        assert(tree.tokenizedProgramFactory == originalTokenizedProgramFactory) {
          "The tokenized program factory should be unchanged during a reduction process."
        }
        assert(
          tree.tokenizedProgramFactory.tokenFactory ==
            originalTokenizedProgramFactory.tokenFactory
        ) {
          "The perses token factory should be unchanged duing a reduction process."
        }
      }
      val initialTokenCount = tree.tokenCount
      reduceOneFixpointIteration(currentFixpointIteration, mainReducer)
      if (shouldExitFixpointIteration(initialTokenCount)) {
        runTreeSlicerIfEnabled(initialTokenCount)
      }
      if (shouldExitFixpointIteration(initialTokenCount)) {
        runTokenSlicerIfEnabled(initialTokenCount)
      }
      if (shouldExitFixpointIteration(initialTokenCount)) {
        break
      }
      ++fixpointIteration
    }
  }

  private fun callCreduceIfEnabled() {
    if (!cmd.outputRefiningFlags.callCReduce) {
      return
    }
    val program = tree.programSnapshot
    val origTokenCount = program.tokenCount()
    logger.atInfo().log(
      "Calling C-Reduce to further refine the result. #tokens=%s",
      origTokenCount
    )
    val creduceCmd = cmd.outputRefiningFlags.getCreduceCmd()
    val reductionFolderName = "creduce_at_the_end_" +
      TimeUtil.formatDateForFileName(System.currentTimeMillis())
    val reductionFolder = executorService.createNamedReductionFolder(reductionFolderName)
    program.writeToFile(
      reductionFolder.sourceFilePath, configuration.programFormatControl
    )
    val cmdOutput = Shell.run(
      constructFullCreduceCommand(creduceCmd, reductionFolder),
      reductionFolder.folder,
      captureOutput = false,
      environment = Shell.CURRENT_ENV
    )
    if (cmdOutput.exitCode != 0) {
      val tempDir = copyFilesToTempDir(reductionFolder.folder)
      logger.atSevere().log(
        "C-Reduce failed to reduce the file. All files are copied to %s",
        tempDir
      )
      return
    } else {
      // TODO: use kotlin's copyTo.
      Files.copy(reductionFolder.sourceFilePath, configuration.bestResultFile)
      val tokenCount = configuration.parserFacade.parseIntoTokens(configuration.bestResultFile).size
      logger.atInfo().log(
        "C-Reduce reduced the file from %s to %s tokens",
        origTokenCount, tokenCount
      )
      // FIXME: this may crash, as c-reduce can produce programs unparseable for Perses.
      tree = createSparTree(
        SourceFile(configuration.bestResultFile, configuration.parserFacade.language)
      )
    }
  }

  private fun constructFullCreduceCommand(
    creduceCmd: String,
    reductionFolder: ReductionFolder
  ): String {
    return StringBuilder()
      .append(creduceCmd)
      .append(' ')
      .append(reductionFolder.testScript.scriptFile.name)
      .append(' ')
      .append(reductionFolder.sourceFilePath.name)
      .toString()
  }

  private fun shouldExitFixpointIteration(initialTokenCount: Int): Boolean {
    check(initialTokenCount >= tree.tokenCount)
    return !configuration.fixpointReduction || initialTokenCount == tree.tokenCount
  }

  private fun runTreeSlicerIfEnabled(initialTokenCount: Int) {
    assert(shouldExitFixpointIteration(initialTokenCount)) {
      "TreeSlicer should run only if the fixpoint is about to finish."
    }
    if (!cmd.algorithmControlFlags.enableTreeSlicer) {
      return
    }
    SparTreeSimplifier.simplify(tree)
    callSlicer(TreeSlicer.META)
  }

  private fun runTokenSlicerIfEnabled(initialTokenCount: Int) {
    assert(shouldExitFixpointIteration(initialTokenCount)) {
      "TokenSlicer should run only if the fixpoint is about to finish."
    }
    if (!cmd.algorithmControlFlags.enableTokenSlicer) {
      return
    }
    callSlicer(TokenSlicer.META)
  }

  private fun callSlicer(reducerAnnotation: ReducerAnnotation) {
    val sizeBeforeTokenSclier = tree.tokenCount
    if (logger.atInfo().isEnabled) {
      logger.atInfo().log(
        "%s started at %s. #tokens=%s", reducerAnnotation.shortName(),
        TimeUtil.formatDateForDisplay(System.currentTimeMillis()),
        sizeBeforeTokenSclier
      )
    }
    val tokenSlicer = createReducer(reducerAnnotation)
    tokenSlicer.reduce(ReductionState(tree))
    if (logger.atInfo().isEnabled) {
      logger.atInfo().log(
        "%s ended at %s. #old=%s, #new=%s", reducerAnnotation.shortName(),
        TimeUtil.formatDateForDisplay(System.currentTimeMillis()),
        sizeBeforeTokenSclier, tree.tokenCount
      )
    }
  }

  private fun reduceOneFixpointIteration(
    currentFixpointIteration: Int,
    mainReducer: AbstractReducer
  ) {
    tree.updateLeafTokenCount()
    val preSize = tree.tokenCount
    val testScriptExecutionsBefore = executorService.statistics.getScriptExecutionNumber()
    listenerManager.onFixpointIterationStart(
      currentFixpointIteration, preSize, mainReducer.redcucerAnnotation
    )
    val reductionState = ReductionState(tree)
    assert(reductionState.sparTree == tree)
    mainReducer.reduce(reductionState)
    val scriptExecutionNumberAfter = executorService.statistics.getScriptExecutionNumber()
    val countOfTestScriptExecutionsInThisIteration =
      scriptExecutionNumberAfter - testScriptExecutionsBefore
    listenerManager.onFixpointIterationEnd(
      currentFixpointIteration, tree.programSnapshot.tokenCount(),
      countOfTestScriptExecutionsInThisIteration
    )
    run {
      // Save the best result after a fixpoint iteration.
      val fixpointIterationResultFile =
        configuration.getFixpointIterationResultFile(currentFixpointIteration)
      logger.atFinest().log(
        "Saved result after fixpoint %s to %s",
        currentFixpointIteration, fixpointIterationResultFile
      )
      tree.programSnapshot.writeToFile(
        fixpointIterationResultFile, configuration.programFormatControl
      )
    }
  }

  protected fun sanityCheck(tree: SparTree) {
    logger.atFinest().log("sanity checking...")
    // TODO: need two steps of sanity check:
//  (1) use the original source program and test scrip. This ensures the test script is correct.
//  (2) use the spar-tree. This ensures the Antlr parser works correctly.
    val program = tree.programSnapshot
    val future = executorService.testProgramAsync(
      ALWAYS_TRUE_PRECHECK,
      program, configuration.programFormatControl
    )
    if (!future.get().isPass) {
      logger.atSevere().log("The initial sanity check failed. Folder: ${future.workingDirectory}")
      val tempDir = copyFilesToTempDir(future.workingDirectory)
      logger.atSevere().log("The files have been saved to $tempDir")
      throw IllegalStateException()
    }
    check(future.get().isPass) {
      "The initial sanity check failed. Folder: ${future.workingDirectory}"
    }
  }

  private fun copyFilesToTempDir(directory: File): File {
    val tempDir = Files.createTempDir()
    for (file in directory.listFiles()) {
      if (file.isFile) {
        Files.copy(file, File(tempDir, file.name))
      }
    }
    return tempDir
  }

  // TODO: test this function.
  private fun formatBestFileIfEnabled() {
    if (!cmd.outputRefiningFlags.callFormatter) {
      return
    }
    val formatCmd = configuration.parserFacade.language.defaultFormmaterCommand ?: return

    val formatFolderName = "formatter_at_the_end_" +
      TimeUtil.formatDateForFileName(System.currentTimeMillis())
    val formatFolder = executorService.createNamedReductionFolder(formatFolderName)
    configuration.bestResultFile.copyTo(formatFolder.sourceFilePath)
    logger.atInfo().log(
      "Formatting the reduction result %s with %s",
      configuration.bestResultFile,
      formatCmd.command
    )
    val cmdOutput = formatCmd.runWith(
      ImmutableList.of(formatFolder.sourceFilePath.name),
      workingDirectory = formatFolder.folder
    )
    if (cmdOutput.exitCode != 0) {
      logger.atSevere().log(
        "Failed to call formatter %s on the final result %s.",
        formatCmd.command,
        formatFolder.sourceFilePath
      )
      logger.atSevere().log("stdout: %s", cmdOutput.stderr.combineLines())
      logger.atSevere().log("stderr: %s", cmdOutput.stdout.combineLines())
      return
    }
    val scriptTestResult = formatFolder.testScript.test()
    if (scriptTestResult.isFail) {
      logger.atSevere().log(
        "The formatted file failed the property test: formatter=%s, program=%s",
        formatCmd.command,
        formatFolder.sourceFilePath
      )
      return
    }
    formatFolder.sourceFilePath.copyTo(configuration.bestResultFile, overwrite = true)
  }

  fun reparseAndCreateSparTree(originalTree: SparTree): SparTree {
    val program = originalTree.programSnapshot
    try {
      val parserFacade = configuration.parserFacade
      val parseTree = parserFacade.parseString(
        program.toSourceCodeInOrigFormatWithBlankLines()
      ).tree
      return SparTreeBuilder(
        parserFacade.ruleHierarchy, originalTree.tokenizedProgramFactory
      ).build(parseTree)
    } catch (e: Exception) {
      logger.atSevere().log(
        "Fail to parse the following program. \n%s",
        program.toSourceCodeInOrigFormatWithBlankLines()
      )
      throw e
    }
  }

  fun createSparTree(fileToReduce: SourceFile): SparTree {
    val timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis())
    logger.atInfo().log(
      "Tree Building: Start building spar-tree from input file %s",
      fileToReduce
    )
    val parserFacade = configuration.parserFacade
    val hierarchy = parserFacade.ruleHierarchy
    logger.atInfo().log("Tree Building: Step 1: Antlr parsing.")
    val parseTree = parserFacade.parseString(fileToReduce.fileContent).tree
    val tokenizedProgramFactory = createTokenizedProgramFactory(parseTree)
    logger.atInfo().log("Tree Building: Step 2: Converting parse tree to spar-tree")
    val sparTree = SparTreeBuilder(hierarchy, tokenizedProgramFactory).build(parseTree)
    logger.atInfo().log("Tree Building: Step 3: Simplifying spar-tree")
    val time = timeSpanBuilder.end(System.currentTimeMillis())
    logger.atInfo().log("Tree Building: Finished in %s", time)
    return sparTree
  }

  override fun close() {
    executorService.close()
  }

  private fun createSparTreeEditListeners(
    configuration: ReductionConfiguration
  ): ImmutableList<AbstractSparTreeEditListener> {
    val builder = ImmutableList.builder<AbstractSparTreeEditListener>()
    builder.add(
      object : AbstractSparTreeEditListener() {
        override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
          try {
            event
              .program
              .writeToFile(
                configuration.bestResultFile, configuration.programFormatControl
              )
            logger.atFine().log(
              "An edit is applied to the spar-tree. New #tokens=%s", event.program.tokenCount()
            )
          } catch (e: IOException) {
            throw RuntimeException(e)
          }
        }
      })
    builder.add(
      object : AbstractSparTreeEditListener() {
        override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
          val cache = queryCache
          val sizeBefore = cache.size()
          cache.evictEntriesLargerThan(event.program)
          val sizeAfter = cache.size()
          listenerManager.onTestScriptExecutionCacheEntryEviction(sizeBefore, sizeAfter)
        }
      })
    builder.add(
      object : AbstractSparTreeEditListener() {
        override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
          val originalSize = nodeActionSetCache.size()
          nodeActionSetCache.clear()
          listenerManager.onNodeActionSetClearance(originalSize)
        }
      })
    return builder.build()
  }

  fun createMainReducer(): AbstractReducer {
    val algorithmMeta = ReducerFactory.getReductionAlgorithm(
      cmd.algorithmControlFlags.getReductionAlgorithmName()
    )
    val algorithm = createReducer(algorithmMeta)
    logger.atInfo().log(
      "Reduction algorithm is %s",
      algorithm.javaClass.canonicalName
    )
    return algorithm
  }

  private fun createReducer(reducerAnnotation: ReducerAnnotation) =
    reducerAnnotation.create(
      ReducerContext(
        configuration,
        executorService,
        listenerManager,
        queryCache,
        nodeActionSetCache,
        actionSetProfiler
      )
    )

  @Throws(IOException::class)
  private fun backupFile(configuration: ReductionConfiguration) {
    val fileToReduce = configuration.fileToReduce
    val baseName = fileToReduce.baseName
    val fileContent = fileToReduce.fileContent
    val backupFile = File(
      configuration.workingFolder,
      baseName + "." + TimeUtil.formatDateForFileName(System.currentTimeMillis()) + ".orig"
    )
    MoreFiles.asCharSink(backupFile.toPath(), StandardCharsets.UTF_8).write(fileContent)
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    @VisibleForTesting
    fun createConfiguration(
      cmd: CommandOptions,
      parserFacadeFactory: ParserFacadeFactory
    ): ReductionConfiguration {
      val sourceFile = SourceFile(
        cmd.compulsoryFlags.getSourceFile().absoluteFile,
        parserFacadeFactory.computeLanguageKind(cmd.compulsoryFlags.getSourceFile().absoluteFile)!!
      )
      val testScript = ScriptFile(cmd.compulsoryFlags.getTestScript().absoluteFile)

      require(sourceFile.parentFile.absolutePath == testScript.parentFile.absolutePath) {
        "The source file and the test script should reside in the same folder. " +
          "sourceFile:$sourceFile, testScript:$testScript"
      }
      val workingDirectory = sourceFile.parentFile
      val bestFile = getOutputFile(cmd)
      val statisticsFile =
        if (Strings.isNullOrEmpty(cmd.profilingFlags.statDumpFile)) null
        else File(cmd.profilingFlags.statDumpFile)
      val progressDumpFile =
        if (Strings.isNullOrEmpty(cmd.profilingFlags.progressDumpFile)) null
        else File(cmd.profilingFlags.progressDumpFile)

      val programFormatControl = cmd.reductionControlFlags.codeFormat.let { codeFormat ->
        if (codeFormat != null) {
          check(sourceFile.languageKind.isCodeFormatAllowed(codeFormat)) {
            "$codeFormat is not allowed for language ${sourceFile.languageKind}"
          }
          codeFormat
        } else {
          sourceFile.languageKind.defaultCodeFormatControl
        }
      }

      return ReductionConfiguration(
        workingFolder = workingDirectory,
        testScript = testScript,
        fileToReduce = sourceFile,
        bestResultFile = bestFile,
        statisticsFile = statisticsFile,
        progressDumpFile = progressDumpFile,
        programFormatControl = programFormatControl,
        fixpointReduction = cmd.reductionControlFlags.fixpoint,
        enableTestScriptExecutionCaching = cmd.cacheControlFlags.queryCaching,
        useRealDeltaDebugger = cmd.algorithmControlFlags.useRealDeltaDebugger,
        numOfReductionThreads = cmd.reductionControlFlags.getNumOfThreads(),
        parserFacadeFactory = parserFacadeFactory
      )
    }

    private fun createTokenizedProgramFactory(originalTree: ParseTree): TokenizedProgramFactory {
      val tokens = AbstractParserFacade.getTokens(originalTree)
      return TokenizedProgramFactory.createFactory(tokens)
    }

    private fun createListeners(
      enableProfiling: Boolean,
      configuration: ReductionConfiguration,
      extraListeners: Array<out AbstractReductionListener>
    ): ImmutableList<AbstractReductionListener> {
      val builder = ImmutableList.builder<AbstractReductionListener>()
      builder.add(LoggingListener())
      configuration.getStatisticsFile().map { file: File? -> builder.add(StatisticsListener(file)) }
      configuration
        .getProgressDumpFile()
        .map { file: File? -> builder.add(ProgressMonitorForNodeReducer.createForFile(file)) }
      configuration
        .testScriptStatisticsFile
        .map { file: File? -> builder.add(TestScriptExecutionListener(file)) }
      for (extraListener in extraListeners) {
        builder.add(extraListener)
      }
      if (enableProfiling) {
        val profileFile = File(
          configuration.workingFolder,
          configuration.fileToReduce.baseName + ".profile.txt"
        )
        val profile = ReductionProfileListener(profileFile)
        profile.addComment("reduction config", configuration.dumpConfiguration())
        builder.add(profile)
      }
      return builder.build()
    }

    private fun getOutputFile(cmd: CommandOptions): File {
      val sourceFile = cmd.compulsoryFlags.getSourceFile()
      if (cmd.resultOutputFlags.inPlaceReduction) {
        return sourceFile
      }
      return if (Strings.isNullOrEmpty(cmd.resultOutputFlags.outputFile)) {
        val reductionAlgorithm = cmd.algorithmControlFlags.getReductionAlgorithmName()
        File(
          sourceFile.parent, reductionAlgorithm + "_reduced_" + sourceFile.name
        )
      } else {
        File(cmd.resultOutputFlags.outputFile)
      }
    }
  }
}

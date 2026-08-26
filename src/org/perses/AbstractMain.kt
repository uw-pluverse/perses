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
package org.perses

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.cmd.EnumListMinimizerMicrobenchmarkingMode
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.TolerantFallbackParserFacades
import org.perses.listminimizer.microbenchmark.ListMinimizationMicrobenchmark
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.program.ProgramSize
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.IReductionDriver
import org.perses.reduction.LanguageProfile
import org.perses.reduction.ListMinimizerEvaluationDriver
import org.perses.reduction.QueryCacheManager
import org.perses.reduction.ReducerFactory
import org.perses.reduction.ReductionDriverParams
import org.perses.reduction.SanityCheckFailedException
import org.perses.reduction.SanityCheckResult
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptVerdict
import org.perses.reduction.createSnapshot
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.SanityCheckEvent
import org.perses.reduction.io.AbstractOriginalReductionInputs
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.ReductionFolderManager
import org.perses.util.AutoIncrementDirectory
import org.perses.util.FileSystemUtil
import org.perses.util.ReflectionUtil
import org.perses.util.Serialization
import org.perses.util.ktFine
import org.perses.util.ktInfo
import org.perses.util.ktWarning
import org.perses.util.shell.CmdOutput
import org.perses.util.transformToImmutableList
import java.io.Closeable
import java.nio.file.Files
import java.nio.file.Path
import java.time.LocalDateTime

abstract class AbstractMain<
  Cmd : PersesCommandOptions,
  ReductionDriver : IReductionDriver,
  OriginalReductionInputs : DefaultLanguageOriginalReductionInputs,
>(
  cmd: Cmd,
  protected val globalContext: GlobalContext,
) : org.perses.util.cmd.AbstractMain<Cmd>(cmd),
  Closeable {
  protected val parserFacadeFactory by lazy {
    initializeParserFacadeFactory()
  }

  protected val languageAndParserConfiguration: LanguageAndParserConfiguration by lazy {
    computeLanguageAndParserConfiguration(parserFacadeFactory)
  }

  val originalReductionInputs: OriginalReductionInputs by lazy {
    createOriginalReductionInputs(parserFacadeFactory)
  }

  /**
   * The result folder, created and populated once and shared by the reduction driver and the
   * cross-file post-pass. Mirrors [originalReductionInputs]: a lazy property backed by an abstract factory
   * ([createAndPopulateResultFolder]), since the populated/plain policy and the concrete inputs type
   * are known only in each subclass.
   */
  val resultFolder: ReductionFolder by lazy {
    createAndPopulateResultFolder()
  }

  val workingDirectory: Path by lazy {
    computeWorkingDirectory().toAbsolutePath().also {
      check(it.isAbsolute) { "Working directory must be an absolute path" }
    }
  }

  /**
   * The query cache, created once and shared by every per-file reduction driver of this reduction
   * (mirrors [resultFolder]). It is owned here -- not by the drivers -- so it outlives any driver
   * that is rebuilt per file; it is closed in [close], which returns the profiler's rented stream to
   * the file-stream pool.
   */
  val queryCacheManager: QueryCacheManager by lazy {
    QueryCacheManager.create(cmd.profilingFlags, cmd.cacheControlFlags, globalContext)
  }

  /**
   * The test-script executor, created once and shared by every reduction driver of this reduction
   * (mirrors [resultFolder]/[queryCacheManager]). Owned here -- not by the drivers -- so its thread
   * pools are reused across the per-file sweeps and the cross-file pass instead of being rebuilt per
   * driver, and its [TestScriptExecutorService.statistics] is the whole-reduction total. It is closed
   * in [close] (which deletes the temp root its folder manager creates under [workingDirectory]).
   */
  val testScriptExecutorService: TestScriptExecutorService by lazy {
    val inputs = originalReductionInputs as AbstractOriginalReductionInputs
    val tempRoot =
      workingDirectory.resolve(
        AbstractReductionIOManager.getTempRootFolderName(
          inputs.relativePathSequence().asIterable(),
          inputs.testScript.file.fileName
            .toString(),
          LocalDateTime.now(),
          currentProcessID = ProcessHandle.current().pid(),
        ),
      )
    FileSystemUtil.ensureDirExists(tempRoot)
    TestScriptExecutorService(
      reductionFolderManager = ReductionFolderManager(inputs, tempRoot),
      specifiedNumOfThreads = cmd.reductionControlFlags.getNumOfThreads(),
      scriptExecutionTimeoutInSeconds =
        cmd.reductionControlFlags.testScriptExecutionTimeoutInSeconds,
      scriptExecutionKeepTryingAfterTimeout =
        cmd.reductionControlFlags.testScriptExecutionKeepWaitingAfterTimeout,
      globalExecutionCache = globalContext.globalExecutionCache,
    )
  }

  val outputDirectory: Path by lazy {
    var outputDirectory: Path? = getUserSpecifiedOutputDirectory()
    if (outputDirectory == null) {
      outputDirectory =
        AutoIncrementDirectory(DEFAULT_PERSES_BEST_DIR_NAME)
          .computeAndCreate(workingDirectory)
    }
    if (!Files.exists(outputDirectory)) {
      Files.createDirectories(outputDirectory)
    }
    check(Files.isDirectory(outputDirectory)) {
      "$outputDirectory is not a directory."
    }
    if (!allowsInPlaceReduction) {
      originalReductionInputs.checkOutputDirectoryIsNotInPlace(outputDirectory)
    }
    outputDirectory
  }

  protected fun getUserSpecifiedOutputDirectory(): Path? = cmd.resultOutputFlags.outputDir

  /**
   * Whether this main may reduce *in place* -- write reduced content back over the input files.
   *
   * Defaults to `false` (fail closed): perses reduces out of place into a separate result folder and
   * no longer backs up inputs (see [org.perses.reduction.AbstractProgramReductionDriver]), so the
   * output directory must not coincide with any input -- enforced by
   * [org.perses.reduction.io.AbstractOriginalReductionInputs.checkOutputDirectoryIsNotInPlace]. The
   * ppr diff-based mains override this to `true`: they deliberately reduce the seed/variant in place
   * in the test-script directory (see [org.perses.ppr.diff.DiffOriginalReductionInputs]).
   */
  protected open val allowsInPlaceReduction: Boolean = false

  protected val listenerManager: AsyncReductionListenerManager by lazy {
    createAsyncReductionListenerManager()
  }

  /**
   * The reduction pipeline, in three stages:
   *  1. [runInitialSanityCheck] -- verify the original input passes the test script before reducing;
   *  2. [runContentReductionToFixpoint] -- per-file then cross-file content reduction, repeated to a
   *     global fixpoint so each phase picks up the opportunities the other re-enables;
   *  3. [runFileDeletion] -- a terminal pass that drops any whole mutable file proven unnecessary.
   *
   * Deletion runs last, once. Folding it into the content fixpoint was tried and reverted: a file is
   * deletable only when the test passes without it, so content reduction can already neutralize it
   * (reduce it to a form that drops its cross-file constraints) and unlock the same survivor
   * reductions. Interleaving therefore produced byte-identical results across every multi-file and
   * grammar configuration tested, while running extra rounds; terminal deletion is simpler and
   * slightly faster. (Full rationale: `internal_doc/why_file_deletion_is_terminal.md`.) The folder
   * readers still derive their live set from disk ([ReductionFolder.sequenceOfLiveMutableFiles] /
   * [ReductionFolder.readLiveMutableFileContents]), so the final size metrics over the post-deletion
   * subset folder are correct.
   */
  override fun internalRun() {
    runInitialSanityCheck()
    // The reduction lifecycle events fire exactly once here, around the whole pipeline -- not inside
    // the reduction drivers, of which a single reduction runs many (per-file warm-up and full sweeps,
    // plus the cross-file pass). The drivers report only their per-fixpoint and ad-hoc events; the
    // start/end pair belongs to this orchestrating method.
    val reductionStartEvent =
      ReductionStartEvent(
        currentTimeMillis = System.currentTimeMillis(),
        perFileSizeMetrics = computeWholeReductionSizeMetrics(),
        commandLineOptions =
          Serialization.toYamlString(
            cmd,
            objectMapperCustomizer = Serialization::customizeObjectMapperByUsingBasenameForPath,
          ),
      )
    listenerManager.onReductionStart(reductionStartEvent)
    try {
      if (
        cmd.listMinimizerMicrobenchmarkingFlags.mode ==
        EnumListMinimizerMicrobenchmarkingMode.EVALUATE
      ) {
        // EVALUATE replaces the reduction stages, not the lifecycle. Branching here keeps the
        // sanity check -- which, pointed at a recorded folder, is exactly the check that the
        // recording is still interesting -- and keeps both reduction events, and with them every
        // listener this binary builds: the statistics summary, the size trend, the progress dump.
        //
        // The evaluator is built here rather than returned from [createReductionDriver], so the
        // mode is decided in exactly one place. It runs once: evaluation commits nothing, so a
        // content fixpoint would re-run an identical measurement, and the cross-file and
        // file-deletion phases would reduce the very program the recorded ranges index into.
        createListMinimizerEvaluationDriver(reductionStartEvent).use { it.reduce() }
      } else {
        runContentReductionToFixpoint(reductionStartEvent)
        runFileDeletion(reductionStartEvent)
      }
    } finally {
      val finalMetrics =
        runCatching { computeWholeReductionSizeMetrics() }
          .onFailure { listenerManager.onCriticalException(it as Exception) }
          .getOrDefault(zeroPerFileSizeMetrics())
      listenerManager.onReductionEnd(
        reductionStartEvent.createEndEvent(
          perFileSizeMetrics = finalMetrics,
          testScriptStatistics = testScriptExecutorService.statistics.createSnapshot(),
        ),
      )
    }
  }

  /**
   * The whole reduction's size metrics, one slot per mutable file, read from [resultFolder] (the
   * source of truth). Each file is sized with its own language's facade when that facade can lex it,
   * else with a tolerant fallback (Line always lexes), so a file that does not parse/lex under its
   * real grammar is still measured rather than crashing the size report -- consistent with the
   * tolerant-grammar fallback the reduction itself uses. A mixed-language set is measured per file; a
   * file already removed by the terminal file-deletion phase is absent from the folder and reports
   * [ProgramSize.ZERO]. Called only at the reduction's start and end, so re-resolving facades here is
   * negligible.
   */
  private fun computeWholeReductionSizeMetrics(): PerFileSizeMetrics {
    val inputs = originalReductionInputs as AbstractOriginalReductionInputs
    val realFacadeByLanguage = HashMap<LanguageKind, AbstractParserFacade>()
    return PerFileSizeMetrics(
      inputs,
      inputs.mutableFiles.transformToImmutableList { file ->
        val absPath = resultFolder.computeAbsPathForOrigFile(file)
        if (Files.exists(absPath)) {
          val language = computeLanguageForFile(absPath)
          val realFacade =
            realFacadeByLanguage.getOrPut(language) {
              computePlausibleParserFacades(language).defaultParserFacade.create()
            }
          computeProgramSizeTolerantly(realFacade, absPath)
        } else {
          ProgramSize.ZERO
        }
      },
    )
  }

  // Size [absPath] with [realFacade] when it can lex the content, else walk down the tolerant fallback
  // ladder (the adaptive Dyck rung always lexes). Only an unparsable/unlexable file leaves the real
  // grammar; its metric
  // is then on a fallback grammar's tokens, but start and end size with the same fallback so the
  // reported reduction stays meaningful.
  private fun computeProgramSizeTolerantly(
    realFacade: AbstractParserFacade,
    absPath: Path,
  ): ProgramSize<Unit> {
    val failures = mutableListOf<Exception>()
    var facade: AbstractParserFacade? = realFacade
    while (facade != null) {
      try {
        return facade.computeProgramSizeOf(absPath)
      } catch (e: Exception) {
        failures.add(e)
        facade = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(facade)
      }
    }
    // The whole ladder failed (the Dyck rung always lexes, so this is effectively unreachable): surface every
    // grammar's failure together -- the real grammar's as the primary, the rest attached as suppressed.
    val primary = failures.first()
    failures.drop(1).forEach(primary::addSuppressed)
    throw primary
  }

  /**
   * Stage 2 -- per-file then cross-file content reduction, repeated to a global fixpoint.
   *
   * A cross-file pass can re-enable per-file opportunities (e.g. removing a declaration used across
   * files unlocks per-file deletions of its now-dead uses), and the reverse holds too. Each phase
   * already runs to its own internal fixpoint, but a single per-file-then-cross-file round does not
   * see what the other phase re-enables, so the round is repeated.
   *
   * Convergence is detected on the cross-file phase: [runPerFileReductionToFixpoint] returns with the
   * per-file stack at its own fixpoint, so it cannot change the set further on its own; if the
   * following [runCrossFileReductionToFixpoint] then leaves the folder contents unchanged, neither
   * phase can make progress and the global fixpoint is reached -- so the loop stops as soon as a
   * cross-file pass changes nothing. (This also covers the no-cross-file case -- the default and the
   * base `perses` binary -- where the first cross-file pass is a no-op and the loop exits after a
   * single per-file pass.)
   *
   * A cross-file change re-enables per-file work, so the loop otherwise continues -- but it must
   * still terminate even when per-file and cross-file form a cycle (per-file re-inflating what
   * cross-file removed, or a round trading non-blank character count -- the metric here -- for a
   * canonical-token-count win the per-file stack drives by). So, mirroring
   * [org.perses.reduction.scheduler.ReducerScheduler]'s fixpoint guard, the **round-over-round** size
   * is tracked: a strictly-smaller round resets a counter, a non-shrinking one increments it, and the
   * loop gives up once [MAX_NON_SHRINKING_CONTENT_ROUNDS] non-shrinking rounds occur in a row. Since
   * strictly-shrinking rounds are finite (size is bounded below by 0), the loop terminates.
   *
   * File deletion is excluded -- it is the strictly-terminal stage (see [internalRun]) -- so the
   * folder's mutable-file set is complete on every round here.
   */
  private fun runContentReductionToFixpoint(reductionStartEvent: ReductionStartEvent) {
    var sizeAtPreviousRoundEnd = nonBlankCharCountOf(resultFolder.readLiveMutableFileContents())
    var countOfNonShrinkingRounds = 0
    while (true) {
      runPerFileReductionToFixpoint(reductionStartEvent)
      val contentsBeforeCrossFile = resultFolder.readLiveMutableFileContents()
      runCrossFileReductionToFixpoint(reductionStartEvent)
      val contentsAfterCrossFile = resultFolder.readLiveMutableFileContents()
      if (contentsAfterCrossFile == contentsBeforeCrossFile) {
        // Cross-file changed nothing on top of the per-file fixpoint: global fixpoint reached.
        return
      }
      // Cross-file changed the set, so another per-file pass may find more -- but guard against a
      // non-shrinking per-file<->cross-file cycle by requiring round-over-round progress.
      val sizeAtThisRoundEnd = nonBlankCharCountOf(contentsAfterCrossFile)
      if (sizeAtThisRoundEnd < sizeAtPreviousRoundEnd) {
        countOfNonShrinkingRounds = 0
      } else if (++countOfNonShrinkingRounds >= MAX_NON_SHRINKING_CONTENT_ROUNDS) {
        return
      }
      sizeAtPreviousRoundEnd = sizeAtThisRoundEnd
    }
  }

  /**
   * Total non-blank character count over [contents]. The content phases span a possibly
   * multi-language file set with no single parser facade, so this loop measures non-blank character
   * count rather than token count to stay language-agnostic; it is also the metric the cross-file
   * stack itself drives by.
   */
  private fun nonBlankCharCountOf(contents: Map<*, String>): Long =
    contents.values.sumOf { content -> content.count { !Character.isWhitespace(it) }.toLong() }

  /**
   * Phase 1 -- the initial (Layer-1) sanity check. Once [resultFolder] has been populated with the
   * original input files -- the source of truth shared by every reduction driver and the cross-file
   * post-pass -- run the test script directly against it. If it passes, reduction proceeds; if not,
   * the script is wrong for these inputs (or the folder was mis-populated) and there is nothing to
   * reduce, so it aborts. Either way the outcome is reported once via [SanityCheckEvent]; this is the
   * sole initial sanity check (the per-driver check it replaced has been removed).
   *
   * The check is parser-facade-independent (it tests the raw files, not a spar-tree), and it runs
   * the script directly against the folder rather than through the [TestScriptExecutorService], so
   * it is not counted in the reduction's script-execution statistics. It complements the per-reducer
   * (Layer-2) check
   * ([org.perses.reduction.AbstractReductionDriver.checkRepresentationPreservesPropertyOrThrow]),
   * which verifies that each reducer's reconstructed representation still preserves the property.
   */
  private fun runInitialSanityCheck() {
    resultFolder.checkAllInputFilesPopulated()
    val runTest = { resultFolder.runTestScript() }
    val result: SanityCheckResult =
      if (runTest().isInteresting) {
        SanityCheckResult.Passing
      } else {
        SanityCheckResult.Failing(buildInitialSanityFailure(runTest))
      }
    listenerManager.onSanityCheck(
      SanityCheckEvent(
        currentTimeMillis = System.currentTimeMillis(),
        perFileSizeMetrics = zeroPerFileSizeMetrics(),
        sanityCheckResult = result,
      ),
    )
    if (result is SanityCheckResult.Failing) {
      listenerManager.onCriticalException(result.exception)
      throw result.exception
    }
  }

  /**
   * The original input does not pass the test script. Re-run it a few times to determine whether the
   * property is flaky and build a pretty-printed diagnostic.
   */
  private fun buildInitialSanityFailure(
    runTest: () -> TestScriptVerdict,
  ): SanityCheckFailedException {
    logger.ktInfo { "The initial sanity check failed." }
    val flakinessResult =
      PropertyFlakinessChecker(
        numberOfTrials = 5,
        initialNumOfUninteresting = 1,
        runTest,
      ).run().computeResult()
    return SanityCheckFailedException(
      buildInitialSanityFailureMessage(
        cmdOutput = resultFolder.testScript.runAndCaptureOutput(),
        flakinessResult = flakinessResult,
      ),
    )
  }

  /** Size metrics with a zero entry per mutable file -- the [SanityCheckEvent] reports the check's
   * result, not sizes, so the metrics are unused by its listeners. */
  private fun zeroPerFileSizeMetrics(): PerFileSizeMetrics =
    (originalReductionInputs as AbstractOriginalReductionInputs).let { inputs ->
      PerFileSizeMetrics(inputs, inputs.mutableFiles.transformToImmutableList { ProgramSize.ZERO })
    }

  private fun buildInitialSanityFailureMessage(
    cmdOutput: CmdOutput,
    flakinessResult: PropertyFlakinessChecker.Result,
  ): String =
    """The initial sanity check failed.

      ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
      *
      * The script exit code is ${cmdOutput.exitCode}
      * The files have been saved, and you can check them at:
      *     ${resultFolder.path}
      * ${flakinessResult.describeResult()}
      ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****

      ============= stderr =============
      ${cmdOutput.stderr.combinedLines.let { it.ifBlank { "<empty>" } }}

      ============= stdout =============
      ${cmdOutput.stdout.combinedLines.let { it.ifBlank { "<empty>" } }}
    """.lineSequence()
      .map { it.trimStart() }
      .joinToString("\n")

  /**
   * Runs the test script several times to decide whether the property is flaky -- moved here from
   * the driver-level sanity check so the Layer-1 result-folder check owns the flakiness diagnostics.
   */
  class PropertyFlakinessChecker(
    val numberOfTrials: Int,
    val initialNumOfUninteresting: Int,
    private val sanityChecker: () -> TestScriptVerdict,
  ) {
    private val results = mutableListOf<TestScriptVerdict>()

    init {
      require(numberOfTrials > 0) { numberOfTrials }
    }

    fun run(): PropertyFlakinessChecker {
      check(results.isEmpty()) { "This method can only be called once." }
      (1..numberOfTrials).forEach { _ ->
        results.add(sanityChecker.invoke())
      }
      check(results.size == numberOfTrials)
      return this
    }

    fun computeResult() =
      Result(
        numOfInteresting = results.count { it.isInteresting },
        numOfUninteresting = results.count { it.isNotInteresting } + initialNumOfUninteresting,
      )

    data class Result(
      val numOfInteresting: Int,
      val numOfUninteresting: Int,
    ) {
      init {
        require(numOfInteresting >= 0)
        require(numOfUninteresting >= 0)
      }

      val totalNumber: Int
        get() = numOfInteresting + numOfUninteresting

      val isFlaky = numOfInteresting != 0 && numOfUninteresting != 0

      fun describeResult(): String =
        buildString {
          append("The property test is")
          if (!isFlaky) {
            append(" not")
          }
          append(" flaky. ")
          append("#total runs: $totalNumber")
          append(", #interesting: $numOfInteresting, #uninteresting: $numOfUninteresting")
        }
    }
  }

  /**
   * Builds the driver that evaluates one recorded problem with one list minimizer.
   *
   * Lives here rather than in a subclass because it needs nothing a subclass owns: [Cmd] is bound by
   * [PersesCommandOptions], so the flag group is visible, and every collaborator it uses is declared
   * here. Recording is likewise handled once, in [AbstractProgramReductionDriver], so putting the
   * wiring in one binary's `Main` would split one feature across two levels of the hierarchy.
   *
   * The program is never parsed under its real grammar -- only lexed -- which matters because a
   * mid-reduction program need not parse cleanly.
   */
  private fun createListMinimizerEvaluationDriver(
    reductionStartEvent: ReductionStartEvent,
  ): ListMinimizerEvaluationDriver {
    val flags = cmd.listMinimizerMicrobenchmarkingFlags
    val microbenchmark = ListMinimizationMicrobenchmark.readFrom(flags.microbenchmarkFile!!)
    val targetFile = findRecordedTargetFile(microbenchmark)
    val languageKind = targetFile.dataKind as LanguageKind
    // The default facade, not one resolved by probing: evaluation needs the lexer, and resolving a
    // canonical facade would mean parsing the very program that may not parse.
    return ListMinimizerEvaluationDriver.create(
      params = createReductionDriverParams(reductionStartEvent),
      mainFile = targetFile,
      // The default facade, not one resolved by probing: it decides how candidates are printed and
      // how tokens are counted, while the driver builds its tree with FlatTokenList so the recorded
      // program is never parsed under this grammar.
      resolvedParserFacade =
        computePlausibleParserFacades(languageKind).defaultParserFacade.create(),
      microbenchmark = microbenchmark,
      minimizerType = flags.minimizerUnderEvaluation!!,
      outputDirectory = FileSystemUtil.ensureDirExists(flags.evaluationOutputDirectory!!),
    )
  }

  private fun findRecordedTargetFile(microbenchmark: ListMinimizationMicrobenchmark) =
    originalReductionInputs.mutableFiles.singleOrNull {
      originalReductionInputs.getRelativePathForOrigFile(it).toString() ==
        microbenchmark.targetFilePath
    } ?: error(
      "The recorded target file '${microbenchmark.targetFilePath}' is not among the mutable " +
        "files ${originalReductionInputs.relativePathSequence().toList()}. Point --input at the " +
        "problem's own input/ directory.",
    )

  /**
   * The profile whose extra reducers a driver may run, and the factory that resolves `--alg`.
   * Evaluation runs no reducer pipeline, so the defaults are inert; a reducing binary overrides them.
   */
  protected open val languageProfile: LanguageProfile
    get() = LanguageProfile.DEFAULT

  protected open val reducerFactory: ReducerFactory
    get() = ReducerFactory.DEFAULT

  /**
   * Everything that configures a reduction independently of which file is reduced. Shared by the
   * per-file drivers and the evaluation driver so the two cannot drift apart in how they are wired.
   */
  protected fun createReductionDriverParams(reductionStartEvent: ReductionStartEvent) =
    ReductionDriverParams(
      globalContext = globalContext,
      cmd = cmd,
      workingDirectory = workingDirectory,
      resultFolder = resultFolder,
      originalReductionInputs = originalReductionInputs,
      parserFacadeCandidatesFor = { languageKind -> computePlausibleParserFacades(languageKind) },
      codeFormatFor = { languageKind -> getSpecifiedCodeFormatControl(languageKind) },
      listenerManager = listenerManager,
      shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
      languageProfile = languageProfile,
      reducerFactory = reducerFactory,
      queryCache = queryCacheManager.cache,
      reductionStartEvent = reductionStartEvent,
      executorService = testScriptExecutorService,
    )

  /**
   * The code format to render a file of [languageKind] in: the one `--code-format` asked for, or the
   * language's own default when the flag is unset or names a format this language forbids.
   *
   * The mismatch happens when a file falls back to a tolerant grammar (Line/Dyck) whose allowed
   * formats differ. Honoring the request would crash the per-file driver, so this mirrors the
   * on-the-fly adaptive-format switch in AbstractProgramReductionDriver.
   */
  protected fun getSpecifiedCodeFormatControl(languageKind: LanguageKind): EnumFormatControl {
    val codeFormat =
      cmd.reductionControlFlags.codeFormat ?: return languageKind.defaultCodeFormatControl
    if (languageKind.isCodeFormatAllowed(codeFormat)) {
      return codeFormat
    }
    logger.ktWarning {
      "The requested code format $codeFormat is not allowed for language ${languageKind.name} " +
        "(allowed: ${languageKind.allowedCodeFormatControl}); using its default " +
        "${languageKind.defaultCodeFormatControl} instead."
    }
    return languageKind.defaultCodeFormatControl
  }

  /**
   * Cross-file reduction: whole-set passes run inside a [runContentReductionToFixpoint] round, after
   * the per-file phase has committed its result to [resultFolder]. The default does nothing; a binary
   * whose profile contributes cross-file transformations overrides this to run them over the
   * already-reduced file set.
   */
  protected open fun runCrossFileReductionToFixpoint(reductionStartEvent: ReductionStartEvent) {}

  /**
   * File deletion -- the strictly-terminal stage (see [internalRun]): drops any whole mutable file
   * that proves unnecessary (the property still holds without it). The default does nothing; a binary
   * that supports multi-file reduction overrides this. It must remain the last stage because it can
   * shrink the result-folder file set below `mutableFiles`, and it only ever shrinks it.
   */
  protected open fun runFileDeletion(reductionStartEvent: ReductionStartEvent) {}

  /**
   * The per-file reduction phase: builds the reduction driver and runs it. The driver resolves the
   * parser facade that parses the input (see [createReductionDriver]); a parse failure surfaces
   * directly from its construction.
   */
  private fun runPerFileReductionToFixpoint(reductionStartEvent: ReductionStartEvent) {
    createReductionDriver(originalReductionInputs, reductionStartEvent).use { it.reduce() }
  }

  protected fun computeLanguageForFile(file: Path): LanguageKind =
    when (val configuration = languageAndParserConfiguration) {
      is LanguageAndParserConfiguration.Automatic -> {
        parserFacadeFactory.computeLanguageKindOrThrow(file)
      }

      is LanguageAndParserConfiguration.UserSpecifiedParser -> {
        configuration.languageKind
      }

      is LanguageAndParserConfiguration.UserSpecifiedLanguage -> {
        configuration.languageKind
      }
    }

  protected fun computePlausibleParserFacades(
    languageKind: LanguageKind,
  ): AbstractParserFacadeFactory.ParserFacadeList {
    val configuration = languageAndParserConfiguration
    val result =
      if (configuration is LanguageAndParserConfiguration.UserSpecifiedParser) {
        AbstractParserFacadeFactory.ParserFacadeList(
          defaultParserFacade = configuration.parserFacade,
          otherParserFacades = ImmutableList.of(),
        )
      } else {
        parserFacadeFactory.getParserFacadeListForOrNull(languageKind)
      }
    checkNotNull(result) {
      """
        |$originalReductionInputs
        |
        |$languageAndParserConfiguration
      """.trimMargin()
    }
    return result
  }

  abstract fun computeLanguageAndParserConfiguration(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): LanguageAndParserConfiguration

  abstract fun computeWorkingDirectory(): Path

  protected abstract fun createAsyncReductionListenerManager(): AsyncReductionListenerManager

  protected abstract fun createOriginalReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): OriginalReductionInputs

  /**
   * Creates the result folder. The default populates it with the original inputs, which is what the
   * token-reduction path requires (the driver reads the program and siblings from it). Subclasses
   * whose IO manager does not read the folder (e.g. list-diff) override this to skip populating.
   */
  private fun createAndPopulateResultFolder(): ReductionFolder =
    AbstractReductionIOManager.createPopulatedResultFolder(
      originalReductionInputs as AbstractOriginalReductionInputs,
      globalContext.shaAlgorithm,
      outputDirectory,
    )

  private fun initializeParserFacadeFactory(): AbstractParserFacadeFactory {
    val builtinFacadeFactory = createBuiltinParserFacadeFactory()
    val extFacadeFactory = createExtFacadeFactory()
    return CompositeParserFacadeFactory(
      builtinFactory = builtinFacadeFactory,
      extFactory = extFacadeFactory,
    )
  }

  sealed class LanguageAndParserConfiguration {
    object Automatic : LanguageAndParserConfiguration()

    class UserSpecifiedLanguage(
      val languageKind: LanguageKind,
    ) : LanguageAndParserConfiguration()

    class UserSpecifiedParser(
      val languageKind: LanguageKind,
      val parserFacade: AbstractParserFacadeFactory.ParserFacadeCreator,
    ) : LanguageAndParserConfiguration()
  }

  abstract fun createReductionDriver(
    originalReductionInputs: OriginalReductionInputs,
    reductionStartEvent: ReductionStartEvent,
  ): ReductionDriver

  protected open fun createExtFacadeFactory(): AbstractParserFacadeFactory =
    SingleParserFacadeFactory.createEmptyFactory()

  override fun close() {
    val klassName: String = this::class.java.name
    logger.ktFine { "Closing the resources used in $klassName" }
    // Close the cache before globalContext (closed by its external owner): its profiler's rented
    // stream must be returned before the file-stream pool is closed.
    if (ReflectionUtil.isInitialized(this::queryCacheManager)) {
      queryCacheManager.close()
    }
    if (ReflectionUtil.isInitialized(this::listenerManager)) {
      listenerManager.close()
    }
    // Owned here (shared by all drivers), so it is closed here -- shutting down its thread pools and
    // deleting the temp root its folder manager created.
    if (ReflectionUtil.isInitialized(this::testScriptExecutorService)) {
      testScriptExecutorService.close()
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    protected const val DEFAULT_PERSES_BEST_DIR_NAME = "perses_result"

    /**
     * How many consecutive content-fixpoint rounds that change the folder without shrinking it (by
     * non-blank character count) are tolerated before [runContentReductionToFixpoint] gives up. A
     * round shrinks tokens but not chars rarely, so a small budget suffices; it exists only to
     * guarantee termination, not to keep reducing. Mirrors `ReducerScheduler`'s
     * `maxCountOfAllowedChanges`.
     */
    private const val MAX_NON_SHRINKING_CONTENT_ROUNDS = 3

    fun createBuiltinParserFacadeFactory(): AbstractParserFacadeFactory =
      builderWithBuiltinLanguages().build()
  }
}

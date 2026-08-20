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
import org.apache.commons.lang3.StringUtils
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil.createParserFacadeFactory
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.LanguageProfile
import org.perses.reduction.PerFileReductionDriver
import org.perses.reduction.ReducerFactory
import org.perses.reduction.crossfile.CrossFileOutputManagerFactory
import org.perses.reduction.crossfile.CrossFileReducerFactory
import org.perses.reduction.crossfile.CrossFileReductionDriver
import org.perses.reduction.crossfile.CrossFileReductionIOManager
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.CommandLineProcessor.HelpRequestProcessingDecision
import java.nio.file.Path

class Main(
  cmd: PersesCommandOptions,
  globalContext: GlobalContext,
  /**
   * The language profile that customizes this binary's reducer set and default pipeline. The plain
   * `perses` binary passes [LanguageProfile.DEFAULT] (no customization); a language-specific binary
   * (e.g. `perses_cxx`) passes its own profile. Injected as a value rather than overridden, so the
   * choice is made once and explicitly at the entry point.
   */
  override val languageProfile: LanguageProfile,
) : AbstractMain<
    PersesCommandOptions,
    PerFileReductionDriver,
    DefaultLanguageOriginalReductionInputs,
  >(
    cmd,
    globalContext,
  ) {
  // The reducers selectable by name (`--alg`, `--list-algs`): the built-ins plus the ones the profile
  // registers. (Weaving into the pipeline is separate — see languageProfile.customizeReductionPipeline.)
  override val reducerFactory =
    ReducerFactory.createWithExtra(
      languageProfile.extraReducerAnnotations(),
    )

  override fun createExtFacadeFactory(): AbstractParserFacadeFactory {
    // Cannot close this file, as the file has class loader to load the parser facade classes.
    return createParserFacadeFactory(
      cmd.languageControlFlags.languageJarFiles,
    )
  }

  override fun validateCommandOptions() {
    super.validateCommandOptions()
    cmd.algorithmControlFlags.mainReductionAlgorithm?.let {
      check(reducerFactory.isValidReducerName(it)) { "Invalid main reduction algorithm $it" }
    }
    cmd.algorithmControlFlags.cleanupReductionAlgorithm?.let {
      check(reducerFactory.isValidReducerName(it)) { "Invalid cleanup reduction algorithm $it" }
    }
    cmd.languageControlFlags.languageName.trim().let { lang ->
      check(
        lang.isBlank() ||
          parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(lang) != null,
      ) {
        "Invalid language name $lang"
      }
    }
    cmd.languageControlFlags.designatedParserFacadeClassName.trim().let { klassName ->
      check(
        klassName.isBlank() ||
          parserFacadeFactory.getParserFacadeClassForClassNameOrNull(klassName) != null,
      ) {
        "Invalid parser facade class $klassName"
      }
    }
  }

  override fun computeLanguageAndParserConfiguration(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): LanguageAndParserConfiguration =
    HelperForPersesMain.computeLanguageAndParserConfiguration(
      parserFacadeFactory,
      cmd.languageControlFlags,
    )

  override fun processOtherHelpRequests(): HelpRequestProcessingDecision {
    if (cmd.algorithmControlFlags.listAllReductionAlgorithms) {
      println("All available reduction algorithms: ")
      println(reducerFactory.printAllReductionAlgorithms())
      return HelpRequestProcessingDecision.EXIT
    }
    if (cmd.languageControlFlags.listParserFacades) {
      println("All currently supported parser facade classes:\n")
      parserFacadeFactory
        .languageSequence()
        .sortedBy { it.name }
        .withIndex()
        .forEach { (index, lang) ->
          val id = StringUtils.leftPad(index.toString(), 2, ' ')
          val parserFacadeList = parserFacadeFactory.getParserFacadeListForOrNull(lang)!!
          val numOfParserFacades = parserFacadeList.numberOfParserFacades()
          val postfix = if (numOfParserFacades > 1) "s" else ""
          println("$id: $lang ($numOfParserFacades parser facade$postfix):")
          val prefix = "    Default: "
          println("$prefix${parserFacadeList.defaultParserFacade.klass.qualifiedName}")

          if (parserFacadeList.otherParserFacades.isNotEmpty()) {
            val firstEntry =
              parserFacadeList.otherParserFacades
                .first()
                .klass.qualifiedName
            println("    Others : $firstEntry")
            parserFacadeList.otherParserFacades.drop(1).forEach {
              println("             ${it.klass.qualifiedName}")
            }
          }
          println()
        }
      return HelpRequestProcessingDecision.EXIT
    }
    if (cmd.languageControlFlags.listLangs) {
      println("All currently supported languages:")
      val maxLength = computeMaxLengthOfLanguageNames(parserFacadeFactory)
      parserFacadeFactory.languageSequence().sortedBy { it.name }.forEach {
        println("    ${it.name.padEnd(maxLength, padChar = ' ')}: $it")
      }
      return HelpRequestProcessingDecision.EXIT
    }
    return HelpRequestProcessingDecision.NO_EXIT
  }

  private fun computeMaxLengthOfLanguageNames(parserFacadeFactory: AbstractParserFacadeFactory) =
    parserFacadeFactory.languageSequence().maxOfOrNull { it.name.length } ?: 0

  override fun createReductionDriver(
    originalReductionInputs: DefaultLanguageOriginalReductionInputs,
    reductionStartEvent: ReductionStartEvent,
  ): PerFileReductionDriver =
    PerFileReductionDriver(createReductionDriverParams(reductionStartEvent))

  // After per-file reduction completes, run the profile's cross-file transformations (if any) over
  // the already-reduced result folder as a whole-set pass. The base `perses` binary's profile
  // contributes none, so this is a no-op there; `perses_java` runs the override-removal pass.
  override fun runCrossFileReductionToFixpoint(reductionStartEvent: ReductionStartEvent) {
    val transformations = languageProfile.crossFileTransformations()
    if (transformations.isEmpty()) {
      return
    }
    runCrossFileDriver(
      ImmutableList.of(CrossFileReductionDriver.transformationReducerFactory(transformations)),
      reductionStartEvent,
    )
  }

  // The strictly-terminal phase (see AbstractMain.internalRun): drop any whole mutable file that
  // proves unnecessary, in its own driver placed last. A multi-file cleanup, so it only runs when
  // there is more than one mutable file.
  override fun runFileDeletion(reductionStartEvent: ReductionStartEvent) {
    if (originalReductionInputs.mutableFiles.size <= 1) {
      return
    }
    runCrossFileDriver(
      ImmutableList.of(CrossFileReductionDriver.FILE_DELETION_REDUCER_FACTORY),
      reductionStartEvent,
    )
  }

  private fun runCrossFileDriver(
    reducerFactories: ImmutableList<CrossFileReducerFactory>,
    reductionStartEvent: ReductionStartEvent,
  ) {
    val shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm
    val ioManager =
      CrossFileReductionIOManager(
        workingDirectory = workingDirectory,
        originalReductionInputs = originalReductionInputs,
        // Reuse the shared result folder, now holding the per-file-reduced files: the cross-file
        // driver reads it as its starting program and writes accepted improvements back to it.
        resultFolder = resultFolder,
      )
    CrossFileReductionDriver(
      globalContext = globalContext,
      ioManager = ioManager,
      outputManagerFactory = CrossFileOutputManagerFactory(originalReductionInputs, shaAlgorithm),
      reducerFactories = reducerFactories,
      listenerManager = listenerManager,
      executorService = testScriptExecutorService,
      hideTimestampsInLog = cmd.verbosityFlags.hideTimestamps,
      reductionStartEvent = reductionStartEvent,
    ).use { it.reduce() }
  }

  // Use the test script's directory as the working directory. The test script and every input file
  // reside in the same directory, so this matches the input file's parent for the single-file case,
  // while not materializing the single-file originalReductionInputs field (which the multi-file path must
  // not touch).
  override fun computeWorkingDirectory(): Path =
    cmd.inputFlags
      .getTestScript()
      .toAbsolutePath()
      .parent

  override fun createOriginalReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): DefaultLanguageOriginalReductionInputs {
    val inputFlags = cmd.inputFlags
    // This single-file entry reduces a single input file (the first of inputFiles). Reducing
    // multiple files together is handled by a separate multi-file orchestrator (dispatched on
    // inputFiles.size).
    return DefaultLanguageOriginalReductionInputs.create(
      testScriptPath = inputFlags.getTestScript(),
      sourceFilePaths = inputFlags.computeInputFiles(),
      dependencyFiles = inputFlags.computeDeps(),
      languageKindComputer = { sourceFileAbsPath ->
        computeLanguageForFile(sourceFileAbsPath)
      },
    )
  }

  override fun createAsyncReductionListenerManager(): AsyncReductionListenerManager =
    PersesListenerManagerCreator.createAsyncReductionListenerManager(
      cmd = cmd,
      fileStreamPool = globalContext.fileStreamPool,
      outputDirectory = outputDirectory,
    )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun main(args: Array<String>) {
      launch(args, programName = Main::class.qualifiedName!!) { cmd, globalContext ->
        Main(cmd, globalContext, LanguageProfile.DEFAULT)
      }
    }

    /**
     * Shared entry point: parse the command line, build the [Main] via [mainFactory], and run. A
     * language-specific binary calls this from its own `main`, passing a [mainFactory] that supplies
     * its [LanguageProfile] (which contributes the profile's reducers via the [ReducerFactory] [Main]
     * builds from it).
     */
    @JvmStatic
    fun launch(
      args: Array<String>,
      programName: String,
      mainFactory: (PersesCommandOptions, GlobalContext) -> Main,
    ) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { PersesCommandOptions() },
          programName = programName,
          args = args,
        )
      if (processor.process() == HelpRequestProcessingDecision.EXIT) {
        return
      }
      val cmd = processor.cmd
      Util.useResources(
        {
          GlobalContext(
            enableGlobalCache = cmd.cacheControlFlags.enableGlobalCache,
            globalCacheFile = cmd.cacheControlFlags.globalCacheFile,
            pathToSaveUpdatedGlobalCache = cmd.cacheControlFlags.pathToSaveUpdatedGlobalCache,
            shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
          )
        },
        { globalContext -> mainFactory(cmd, globalContext) },
      ) { _, main ->
        main.run()
      }
    }
  }
}

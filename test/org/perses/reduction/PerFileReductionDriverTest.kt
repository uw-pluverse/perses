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
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.PersesCommandOptions
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.program.ProgramSize
import org.perses.program.SourceFile
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.io.ReductionFolderManager
import org.perses.util.FileSystemUtil
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.shell.Shells
import org.perses.util.transformToImmutableList
import java.nio.file.Files
import kotlin.io.path.createFile
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class PerFileReductionDriverTest {
  private val workDir = FileSystemUtil.createTempDirForObject(this)
  private val outputDir =
    workDir.resolve("default_test_output_dir").apply {
      FileSystemUtil.ensureDirExists(this)
    }
  private val inputDir =
    workDir.resolve("input_dir").apply {
      FileSystemUtil.ensureDirExists(this)
    }
  private val fileA =
    inputDir.resolve("a.c").apply {
      createFile()
      writeText("int aaa; int bbb;")
    }
  private val fileB =
    inputDir.resolve("b.c").apply {
      createFile()
      writeText("int ccc; int ddd; int eee;")
    }
  private val scriptFile =
    inputDir.resolve("r.sh").apply {
      createFile()
      FileSystemUtil.setExecutable(this)
      writeText(
        """
        |${Shells.SHEBANG_BASH}
        |grep "aaa" a.c && grep "ccc" b.c
        |
        """.trimMargin(),
      )
    }
  private val facadeFactory = builderWithBuiltinLanguages().build()
  private val listenerManager =
    AsyncReductionListenerManager(
      listeners = ImmutableList.of(),
      synchronousMode = true,
    )
  private val globalContext =
    GlobalContext(
      enableGlobalCache = false,
      globalCacheFile = null,
      pathToSaveUpdatedGlobalCache = null,
      shaAlgorithm = EnumShaAlgorithm.SHA512,
    )

  private val cmd =
    PersesCommandOptions().apply {
      inputFlags.setInputFiles(listOf(fileA, fileB))
      inputFlags.testScript = scriptFile
    }

  // The query cache the driver is given; this test owns it (the driver does not), so it is closed in
  // teardown -- before globalContext, whose stream pool asserts every rented stream was returned.
  private val queryCacheManager =
    QueryCacheManager.create(cmd.profilingFlags, cmd.cacheControlFlags, globalContext)

  // The executor is now shared and owned by the caller (AbstractMain in production); this test owns
  // the one(s) it builds and closes them in teardown.
  private val executorsToClose = mutableListOf<TestScriptExecutorService>()

  private fun newSharedExecutor(
    originalReductionInputs: DefaultLanguageOriginalReductionInputs,
    rootName: String,
  ): TestScriptExecutorService =
    TestScriptExecutorService(
      reductionFolderManager =
        ReductionFolderManager(
          originalReductionInputs,
          Files.createDirectory(workDir.resolve(rootName)),
        ),
      specifiedNumOfThreads = 1,
      scriptExecutionTimeoutInSeconds =
        cmd.reductionControlFlags.testScriptExecutionTimeoutInSeconds,
      globalExecutionCache = globalContext.globalExecutionCache,
    ).also { executorsToClose.add(it) }

  @After
  fun teardown() {
    executorsToClose.forEach { it.close() }
    queryCacheManager.close()
    workDir.toFile().deleteRecursively()
    listenerManager.close()
    globalContext.close()
  }

  @Test
  fun reduceReducesEveryFileOfTheSweep() {
    val inputs =
      DefaultLanguageOriginalReductionInputs.create(
        testScriptPath = cmd.inputFlags.getTestScript(),
        sourceFilePaths = cmd.inputFlags.computeInputFiles(),
        dependencyFiles = ImmutableList.of(),
      ) {
        facadeFactory.computeLanguageKindOrThrow(it)
      }
    val resultFolder =
      AbstractReductionIOManager.createPopulatedResultFolder(
        inputs,
        cmd.cacheControlFlags.defaultShaAlgorithm,
        outputDir,
      )
    val driver =
      PerFileReductionDriver(
        ReductionDriverParams(
          globalContext = globalContext,
          cmd = cmd,
          workingDirectory = workDir,
          resultFolder = resultFolder,
          originalReductionInputs = inputs,
          parserFacadeCandidatesFor = { facadeFactory.getParserFacadeListForOrNull(it)!! },
          codeFormatFor = { it.defaultCodeFormatControl },
          listenerManager = listenerManager,
          shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
          languageProfile = LanguageProfile.DEFAULT,
          reducerFactory = ReducerFactory.DEFAULT,
          queryCache = queryCacheManager.cache,
          reductionStartEvent =
            ReductionStartEvent(
              currentTimeMillis = System.currentTimeMillis(),
              perFileSizeMetrics =
                PerFileSizeMetrics(
                  inputs,
                  inputs.mutableFiles.transformToImmutableList { ProgramSize.ZERO },
                ),
              commandLineOptions = "",
            ),
          executorService = newSharedExecutor(inputs, "exec_root"),
        ),
      )

    // The eagerly-built first-file driver's input representation can compute the initial sizes
    // of the whole set: a.c has 6 canonical tokens and b.c has 9.
    val initialMetrics =
      driver
        .createReductionDriverFor(inputs.mutableFiles[0] as SourceFile)
        .inputRepresentation
        .computePerFileSizeMetrics()
    assertThat(
      intArrayOf(
        initialMetrics.sizeAt(0).canonicalTokenCount,
        initialMetrics.sizeAt(1).canonicalTokenCount,
      ),
    ).isEqualTo(intArrayOf(6, 9))

    driver.reduce()

    val sourceA = inputs.mutableFiles[0]
    val sourceB = inputs.mutableFiles[1]
    val parserFacade =
      facadeFactory
        .getParserFacadeListForOrNull(inputs.initiallyDeterminedMainDataKind)!!
        .defaultParserFacade
        .create()
    val sizeA = parserFacade.computeProgramSizeOf(resultFolder.computeAbsPathForOrigFile(sourceA))
    val sizeB = parserFacade.computeProgramSizeOf(resultFolder.computeAbsPathForOrigFile(sourceB))
    // The oracle keeps "aaa" in a.c and "ccc" in b.c, so neither file can become empty, and both
    // must shrink from their originals (6 and 9 canonical tokens).
    assertThat(sizeA.canonicalTokenCount).isIn(1..5)
    assertThat(sizeB.canonicalTokenCount).isIn(1..8)
  }

  @Test
  fun reducesAMixedLanguageSetWithEachFileOnItsOwnFacade() {
    val mixedDir = workDir.resolve("mixed_input").apply { FileSystemUtil.ensureDirExists(this) }
    val cFile =
      mixedDir.resolve("prog.c").apply {
        createFile()
        writeText("int keep_c; int drop_c;")
      }
    val yamlFile =
      mixedDir.resolve("data.yaml").apply {
        createFile()
        writeText("keep_yaml: 1\ndrop_yaml: 2\n")
      }
    val script =
      mixedDir.resolve("r.sh").apply {
        createFile()
        FileSystemUtil.setExecutable(this)
        writeText(
          """
          |${Shells.SHEBANG_BASH}
          |grep "keep_c" prog.c && grep "keep_yaml" data.yaml
          |
          """.trimMargin(),
        )
      }
    val mixedCmd =
      PersesCommandOptions().apply {
        inputFlags.setInputFiles(listOf(cFile, yamlFile))
        inputFlags.testScript = script
      }
    val inputs =
      DefaultLanguageOriginalReductionInputs.create(
        testScriptPath = mixedCmd.inputFlags.getTestScript(),
        sourceFilePaths = mixedCmd.inputFlags.computeInputFiles(),
        dependencyFiles = ImmutableList.of(),
      ) {
        facadeFactory.computeLanguageKindOrThrow(it)
      }
    val resultFolder =
      AbstractReductionIOManager.createPopulatedResultFolder(
        inputs,
        mixedCmd.cacheControlFlags.defaultShaAlgorithm,
        outputDir,
      )
    val driver =
      PerFileReductionDriver(
        ReductionDriverParams(
          globalContext = globalContext,
          cmd = mixedCmd,
          workingDirectory = mixedDir,
          resultFolder = resultFolder,
          originalReductionInputs = inputs,
          parserFacadeCandidatesFor = { facadeFactory.getParserFacadeListForOrNull(it)!! },
          codeFormatFor = { it.defaultCodeFormatControl },
          listenerManager = listenerManager,
          shaAlgorithm = mixedCmd.cacheControlFlags.defaultShaAlgorithm,
          languageProfile = LanguageProfile.DEFAULT,
          reducerFactory = ReducerFactory.DEFAULT,
          queryCache = queryCacheManager.cache,
          reductionStartEvent =
            ReductionStartEvent(
              currentTimeMillis = System.currentTimeMillis(),
              perFileSizeMetrics =
                PerFileSizeMetrics(
                  inputs,
                  inputs.mutableFiles.transformToImmutableList { ProgramSize.ZERO },
                ),
              commandLineOptions = "",
            ),
          executorService = newSharedExecutor(inputs, "exec_root"),
        ),
      )

    val cSource =
      inputs.mutableFiles.single { (it as SourceFile).file.fileName.toString() == "prog.c" }
    val yamlSource =
      inputs.mutableFiles.single { (it as SourceFile).file.fileName.toString() == "data.yaml" }
    // The point of the per-file facade: each file is parsed by a facade for its OWN language, and
    // the two are different languages.
    val cFacade = inputs.getCanonicalParserFacade(cSource)
    val yamlFacade = inputs.getCanonicalParserFacade(yamlSource)
    assertThat(cFacade.language).isEqualTo(cSource.dataKind)
    assertThat(yamlFacade.language).isEqualTo(yamlSource.dataKind)
    assertThat(cFacade.language).isNotEqualTo(yamlFacade.language)

    driver.reduce()

    // Both files reduce against the single oracle: the dropped declarations are gone, the kept
    // markers (one per file, one per language) remain.
    val reducedC = resultFolder.computeAbsPathForOrigFile(cSource).toFile().readText()
    val reducedYaml = resultFolder.computeAbsPathForOrigFile(yamlSource).toFile().readText()
    assertThat(reducedC).contains("keep_c")
    assertThat(reducedC).doesNotContain("drop_c")
    assertThat(reducedYaml).contains("keep_yaml")
    assertThat(reducedYaml).doesNotContain("drop_yaml")
  }

  // Lexes cleanly (all valid C tokens) but does not parse as C (the second '='), so a strict parse
  // fails while an error-tolerant one recovers. It is also balanced, so the Dyck rung accepts it.
  private val malformedButLexableC = "int x = = 5 ;"

  @Test
  fun errorTolerantRungKeepsTheRealGrammarWhenEnabled() {
    cmd.experimentFlags.enableErrorTolerantGrammar = true
    val (inputs, driver) = createInputsAndDriver()
    val cFile = inputs.mutableFiles[0] as SourceFile
    val resolution = driver.resolveCurrentFacade(cFile, malformedButLexableC)
    assertThat(resolution.facade::class).isEqualTo(realFacadeClassFor(cFile))
    assertThat(resolution.parseTree!!.hasError).isTrue()
  }

  @Test
  fun withoutTheFlagMalformedInputFallsToATolerantGrammar() {
    cmd.experimentFlags.enableErrorTolerantGrammar = false
    val (inputs, driver) = createInputsAndDriver()
    val cFile = inputs.mutableFiles[0] as SourceFile
    val resolution = driver.resolveCurrentFacade(cFile, malformedButLexableC)
    assertThat(resolution.facade::class).isNotEqualTo(realFacadeClassFor(cFile))
  }

  private fun realFacadeClassFor(file: SourceFile) =
    facadeFactory
      .getParserFacadeListForOrNull(
        file.dataKind,
      )!!
      .sequenceOfCreators()
      .first()
      .create()::class

  private fun createInputsAndDriver():
    Pair<DefaultLanguageOriginalReductionInputs, PerFileReductionDriver> {
    val inputs =
      DefaultLanguageOriginalReductionInputs.create(
        testScriptPath = cmd.inputFlags.getTestScript(),
        sourceFilePaths = cmd.inputFlags.computeInputFiles(),
        dependencyFiles = ImmutableList.of(),
      ) {
        facadeFactory.computeLanguageKindOrThrow(it)
      }
    val resultFolder =
      AbstractReductionIOManager.createPopulatedResultFolder(
        inputs,
        cmd.cacheControlFlags.defaultShaAlgorithm,
        outputDir,
      )
    val driver =
      PerFileReductionDriver(
        ReductionDriverParams(
          globalContext = globalContext,
          cmd = cmd,
          workingDirectory = workDir,
          resultFolder = resultFolder,
          originalReductionInputs = inputs,
          parserFacadeCandidatesFor = { facadeFactory.getParserFacadeListForOrNull(it)!! },
          codeFormatFor = { it.defaultCodeFormatControl },
          listenerManager = listenerManager,
          shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
          languageProfile = LanguageProfile.DEFAULT,
          reducerFactory = ReducerFactory.DEFAULT,
          queryCache = queryCacheManager.cache,
          reductionStartEvent =
            ReductionStartEvent(
              currentTimeMillis = System.currentTimeMillis(),
              perFileSizeMetrics =
                PerFileSizeMetrics(
                  inputs,
                  inputs.mutableFiles.transformToImmutableList { ProgramSize.ZERO },
                ),
              commandLineOptions = "",
            ),
          executorService = newSharedExecutor(inputs, "exec_root"),
        ),
      )
    return inputs to driver
  }
}

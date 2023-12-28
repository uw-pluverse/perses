/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr.reducer.setup

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.AntlrCompiler
import org.perses.antlr.reducer.codegen.GrammarMainStubFactory
import org.perses.antlr.reducer.codegen.ReductionScriptTemplate
import org.perses.program.ScriptFile
import org.perses.util.AutoDeletableFolder
import org.perses.util.AutoIncrementDirectory
import org.perses.util.Util
import org.perses.util.java.JarFile
import org.perses.util.java.JavacWrapper
import org.perses.util.ktInfo
import org.perses.util.shell.Shells
import java.nio.file.Files
import java.nio.file.Path

class Setup(
  parentWorkingDir: Path,
  parserGrammarPath: Path,
  lexerGrammarPath: Path,
  val startRuleName: String,
  val testPrograms: ImmutableList<Path>,
) {

  init {
    logger.ktInfo { "Creating setup for $parserGrammarPath and $lexerGrammarPath" }
  }

  val workingDir = AutoIncrementDirectory
    .computeAndCreate(
      workingDir = parentWorkingDir,
      defaultDirName = DEFAULT_SETUP_DIR_NAME,
    ).also {
      check(Files.isDirectory(it))
      check(Util.isEmptyDirectory(it))
      logger.ktInfo { "The working directory of the setup is $it" }
    }

  val parserFile = copyFiletoDir(parserGrammarPath, workingDir)
  val lexerFile = copyFiletoDir(lexerGrammarPath, workingDir)

  val jarFile = createJarFile(
    workingDir,
    parserFile = parserFile,
    lexerFile = lexerFile,
    startRuleName = startRuleName,
    workingDir.resolve(
      Util.replaceFileExtension(parserFile.fileName.toString(), "jar"),
    ),
  ).also { logger.ktInfo { "Create the JAR file at ${it.path}" } }

  val parseableTestPrograms = testPrograms
    .asSequence()
    .filter {
      jarFile.expensiveTestParsable(it)
    }
    .map { it.toAbsolutePath() }
    .fold(
      ImmutableList.builder<Path>(),
      { builder, element -> builder.add(element) },
    )
    .build()
    .also {
      logger.ktInfo {
        "There are ${it.size} parseable files, vs. original ${testPrograms.size}."
      }
    }

  val testScript = createTestScript(
    jarFile,
    workingDir.resolve("r.sh"),
  ).also {
    logger.ktInfo { "About to test the generated test script ${it.file}" }
    val startTime = System.currentTimeMillis()
    val result = Shells.singleton.run(
      "${it.shebang} ${it.file.fileName}",
      it.parentFile,
      captureOutput = false,
      environment = Shells.CURRENT_ENV,
    )
    val endTime = System.currentTimeMillis()
    logger.ktInfo { "${(endTime - startTime) / 1000} seconds spent by the script." }
    check(result.exitCode.isZero()) { result }
  }

  companion object {

    fun createTestScript(
      jarFile: JarFile,
      outputPath: Path,
    ): ScriptFile {
      return ReductionScriptTemplate(
        jarFileName = jarFile.path.fileName.toString(),
        mainClassFullName = jarFile.mainClassFullName,
        extraClasspath = JavacWrapper.getJarsOnClasspath(),
      ).writeTo(outputPath)
    }

    fun copyFiletoDir(file: Path, destinationDir: Path): Path {
      val result = destinationDir.resolve(file.fileName.toString())
      Files.copy(file, result)
      return result
    }

    fun createJarFile(
      workingDir: Path,
      parserFile: Path,
      lexerFile: Path,
      startRuleName: String,
      jarOutputFile: Path,
    ): JarFile {
      require(!Files.exists(jarOutputFile))

      AutoDeletableFolder(
        AutoIncrementDirectory.computeAndCreate(
          workingDir,
          defaultDirName = "jar_compilation_dir",
        ),
      ).use {
        val generatedJarFile = AntlrCompiler.createFromFiles(
          parserFile,
          lexerFile,
          startRuleName,
          it.file,
          stubFactory = GrammarMainStubFactory(testPrograms = ImmutableList.of()),
          packageName = "org.perses.antlr",
          jarFileCustomizer = {},
        ).run()

        return generatedJarFile.copyTo(jarOutputFile)
      }
    }

    private const val DEFAULT_SETUP_DIR_NAME = "perses_antlr_reducer"

    private val logger = FluentLogger.forEnclosingClass()
  }
}

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
package org.perses.fuzzer

import org.perses.fuzzer.compilers.DefaultCompilationConfigurationFacade
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.fuzzer.config.CmdFlags
import org.perses.fuzzer.config.ProgramUnderTest
import org.perses.fuzzer.config.SeedFolder
import org.perses.fuzzer.config.TestingConfiguration
import org.perses.fuzzer.organizer.OrganizerDriver
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.rust.LanguageRust
import org.perses.util.shell.ShellCommandOnPath
import java.io.File
import java.nio.file.Files.createTempDirectory
import java.util.concurrent.atomic.AtomicInteger
import kotlin.io.path.writeText

class RustTestUtil : AutoCloseable {

  val parserFacadeFactory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
  val mockRustcCommand = ShellCommandOnPath("kitten/test/mock_scripts/mock_rustc.py")

  val workingDir = createTempDirectory(javaClass.simpleName).toFile()
  private val fileCounter = AtomicInteger()

  private val findingFolderFile = File(workingDir, "finding_folder")

  val testingConfiguration = TestingConfiguration(
    language = "RUST",
    seedFolders = listOf(
      SeedFolder(
        path = File(workingDir, "seed_folder").apply {
          check(mkdirs())
          File(this, "seed_1.rs").apply {
            this.toPath().writeText(
              """
              fn main() {
                  println!("Hello World!");
              }
              """.trimIndent(),
            )
          }
        }.absolutePath,
        fileExtentions = listOf(".rs"),
      ),
    ),
    programsUnderTest = listOf(
      ProgramUnderTest(
        command = mockRustcCommand.normalizedCommand,
        flagsToTest = listOf(CmdFlags.EMPTY),
        versionFlags = CmdFlags(listOf("--version", "--verbose")),
        crashDetectorClassName = RustcCrashDetector::class.java.canonicalName,
      ),
    ),
  )

  val facade = DefaultCompilationConfigurationFacade(
    languageKind = parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(
      testingConfiguration.language,
    )!!,
    programUnderTest = testingConfiguration.programsUnderTest[0],
  )
  val action = facade.compilationActions[0]
  val mockRustcAction = facade.compilationActions[0]

  val fuzzerDriver = FuzzerDriver(
    CommandOptions().also {
      it.generalFlags.setFindingFolder(findingFolderFile.absoluteFile)
      it.compilerFlags.testingConfiguration = testingConfiguration
    },
    AdditionalFuzzerControl(1),
  )

  private val processingFolderFile = File(workingDir, "processing_folder")
  private val reportedFolderFile = File(workingDir, "reported_folder")
  private val duplicateBugFolderFile = File(workingDir, "duplicate_folder")
  val organizer = OrganizerDriver(
    org.perses.fuzzer.organizer.CommandOptions().apply {
      findingFolder = findingFolderFile
      processingFolder = processingFolderFile
      reportedFolder = reportedFolderFile
      duplicateBugFolder = duplicateBugFolderFile
      setLang("RUST")
    },
  )

  fun testWithProgram(sourceFileName: String, sourceCode: String) {
    val mutantFile = File(workingDir, sourceFileName).apply { writeText(sourceCode) }
    val seedFile = createTempFile().apply { writeText(sourceCode) }
    val seedProgram = FuzzerDriverTest.getTokenizedProgram(seedFile, LanguageRust)
    fuzzerDriver.testActionOnMutant(
      mockRustcAction,
      mutantFile,
      seedFile,
      seedProgram,
      fuzzerDriver.facades.first().crashDetector,
    )
  }

  fun populateFindingFolder(numOfDuplicatesPerCrashSignature: Int) {
    for (i in 0..numOfDuplicatesPerCrashSignature) {
      testWithProgram("m1.rs", PROGRAM_CRASH_1)
      testWithProgram("m2.rs", PROGRAM_CRASH_2)
      testWithProgram("m3.rs", PROGRAM_VALID)
    }
  }

  fun populateProcessingFolder(numOfDuplicatesPerCrashSignature: Int) {
    populateFindingFolder(numOfDuplicatesPerCrashSignature)
  }

  fun getFindingFolder() = fuzzerDriver.findingFolder

  fun getProcessingFolder() = organizer.processingFolder

  fun getReportedFolder() = organizer.reportedBugFolder

  fun getDuplicateFolder() = organizer.duplicateBugFolder

  private fun createTempFile() = File(
    workingDir,
    fileCounter.getAndIncrement().toString() + ".rs",
  )

  override fun close() {
    fuzzerDriver.close()
    workingDir.deleteRecursively()
  }

  companion object {
    val PROGRAM_CRASH_1 =
      """
      |fn main() {
      |    println!("trigger crash 1");
      |}
      """.trimMargin()

    val PROGRAM_CRASH_2 =
      """
      |fn main() {
      |    println!("trigger crash 2");
      |}
      """.trimMargin()

    val PROGRAM_VALID =
      """
      |fn main() { }
      """.trimMargin()

    fun markCrashAsReported(
      crash: CrashInstanceFolder,
      bugReportUrl: String,
      bugReportId: Int,
      bugResolution: CrashInstanceFolder.BugResolution,
    ) {
      val info = crash.info()
      val newInfo = CrashInstanceFolder.Info(
        seedFileName = info.seedFileName,
        mutantFileName = info.mutantFileName,
        language = info.language,
        stdoutFileName = info.stdoutFileName,
        stderrFileName = info.stderrFileName,
        reproduceScriptFileName = info.reproduceScriptFileName,
        crashSignatureFileName = info.crashSignatureFileName,
        deltaFolderName = info.deltaFolderName,
        bugReportUrl = bugReportUrl,
        bugId = bugReportId.toString(),
        bugResolution = bugResolution,
        crashDetectorClassName = info.crashDetectorClassName,
      )
      newInfo.save(File(crash.folder, CrashInstanceFolder.FILE_NAME_BUG_DESCRIPTOR))
    }
  }
}

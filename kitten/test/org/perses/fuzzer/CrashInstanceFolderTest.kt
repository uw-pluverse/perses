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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.ICompilerCrashDetector
import org.perses.fuzzer.compilers.c.GccCrashDetector
import org.perses.grammar.c.LanguageC
import org.perses.util.shell.Shells
import java.io.File

@RunWith(JUnit4::class)
class CrashInstanceFolderTest {

  private val workingDirectory = java.nio.file.Files
    .createTempDirectory(javaClass.simpleName).toFile()

  private val crashDetector = GccCrashDetector()

  @After
  fun teardown() {
    workingDirectory.deleteRecursively()
  }

  @Test
  fun testCreateCrashInstanceFolder() {
    val findingFolder = FindingFolder(File(workingDirectory, "findings").apply { mkdir() })
    assertThat(findingFolder.getChildren()).isEmpty()

    val seedFile = File(workingDirectory, "seed.c").apply {
      writeText("int a; // seed")
    }

    val seedProgram = FuzzerDriverTest.getTokenizedProgram(seedFile, LanguageC)
    val mutantFile = File(workingDirectory, "mutant.c").apply {
      writeText("int a; // mutant")
    }
    val action = FakeCompilationAction
    val actionResult = action.compile(mutantFile)
    val crashSignature = ICompilerCrashDetector.AbstractResult.CrashResult.create(
      crashDetector.javaClass,
      actionResult.cmdOutput.exitCode.intValue,
      listOf("internal compiler error", "this is a bug"),
    )

    val bugFolder = CrashInstanceFolder.create(
      findingFolder,
      seedProgram,
      mutantFile,
      actionResult,
      action,
      crashSignature,
    ).folder

    assertThat(findingFolder.getChildren()).hasSize(1)
    assertThat(findingFolder.getChildren()[0].name).isEqualTo(bugFolder.name)
    assertThat(bugFolder.list().toList()).containsExactly(
      "delta",
      "stdout.txt",
      "stderr.txt",
      "mutant.c",
      "bug_descriptor.properties",
      "reproduce.sh",
      "seed.c",
      "crash_signature.txt",
      ".bug_folder_creation_is_done.txt",
    )

    assertThat(File(bugFolder, "stdout.txt").readText().trim())
      .isEqualTo("stdout")
    assertThat(File(bugFolder, "stderr.txt").readText().trim())
      .contains("internal compiler error\nthis is a bug")
    assertThat(File(bugFolder, "seed.c").readText().trim())
      .isEqualTo("int a;")
    assertThat(File(bugFolder, "mutant.c").readText().trim())
      .isEqualTo("int a; // mutant")

    val restoredInfo = CrashInstanceFolder(bugFolder)
    restoredInfo.info().let {
      assertThat(it.bugReportUrl).isEmpty()
      assertThat(it.crashSignatureFileName).isEqualTo("crash_signature.txt")
      assertThat(it.deltaFolderName).isEqualTo("delta")
      assertThat(it.mutantFileName).isEqualTo("mutant.c")
      assertThat(it.seedFileName).isEqualTo("seed.c")
      assertThat(it.stderrFileName).isEqualTo("stderr.txt")
      assertThat(it.stdoutFileName).isEqualTo("stdout.txt")
    }

    File(bugFolder, "delta").let {
      assertThat(it.isDirectory).isTrue()
      assertThat(it.list().size).isAtLeast(3)
      assertThat(File(it, "info.properties").exists()).isTrue()
      assertThat(File(it, "r.sh").canExecute()).isTrue()
      assertThat(File(it, "mutant.c").isFile).isTrue()

      val cmdOutput = Shells.singleton.run(
        "./r.sh",
        it.toPath(),
        captureOutput = false,
        environment = Shells.CURRENT_ENV,
      )
      assertThat(cmdOutput.exitCode.intValue).isEqualTo(0)
    }

    File(bugFolder, "crash_signature.txt").readText().trim().let {
      assertThat(it).contains("internal compiler error")
    }

    // TODO: need to add a test for this.
//    assertThat(restoredInfo.isReproducible()).isEqualTo(
//      CrashInstanceFolder.ReproductionResult.REPRODUCIBLE)
  }

  @Test
  fun testBugInfoWithEmptyBugResolution() {
    val info = CrashInstanceFolder.Info(
      seedFileName = "seed.rs",
      mutantFileName = "mutant.rs",
      language = "rust",
      stdoutFileName = "stdout.txt",
      stderrFileName = "stderr.txt",
      reproduceScriptFileName = "reproduce.sh",
      crashSignatureFileName = "crash_signature.sh",
      deltaFolderName = "delta",
      bugReportUrl = "",
      bugId = "",
      bugResolution = CrashInstanceFolder.BugResolution.NEW,
      crashDetectorClassName = crashDetector.javaClass.canonicalName,
    )
    val file = File(workingDirectory, "temp.properties")
    info.save(file)
    val lines = file
      .readLines()
      .filter {
        !(
          it.startsWith(CrashInstanceFolder.Info.KEY_BUG_ID) ||
            it.startsWith(CrashInstanceFolder.Info.KEY_BUG_REPORT_URL) ||
            it.startsWith(CrashInstanceFolder.Info.KEY_BUG_RESOLUTION)
          )
      }
    val fileWithoutBugInfo = File(workingDirectory, "info_without_bug_info.properties")
    fileWithoutBugInfo.writeText(lines.joinToString("\n"))
    val infoFromFile = CrashInstanceFolder.Info.readFrom(fileWithoutBugInfo)
    assertThat(infoFromFile.bugId).isEmpty()
    assertThat(infoFromFile.bugReportUrl).isEmpty()
    assertThat(infoFromFile.bugResolution).isEqualTo(CrashInstanceFolder.BugResolution.NEW)
    assertThat(info).isEqualTo(infoFromFile)
  }
}

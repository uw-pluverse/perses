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
package org.perses.fuzzer.reduction

import org.perses.util.shell.Shells
import java.io.File
import java.util.Properties

class DeltaFolder(
  val folder: File,
) {

  fun info() = DeltaFolderInfo.readFrom(File(folder, INFO_FILE_NAME))

  val scriptFile = File(folder, info().scriptFileName)

  val programFile = File(folder, info().programFileName)

  val reducedFile = File(folder, info().reducedFileName)

  val buggyCompilerVersionFile = File(folder, info().buggyCompilerVersionFileName)

  init {
    check(scriptFile.exists())
    check(programFile.exists())
    check(buggyCompilerVersionFile.exists())
  }

  fun reduce() {
    if (reducedFile.exists()) {
      return
    }
    val tempResultFile = File(folder, ".temp_result_${info().reducedFileName}")
    org.perses.Main.main(
      arrayOf(
        "--test-script",
        scriptFile.toString(),
        "--input-file",
        programFile.toString(),
        "--output-file",
        tempResultFile.toString(),
        "--call-formatter",
        "true",
      ),
    )
    check(tempResultFile.renameTo(reducedFile)) {
      "cannot rename $tempResultFile to $reducedFile"
    }
  }

  companion object {
    val INFO_FILE_NAME = "info.properties"
  }

  data class DeltaFolderInfo(
    val scriptFileName: String,
    val programFileName: String,
    val reducedFileName: String,
    val buggyCompilerVersionFileName: String,
  ) {

    fun saveTo(file: File) = file.bufferedWriter().use {
      Properties().apply {
        put(KEY_SCRIPT_FILE, scriptFileName)
        put(KEY_SOURCE_FILE, programFileName)
        put(KEY_REDUCED_FILE, reducedFileName)
        put(KEY_VERSION_FILE, buggyCompilerVersionFileName)
      }.store(it, null)
    }

    companion object {

      fun readFrom(file: File): DeltaFolderInfo {
        val properties = Properties().apply {
          file.bufferedReader().use {
            load(it)
          }
        }
        return DeltaFolderInfo(
          scriptFileName = properties.getProperty(KEY_SCRIPT_FILE)!!,
          programFileName = properties.getProperty(KEY_SOURCE_FILE)!!,
          reducedFileName = properties.getProperty(KEY_REDUCED_FILE)!!,
          buggyCompilerVersionFileName = properties.getProperty(KEY_VERSION_FILE)!!,
        )
      }

      // DO NOT CHANGE THE KEY NAMES. Our benchmark follows this naming convention.
      private val KEY_SCRIPT_FILE = "script_file"
      private val KEY_SOURCE_FILE = "source_file"
      private val KEY_REDUCED_FILE = "reduced_file"
      private val KEY_VERSION_FILE = "buggy_compiler_version_file"
    }
  }

  class Builder(
    val folder: File,
    val scriptName: String,
    val programName: String,
    val reducedProgramName: String,
    val buggyCompilerVersionFileName: String,
  ) {

    val reductionScript = File(folder, scriptName)
    val programFile = File(folder, programName)
    val buggyCompilerVersionFile = File(folder, buggyCompilerVersionFileName)

    init {
      if (!folder.exists()) {
        check(folder.mkdirs())
      }
      check(folder.exists())

      check(!reductionScript.exists())
      check(!programFile.exists())
      check(!buggyCompilerVersionFile.exists())

      check(
        setOf(
          scriptName,
          programName,
          reducedProgramName,
          buggyCompilerVersionFileName,
        ).size == 4,
      )
    }

    fun populateReductionScript(reductionScriptGenerator: ReductionScriptGenerator): Builder {
      check(!reductionScript.exists())
      reductionScript.writeText(reductionScriptGenerator.generate())
      check(reductionScript.setExecutable(true))
      check(reductionScript.exists())
      return this
    }

    fun populateProgramFile(sourceProgram: String): Builder {
      check(!programFile.exists())
      programFile.writeText(sourceProgram)
      check(programFile.exists())
      return this
    }

    fun populateBuggyCompilerVersionFile(version: String): Builder {
      check(!buggyCompilerVersionFile.exists())
      buggyCompilerVersionFile.writeText(version)
      check(buggyCompilerVersionFile.exists())
      return this
    }

    fun build(): DeltaFolder {
      check(reductionScript.exists())
      check(programFile.exists())

      Shells.singleton.run(
        "./$scriptName",
        folder.toPath(),
        captureOutput = true,
        environment = Shells.CURRENT_ENV,
      ).let {
        check(it.exitCode.isZero()) { it }
      }

      val info = DeltaFolderInfo(
        scriptName,
        programName,
        reducedProgramName,
        buggyCompilerVersionFileName,
      )
      val infoFile = File(folder, INFO_FILE_NAME)
      check(!infoFile.exists())
      info.saveTo(infoFile)
      // Intentionally parse the DeltaFolder again to validate correctness.
      return DeltaFolder(folder)
    }
  }
}

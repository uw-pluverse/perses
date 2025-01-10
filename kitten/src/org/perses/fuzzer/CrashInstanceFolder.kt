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

import com.google.common.flogger.FluentLogger
import com.google.common.io.Files
import com.google.common.io.MoreFiles
import org.perses.fuzzer.compilers.ActionResult
import org.perses.fuzzer.compilers.ICompilationAction
import org.perses.fuzzer.compilers.ICompilerCrashDetector
import org.perses.fuzzer.compilers.ICompilerCrashDetector.AbstractResult
import org.perses.fuzzer.compilers.ICompilerCrashDetector.CrashSignature
import org.perses.fuzzer.reduction.DeltaFolder
import org.perses.fuzzer.reduction.ReductionScriptGenerator
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.util.TimeUtil
import org.perses.util.ktAt
import org.perses.util.ktInfo
import org.perses.util.shell.Shells
import java.io.File
import java.util.Properties
import java.util.logging.Level

class CrashInstanceFolder(val folder: File) {

  private val bugDescriptorFile = File(folder, FILE_NAME_BUG_DESCRIPTOR)

  init {
    check(folder.exists())
    check(isCrashInstanceFolder(folder)) {
      "The bug folder is not completed yet. $folder"
    }
    check(bugDescriptorFile.isFile) { bugDescriptorFile }
    info() // Validate the bugDescriptorFile.
  }

  fun info() = Info.readFrom(bugDescriptorFile)

  fun reduce() = getDeltaFolder().reduce()

  fun createCrashDetector(): ICompilerCrashDetector {
    return Class.forName(info().crashDetectorClassName)
      .getDeclaredConstructor().newInstance() as ICompilerCrashDetector
  }

  private fun getDeltaFolder() = DeltaFolder(File(folder, info().deltaFolderName))

  fun delete() = folder.deleteRecursively()

  fun isDeleted() = folder.isDirectory

  fun isReported() = info().bugId.isNotBlank()

  fun getReportedBugId() = Integer.parseInt(info().bugId.trim())

  fun getMutantFile() = File(folder, info().mutantFileName)

  fun isReproducible(): ReproductionResult {
    val reproduceScript = getReproductionScriptFile()
    val cmdOutput = Shells.singleton.run(
      "./${reproduceScript.name}",
      workingDirectory = folder.toPath(),
      captureOutput = true,
      environment = Shells.CURRENT_ENV,
    )
    val detectResult = createCrashDetector().detectCrash(cmdOutput)
    if (!detectResult.isCrashDetected()) {
      return ReproductionResult.NO_CRASH
    }
    if (!detectResult.asCrash().signature.equals(readCrashSignature())) {
      return ReproductionResult.CRASH_WITH_DIFFERENT_SIGNATURE
    }
    return ReproductionResult.REPRODUCIBLE
  }

  private fun getReproductionScriptFile() = File(folder, info().reproduceScriptFileName)

  private fun getReproductionCommand(): String {
    val lines = getReproductionScriptFile().readLines()
      .asSequence()
      .map { it.trim() }
      .filter { it.isNotBlank() }
      .toList()
    check(lines.size == 2)
    check(lines.first().startsWith("#"))
    return lines[1]
  }

  fun move(destination: File) {
    java.nio.file.Files.move(folder.toPath(), destination.toPath())
  }

  enum class ReproductionResult {
    REPRODUCIBLE,
    CRASH_WITH_DIFFERENT_SIGNATURE,
    NO_CRASH,
  }

  @Throws(NotCrashAnyMoreException::class)
  fun updateCrashSignatureAndReductionScript(
    crashDetector: ICompilerCrashDetector,
    updateReductionScript: Boolean = false,
  ) {
    val result = crashDetector.detectCrash(readStderr())
    if (!result.isCrashDetected()) {
      throw NotCrashAnyMoreException()
    }
    val timeComponent = TimeUtil.formatDateForFileName(System.currentTimeMillis())
    val backupFileName = "backup_" + timeComponent + "_" + info().crashSignatureFileName
    check(getCrashSignatureFile().renameTo(File(folder, backupFileName))) {
      "fail to rename ${getCrashSignatureFile()} to $backupFileName"
    }
    result.asCrash().signature.writeTo(getCrashSignatureFile())

    if (!updateReductionScript) {
      return
    }
    val deltaFolder = getDeltaFolder()
    val reductionScriptBackupFile = File(
      deltaFolder.folder,
      "backup_" + timeComponent + "_" + deltaFolder.info().scriptFileName,
    )
    Files.copy(deltaFolder.scriptFile, reductionScriptBackupFile)
    val reductionScriptGenerator = ReductionScriptGenerator(
      getReproductionCommand(),
      result.asCrash(),
    )
    deltaFolder.scriptFile.writeText(
      reductionScriptGenerator.generate(),
    )
  }

  fun readCrashSignature() = CrashSignature.readFrom(getCrashSignatureFile())

  private fun getCrashSignatureFile() = File(folder, info().crashSignatureFileName)

  fun readStderr() = File(folder, info().stderrFileName).readText()

  enum class BugResolution {
    FIXED,
    NEW,
    ;

    companion object {

      fun parse(string: String) = when (val normalized = string.trim().lowercase()) {
        "fixed" -> FIXED
        "", "new" -> NEW
        else -> throw RuntimeException("Unhandled value: $normalized")
      }
    }
  }

  data class Info(
    val seedFileName: String,
    val mutantFileName: String,
    val language: String,
    val stdoutFileName: String,
    val stderrFileName: String,
    val reproduceScriptFileName: String,
    val crashSignatureFileName: String,
    val deltaFolderName: String,
    val bugReportUrl: String,
    val bugId: String,
    val bugResolution: BugResolution,
    val crashDetectorClassName: String,
  ) {

    fun save(file: File) {
      val p = Properties().apply {
        setProperty(KEY_SEED, seedFileName)
        setProperty(KEY_MUTANT, mutantFileName)
        setProperty(KEY_STDOUT, stdoutFileName)
        setProperty(KEY_STDERR, stderrFileName)
        setProperty(KEY_LANGUAGE, language)
        setProperty(KEY_REPRODUCE_SCRIPT, reproduceScriptFileName)
        setProperty(KEY_CRASH_SIGNATURES, crashSignatureFileName)
        setProperty(KEY_DELTA_FOLDER, deltaFolderName)
        setProperty(KEY_BUG_REPORT_URL, bugReportUrl)
        setProperty(KEY_BUG_ID, bugId)
        setProperty(KEY_BUG_RESOLUTION, bugResolution.toString())
        setProperty(KEY_CRASH_DETECTOR_CLASS_NAME, crashDetectorClassName)
      }
      file.bufferedWriter().use {
        p.store(
          it,
          null, // comments
        )
      }
    }

    companion object {
      const val KEY_SEED = "seed_file"
      const val KEY_MUTANT = "mutant_file"
      const val KEY_STDOUT = "stdout_file"
      const val KEY_LANGUAGE = "language"
      const val KEY_STDERR = "stderr_file"
      const val KEY_REPRODUCE_SCRIPT = "reproduce_script"
      const val KEY_CRASH_SIGNATURES = "crash_signature_file"
      const val KEY_DELTA_FOLDER = "delta_folder"
      const val KEY_BUG_REPORT_URL = "bug_report_url"
      const val KEY_BUG_ID = "bug_id"
      const val KEY_BUG_RESOLUTION = "bug_resolution"
      const val KEY_CRASH_DETECTOR_CLASS_NAME = "crash_detector_class"

      fun readFrom(file: File): Info {
        val p = Properties().apply {
          file.bufferedReader().use { load(it) }
        }
        if (p.getProperty(KEY_CRASH_DETECTOR_CLASS_NAME) == null) {
          logger.ktInfo { "The folder $file does not have all fields" }
        }
        return Info(
          seedFileName = p.getProperty(KEY_SEED)!!,
          mutantFileName = p.getProperty(KEY_MUTANT)!!,
          stdoutFileName = p.getProperty(KEY_STDOUT)!!,
          stderrFileName = p.getProperty(KEY_STDERR)!!,
          language = p.getProperty(KEY_LANGUAGE, "")!!, // TODO: remove rust.
          reproduceScriptFileName = p.getProperty(KEY_REPRODUCE_SCRIPT, "")!!,
          crashSignatureFileName = p.getProperty(KEY_CRASH_SIGNATURES)!!,
          deltaFolderName = p.getProperty(KEY_DELTA_FOLDER)!!,
          bugReportUrl = p.getProperty(KEY_BUG_REPORT_URL, "")!!,
          bugId = p.getProperty(KEY_BUG_ID, "")!!,
          bugResolution = BugResolution.parse(p.getProperty(KEY_BUG_RESOLUTION, "")),
          crashDetectorClassName = p.getProperty(KEY_CRASH_DETECTOR_CLASS_NAME)!!,
        )
      }
    }
  }

  companion object {
    val FILE_NAME_FOLDER_CREATION_COMPLETED = ".bug_folder_creation_is_done.txt"
    val FILE_NAME_BUG_DESCRIPTOR = "bug_descriptor.properties"
    val FILE_NAME_STDOUT = "stdout.txt"
    val FILE_NAME_STDERR = "stderr.txt"
    val FILE_NAME_REPRODUCE_SCRIPT = "reproduce.sh"
    val FILE_NAME_CRASH_SIGNATURE = "crash_signature.txt"
    val FOLDER_NAME_DELTA = "delta"

    fun isCrashInstanceFolder(folder: File) =
      File(folder, FILE_NAME_FOLDER_CREATION_COMPLETED).isFile

    fun create(
      findingFolder: FindingFolder,
      seedProgram: TokenizedProgram,
      mutantFile: File,
      result: ActionResult,
      action: ICompilationAction,
      crashDetectorResult: AbstractResult.CrashResult,
    ): CrashInstanceFolder {
      logger.ktAt(Level.FINE) { "Saving mutant to $mutantFile" }
      val bugFolder = findingFolder.createBugFolder("crash_")
      var fileExtension = MoreFiles.getFileExtension(mutantFile.toPath())
      if (!fileExtension.isEmpty()) {
        fileExtension = ".$fileExtension"
      }

      val seedFileName = "seed$fileExtension"
      Files.copy(mutantFile, File(bugFolder, mutantFile.name))

      try {
        val printer = PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT)
        printer.print(seedProgram).writeTo(File(bugFolder, seedFileName).toPath())
      } catch (e: IllegalStateException) {
        // Generator cannot generate correct line number,
        // so some program cannot be printed in original format
        val printer = PrinterRegistry.getPrinter(EnumFormatControl.SINGLE_TOKEN_PER_LINE)
        printer.print(seedProgram).writeTo(File(bugFolder, seedFileName).toPath())
      }

      File(bugFolder, FILE_NAME_REPRODUCE_SCRIPT).apply {
        writeText(
          """#!/usr/bin/env bash
          |${result.cmd}
          """.trimMargin(),
        )
        check(setExecutable(true))
      }

      val bugInfo = Info(
        seedFileName = seedFileName,
        mutantFileName = mutantFile.name,
        stdoutFileName = FILE_NAME_STDOUT,
        stderrFileName = FILE_NAME_STDERR,
        language = action.getLanguage().name,
        reproduceScriptFileName = FILE_NAME_REPRODUCE_SCRIPT,
        crashSignatureFileName = FILE_NAME_CRASH_SIGNATURE,
        deltaFolderName = FOLDER_NAME_DELTA,
        bugReportUrl = "",
        bugId = "",
        bugResolution = BugResolution.NEW,
        crashDetectorClassName = crashDetectorResult.crashDetectorClass.canonicalName,
      )
      bugInfo.save(File(bugFolder, FILE_NAME_BUG_DESCRIPTOR))

      crashDetectorResult.signature.writeTo(File(bugFolder, FILE_NAME_CRASH_SIGNATURE))

      try {
        DeltaFolder.Builder(
          File(bugFolder, FOLDER_NAME_DELTA),
          scriptName = "r.sh",
          programName = mutantFile.name,
          reducedProgramName = "reduced_${mutantFile.name}",
          buggyCompilerVersionFileName = "compiler_version.txt",
        ).populateReductionScript(
          ReductionScriptGenerator(cmd = result.cmd, crashSignature = crashDetectorResult),
        ).populateProgramFile(mutantFile.readText())
          .populateBuggyCompilerVersionFile(action.getVersion())
          .build()
      } catch (e: Throwable) {
        // Tolerate exceptions so that the crash can be saved successfully.
        e.printStackTrace()
        logger.atSevere().log("Exception occurred in creating a crash instance folder: $bugFolder")
      }

      result.cmdOutput.stdout.writeToFile(File(bugFolder, FILE_NAME_STDOUT).toPath())
      result.cmdOutput.stderr.writeToFile(File(bugFolder, FILE_NAME_STDERR).toPath())
      logger.ktAt(Level.FINE) { "Saved a bug-triggering input to $bugFolder" }
      File(bugFolder, FILE_NAME_FOLDER_CREATION_COMPLETED).apply {
        check(createNewFile())
      }
      return CrashInstanceFolder(bugFolder)
    }

    private val logger = FluentLogger.forEnclosingClass()
  }

  class NotCrashAnyMoreException : Exception("Not a crash any more.")
}

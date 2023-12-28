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
package org.perses.reduction.io

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.Joiner
import com.google.common.base.Strings
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.program.AbstractDataKind
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.util.AutoIncrementDirectory
import org.perses.util.GlobalSequenceGenerator
import org.perses.util.TimeUtil
import org.perses.util.Util
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption
import java.time.LocalDateTime
import java.util.concurrent.atomic.AtomicInteger
import kotlin.io.path.listDirectoryEntries
import kotlin.io.path.name

abstract class AbstractReductionIOManager<
  P,
  K : AbstractDataKind,
  Self : AbstractReductionIOManager<P, K, Self>,
  >(
  private val workingFolder: Path,
  val reductionInputs: AbstractReductionInputs<K, *>,
  val outputManagerFactory: AbstractOutputManagerFactory<P>,
  outputDirectory: Path?,
) {

  val tempRootFolder: Path = workingFolder.resolve(
    getTempRootFolderName(
      reductionInputs.relativePathSequence().asIterable(),
      reductionInputs.testScript.file.fileName.toString(),
      LocalDateTime.now(),
    ),
  )

  abstract fun getConcreteReductionInputs(): AbstractReductionInputs<*, *>

  val resultFolder = if (outputDirectory == null) {
    val dir = AutoIncrementDirectory(DEFAULT_PERSES_BEST_DIR_NAME)
      .computeAndCreate(workingFolder)
    ReductionFolder(reductionInputs, dir)
  } else {
    if (!Files.exists(outputDirectory)) {
      Files.createDirectories(outputDirectory)
    }
    check(Files.isDirectory(outputDirectory)) {
      "$outputDirectory is not a directory."
    }
    ReductionFolder(reductionInputs, outputDirectory)
  }

  fun updateBestResult(program: P) {
    /*
     * We try to make the writing-best-resut operation atomic.
     *
     * https://github.com/uw-pluverse/perses/issues/9
     *
     * https://github.com/chengniansun/perses-private/issues/508
     */
    val tempDirectory = createCurrentBestResultFolder()
    createOutputManager(program).write(tempDirectory)
    Util.copyDirectory(
      tempDirectory.folder,
      resultFolder.folder,
      StandardCopyOption.REPLACE_EXISTING,
    )
    tempDirectory.deleteThisDirectoryRecursively()
  }

  private var snapshotCounter = 0
  internal fun createCurrentBestResultFolder(): ReductionFolder {
    // create the result folder besides the resultFolder
    val timestamp = TimeUtil.formatDateForFileName(System.currentTimeMillis())
    val path = resultFolder.folder.parent.resolve(
      resultFolder.folder.name + "_best_result_snapshot_${++snapshotCounter}_at_" + timestamp,
    )
    check(!Files.exists(path))
    Files.createDirectories(path)
    check(Files.isDirectory(path)) { path }
    return ReductionFolder(reductionInputs, path)
  }

  fun createTempResultFolder(): ReductionFolder {
    return lazilyInitializedReductionFolderManager.createNextFolder(
      prefix = "temp_",
      postfix = System.currentTimeMillis().toString(),
    )
  }

  fun createOutputManager(program: P): AbstractOutputManager {
    return outputManagerFactory.createManagerFor(program)
  }

  fun getScriptFileBaseNameIn(folder: ReductionFolder): String {
    val scriptBaseName = reductionInputs.testScript.baseName
    check(folder.checkFileExistence(scriptBaseName))
    return scriptBaseName
  }

  fun getSingleSourceFileBaseName(folder: ReductionFolder): String {
    val baseName = reductionInputs.relativePathSequence().single().toString()
    check(folder.checkFileExistence(baseName))
    return baseName
  }

  fun getAllSourceFileBaseNamesIn(folder: ReductionFolder): ImmutableList<String> {
    val baseNameList = reductionInputs.relativePathSequence().map {
      val baseName = it.toString()
      check(folder.checkFileExistence(baseName))
      baseName
    }.toImmutableList()
    return baseNameList
  }

  fun getMainSourceFileBaseName(): String {
    check(reductionInputs is AbstractSingleFileReductionInputs<*, *, *>) {
      "We currently only support AbstractSingleFileReductionInputs."
    }
    return reductionInputs.mainFile.baseName
  }

  inline fun <T> visitMainSourceFileIn(
    reductionFolder: ReductionFolder,
    visitor: (SourceFile) -> T,
  ): T {
    return visitor.invoke(
      SourceFile(
        reductionFolder.folder.resolve(getMainSourceFileBaseName()),
        reductionInputs.mainDataKind as LanguageKind,
      ),
    )
  }

  fun getProfileFile() = workingFolder.resolve(
    getCompactNameForFileList(reductionInputs.relativePathSequence().asIterable()) + "." +
      TimeUtil.formatDateForFileName(System.currentTimeMillis()) + ".profile.txt",
  )

  fun backupMainFile(): ImmutableList<Path> {
    val formatDateForFileName = TimeUtil.formatDateForFileName(System.currentTimeMillis())
    val globalId = GlobalSequenceGenerator.nextWithPadding(paddingLength = 2, paddingChar = '0')
    return reductionInputs.orig2relativePathPairs
      .asSequence()
      .map {
        val fileToReduce = it.origFile
        val relativePath = it.relativePath
        val backupFile = workingFolder.resolve(
          "$relativePath.${formatDateForFileName}_$globalId.orig",
        )
        check(!Files.exists(backupFile)) {
          buildString {
            append(
              "The backup file ${backupFile.fileName} exists in directory ${backupFile.parent}",
            )
            append('\n')
            append("The directory currently has the following children.")
            workingFolder.listDirectoryEntries().forEach { fileInWorkingFolder ->
              append('\n')
              append("    ${fileInWorkingFolder.fileName}")
            }
          }
        }
        // Note that a file can be a binary file, so it is good to copy the file directly.
        Files.copy(fileToReduce.file, backupFile)
        backupFile
      }.toImmutableList()
  }

  val lazilyInitializedReductionFolderManager by lazy {
    materializeTempRootFolder()
    ReductionFolderManager(
      reductionInputs = reductionInputs,
      rootFolder = tempRootFolder,
    )
  }

  private fun materializeTempRootFolder(): Path {
    if (!Files.exists(tempRootFolder)) {
      Files.createDirectory(tempRootFolder)
    }
    check(Files.isDirectory(tempRootFolder)) {
      "The temp root folder is not a directory: $tempRootFolder"
    }
    return tempRootFolder
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    protected const val PERSES_TEMP_ROOT_PREFIX = "PersesTempRoot"
    protected const val DEFAULT_PERSES_BEST_DIR_NAME = "perses_result"
    protected val idGenerator = AtomicInteger(0)

    fun getCompactNameForFileList(fileList: Iterable<Path>): String {
      return fileList
        .groupBy { it.fileName.toString() }
        .map { (fileName, pathList) ->
          return if (pathList.size < 2) {
            fileName
          } else {
            return "${fileName}${pathList.size}"
          }
        }.joinToString("_")
    }

    @JvmStatic
    @VisibleForTesting
    fun getTempRootFolderName(
      fileNameForReduction: Iterable<Path>,
      testScriptName: String?,
      time: LocalDateTime,
    ): String {
      val separator = "_"
      val fileListString = getCompactNameForFileList(fileNameForReduction)
      return Joiner.on(separator)
        .join(
          PERSES_TEMP_ROOT_PREFIX,
          fileListString,
          testScriptName,
          TimeUtil.formatDateForFileName(time),
          Strings.padStart(idGenerator.getAndIncrement().toString(), 2, '0'),
        )
    }
  }

  init {
    require(Files.exists(workingFolder)) {
      "The working folder does not exist: $workingFolder"
    }
    require(Files.isDirectory(workingFolder)) {
      "The working folder is not a directory: $workingFolder"
    }
  }
}

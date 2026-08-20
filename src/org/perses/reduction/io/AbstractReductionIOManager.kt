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
package org.perses.reduction.io

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.Joiner
import com.google.common.base.Strings
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.util.TimeUtil
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption
import java.time.LocalDateTime
import java.util.concurrent.atomic.AtomicInteger
import kotlin.io.path.name

abstract class AbstractReductionIOManager<
  P,
  Self : AbstractReductionIOManager<P, Self>,
>(
  private val workingDirectory: Path,
  val originalReductionInputs: DefaultLanguageOriginalReductionInputs,
  val resultFolder: ReductionFolder,
) {
  /**
   * Writes an already-rendered [outputManager] to [resultFolder] as the current best. The caller
   * owns the renderer (the factory) -- e.g. a reduction driver, whose code format may be adapted --
   * renders the program itself, and passes the output manager here, so the IO manager stays out of
   * the rendering decision.
   */
  fun saveBestProgram(outputManager: AbstractOutputManager) {
    /*
     * We try to make the writing-best-result operation atomic.
     *
     * https://github.com/uw-pluverse/perses/issues/9
     *
     * https://github.com/chengniansun/perses-private/issues/508
     */
    val tempDirectory = createCurrentBestResultFolder()
    outputManager.write(tempDirectory)
    Util.copyDirectory(
      tempDirectory.path,
      resultFolder.path,
      StandardCopyOption.REPLACE_EXISTING,
    )
    // `copyDirectory` only adds/overwrites; it never removes, so a file that is in [resultFolder] but
    // no longer rendered would linger forever. Delete any mutable file the output manager did not
    // render so the folder mirrors the rendered set. This is a no-op for every default output manager
    // (each renders the full fixed mutable-file set); it matters only when the set has shrunk -- e.g.
    // after the cross-file empty-file-deletion reducer drops an emptied file.
    val renderedFiles = outputManager.fileContentList.pairs.mapTo(HashSet()) { it.fileName }
    originalReductionInputs.mutableFiles.forEach { file ->
      if (file !in renderedFiles) {
        resultFolder.deleteMutableFile(file)
      }
    }
    tempDirectory.deleteThisDirectoryRecursively()
  }

  private var snapshotCounter = 0

  internal fun createCurrentBestResultFolder(): ReductionFolder {
    // create the result folder besides the resultFolder
    val timestamp = TimeUtil.formatDateForFileName(System.currentTimeMillis())
    val path =
      resultFolder.path.parent.resolve(
        resultFolder.path.name + "_best_result_snapshot_${++snapshotCounter}_at_" + timestamp,
      )
    check(!Files.exists(path))
    Files.createDirectories(path)
    check(Files.isDirectory(path)) { path }
    return ReductionFolder(originalReductionInputs, path)
  }

  fun getScriptFileBaseNameIn(folder: ReductionFolder): String {
    val scriptBaseName = originalReductionInputs.testScript.baseName
    check(folder.checkFileExistence(scriptBaseName))
    return scriptBaseName
  }

  /**
   * The *root-relative paths* (e.g. `dir/a.c` for a file in a subdirectory -- equal to the bare base
   * name only for a top-level file) of the input files actually present in [folder], in input order.
   * Keys off the input universe but keeps only files that exist on disk, so it tolerates a subset
   * folder: a mutable file deleted by the file-deletion phase is simply omitted (the never-deleted
   * test script and dependency files always remain). For a full folder this is every input file,
   * unchanged.
   *
   * The sole caller ([org.perses.reduction.reducer.FormatReducer]) runs the formatter with each path
   * (as a string) as the file argument and [folder] as the working directory, so it must be the
   * root-relative path, not the bare base name -- otherwise a nested or same-base-name file would not
   * be found. The `benchmark_toys/format_nested_c` golden test pins this.
   */
  fun getExistingInputFileRelativePathsIn(folder: ReductionFolder): ImmutableList<Path> =
    originalReductionInputs
      .relativePathSequence()
      .filter { folder.checkFileExistence(it.toString()) }
      .toImmutableList()

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    protected const val PERSES_TEMP_ROOT_PREFIX = "PersesTempRoot"
    protected val idGenerator = AtomicInteger(0)

    /**
     * Builds a [ReductionFolder] under [outputDirectory] populated with the original inputs -- the
     * test script and dependency files (written by [ReductionFolder] construction) plus every
     * mutable file's original content (written via [AbstractOutputManager.createForOriginalInput]).
     * Callers populate the result folder this way *before* constructing an IO manager that requires
     * it (e.g. [org.perses.reduction.io.token.TokenReductionIOManager]).
     */
    fun createPopulatedResultFolder(
      originalReductionInputs: AbstractOriginalReductionInputs,
      shaAlgorithm: EnumShaAlgorithm,
      outputDirectory: Path,
    ): ReductionFolder {
      val resultFolder = ReductionFolder(originalReductionInputs, outputDirectory)
      AbstractOutputManager
        .createForOriginalInput(
          originalReductionInputs,
          shaAlgorithm,
        ).write(resultFolder)
      return resultFolder
    }

    fun getCompactNameForFileList(fileList: Iterable<Path>): String {
      return fileList
        .groupBy { it.fileName.toString() }
        .map { (fileName, pathList) ->
          return if (pathList.size < 2) {
            fileName
          } else {
            "${fileName}${pathList.size}"
          }
        }.joinToString("_")
    }

    @JvmStatic
    @VisibleForTesting
    fun getTempRootFolderName(
      fileNameForReduction: Iterable<Path>,
      testScriptName: String?,
      time: LocalDateTime,
      currentProcessID: Long,
    ): String {
      val separator = "_"
      val fileListString = getCompactNameForFileList(fileNameForReduction)
      return Joiner
        .on(separator)
        .join(
          PERSES_TEMP_ROOT_PREFIX,
          fileListString,
          testScriptName,
          TimeUtil.formatDateForFileName(time),
          "pid_$currentProcessID",
          Strings.padStart(idGenerator.getAndIncrement().toString(), 2, '0'),
        )
    }
  }

  init {
    require(Files.exists(workingDirectory)) {
      "The working folder does not exist: $workingDirectory"
    }
    require(Files.isDirectory(workingDirectory)) {
      "The working folder is not a directory: $workingDirectory"
    }
  }
}

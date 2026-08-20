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

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractReductionFile
import org.perses.util.AbstractFileContent
import org.perses.util.FileNameContentPair
import org.perses.util.FileNameContentPairList
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.hashing.ShaHashCode
import org.perses.util.toImmutableList

abstract class AbstractOutputManager(
  private val originalReductionInputs: AbstractOriginalReductionInputs,
  private val shaAlgorithm: EnumShaAlgorithm,
) {
  val shaHashCode: ShaHashCode by lazy {
    AbstractFileContent.createFromListOfFileContents(
      shaHash = shaAlgorithm,
      fileContents = fileContentList.pairs.map { it.content },
    )
  }

  /**
   * The mutable files this manager renders, in order. Defaults to the whole fixed mutable-file set;
   * a manager whose program describes only a *subset* -- e.g. the cross-file manager after an empty
   * file has been dropped from the set -- overrides this to render just those files. The value must
   * be a distinct subset of [AbstractOriginalReductionInputs.mutableFiles], which [fileContentList] checks.
   */
  protected open val filesToRender: ImmutableList<out AbstractReductionFile<*, *>>
    get() = originalReductionInputs.mutableFiles

  // A list (not a map): its size is usually 1.
  val fileContentList: FileNameContentPairList<AbstractReductionFile<*, *>> by lazy {
    val files = filesToRender
    check(files.size == files.distinct().size) {
      "Files to render must be distinct: $files"
    }
    files.forEach { file ->
      check(originalReductionInputs.mutableFiles.any { it === file }) {
        "Not a mutable file of this reduction: $file. mutableFiles = ${originalReductionInputs.mutableFiles}"
      }
    }
    FileNameContentPairList(
      pairs =
        files
          .map { file ->
            FileNameContentPair(
              fileName = file,
              AbstractFileContent.TextFileContent(text = internalComputeContentForFile(file)),
            )
          }.toImmutableList(),
      fileNameExtractor = { fileName ->
        fileName.baseName
      },
    )
  }

  protected abstract fun internalComputeContentForFile(
    origReductionFile: AbstractReductionFile<*, *>,
  ): String

  fun write(folder: ReductionFolder) {
    fileContentList.pairs.forEach { (fileName, content) ->
      val destinationFile = folder.computeAbsPathForOrigFile(fileName)
      Util.ensureDirExists(destinationFile.parent)
      content.writeToFile(destinationFile)
    }
    writeMore(folder)
  }

  protected open fun writeMore(folder: ReductionFolder) {}

  companion object {
    /**
     * An output manager that emits every mutable file's original on-disk content. Writing it to a
     * folder materializes the original inputs there (the canonical way to populate a result folder
     * before a reduction starts). This is the default behavior of
     * [AbstractOutputManagerFactory.createOutputManagerForOriginalInput].
     */
    fun createForOriginalInput(
      originalReductionInputs: AbstractOriginalReductionInputs,
      shaAlgorithm: EnumShaAlgorithm,
    ): AbstractOutputManager =
      object : AbstractOutputManager(originalReductionInputs, shaAlgorithm) {
        override fun internalComputeContentForFile(
          origReductionFile: AbstractReductionFile<*, *>,
        ): String = origReductionFile.fileWithContent.textualFileContent
      }
  }
}

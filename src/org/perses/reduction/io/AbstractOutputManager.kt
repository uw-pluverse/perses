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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractReductionFile
import org.perses.util.AbstractFileContent
import org.perses.util.FileNameContentPair
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.hashing.ShaHashCode

abstract class AbstractOutputManager(
  private val reductionInputs: AbstractReductionInputs<*, *>,
  private val shaAlgorithm: EnumShaAlgorithm,
) {
  val shaHashCode: ShaHashCode by lazy {
    AbstractFileContent.createFromListOfFileContents(
      shaHash = shaAlgorithm,
      fileContents = fileContentList.map { it.content },
    )
  }

  val fileContentList: ImmutableList<FileNameContentPair<AbstractReductionFile<*, *>>> by lazy {
    val list = internalComputeFileContentList()
    check(list.size == reductionInputs.mutableFiles.size) {
      """
        | list = $list
        | 
        | mutableFiles = ${reductionInputs.mutableFiles}
      """.trimMargin()
    }
    list.zip(reductionInputs.mutableFiles).forEach { (first, second) ->
      val firstReductionFile = first.fileName
      check(firstReductionFile === second) {
        firstReductionFile.toString() + second.toString()
      }
    }
    list
  }

  fun tryToGetMainFileContentOrThrow(): FileNameContentPair<AbstractReductionFile<*, *>> {
    check(reductionInputs is AbstractSingleFileReductionInputs<*, *, *>) {
      "The reduction inputs have to have a single main file."
    }
    return fileContentList.single { it.fileName === reductionInputs.mainFile }
  }

  /**
   * Note that we use a list instead of a map, because the list size is usually 1 element long.
   */
  private fun internalComputeFileContentList():
    ImmutableList<FileNameContentPair<AbstractReductionFile<*, *>>> {
    val files = reductionInputs.mutableFiles
    val builder =
      ImmutableList.builderWithExpectedSize<FileNameContentPair<AbstractReductionFile<*, *>>>(
        files.size,
      )
    files.forEach {
      builder.add(
        FileNameContentPair(
          fileName = it,
          AbstractFileContent.TextFileContent(text = internalComputeContentForFile(it)),
        ),
      )
    }
    return builder.build()
  }

  protected abstract fun internalComputeContentForFile(
    origReductionFile: AbstractReductionFile<*, *>,
  ): String

  fun write(folder: ReductionFolder) {
    fileContentList.forEach { (fileName, content) ->
      val destinationFile = folder.computeAbsPathForOrigFile(fileName)
      Util.ensureDirExists(destinationFile.parent)
      content.writeToFile(destinationFile)
    }
    writeMore(folder)
  }

  protected open fun writeMore(folder: ReductionFolder) {}
}

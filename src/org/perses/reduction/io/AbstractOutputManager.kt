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

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractReductionFile
import org.perses.util.Util
import kotlin.io.path.writeText

abstract class AbstractOutputManager(private val reductionInputs: AbstractReductionInputs<*, *>) {

  val shA512HashCode by lazy {
    Util.SHA512HashCode.createFromListOfStrings(
      fileContentList.map { it.second },
    )
  }

  val fileContentList: ImmutableList<Pair<AbstractReductionFile<*, *>, String>> by lazy {
    val list = internalComputeFileContentList()
    check(list.size == reductionInputs.programFiles.size)
    list.zip(reductionInputs.programFiles).forEach { (first, second) ->
      val firstReductionFile = first.first
      check(firstReductionFile === second) {
        firstReductionFile.toString() + second.toString()
      }
    }
    list
  }

  /**
   * Note that we use a list instead of a map, because the list size is usually 1 element long.
   */
  private fun internalComputeFileContentList():
    ImmutableList<Pair<AbstractReductionFile<*, *>, String>> {
    val files = reductionInputs.programFiles
    val builder =
      ImmutableList.builderWithExpectedSize<Pair<AbstractReductionFile<*, *>, String>>(
        files.size,
      )
    files.forEach {
      builder.add(Pair(it, internalComputeContentForFile(it)))
    }
    return builder.build()
  }

  protected abstract fun internalComputeContentForFile(
    origReductionFile: AbstractReductionFile<*, *>,
  ): String

  fun write(folder: ReductionFolder) {
    fileContentList.forEach { pair ->
      val destinationFile = folder.computeAbsPathForOrigFile(pair.first)
      Util.ensureDirExists(destinationFile.parent)
      destinationFile.writeText(pair.second)
    }
    writeMore(folder)
  }

  protected open fun writeMore(folder: ReductionFolder) {}
}

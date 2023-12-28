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
package org.perses.ppr.diff.tree

import com.beust.jcommander.Parameter
import org.perses.CommandOptions
import org.perses.cmd.InputFlagGroup
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

class TreeDiffCmdOptions : CommandOptions(defaultReductionAlgName) {

  override fun createInputFlags() = TreeDiffInputFlagGroup()

  val treeDiffInputFlags = inputFlags as TreeDiffInputFlagGroup

  class TreeDiffInputFlagGroup : InputFlagGroup() {

    @JvmField
    @Parameter(
      names = ["--variant-file", "--variant"],
      required = true,
      description = "The variant file to reduce",
      order = 11,
    )
    var variantFile: String? = null

    fun getVariantFile(): Path = Paths.get(checkNotNull(variantFile))

    override fun validate() {
      super.validate()

      val variantFile = getVariantFile()
      check(Files.isRegularFile(variantFile)) {
        val workingDirectory = Paths.get(".").toAbsolutePath()
        "The variant program $variantFile is not a file. " +
          "The current directory is $workingDirectory."
      }
    }
  }
}

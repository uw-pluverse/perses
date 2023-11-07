/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.ppr

import com.beust.jcommander.Parameter
import org.perses.CommandOptions
import org.perses.cmd.InputFlags
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import org.perses.util.cmd.CommonCmdOptionGroupOrder
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

class CmdOptions : CommandOptions(defaultReductionAlgName) {

  override fun createInputFlags() = OverallInputFlags()

  val overallInputFlags = inputFlags as OverallInputFlags

  class OverallInputFlags : InputFlags() {
    @JvmField
    @Parameter(
      names = ["--variant-file", "--variant", "-v"],
      required = true,
      description = "The variant file to reduce",
      order = CommonCmdOptionGroupOrder.COMPULSORY + 10,
    )
    var variantFile: Path? = null

    @JvmField
    @Parameter(
      names = ["--min-tdiff"],
      required = true,
      arity = 1,
      description = "if true, enable tree-based diff reduction",
      order = CommonCmdOptionGroupOrder.COMPULSORY + 11,
    )
    var minTDiff: Boolean = true

    @JvmField
    @Parameter(
      names = ["--min-commonality"],
      required = true,
      arity = 1,
      description = "if true, enable seed reduction with diff",
      order = CommonCmdOptionGroupOrder.COMPULSORY + 12,
    )
    var minCommonality: Boolean = true

    @JvmField
    @Parameter(
      names = ["--min-ldiff"],
      required = true,
      arity = 1,
      description = "if true, enable list-based diff reduction",
      order = CommonCmdOptionGroupOrder.COMPULSORY + 13,
    )
    var minLDiff: Boolean = true

    @JvmField
    @Parameter(
      names = ["--enable-diff-slicer"],
      description = "Enable diff slicer after syntax-guided variant reduction is done. Maybe slow.",
      arity = 1,
      order = CommonCmdOptionGroupOrder.COMPULSORY + 14,
    )
    var enableDiffSlicer = true

    @JvmField
    @Parameter(
      names = ["--enable-diff-ddmin"],
      description = "Enable diff delta debugging reducer " +
        "after syntax-guided variant reduction is done.",
      arity = 1,
      order = CommonCmdOptionGroupOrder.COMPULSORY + 15,
    )
    var enableDiffDdmin = true

    @JvmField
    @Parameter(
      names = ["--enable-mirror"],
      required = false,
      arity = 1,
      description = "List-based diff is not as symmetrical as Tree-based diff. " +
        "If mirror is enabled, it swaps the position of seed and variant, " +
        "and perform the same reduce algorithm once more.",
      order = CommonCmdOptionGroupOrder.COMPULSORY + 16,
    )
    var mirror: Boolean = false

    override fun validate() {
      super.validate()

      check(Files.isRegularFile(variantFile)) {
        val workingDirectory = Paths.get(".").toAbsolutePath()
        "The seed program $variantFile is not a file. The current directory is $workingDirectory."
      }

      check(enableDiffDdmin || enableDiffSlicer) {
        "You need to enable at least slicer or ddmin for ldiff reduction."
      }
    }
  }
}

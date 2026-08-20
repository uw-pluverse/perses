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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.util.cmd.AbstractCommandLineFlagGroup

class ReductionAlgorithmControlFlagGroup :
  AbstractCommandLineFlagGroup(groupName = "Reduction Algorithm Control") {
  @JvmField
  @Parameter(
    names = ["--alg"],
    description = "The main reduction algorithm: use --list-algs to list all available algorithms",
    order = 0,
  )
  var mainReductionAlgorithm: String? = null

  // TODO(cnsun): we need to allow to use a different reduction algorithm for the cleanup.
  @JvmField
  @Parameter(
    names = ["--cleanup-alg"],
    description =
      "The cleanup reduction algorithm, " +
        "which is the non-first reduction algorithm used in the fixpoint iteration. " +
        "Use --list-algs to list all available algorithms.",
    order = 5,
  )
  var cleanupReductionAlgorithm: String? = null

  @JvmField
  @Parameter(
    names = ["--list-algs"],
    description = "list all the reduction algorithms.",
    help = true,
    order = 10,
  )
  var listAllReductionAlgorithms = false

  @Parameter(
    names = ["--reparse-each-iteration"],
    description = "Reparse the program before the start of each fixpoint iteration.",
    arity = 1,
    order = 20,
  )
  var rebuildParseTreeEachIteration = true

  @Parameter(
    names = ["--enable-token-slicer"],
    description = "Enable token slicer after syntax-guided reduction is done. Maybe slow.",
    arity = 1,
    order = 30,
  )
  var enableTokenSlicer = false

  @Parameter(
    names = ["--enable-tree-slicer"],
    description = "Enable tree slicer after syntax-guided reduction, and before token slicer",
    arity = 1,
    order = 40,
  )
  var enableTreeSlicer = false

  @Parameter(
    names = ["--line-slicer"],
    description =
      "whether to run the line slicer (after syntax-guided reduction, before the token slicer): " +
        "auto (only for files that do not parse under their real grammar), on (every file), or off",
    arity = 1,
    order = 50,
  )
  var lineSlicer: EnumPassMode = EnumPassMode.AUTO

  @Parameter(
    names = ["--default-list-minimizer-for-hdd"],
    description = "The default list minimizer algorithm to reduce kleene nodes.",
    arity = 1,
    hidden = true,
    order = 65,
  )
  var defaultListMinimizerTypeForHDD = EnumListMinimizerType.CDD

  @Parameter(
    names = ["--min-slicing-window-size"],
    description = "The minimum window size of the windowed slicer.",
    arity = 1,
    order = 70,
  )
  var minSlicingWindowSize = 1

  @Parameter(
    names = ["--max-slicing-window-size"],
    description = "The maximum window size of the windowed slicer.",
    arity = 1,
    order = 80,
  )
  var maxSlicingWindowSize = 14

  override fun validate() {
    require(minSlicingWindowSize > 0) { "minSlicingWindowSize must be greater than 0" }
    require(maxSlicingWindowSize >= minSlicingWindowSize) {
      "maxSlicingWindowSize must be greater than or equal to minSlicingWindowSize"
    }
  }
}

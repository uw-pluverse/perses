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

class PersesFlagGroup :
  AbstractCommandLineFlagGroup(groupName = "Classical Perses Reducer Control") {
  @JvmField
  @Parameter(
    names = ["--enable-top-down-reduction"],
    description = "Enable the main top-down queue-based reduction from root to leaves.",
    arity = 1,
    hidden = true,
    order = 300,
  )
  var enableTopDownReduction = true

  @JvmField
  @Parameter(
    names = ["--enable-reducing-regular-rule-node"],
    description =
      "Enables the reduction on regular rule node (non-kleene, non-optional nodes)." +
        " This flag is created mainly for writing tests.",
    arity = 1,
    hidden = true,
    order = 400,
  )
  var enableReductionOnRegularNodes = true

  @JvmField
  @Parameter(
    names = ["--max-edit-count-for-regular-rule-node"],
    description = "The max count of edit candidates for reducing a regular rule node.",
    arity = 1,
    hidden = true,
    order = 500,
  )
  var maxEditCountForRegularRuleNode = 100

  @JvmField
  @Parameter(
    names = ["--max-bfs-depth-for-regular-rule-node"],
    description = "The max count of edit candidates for reducing a regular rule node.",
    arity = 1,
    hidden = true,
    order = 800,
  )
  var maxBfsDepthForRegularRuleNode = 5

  @JvmField
  @Parameter(
    names = ["--enable-literal-replacement-for-regular-rule-node"],
    description = "enable literal replacement of regular rule node.",
    arity = 1,
    hidden = true,
    order = 900,
  )
  var enableLiteralReplacementForRegularRuleNode = false

  @JvmField
  @Parameter(
    names = ["--enable-literal-replacement-for-list-minimizer"],
    description = "enable literal replacement in list minimizer when trying to delete elements",
    hidden = true,
    order = 1000,
    arity = 1,
  )
  var enableLiteralReplacementForListMinimizer = false

  @JvmField
  @Parameter(
    names = ["--stop-at-first-compatible-child-for-regular-rule-node"],
    description = "The max count of edit candidates for reducing a regular rule node.",
    arity = 1,
    hidden = true,
    order = 1100,
  )
  var stopAtFirstCompatibleChildForRegularRuleNode = false

  @Parameter(
    names = ["--default-list-minimizer-for-kleene"],
    description = "The default list minimizer algorithm to reduce kleene nodes.",
    arity = 1,
    order = 1200,
  )
  var listMinimizerTypeForKleene = EnumListMinimizerType.DFS

  @JvmField
  @Parameter(
    names = ["--enable-reducing-kleene-and-optional-node"],
    description =
      "Enables the reduction on Kleene and Optional node." +
        " This flag is created mainly for experimentation.",
    arity = 1,
    hidden = true,
    order = 1300,
  )
  var enableReductionOnKleeneAndOptionalNodes = true

  @JvmField
  @Parameter(
    names = ["--anticipated-result-token-count"],
    description = "anticipate how many tokens will remain in the result",
    hidden = true,
    order = 600,
    arity = 1,
  )
  var anticipatedTokenCountInResult = 150

  override fun validate() {
  }
}

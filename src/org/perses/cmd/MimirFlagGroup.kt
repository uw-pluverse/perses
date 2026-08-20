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
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm
import org.perses.util.cmd.AbstractCommandLineFlagGroup

class MimirFlagGroup :
  AbstractCommandLineFlagGroup(
    groupName = "Mimir Reducer Control",
    hidden = true,
  ) {
  @Parameter(
    names = ["--mimir-node-count-to-use-1by1"],
    description = "The threshold of node count to use one-by-one list minimizer",
    arity = 1,
    hidden = true,
    order = 200,
  )
  var nodeCountThresholdToUseOneByOne = 10

  @Parameter(
    names = ["--mimir-further-reduce-nodes-with-zeroed-out-degree"],
    description = "Whether to further reduce the nodes whose out-degree is zeroed",
    arity = 1,
    hidden = true,
    order = 300,
  )
  var enableBottomUpReductionAfterMainReductionLoop = true

  @Parameter(
    names = ["--mimir-bottom-up-reduction-max-depth"],
    description =
      "The max depth we can go up from the leaves toward the root. " +
        "To limit the search space",
    arity = 1,
    hidden = true,
    order = 400,
  )
  var bottomUpReductionMaxDepth = 5

  @Parameter(
    names = ["--mimir-reduction-algorithm"],
    description =
      "The Mimir reduction algorithm to use",
    arity = 1,
    hidden = true,
    order = 700,
  )
  var mimirReductionAlgorithm = EnumMimirReductionAlgorithm.FINE_DAG_AS_LIST

  @Parameter(
    names = ["--enable-mimir-for-regular-node"],
    description =
      "The Mimir reduction algorithm to use",
    arity = 1,
    hidden = true,
    order = 800,
  )
  var enableMimirForRegularNode = true

  @Parameter(
    names = ["--enable-mimir-delete-def-with-all-its-concrete-uses"],
    description =
      "In Mimir, delete a def node with all its concrete uses (not the use nodes in the DAG)",
    arity = 1,
    hidden = true,
    order = 900,
  )
  var enableMimirDeleteDefWithAllItsConcreteUses = false

  @Parameter(
    names = ["--mimir-java-language-server-cmd"],
    description = "The command to start the Java language server",
    arity = 1,
    hidden = true,
    order = 1000,
  )
  var javaLanguageServerCmd: String? = "start_jdtls.sh"

  @Parameter(
    names = ["--mimir-c-language-server-cmd"],
    description = "The command to start the C language server",
    arity = 1,
    hidden = true,
    order = 1100,
  )
  var cLanguageServerCmd = "clangd-18"

  override fun validate() {
    require(nodeCountThresholdToUseOneByOne >= 0) {
      "The node count threshold must be greater than or equal to 0"
    }
  }
}

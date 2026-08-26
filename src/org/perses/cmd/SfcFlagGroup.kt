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
import org.perses.util.cmd.AbstractCommandLineFlagGroup

/**
 * Controls the reducers built on Structure Form Conversion: a subtree is replaced with a subtree
 * of another production of the same nonterminal, assembled from the pieces of the original
 * subtree.
 */
class SfcFlagGroup :
  AbstractCommandLineFlagGroup(groupName = "SFC (Structure Form Conversion) Reducer Control") {
  @Parameter(
    names = ["--enable-sfc"],
    description =
      "Enable the SFC reducers (structure form conversion, to produce smaller " +
        "reduction output at the cost of more property tests).",
    arity = 1,
    order = 0,
  )
  var enableSfc = false

  @Parameter(
    names = ["--sfc-fixpoint"],
    description = "Enable fixpoint mode for running the SFC reducers.",
    arity = 1,
    order = 100,
  )
  var enableFixpoint = true

  @Parameter(
    names = ["--sfc-subtree-token-count-limit"],
    description =
      "Skip a subtree whose token count exceeds this limit: the number of structures of a " +
        "subtree grows with the number of its reusable pieces.",
    order = 200,
  )
  var subtreeTokenCountLimit = DEFAULT_SUBTREE_TOKEN_COUNT_LIMIT

  @Parameter(
    names = ["--sfc-candidate-limit"],
    description = "The maximum number of candidate structures to test for a single subtree.",
    order = 300,
  )
  var candidateLimit = DEFAULT_CANDIDATE_LIMIT

  override fun validate() {
    require(subtreeTokenCountLimit > 0) {
      "The subtree token count limit must be positive: $subtreeTokenCountLimit"
    }
    require(candidateLimit > 0) {
      "The candidate limit must be positive: $candidateLimit"
    }
  }

  companion object {
    const val DEFAULT_SUBTREE_TOKEN_COUNT_LIMIT = 64
    const val DEFAULT_CANDIDATE_LIMIT = 64
  }
}

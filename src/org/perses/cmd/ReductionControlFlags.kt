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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.program.EnumFormatControl
import org.perses.util.cmd.CommonCmdOptionGroupOrder
import org.perses.util.cmd.ICommandLineFlags

class ReductionControlFlags : ICommandLineFlags {
  @JvmField
  @Parameter(
    names = ["--fixpoint"],
    description = "iterative reduction till fixpoint",
    arity = 1,
    order = CommonCmdOptionGroupOrder.REDUCTION_CONTROL + 0
  )
  var fixpoint = true

  @Parameter(
    names = ["--threads"],
    description = "Number of reduction threads: a positive integer, or 'auto'.",
    order = CommonCmdOptionGroupOrder.REDUCTION_CONTROL + 1
  )
  private var numOfThreads = "auto"

  @Parameter(
    names = ["--code-format"],
    description = "The format of the reduced program.",
    arity = 1,
    order = CommonCmdOptionGroupOrder.REDUCTION_CONTROL + 2
  )
  var codeFormat: EnumFormatControl? = null

  override fun validate() {
    if ("auto" != numOfThreads) {
      check(numOfThreads.toInt() > 0) { numOfThreads }
    }
  }

  fun getNumOfThreads(): Int {
    return if ("auto" == numOfThreads) {
      Runtime.getRuntime().availableProcessors()
    } else {
      numOfThreads.toInt()
    }
  }
}

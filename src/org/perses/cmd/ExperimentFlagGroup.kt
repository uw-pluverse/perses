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
package org.perses.cmd

import com.beust.jcommander.IStringConverter
import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup

class ExperimentFlagGroup : AbstractCommandLineFlagGroup(groupName = "Experiment Control") {
  @JvmField
  @Parameter(
    names = ["--on-demand-fine-grit-reducer-annotations"],
    description = "the list of fine-grit reducer classes to be called after the main reduction",
    hidden = true,
    order = 100,
    converter = ClassConverter::class,
  )
  var onDemandFineGritReducerAnnotationClasses: List<Class<*>> = listOf()

  @JvmField
  @Parameter(
    names = ["--on-demand-medium-grit-reducer-annotations"],
    description = "the list of medium-grit reducer classes to be called after the main reduction",
    hidden = true,
    order = 200,
    converter = ClassConverter::class,
  )
  var onDemandMediumGritReducerAnnotationClasses: List<Class<*>> = listOf()

  @JvmField
  @Parameter(
    names = ["--on-demand-coarse-grit-reducer-annotations"],
    description = "the list of coarse-grit reducer classes to be called after the main reduction",
    hidden = true,
    order = 300,
    converter = ClassConverter::class,
  )
  var onDemandCoarseGritReducerAnnotationClasses: List<Class<*>> = listOf()

  override fun validate() = Unit

  @JvmField
  @Parameter(
    names = ["--fully-deterministic-mode"],
    description =
      "make sure the reduction process is fully deterministic for testing purpose " +
        "at the cost of affected performance",
    hidden = true,
    order = 400,
    arity = 1,
  )
  var fullyDeterministicMode = false

  @JvmField
  @Parameter(
    names = ["--keep-reduction-history"],
    description = "keep all the reduction folders generated during reduction",
    hidden = false,
    order = 500,
    arity = 1,
  )
  var keepReductionHistory = false

  class ClassConverter : IStringConverter<Class<*>> {
    override fun convert(className: String?): Class<*> {
      requireNotNull(className)
      return Class.forName(className)
    }
  }
}

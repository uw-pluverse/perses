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
package org.perses

import org.perses.cmd.CacheControlFlags
import org.perses.cmd.ExperimentFlags
import org.perses.cmd.InputFlags
import org.perses.cmd.LanguageControlFlags
import org.perses.cmd.OutputFlags
import org.perses.cmd.OutputRefiningFlags
import org.perses.cmd.ProfilingFlags
import org.perses.cmd.ReductionAlgorithmControlFlags
import org.perses.cmd.ReductionControlFlags
import org.perses.cmd.VulcanFlags
import org.perses.util.cmd.AbstractCommandOptions

/** Parser for command line arguments.  */
open class CommandOptions(defaultReductionAlgorithm: String) : AbstractCommandOptions() {

  val inputFlags = registerFlags(createInputFlags())
  val resultOutputFlags = registerFlags(OutputFlags())
  val reductionControlFlags = registerFlags(ReductionControlFlags())
  val outputRefiningFlags = registerFlags(OutputRefiningFlags())
  val algorithmControlFlags = registerFlags(
    ReductionAlgorithmControlFlags(defaultReductionAlgorithm),
  )
  val cacheControlFlags = registerFlags(CacheControlFlags())
  val profilingFlags = registerFlags(ProfilingFlags())
  val experimentFlags = registerFlags(ExperimentFlags())
  val languageControlFlags = registerFlags(LanguageControlFlags())
  val vulcanFlags = registerFlags(VulcanFlags())
  open fun createInputFlags() = InputFlags()
}

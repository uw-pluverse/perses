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
package org.perses.ppr

import org.perses.PersesCommandOptions
import org.perses.cmd.LatraFlagGroup
import org.perses.cmd.MimirFlagGroup
import org.perses.cmd.PersesFlagGroup
import org.perses.cmd.TRecFlagGroup

abstract class AbstractPPRCommandOptions : PersesCommandOptions() {
  override val latraFlags: LatraFlagGroup
    get() {
      val flags = super.latraFlags
      flags.enableLatra = false
      return flags
    }

  override val trecFlags: TRecFlagGroup
    get() {
      val flags = super.trecFlags
      flags.enableTRec = false
      return flags
    }

  override val persesFlags: PersesFlagGroup
    get() {
      val flags = super.persesFlags
      flags.enableLiteralReplacementForRegularRuleNode = false
      flags.enableLiteralReplacementForListMinimizer = false
      return flags
    }

  override val mimirFlags: MimirFlagGroup
    get() {
      val flags = super.mimirFlags
      return flags
    }

  override fun validateExtra() {
    super.validateExtra()
    val inputFiles = inputFlags.computeInputFiles()
    check(inputFiles.size == 1) {
      "PPR supports exactly one input file, but ${inputFiles.size} " +
        "were given: $inputFiles."
    }
    check(!trecFlags.enableTRec) {
      "The token reducer is not compatible with PPR."
    }
    check(!latraFlags.enableLatra) {
      "The latra reducer is not compatible with PPR."
    }
    check(!persesFlags.enableLiteralReplacementForRegularRuleNode) {
      "The literal replacement is not compatible with PPR."
    }
    check(!persesFlags.enableLiteralReplacementForListMinimizer) {
      "The literal replacement is not compatible with PPR."
    }
  }
}

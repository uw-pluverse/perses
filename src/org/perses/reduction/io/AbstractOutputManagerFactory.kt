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
package org.perses.reduction.io

import org.perses.util.hashing.EnumShaAlgorithm

abstract class AbstractOutputManagerFactory<Program>(
  open val originalReductionInputs: AbstractOriginalReductionInputs,
  val shaAlgorithm: EnumShaAlgorithm,
) {
  /**
   * Creates an output manager that renders the whole mutable-file set for [program]. Everything the
   * factory needs beyond the program -- e.g. which file the program represents and where the other
   * mutable files' content comes from, in the single-tree case -- is supplied to the factory at
   * construction, so this method takes only the program.
   */
  abstract fun createManagerFor(program: Program): AbstractOutputManager

  open fun createOutputManagerForOriginalInput(): AbstractOutputManager =
    AbstractOutputManager.createForOriginalInput(originalReductionInputs, shaAlgorithm)
}

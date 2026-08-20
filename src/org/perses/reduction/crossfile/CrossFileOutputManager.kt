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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractReductionFile
import org.perses.reduction.io.AbstractOriginalReductionInputs
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.toImmutableList

/**
 * Builds output managers for a [CrossFileProgram]. The program is self-complete -- it already
 * carries the content of every mutable file -- so the factory needs nothing beyond the program;
 * each file's content is read straight from the map.
 */
class CrossFileOutputManagerFactory(
  originalReductionInputs: AbstractOriginalReductionInputs,
  shaAlgorithm: EnumShaAlgorithm,
) : AbstractOutputManagerFactory<CrossFileProgram>(originalReductionInputs, shaAlgorithm) {
  override fun createManagerFor(program: CrossFileProgram): AbstractOutputManager =
    CrossFileOutputManager(originalReductionInputs, shaAlgorithm, program)
}

/**
 * Renders each of the [program]'s files' content directly from the whole-set [program].
 *
 * The default [AbstractOutputManager] renders exactly the fixed [AbstractOriginalReductionInputs.mutableFiles]
 * set. A [CrossFileProgram], however, holds content only for its *currently-live* files: once an
 * (emptied) file is dropped from the set, the program no longer has a key for it. So this manager
 * overrides [filesToRender] with just the program's keys -- the live files -- which makes the dropped
 * file truly absent from the rendered folder (not written as an empty file). `find`-based test
 * scripts therefore no longer see it, and the SHA hash (computed from the rendered content)
 * distinguishes a set with the file from a set without it, keeping the query cache correct.
 */
class CrossFileOutputManager(
  originalReductionInputs: AbstractOriginalReductionInputs,
  shaAlgorithm: EnumShaAlgorithm,
  private val program: CrossFileProgram,
) : AbstractOutputManager(originalReductionInputs, shaAlgorithm) {
  override val filesToRender: ImmutableList<out AbstractReductionFile<*, *>>
    get() = program.fileContents.keys.toImmutableList()

  override fun internalComputeContentForFile(
    origReductionFile: AbstractReductionFile<*, *>,
  ): String = program[origReductionFile]
}

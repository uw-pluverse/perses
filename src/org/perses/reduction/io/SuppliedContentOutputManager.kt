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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.toImmutableList

/**
 * An [AbstractOutputManager] for the common case where exactly one mutable file
 * ([fileRepresentedByProgram]) is the program currently being reduced, and every other mutable file
 * is fixed context whose content [otherMutableFileContents] supplies.
 *
 * The keys of [otherMutableFileContents] are the sibling files to render, so the rendered set
 * ([filesToRender]) is the represented file plus those keys; a sibling absent from the map is neither
 * rendered nor looked up.
 *
 * The program is rendered to source by [renderFileRepresentedByProgram], invoked once (when the
 * file content list is first materialized). Subclasses may add [writeMore] to emit derived
 * artifacts.
 */
open class SuppliedContentOutputManager(
  originalReductionInputs: AbstractOriginalReductionInputs,
  shaAlgorithm: EnumShaAlgorithm,
  private val fileRepresentedByProgram: AbstractReductionFile<*, *>,
  private val otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
  private val renderFileRepresentedByProgram: () -> String,
) : AbstractOutputManager(originalReductionInputs, shaAlgorithm) {
  // The represented file plus the sibling files the map carries, in mutable-file slot order (a
  // sibling absent from the map -- none, in a normal reduction -- is not rendered).
  override val filesToRender: ImmutableList<out AbstractReductionFile<*, *>> =
    originalReductionInputs.mutableFiles
      .filter { it === fileRepresentedByProgram || otherMutableFileContents.containsKey(it) }
      .toImmutableList()

  final override fun internalComputeContentForFile(
    origReductionFile: AbstractReductionFile<*, *>,
  ): String =
    if (origReductionFile === fileRepresentedByProgram) {
      renderFileRepresentedByProgram()
    } else {
      otherMutableFileContents.getValue(origReductionFile)
    }
}

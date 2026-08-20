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

import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.ReductionFolder
import java.nio.file.Path

/**
 * The IO manager for true multi-file reduction. It binds the generic reduction stack's `Program`
 * type to [CrossFileProgram] -- a self-complete whole-set snapshot -- exactly as the ppr list-diff
 * reducer binds it to its diff op-list.
 *
 * Because a [CrossFileProgram] already describes every mutable file, this manager is session-level
 * (not bound to any one "file under reduction") and needs nothing beyond the base: the driver owns
 * the renderer (the output-manager factory), renders each accepted best itself, and commits it via
 * the inherited `saveBestProgram(outputManager)`.
 */
class CrossFileReductionIOManager(
  workingDirectory: Path,
  originalReductionInputs: DefaultLanguageOriginalReductionInputs,
  resultFolder: ReductionFolder,
) : AbstractReductionIOManager<CrossFileProgram, CrossFileReductionIOManager>(
    workingDirectory,
    originalReductionInputs,
    resultFolder,
  )

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

import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.AbstractWholeProgramReducer
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.AbstractOutputManagerFactory

/**
 * The base for a true multi-file reducer: it reduces a whole [CrossFileProgram] set at once, so a
 * single accepted edit can change several files together. It is an
 * [AbstractWholeProgramReducer] over the whole-set program; a concrete reducer drives some source of
 * candidate whole-set programs (e.g. a `CrossFileProgramTransformation`), checks each with
 * `testProgram`, and commits the best one via `state.updateBest(...)`.
 */
abstract class AbstractCrossFileReducer(
  nameAndDesc: AbstractReducerNameAndDesc,
  ioManager: CrossFileReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
  outputManagerFactory: AbstractOutputManagerFactory<CrossFileProgram>,
) : AbstractWholeProgramReducer<
    CrossFileProgram,
    CrossFileReductionIOManager,
    CrossFileReductionState,
  >(
    nameAndDesc,
    ioManager,
    testScriptExecutorService,
    outputManagerFactory,
  )

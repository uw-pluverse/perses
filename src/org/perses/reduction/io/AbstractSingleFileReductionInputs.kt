/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
import org.perses.program.AbstractDataKind
import org.perses.program.AbstractReductionFile
import org.perses.program.ScriptFile

abstract class AbstractSingleFileReductionInputs<
  K : AbstractDataKind,
  F : AbstractReductionFile<K, F>,
  S : AbstractSingleFileReductionInputs<K, F, S>,
  >(
  testScript: ScriptFile,
  val mainFile: F,
  files: ImmutableList<AbstractReductionFile<*, *>>,
) : AbstractReductionInputs<K, S>(
  testScript,
  mainDataKind = mainFile.dataKind,
  rootDirectory = mainFile.parentFile,
  files,
) {

  init {
    require(files.singleOrNull { it === mainFile } != null)
  }

  val relativePathForMainFile = getRelativePathForOrigFile(mainFile)
}

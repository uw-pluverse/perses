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
import org.perses.util.cmd.CommonCmdOptionGroupOrder
import org.perses.util.cmd.ICommandLineFlags
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

open class InputFlags : ICommandLineFlags {
  @JvmField
  @Parameter(
    names = ["--test-script", "--test", "-t"],
    required = true,
    description = "The test script to specify the property the reducer needs to preserve.",
    order = CommonCmdOptionGroupOrder.COMPULSORY + 0
  )
  var testScript: String? = null

  @JvmField
  @Parameter(
    names = ["--input-file", "--input", "-i"],
    required = true,
    description = "The input file to reduce",
    order = CommonCmdOptionGroupOrder.COMPULSORY + 1
  )
  var inputFile: String? = null

  fun getTestScript(): Path = Paths.get(checkNotNull(testScript))

  fun getSourceFile(): Path = Paths.get(checkNotNull(inputFile))

  override fun validate() {
    val testScript = getTestScript()
    val workingDirectory = Paths.get(".").toAbsolutePath()
    check(Files.isRegularFile(testScript)) {
      "The test script $testScript is not a file. The current directory is $workingDirectory."
    }
    check(Files.isExecutable(testScript)) {
      "The test script $testScript is not executable."
    }

    val sourceFile = getSourceFile()
    check(Files.isRegularFile(sourceFile)) {
      "The source program $sourceFile is not a file. The current directory is $workingDirectory."
    }
  }
}

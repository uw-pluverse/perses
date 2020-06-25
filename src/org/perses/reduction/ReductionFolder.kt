/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.program.ScriptFile
import java.io.File
import java.io.IOException

// TODO: save the test result in the folder.
class ReductionFolder internal constructor(
  val folder: File,
  testScriptTemplate: ScriptFile,
  sourceFileName: String
) {
  val testScript: TestScript = TestScript(
    File(folder, testScriptTemplate.baseName),
    testScriptTemplate
  )
  val sourceFilePath: File = File(folder, sourceFileName)

  @Throws(IOException::class)
  fun deleteAllOtherFiles() {
    val fileNamesToKeep = ImmutableList.of(testScript.scriptFile.name, sourceFilePath.name)
    val filesToDelete = folder.listFiles { _, name -> !fileNamesToKeep.contains(name) }
    for (fileToDelete in filesToDelete) {
      if (fileToDelete.isDirectory) {
        MoreFiles.deleteRecursively(fileToDelete.toPath(), RecursiveDeleteOption.ALLOW_INSECURE)
      } else {
        fileToDelete.delete()
      }
    }
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("working directory", folder).toString()
  }

  init {
    assert(testScript.scriptFile.isFile) {
      "The test script file ${testScript.scriptFile} does not exist"
    }
    assert(testScript.scriptFile.canExecute()) {
      "The test script file $testScript"
    }
  }
}

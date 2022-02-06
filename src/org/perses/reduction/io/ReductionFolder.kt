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
package org.perses.reduction.io

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.util.Util
import java.io.IOException
import java.nio.file.FileVisitResult
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.SimpleFileVisitor
import java.nio.file.attribute.BasicFileAttributes

// TODO: save the test result in the folder.
class ReductionFolder(
  private val reductionInputs: AbstractReductionInputs,
  val folder: Path
) {
  @VisibleForTesting
  val testScript = reductionInputs.writeTestScriptTo(folder)

  fun runTestScript() = testScript.test()

  fun checkFileExistence(baseName: String) = Files.exists(folder.resolve(baseName))

  fun deleteAllOtherFiles() {
    val fileToKeep = ImmutableList
      .builder<Path>()
      .add(testScript.scriptFile)
      .addAll(reductionInputs.computeAbsolutePathListWRT(folder))
      .build()
    Files.walkFileTree(
      folder,
      object : SimpleFileVisitor<Path>() {
        override fun visitFile(file: Path, attrs: BasicFileAttributes?): FileVisitResult {
          if (!fileToKeep.any { Files.isSameFile(it, file) }) {
            Files.delete(file)
          }
          return super.visitFile(file, attrs)
        }

        override fun postVisitDirectory(dir: Path, exc: IOException?): FileVisitResult {
          if (Util.isEmptyDirectory(dir)) {
            Files.delete(dir)
          }
          return super.postVisitDirectory(dir, exc)
        }
      }
    )
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("working directory", folder).toString()
  }

  init {
    assert(Files.isRegularFile(testScript.scriptFile)) {
      "The test script file ${testScript.scriptFile} does not exist"
    }
    assert(Files.isExecutable(testScript.scriptFile)) {
      "The test script file $testScript"
    }
  }
}

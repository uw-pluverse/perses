/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer

import com.google.common.flogger.FluentLogger
import org.perses.util.shell.ExitCode
import org.perses.util.shell.Shells
import java.lang.RuntimeException
import java.nio.file.Files
import java.nio.file.Files.isExecutable
import java.nio.file.Files.isRegularFile
import java.nio.file.Path

abstract class AbstractExtensionScript {
  abstract fun run(mutantFile: Path)

  companion object {
    val ERROR_EXIT_CODE = ExitCode(100)

    val logger = FluentLogger.forEnclosingClass()
  }
}

class NullExtensionScript : AbstractExtensionScript() {
  override fun run(mutantFile: Path) {
  }
}

class ExtensionScript(
  val extensionScript: Path,
  val resultFolder: Path,
) : AbstractExtensionScript() {

  val absResultFolder = resultFolder.toAbsolutePath()

  override fun run(mutantFile: Path) {
    val cmd = "$extensionScript $mutantFile $absResultFolder"
    val cmdOutput = Shells.singleton.run(
      cmd,
      false,
      Shells.CURRENT_ENV,
    )
    if (cmdOutput.exitCode == ERROR_EXIT_CODE) {
      val message = "Fatal error in extension script $extensionScript"
      logger.atSevere().log(message)
      throw RuntimeException(message)
    }
  }

  init {
    check(isRegularFile(extensionScript)) {
      "The extension script $extensionScript is not a regular file."
    }
    check(isExecutable(extensionScript)) {
      "The extension script $extensionScript is not executable."
    }
    Files.createDirectories(resultFolder)
  }
}

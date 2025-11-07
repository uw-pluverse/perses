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
package org.pluverse.perses

import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.InputOutputOnlyCommandOptions
import org.perses.version.Version
import kotlin.io.path.readText
import kotlin.io.path.writeText

class DownloadLinkDumpMain(
  cmd: InputOutputOnlyCommandOptions,
) : AbstractMain<InputOutputOnlyCommandOptions>(cmd) {
  override fun internalRun() {
    var template = cmd.inputFlags.inputFile!!.readText()
    template = template.replace("{majorVersion}", Version.MAJOR_VERSION)
    template = template.replace("{minorVersion}", Version.MINOR_VERSION)

    cmd.outputFlags.outputFile!!.writeText(template)
  }

  companion object {
    @Suppress("UNUSED_PARAMETER")
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { InputOutputOnlyCommandOptions() },
          programName = DownloadLinkDumpMain::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      DownloadLinkDumpMain(processor.cmd).run()
    }
  }
}

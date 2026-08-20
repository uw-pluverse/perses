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
package org.perses.analyzer.differential

import com.google.common.flogger.FluentLogger
import org.perses.listener.DifferentialEvents
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.CommandLineProcessor.HelpRequestProcessingDecision
import javax.swing.SwingUtilities

class Main(
  cmd: DifferentialAnalyzerCmdOptions,
) : AbstractMain<DifferentialAnalyzerCmdOptions>(cmd) {
  override fun internalRun() {
    var input1 = cmd.inputFlags.inputFiles.getOrNull(0)
    var input2 = cmd.inputFlags.inputFiles.getOrNull(1)

    if (input1 == null || input2 == null) {
      val dialog = FileSelectionDialog()
      dialog.isVisible = true
      val selected = dialog.selectedFiles ?: return
      input1 = selected.first
      input2 = selected.second
    }

    FileSelectionDialog.savePaths(input1, input2)

    val first = DifferentialEvents.readFromYamlFile(input1)
    val second = DifferentialEvents.readFromYamlFile(input2)

    val finalInput1 = input1
    val finalInput2 = input2

    SwingUtilities.invokeLater {
      EventDiffWindow(
        leftPath = finalInput1.toString(),
        leftEvents = first,
        rightPath = finalInput2.toString(),
        rightEvents = second,
      ).isVisible = true
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { DifferentialAnalyzerCmdOptions() },
          programName = Main::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == HelpRequestProcessingDecision.EXIT) {
        return
      }
      val cmd = processor.cmd
      Main(cmd).run()
    }
  }
}

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
package org.perses.analyzer.sizetrend

import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.CommandLineProcessor.HelpRequestProcessingDecision
import javax.swing.SwingUtilities

class Main(
  cmd: SizeTrendCmdOptions,
) : AbstractMain<SizeTrendCmdOptions>(cmd) {
  override fun internalRun() {
    val resolvedFiles = mutableListOf<java.nio.file.Path>()
    for (path in cmd.inputFlags.inputFiles) {
      if (java.nio.file.Files
          .isDirectory(path)
      ) {
        val csvFiles =
          java.nio.file.Files
            .newDirectoryStream(path, "*.csv")
            .use { it.toList() }
            .sortedBy { it.fileName.toString() }
        resolvedFiles.addAll(csvFiles)
      } else {
        resolvedFiles.add(path)
      }
    }

    if (resolvedFiles.isEmpty()) {
      System.err.println("Error: No CSV files found to plot.")
      System.exit(1)
    }

    SwingUtilities.invokeLater {
      SizeTrendWindow(resolvedFiles).isVisible = true
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { SizeTrendCmdOptions() },
          programName = "sizetrend",
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

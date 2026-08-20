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

import org.perses.listener.DifferentialEvents
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.InputOutputOnlyCommandOptions
import javax.swing.tree.DefaultMutableTreeNode
import kotlin.io.path.bufferedWriter

class EventDiffTreeModelDumpMain(
  cmd: InputOutputOnlyCommandOptions,
) : AbstractMain<InputOutputOnlyCommandOptions>(cmd) {
  override fun internalRun() {
    val events = DifferentialEvents.readFromYamlFile(cmd.inputFlags.inputFile!!)

    cmd.outputFlags.outputFile!!.bufferedWriter().use { writer ->
      val (model, _) = EventDiffTreeModelBuilder.createEventTreeModel("Events", events)
      writer.write(printTree(model.root as DefaultMutableTreeNode))
    }
  }

  private fun printTree(
    node: DefaultMutableTreeNode,
    indent: String = "",
  ): String {
    val sb = StringBuilder()
    sb.append(indent).append(node.userObject).append("\n")
    for (i in 0 until node.childCount) {
      sb.append(printTree(node.getChildAt(i) as DefaultMutableTreeNode, indent + "  "))
    }
    return sb.toString()
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { InputOutputOnlyCommandOptions() },
          programName = EventDiffTreeModelDumpMain::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      EventDiffTreeModelDumpMain(processor.cmd).run()
    }
  }
}

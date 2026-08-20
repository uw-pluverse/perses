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
package org.perses.mimir

import org.perses.TestUtility
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.InputOutputOnlyCommandOptions
import org.perses.util.shell.ShellCommandOnPath
import kotlin.io.path.bufferedWriter

class ScopedGraphDumpMain(
  cmd: InputOutputOnlyCommandOptions,
) : AbstractMain<InputOutputOnlyCommandOptions>(cmd) {
  override fun internalRun() {
    val sourceFile = cmd.inputFlags.inputFile!!
    val tree = TestUtility.createSparTreeFromFile(sourceFile)
    val semanticProvider =
      MimirSemanticsProviderCreator(ShellCommandOnPath("clangd-18"))
        .computeSemanticsForSparTree(sourceFile, sparTree = tree)
    cmd.outputFlags.outputFile!!.bufferedWriter(charset = Charsets.UTF_8).use { writer ->
      writer.write(tree.printTreeStructure())
      writer.write("\n")

      tree.realRoot.preOrderVisit { node ->
        val scopedGraphForCurrentNode = semanticProvider.buildScopedDependencyGraph(listOf(node))
        writer.write("Scoped graph for node ${node.nodeId}\n")
        writer.write(scopedGraphForCurrentNode.printGraphStructure())
        writer.write("\n")
        if (node.immutableChildView.isNotEmpty()) {
          val scopedGraphForChildren =
            semanticProvider.buildScopedDependencyGraph(node.immutableChildView)
          writer.write("Scoped graph for the children of node ${node.nodeId}\n")
          writer.write(scopedGraphForChildren.printGraphStructure())
          writer.write("\n")
        }
        node.immutableChildView
      }
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { InputOutputOnlyCommandOptions() },
          programName = ScopedGraphDumpMain::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      ScopedGraphDumpMain(processor.cmd).run()
    }
  }
}

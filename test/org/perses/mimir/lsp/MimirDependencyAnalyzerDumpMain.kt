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
package org.perses.mimir.lsp

import org.eclipse.lsp4j.Position
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.InputOutputOnlyCommandOptions
import org.perses.util.shell.ShellCommandOnPath
import kotlin.io.path.readLines
import kotlin.io.path.writeText

class MimirDependencyAnalyzerDumpMain(
  cmd: InputOutputOnlyCommandOptions,
) : AbstractMain<InputOutputOnlyCommandOptions>(cmd) {
  private val clangdCommand = ShellCommandOnPath("clangd-18")

  override fun internalRun() {
    val sourceFile = cmd.inputFlags.inputFile!!

    MimirDependencyAnalyzer(
      clangdCommand,
      sourceFile = sourceFile,
    ).use { analyzer ->
      val sourceLines = sourceFile.readLines()
      val content = printDefUseInformation(sourceLines, analyzer)
      cmd.outputFlags.outputFile!!.writeText(content)
    }
  }

  private fun printDefUseInformation(
    sourceLines: List<String>,
    analyzer: MimirDependencyAnalyzer,
  ): String {
    val entries = analyzer.defUseMap.entries.sortedBy { it.key.position.line }
    val result = StringBuilder()
    entries.forEach {
      val def = it.key
      val uses = it.value.sortedBy { it.position.line }

      val defPosition = def.position
      val defPositionString = toString(defPosition)
      result
        .append(
          "DEF: ${def.lexeme}@$defPositionString: ",
        ).append(sourceLines[def.position.line].trim())
        .append('\n')
      uses.forEach { use ->
        val usePosition = use.position
        val usePositionString = toString(usePosition)
        result
          .append(
            "  USE: ${use.lexeme}@$usePositionString: ",
          ).append(sourceLines[usePosition.line].trim())
          .append('\n')
      }
      result.append("\n")
    }
    return result.toString()
  }

  private fun toString(position: Position): String = "[${position.line + 1}:${position.character}]"

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { InputOutputOnlyCommandOptions() },
          programName = MimirDependencyAnalyzerDumpMain::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      MimirDependencyAnalyzerDumpMain(processor.cmd).run()
    }
  }
}

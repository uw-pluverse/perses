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
package org.perses.util

import com.beust.jcommander.Parameter
import org.antlr.v4.runtime.ParserRuleContext
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.dotgraph.DotGraph.NodeLabelProvider
import org.perses.dotgraph.TreeDotifier.dotifyAntlrParseTree
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import java.nio.file.Files
import java.nio.file.Path

class AntlrParseTreePdfierMain(
  cmd: CommandOptions,
) : AbstractMain<AntlrParseTreePdfierMain.CommandOptions>(cmd) {

  override fun internalRun() {
    val parserFacadeFactory = SingleParserFacadeFactory
      .builderWithBuiltinLanguages().build()
    val inputFile = cmd.flags.input!!
    val language = parserFacadeFactory.computeLanguageKindWithFileName(inputFile)!!

    val treeWithParser = parserFacadeFactory.getParserFacadeListForOrNull(
      language,
    )!!.defaultParserFacade.create().parseFile(inputFile)
    val outputFile = cmd.flags.output!!

    dotifyAntlrParseTree(
      treeWithParser.tree,
      outputFile,
      object : NodeLabelProvider<ParseTree>() {
        override fun computeNodeLabel(node: ParseTree): String? {
          if (node is TerminalNode) {
            return node.getText()
          }
          val rule = node as ParserRuleContext
          return treeWithParser.parser.getRuleNames().get(rule.ruleIndex)
        }
      },
    )
  }

  class CommandOptions : AbstractCommandOptions() {

    val flags = registerFlags(RequiredFlagGroup())

    class RequiredFlagGroup : AbstractCommandLineFlagGroup(groupName = "Compulsory") {
      @Parameter(
        names = ["--input"],
        required = true,
      )
      val input: Path? = null

      @Parameter(
        names = ["--output"],
        required = true,
      )
      val output: Path? = null

      override fun validate() {
        check(input != null && Files.exists(input) && Files.isRegularFile(input))
      }
    }
  }

  companion object {

    @JvmStatic
    fun main(args: Array<String>) {
      val processor = CommandLineProcessor(
        cmdCreator = { CommandOptions() },
        programName = AntlrParseTreePdfierMain::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      AntlrParseTreePdfierMain(processor.cmd).run()
    }
  }
}

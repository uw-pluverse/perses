/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr

import com.beust.jcommander.Parameter
import com.google.common.io.Files
import com.google.protobuf.TextFormat
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.go.PnfGoParserFacade
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import java.io.File
import java.nio.charset.StandardCharsets

class GrammarHierarchyDumpMain(args: Array<String>) :
  AbstractMain<GrammarHierarchyDumpMain.Options>(args) {

  override fun createCommandOptions(): Options {
    return Options()
  }

  override fun internalRun() {
    dumpGrammarHierarchy(cmd.c!!, PnfCParserFacade().ruleHierarchy)
    dumpGrammarHierarchy(cmd.go!!, PnfGoParserFacade().ruleHierarchy)
    dumpGrammarHierarchy(cmd.scala!!, PnfScalaParserFacade().ruleHierarchy)
  }

  private fun dumpGrammarHierarchy(outputPath: String, hierarchy: GrammarHierarchy) {
    val message = TextFormat.printer().printToString(hierarchy.toProtoMessage())
    Files.asCharSink(File(outputPath), StandardCharsets.UTF_8)
      .write(message)
  }

  class Options : AbstractCommandOptions() {
    @Parameter(names = ["-c"], required = true)
    var c: String? = null

    @Parameter(names = ["-go"], required = true)
    var go: String? = null

    @Parameter(names = ["-scala"], required = true)
    var scala: String? = null

    override fun validateExtra() {
      checkNotNull(c)
      checkNotNull(go)
      checkNotNull(scala)
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      GrammarHierarchyDumpMain(args).run()
    }
  }
}

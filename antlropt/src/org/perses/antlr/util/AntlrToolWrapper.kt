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
package org.perses.antlr.util

import com.google.common.collect.ImmutableList
import org.antlr.v4.Tool
import org.antlr.v4.tool.ErrorManager
import org.perses.util.AutoDeletableFolder
import org.perses.util.FileNameContentPair
import java.nio.file.Path

class AntlrToolWrapper(
  packageName: String,
  parserFile: Path,
  lexerFile: Path?,
  outputDir: String,
) {
  val arguments = ImmutableList.builder<String>().apply {
    add("-no-listener")
    add("-no-visitor")
    add("-package")
    add(packageName)
    add("-o")
    add(outputDir)
    add(parserFile.toString())
    if (lexerFile != null) {
      add(lexerFile.toString())
    }
  }.build()

  internal val antlr = Tool(arguments.toTypedArray())

  fun call() {
    antlr.processGrammarsOnCommandLine()
    if (antlr.errMgr.numErrors != 0) {
      throw AntlrException(
        "Error in Antlr code generation.",
        antlr.errMgr,
      )
    }
  }

  class AntlrException(
    msg: String,
    val errorManager: ErrorManager,
  ) : RuntimeException(msg)

  data class AntlrAcceptanceResult(val accpeted: Boolean, val message: String?)

  data class Grammar(val name: String, val content: String)

  companion object {
    fun doesAntlrAcceptGrammar(
      parserGrammar: FileNameContentPair,
      lexerGrammar: FileNameContentPair? = null,
    ): AntlrAcceptanceResult {
      AutoDeletableFolder.createTempDir(
        AntlrToolWrapper::class.java.simpleName,
      ).use {
        val dir = it.file
        val parserFile = parserGrammar.writeToDirectory(dir)
        val lexerFile: Path? = lexerGrammar?.writeToDirectory(dir)
        val packageName = "org.perses.antlr.temp.grammartest"
        val outputDir = dir.resolve("temp_output_dir")
        val antlrTool = AntlrToolWrapper(
          packageName,
          parserFile,
          lexerFile,
          outputDir.toString(),
        )
        try {
          antlrTool.call()
          return AntlrAcceptanceResult(accpeted = true, message = null)
        } catch (e: AntlrException) {
          val log = antlrTool.antlr.logMgr.toString()
          return AntlrAcceptanceResult(accpeted = false, message = log)
        }
      }
    }
  }
}

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
package org.perses.antlr.reducer

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import java.nio.file.Files
import java.nio.file.Path

class CommandOptions : AbstractCommandOptions() {
  @JvmField
  val compulsoryFlags = registerFlags(CompulsoryFlagGroup())

  @JvmField
  val resultOutputFlags = registerFlags(ResultOutputFlagGroup())

  @JvmField
  val reductionControlFlags = registerFlags(ReductionControlFlagGroup())

  class CompulsoryFlagGroup : AbstractCommandLineFlagGroup("Compulsory") {

    @JvmField
    @Parameter(
      names = ["--parser"],
      required = true,
      description = "The file path to the parser grammar file.",
      order = FlagOrder.COMPULSORY + 100,
    )
    var parserGrammarPath: Path? = null

    @JvmField
    @Parameter(
      names = ["--start"],
      required = true,
      description = "The name of the start rule in the parser grammar",
      order = FlagOrder.COMPULSORY + 200,
    )
    var startRuleName: String = ""

    @JvmField
    @Parameter(
      names = ["--lexer"],
      required = true,
      description = "The file path to the lexer file.",
      order = FlagOrder.COMPULSORY + 300,
    )
    var lexerGrammarPath: Path? = null

    @JvmField
    @Parameter(
      names = ["--corpus"],
      required = true,
      description = "The directory containing the test programs.",
      order = FlagOrder.COMPULSORY + 400,
    )
    var corpus: Path? = null

    @JvmField
    @Parameter(
      names = ["--file-ext"],
      required = true,
      description = "The extension name (without the dot) " +
        "of the test programs, e.g., `rs` for Rust, `c` for C, `java` for Java.",
      order = FlagOrder.COMPULSORY + 500,
    )
    var fileExtName: String = ""

    override fun validate() {
      check(parserGrammarPath != null && Files.isRegularFile(parserGrammarPath)) {
        parserGrammarPath?.toAbsolutePath().toString()
      }
      check(lexerGrammarPath != null && Files.isRegularFile(lexerGrammarPath))
      check(corpus != null && Files.isDirectory(corpus))
      check(fileExtName.isNotBlank())
    }
  }

  class ResultOutputFlagGroup : AbstractCommandLineFlagGroup(groupName = "Output") {

    @Parameter(
      names = ["--output-dir"],
      description = "The output directory to save the reduced result.",
      order = FlagOrder.RESULT_OUTPUT + 1,
    )
    var outputDir: Path? = null

    override fun validate() = Unit
  }

  class ReductionControlFlagGroup : AbstractCommandLineFlagGroup(
    groupName = "Reduction Algorithm Control",
  ) {

    @Parameter(
      names = ["--threads"],
      description = "Number of reduction threads: a positive integer, or 'auto'.",
      order = FlagOrder.REDUCTION_CONTROL + 1,
    )
    private var numOfThreads = "auto"

    @Parameter(
      names = ["--enable-action-remover"],
      hidden = true,
      arity = 1,
      order = FlagOrder.REDUCTION_CONTROL + 100,
    )
    var enableActionRemover = true

    @Parameter(
      names = ["--enable-label-remover"],
      hidden = true,
      arity = 1,

      order = FlagOrder.REDUCTION_CONTROL + 200,
    )
    var enableLabelRemover = true

    @Parameter(
      names = ["--enable-argument-remover"],
      hidden = true,
      arity = 1,

      order = FlagOrder.REDUCTION_CONTROL + 300,
    )
    var enableArgumentsRemover = true

    @Parameter(
      names = ["--enable-return-remover"],
      hidden = true,
      arity = 1,

      order = FlagOrder.REDUCTION_CONTROL + 400,
    )
    var enableReturnsRemover = true

    @Parameter(
      names = ["--enable-local-remover"],
      hidden = true,
      arity = 1,

      order = FlagOrder.REDUCTION_CONTROL + 500,
    )
    var enableLocalsRemover = true

    override fun validate() {
      if ("auto" != numOfThreads) {
        check(numOfThreads.toInt() > 0) { numOfThreads }
      }
    }

    fun getNumOfThreads(): Int {
      return if ("auto" == numOfThreads) {
        Runtime.getRuntime().availableProcessors()
      } else {
        numOfThreads.toInt()
      }
    }
  }
}

private object FlagOrder {
  const val COMPULSORY = 0
  const val RESULT_OUTPUT = 1000
  const val REDUCTION_CONTROL = 2000
  const val VERBOSITY_CONTROL = 7000
  const val HELP = 8000
  const val EXPERIMENT = 9000
}

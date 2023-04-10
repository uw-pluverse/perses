/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses

import com.beust.jcommander.Parameter
import com.beust.jcommander.converters.PathConverter
import org.antlr.v4.runtime.Token
import org.perses.TokenCounterMain.CommandOptions
import org.perses.cmd.LanguageControlFlags
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil.createParserFacadeFactory
import org.perses.program.SourceFile
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.ICommandLineFlags
import java.nio.file.Files
import java.nio.file.Path

class TokenCounterMain(args: Array<String>) : AbstractMain<CommandOptions>(args) {
  override fun createCommandOptions(): CommandOptions {
    return CommandOptions()
  }

  private fun createParserFacadeFactory(): CompositeParserFacadeFactory {
    val builtin = builderWithBuiltinLanguages(
      SingleParserFacadeFactory.IDENTITY_CUSTOMIZER,
    ).build()
    val ext = createParserFacadeFactory(
      cmd.extFlags.languageJarFiles,
    )
    return CompositeParserFacadeFactory(builtin, ext)
  }

  override fun internalRun() {
    val file = cmd.flags.file
    val parserFacadeFactory: AbstractParserFacadeFactory = createParserFacadeFactory()
    val language = parserFacadeFactory.computeLanguageKindWithFileName(file!!)
    val sourceFile = SourceFile(file, language!!)
    val parserFacade = parserFacadeFactory.createParserFacade(sourceFile.dataKind)
    val tokens = parserFacade.parseIntoTokens(sourceFile.file)
    var count = 0
    for (token in tokens) {
      if (token.channel == Token.DEFAULT_CHANNEL) {
        ++count
      }
    }
    println()
    System.out.printf("The number of tokens in file '%s' is:\n", file)
    println(count)
  }

  class CommandOptions : AbstractCommandOptions() {
    val flags = registerFlags(RequiredFlags())
    val extFlags = registerFlags(LanguageControlFlags())

    class RequiredFlags : ICommandLineFlags {
      @Parameter(description = "source file", required = true, converter = PathConverter::class)
      var file: Path? = null
      override fun validate() {
        requireNotNull(file)
        require(Files.isRegularFile(file))
      }
    }
  }

  companion object {

    @JvmStatic
    fun main(args: Array<String>) {
      TokenCounterMain(args).run()
    }
  }
}

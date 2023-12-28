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
package org.perses

import com.beust.jcommander.Parameter
import com.beust.jcommander.converters.PathConverter
import org.antlr.v4.runtime.Token
import org.perses.TokenCounterMain.CommandOptions
import org.perses.cmd.LanguageControlFlagGroup
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil.createParserFacadeFactory
import org.perses.program.SourceFile
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import java.io.OutputStream
import java.io.PrintStream
import java.nio.file.Files
import java.nio.file.Path
import kotlin.properties.Delegates

class TokenCounterMain(
  args: Array<String>,
  private val printStream: PrintStream,
) : AbstractMain<CommandOptions>(args) {

  private var tokenCount by Delegates.notNull<Int>()

  override fun createCommandOptions(): CommandOptions {
    return CommandOptions()
  }

  private fun createParserFacadeFactory(): CompositeParserFacadeFactory {
    val builtin = builderWithBuiltinLanguages().build()
    val ext = createParserFacadeFactory(
      cmd.extFlags.languageJarFiles,
    )
    return CompositeParserFacadeFactory(builtin, ext)
  }

  override fun internalRun() {
    tokenCount = countToken()
    printStream.println()
    printStream.printf("The number of tokens in file '%s' is:\n", cmd.flags.file)
    printStream.println(tokenCount)
  }

  private fun countToken(): Int {
    val file = cmd.flags.file!!
    val parserFacadeFactory: AbstractParserFacadeFactory = createParserFacadeFactory()
    val language = parserFacadeFactory.computeLanguageKindWithFileName(file)
    val sourceFile = SourceFile(file, language!!)
    val parserFacade = parserFacadeFactory.createParserFacade(sourceFile.dataKind)
    val tokens = parserFacade.parseIntoTokens(sourceFile.file)
    var count = 0
    for (token in tokens) {
      if (token.channel == Token.DEFAULT_CHANNEL) {
        ++count
      }
    }
    return count
  }

  class CommandOptions : AbstractCommandOptions() {
    val flags = registerFlags(RequiredFlagGroup())
    val extFlags = registerFlags(LanguageControlFlagGroup())

    class RequiredFlagGroup : AbstractCommandLineFlagGroup(groupName = "Compulsory") {
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
    fun countTokensOfFile(file: Path): Int {
      val args = arrayOf(file.toString())
      return TokenCounterMain(args, PrintStream(OutputStream.nullOutputStream())).let {
        it.run()
        it.tokenCount
      }
    }

    @JvmStatic
    fun main(args: Array<String>) {
      TokenCounterMain(args, System.out).run()
    }
  }
}

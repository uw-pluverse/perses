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
package org.pluverse.perses

import com.google.common.collect.ImmutableList
import org.perses.AbstractMain
import org.perses.program.LanguageKind
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.OutputOnlyCommandOptions
import org.perses.util.toImmutableList
import kotlin.io.path.absolute
import kotlin.io.path.bufferedWriter

class SupportedLanguageDumpMain(
  cmd: OutputOnlyCommandOptions,
) : org.perses.util.cmd.AbstractMain<OutputOnlyCommandOptions>(cmd) {
  override fun internalRun() {
    val supportedLanguages = getActuallySupportedLanguages()
    val outputFile = cmd.flags.outputFile!!.absolute()
    Util.ensureDirExists(outputFile.parent)
    outputFile.bufferedWriter().use { writer ->
      writer.apply {
        append("### Supported Languages\n")
        append("\n")
        append("Currently, Perses supports reduction for the following programming languages:\n")
        append("\n")
        supportedLanguages.forEach {
          writer.write("+ $it")
          writer.write("\n")
        }
        append("\n")
        append("Support for other languages is coming soon.\n\n")
      }
    }
  }

  companion object {
    fun getActuallySupportedLanguages(): ImmutableList<String> =
      AbstractMain
        .createBuiltinParserFacadeFactory()
        .languageSequence()
        .filter { it.hidden.not() }
        .map { languageToString(it) }
        .sorted()
        .toImmutableList()

    private fun languageToString(language: LanguageKind): String {
      val extensions = language.extensions.joinToString(separator = ", ") { "`*.$it`" }
      return "${language.name.lowercase()}: $extensions"
    }

    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { OutputOnlyCommandOptions() },
          programName = SupportedLanguageDumpMain::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      SupportedLanguageDumpMain(processor.cmd).run()
    }
  }
}

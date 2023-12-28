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
package org.perses.grammar.adhoc

import org.perses.PersesConstants
import org.perses.PersesConstants.Companion.createCustomizedConstants
import org.perses.PersesConstants.Companion.createDefaultConstants
import org.perses.util.cmd.AbstractMain
import java.io.Closeable
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.deleteRecursively

class InstallerMain(args: Array<String>) : AbstractMain<CommandOptions>(args), Closeable {

  private var tempDir: Path? = null

  override fun createCommandOptions(): CommandOptions {
    return CommandOptions()
  }

  override fun internalRun() {
    val persesConstants: PersesConstants = if (cmd.outputFlags.output != null) {
      tempDir = Files.createTempDirectory(InstallerMain::class.java.canonicalName)
      createCustomizedConstants(tempDir!!)
    } else {
      createDefaultConstants()
    }
    AdhocGrammarInstaller(
      cmd.computeAdhocGrammarConfiguration(),
      persesConstants,
      cmd.outputFlags.output,
      enablePnfNormalization = cmd.compulsoryFlags.enablePnfNormalization,
    ).run()
  }

  override fun processHelpRequests(): HelpRequestProcessingDecision {
    if (cmd.outputFlags.printLanguageKindExample) {
      println("An example of a language kind configuration in YAML format.")
      println(LanguageAdhoc.INSTANCE.toYamlString())
      return HelpRequestProcessingDecision.EXIT
    }
    return super.processHelpRequests()
  }

  override fun close() {
    tempDir?.let {
      it.deleteRecursively()
      tempDir = null
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      InstallerMain(args).use { it.run() }
    }
  }
}

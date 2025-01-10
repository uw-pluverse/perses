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
package org.perses.antlr.reducer

import org.perses.antlr.reducer.GrammarReductionDriver.Companion.create
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor

class Main(cmd: CommandOptions) : AbstractMain<CommandOptions>(cmd) {

  public override fun internalRun() {
    create(cmd).use { driver -> driver.reduce() }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor = CommandLineProcessor(
        cmdCreator = { CommandOptions() },
        programName = Main::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      Main(processor.cmd).run()
    }
  }
}

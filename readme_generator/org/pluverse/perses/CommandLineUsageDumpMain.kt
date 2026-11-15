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

import org.perses.Main
import org.perses.PersesCommandOptions
import java.nio.file.Paths
import kotlin.io.path.writeText

object CommandLineUsageDumpMain {
  @JvmStatic
  fun main(args: Array<String>) {
    val outputFile = Paths.get(args.single())
    val usage =
      PersesCommandOptions()
        // --help is what lets the parser accept a command line without the required flags.
        .parseArguments(Main::class.qualifiedName!!, arrayOf("--help"))
        .renderMarkdownUsage()
    outputFile.writeText(usage)
  }
}

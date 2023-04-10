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
package org.perses.util.cmd

import com.beust.jcommander.JCommander
import com.beust.jcommander.Parameter

abstract class AbstractCommandOptions {

  interface CmdUsagePrinter {
    fun print()
  }

  @JvmField
  @Parameter(
    names = ["--help", "-h"],
    description = "print help message",
    help = true,
    order = CommonCmdOptionGroupOrder.HELP,
  )
  var help = false

  private val allFlags = LinkedHashSet<ICommandLineFlags>()

  @JvmField
  val verbosityFlags = registerFlags(VerbosityFlags())

  @JvmField
  val versionFlags = registerFlags(VersionFlags())

  fun validate() {
    allFlags.forEach { it.validate() }
    validateExtra()
  }

  protected open fun validateExtra() = Unit

  protected fun <T : ICommandLineFlags> registerFlags(flags: T): T {
    check(flags !in allFlags)
    allFlags.add(flags)
    return flags
  }

  fun parseArguments(programName: String, args: Array<String>): CmdUsagePrinter {
    val builder = JCommander.newBuilder().programName(programName)
    builder.addObject(this)
    builder.addObject(allFlags)
    val commander = builder.build()
    commander.parse(*args)
    return object : CmdUsagePrinter {
      override fun print() {
        commander.usage()
      }
    }
  }
}

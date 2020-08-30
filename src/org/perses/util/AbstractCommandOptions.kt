/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.util

import com.beust.jcommander.JCommander
import java.util.function.Consumer

abstract class AbstractCommandOptions {

  private val allFlags = LinkedHashSet<ICommandLineFlags>()

  fun validate() {
    allFlags.forEach { it.validate() }
  }

  protected fun <T : ICommandLineFlags> registerFlags(flags: T): T {
    check(!allFlags.contains(flags))
    allFlags.add(flags)
    return flags
  }

  fun createJCommander(mainClass: Class<*>): JCommander {
    val builder = JCommander.newBuilder().programName(mainClass.canonicalName).addObject(this)
    allFlags.forEach(Consumer { o: ICommandLineFlags? -> builder.addObject(o) })
    return builder.build()
  }
}

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
package org.perses.listener

import com.google.common.base.Splitter
import com.google.common.base.Strings
import org.perses.reduction.AbstractReductionListener
import org.perses.util.FileStreamPool

abstract class AbstractProgressMonitor(
  protected val stream: FileStreamPool.ManagedPrintStream,
) : AbstractReductionListener() {
  protected fun printBegin(section: String) {
    val length = PROGRAM_END_MARKER.length
    val paddingLength = ((length - section.length) / 2).coerceAtLeast(1)
    val padding = Strings.padEnd("", paddingLength, '=')
    val builder = StringBuilder()
    builder.append(padding)
    builder.append(section)
    while (builder.length < length) {
      builder.append('=')
    }
    stream.println(builder.toString())
    stream.println()
  }

  protected fun printEnd() {
    stream.println(PROGRAM_END_MARKER)
    stream.println("\n")
  }

  protected fun printCode(code: String) {
    Splitter.on('\n').omitEmptyStrings().split(code).forEach {
      if (it.isNotBlank()) {
        stream.println("    $it")
      }
    }
  }

  override fun close() {
    stream.close()
  }

  companion object {
    protected val PROGRAM_END_MARKER: String = Strings.padEnd("", 60, '-')
  }
}

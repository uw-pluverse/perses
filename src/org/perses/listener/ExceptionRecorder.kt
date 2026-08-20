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

import org.perses.reduction.AbstractReductionListener
import java.util.concurrent.ConcurrentLinkedQueue

class ExceptionRecorder : AbstractReductionListener() {
  private val exceptions = ConcurrentLinkedQueue<Exception>()

  override fun onCriticalException(exception: Exception) {
    exceptions.add(exception)
  }

  override fun close() {
    val array = exceptions.toTypedArray()
    if (array.isEmpty()) {
      return
    }
    System.err.println("The following exceptions occurred during the reduction process")
    array.withIndex().forEach {
      System.err.print("${it.index}. ")
      it.value.printStackTrace(System.err)
      System.err.println()
    }
  }
}

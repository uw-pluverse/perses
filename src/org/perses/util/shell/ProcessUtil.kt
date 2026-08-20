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
package org.perses.util.shell

object ProcessUtil {
  /**
   * Forcibly destroys the process and all its descendants.
   */
  fun killProcessAndDescendants(process: Process) {
    if (process.isAlive) {
      /*
       * If this process cannot be destroyed, then forcibly destroy it.
       *
       * Do not try to close the streams of the process, because these streams
       * are used and locked by the StreamPumper.
       *
       * Also, note that BufferedInputStream.read() is blocking and is not interruptable.
       */
      process.descendants().use { stream ->
        stream.forEach { descendant ->
          if (descendant.isAlive) {
            descendant.destroy() // Try to shut down the process cleanly first.
            if (descendant.isAlive) {
              descendant.destroyForcibly()
            }
          }
        }
      }
      process.destroyForcibly()
    }
  }
}

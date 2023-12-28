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
package org.perses.grammar.rust

import com.google.common.base.Preconditions
import org.perses.TestUtility.rustTestFiles
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import java.util.concurrent.ConcurrentLinkedQueue
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit

object RustParserFailListGenerator {
  @JvmStatic
  fun main(args: Array<String>) {
    val executorService = Executors.newFixedThreadPool(40)
    val failList = ConcurrentLinkedQueue<String>()
    try {
      val facade = OrigRustParserFacade()
      for (f in rustTestFiles) {
        executorService.submit {
          try {
            facade.parseFile(f)
          } catch (e: Throwable) {
            failList.add(f.toString())
          }
        }
      }
    } finally {
      executorService.shutdown()
      Preconditions.checkState(
        executorService.awaitTermination(60, TimeUnit.MINUTES),
        "Time out!!!",
      )
    }
    val result = ArrayList(failList)
    result.sort()
    Files.newBufferedWriter(Paths.get(args[0]), StandardCharsets.UTF_8).use { writer ->
      for (file in result) {
        writer.append(file).append('\n')
      }
    }
  }
}

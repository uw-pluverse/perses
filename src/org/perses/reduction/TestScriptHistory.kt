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
package org.perses.reduction

import com.google.common.hash.HashCode
import org.apache.commons.csv.CSVFormat
import org.perses.util.Util.lazyAssert
import org.perses.util.shell.ExitCode
import java.nio.file.Path
import java.util.concurrent.ConcurrentHashMap
import kotlin.io.path.bufferedReader
import kotlin.io.path.bufferedWriter

class TestScriptHistory {

  private val history = ConcurrentHashMap<HashCode, Result>()

  fun getExecutionHistoryFor(key: HashCode): Result? = history[key]

  fun cacheExecutionHistory(key: HashCode, result: Result) {
    lazyAssert { !history.containsKey(key) }
    history[key] = result
  }

  fun asReadOnlyMap(): Map<HashCode, Result> = history

  fun saveToCSV(file: Path) {
    file.bufferedWriter().use { writer ->
      CSVFormat.DEFAULT.print(writer).apply {
        printRecord(NAME_COLUMN_HASH_CODE, NAME_COLUMN_EXIT_CODE, NAME_COLUMN_ELLAPSED_MILLIES)
        history.entries
          .asSequence()
          .map { it.key.toString() to it.value }
          .sortedBy { it.first }
          .forEach { entry ->
            printRecord(entry.first, entry.second.exitCode.intValue, entry.second.ellapsedMillies)
          }
      }
    }
  }
  data class Result(val exitCode: ExitCode, val ellapsedMillies: Int)
  companion object {

    const val NAME_COLUMN_HASH_CODE = "HashCode"
    const val NAME_COLUMN_EXIT_CODE = "ExitCode"
    const val NAME_COLUMN_ELLAPSED_MILLIES = "EllapsedMillies"

    fun loadFromCSV(file: Path): TestScriptHistory {
      val history = TestScriptHistory()
      file.bufferedReader().use { reader ->
        CSVFormat.Builder.create(CSVFormat.DEFAULT).apply {
          setIgnoreEmptyLines(true)
          setIgnoreSurroundingSpaces(true)
        }.build().parse(reader)
          .drop(1) // Drop the header
          .fold(history.history) { acc, record ->
            val hashCode = record[0]
            val result = Result(ExitCode(record[1].toInt()), record[2].toInt())
            acc.apply {
              put(HashCode.fromString(hashCode), result)
            }
          }
      }
      return history
    }
  }
}

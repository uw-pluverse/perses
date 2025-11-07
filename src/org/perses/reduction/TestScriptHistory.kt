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
package org.perses.reduction

import com.google.common.hash.HashCode
import org.apache.commons.csv.CSVFormat
import org.perses.util.Util.lazyAssert
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Path
import java.util.concurrent.ConcurrentHashMap
import kotlin.io.path.bufferedReader
import kotlin.io.path.bufferedWriter

class TestScriptHistory(
  private val shaAlgorithm: EnumShaAlgorithm,
) {
  private val history = ConcurrentHashMap<HashCode, PropertyTestResult>()

  fun getExecutionHistoryFor(key: HashCode): PropertyTestResult? = history[key]

  fun cacheExecutionHistory(
    key: HashCode,
    result: PropertyTestResult,
  ) {
    lazyAssert { !history.containsKey(key) }
    history[key] = result
  }

  fun asReadOnlyMap(): Map<HashCode, PropertyTestResult> = history

  fun saveToCSV(file: Path) {
    file.bufferedWriter().use { writer ->
      CSVFormat.DEFAULT.print(writer).apply {
        printRecord(shaAlgorithm.name, NAME_COLUMN_EXIT_CODE, NAME_COLUMN_ELLAPSED_MILLIES)
        history.entries
          .asSequence()
          .map { it.key.toString() to it.value }
          .sortedBy { it.first }
          .forEach { entry ->
            printRecord(entry.first, entry.second.exitCode.intValue, entry.second.elapsedMillis)
          }
      }
    }
  }

  companion object {
    const val NAME_COLUMN_EXIT_CODE = "ExitCode"
    const val NAME_COLUMN_ELLAPSED_MILLIES = "EllapsedMillies"

    fun loadFromCSV(
      shaAlgorithm: EnumShaAlgorithm,
      file: Path,
    ): TestScriptHistory {
      val history = TestScriptHistory(shaAlgorithm)
      file.bufferedReader().use { reader ->
        val csvFormat =
          CSVFormat.Builder
            .create(CSVFormat.DEFAULT)
            .setHeader()
            .setSkipHeaderRecord(true)
            .setIgnoreEmptyLines(true)
            .setIgnoreSurroundingSpaces(true)
            .build()

        csvFormat.parse(reader).use { csvParser ->
          val actualHeader = csvParser.headerNames
          if (actualHeader == null || actualHeader.isEmpty()) {
            return history
          }
          val hashAlgorithmName = actualHeader[0]
          check(hashAlgorithmName == shaAlgorithm.name) {
            """Inconsistent hash algorithm. 
            |The one in the csv file $file is $hashAlgorithmName
            |The expected one is ${shaAlgorithm.name}
            """.trimMargin()
          }
          for (record in csvParser) {
            val hashCode = record[0]
            val result =
              PropertyTestResult.of(
                exitCode = record[1].toInt(),
                elapsedMillis = record[2].toInt(),
              )
            history.history.put(HashCode.fromString(hashCode), result)
          }
        }
      }
      return history
    }
  }
}

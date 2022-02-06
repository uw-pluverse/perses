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
package org.perses.reduction.cache

import objectexplorer.MemoryMeasurer
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

class QueryCacheMemoryProfiler(file: Path) : AbstractQueryCacheProfiler() {

  private val writer = Files.newBufferedWriter(file, StandardCharsets.UTF_8)

  override fun close() {
    writer.close()
  }

  override fun afterAddProgram(cache: AbstractQueryCache) {
    writeNumOfBytesToFileSubjectToTimeInterval(cache)
  }

  override fun afterCacheEviction(cache: AbstractQueryCache) {
    writeNumOfBytesToFileSubjectToTimeInterval(cache)
  }

  override fun onHeartBeat(cache: AbstractQueryCache) {
    writeNumOfBytesToFile(System.currentTimeMillis(), cache)
  }

  private var prevTime = 0L

  private fun writeNumOfBytesToFileSubjectToTimeInterval(cache: AbstractQueryCache) {
    val now = System.currentTimeMillis()
    if (prevTime + INTERVAL > now) {
      return
    }
    writeNumOfBytesToFile(now, cache)
    prevTime = now
  }

  private fun writeNumOfBytesToFile(now: Long, cache: AbstractQueryCache) {
    writer
      .append(now.toString())
      .append(" ")
      .append(computeMemoryInBytes(cache).toString())
      .append('\n')
  }

  companion object {

    private val INTERVAL = readTimeIntervalFromEnv()

    private fun readTimeIntervalFromEnv(): Long {
      val value = System.getenv("PERSES_CACHE_MEMORY_PROFILING_TIME_INTERVAL")
      val defaultTimeInterval = 5 * 60 * 1000 // 5 minutes.
      return value?.trim()?.toLong() ?: defaultTimeInterval.toLong()
    }

    fun computeMemoryInBytes(cache: Any): Long {
      return MemoryMeasurer.measureBytes(cache) {
        check(it != null)
        val className = it.javaClass.name
        check(className != null) {
          it.javaClass
        }
        !className.startsWith("org.perses.program.")
      }
    }
  }
}

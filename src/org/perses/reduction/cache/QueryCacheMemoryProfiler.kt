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
package org.perses.reduction.cache

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import objectexplorer.MemoryMeasurer
import org.perses.reduction.PropertyTestResult
import org.perses.util.FileStreamPool

class QueryCacheMemoryProfiler(
  writer: FileStreamPool.ManagedPrintStream,
) : AbstractQueryCacheProfiler(writer) {

  override fun afterCacheProgramAndResult(cache: AbstractQueryCache, nanoDuration: Long) {
    writeNumOfBytesToFileSubjectToTimeInterval(cache)
  }

  override fun beforeCacheEviction(cache: AbstractQueryCache) {
    val currentTimeMillis = System.currentTimeMillis()
    writeNumOfBytesToFile(currentTimeMillis, cache)
    prevTime = currentTimeMillis
  }

  override fun afterCacheEviction(cache: AbstractQueryCache, nanoDuration: Long) {
    val currentTimeMillis = System.currentTimeMillis()
    writeNumOfBytesToFile(currentTimeMillis, cache)
    prevTime = currentTimeMillis
  }

  override fun onHeartBeat(cache: AbstractQueryCache) {
    writeNumOfBytesToFile(System.currentTimeMillis(), cache)
  }

  private var prevTime = 0L

  private fun writeNumOfBytesToFileSubjectToTimeInterval(cache: AbstractQueryCache) {
    val currentTimeMillis = System.currentTimeMillis()
    if (prevTime + INTERVAL > currentTimeMillis) {
      return
    }
    writeNumOfBytesToFile(currentTimeMillis, cache)
    prevTime = currentTimeMillis
  }

  private fun writeNumOfBytesToFile(currentTimeMillis: Long, cache: AbstractQueryCache) {
    val profilingResults = computeMemoryInBytes(cache)
    writer!!
      .append(currentTimeMillis.toString())
      .append(" ")
      .append(profilingResults.bytes.toString())
      .append('\n')
    if (logger.atConfig().isEnabled) {
      profilingResults.includedClasses.sortedBy { it.canonicalName }.forEach {
        logger.atConfig().log("Included for profiling: $it")
      }
      profilingResults.excludedClasses.sortedBy { it.canonicalName }.forEach {
        logger.atConfig().log("Excluded from profiling: $it")
      }
    }
  }

  companion object {

    private val INTERVAL = readTimeIntervalFromEnv()
    private val logger = FluentLogger.forEnclosingClass()

    private val CLASS_EXCLUSION_FILTER: ImmutableList<(Any) -> Boolean> = ImmutableList.of(
      { klass -> klass is AbstractQueryCacheProfiler },
      { klass -> klass is QueryCacheConfiguration },
      { klass -> klass is PropertyTestResult },
      { klass -> klass is AbstractTokenizedProgramEncoder<*> },
    )

    private val CLASS_NAME_EXCLUSION_FILTER: ImmutableList<(String) -> Boolean> =
      ImmutableList.of { className ->
        className.startsWith(
          "org.perses.program.",
        )
      }

    private fun readTimeIntervalFromEnv(): Long {
      val value = System.getenv("PERSES_CACHE_MEMORY_PROFILING_TIME_INTERVAL")
      val defaultTimeInterval = 5 * 60 * 1000 // 5 minutes.
      return value?.trim()?.toLong() ?: defaultTimeInterval.toLong()
    }

    data class ProfilingResults(
      val bytes: Long,
      val includedClasses: Set<Class<*>>,
      val excludedClasses: Set<Class<*>>,
    )

    fun computeMemoryInBytes(cache: Any): ProfilingResults {
      val includedClasses = HashSet<Class<*>>()
      val excludedClasses = HashSet<Class<*>>()
      return ProfilingResults(
        bytes = MemoryMeasurer.measureBytes(cache) {
          whetherToProfileMemory(
            includedClasses,
            excludedClasses,
            it,
          )
        },
        includedClasses = includedClasses,
        excludedClasses = excludedClasses,
      )
    }

    private fun whetherToProfileMemory(
      includedClasses: HashSet<Class<*>>,
      excludedClasses: HashSet<Class<*>>,
      obj: Any,
    ): Boolean {
      val javaClass = obj.javaClass
      if (CLASS_EXCLUSION_FILTER.any { it(obj) }) {
        excludedClasses.add(javaClass)
        return false
      }
      val className: String = javaClass.name
      if (CLASS_NAME_EXCLUSION_FILTER.any { it(className) }) {
        excludedClasses.add(javaClass)
        return false
      }
      includedClasses.add(javaClass)
      return true
    }
  }
}

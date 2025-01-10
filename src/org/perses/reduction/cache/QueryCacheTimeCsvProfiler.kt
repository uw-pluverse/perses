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
import org.perses.program.PersesTokenFactory
import org.perses.util.FileStreamPool

class QueryCacheTimeCsvProfiler(
  writer: FileStreamPool.ManagedPrintStream,
) : AbstractQueryCacheProfiler(writer) {

  private val createEncoderNanoTime = mutableListOf<Long>()
  private val decodeProgramNanoTime = mutableListOf<Long>()
  private val getCachedResultNanoTime = mutableListOf<Long>()
  private val cacheEvictionNanoTime = mutableListOf<Long>()
  private val cacheProgramAndResultNanoTime = mutableListOf<Long>()
  private val heavyWeightCacheRefreshing = mutableListOf<Long>()

  override fun afterGetCachedResult(cache: AbstractQueryCache, nanoDuration: Long) {
    getCachedResultNanoTime.add(nanoDuration)
  }

  override fun afterCacheProgramAndResult(cache: AbstractQueryCache, nanoDuration: Long) {
    cacheProgramAndResultNanoTime.add(nanoDuration)
  }

  override fun afterCacheEviction(cache: AbstractQueryCache, nanoDuration: Long) {
    cacheEvictionNanoTime.add(nanoDuration)
  }

  override fun afterHeavyweightCacheRefreshing(
    oldBestProgram: ImmutableList<PersesTokenFactory.PersesToken>,
    newBestProgram: ImmutableList<PersesTokenFactory.PersesToken>,
    numOfEntriesInCacheBefore: Int,
    numOfEntriesInCacheAfter: Int,
    nanoDuration: Long,
  ) {
    heavyWeightCacheRefreshing.add(nanoDuration)
  }

  override fun onCreatingEncoder(
    tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
    nanoDuration: Long,
  ) {
    createEncoderNanoTime.add(nanoDuration)
  }

  override fun onDecodingProgram(
    tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
    encoding: RccProgramEncoding,
    nanoDuration: Long,
  ) {
    decodeProgramNanoTime.add(nanoDuration)
  }

  override fun close() {
    val fields = listOf(
      ::createEncoderNanoTime,
      ::decodeProgramNanoTime,
      ::getCachedResultNanoTime,
      ::cacheEvictionNanoTime,
      ::cacheProgramAndResultNanoTime,
      ::heavyWeightCacheRefreshing,
    )
    var totalNano: Long = 0
    fields.forEach { field ->
      val value = field.get()
      val sum = value.sum()
      totalNano += sum
      writer!!.printf("%s[#=%,d]=%,d\n", field.name, value.size, sum)
    }
    writer!!.printf("total=%,d\n", totalNano)
    super.close()
  }
}

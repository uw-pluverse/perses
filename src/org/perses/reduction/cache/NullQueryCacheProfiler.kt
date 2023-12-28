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
package org.perses.reduction.cache

import com.google.common.collect.ImmutableList
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram

class NullQueryCacheProfiler : AbstractQueryCacheProfiler() {

  override fun close() {}

  override fun onEncodingProgram(
    tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
    program: TokenizedProgram,
    startTime: Long,
    endTime: Long,
  ) {
  }

  override fun onDecodingProgram(
    tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
    encoding: CompactProgramEncoding,
    startTime: Long,
    endTime: Long,
  ) {
  }

  override fun onCreatingEncoder(
    tokensInOrigin: ImmutableList<PersesTokenFactory.PersesToken>,
    startTime: Long,
    endTime: Long,
  ) {
  }

  override fun onHeavyweightCacheRefreshing(
    oldBestProgram: ImmutableList<PersesTokenFactory.PersesToken>,
    newBestProgram: ImmutableList<PersesTokenFactory.PersesToken>,
    numOfEntriesInCacheBefore: Int,
    numOfEntriesInCacheAfter: Int,
    startTime: Long,
    endTime: Long,
  ) {
  }
}

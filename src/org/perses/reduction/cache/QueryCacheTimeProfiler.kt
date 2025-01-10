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
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.FileStreamPool
import java.lang.AutoCloseable

class QueryCacheTimeProfiler(
  writer: FileStreamPool.ManagedPrintStream,
) : AbstractQueryCacheProfiler(writer), AutoCloseable {

  override fun onCreatingEncoder(
    tokensInOrigin: ImmutableList<PersesToken>,
    nanoDuration: Long,
  ) {
    writer!!
      .append("create_encoder")
      .append('\t')
      .append("origin_token_count=")
      .append(tokensInOrigin.size.toString())
      .append('\t')
      .append("duration=")
      .append(nanoDuration.toString())
      .append('\n')
      .flush()
  }

  override fun onDecodingProgram(
    tokensInOrigin: ImmutableList<PersesToken>,
    encoding: RccProgramEncoding,
    nanoDuration: Long,
  ) {
    writer!!
      .append("decode")
      .append('\t')
      .append("origin_token_count=")
      .append(tokensInOrigin.size.toString())
      .append('\t')
      .append("encoding_token_count=")
      .append(encoding.tokenCount.toString())
      .append('\t')
      .append("encoding_length=")
      .append(encoding.encodingSize().toString())
      .append('\t')
      .append("duration=")
      .append(nanoDuration.toString())
      .append('\n')
      .flush()
  }

  override fun afterEncodeProgram(
    tokensInOrigin: ImmutableList<PersesToken>,
    program: TokenizedProgram,
    nanoDuration: Long,
  ) {
    writer!!
      .append("encode")
      .append('\t')
      .append("origin_token_count=")
      .append(tokensInOrigin.size.toString())
      .append('\t')
      .append("token_count=")
      .append(program.tokenCount().toString())
      .append('\t')
      .append("duration=")
      .append(nanoDuration.toString())
      .append('\n')
      .flush()
  }

  override fun afterHeavyweightCacheRefreshing(
    oldBestProgram: ImmutableList<PersesToken>,
    newBestProgram: ImmutableList<PersesToken>,
    numOfEntriesInCacheBefore: Int,
    numOfEntriesInCacheAfter: Int,
    nanoDuration: Long,
  ) {
    writer!!
      .append("refresh_cache")
      .append('\t')
      .append("old_origin_token_count=")
      .append(oldBestProgram.size.toString())
      .append('\t')
      .append("new_origin_token_count=")
      .append(newBestProgram.size.toString())
      .append('\t')
      .append("entries_before=")
      .append(numOfEntriesInCacheBefore.toString())
      .append('\t')
      .append("entries_after=")
      .append(numOfEntriesInCacheAfter.toString())
      .append('\t')
      .append("duration=")
      .append(nanoDuration.toString())
      .append('\n')
      .flush()
  }
}

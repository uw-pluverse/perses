/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction;

import com.google.common.collect.ImmutableList;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgram;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

public abstract class AbstractTestScriptExecutionCacheProfiler implements AutoCloseable {

  public static long now() {
    return System.nanoTime();
  }

  public static final AbstractTestScriptExecutionCacheProfiler NULL_PROFILER =
      new AbstractTestScriptExecutionCacheProfiler() {
        @Override
        public void close() {}

        @Override
        public void onEncodingProgram(
            ImmutableList<PersesToken> tokensInOrigin,
            TokenizedProgram program,
            long startTime,
            long endTime) {}

        @Override
        public void onDecodingProgram(
            ImmutableList<PersesToken> tokensInOrigin,
            TokenizedProgramEncoder.CompactProgramEncoding encoding,
            long startTime,
            long endTime) {}

        @Override
        public void onCreatingEncoder(
            ImmutableList<PersesToken> tokensInOrigin, long startTime, long endTime) {}

        @Override
        public void onHeavyweightCacheRefreshing(
            ImmutableList<PersesToken> oldBestProgram,
            ImmutableList<PersesToken> newBestProgram,
            int numOfEntriesInCacheBefore,
            int numOfEntriesInCacheAfter,
            long startTime,
            long endTime) {}
      };

  public abstract void onEncodingProgram(
      ImmutableList<PersesToken> tokensInOrigin,
      TokenizedProgram program,
      long startTime,
      long endTime);

  public abstract void onDecodingProgram(
      ImmutableList<PersesToken> tokensInOrigin,
      TokenizedProgramEncoder.CompactProgramEncoding encoding,
      long startTime,
      long endTime);

  public abstract void onCreatingEncoder(
      ImmutableList<PersesToken> tokensInOrigin, long startTime, long endTime);

  public abstract void onHeavyweightCacheRefreshing(
      ImmutableList<PersesToken> oldBestProgram,
      ImmutableList<PersesToken> newBestProgram,
      int numOfEntriesInCacheBefore,
      int numOfEntriesInCacheAfter,
      long startTime,
      long endTime);

  public static final class TestScriptExecutionCacheProfiler
      extends AbstractTestScriptExecutionCacheProfiler implements AutoCloseable {

    private BufferedWriter writer;

    public TestScriptExecutionCacheProfiler(File file) throws IOException {
      writer = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8);
      Runtime.getRuntime().addShutdownHook(new Thread(() -> close()));
    }

    @Override
    public void close() {
      try {
        BufferedWriter local = writer;
        writer = null;
        if (local != null) {
          local.close();
        }
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    @Override
    public void onCreatingEncoder(
        ImmutableList<PersesToken> tokensInOrigin, long startTime, long endTime) {
      try {
        writer
            .append("create_encoder")
            .append('\t')
            .append("origin_token_count=")
            .append(String.valueOf(tokensInOrigin.size()))
            .append('\t')
            .append("duration=")
            .append(String.valueOf(endTime - startTime))
            .append('\n')
            .flush();
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    @Override
    public void onDecodingProgram(
        ImmutableList<PersesToken> tokensInOrigin,
        TokenizedProgramEncoder.CompactProgramEncoding encoding,
        long startTime,
        long endTime) {
      try {
        writer
            .append("decode")
            .append('\t')
            .append("origin_token_count=")
            .append(String.valueOf(tokensInOrigin.size()))
            .append('\t')
            .append("encoding_token_count=")
            .append(String.valueOf(encoding.getTokenCount()))
            .append('\t')
            .append("encoding_length=")
            .append(String.valueOf(encoding.encodingSize()))
            .append('\t')
            .append("duration=")
            .append(String.valueOf(endTime - startTime))
            .append('\n')
            .flush();
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    @Override
    public void onEncodingProgram(
        ImmutableList<PersesToken> tokensInOrigin,
        TokenizedProgram program,
        long startTime,
        long endTime) {
      try {
        writer
            .append("encode")
            .append('\t')
            .append("origin_token_count=")
            .append(String.valueOf(tokensInOrigin.size()))
            .append('\t')
            .append("token_count=")
            .append(String.valueOf(program.tokenCount()))
            .append('\t')
            .append("duration=")
            .append(String.valueOf(endTime - startTime))
            .append('\n')
            .flush();
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    @Override
    public void onHeavyweightCacheRefreshing(
        ImmutableList<PersesToken> oldBestProgram,
        ImmutableList<PersesToken> newBestProgram,
        int numOfEntriesInCacheBefore,
        int numOfEntriesInCacheAfter,
        long startTime,
        long endTime) {
      try {
        writer
            .append("refresh_cache")
            .append('\t')
            .append("old_origin_token_count=")
            .append(String.valueOf(oldBestProgram.size()))
            .append('\t')
            .append("new_origin_token_count=")
            .append(String.valueOf(newBestProgram.size()))
            .append('\t')
            .append("entries_before=")
            .append(String.valueOf(numOfEntriesInCacheBefore))
            .append('\t')
            .append("entries_after=")
            .append(String.valueOf(numOfEntriesInCacheAfter))
            .append('\t')
            .append("duration=")
            .append(String.valueOf(endTime - startTime))
            .append('\n')
            .flush();
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
  }
}

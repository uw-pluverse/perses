package org.perses.reduction;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import it.unimi.dsi.fastutil.ints.IntArrayList;
import me.lemire.integercompression.differential.IntegratedIntCompressor;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgram;

import java.util.Arrays;
import java.util.Optional;
import java.util.WeakHashMap;

import static org.perses.reduction.AbstractTestScriptExecutionCacheProfiler.now;

public final class TokenizedProgramEncoder {

  private static final IntegratedIntCompressor COMPRESSOR = new IntegratedIntCompressor();

  private final ImmutableList<PersesToken> tokensInOrigin;
  private final ImmutableList<AbstractForwardAdjacencyMap> forwardLexeme2IndexMap;
  private final WeakHashMap<TokenizedProgram, CompactProgramEncoding> encodingCache =
      new WeakHashMap<>();
  private final AbstractTestScriptExecutionCacheProfiler profiler;

  public TokenizedProgramEncoder(
      ImmutableList<PersesToken> tokensInOrigin,
      AbstractTestScriptExecutionCacheProfiler profiler) {
    final long startTime = now();
    this.tokensInOrigin = tokensInOrigin;
    this.profiler = profiler;
    forwardLexeme2IndexMap = buildLexemeId2Indices(tokensInOrigin);
    final long endTime = now();
    profiler.onCreatingEncoder(tokensInOrigin, startTime, endTime);
  }

  public Optional<CompactProgramEncoding> encode(TokenizedProgram program) {
    CompactProgramEncoding encoding = encodingCache.get(program);
    if (encoding == null) {
      final long startTime = now();
      final Optional<int[]> intervalArray = encodeUncompressed(program);
      if (!intervalArray.isPresent()) {
        return Optional.empty();
      }
      int[] interval = intervalArray.get();
      assert interval.length % 2 == 0;
      encoding = new CompactProgramEncoding(COMPRESSOR.compress(interval), program.tokenCount());
      encodingCache.put(program, encoding);
      final long endTime = now();
      profiler.onEncodingProgram(tokensInOrigin, program, startTime, endTime);
    }
    assert encodingCache.containsKey(program);
    assert encoding != null;
    return Optional.of(encoding);
  }

  public int searchForLexemeId(final int startIndex, PersesToken persesToken) {
    final int targetLexemeId = persesToken.getPersesLexemeId();
    final int size = tokensInOrigin.size();
    if (startIndex >= size) {
      return startIndex;
    }
    if (tokensInOrigin.get(startIndex).getPersesLexemeId() == targetLexemeId) {
      return startIndex;
    }
    return forwardLexeme2IndexMap.get(startIndex).getNearestForwardIndex(targetLexemeId);
  }

  public ImmutableList<PersesToken> getTokensInOrigin() {
    return tokensInOrigin;
  }

  @VisibleForTesting
  Optional<int[]> encodeUncompressed(TokenizedProgram program) {
    final ImmutableList<PersesToken> tokens = program.getTokens();
    final int size = tokens.size();
    final IntArrayList intervals = new IntArrayList(size);
    int origIndex = 0;
    final int origTokenCount = tokensInOrigin.size();
    for (int i = 0; i < size; ) {
      final PersesToken currentToken = tokens.get(i);
      // Search for start of the internal.
      origIndex = searchForLexemeId(origIndex, currentToken);
      if (origIndex == AbstractForwardAdjacencyMap.NOT_FOUND) {
        return Optional.empty();
      }
      assert currentToken.getPersesLexemeId() == tokensInOrigin.get(origIndex).getPersesLexemeId();
      intervals.add(origIndex);
      // Search for the end of the interval.
      do {
        ++i;
        ++origIndex;
      } while (i < size
          && origIndex < origTokenCount
          && tokens.get(i).getPersesLexemeId()
              == tokensInOrigin.get(origIndex).getPersesLexemeId());
      if (origIndex == origTokenCount && i < size) {
        return Optional.empty();
      }
      intervals.add(origIndex);
    }
    return Optional.of(intervals.toArray(new int[intervals.size()]));
  }

  @VisibleForTesting
  public final TokenizedProgram decode(CompactProgramEncoding encoding) {
    final long startTime = now();
    final int[] uncompressedIntervals = COMPRESSOR.uncompress(encoding.copyCompressedIds());
    TokenizedProgram result = restoreProgram(uncompressedIntervals, encoding.tokenCount);
    final long endTime = now();
    profiler.onDecodingProgram(tokensInOrigin, encoding, startTime, endTime);
    return result;
  }

  @VisibleForTesting
  final TokenizedProgram restoreProgram(int[] uncompressedIntervals, int expectedTokenCount) {
    ImmutableList.Builder<PersesToken> builder =
        expectedTokenCount <= 0
            ? ImmutableList.builder()
            : ImmutableList.builderWithExpectedSize(expectedTokenCount);
    Preconditions.checkState(uncompressedIntervals.length % 2 == 0);
    for (int i = 0, length = uncompressedIntervals.length; i < length; ++i) {
      final int start = uncompressedIntervals[i];
      final int end = uncompressedIntervals[++i];
      builder.addAll(tokensInOrigin.subList(start, end));
    }
    return new TokenizedProgram(builder.build());
  }

  private ImmutableList<AbstractForwardAdjacencyMap> buildLexemeId2Indices(
      ImmutableList<PersesToken> tokensInOrigin) {
    final int size = tokensInOrigin.size();
    if (size == 0) {
      return ImmutableList.of();
    }
    AbstractForwardAdjacencyMap[] result = new AbstractForwardAdjacencyMap[size];
    // The flast forward link is always empty.
    result[size - 1] = AbstractForwardAdjacencyMap.EMPTY;
    // Skip the last token, as its forward link is always empty.
    for (int i = size - 2; i >= 0; --i) {
      final AbstractForwardAdjacencyMap next = result[i + 1];
      assert result[i] == null;
      assert next != null;

      final PersesToken nextToken = tokensInOrigin.get(i + 1);
      final AbstractForwardAdjacencyMap current =
          AbstractForwardAdjacencyMap.create(next, nextToken.getPersesLexemeId(), i + 1);
      result[i] = current;
    }
    return ImmutableList.copyOf(result);
  }

  public final class CompactProgramEncoding {

    private final int[] encoding;
    private final int hashcode;
    private final int tokenCount;

    private CompactProgramEncoding(int[] encoding, int tokenCount) {
      this.encoding = encoding;
      this.hashcode = Arrays.hashCode(encoding);
      this.tokenCount = tokenCount;
    }

    @Override
    public int hashCode() {
      return hashcode;
    }

    public int encodingSize() {
      return encoding.length;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;
      CompactProgramEncoding that = (CompactProgramEncoding) o;
      return hashcode == that.hashcode
          && tokenCount == that.tokenCount
          && Arrays.equals(encoding, that.encoding);
    }

    public int getTokenCount() {
      return tokenCount;
    }

    public int[] copyCompressedIds() {
      return Arrays.copyOf(encoding, encoding.length);
    }

    public int memoryFootprintInBytes() {
      return encoding.length * 4 + 2;
    }
  }
}

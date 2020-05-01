/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.program;

import com.google.common.base.MoreObjects;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.UnmodifiableIterator;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenFactory;
import org.antlr.v4.runtime.TokenSource;
import org.checkerframework.checker.nullness.qual.MonotonicNonNull;
import org.perses.util.FastStringBuilder;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

/** A program represented by a list of tokens. */
public final class TokenizedProgram {

  private final ImmutableList<PersesToken> tokens;

  public TokenizedProgram(ImmutableList<PersesToken> tokens) {
    this.tokens = tokens;
  }

  public ImmutableList<PersesToken> getTokens() {
    return tokens;
  }

  @MonotonicNonNull FastStringBuilder codeStringInLines;

  public synchronized void writeSourceCodeInLines(BufferedWriter writer) throws IOException {
    if (codeStringInLines == null) {
      codeStringInLines = computeCodeStringInLines();
    }
    codeStringInLines.writeToWriter(writer);
  }

  FastStringBuilder computeCodeStringInLines() {
    final int tokenCount = tokenCount();
    final FastStringBuilder result = new FastStringBuilder(tokenCount * 5);

    for (int i = 0; i < tokenCount; ++i) {
      final PersesToken token = tokens.get(i);
      result.append(token.getText()).append('\n');
    }
    return result;
  }

  @MonotonicNonNull private String codeStringInOriginalFormatWithBlankLines;

  public synchronized String getSourceCodeInOrigFormat() {
    if (codeStringInOriginalFormatWithBlankLines != null) {
      return codeStringInOriginalFormatWithBlankLines;
    }
    final int tokenCount = tokenCount();
    final StringBuilder builder = new StringBuilder(tokenCount * 5);
    int lineNoCurrent = 1;
    int positionInLineCurrent = 0;
    for (int i = 0; i < tokenCount; ++i) {
      final PersesToken token = tokens.get(i);
      final int lineNo = token.getLine();
      final int tokenPositionInLine = token.getCharPositionInLine();
      final String text = token.getText();
      assert lineNo > 0;
      assert tokenPositionInLine >= 0;
      while (lineNoCurrent < lineNo) {
        ++lineNoCurrent;
        builder.append('\n');
        positionInLineCurrent = 0;
      }
      while (positionInLineCurrent < tokenPositionInLine) {
        ++positionInLineCurrent;
        builder.append(' ');
      }
      builder.append(text);
      positionInLineCurrent += text.length();
    }
    builder.append('\n');
    codeStringInOriginalFormatWithBlankLines = builder.toString();
    return codeStringInOriginalFormatWithBlankLines;
  }

  public final int tokenCount() {
    return tokens.size();
  }

  @Override
  public final String toString() {
    return MoreObjects.toStringHelper(this).add("tokens", tokens).toString();
  }

  public final void writeToFile(File file, boolean keepOriginalFormat) throws IOException {
    try (BufferedWriter writer = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8)) {
      if (keepOriginalFormat) {
        writer.write(getSourceCodeInOrigFormat());
      } else {
        writeSourceCodeInLines(writer);
      }
    }
  }

  public TokenSource createTokenSource() {
    return new TokenSource() {
      private UnmodifiableIterator<PersesToken> iterator = tokens.iterator();

      @Override
      public Token nextToken() {
        if (iterator.hasNext()) {
          return iterator.next();
        } else {
          return EOF_TOKEN;
        }
      }

      @Override
      public int getLine() {
        throw new UnsupportedOperationException();
      }

      @Override
      public int getCharPositionInLine() {
        throw new UnsupportedOperationException();
      }

      @Override
      public CharStream getInputStream() {
        throw new UnsupportedOperationException();
      }

      @Override
      public String getSourceName() {
        return "<from TokenizedProgram>";
      }

      @Override
      public void setTokenFactory(TokenFactory<?> tokenFactory) {
        throw new UnsupportedOperationException();
      }

      @Override
      public TokenFactory<?> getTokenFactory() {
        throw new UnsupportedOperationException();
      }
    };
  }

  private static final Token EOF_TOKEN = new CommonToken(Token.EOF);
}

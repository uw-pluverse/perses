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
package org.perses.program;

import com.google.common.base.MoreObjects;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.UnmodifiableIterator;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenFactory;
import org.antlr.v4.runtime.TokenSource;
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

  private final AbstractLazySourceCode sourceCodeSingleLine =
      new AbstractLazySourceCode() {
        @Override
        protected FastStringBuilder computeStringBuilder() {
          final int tokenCount = tokenCount();
          final FastStringBuilder result = new FastStringBuilder(tokenCount * 5);

          for (int i = 0; i < tokenCount; ++i) {
            final PersesToken token = tokens.get(i);
            result.append(token.getText()).append('\n');
          }
          return result;
        }
      };

  private final AbstractLazySourceCode sourceCodeInOrigFormat =
      new AbstractLazySourceCode() {
        @Override
        protected FastStringBuilder computeStringBuilder() {
          return computeSourceCodeInOrigFormat(tokens, /*keepBlankLines=*/ true);
        }
      };

  private final AbstractLazySourceCode compactSourceCodeInOrigFormat =
      new AbstractLazySourceCode() {
        @Override
        protected FastStringBuilder computeStringBuilder() {
          return computeSourceCodeInOrigFormat(tokens, /*keepBlankLines=*/ false);
        }
      };

  public String toCompactSourceCode() {
    return compactSourceCodeInOrigFormat.getSourceCode();
  }

  public String toSourceCodeInOrigFormatWithBlankLines() {
    return sourceCodeInOrigFormat.getSourceCode();
  }

  private static FastStringBuilder computeSourceCodeInOrigFormat(
      ImmutableList<PersesToken> tokens, boolean keepBlankLines) {
    final int tokenCount = tokens.size();
    final FastStringBuilder builder = new FastStringBuilder(tokenCount * 5);
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
        if (keepBlankLines) {
          builder.append('\n');
        } else if (builder.isNotEmpty() && builder.lastChar() != '\n') {
          builder.append('\n');
        }
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
    return builder;
  }

  public final int tokenCount() {
    return tokens.size();
  }

  @Override
  public final String toString() {
    return MoreObjects.toStringHelper(this).add("tokens", tokens).toString();
  }

  public final void writeToFile(File file, EnumFormatControl formatControl) throws IOException {
    try (BufferedWriter writer = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8)) {
      switch (formatControl) {
        case ORIG_FORMAT:
          sourceCodeInOrigFormat.writeTo(writer);
          break;
        case SINGLE_TOKEN_PER_LINE:
          sourceCodeSingleLine.writeTo(writer);
          break;
        case COMPACT_ORIG_FORMAT:
          compactSourceCodeInOrigFormat.writeTo(writer);
          break;
        default:
          throw new RuntimeException("Unhandled format control: " + formatControl);
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

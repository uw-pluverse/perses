package org.perses.program;

import com.google.common.base.MoreObjects;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenSource;

public final class PersesToken implements Token {
  private final int persesLexemeId;

  // Cache the token text, due to the uncertain way how Antlr returns lexeme.
  private final String text;
  private final int type;
  private final int line;
  private final int charPositionInLine;
  private final int channel;
  private final int tokenIndex;
  private final int startIndex;
  private final int stopIndex;

  PersesToken(int persesLexemeId, Token token) {
    this.persesLexemeId = persesLexemeId;
    type = token.getType();
    line = token.getLine();
    charPositionInLine = token.getCharPositionInLine();
    channel = token.getChannel();
    tokenIndex = token.getTokenIndex();
    startIndex = token.getStartIndex();
    stopIndex = token.getStopIndex();
    this.text = token.getText();
  }

  @Override
  public String getText() {
    return text;
  }

  @Override
  public int getType() {
    return type;
  }

  @Override
  public int getLine() {
    return line;
  }

  @Override
  public int getCharPositionInLine() {
    return charPositionInLine;
  }

  @Override
  public int getChannel() {
    return channel;
  }

  @Override
  public int getTokenIndex() {
    return tokenIndex;
  }

  @Override
  public int getStartIndex() {
    return startIndex;
  }

  @Override
  public int getStopIndex() {
    return stopIndex;
  }

  @Override
  public TokenSource getTokenSource() {
    throw new UnsupportedOperationException();
  }

  @Override
  public CharStream getInputStream() {
    throw new UnsupportedOperationException();
  }

  public int getPersesLexemeId() {
    return persesLexemeId;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("token", getText()).toString();
  }
}

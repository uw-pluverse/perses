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

import com.google.common.collect.ImmutableList;
import org.antlr.v4.runtime.Token;

import java.util.List;

public final class TokenizedProgramFactory {

  public static TokenizedProgramFactory createFactory(List<Token> originalProgram) {
    ImmutableList.Builder<PersesToken> builder =
        ImmutableList.builderWithExpectedSize(originalProgram.size());
    PersesTokenFactory.Builder tokenFactoryBuilder = new PersesTokenFactory.Builder();
    for (Token token : originalProgram) {
      builder.add(tokenFactoryBuilder.create(token));
    }
    return new TokenizedProgramFactory(tokenFactoryBuilder.build(), builder.build());
  }

  private final PersesTokenFactory tokenFactory;
  // TODO: build an inverted index for this original program.
  private final ImmutableList<PersesToken> tokensInOrigin;

  private TokenizedProgramFactory(
      PersesTokenFactory tokenFactory, ImmutableList<PersesToken> tokensInOrigin) {
    this.tokenFactory = tokenFactory;
    this.tokensInOrigin = tokensInOrigin;
  }

  public TokenizedProgram create(List<Token> tokens) {
    final ImmutableList.Builder<PersesToken> builder =
        ImmutableList.builderWithExpectedSize(tokens.size());
    for (Token token : tokens) {
      builder.add(tokenFactory.getPersesToken(token));
    }
    return new TokenizedProgram(builder.build());
  }

  public PersesTokenFactory getTokenFactory() {
    return tokenFactory;
  }

  public ImmutableList<PersesToken> getTokensInOrigin() {
    return tokensInOrigin;
  }
}

package org.perses.program;

import com.google.common.collect.ImmutableList;
import com.google.common.truth.Truth;
import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.Token;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.util.List;

@RunWith(JUnit4.class)
public class TokenizedProgramFactoryTest {

  private TokenizedProgramFactory factory;

  @Before
  public void setup() {
    ImmutableList<Token> tokens = createAntlrTokens(ImmutableList.of("a", "b", "c", "d", "e"));
    factory = TokenizedProgramFactory.createFactory(tokens);
  }

  @Test
  public void test() {
    ImmutableList<Token> tokens = createAntlrTokens(ImmutableList.of("b", "e"));
    final TokenizedProgram program = factory.create(tokens);
    final ImmutableList<PersesToken> persesTokens = program.getTokens();
    Truth.assertThat(persesTokens).hasSize(2);
    Truth.assertThat(persesTokens.get(0).getPersesLexemeId()).isEqualTo(1);
    Truth.assertThat(persesTokens.get(1).getPersesLexemeId()).isEqualTo(4);
  }

  private ImmutableList<Token> createAntlrTokens(List<String> lexemes) {
    return lexemes.stream()
        .map(l -> new CommonToken(/*type=*/ 0, l))
        .collect(ImmutableList.toImmutableList());
  }
}

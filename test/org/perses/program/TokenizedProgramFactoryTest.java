package org.perses.program;

import com.google.common.collect.ImmutableList;
import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.Token;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import java.io.IOException;
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
  public void testOnClang27747() throws IOException {
    TestUtility.createSparTreeFromFile("test/org/perses/program/clang-27747.c")
        .getProgramSnapshot();
  }

  private ImmutableList<Token> createAntlrTokens(List<String> lexemes) {
    return lexemes.stream()
        .map(l -> new CommonToken(/*type=*/ 0, l))
        .collect(ImmutableList.toImmutableList());
  }
}

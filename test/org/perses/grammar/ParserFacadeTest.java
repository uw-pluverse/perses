package org.perses.grammar;

import com.google.common.collect.ImmutableList;
import com.google.common.truth.Truth;
import org.antlr.v4.runtime.Token;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.PnfCParserFacade;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;
import org.perses.tree.spar.SparTree;
import org.perses.tree.spar.SparTreeBuilder;

import java.io.IOException;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class ParserFacadeTest {

  private CParserFacade facade = new CParserFacade();
  private PnfCParserFacade pnfcFacade = new PnfCParserFacade();

  @Test
  public void testIsParsable_true() throws IOException {
    final TokenizedProgram program =
        TestUtility.createSparTreeFromFile("test_data/misc/t1.c").getProgramSnapshot();
    assertThat(facade.isSourceCodeParsable(program.getSourceCodeInOrigFormat())).isTrue();
    assertThat(facade.isSourceCodeParsable(program)).isTrue();

    assertThat(pnfcFacade.isSourceCodeParsable(program.getSourceCodeInOrigFormat())).isTrue();
    assertThat(pnfcFacade.isSourceCodeParsable(program)).isTrue();

    final TokenizedProgram invalidProgram = deriveInvalidProgram(program);
    assertThat(facade.isSourceCodeParsable(invalidProgram.getSourceCodeInOrigFormat())).isFalse();
    assertThat(facade.isSourceCodeParsable(invalidProgram)).isFalse();

    assertThat(pnfcFacade.isSourceCodeParsable(invalidProgram.getSourceCodeInOrigFormat()))
        .isFalse();
    assertThat(pnfcFacade.isSourceCodeParsable(invalidProgram)).isFalse();
  }

  @Test
  public void testParseTokenizedProgram_t1() throws IOException {
    testParseTokenizedProgram("t1.c");
  }

  @Test
  public void testParseTokenizedProgram_t2() throws Exception {
    testParseTokenizedProgram("t2.c");
  }

  @Test
  public void testParseTokenizedProgram_t3() throws Exception {
    testParseTokenizedProgram("t3.c");
  }

  @Test
  public void testParseTokenizedProgram_t4() throws Exception {
    testParseTokenizedProgram("t4.c");
  }

  @Test
  public void testParseTokenizedProgram_t5() throws Exception {
    testParseTokenizedProgram("t5.c");
  }

  @Test
  public void testParseTokenizedProgram_t9() throws Exception {
    testParseTokenizedProgram("t9.c");
  }

  private void testParseTokenizedProgram(String filename) throws IOException {
    final SparTree sparTreeFromFile =
        TestUtility.createSparTreeFromFile("test_data/misc/" + filename);
    final TokenizedProgram originalProgram = sparTreeFromFile.getProgramSnapshot();
    final ImmutableList<String> originalTokens = toAntlrTokens(originalProgram.getTokens());
    TokenizedProgramFactory factory = sparTreeFromFile.getTokenizedProgramFactory();
    {
      final ParseTreeWithParser parseTreeFromFacade = facade.parseTokenizedProgram(originalProgram);
      final SparTree tree =
          new SparTreeBuilder(facade.getRuleHierarchy(), factory)
              .build(parseTreeFromFacade.getTree());
      final ImmutableList<String> tokens = toAntlrTokens(tree.getProgramSnapshot().getTokens());
      Truth.assertThat(tokens).containsExactlyElementsIn(originalTokens).inOrder();
    }
    {
      final ParseTreeWithParser parseTreeFromPnfc =
          pnfcFacade.parseTokenizedProgram(originalProgram);
      final SparTree treeFromPnfc =
          new SparTreeBuilder(pnfcFacade.getRuleHierarchy(), factory)
              .build(parseTreeFromPnfc.getTree());
      final ImmutableList<String> tokens =
          toAntlrTokens(treeFromPnfc.getProgramSnapshot().getTokens());
      Truth.assertThat(tokens).containsExactlyElementsIn(originalTokens).inOrder();
    }
  }

  private static ImmutableList<String> toAntlrTokens(ImmutableList<PersesToken> tokens) {
    return tokens.stream().map(Token::getText).collect(ImmutableList.toImmutableList());
  }

  private static TokenizedProgram deriveInvalidProgram(TokenizedProgram program) {
    ImmutableList.Builder<PersesToken> builder = ImmutableList.builder();
    for (PersesToken t : program.getTokens()) {
      final String lexeme = t.getText();
      if (lexeme.equals(";") || lexeme.equals(",")) {
        continue;
      }
      builder.add(t);
    }
    return new TokenizedProgram(builder.build());
  }
}

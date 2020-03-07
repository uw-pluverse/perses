package org.perses.grammar.c;

import com.google.common.io.Files;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@RunWith(JUnit4.class)
public class PnfCParserFacadeTest {

  @Test
  public void testGoldenPnfCGrammar() throws IOException {
    PnfCParserFacade facade = new PnfCParserFacade();
    String content = facade.getAntlrGrammar().asCombined().getGrammar().getSourceCode();
    String golden =
        Files.asCharSource(
                new File("test/org/perses/grammar/c/golden_pnf_c.g4"), StandardCharsets.UTF_8)
            .read();
    Truth.assertThat(content).isEqualTo(golden);
  }
}

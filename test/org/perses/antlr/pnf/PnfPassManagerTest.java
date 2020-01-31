package org.perses.antlr.pnf;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;

@RunWith(JUnit4.class)
public class PnfPassManagerTest extends PnfLeftTestGrammar {

  private PnfPassManager manager;

  @Before
  public void setup() {
    manager = new PnfPassManager();
  }

  @Test
  public void testPassManager() {
    // No test so far.
  }

  @Test
  public void testConvertC() {
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromFile("C.g4");
    PersesGrammar processed = manager.process(grammar, "compilationUnit");
    System.out.println(processed.getSourceCode());
  }
}

package org.perses.antlr.pnf;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class PnfPassManagerTest extends PnfLeftTestGrammar {

  private PnfPassManager manager;
  private PnfPassManager.Listener listener =
      new PnfPassManager.Listener() {
        @Override
        protected void start(PersesGrammar grammar, String startRuleName) {
          System.err.println("Starting...");
          System.err.println(grammar.getSourceCode());
        }

        @Override
        protected void beforePass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
          super.beforePass(grammar, passClass, iteration);
        }

        @Override
        protected void afterPass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
          System.err.println("After pass " + passClass);
          System.err.println(grammar.getPersesGrammar().getSourceCode());
        }
      };

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

  @Test
  public void testConvertPrimaryExprOfGo_shouldNotCrash() {
    PersesGrammar grammar =
        GrammarTestingUtility.loadGrammarFromFile("nested_alt_block_from_go.g4");
    final PersesGrammar processed = manager.process(grammar, "primaryExpr", listener);
    final String sourceCode = processed.getSourceCode();
    System.err.println(sourceCode);
  }


  @Test
  public void testConvertGoParser_shouldNotCrash() {
    PersesGrammar grammar =
        GrammarTestingUtility.loadGrammarFromFile("GoParser.g4");
    final PersesGrammar processed = manager.process(grammar, "primaryExpr", listener);
    final String sourceCode = processed.getSourceCode();
    System.err.println(sourceCode);
  }
}

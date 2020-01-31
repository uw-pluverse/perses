package org.perses.antlr.pnf;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class RuleTransitionGraphTest extends PnfLeftTestGrammar {

  @Test
  public void testTransitionGraphCanBeBuilt() {
    assertThat(a.get()).isEqualTo("a");
    assertThat(b.get()).isEqualTo("b");
    assertThat(c.get()).isEqualTo("c");
    assertThat(d.get()).isEqualTo("d");

    assertThat(edge_bc.getSourceCode()).isEqualTo("b c");
    assertThat(edge_d.getSourceCode()).isEqualTo("d");
    assertThat(edge_ad.getSourceCode()).isEqualTo("a d");
    assertThat(edge_cd.getSourceCode()).isEqualTo("c d");
  }
}

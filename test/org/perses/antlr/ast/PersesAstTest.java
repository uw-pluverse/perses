package org.perses.antlr.ast;

import com.google.common.collect.ImmutableList;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class PersesAstTest {

  @Test
  public void testChildrenOfAltBlockAreKeptInInitOrder() {
    ImmutableList<AbstractPersesRuleElement> childrenA =
        GrammarTestingUtility.createTerminalList("a", "b");
    PersesAlternativeBlockAst a = new PersesAlternativeBlockAst(childrenA);
    ImmutableList<AbstractPersesRuleElement> childrenB =
        GrammarTestingUtility.createTerminalList("b", "a");
    PersesAlternativeBlockAst b = new PersesAlternativeBlockAst(childrenB);

    assertThat(a.getChild(0).getSourceCode()).isEqualTo(b.getChild(1).getSourceCode());
    assertThat(a.getChild(1).getSourceCode()).isEqualTo(b.getChild(0).getSourceCode());
    assertThat(a.isEquivalent(b)).isTrue();
  }

  @Test
  public void testChildrenOfTokenSetKeptInInitOrder() {
    ImmutableList<AbstractPersesTerminalAst> childrenA =
        GrammarTestingUtility.createTerminalList("A", "B").stream()
            .map(a -> (AbstractPersesTerminalAst) a)
            .collect(ImmutableList.toImmutableList());
    PersesTokenSetAst a = new PersesTokenSetAst(childrenA);
    ImmutableList<AbstractPersesTerminalAst> childrenB =
        GrammarTestingUtility.createTerminalList("B", "A").stream()
            .map(b -> (AbstractPersesTerminalAst) b)
            .collect(ImmutableList.toImmutableList());
    PersesTokenSetAst b = new PersesTokenSetAst(childrenB);

    assertThat(a.getChild(0).getSourceCode()).isEqualTo(b.getChild(1).getSourceCode());
    assertThat(a.getChild(1).getSourceCode()).isEqualTo(b.getChild(0).getSourceCode());
    assertThat(a.isEquivalent(b)).isTrue();
  }

  @Test
  public void testBlockComment() {
    PersesGrammar persesGrammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            "BlockComment: '/*' .*? '*/' -> skip ;");
    AbstractPersesRuleElement body = persesGrammar.getRuleDefinition("BlockComment").get().getBody();
    assertThat(body).isInstanceOf(PersesLexerSkipCommandAst.class);
    AbstractPersesRuleElement child = body.getChild(0);
    assertThat(child).isInstanceOf(PersesSequenceAst.class);
    assertThat(child.getChildCount()).isEqualTo(3);

    AbstractPersesRuleElement first = child.getChild(0);
    assertThat(first.getSourceCode()).isEqualTo("'/*'");
    AbstractPersesRuleElement second = child.getChild(1);
    assertThat(second.getSourceCode()).isEqualTo(".*?");
    AbstractPersesRuleElement third = child.getChild(2);
    assertThat(third.getSourceCode()).isEqualTo("'*/'");
  }
}

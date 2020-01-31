package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import org.jgrapht.Graph;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.*;

import java.util.List;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class IndirectRightRecursionEliminationPassTest extends PnfRightTestGrammar {

  private IndirectRightRecursionEliminationPass pass;

  @Before
  public void setup() {
    pass = new IndirectRightRecursionEliminationPass();
  }

  @Test
  public void testGetLastIfRuleRef() {
    RuleNameRegistry registry = new RuleNameRegistry();
    RuleNameRegistry.RuleNameHandle name = registry.getOrCreate("a");
    PersesRuleReferenceAst ref = new PersesRuleReferenceAst(name);

    assertThat(pass.getRuleRefToInline(ref)).isEqualTo(Optional.of(name));

    PersesTerminalAst terminal = new PersesTerminalAst("t", 0);

    {
      PersesSequenceAst seqWithFirstAsRef = new PersesSequenceAst(ImmutableList.of(ref, terminal));
      assertThat(pass.getRuleRefToInline(seqWithFirstAsRef).isPresent()).isFalse();
    }
    {
      PersesSequenceAst seqWithoutFirstAsRef =
          new PersesSequenceAst(ImmutableList.of(terminal, ref));
      assertThat(pass.getRuleRefToInline(seqWithoutFirstAsRef).isPresent()).isTrue();
      assertThat(pass.getRuleRefToInline(seqWithoutFirstAsRef).get())
          .isEqualTo(ref.getRuleNameHandle());
    }
    assertThat(pass.getRuleRefToInline(terminal).isPresent()).isFalse();
  }

  @Test
  public void testComputeScc() {
    RuleTransitionGraph graph =
        RuleTransitionGraph.createForRightmostTransition(ImmutableRuleDefMap.create(grammar));
    List<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> sccSet =
        GrammarTestingUtility.getSortedSccList(graph);
    assertThat(sccSet).hasSize(3);
    assertThat(sccSet.get(0).vertexSet()).containsExactly(a, b);
    assertThat(sccSet.get(1).vertexSet()).containsExactly(c);
    assertThat(sccSet.get(2).vertexSet()).containsExactly(d);
  }

  @Test
  public void test_transformRightForScc() {
    List<Set<RuleNameRegistry.RuleNameHandle>> grammars =
        GrammarTestingUtility.getSortedSccList(
                RuleTransitionGraph.createForRightmostTransition(ruleDefMap))
            .stream()
            .map(Graph::vertexSet)
            .collect(Collectors.toList());

    {
      Set<RuleNameRegistry.RuleNameHandle> g = grammars.get(0);
      MutableRuleDefMap result =
          ruleDefMap.createMutable();
      pass.transformForScc(new ProjectedHashMultimap(result, g));
      assertThat(result.keySet()).containsAtLeast(a, b);
      {
        Set<AbstractPersesRuleElement> defs = result.get(a);
        assertThat(defs).hasSize(3);
        assertThat(defs).containsExactly(def_a_cb, def_a_d, PersesEpsilonAst.INSTANCE);
      }
      {
        Set<AbstractPersesRuleElement> defs = result.get(b);
        assertThat(defs).hasSize(4);
        List<String> defsStrings =
            defs.stream()
                .map(AbstractPersesAst::getSourceCode)
                .sorted()
                .collect(Collectors.toList());
        assertThat(defsStrings).containsExactly("d c b", "d d", "d", "c d");
      }
    }
  }
}

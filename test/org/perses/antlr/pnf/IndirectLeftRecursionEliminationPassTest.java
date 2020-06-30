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
public class IndirectLeftRecursionEliminationPassTest extends PnfLeftTestGrammar {

  private IndirectLeftRecursionEliminationPass pass;

  @Before
  public void setup() {
    pass = new IndirectLeftRecursionEliminationPass();
  }

  @Test
  public void testGetFirstIfIsRuleRef() {
    RuleNameRegistry registry = new RuleNameRegistry();
    RuleNameRegistry.RuleNameHandle name = registry.getOrCreate("a");
    PersesRuleReferenceAst ref = new PersesRuleReferenceAst(name);

    assertThat(pass.getRuleRefToInline(ref)).isEqualTo(Optional.of(name));

    PersesTerminalAst terminal = new PersesTerminalAst("t", 0);

    {
      PersesSequenceAst seqWithFirstAsRef = new PersesSequenceAst(ImmutableList.of(ref, terminal));
      assertThat(pass.getRuleRefToInline(seqWithFirstAsRef)).isEqualTo(Optional.of(name));
    }
    {
      PersesSequenceAst seqWithoutFirstAsRef =
          new PersesSequenceAst(ImmutableList.of(terminal, ref));
      assertThat(pass.getRuleRefToInline(seqWithoutFirstAsRef).isPresent()).isFalse();
    }
    assertThat(pass.getRuleRefToInline(terminal).isPresent()).isFalse();
  }

  @Test
  public void test_inlineFirstRuleRef() {
    {
      AbstractPersesRuleElement ele = pass.inlineRuleRef(edge_bc, edge_ad);
      assertThat(ele).isInstanceOf(PersesSequenceAst.class);
      PersesSequenceAst seq = (PersesSequenceAst) ele;
      assertThat(seq.getChildCount()).isEqualTo(3);
      assertThat(seq.getChild(0).getSourceCode()).isEqualTo("a");
      assertThat(seq.getChild(1).getSourceCode()).isEqualTo("d");
      assertThat(seq.getChild(2).getSourceCode()).isEqualTo("c");
    }
    {
      AbstractPersesRuleElement ele = pass.inlineRuleRef(edge_d, edge_ad);
      assertThat(ele).isInstanceOf(PersesSequenceAst.class);
      assertThat(ele).isSameInstanceAs(edge_ad);
    }
  }

  @Test
  public void testComputeScc() {
    List<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> sccSet =
        GrammarTestingUtility.getSortedSccList(graph);
    assertThat(sccSet).hasSize(3);
    {
      Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> scc = sccSet.get(0);
      assertThat(scc.vertexSet()).containsExactly(a, b);
      assertThat(scc.outgoingEdgesOf(a)).containsExactly(edge_bc);
      assertThat(scc.outgoingEdgesOf(b)).containsExactly(edge_ad);
    }
    {
      Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> scc = sccSet.get(1);
      assertThat(scc.vertexSet()).containsExactly(c);
      assertThat(scc.outDegreeOf(c)).isEqualTo(0);
    }
    {
      Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> scc = sccSet.get(2);
      assertThat(scc.vertexSet()).containsExactly(d);
      assertThat(scc.outDegreeOf(d)).isEqualTo(0);
    }
  }

  @Test
  public void test_transformLeftForScc() {
    ImmutableRuleDefMap origGrammar = ImmutableRuleDefMap.create(grammar);
    List<Set<RuleNameRegistry.RuleNameHandle>> grammars =
        GrammarTestingUtility.getSortedSccList(graph).stream()
            .map(Graph::vertexSet)
            .collect(Collectors.toList());
    {
      Set<RuleNameRegistry.RuleNameHandle> g = grammars.get(0);
      MutableRuleDefMap result = origGrammar.createMutable();
      pass.transformForScc(new ProjectedHashMultimap(result, g));
      assertThat(result.keySet()).containsAtLeast(a, b);
      {
        Set<AbstractPersesRuleElement> defs = result.get(a);
        assertThat(defs).hasSize(3);
        assertThat(defs).containsExactly(edge_bc, edge_d, PersesEpsilonAst.INSTANCE);
      }
      {
        Set<AbstractPersesRuleElement> defs = result.get(b);
        assertThat(defs).hasSize(4);
        List<String> defStrings =
            defs.stream()
                .map(AbstractPersesRuleElement::getSourceCode)
                .sorted()
                .collect(Collectors.toList());
        assertThat(defStrings).containsExactly("d d", "b c d", "d", "c d");
      }
    }
    {
      Set<RuleNameRegistry.RuleNameHandle> g = grammars.get(1);
      MutableRuleDefMap result = origGrammar.createMutable();
      pass.transformForScc(new ProjectedHashMultimap(result, g));
      Set<AbstractPersesRuleElement> defs = result.get(c);
      assertThat(defs).hasSize(1);
      assertThat(defs.iterator().next().getSourceCode()).isEqualTo("'c'");
    }
    {
      Set<RuleNameRegistry.RuleNameHandle> g = grammars.get(2);
      MutableRuleDefMap result = origGrammar.createMutable();
      pass.transformForScc(new ProjectedHashMultimap(result, g));
      assertThat(
              result.get(d).stream()
                  .map(AbstractPersesAst::getSourceCode)
                  .collect(Collectors.toList()))
          .containsExactly("'d'");
    }
  }
}

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

import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

public class PnfLeftTestGrammar {

  protected RuleTransitionGraph graph;
  protected RuleNameRegistry.RuleNameHandle a;
  protected RuleNameRegistry.RuleNameHandle b;
  protected RuleNameRegistry.RuleNameHandle c;
  protected RuleNameRegistry.RuleNameHandle d;

  protected AbstractPersesRuleElement edge_bc;
  protected AbstractPersesRuleElement edge_d;
  protected AbstractPersesRuleElement edge_ad;
  protected AbstractPersesRuleElement edge_cd;
  protected PersesGrammar grammar;

  public PnfLeftTestGrammar() {
    grammar = GrammarTestingUtility.loadGrammarFromFile("pnf_test.g4");
    graph = RuleTransitionGraph.createForLeftmostTransition(ImmutableRuleDefMap.create(grammar));
    List<RuleNameRegistry.RuleNameHandle> nodes =
        graph.getGraph().vertexSet().stream()
            .sorted(Comparator.comparingInt(RuleNameRegistry.RuleNameHandle::getId))
            .collect(Collectors.toList());
    assertThat(nodes).hasSize(4);
    a = nodes.get(0);
    b = nodes.get(1);
    c = nodes.get(2);
    d = nodes.get(3);

    {
      List<AbstractPersesRuleElement> edgesOfA =
          graph.getGraph().outgoingEdgesOf(a).stream()
              .sorted(Comparator.comparing(AbstractPersesAst::getSourceCode))
              .collect(Collectors.toList());
      assertThat(edgesOfA).hasSize(2);

      edge_bc = edgesOfA.get(0);
      edge_d = edgesOfA.get(1);
    }

    {
      List<AbstractPersesRuleElement> edges =
          graph.getGraph().outgoingEdgesOf(b).stream()
              .sorted(Comparator.comparing(AbstractPersesAst::getSourceCode))
              .collect(Collectors.toList());
      assertThat(edges).hasSize(2);

      edge_ad = edges.get(0);
      edge_cd = edges.get(1);
    }
  }
}

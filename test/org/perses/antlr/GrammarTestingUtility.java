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
package org.perses.antlr;

import com.google.common.base.Joiner;
import com.google.common.collect.Comparators;
import com.google.common.collect.ImmutableList;
import com.google.common.io.Files;
import org.jgrapht.Graph;
import org.perses.antlr.ast.*;
import org.perses.antlr.pnf.RuleTransitionGraph;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public final class GrammarTestingUtility {

  public static PersesGrammar loadGrammarFromString(String antlrGrammarContent) {
    try {
      return new PersesAstBuilder()
          .buildFromAntlrRootAst(
              AntlrGrammarParser.parseRawGrammarASTFromString(antlrGrammarContent));
    } catch (Exception e) {
      throw new AssertionError(e);
    }
  }

  public static PersesGrammar loadGrammarFromFile(String filename) {
    try {
      return new PersesAstBuilder()
          .buildFromAntlrRootAst(
              AntlrGrammarParser.parseRawGrammarASTFromString(readAntlrFileToString(filename)));
    } catch (Exception e) {
      throw new AssertionError(e);
    }
  }

  public static String readAntlrFileToString(String filename) throws IOException {
    return Files.asCharSource(
            new File("test_data/antlr_grammars/" + filename), StandardCharsets.UTF_8)
        .read();
  }

  public static PersesGrammar createPersesGrammarFromString(String... lines) {
    ArrayList<String> list = new ArrayList<>();
    list.add("grammar Temp;");
    Stream.of(lines).forEach(list::add);
    return PersesAstBuilder.loadGrammarFromString(Joiner.on("\n").join(list));
  }

  public static PersesSequenceAst createSeqOfTerminals(List<String> terminals) {
    return createSeqOfTerminals(terminals.toArray(new String[0]));
  }

  public static PersesSequenceAst createSeqOfTerminals(String... terminals) {
    ImmutableList<AbstractPersesRuleElement> astList = createTerminalList(terminals);
    return new PersesSequenceAst(astList);
  }

  public static AbstractPersesRuleElement createTerminal(String text) {
    return new PersesTerminalAst(text, 0);
  }

  public static ImmutableList<AbstractPersesRuleElement> createTerminalList(String... terminals) {
    return Stream.of(terminals)
        .map(GrammarTestingUtility::createTerminal)
        .collect(ImmutableList.toImmutableList());
  }

  public static List<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>>
      getSortedSccList(RuleTransitionGraph graph) {
    return graph.computeSccSet().stream().sorted(new GraphOrder()).collect(Collectors.toList());
  }

  public static class GraphOrder
      implements Comparator<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> {

    @Override
    public int compare(
        Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> o1,
        Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> o2) {
      List<RuleNameRegistry.RuleNameHandle> v1 = toSortedVertices(o1.vertexSet());
      List<RuleNameRegistry.RuleNameHandle> v2 = toSortedVertices(o2.vertexSet());

      int result = compareVertices(v1, v2);
      if (result != 0) {
        return result;
      }
      for (int i = 0, size = v1.size(); i < size; ++i) {
        RuleNameRegistry.RuleNameHandle n1 = v1.get(i);
        RuleNameRegistry.RuleNameHandle n2 = v2.get(i);
        List<String> e1 = toSortedEdges(o1.outgoingEdgesOf(n1));
        List<String> e2 = toSortedEdges(o2.outgoingEdgesOf(n2));
        result =
            Comparators.lexicographical((String a, String b) -> a.compareTo(b)).compare(e1, e2);
        if (result != 0) {
          return result;
        }
      }
      return 0;
    }

    private static int compareVertices(
        List<RuleNameRegistry.RuleNameHandle> v1, List<RuleNameRegistry.RuleNameHandle> v2) {
      return Comparators.lexicographical(
              Comparator.comparingInt(RuleNameRegistry.RuleNameHandle::getId))
          .compare(v1, v2);
    }
  }

  public static List<String> toSortedEdges(Set<AbstractPersesRuleElement> edges) {
    return edges.stream()
        .map(AbstractPersesAst::getSourceCode)
        .sorted()
        .collect(Collectors.toList());
  }

  public static List<RuleNameRegistry.RuleNameHandle> toSortedVertices(
      Set<RuleNameRegistry.RuleNameHandle> vertices) {
    return vertices.stream()
        .sorted(Comparator.comparingInt(RuleNameRegistry.RuleNameHandle::getId))
        .collect(Collectors.toList());
  }
}

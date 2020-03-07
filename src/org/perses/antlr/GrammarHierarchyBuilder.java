package org.perses.antlr;

import com.google.common.collect.*;
import com.google.common.graph.EndpointPair;
import com.google.common.graph.GraphBuilder;
import com.google.common.graph.MutableGraph;
import org.perses.antlr.ast.*;

import java.util.*;

import static com.google.common.base.Preconditions.checkNotNull;

public final class GrammarHierarchyBuilder {

  private final AbstractAntlrGrammar grammar;
  private final EpsilonInfo epsilonInfo;
  private final ImmutableList<RuleHierarchyInfo> indexToRuleMap;
  private final ImmutableMap<String, RuleHierarchyInfo> nameToRuleMap;
  private final ImmutableList<Optional<RuleHierarchyInfo>> indexToTokenMap;

  public GrammarHierarchyBuilder(
      AbstractAntlrGrammar grammar, ImmutableMap<Integer, String> typeToTokenNameMap) {
    this.grammar = grammar;
    final ImmutableList<AbstractPersesRuleDefAst> combinedRules = grammar.getCombinedRules();
    epsilonInfo = RuleEpsilonComputer.computeEpsilonableRules(combinedRules);
    indexToRuleMap =
        combinedRules.stream()
            .map(this::extractRuleHierarchyInfo)
            .collect(ImmutableList.toImmutableList());
    nameToRuleMap = buildNameToRuleMap(indexToRuleMap);
    indexToTokenMap = buildIndexToTokenMap(typeToTokenNameMap, nameToRuleMap);
  }

  private RuleHierarchyInfo extractRuleHierarchyInfo(AbstractPersesRuleDefAst ruleDefinition) {
    final ImmutableSet<String> immediateSubRules = extractImmediateSubRules(ruleDefinition);
    final RuleHierarchyInfo rule =
        new RuleHierarchyInfo(
            ruleDefinition, immediateSubRules, epsilonInfo.canBeEpsilon(ruleDefinition));
    return rule;
  }

  private ImmutableSet<String> extractImmediateSubRules(AbstractPersesRuleDefAst rule) {
    if (rule.isLexerRule()) {
      return ImmutableSet.of();
    }
    final HashSet<String> result = new HashSet<>();
    extractImmediateSubrulesFromBlockAST(rule.getBody(), result);
    return ImmutableSet.copyOf(result);
  }

  // FIXME: need to support lex rules.
  private void extractImmediateSubrulesFromBlockAST(
      AbstractPersesRuleElement ruleBody, HashSet<String> result) {
    switch (ruleBody.getTag()) {
      case ALTERNATIVE_BLOCK:
        {
          PersesAlternativeBlockAst block = (PersesAlternativeBlockAst) ruleBody;
          for (int i = 0, size = block.getChildCount(); i < size; ++i) {
            extractImmediateSubrulesFromBlockAST(block.getChild(i), result);
          }
          return;
        }
      case TERMINAL:
        {
          PersesTerminalAst terminal = (PersesTerminalAst) ruleBody;
          if (terminal.isEOF() || terminal.isStringLiteral()) {
            return;
          }
          result.add(terminal.getText());
          return;
        }
      case RULE_REF:
        {
          result.add(((PersesRuleReferenceAst) ruleBody).getRuleNameHandle().get());
          return;
        }
      case STAR:
      case PLUS:
      case OPTIONAL:
        {
          AbstractPersesQuantifiedAst quantified = (AbstractPersesQuantifiedAst) ruleBody;
          extractImmediateSubrulesFromBlockAST(quantified.getBody(), result);
          return;
        }
      case SEQUENCE:
        {
          PersesSequenceAst seq = (PersesSequenceAst) ruleBody;
          final ArrayList<AbstractPersesRuleElement> unremovableChildren = new ArrayList<>();
          for (int i = 0, size = seq.getChildCount(); i < size; ++i) {
            final AbstractPersesRuleElement child = seq.getChild(i);
            if (epsilonInfo.canBeEpsilon(child)) {
              continue;
            }
            unremovableChildren.add(child);
          }
          switch (unremovableChildren.size()) {
            case 0:
              {
                for (int i = 0, size = seq.getChildCount(); i < size; ++i) {
                  extractImmediateSubrulesFromBlockAST(seq.getChild(i), result);
                }
                return;
              }
            case 1:
              {
                extractImmediateSubrulesFromBlockAST(unremovableChildren.get(0), result);
                return;
              }
            default:
              return;
          }
        }
    }
  }

  private static ImmutableList<Optional<RuleHierarchyInfo>> buildIndexToTokenMap(
      ImmutableMap<Integer, String> typeToTokenNameMap,
      ImmutableMap<String, RuleHierarchyInfo> nameToRuleMap) {
    final Optional<Integer> max = typeToTokenNameMap.keySet().stream().max(Integer::compareTo);
    assert max.isPresent() : typeToTokenNameMap;
    final ImmutableList.Builder<Optional<RuleHierarchyInfo>> builder = ImmutableList.builder();
    final int maxValue = max.get();
    for (int i = 0; i <= maxValue; ++i) {
      final String tokeName = typeToTokenNameMap.get(i);
      if (tokeName == null) {
        builder.add(Optional.empty());
        continue;
      }
      final RuleHierarchyInfo rule = nameToRuleMap.get(tokeName);
      builder.add(Optional.ofNullable(rule));
    }
    return builder.build();
  }

  private static ImmutableMap<String, RuleHierarchyInfo> buildNameToRuleMap(
      ImmutableList<RuleHierarchyInfo> rules) {
    final ImmutableMap.Builder<String, RuleHierarchyInfo> builder = ImmutableMap.builder();
    rules.forEach(rule -> builder.put(rule.getRuleName(), rule));
    return builder.build();
  }

  public GrammarHierarchy build() {
    buildTransitiveSubtypingRule();
    return new GrammarHierarchy(indexToRuleMap, nameToRuleMap, indexToTokenMap);
  }

  private void buildTransitiveSubtypingRule() {
    MutableGraph<RuleHierarchyInfo> graph = GraphBuilder.directed().allowsSelfLoops(false).build();
    indexToRuleMap.forEach(
        node -> {
          graph.addNode(node); // This is necessary, as it can have no immediate subrules.
          for (String subruleName : node.getImmediateSubRuleNames()) {
            final RuleHierarchyInfo subrule = nameToRuleMap.get(subruleName);
            checkNotNull(
                subrule, "No subrule for node %s. Node=%s", subruleName, node.getRuleName());
            graph.putEdge(node, subrule);
          }
        });
    final ArrayDeque<RuleHierarchyInfo> worklist = new ArrayDeque<>(indexToRuleMap.size() * 2);
    for (RuleHierarchyInfo rule : indexToRuleMap) {
      if (graph.outDegree(rule) == 0) {
        worklist.addFirst(rule); // Put leaves at the head.
      } else {
        worklist.addLast(rule); // Put non-leaves at the tail.
      }
    }
    while (!worklist.isEmpty()) {
      final RuleHierarchyInfo workitem = worklist.pollFirst(); // Always prefer the leaves.
      final Set<RuleHierarchyInfo> subrules = graph.successors(workitem);
      final int prevSize = subrules.size();
      final ArrayList<EndpointPair<RuleHierarchyInfo>> newEdges = new ArrayList<>();
      for (RuleHierarchyInfo subrule : subrules) {
        for (RuleHierarchyInfo subsubrule : graph.successors(subrule)) {
          if (!graph.hasEdgeConnecting(workitem, subsubrule)) {
            newEdges.add(EndpointPair.ordered(workitem, subsubrule));
          }
        }
      }
      for (EndpointPair<RuleHierarchyInfo> edge : newEdges) {
        if (graph.hasEdgeConnecting(edge)) {
          continue;
        }
        graph.putEdge(edge);
      }
      if (prevSize != graph.outDegree(workitem)) {
        graph.predecessors(workitem).forEach(worklist::addFirst);
      }
    }
    graph
        .nodes()
        .forEach(node -> node.setTransitiveSubRules(ImmutableSet.copyOf(graph.successors(node))));
  }

  private Multimap<RuleHierarchyInfo, RuleHierarchyInfo> reverseMultiMap(
      Multimap<RuleHierarchyInfo, RuleHierarchyInfo> map) {
    final Multimap<RuleHierarchyInfo, RuleHierarchyInfo> inverseDependencies =
        HashMultimap.create();
    map.entries().forEach(entry -> inverseDependencies.put(entry.getValue(), entry.getKey()));
    return inverseDependencies;
  }

  private Multimap<RuleHierarchyInfo, RuleHierarchyInfo> buildInitialSubruleGraph() {
    final Multimap<RuleHierarchyInfo, RuleHierarchyInfo> initialSubruleGraph =
        HashMultimap.create();
    for (RuleHierarchyInfo rule : indexToRuleMap) {
      for (String subrule : rule.getImmediateSubRuleNames()) {
        assert nameToRuleMap.get(subrule) != null : subrule;
        initialSubruleGraph.put(rule, nameToRuleMap.get(subrule));
      }
    }
    return initialSubruleGraph;
  }
}

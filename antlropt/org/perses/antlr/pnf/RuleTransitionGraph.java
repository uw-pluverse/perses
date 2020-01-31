package org.perses.antlr.pnf;

import org.jgrapht.Graph;
import org.jgrapht.alg.connectivity.KosarajuStrongConnectivityInspector;
import org.jgrapht.graph.DirectedMultigraph;
import org.jgrapht.io.DOTExporter;
import org.perses.antlr.ast.*;

import java.io.StringWriter;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.Function;

import static com.google.common.base.Preconditions.checkState;

public class RuleTransitionGraph {

  public static RuleTransitionGraph createForLeftmostTransition(ImmutableRuleDefMap grammar) {
    return create(grammar, seq -> seq.getChild(0));
  }

  public static RuleTransitionGraph createForRightmostTransition(ImmutableRuleDefMap grammar) {
    return create(grammar, seq -> seq.getChild(seq.getChildCount() - 1));
  }

  private static RuleTransitionGraph create(
      ImmutableRuleDefMap grammar, Function<PersesSequenceAst, AbstractPersesRuleElement> childSelector) {
    DirectedMultigraph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> graph =
        createGraph();
    for (RuleNameRegistry.RuleNameHandle rule : grammar.getParserRuleNames()) {
      graph.addVertex(rule);
    }
    for (Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> rule :
        grammar.getRuleDefinitions()) {
      final AbstractPersesRuleElement body = rule.getValue();
      RuleNameRegistry.RuleNameHandle ruleNameHandle = rule.getKey();
      checkState(!(body instanceof PersesAlternativeBlockAst), "%s : %s", ruleNameHandle, body);
      final AbstractPersesRuleElement edgeLabel = body;
      addEdge(graph, ruleNameHandle, edgeLabel, body, childSelector);
    }
    return new RuleTransitionGraph(graph);
  }

  private static DirectedMultigraph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>
      createGraph() {
    return new DirectedMultigraph<>(AbstractPersesRuleElement.class);
  }

  public List<Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> computeSccSet() {
    // The scc set here is just a view of the graph.
    return new KosarajuStrongConnectivityInspector<>(graph).getStronglyConnectedComponents();
  }

  DirectedMultigraph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> duplicateGraph(
      Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> scc) {
    DirectedMultigraph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> subgraph =
        createGraph();
    Set<RuleNameRegistry.RuleNameHandle> vertices = scc.vertexSet();
    for (RuleNameRegistry.RuleNameHandle node : vertices) {
      subgraph.addVertex(node);
    }
    Set<AbstractPersesRuleElement> edges = scc.edgeSet();
    for (AbstractPersesRuleElement edge : edges) {
      final RuleNameRegistry.RuleNameHandle source = scc.getEdgeSource(edge);
      final RuleNameRegistry.RuleNameHandle target = scc.getEdgeTarget(edge);
      subgraph.addEdge(source, target, edge);
    }
    return subgraph;
  }

  private static void addEdge(
      DirectedMultigraph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> graph,
      RuleNameRegistry.RuleNameHandle ruleName,
      final AbstractPersesRuleElement edgeLabel,
      AbstractPersesRuleElement ast,
      Function<PersesSequenceAst, AbstractPersesRuleElement> childSelector) {
    switch (ast.getTag()) {
      case ALTERNATIVE_BLOCK:
        for (int i = 0, size = ast.getChildCount(); i < size; ++i) {
          addEdge(graph, ruleName, edgeLabel, ast.getChild(i), childSelector);
        }
        return;
      case RULE_REF:
        {
          RuleNameRegistry.RuleNameHandle targetVertex =
              ((PersesRuleReferenceAst) ast).getRuleNameHandle();
          if (!ruleName.equals(targetVertex)) {
            graph.addEdge(ruleName, targetVertex, edgeLabel);
          }
          return;
        }
      case SEQUENCE:
        addEdge(
            graph,
            ruleName,
            edgeLabel,
            childSelector.apply((PersesSequenceAst) ast),
            childSelector);
        return;
    }
  }

  private final Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> graph;

  private RuleTransitionGraph(
      Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> graph) {
    this.graph = graph;
  }

  public String dottify() {
    DOTExporter<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> exporter =
        new DOTExporter<>(
            (RuleNameRegistry.RuleNameHandle v) -> Integer.toString(v.getId()),
            (RuleNameRegistry.RuleNameHandle v) -> v.get(),
            (AbstractPersesRuleElement e) -> e.getSourceCode());
    StringWriter writer = new StringWriter();
    exporter.exportGraph(graph, writer);
    return writer.toString();
  }

  public Graph<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> getGraph() {
    return graph;
  }
}

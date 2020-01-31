package org.perses.antlr.pnf;

import com.google.common.collect.HashMultimap;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.DefaultAstVisitor;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;

public class EliminateUnreachableRulePass extends AbstractPnfPass {

  private final String entryRuleName;

  public EliminateUnreachableRulePass(String entryRuleName) {
    this.entryRuleName = entryRuleName;
  }

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    HashSet<RuleNameRegistry.RuleNameHandle> usedRules = new HashSet<>();
    final HashSet<RuleNameRegistry.RuleNameHandle> visited = new HashSet<>();
    final ArrayDeque<RuleNameRegistry.RuleNameHandle> worklist = new ArrayDeque<>();
    RuleNameRegistry.RuleNameHandle rootRuleName =
        grammar
            .getOriginalGrammar()
            .getSymbolTable()
            .getRuleNameRegistry()
            .getOrThrow(entryRuleName);
    usedRules.add(rootRuleName);
    worklist.addLast(rootRuleName);
    while (worklist.size() > 0) {
      final RuleNameRegistry.RuleNameHandle name = worklist.pollLast();
      if (visited.contains(name)) {
        continue;
      } else {
        visited.add(name);
      }
      for (AbstractPersesRuleElement def : grammar.getRuleDefinition(name)) {
        RuleNameCollector collector = new RuleNameCollector();
        collector.preorder(def);
        usedRules.addAll(collector.usedRules);
        worklist.addAll(collector.usedRules);
      }
    }
    if (usedRules.isEmpty()) {
      return grammar;
    }
    MutableRuleDefMap mutable =
        grammar.createMutable();
    List<RuleNameRegistry.RuleNameHandle> unusedRuleNames =
        mutable.keySet().stream()
            .filter(name -> !usedRules.contains(name))
            .collect(Collectors.toList());
    for (RuleNameRegistry.RuleNameHandle unusedRuleName : unusedRuleNames) {
      mutable.removeAll(unusedRuleName);
    }
    return grammar.createWithParserDefs(mutable);
  }

  private static class RuleNameCollector extends DefaultAstVisitor {
    final HashSet<RuleNameRegistry.RuleNameHandle> usedRules = new HashSet<>();

    @Override
    protected void visit(PersesRuleReferenceAst ast) {
      usedRules.add(ast.getRuleNameHandle());
    }
  }
}

package org.perses.antlr.ast;

import com.google.common.collect.ImmutableSet;

import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;

public class RuleEpsilonComputer {

  public static EpsilonInfo computeEpsilonableRules(
      PersesGrammar grammar) {
    RuleEpsilonComputer computer = new RuleEpsilonComputer(grammar);
    computer.compute();
    ImmutableSet.Builder<AbstractPersesRuleDefAst> builder = ImmutableSet.builder();
    for (AbstractPersesRuleDefAst rule : grammar.getRules()) {
      if (computer.containsEpsilon(rule)) {
        builder.add(rule);
      }
    }
    return new EpsilonInfo(builder.build(), computer.getEpsilonableElements());
  }

  private final HashSet<AbstractPersesRuleElement> epsilonable = new HashSet<>();
  private final PersesGrammar grammar;

  private RuleEpsilonComputer(PersesGrammar grammar) {
    this.grammar = grammar;
  }

  public boolean containsEpsilon(AbstractPersesRuleDefAst rule) {
    return epsilonable.contains(rule.getBody());
  }

  public ImmutableSet<AbstractPersesRuleElement> getEpsilonableElements() {
    return ImmutableSet.copyOf(epsilonable);
  }

  public void compute() {
    final EpsilonComputingVisitor visitor = new EpsilonComputingVisitor();

    int prevSize;
    do {
      prevSize = epsilonable.size();
      List<AbstractPersesRuleDefAst> rules =
          grammar.getRules().stream()
              .filter(def -> !epsilonable.contains(def.getBody()))
              .collect(Collectors.toList());
      for (AbstractPersesRuleDefAst rule : rules) {
        final AbstractPersesRuleElement body = rule.getBody();
        visitor.postorder(body);
      }
    } while (prevSize < epsilonable.size());
  }

  private class EpsilonComputingVisitor extends DefaultAstVisitor {

    @Override
    protected void visit(PersesSequenceAst ast) {
      final int count = ast.getChildCount();
      for (int i = 0; i < count; ++i) {
        if (!epsilonable.contains(ast.getChild(i))) {
          return;
        }
      }
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesPlusAst ast) {
      if (epsilonable.contains(ast.getBody())) {
        epsilonable.add(ast);
      }
    }

    @Override
    protected void visit(PersesStarAst ast) {
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesOptionalAst ast) {
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesLexerSkipCommandAst ast) {
      if (epsilonable.contains(ast.getBody())) {
        epsilonable.add(ast);
      }
    }

    @Override
    protected void visit(PersesEpsilonAst ast) {
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesAlternativeBlockAst ast) {
      final int count = ast.getChildCount();
      for (int i = 0; i < count; ++i) {
        if (epsilonable.contains(ast.getChild(i))) {
          epsilonable.add(ast);
          break;
        }
      }
    }

    @Override
    protected void visit(PersesRuleReferenceAst ast) {
      AbstractPersesRuleDefAst def = grammar.getRuleDefinition(ast.getRuleNameHandle()).get();
      if (epsilonable.contains(def.getBody())) {
        epsilonable.add(ast);
      }
    }
  }
}

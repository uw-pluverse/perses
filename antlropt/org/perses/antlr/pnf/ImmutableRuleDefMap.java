package org.perses.antlr.pnf;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSetMultimap;
import com.google.common.collect.Iterables;
import org.perses.antlr.ast.*;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public final class ImmutableRuleDefMap {

  public static ImmutableRuleDefMap create(PersesGrammar originalGrammar) {
    ImmutableList<AbstractPersesRuleDefAst> rules = originalGrammar.getRules();
    ImmutableSetMultimap.Builder<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>
        parserRules = ImmutableSetMultimap.builder();
    ArrayList<AbstractPersesRuleDefAst> lexerRules = new ArrayList();
    for (AbstractPersesRuleDefAst rule : rules) {
      if (rule.isLexerRule()) {
        lexerRules.add(rule);
        continue;
      }
      RuleNameRegistry.RuleNameHandle name = rule.getRuleNameHandle();
      AbstractPersesRuleElement body = rule.getBody();
      if (body instanceof PersesAlternativeBlockAst) {
        body.foreachChildRuleElement(
            child -> {
              Preconditions.checkState(
                  !(child instanceof PersesAlternativeBlockAst), "name=%s, child=%s", name, child);
              parserRules.put(name, child);
            });
      } else {
        parserRules.put(name, body);
      }
    }
    return new ImmutableRuleDefMap(
        originalGrammar,
        lexerRules.stream()
            .sorted(Comparator.comparingInt(def -> def.getRuleNameHandle().getId()))
            .collect(ImmutableList.toImmutableList()),
        parserRules.build());
  }

  private final PersesGrammar originalGrammar;
  private final ImmutableList<AbstractPersesRuleDefAst> lexerRules;
  private final ImmutableSetMultimap<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>
      parserRules;

  private ImmutableRuleDefMap(
      PersesGrammar originalGrammar,
      ImmutableList<AbstractPersesRuleDefAst> lexerRules,
      ImmutableSetMultimap<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>
          parserRules) {
    this.originalGrammar = originalGrammar;
    this.lexerRules = lexerRules;
    this.parserRules = parserRules;
  }

  public ImmutableRuleDefMap createWithParserDefs(MutableRuleDefMap definitions) {
    return new ImmutableRuleDefMap(originalGrammar, lexerRules, definitions.toImmutable());
  }

  public Stream<Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>>
      entryStream() {
    return parserRules.entries().stream();
  }

  public PersesGrammar getOriginalGrammar() {
    return originalGrammar;
  }

  public ImmutableRuleDefMap project(final Set<RuleNameRegistry.RuleNameHandle> rulesToKeep) {
    ImmutableSetMultimap<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> projectedMap =
        rulesToKeep.stream()
            .filter(parserRules::containsKey)
            .collect(
                ImmutableSetMultimap.flatteningToImmutableSetMultimap(
                    name -> name, name -> parserRules.get(name).stream()));
    return new ImmutableRuleDefMap(originalGrammar, lexerRules, projectedMap);
  }

  public ImmutableSet<RuleNameRegistry.RuleNameHandle> getParserRuleNames() {
    return parserRules.keySet();
  }

  public ImmutableSet<Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>>
      getRuleDefinitions() {
    return parserRules.entries();
  }

  public ImmutableSet<AbstractPersesRuleElement> getRuleDefinition(
      RuleNameRegistry.RuleNameHandle name) {
    return parserRules.get(name);
  }

  public ImmutableSet<AbstractPersesRuleElement> getRuleDefinition(String name) {
    final RuleNameRegistry.RuleNameHandle handle =
        originalGrammar.getSymbolTable().getRuleNameRegistry().getOrThrow(name);
    return getRuleDefinition(handle);
  }

  public MutableRuleDefMap createMutable() {
    return new MutableRuleDefMap(parserRules);
  }

  public int size() {
    return parserRules.size();
  }

  private PersesGrammar sortedPersesGrammar;

  public synchronized PersesGrammar getPersesGrammar() {
    if (sortedPersesGrammar == null) {
      sortedPersesGrammar = computePersesGrammar();
    }
    return sortedPersesGrammar;
  }

  private PersesGrammar computePersesGrammar() {
    final ImmutableList.Builder<AbstractPersesRuleDefAst> builder = ImmutableList.builder();
    List<RuleNameRegistry.RuleNameHandle> ruleNames =
        parserRules.keySet().stream().sorted().collect(Collectors.toList());
    for (RuleNameRegistry.RuleNameHandle ruleName : ruleNames) {
      ImmutableList<AbstractPersesRuleElement> alternatives =
          ImmutableList.copyOf(parserRules.get(ruleName));
      AbstractPersesRuleElement body =
          alternatives.size() == 1
              ? Iterables.getOnlyElement(alternatives)
              : new PersesAlternativeBlockAst(alternatives);
      builder.add(PersesAstBuilder.createRuleDef(ruleName, body));
    }
    builder.addAll(lexerRules);
    return new PersesGrammar(
        originalGrammar.getGrammarName(), builder.build(), originalGrammar.getSymbolTable());
  }
}

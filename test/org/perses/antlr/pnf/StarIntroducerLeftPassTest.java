package org.perses.antlr.pnf;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.*;

import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class StarIntroducerLeftPassTest extends PnfLeftTestGrammar {

  private StarLeftIntroducerPass pass;

  @Before
  public void setup() {
    pass = new StarLeftIntroducerPass();
  }

  @Test
  public void testStarIntroducerLeftPass_pnf_grammar() {
    ImmutableRuleDefMap originalMap = ImmutableRuleDefMap.create(grammar);

    IndirectLeftRecursionEliminationPass indirectLeftRecursionEliminationPass =
        new IndirectLeftRecursionEliminationPass();
    ImmutableRuleDefMap result = indirectLeftRecursionEliminationPass.process(originalMap);

    result = pass.process(result);

    PersesGrammar persesGrammar = result.getPersesGrammar();

    AbstractPersesRuleDefAst b = persesGrammar.getRuleDefinition("b").get();
    AbstractPersesRuleElement bBody = b.getBody();

    assertThat(bBody.getChildCount()).isEqualTo(2);
    assertThat(bBody.getChild(0).getSourceCode()).isEqualTo("b_3");
    assertThat(bBody.getChild(1).getSourceCode()).isEqualTo("kleene_star__b_1");

    AbstractPersesRuleDefAst kleene_star__b_1 =
        persesGrammar.getRuleDefinition("kleene_star__b_1").get();
    AbstractPersesRuleElement kleene_star__b_1Body = kleene_star__b_1.getBody();
    assertThat(kleene_star__b_1Body.getSourceCode()).isEqualTo("b_2*");

    AbstractPersesRuleDefAst b_2 = persesGrammar.getRuleDefinition("b_2").get();
    AbstractPersesRuleElement b_2Body = b_2.getBody();
    assertThat(b_2Body.getSourceCode()).isEqualTo("c d");

    AbstractPersesRuleElement b_3 = persesGrammar.getRuleDefinition("b_3").get().getBody();
    assertThat(b_3.getChildCount()).isEqualTo(3);
    assertThat(b_3.getChild(0).getSourceCode()).isEqualTo("c d");
    assertThat(b_3.getChild(1).getSourceCode()).isEqualTo("d");
    assertThat(b_3.getChild(2).getSourceCode()).isEqualTo("d d");
  }

  @Test
  public void test_introduceStartsLeft_rule_refN_nonLeftRecursionShouldBeUnchanged() {
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromFile("rule_ref.g4");
    ImmutableRuleDefMap map = ImmutableRuleDefMap.create(grammar);
    MutableRuleDefMap mutable = map.createMutable();
    pass.introduceStars(
        mutable, grammar.getSymbolTable().getRuleNameRegistry().getOrThrow("start"));
    pass.introduceStars(mutable, grammar.getSymbolTable().getRuleNameRegistry().getOrThrow("a"));
    pass.introduceStars(mutable, grammar.getSymbolTable().getRuleNameRegistry().getOrThrow("b"));
    ImmutableRuleDefMap newMap = map.createWithParserDefs(mutable);
    {
      ImmutableList<AbstractPersesRuleElement> defs = findRuleDefinitions(newMap, "start");
      assertThat(defs).hasSize(2);
      assertThat(defs.stream().map(AbstractPersesAst::getSourceCode).collect(Collectors.toList()))
          .containsExactly("a b", "b");
    }
    {
      ImmutableList<AbstractPersesRuleElement> defs = findRuleDefinitions(newMap, "a");
      assertThat(defs).hasSize(1);
      assertThat(defs).containsExactly(PersesEpsilonAst.INSTANCE);
    }
    {
      ImmutableList<AbstractPersesRuleElement> defs = findRuleDefinitions(newMap, "b");
      assertThat(defs).hasSize(1);
      assertThat(defs.get(0).getSourceCode()).isEqualTo("ID");
    }
  }

  @Test
  public void test_introduceStarsLeft() {
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromFile("left_recursion.g4");
    ImmutableRuleDefMap map = ImmutableRuleDefMap.create(grammar);
    MutableRuleDefMap mutable = map.createMutable();
    pass.introduceStars(
        mutable, grammar.getSymbolTable().getRuleNameRegistry().getOrThrow("start"));

    ImmutableRuleDefMap newMap = map.createWithParserDefs(mutable);
    ImmutableSet<RuleNameRegistry.RuleNameHandle> ruleNames = newMap.getParserRuleNames();
    assertThat(
            ruleNames.stream()
                .map(RuleNameRegistry.RuleNameHandle::get)
                .collect(Collectors.toList()))
        .containsExactly("start_2", "id", "start", "kleene_star__start_1", "start_3");

    final RuleNameRegistry.RuleNameHandle name_start = findRuleName(ruleNames, "start");
    final RuleNameRegistry.RuleNameHandle name_id = findRuleName(ruleNames, "id");
    final RuleNameRegistry.RuleNameHandle name_start_2 = findRuleName(ruleNames, "start_2");
    final RuleNameRegistry.RuleNameHandle name_kleene_star__start_1 =
        findRuleName(ruleNames, "kleene_star__start_1");

    {
      ImmutableSet<AbstractPersesRuleElement> def = newMap.getRuleDefinition(name_id);
      assertThat(def).hasSize(1);
      String code = def.iterator().next().getSourceCode();
      assertThat(code).contains("hello");
      assertThat(code).contains("world");
    }
    {
      ImmutableSet<AbstractPersesRuleElement> defs =
          newMap.getRuleDefinition(name_kleene_star__start_1);
      assertThat(defs).hasSize(1);
      AbstractPersesRuleElement def = defs.asList().get(0);
      assertThat(def).isInstanceOf(PersesStarAst.class);
      assertThat(def.getChildCount()).isEqualTo(1);
      AbstractPersesRuleElement child = def.getChild(0);
      assertThat(child).isInstanceOf(PersesRuleReferenceAst.class);
      assertThat(child.getSourceCode()).isEqualTo("start_2");
    }
    {
      ImmutableSet<AbstractPersesRuleElement> defs = newMap.getRuleDefinition(name_start_2);
      assertThat(defs.stream().map(AbstractPersesAst::getSourceCode).collect(Collectors.toList()))
          .containsExactly("'()'", "'++'", "'--'", "'->' id", "'.' id", "'[]'");
    }
    {
      List<String> defs =
          newMap.getRuleDefinition(name_start).stream()
              .map(AbstractPersesAst::getSourceCode)
              .sorted()
              .collect(Collectors.toList());

      assertThat(defs).containsExactly("start_3 kleene_star__start_1");
    }
  }

  private static RuleNameRegistry.RuleNameHandle findRuleName(
      ImmutableRuleDefMap map, String nameToFind) {
    final RuleNameRegistry.RuleNameHandle name = findRuleName(map.getParserRuleNames(), nameToFind);
    return name;
  }

  private static ImmutableList<AbstractPersesRuleElement> findRuleDefinitions(
      ImmutableRuleDefMap map, String ruleName) {
    final RuleNameRegistry.RuleNameHandle handle = findRuleName(map, ruleName);
    return ImmutableList.copyOf(map.getRuleDefinition(handle));
  }

  private static RuleNameRegistry.RuleNameHandle findRuleName(
      Collection<RuleNameRegistry.RuleNameHandle> names, String nameToFind) {
    List<RuleNameRegistry.RuleNameHandle> result =
        names.stream().filter(n -> n.get().equals(nameToFind)).collect(Collectors.toList());
    assertThat(result).hasSize(1);
    return result.get(0);
  }
}

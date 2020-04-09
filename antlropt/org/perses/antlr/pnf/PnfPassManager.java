package org.perses.antlr.pnf;

import com.google.common.base.Stopwatch;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.flogger.FluentLogger;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import static com.google.common.base.Preconditions.checkArgument;

public final class PnfPassManager {

  public abstract static class Listener {
    protected void start(PersesGrammar grammar, String startRuleName) {}

    protected void beforePass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {}

    protected void afterPass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {}
  }

  public PersesGrammar process(PersesGrammar grammar, String startRuleName, Listener... listeners) {
    ImmutableRuleDefMap before = ImmutableRuleDefMap.create(grammar);
    ImmutableRuleDefMap after = before;
    ImmutableList<Listener> allListeners =
        ImmutableList.<Listener>builder().add(listeners).add(new LoggingListener()).build();
    allListeners.forEach(l -> l.start(grammar, startRuleName));
    for (int i = 0; i < 20; ++i) {
      for (AbstractPnfPass pass : createPasses(startRuleName)) {
        for (Listener listener : allListeners) {
          listener.beforePass(after, pass.getClass(), i);
        }
        after = pass.process(after);
        validateIntermediateGrammar(after, pass);
        for (Listener listener : allListeners) {
          listener.afterPass(after, pass.getClass(), i);
        }
      }
      if (after.getPersesGrammar().isEquivalent(before.getPersesGrammar())) {
        break;
      } else {
        before = after;
      }
    }
    return before.getPersesGrammar();
  }

  private static void validateIntermediateGrammar(
      ImmutableRuleDefMap grammar, AbstractPnfPass pass) {
    try {
      checkNoDuplicateDefs(grammar);
    } catch (Exception e) {
      throw new RuntimeException("Validation fails after pass " + pass.getClass(), e);
    }
  }

  private static void checkNoDuplicateDefs(ImmutableRuleDefMap gramamr) {
    final ImmutableSet<RuleNameRegistry.RuleNameHandle> parserRuleNames =
        gramamr.getParserRuleNames();
    for (RuleNameRegistry.RuleNameHandle ruleName : parserRuleNames) {
      final ImmutableList<AbstractPersesRuleElement> alternatives =
          ImmutableList.copyOf(gramamr.getRuleDefinition(ruleName));
      final int size = alternatives.size();
      for (int i = 0; i < size - 1; ++i) {
        final AbstractPersesRuleElement prev = alternatives.get(i);
        for (int j = i + 1; j < size; ++j) {
          final AbstractPersesRuleElement current = alternatives.get(j);
          if (prev.isEquivalent(current)) {
            final StringBuilder builder = new StringBuilder();
            builder.append("Duplicate alternatives are found. \n");
            builder.append("prev=" + prev.getSourceCode()).append("\n");
            builder.append("current=" + current.getSourceCode()).append("\n");
            builder.append("All alternatives: \n");
            for (AbstractPersesRuleElement alt : alternatives) {
              builder.append("  " + alt.getSourceCode()).append("\n");
            }
            throw new RuntimeException(builder.toString());
          }
          checkArgument(!prev.isEquivalent(current));
        }
      }
    }
  }

  private ArrayList<AbstractPnfPass> createPasses(String startRuleName) {
    ArrayList<AbstractPnfPass> result = new ArrayList<>();

    result.add(new QuantifiedAstNormalizationPass());

    result.add(new IndirectLeftRecursionEliminationPass());
    result.add(new StarLeftIntroducerPass());
    result.add(new PlusIntroducerLeftPass());
    result.add(new OptionalIntroducerPass());
    result.add(new AlternativeBlockOutliningPass());
    // TODO (#https://github.com/chengniansun/perses/issues/21). Enable InlineSingleUseAltRulePass pass.
    // -- messes with rule ordering / disambiguation in ANTLR4
    // result.add(new InlineSingleUseAltRulePass());

    // TODO: need to study why right recursion is hard to eliminate. Currently this is toooo slow.
    //    result.add(new IndirectRightRecursionEliminationPass());
    //    result.add(new StarRightIntroducerPass());
    //    result.add(new PlusIntroducerLeftPass());
    //    result.add(new OptionalIntroducerPass());

    result.add(new EliminateUnreachableRulePass(startRuleName));
    result.add(new DuplicateRuleEliminationPass(startRuleName));
    return result;
  }

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  private static class LoggingListener extends Listener {

    private Stopwatch stopwatch = Stopwatch.createUnstarted();

    @Override
    protected void start(PersesGrammar grammar, String startRuleName) {

      logger.atInfo().log(
          "Starting to process grammar %s with start rule %s",
          grammar.getGrammarName(), startRuleName);
    }

    @Override
    protected void beforePass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
      stopwatch.reset().start();
      logger.atInfo().log("Pass %s at iteration %s", passClass, iteration);
    }

    @Override
    protected void afterPass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
      logger.atInfo().log(
          "Pass %s takes %s seconds.", passClass, stopwatch.elapsed(TimeUnit.SECONDS));
    }
  }
}

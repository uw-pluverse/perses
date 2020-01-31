package org.perses.antlr.pnf;

import com.google.common.base.Stopwatch;
import com.google.common.collect.ImmutableList;
import com.google.common.flogger.FluentLogger;
import org.perses.antlr.ast.PersesGrammar;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

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

  private ArrayList<AbstractPnfPass> createPasses(String startRuleName) {
    ArrayList<AbstractPnfPass> result = new ArrayList<>();

    result.add(new QuantifiedAstNormalizationPass());

    result.add(new IndirectLeftRecursionEliminationPass());
    result.add(new StarLeftIntroducerPass());
    result.add(new PlusIntroducerLeftPass());
    result.add(new OptionalIntroducerPass());
    result.add(new AlternativeBlockOutliningPass());
    result.add(new InlineSingleUseAltRulePass());

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

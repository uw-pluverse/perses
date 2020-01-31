package org.perses.antlr.pnf;

import org.perses.antlr.RuleType;
import org.perses.antlr.ast.AstTag;

public final class PnfUtil {

  public static RuleType getRuleTypeIfQuantifiedOrThrow(AstTag tag) {
    switch (tag) {
      case STAR:
        return RuleType.KLEENE_STAR;
      case OPTIONAL:
        return RuleType.OPTIONAL;
      case PLUS:
        return RuleType.KLEENE_PLUS;
    }
    throw new RuntimeException("Unhandled tag " + tag);
  }
}

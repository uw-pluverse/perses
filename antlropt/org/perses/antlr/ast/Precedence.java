package org.perses.antlr.ast;

public enum Precedence {
  UNIT(100),

  QUANTIFIER(90),

  NOT(70),

  SEQUENCE(50),

  SKIP(30),

  ALTERNATIVE(10),

  RULE(0),

  NONE(Integer.MIN_VALUE);

  private final int precedence;

  Precedence(int precedence) {
    this.precedence = precedence;
  }

  public boolean gt(Precedence other) {
    return precedence > other.precedence;
  }

  public boolean lt(Precedence other) {
    return precedence < other.precedence;
  }
}

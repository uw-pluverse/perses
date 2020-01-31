package org.perses.antlr.pnf;

import com.google.common.base.MoreObjects;

public class Interval {
  final int leftInclusive;
  final int rightExclusive;

  public Interval(int leftInclusive, int rightExclusive) {
    assert leftInclusive >= 0;
    assert leftInclusive <= rightExclusive;
    this.leftInclusive = leftInclusive;
    this.rightExclusive = rightExclusive;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this)
        .add("left", leftInclusive)
        .add("right", rightExclusive)
        .toString();
  }

  public boolean contains(int i) {
    return leftInclusive <= i && i < rightExclusive;
  }

  public int length() {
    return rightExclusive - leftInclusive;
  }
}

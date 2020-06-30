/*
 * Copyright (C) 2018-2020 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
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

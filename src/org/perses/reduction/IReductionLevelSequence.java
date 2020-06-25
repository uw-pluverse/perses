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

package org.perses.reduction;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import org.perses.PersesRuntimeException;

import java.util.Iterator;

/** Created by neo on 12/30/16. */
public interface IReductionLevelSequence {

  void reset();

  boolean hasNext();

  int nextLevel();

  class ContinuousLevelSequence implements IReductionLevelSequence {

    private int current;

    @Override
    public boolean hasNext() {
      return true;
    }

    @Override
    public void reset() {
      this.current = 0;
    }

    @Override
    public int nextLevel() {
      return ++this.current;
    }
  }

  class FixedLevelSequence implements IReductionLevelSequence {

    private final ImmutableList<Integer> sequence;
    private final boolean continuousAfterFinish;
    private int current;
    private Iterator<Integer> iterator;

    public FixedLevelSequence(ImmutableList<Integer> sequence, boolean continuousAfterFinish) {
      sequence.forEach(i -> Preconditions.checkState(i > 0));
      this.sequence = sequence;
      this.iterator = this.sequence.iterator();
      this.continuousAfterFinish = continuousAfterFinish;
    }

    @Override
    public void reset() {
      this.iterator = this.sequence.iterator();
    }

    @Override
    public boolean hasNext() {
      return this.continuousAfterFinish || this.iterator.hasNext();
    }

    @Override
    public int nextLevel() {
      if (iterator.hasNext()) {
        this.current = iterator.next();
        return this.current;
      }
      if (this.continuousAfterFinish) return ++this.current;
      else {
        throw new PersesRuntimeException("No more levels.");
      }
    }
  }
}

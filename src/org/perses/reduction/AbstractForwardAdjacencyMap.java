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

import com.google.common.annotations.VisibleForTesting;
import it.unimi.dsi.fastutil.ints.Int2IntOpenHashMap;

public abstract class AbstractForwardAdjacencyMap {

  public static final int NOT_FOUND = Integer.MIN_VALUE;
  @VisibleForTesting static final int NUM_INDIRECTIONS_THRESHOLD = 10;

  public static AbstractForwardAdjacencyMap EMPTY =
      new AbstractForwardAdjacencyMap() {
        @Override
        public int getNearestForwardIndex(int lexemeId) {
          return NOT_FOUND;
        }

        @Override
        protected int getNumberOfIndirections() {
          return 0;
        }

        @Override
        protected void writeIndicesToMap(Int2IntOpenHashMap resultCollector) {}

        @Override
        protected int size() {
          return 0;
        }
      };

  public static AbstractForwardAdjacencyMap create(
      AbstractForwardAdjacencyMap existingIndex, int lexemeId, int newIndex) {
    if (existingIndex.getNumberOfIndirections() < NUM_INDIRECTIONS_THRESHOLD) {
      return new DelegatingForwardAdjacencyIndex(lexemeId, newIndex, existingIndex);
    }
    final Int2IntOpenHashMap map = new Int2IntOpenHashMap(existingIndex.size() + 1);
    existingIndex.writeIndicesToMap(map);
    map.put(lexemeId, newIndex);
    return new HashForwardAdjacencyIndex(map);
  }

  public abstract int getNearestForwardIndex(int lexemeId);

  protected abstract int size();

  protected abstract int getNumberOfIndirections();

  protected abstract void writeIndicesToMap(Int2IntOpenHashMap resultCollector);

  @VisibleForTesting
  static class HashForwardAdjacencyIndex extends AbstractForwardAdjacencyMap {

    private final Int2IntOpenHashMap map;

    private HashForwardAdjacencyIndex(Int2IntOpenHashMap map) {
      this.map = map;
    }

    @Override
    protected int getNumberOfIndirections() {
      return 0;
    }

    @Override
    public int getNearestForwardIndex(int lexemeId) {
      return map.getOrDefault(lexemeId, NOT_FOUND);
    }

    @Override
    protected void writeIndicesToMap(Int2IntOpenHashMap resultCollector) {
      resultCollector.putAll(map);
    }

    @Override
    protected int size() {
      return map.size();
    }
  }

  @VisibleForTesting
  static class DelegatingForwardAdjacencyIndex extends AbstractForwardAdjacencyMap {

    private final int lexemeId;
    private final int index;
    private final AbstractForwardAdjacencyMap delegate;
    private final int numberOfIndirections;
    private final int size;

    private DelegatingForwardAdjacencyIndex(
        int lexemeId, int index, AbstractForwardAdjacencyMap delegate) {
      this.lexemeId = lexemeId;
      this.index = index;
      this.delegate = delegate;
      this.numberOfIndirections = delegate.getNumberOfIndirections() + 1;
      this.size = delegate.size() + 1;
    }

    @Override
    public int getNumberOfIndirections() {
      return numberOfIndirections;
    }

    @Override
    public int getNearestForwardIndex(int lexemeId) {
      if (lexemeId == this.lexemeId) {
        return index;
      }
      return delegate.getNearestForwardIndex(lexemeId);
    }

    @Override
    protected void writeIndicesToMap(Int2IntOpenHashMap resultCollector) {
      delegate.writeIndicesToMap(resultCollector);
      resultCollector.put(lexemeId, index);
    }

    @Override
    protected int size() {
      return size;
    }
  }
}

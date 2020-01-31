/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import com.google.common.base.MoreObjects;
import org.perses.tree.spar.SparTree;

/** This is the information passed between different reduction passes. */
public final class ReductionState {

  private final SparTree sparTree;

  public ReductionState(SparTree sparTree) {
    this.sparTree = sparTree;
  }

  public final SparTree getSparTree() {
    return sparTree;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("tree-id", sparTree.getTreeId()).toString();
  }
}

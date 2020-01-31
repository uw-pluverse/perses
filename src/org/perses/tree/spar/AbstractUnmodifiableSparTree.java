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

package org.perses.tree.spar;

import org.perses.program.TokenizedProgram;

/**
 * The primary tree data structure for Perses program reduction. This interface serves as an
 * immutable information provider.
 */
public abstract class AbstractUnmodifiableSparTree {

  public final int getTokenCount() {
    return getProgramSnapshot().tokenCount();
  }

  public abstract TokenizedProgram getProgramSnapshot();

  public abstract AbstractSparTreeNode getRoot();

  public abstract String printTreeStructure();
}

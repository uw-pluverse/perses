/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import org.perses.spartree.AbstractSparTreeNode

/**
 * One hole and the subtrees whose content fills it, which are none when the hole is left
 * unfilled. The subtrees belong to the tree being reduced and stay there: a candidate spells a
 * copy of their content, which is what "reuse" means throughout Structure Form Conversion.
 *
 * Carrying the hole here is what lets a filling be a plain list: every entry says which hole it
 * fills.
 */
class FilledHole(
  val hole: TemplateElement.Hole,
  val subtreesToCopy: ImmutableList<AbstractSparTreeNode>,
) : Iterable<AbstractSparTreeNode> {
  override fun iterator(): Iterator<AbstractSparTreeNode> = subtreesToCopy.iterator()

  override fun toString() = "${hole.symbol.ruleName} <- $subtreesToCopy"

  companion object {
    /** The hole is left unfilled, which a `?` or `*` hole allows. */
    fun withoutSubtree(hole: TemplateElement.Hole) = FilledHole(hole, ImmutableList.of())

    fun withSubtree(
      hole: TemplateElement.Hole,
      subtree: AbstractSparTreeNode,
    ) = FilledHole(hole, ImmutableList.of(subtree))

    fun withSubtrees(
      hole: TemplateElement.Hole,
      subtreesToCopy: ImmutableList<AbstractSparTreeNode>,
    ) = FilledHole(hole, subtreesToCopy)
  }
}

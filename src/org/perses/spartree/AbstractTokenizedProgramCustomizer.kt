/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.spartree

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.util.Util.lazyAssert

abstract class AbstractTokenizedProgramCustomizer protected constructor(
  actionSet: AbstractActionSet<*>,
) {

  protected val targets = actionSet.targets
  protected val pathsToRootExcludingTargets = computePathsToRootExcludingTargets(targets)
  protected val builder = ImmutableList.builderWithExpectedSize<PersesToken>(1000)

  abstract fun visit(node: AbstractSparTreeNode): List<AbstractSparTreeNode>

  val result: ImmutableList<PersesToken>
    get() = builder.build()

  protected fun addTokenIntervalToResult(node: AbstractSparTreeNode) {
    val beginToken = node.beginToken
    val endToken = node.endToken
    if (beginToken == null) {
      lazyAssert { endToken == null }
    } else {
      lazyAssert { endToken != null }
      val sentinel = endToken!!.next
      var i = beginToken
      while (i !== sentinel) {
        lazyAssert({ !i!!.isPermanentlyDeleted }) {
          "The node has been deleted: $i"
        }
        builder.add(i!!.token)
        i = i.next
      }
    }
  }

  private fun computePathsToRootExcludingTargets(
    targets: ImmutableSet<AbstractSparTreeNode>,
  ): HashSet<AbstractSparTreeNode> {
    val result = HashSet<AbstractSparTreeNode>()
    for (target in targets) {
      var parent = target!!.parent
      while (parent != null) {
        val node = parent.asParserRule()
        parent = if (result.add(node)) {
          node.parent
        } else {
          break
        }
      }
    }
    return result
  }
}

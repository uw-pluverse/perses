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
package org.perses.reduction.reducer.latra.language

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.reduction.reducer.latra.LatraEmptyHoleBindingException
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.ConcreteToken
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole.HoleName
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.DeepCopyResult
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.toImmutableMap
import org.perses.util.transformToImmutableList

sealed class AbstractPatternElementBindings {
  abstract fun getHoleBinding(holeName: HoleName): ImmutableList<AbstractSparTreeNode>?

  fun getHoleBindingOrThrow(holeName: HoleName): ImmutableList<AbstractSparTreeNode> =
    getHoleBinding(holeName)
      ?: throw LatraEmptyHoleBindingException("No binding for the hole $holeName")

  fun getConcreteTokenBindingOrThrow(patternElement: ConcreteToken): LexerRuleSparTreeNode =
    getConcreteTokenBinding(patternElement)
      ?: error("No binding for the pattern element $patternElement")

  abstract fun getConcreteTokenBinding(patternElement: ConcreteToken): LexerRuleSparTreeNode?

  abstract fun containsHoleName(holeName: HoleName): Boolean

  data class NonScopedBindings(
    val holeBindings: ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>>,
    val concreteTokenBindings: ImmutableMap<ConcreteToken, LexerRuleSparTreeNode>,
  ) : AbstractPatternElementBindings() {
    // TODO(cnsun): need to be tested.
    fun portToAnotherTree(
      treeCopy: DeepCopyResult<SparTree, AbstractSparTreeNode>,
    ): NonScopedBindings =
      NonScopedBindings(
        holeBindings =
          holeBindings.entries.asSequence().toImmutableMap(
            keyFunc = { it.key },
            valueFunc = {
              it.value.transformToImmutableList { node ->
                treeCopy.getCopyNode(node)!!
              }
            },
          ),
        concreteTokenBindings =
          concreteTokenBindings.entries.asSequence().toImmutableMap(
            keyFunc = { it.key },
            valueFunc = {
              treeCopy.getCopyNode(it.value) as LexerRuleSparTreeNode
            },
          ),
      )

    override fun getConcreteTokenBinding(patternElement: ConcreteToken): LexerRuleSparTreeNode? =
      concreteTokenBindings[patternElement]

    override fun containsHoleName(holeName: HoleName): Boolean = holeBindings.containsKey(holeName)

    fun asSequence() = holeBindings.asSequence()

    override fun getHoleBinding(holeName: HoleName): ImmutableList<AbstractSparTreeNode>? =
      holeBindings[holeName]

    companion object {
      val EMPTY =
        NonScopedBindings(
          holeBindings = ImmutableMap.of(),
          concreteTokenBindings = ImmutableMap.of(),
        )
    }
  }

  class ScopedPatternElementBindings(
    private val outerScopedHoleBindings: AbstractPatternElementBindings,
  ) : AbstractPatternElementBindings() {
    private val currentBindings = mutableMapOf<HoleName, ImmutableList<AbstractSparTreeNode>>()

    override fun containsHoleName(holeName: HoleName): Boolean =
      currentBindings.containsKey(holeName) ||
        outerScopedHoleBindings.containsHoleName(holeName)

    override fun getConcreteTokenBinding(patternElement: ConcreteToken): LexerRuleSparTreeNode? =
      outerScopedHoleBindings.getConcreteTokenBinding(patternElement)

    fun createEmptyBinding(holeName: HoleName) {
      createNewBinding(holeName, binding = ImmutableList.of())
    }

    fun createNewBindings(
      newBindings: ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>>,
    ) {
      currentBindings.putAll(newBindings)
    }

    fun createNewBinding(
      holeName: HoleName,
      binding: Iterable<AbstractSparTreeNode>,
    ) {
//      require(!currentBindings.containsKey(holeName)) {
//        "The $holeName already exists in $currentBindings"
//      }
      currentBindings[holeName] = ImmutableList.copyOf(binding)
    }

    override fun getHoleBinding(holeName: HoleName): ImmutableList<AbstractSparTreeNode>? =
      if (currentBindings.containsKey(holeName)) {
        currentBindings[holeName]
      } else {
        outerScopedHoleBindings.getHoleBinding(holeName)
      }

    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .add("currentBindings", currentBindings)
        .add("outerScope", outerScopedHoleBindings)
        .toString()
  }
}

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
package org.perses.antlr.ast

import org.perses.util.toImmutableList

abstract class AbstractPersesRuleElement : AbstractPersesAst() {

  abstract override fun getChild(index: Int): AbstractPersesRuleElement

  fun childSequence(): Sequence<AbstractPersesRuleElement> {
    return IntRange(0, childCount - 1).asSequence().map { getChild(it) }
  }

  inline fun foreachChildRuleElement(consumer: (AbstractPersesRuleElement) -> Unit) {
    childSequence().forEach(consumer)
  }

  abstract fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement

  fun deepCopyTreeStructure(): AbstractPersesRuleElement {
    val newChildren = childSequence()
      .map { it.deepCopyTreeStructure() }
      .toImmutableList()
    return createWithNewChildren(newChildren)
  }

  fun shallowCopy(): AbstractPersesRuleElement {
    return createWithNewChildren(childSequence().toList())
  }

  fun isEquivalent(other: AbstractPersesRuleElement): Boolean {
    if (other.javaClass != javaClass) {
      return false
    }
    return if (!areChildrenEquivalent(other)) {
      false
    } else {
      extraEquivalenceTest(other)
    }
  }

  private fun areChildrenEquivalent(other: AbstractPersesRuleElement): Boolean {
    val size = childCount
    if (size != other.childCount) {
      return false
    }
    // Note that all Perses ASTs should normalize to a single form.
    for (i in 0 until size) {
      if (!getChildForEquivalenceChecking(i)
          .isEquivalent(other.getChildForEquivalenceChecking(i))
      ) {
        return false
      }
    }
    return true
  }

  protected open fun getChildForEquivalenceChecking(index: Int): AbstractPersesRuleElement {
    return getChild(index)
  }

  protected open fun extraEquivalenceTest(other: AbstractPersesRuleElement): Boolean {
    return true
  }
}

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

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.TransformDecision.NonDeleteTransformDecision
import org.perses.util.exhaustive

abstract class AstEdit {
  // TODO: replace Optional with nullable types.
  fun apply(ast: AbstractPersesRuleElement): NonDeleteTransformDecision {
    return apply(ast, isRoot = true)
  }

  private fun apply(
    ast: AbstractPersesRuleElement,
    isRoot: Boolean,
  ): NonDeleteTransformDecision {
    val size = ast.childCount
    val newChildren = ImmutableList.builder<AbstractPersesRuleElement>()
    var childrenChanged = false
    for (i in 0 until size) {
      val oldChild = ast.getChild(i)
      val decision = apply(oldChild, isRoot = false)
      when (decision) {
        is TransformDecision.Replace -> {
          childrenChanged = true
          newChildren.add(decision.newValue)
        }
        is TransformDecision.Keep -> {
          newChildren.add(decision.oldValue)
        }
        else -> TODO("$decision")
      }.exhaustive
    }
    return if (childrenChanged) {
      TransformDecision.Replace(
        oldValue = ast,
        newValue = internalApplyWithNewChildren(ast, newChildren.build(), isRoot),
      )
    } else {
      internalApply(ast, isRoot)
    }
  }

  protected abstract fun internalApply(
    element: AbstractPersesRuleElement,
    isRoot: Boolean,
  ): NonDeleteTransformDecision

  protected open fun internalApplyWithNewChildren(
    element: AbstractPersesRuleElement,
    children: ImmutableList<AbstractPersesRuleElement>,
    isRoot: Boolean,
  ): AbstractPersesRuleElement {
    val newElement = SmartAstConstructor.createWithNewChildren(element, children)
    return when (val decision = internalApply(newElement, isRoot)) {
      is TransformDecision.Keep -> {
        newElement
      }
      is TransformDecision.Replace -> {
        decision.newValue
      }
      else -> TODO(decision.toString())
    }
  }
}

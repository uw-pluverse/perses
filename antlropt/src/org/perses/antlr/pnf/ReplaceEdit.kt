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
package org.perses.antlr.pnf

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstEdit
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.TransformDecision

open class ReplaceEdit(
  val oldPredicate: (AbstractPersesRuleElement) -> Boolean,
  val newValueComputer: (oldValue: AbstractPersesRuleElement) -> AbstractPersesRuleElement,
) : AstEdit() {

  override fun internalApply(
    element: AbstractPersesRuleElement,
    isRoot: Boolean,
  ): TransformDecision.NonDeleteTransformDecision {
    return if (!oldPredicate(element)) {
      TransformDecision.Keep(element)
    } else {
      TransformDecision.Replace(oldValue = element, newValue = newValueComputer(element))
    }
  }

  override fun internalApplyWithNewChildren(
    element: AbstractPersesRuleElement,
    children: ImmutableList<AbstractPersesRuleElement>,
    isRoot: Boolean,
  ): AbstractPersesRuleElement {
    if (element.tag != AstTag.SEQUENCE) {
      return super.internalApplyWithNewChildren(element, children, isRoot)
    }
    val nonEpsilonChildren = children.asSequence()
      .filter { it.tag != AstTag.EPSILON }
      .flatMap {
        if (it is PersesSequenceAst) {
          it.children.asSequence()
        } else {
          sequenceOf(it)
        }
      }.toList()
    return when (nonEpsilonChildren.size) {
      children.size -> {
        super.internalApplyWithNewChildren(element, children, isRoot)
      }
      1 -> {
        nonEpsilonChildren.single()
      }
      else -> {
        (element as PersesSequenceAst).createWithNewChildren(nonEpsilonChildren)
      }
    }
  }
}

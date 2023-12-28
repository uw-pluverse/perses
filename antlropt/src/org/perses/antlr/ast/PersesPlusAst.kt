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

class PersesPlusAst(
  body: AbstractPersesRuleElement,
  isGreedy: Boolean,
) : AbstractPersesQuantifiedAst(body, isGreedy) {

  init {
    require(body !is PersesPlusAst)
  }

  override val operator: String
    get() = "+"

  override val tag: AstTag
    get() = AstTag.PLUS

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    check(newChildren.size == 1)
    return PersesPlusAst(newChildren[0], isGreedy)
  }

  companion object {
    @JvmStatic
    fun createGreedy(body: AbstractPersesRuleElement): PersesPlusAst {
      return PersesPlusAst(body, isGreedy = true)
    }

    @JvmStatic
    fun createNonGreedy(body: AbstractPersesRuleElement): PersesPlusAst {
      return PersesPlusAst(body, isGreedy = false)
    }
  }
}

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

class PersesStarAst(
  body: AbstractPersesRuleElement,
  isGreedy: Boolean,
) : AbstractPersesQuantifiedAst(body, isGreedy) {

  init {
    when (body.tag) {
      AstTag.EPSILON, AstTag.STAR, AstTag.PLUS, AstTag.OPTIONAL ->
        error("Kleene nodes are not allowed as body of star: ${body::class.java}")
      else -> Unit
    }
  }

  override val operator: String
    get() = "*"

  override val tag: AstTag
    get() = AstTag.STAR

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    check(newChildren.size == 1)
    return PersesStarAst(newChildren[0], isGreedy)
  }

  companion object {
    @JvmStatic
    fun createGreedy(body: AbstractPersesRuleElement): PersesStarAst {
      return PersesStarAst(body, true)
    }

    @JvmStatic
    fun createNonGreedy(body: AbstractPersesRuleElement): PersesStarAst {
      return PersesStarAst(body, false)
    }
  }
}

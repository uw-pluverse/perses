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
import org.perses.antlr.RuleHierarchyEntry

/** One element of a [RuleAlternativeTemplate]. */
sealed class TemplateElement {
  /** Whether this element, or any element nested in it, has to be filled with a structure. */
  abstract val containsHole: Boolean

  /**
   * The elements nested *directly* in this one, in the order they are spelled. Walking the whole
   * template, at any depth, is the caller's job: see [RuleAlternativeTemplate.holes].
   */
  open val immediateNestedElements: ImmutableList<TemplateElement>
    get() = ImmutableList.of()

  /** A terminal whose lexeme the grammar fixes, so no structure has to be reused for it. */
  class Constant(
    val lexeme: String,
  ) : TemplateElement() {
    override val containsHole = false

    override fun toString() = "'$lexeme'"
  }

  /** A symbol to be filled with structures reused from the subtree being converted. */
  class Hole(
    val symbol: RuleHierarchyEntry,
    val quantifier: Quantifier,
  ) : TemplateElement() {
    override val containsHole = true

    override fun toString() = "<${symbol.ruleName}>${quantifier.suffix}"
  }

  /**
   * A rule whose body was inlined into this template. PNF splits one alternative of the original
   * grammar over several generated rules; inlining them lets one template spell one alternative
   * of the original grammar.
   */
  class InlinedRule(
    val rule: RuleHierarchyEntry,
    override val immediateNestedElements: ImmutableList<TemplateElement>,
  ) : TemplateElement() {
    override val containsHole = immediateNestedElements.any { it.containsHole }

    override fun toString() = immediateNestedElements.joinToString(separator = " ")
  }
}

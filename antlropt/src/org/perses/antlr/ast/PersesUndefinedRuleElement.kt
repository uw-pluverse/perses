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
package org.perses.antlr.ast

import org.perses.util.ast.Indent
import java.io.PrintStream

/**
 * TODO(cnsun): to be tested.
 */
class PersesUndefinedRuleElement : AbstractPersesRuleElement() {
  override val tag: AstTag?
    get() = AstTag.UNDEFINED

  override val childCount: Int
    get() = 0

  @Deprecated("")
  override fun getChild(index: Int): AbstractPersesRuleElement {
    error("Unsupported.")
  }

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    stream.print("this_rule_is_undefined.")
  }

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    require(newChildren.isEmpty())
    return PersesUndefinedRuleElement()
  }

  // TODO(cnsun): make sure equivalence test works for this class.
  override fun extraEquivalenceTest(other: AbstractPersesRuleElement): Boolean {
    // this element is not equivalent to any element including itself.
    return false
  }
}

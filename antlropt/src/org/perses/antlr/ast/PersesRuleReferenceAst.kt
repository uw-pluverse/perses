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

import com.google.common.base.MoreObjects
import org.perses.antlr.RuleType
import org.perses.util.ast.Indent
import java.io.PrintStream

class PersesRuleReferenceAst private constructor(
  val ruleNameHandle: RuleNameRegistry.RuleNameHandle,
  val arguments: PersesActionAst?,
) : AbstractPersesRuleElement() {

  init {
    require(RuleType.isParserRule(ruleNameHandle.ruleName))
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    stream.print(ruleNameHandle.ruleName)
    if (arguments != null) {
      stream.append("[")
      arguments.toSourceCode(stream, Indent.FOUR_CHAR_EMPTY_INDENT, false)
      stream.append("]")
    }
  }

  @Deprecated("")
  override fun getChild(index: Int): AbstractPersesRuleElement {
    throw UnsupportedOperationException()
  }

  override val childCount: Int
    get() = 0

  override val extraLabelForTreeStructurePrinting: String
    get() = "rule_name=" + ruleNameHandle.ruleName

  override val tag: AstTag
    get() = AstTag.RULE_REF

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("ref", ruleNameHandle.ruleName).toString()
  }

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    return this
  }

  override fun extraEquivalenceTest(other: AbstractPersesRuleElement): Boolean {
    return ruleNameHandle.ruleName == (other as PersesRuleReferenceAst).ruleNameHandle.ruleName
  }

  companion object {
    @JvmStatic
    fun createWithArgs(
      ruleNameHandle: RuleNameRegistry.RuleNameHandle,
      arguments: PersesActionAst?,
    ): PersesRuleReferenceAst {
      return PersesRuleReferenceAst(ruleNameHandle, arguments)
    }

    @JvmStatic
    fun create(ruleNameHandle: RuleNameRegistry.RuleNameHandle): PersesRuleReferenceAst {
      return PersesRuleReferenceAst(ruleNameHandle, arguments = null)
    }
  }
}

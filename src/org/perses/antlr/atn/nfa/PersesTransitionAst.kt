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
package org.perses.antlr.atn.nfa

import com.google.common.base.MoreObjects
import org.antlr.v4.runtime.atn.AtomTransition
import org.antlr.v4.runtime.atn.NotSetTransition
import org.antlr.v4.runtime.atn.RangeTransition
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.atn.WildcardTransition
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AbstractPersesTerminalAst
import org.perses.antlr.ast.AstTag
import org.perses.util.ast.Indent
import java.io.PrintStream

class PersesTransitionAst(
  val atnTransition: Transition,
) : AbstractPersesTerminalAst() {

  init {
    require(!atnTransition.isEpsilon)
    require(
      when (atnTransition::class.java) {
        AtomTransition::class.java,
        RangeTransition::class.java,
        SetTransition::class.java,
        WildcardTransition::class.java,
        NotSetTransition::class.java,
        -> true
        else -> false
      },
    ) {
      "Unsupported transition class: ${atnTransition::class.java}"
    }
  }

  override fun extraEquivalenceTest(other: AbstractPersesRuleElement): Boolean {
    return other is PersesTransitionAst &&
      testTransitionEquivalence(atnTransition, other.atnTransition)
  }

  private fun testTransitionEquivalence(
    t1: Transition,
    t2: Transition,
  ): Boolean {
    if (t1::class.java != t2::class.java) {
      return false
    }
    // Use the class instead of the 'is' keyword, because NotSetTransistion is a subclass
    // of SetTransition
    return when (t1::class.java) {
      AtomTransition::class.java -> {
        val a1 = t1 as AtomTransition
        val a2 = t2 as AtomTransition
        a1.label == a2.label
      }
      NotSetTransition::class.java, SetTransition::class.java -> {
        val s1 = t1 as SetTransition
        val s2 = t2 as SetTransition
        s1.set == s2.set
      }
      RangeTransition::class.java -> {
        val r1 = t1 as RangeTransition
        val r2 = t2 as RangeTransition
        r1.from == r2.from && r1.to == r2.to
      }
      WildcardTransition::class.java -> true

      else -> error("Unreachable. ${t1::class.java}, ${t2::class.java}")
    }
  }

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    assert(newChildren.isEmpty())
    return PersesTransitionAst(atnTransition)
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    stream.print(atnTransition.toString())
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("transition", atnTransition).toString()
  }

  override val tag: AstTag
    get() = AstTag.UNKNOWN_TERMINAL_WITH_UNIT_PRECEDENCE
}

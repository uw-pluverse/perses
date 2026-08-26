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

import com.google.common.collect.ImmutableList
import org.perses.util.ast.Indent
import org.perses.util.toImmutableList
import java.io.PrintStream

class PersesAlternativeBlockAst(
  val alternatives: ImmutableList<AbstractPersesRuleElement>,
) : AbstractPersesRuleElement() {
  private val sortedAlternatives =
    alternatives.asSequence().sorted().toImmutableList()

  init {
    require(alternatives.size > 1) {
      alternatives
    }
    checkNoDuplicatesAmongAlternatives(alternatives)
    alternatives.forEach {
      // Quantified alternatives (`b? | c`) are legal ANTLR and must be representable here;
      // PNF forbids them, and QuantifiedAstNormalizationPass outlines them into aux rules.
      require(it.tag != AstTag.EPSILON && it.tag != AstTag.STAR) {
        "Cannot have epsilon or * as an alternative: $sourceCode"
      }
    }
  }

  override fun getChildForEquivalenceChecking(index: Int): AbstractPersesRuleElement =
    sortedAlternatives[index]

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    var first = true
    for (alt in alternatives) {
      if (first) {
        first = false
      } else {
        if (multiLineMode) {
          stream.print('\n')
          indent.printIndent(stream).append("| ")
        } else {
          stream.append(" | ")
        }
      }
      alt.toSourceCode(stream, indent, false)
    }
  }

  override val childCount: Int
    get() = alternatives.size

  override fun getChild(index: Int): AbstractPersesRuleElement = alternatives[index]

  override val tag = AstTag.ALTERNATIVE_BLOCK

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement = PersesAlternativeBlockAst(ImmutableList.copyOf(newChildren))

  override fun toString(): String = sourceCode

  companion object {
    @JvmStatic
    fun checkNoDuplicatesAmongAlternatives(alternatives: List<AbstractPersesRuleElement>) {
      val size = alternatives.size
      for (i in 0 until size - 1) {
        val prev = alternatives[i]
        for (j in i + 1 until size) {
          val current = alternatives[j]
          if (prev.isEquivalent(current)) {
            error(
              buildString {
                append("Duplicate alternatives are found. \n")
                append("prev=" + prev.sourceCode).append("\n")
                append("current=" + current.sourceCode).append("\n")
                append("All alternatives: \n")
                for (alt in alternatives) {
                  append("  " + alt.sourceCode).append("\n")
                }
              },
            )
          }
          require(!prev.isEquivalent(current))
        }
      }
    }
  }
}

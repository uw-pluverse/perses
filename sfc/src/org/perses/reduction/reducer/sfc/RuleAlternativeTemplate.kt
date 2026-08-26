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
import com.google.common.graph.Traverser
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.util.toImmutableList

/**
 * The shape of one alternative of a grammar rule, in the form a new subtree of that alternative
 * is built from.
 *
 * A template is a sequence of elements. A [TemplateElement.Constant] is a terminal whose lexeme
 * the grammar fixes, so it is spelled as it is. A [TemplateElement.Hole] is a symbol, so it is
 * filled with structures taken from the subtree being converted.
 *
 * For example, the alternative `'if' '(' expr ')' stmt` becomes the template
 * `'if' '(' <expr> ')' <stmt>`, and its two holes are filled with an expression and a statement
 * of that subtree.
 *
 * "Alternative" is meant in the grammar sense throughout: one branch of the rule's alternative
 * block (see [PersesAlternativeBlockAst.alternatives]), or the whole body when the rule has no
 * such block. It does not mean "another structure that could replace the subtree" -- that is
 * what a converter builds *from* these templates.
 */
class RuleAlternativeTemplate(
  val rule: RuleHierarchyEntry,
  /** The position of this alternative among the rule's alternatives, in grammar order. */
  val alternativeIndex: Int,
  /** The elements of this alternative, in the order they are spelled. */
  val elements: ImmutableList<TemplateElement>,
) {
  init {
    require(rule.ruleDef.isParserRule) {
      "Only a parser rule has alternatives to build a template for: ${rule.ruleName}"
    }
    // A body that is not an alternative block is the rule's single alternative.
    val alternativeCount =
      (rule.ruleDef.body as? PersesAlternativeBlockAst)?.alternatives?.size ?: 1
    require(alternativeIndex in 0 until alternativeCount) {
      "The alternative index $alternativeIndex is out of range for rule ${rule.ruleName}, " +
        "which has $alternativeCount alternative(s)."
    }
  }

  /**
   * The holes in the order they are spelled, which is the order the fillers are assigned in.
   */
  val holes: ImmutableList<TemplateElement.Hole> =
    Traverser
      .forTree<TemplateElement> { it.immediateNestedElements }
      .depthFirstPreOrder(elements)
      .filterIsInstance<TemplateElement.Hole>()
      .toImmutableList()

  /**
   * The constants in the order they are spelled. Every candidate built from this template spells
   * them, however its holes are filled, so they are the floor on a candidate's size.
   */
  val constants: ImmutableList<TemplateElement.Constant> =
    Traverser
      .forTree<TemplateElement> { it.immediateNestedElements }
      .depthFirstPreOrder(elements)
      .filterIsInstance<TemplateElement.Constant>()
      .toImmutableList()

  override fun toString(): String = elements.joinToString(separator = " ")
}

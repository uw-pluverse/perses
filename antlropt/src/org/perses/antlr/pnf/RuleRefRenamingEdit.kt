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

import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstEdit
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesRuleReferenceAst.Companion.createWithArgs
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision

class RuleRefRenamingEdit(
  private val oldName: RuleNameHandle,
  private val newName: RuleNameHandle,
) : AstEdit() {

  init {
    require(oldName.ruleName != newName.ruleName) {
      "$oldName, $newName"
    }
  }

  override fun internalApply(
    element: AbstractPersesRuleElement,
    isRoot: Boolean,
  ): TransformDecision.NonDeleteTransformDecision {
    if (element.tag !== AstTag.RULE_REF) {
      return TransformDecision.Keep(element)
    }
    val ref = element as PersesRuleReferenceAst
    val name = ref.ruleNameHandle
    return if (name != oldName) {
      TransformDecision.Keep(element)
    } else {
      TransformDecision.Replace(
        oldValue = element,
        newValue = createWithArgs(newName, ref.arguments),
      )
    }
  }

  companion object {

    fun renameDefMap(
      defMap: MutableGrammar,
      oldName: RuleNameHandle,
      newName: RuleNameHandle,
    ) {
      val edit = RuleRefRenamingEdit(oldName, newName)
      val ruleEditTriples = ArrayList<RuleEditTriple>()
      defMap.ruleNameAltPairSequence().forEach { (ruleName, alt) ->
        when (val decision = edit.apply(alt)) {
          is TransformDecision.Keep -> Unit // Do nothing
          is TransformDecision.Replace -> ruleEditTriples.add(
            RuleEditTriple(ruleName, alt, decision.newValue),
          )
          else -> TODO(decision.toString())
        }
      }
      ruleEditTriples.forEach { it.applyTo(defMap) }
    }
  }
}

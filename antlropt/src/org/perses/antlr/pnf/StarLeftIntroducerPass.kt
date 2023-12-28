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
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

class StarLeftIntroducerPass : AbstractStarIntroducerPass() {

  override fun classifyAndExtractPartsFromSequenceDef(
    ruleName: RuleNameHandle,
    sequenceDef: PersesSequenceAst,
    nonRecursivePartsInRecursiveDef: ArrayList<AbstractPersesRuleElement>,
    nonRecursiveDefs: LinkedHashSet<AbstractPersesRuleElement>,
  ) {
    val first = sequenceDef.firstChild
    val rest = sequenceDef.subsequence(1)
    if (first.tag === AstTag.RULE_REF &&
      (first as PersesRuleReferenceAst).ruleNameHandle == ruleName
    ) {
      nonRecursivePartsInRecursiveDef.add(rest)
    } else {
      nonRecursiveDefs.add(sequenceDef)
    }
  }

  override fun constructNewSequenceDef(
    nonRecursiveDef: AbstractPersesRuleElement,
    starRuleRef: PersesRuleReferenceAst,
  ): ImmutableList<AbstractPersesRuleElement> {
    return ImmutableList.of(nonRecursiveDef, starRuleRef)
  }
}

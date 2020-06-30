/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.antlr.pnf;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesSequenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Optional;

public class IndirectLeftRecursionEliminationPass extends AbstractIndirectRecursionEliminationPass {

  @Override
  protected RuleTransitionGraph createRuleTransitionGraph(ImmutableRuleDefMap grammar) {
    return RuleTransitionGraph.createForLeftmostTransition(grammar);
  }

  @VisibleForTesting
  protected Optional<RuleNameRegistry.RuleNameHandle> getRuleRefToInline(
      AbstractPersesRuleElement def) {
    Preconditions.checkArgument(def.getTag() != AstTag.ALTERNATIVE_BLOCK);
    return getFirstOrLastRuleRef(def, /*seekingFirst=*/ true);
  }

  protected final void inlineRuleRefIntoSequence(
      PersesSequenceAst originalSequence,
      AbstractPersesRuleElement toInline,
      ImmutableList.Builder<AbstractPersesRuleElement> newSeqBuilder) {
    Preconditions.checkState(originalSequence.getFirstChild().getTag() == AstTag.RULE_REF);
    if (toInline.getTag() == AstTag.SEQUENCE) {
      toInline.foreachChildRuleElement(newSeqBuilder::add);
    } else if (toInline.getTag() == AstTag.EPSILON) {
      // Do not inline epsilon, as it is empty.
    } else {
      newSeqBuilder.add(toInline);
    }
    for (int i = 1, size = originalSequence.getChildCount(); i < size; ++i) {
      newSeqBuilder.add(originalSequence.getChild(i));
    }
  }
}

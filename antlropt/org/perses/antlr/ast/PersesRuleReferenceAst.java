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
package org.perses.antlr.ast;

import com.google.common.base.MoreObjects;

import java.io.PrintStream;
import java.util.List;

public final class PersesRuleReferenceAst extends AbstractPersesRuleElement {

  private final RuleNameRegistry.RuleNameHandle ruleNameHandle;

  public PersesRuleReferenceAst(RuleNameRegistry.RuleNameHandle ruleNameHandle) {
    this.ruleNameHandle = ruleNameHandle;
  }

  public RuleNameRegistry.RuleNameHandle getRuleNameHandle() {
    return ruleNameHandle;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(ruleNameHandle.get());
  }

  @Deprecated
  @Override
  public AbstractPersesRuleElement getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Override
  protected String getExtraLabelForTreeStructurePrinting() {
    return "rule_name=" + ruleNameHandle.get();
  }

  @Override
  public AstTag getTag() {
    return AstTag.RULE_REF;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("ref", ruleNameHandle.get()).toString();
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return this;
  }

  @Override
  protected boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    return ruleNameHandle.get().equals(((PersesRuleReferenceAst) other).ruleNameHandle.get());
  }
}

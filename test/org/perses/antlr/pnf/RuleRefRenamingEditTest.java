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

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;

import java.util.Optional;

@RunWith(JUnit4.class)
public class RuleRefRenamingEditTest extends PnfLeftTestGrammar {

  @Test
  public void test() {
    AbstractPersesRuleDefAst ruleA = grammar.getRuleDefinition("a").get();
    RuleRefRenamingEdit edit = new RuleRefRenamingEdit(this.b, this.c);
    RuleRefCounterAstVisitor counter = new RuleRefCounterAstVisitor(this.b);
    counter.preorder(ruleA);
    Truth.assertThat(counter.getCount()).isEqualTo(1);
    Optional<AbstractPersesRuleElement> applied = edit.apply(ruleA.getBody());
    Truth.assertThat(applied.isPresent()).isTrue();

    RuleRefCounterAstVisitor anotherCounter = new RuleRefCounterAstVisitor(this.b);
    counter.preorder(applied.get());
    Truth.assertThat(anotherCounter.getCount()).isEqualTo(0);
  }
}

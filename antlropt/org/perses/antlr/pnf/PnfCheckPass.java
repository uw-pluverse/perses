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

import org.perses.antlr.RuleType;
import org.perses.antlr.ast.*;

import java.util.ArrayList;
import java.util.Map;

import static com.google.common.base.Preconditions.checkState;

public class PnfCheckPass extends AbstractPnfPass {

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    for (Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> rule :
        grammar.getRuleDefinitions()) {
      final RuleNameRegistry.RuleNameHandle name = rule.getKey();
      final AbstractPersesRuleElement body = rule.getValue();
      final RuleType ruleType = name.getType();
      switch (ruleType) {
        case KLEENE_PLUS:
          checkQuantifiedAst(body, AstTag.PLUS);
          break;
        case KLEENE_STAR:
          checkQuantifiedAst(body, AstTag.STAR);
          break;
        case OPTIONAL:
          checkQuantifiedAst(body, AstTag.OPTIONAL);
          break;
        case OTHER_RULE:
          checkNoQuantifiedDescendant(body);
          break;
        case TOKEN:
          break;
        default:
          throw new RuntimeException("Unhandled type" + rule + ", " + body.getSourceCode());
      }
    }
    return grammar;
  }

  private static class QuantifiedRuleDetector extends DefaultAstVisitor {
    private ArrayList<AbstractPersesQuantifiedAst> detectedNodes = new ArrayList<>();

    @Override
    protected void visit(PersesPlusAst ast) {
      detectedNodes.add(ast);
    }

    @Override
    protected void visit(PersesStarAst ast) {
      detectedNodes.add(ast);
    }

    @Override
    protected void visit(PersesOptionalAst ast) {
      detectedNodes.add(ast);
    }
  }

  private static class AltBlockRuleDetector extends DefaultAstVisitor {
    private final ArrayList<PersesAlternativeBlockAst> detectedNodes = new ArrayList<>();

    @Override
    protected void visit(PersesAlternativeBlockAst ast) {
      detectedNodes.add(ast);
    }
  }

  private static void checkNoQuantifiedDescendant(AbstractPersesRuleElement ast) {
    final QuantifiedRuleDetector detector = new QuantifiedRuleDetector();
    detector.preorder(ast);
    checkState(detector.detectedNodes.isEmpty(), detector.detectedNodes);
  }

  private static void checkQuantifiedAst(AbstractPersesRuleElement ast, AstTag expectedTag) {
    checkState(ast.getTag() == expectedTag);
    checkState(ast.getChildCount() == 1);
    AbstractPersesRuleElement child = ast.getChild(0);
    checkState(child.getTag() == AstTag.TERMINAL || child.getTag() == AstTag.RULE_REF);
  }
}

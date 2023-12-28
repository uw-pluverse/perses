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

import com.google.common.collect.ImmutableList

// TODO: to be refined and tested.
abstract class AbstractAstEditor {

  fun bottomUpApply(grammar: PersesGrammar): PersesGrammar {
    val rules = grammar.parserRules
    val ruleBuilder = ImmutableList
      .builderWithExpectedSize<PersesParserRuleAst>(rules.size)
    for (rule in rules) {
      val newBody = bottomUpApply(rule.body)
      if (newBody != null) {
        ruleBuilder.add(rule.copyWithNewBody(newBody))
      }
    }
    return grammar.copyWithNewParserRuleDefs(ruleBuilder.build())
  }

  fun bottomUpApply(ast: AbstractPersesRuleElement): AbstractPersesRuleElement? {
    val childCount = ast.childCount
    val newChildren = ImmutableList
      .builderWithExpectedSize<AbstractPersesRuleElement>(childCount)
    var nullChildFound = false
    for (i in 0 until childCount) {
      val origChild = ast.getChild(i)
      val newChild = bottomUpApply(origChild)
      if (newChild != null) {
        newChildren.add(newChild)
      } else {
        nullChildFound = true
      }
    }
    if (ast.tag == AstTag.ALTERNATIVE_BLOCK && nullChildFound) {
      newChildren.add(PersesEpsilonAst())
    }
    return dispatch(ast, newChildren.build())
  }

  fun dispatch(
    ast: AbstractPersesRuleElement,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return when (ast.tag) {
      AstTag.RULE_REF -> visit(ast as PersesRuleReferenceAst, newChildren)
      AstTag.ACTION -> visit(ast as PersesActionAst, newChildren)
      AstTag.ALTERNATIVE_BLOCK -> visit(ast as PersesAlternativeBlockAst, newChildren)
      AstTag.EPSILON -> visit(ast as PersesEpsilonAst, newChildren)
      AstTag.LEXER_CHAR_SET -> visit(ast as PersesLexerCharSet, newChildren)
      AstTag.LEXER_COMMAND -> visit(ast as PersesLexerCommandAst, newChildren)
      AstTag.NOT -> visit(ast as PersesNotAst, newChildren)
      AstTag.OPTIONAL -> visit(ast as PersesOptionalAst, newChildren)
      AstTag.STAR -> visit(ast as PersesStarAst, newChildren)
      AstTag.PLUS -> visit(ast as PersesPlusAst, newChildren)
      AstTag.SEQUENCE -> visit(ast as PersesSequenceAst, newChildren)
      AstTag.TERMINAL -> visit(ast as PersesTerminalAst, newChildren)
      AstTag.TOKEN_SET -> visit(ast as PersesTokenSetAst, newChildren)
      AstTag.LEXER_RANGE_OPERATOR -> visit(ast as PersesRangeAst, newChildren)
      AstTag.RULE_ELEMENT_OPTION -> visit(ast as PersesRuleElementOption, newChildren)
      AstTag.RULE_ELEMENT_LABEL -> visit(ast as PersesRuleElementLabel, newChildren)
      else -> throw RuntimeException("Unhandled type: $ast")
    }
  }

  protected open fun visit(
    ast: PersesTokenSetAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesTerminalAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesSequenceAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return when (newChildren.size) {
      0 -> null
      1 -> newChildren.single()
      else -> SmartAstConstructor.createForSequence(PersesSequenceAst.flatten(newChildren))
    }
  }

  protected open fun visit(
    ast: PersesPlusAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesStarAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesOptionalAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesNotAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesLexerCommandAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesLexerCharSet,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesEpsilonAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesAlternativeBlockAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return when (newChildren.size) {
      0 -> null
      1 -> newChildren.first()
      else -> SmartAstConstructor.createForAlternatives(newChildren)
    }
  }

  protected open fun visit(
    ast: PersesActionAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesRuleElementOption,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesRuleReferenceAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesRuleElementLabel,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }

  protected open fun visit(
    ast: PersesRangeAst,
    newChildren: ImmutableList<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement? {
    return ast.createWithNewChildren(newChildren)
  }
}

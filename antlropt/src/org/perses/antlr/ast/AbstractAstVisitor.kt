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

import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.util.exhaustive

abstract class AbstractAstVisitor {

  fun postorder(ast: AbstractPersesRuleElement) {
    ast.foreachChildRuleElement { postorder(it) }
    dispatch(ast)
  }

  fun preorder(ast: AbstractPersesAst) {
    dispatch(ast)
    ast.foreachChild { preorder(it) }
  }

  fun preorderGrammar(
    rules: Iterable<Map.Entry<RuleNameHandle, AbstractPersesRuleElement>>,
  ) {
    for ((_, value) in rules) {
      preorder(value)
    }
  }

  fun preorderGrammar(grammar: PersesGrammar) {
    grammar.flattenedAllRules
      .asSequence()
      .map(AbstractPersesRuleDefAst::body)
      .forEach { preorder(it) }
  }

  private fun dispatch(ast: AbstractPersesAst) {
    when (ast.tag) {
      AstTag.GRAMMAR -> visit(ast as PersesGrammar)
      AstTag.RULE_REF -> visit(ast as PersesRuleReferenceAst)
      AstTag.RULE_DEFINITION_LEXER -> visit(ast as PersesLexerRuleAst)
      AstTag.RULE_DEFINITION_PARSER -> visit(ast as PersesParserRuleAst)
      AstTag.RULE_DEFINITION_LEXER_FRAGMENT -> visit(ast as PersesFragmentLexerRuleAst)
      AstTag.ACTION -> visit(ast as PersesActionAst)
      AstTag.ALTERNATIVE_BLOCK -> visit(ast as PersesAlternativeBlockAst)
      AstTag.EPSILON -> visit(ast as PersesEpsilonAst)
      AstTag.LEXER_CHAR_SET -> visit(ast as PersesLexerCharSet)
      AstTag.LEXER_COMMAND -> visit(ast as PersesLexerCommandAst)
      AstTag.NOT -> visit(ast as PersesNotAst)
      AstTag.OPTIONAL -> visit(ast as PersesOptionalAst)
      AstTag.STAR -> visit(ast as PersesStarAst)
      AstTag.PLUS -> visit(ast as PersesPlusAst)
      AstTag.SEQUENCE -> visit(ast as PersesSequenceAst)
      AstTag.TERMINAL -> visit(ast as PersesTerminalAst)
      AstTag.TOKEN_SET -> visit(ast as PersesTokenSetAst)
      AstTag.LEXER_RANGE_OPERATOR -> visit(ast as PersesRangeAst)
      AstTag.RULE_ELEMENT_OPTION -> visit(ast as PersesRuleElementOption)
      AstTag.RULE_ELEMENT_LABEL -> visit(ast as PersesRuleElementLabel)
      else -> visitOthers(ast)
    }.exhaustive
  }

  protected abstract fun visit(ast: PersesTokenSetAst)
  protected abstract fun visit(ast: PersesTerminalAst)
  protected abstract fun visit(ast: PersesSequenceAst)
  protected abstract fun visit(ast: PersesPlusAst)
  protected abstract fun visit(ast: PersesStarAst)
  protected abstract fun visit(ast: PersesOptionalAst)
  protected abstract fun visit(ast: PersesNotAst)
  protected abstract fun visit(ast: PersesLexerCommandAst)
  protected abstract fun visit(ast: PersesLexerCharSet)
  protected abstract fun visit(ast: PersesEpsilonAst)
  protected abstract fun visit(ast: PersesAlternativeBlockAst)
  protected abstract fun visit(ast: PersesActionAst)
  protected abstract fun visit(ast: PersesRuleElementOption)
  protected abstract fun visit(ast: PersesFragmentLexerRuleAst)
  protected abstract fun visit(ast: PersesParserRuleAst)
  protected abstract fun visit(ast: PersesLexerRuleAst)
  protected abstract fun visit(ast: PersesRuleReferenceAst)
  protected abstract fun visit(ast: PersesGrammar)
  protected abstract fun visit(ast: PersesRuleElementLabel)
  protected abstract fun visit(ast: PersesRangeAst)

  protected open fun visitOthers(ast: AbstractPersesAst) {
    error("Unhandled type: $ast")
  }
}

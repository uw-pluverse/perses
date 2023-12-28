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

import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.DefaultAstVisitor
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.util.exhaustive
import java.lang.RuntimeException

class PnfCheckPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    for (rule in grammar.flattenedAllRuleSequence()) {
      val name = rule.ruleNameHandle
      if (RuleType.isLexerRule(name.ruleName)) {
        continue
      }
      val body = rule.body

      try {
        when (body.tag) {
          AstTag.PLUS -> checkQuantifiedAst(body, AstTag.PLUS)
          AstTag.STAR -> checkQuantifiedAst(body, AstTag.STAR)
          AstTag.OPTIONAL -> checkQuantifiedAst(body, AstTag.OPTIONAL)
          AstTag.ALTERNATIVE_BLOCK -> checkAltBlock(body)
          AstTag.SEQUENCE -> checkSequenceAst(body)
          else -> checkNoQuantifiedDescendant(body)
        }.exhaustive
      } catch (e: Exception) {
        throw RuntimeException("Checking $name failed.", e)
      }
    }
    return grammar
  }

  private fun checkSequenceAst(body: AbstractPersesRuleElement) {
    body.foreachChildRuleElement {
      check(it !is PersesAlternativeBlockAst)
      check(it !is AbstractPersesQuantifiedAst)
    }
  }

  private fun checkAltBlock(body: AbstractPersesRuleElement) {
    check(body.tag == AstTag.ALTERNATIVE_BLOCK)
    body.foreachChildRuleElement {
      check(it is PersesTerminalAst || it is PersesRuleReferenceAst)
    }
  }

  internal class QuantifiedRuleDetector : DefaultAstVisitor() {
    internal val detectedNodes = ArrayList<AbstractPersesQuantifiedAst>()
    override fun visit(ast: PersesPlusAst) {
      detectedNodes.add(ast)
    }

    override fun visit(ast: PersesStarAst) {
      detectedNodes.add(ast)
    }

    override fun visit(ast: PersesOptionalAst) {
      detectedNodes.add(ast)
    }
  }

  private class AltBlockRuleDetector : DefaultAstVisitor() {
    private val detectedNodes = ArrayList<PersesAlternativeBlockAst>()
    override fun visit(ast: PersesAlternativeBlockAst) {
      detectedNodes.add(ast)
    }
  }

  companion object {

    private fun checkNoQuantifiedDescendant(ast: AbstractPersesRuleElement) {
      val detector = QuantifiedRuleDetector()
      detector.preorder(ast)
      check(detector.detectedNodes.isEmpty()) { detector.detectedNodes }
    }

    private fun checkQuantifiedAst(ast: AbstractPersesRuleElement, expectedTag: AstTag) {
      check(ast.tag === expectedTag)
      check(ast.childCount == 1)
      val child = ast.getChild(0)
      check(child.tag === AstTag.TERMINAL || child.tag === AstTag.RULE_REF) { ast }
    }
  }
}

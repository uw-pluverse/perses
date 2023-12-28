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
import org.perses.antlr.ast.AbstractPersesLexerRuleAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.DefaultAstVisitor
import org.perses.antlr.ast.LexerRuleList
import org.perses.antlr.ast.PersesLexerRuleAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision

class OutlineImplicitTokenDefPass : AbstractPnfPass() {
  override fun processGrammar(grammar: GrammarPair): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val mutableParserRules = MutableGrammar.createParserRulesFrom(parserGrammar)
    val lexerGrammar = LexerGrammarPair.createFrom(grammar)
    val edits = mutableListOf<RuleEditTriple>()
    mutableParserRules.ruleNameAltPairSequence().forEach { (name, alt) ->
      val edit = OutlineImplicitTokenDefEdit(
        hostRuleName = name,
        lexerGrammar,
      )
      when (val decision = edit.apply(alt)) {
        is TransformDecision.Keep -> Unit // do nothing.
        is TransformDecision.Replace ->
          edits.add(
            RuleEditTriple(
              name,
              decision.oldValue,
              newDef = decision.newValue,
            ),
          )
        else -> error("Unhandled decision: $decision")
      }
    }
    edits.forEach { it.applyTo(mutableParserRules) }
    val newParserGrammar = parserGrammar.copyWithNewParserRuleDefs(
      mutableParserRules.toParserRuleAstList(),
    )
    return grammar.withNewParserAndExtraLexerRules(
      newParserGrammar,
      lexerGrammar.newLexerRules,
    )
  }

  internal class LexerGrammarPair(
    val combinedLexerGrammar: LexerRuleList,
    val separateLexerGrammar: LexerRuleList?,
  ) {

    val newLexerRules = mutableListOf<PersesLexerRuleAst>()

    fun allAsSequence(): Sequence<AbstractPersesLexerRuleAst> {
      val separateLexerGrammarSequence = separateLexerGrammar?.flattenedLexerRules?.asSequence()
        ?: sequenceOf<AbstractPersesLexerRuleAst>()
      return combinedLexerGrammar.flattenedLexerRules.asSequence() +
        separateLexerGrammarSequence +
        newLexerRules.asSequence()
    }

    fun getOrCreateLexerRule(
      hostRuleName: RuleNameHandle,
      implicitTokenDef: PersesTerminalAst,
    ): RuleNameHandle {
      val existingRule = allAsSequence().singleOrNull { lexerRule ->
        lexerRule.body.isEquivalent(implicitTokenDef)
      }
      if (existingRule != null) {
        return existingRule.ruleNameHandle
      }
      val newRuleName = hostRuleName.createAuxiliaryRuleName(RuleType.TOKEN)
      val newRuleDef = PersesLexerRuleAst(
        ruleNameHandle = newRuleName,
        body = implicitTokenDef.deepCopyTreeStructure(),
      )
      newLexerRules.add(newRuleDef)
      return newRuleName
    }

    companion object {
      fun createFrom(grammar: GrammarPair): LexerGrammarPair {
        return LexerGrammarPair(
          grammar.parserGrammar!!.lexerRules,
          grammar.lexerGrammar?.lexerRules,
        )
      }
    }
  }

  internal class OutlineImplicitTokenDefEdit(
    val hostRuleName: RuleNameHandle,
    val lexerGrammarPair: LexerGrammarPair,
  ) : ReplaceEdit(
    oldPredicate = { old -> old is PersesTerminalAst && old.isStringLiteral() },
    newValueComputer = { old ->
      val tokenDefName = lexerGrammarPair.getOrCreateLexerRule(
        hostRuleName = hostRuleName,
        implicitTokenDef = old as PersesTerminalAst,
      )
      PersesTerminalAst.createTokenReference(tokenDefName.ruleName)
    },
  )

  internal class ImplicitTokenDefCollector : DefaultAstVisitor() {
    val implicitDefs = mutableListOf<PersesTerminalAst>()
    override fun visit(ast: PersesTerminalAst) {
      if (ast.isStringLiteral()) {
        implicitDefs.add(ast)
      }
    }

    companion object {

      fun collectImplicitTokenDefs(ast: AbstractPersesRuleElement): List<PersesTerminalAst> {
        val collector = ImplicitTokenDefCollector()
        collector.postorder(ast)
        return collector.implicitDefs
      }
    }
  }
}

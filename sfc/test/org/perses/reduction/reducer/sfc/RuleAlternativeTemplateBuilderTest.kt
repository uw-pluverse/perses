/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import com.google.common.graph.Traverser
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.reduction.reducer.sfc.SfcTestUtility.templatesOfRule

@RunWith(JUnit4::class)
class RuleAlternativeTemplateBuilderTest : AbstractSfcTestWithGeneratedFacade() {
  private fun createToyFacade(enablePnfNormalization: Boolean): AbstractParserFacade =
    createFacade(
      grammarName = if (enablePnfNormalization) "TemplatePnf" else "TemplateOrig",
      parserRules =
        """
        start : stmt+ EOF ;
        stmt : expr ';' | 'if' '(' expr ')' stmt ;
        expr : ID op ID | ID | '(' expr ')' ;
        op : '+' | '-' ;
        """.trimIndent(),
      enablePnfNormalization = enablePnfNormalization,
    )

  private fun templatesOf(
    facade: AbstractParserFacade,
    ruleName: String,
  ): List<RuleAlternativeTemplate> = facade.templatesOfRule(ruleName)

  @Test
  fun templatesSpellTheProductionsOfTheRule() {
    val facade = createToyFacade(enablePnfNormalization = false)

    assertThat(templatesOf(facade, "stmt").map { it.toString() })
      .containsExactly("<expr> ';'", "'if' '(' <expr> ')' <stmt>")
      .inOrder()
  }

  @Test
  fun alternativeIndexFollowsGrammarOrder() {
    val facade = createToyFacade(enablePnfNormalization = false)

    assertThat(templatesOf(facade, "stmt").map { it.alternativeIndex })
      .containsExactly(0, 1)
      .inOrder()
  }

  @Test
  fun constantOnlyRuleIsSpelledOutSoThatItNeedsNoReuse() {
    val facade = createToyFacade(enablePnfNormalization = false)

    // `op` derives '+' and '-' only. Without spelling it out, the production would be usable
    // only when the input happens to contain an `op` node to reuse. The hole variant stays as
    // well, because reusing the input's own operator is just as valid.
    assertThat(templatesOf(facade, "expr").map { it.toString() })
      .containsExactly(
        "<ID> <op> <ID>",
        "<ID> '+' <ID>",
        "<ID> '-' <ID>",
        "<ID>",
        "'(' <expr> ')'",
      ).inOrder()
  }

  @Test
  fun holesAreListedInTheOrderTheyAreSpelled() {
    val facade = createToyFacade(enablePnfNormalization = false)
    val ifStatement = templatesOf(facade, "stmt").single { it.alternativeIndex == 1 }

    assertThat(
      ifStatement.holes.map { it.symbol.ruleName },
    ).containsExactly("expr", "stmt").inOrder()
    assertThat(
      ifStatement.holes.map { it.quantifier },
    ).containsExactly(Quantifier.EXACTLY_ONE, Quantifier.EXACTLY_ONE)
  }

  @Test
  fun theConstantsAreListedInTheOrderTheyAreSpelled() {
    val facade = createToyFacade(enablePnfNormalization = false)
    val statements = templatesOf(facade, "stmt")

    assertThat(statements.map { template -> template.constants.map { it.lexeme } })
      .containsExactly(listOf(";"), listOf("if", "(", ")"))
      .inOrder()
  }

  @Test
  fun originalAlternativesAreRecoveredFromThePnfGeneratedRules() {
    val facade = createToyFacade(enablePnfNormalization = true)
    val templates = templatesOf(facade, "stmt")

    // PNF rewrites `stmt` into a quantified prefix plus generated rules, and inlining them
    // spells the `if` alternative again. The assertion names no generated rule: their names and
    // numbering are an artifact of the PNF passes, so pinning them here would turn any change to
    // those passes into a failure of this test.
    assertThat(templates.map { constantLexemesOf(it) }).contains(listOf("if", "(", ")", ";"))
    assertThat(
      templates.first { constantLexemesOf(it) == listOf("if", "(", ")", ";") }.holes,
    ).isNotEmpty()
  }

  /** The lexemes the template spells itself, i.e. the ones no structure has to be reused for. */
  private fun constantLexemesOf(template: RuleAlternativeTemplate): List<String> =
    Traverser
      .forTree<TemplateElement> { it.immediateNestedElements }
      .depthFirstPreOrder(template.elements)
      .filterIsInstance<TemplateElement.Constant>()
      .map { it.lexeme }

  @Test
  fun generatedRuleNamesAreRecognizedWithoutHardCodingAnyGrammar() {
    val facade = createToyFacade(enablePnfNormalization = true)
    val hierarchy = facade.ruleHierarchy

    assertThat(
      hierarchy.ruleList
        .filter {
          RuleAlternativeTemplateBuilder.isPnfGeneratedRule(
            it,
          )
        }.map { it.ruleName },
    ).isNotEmpty()
    assertThat(
      RuleAlternativeTemplateBuilder.isPnfGeneratedRule(
        hierarchy.getRuleHierarchyEntryWithNameOrThrow("stmt"),
      ),
    ).isFalse()
  }

  @Test
  fun aTemplateRejectsAnAlternativeIndexOutOfRange() {
    val facade = createToyFacade(enablePnfNormalization = false)
    val statement = facade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("stmt")
    val template = templatesOf(facade, "stmt").first()

    // `stmt` has two alternatives, so 2 and -1 are both out of range.
    assertThrows(IllegalArgumentException::class.java) {
      RuleAlternativeTemplate(statement, alternativeIndex = 2, elements = template.elements)
    }
    assertThrows(IllegalArgumentException::class.java) {
      RuleAlternativeTemplate(statement, alternativeIndex = -1, elements = template.elements)
    }
  }

  @Test
  fun aTemplateRejectsALexerRule() {
    val facade = createToyFacade(enablePnfNormalization = false)
    val identifier = facade.ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow("ID")

    assertThrows(IllegalArgumentException::class.java) {
      RuleAlternativeTemplate(identifier, alternativeIndex = 0, elements = ImmutableList.of())
    }
  }

  @Test
  fun templatesAreBuiltForEveryRuleOfARealGrammar() {
    val facade = PnfCParserFacade()
    val builder = RuleAlternativeTemplateBuilder(facade)
    val parserRules = facade.ruleHierarchy.ruleList.filter { it.ruleDef.isParserRule }

    // Every template checks its own rule and alternative index while being constructed, so
    // building all of them exercises those invariants over a whole real grammar.
    val templates = parserRules.flatMap { builder.templatesOf(it) }

    assertThat(parserRules).isNotEmpty()
    assertThat(templates).isNotEmpty()
    templates.forEach { assertThat(it.alternativeIndex).isAtLeast(0) }
    assertThat(templates.count { it.holes.isNotEmpty() }).isGreaterThan(0)
  }
}

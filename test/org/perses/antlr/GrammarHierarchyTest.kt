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
package org.perses.antlr

import com.google.common.base.Function
import com.google.common.collect.ImmutableList
import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarHierarchy.Companion.createFromString
import org.perses.antlr.GrammarTestingUtility.readAntlrFileToString
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.grammar.c.CParserFacade
import java.io.ByteArrayInputStream
import java.nio.charset.StandardCharsets
import java.nio.file.Paths
import java.util.TreeSet

@RunWith(JUnit4::class)
class GrammarHierarchyTest {

  @Test
  fun testParsingCGrammar() {
    val grammarFileContent = readAntlrFileToString("C.g4")
    val grammar = AntlrGrammarParser.loadAntlrGrammarFromInputStream(
      ByteArrayInputStream(grammarFileContent.toByteArray(StandardCharsets.UTF_8)),
    )
    assertThat(grammar.rules.keys)
      .containsExactlyElementsIn(RULE_NAMES_IN_ORIGINAL_C_PARSER)
      .inOrder()
    assertThat(grammar.rules.values.map { it.name }.toList())
      .containsExactlyElementsIn(RULE_NAMES_IN_ORIGINAL_C_PARSER)
      .inOrder()
  }

  @Test
  fun testSubruleCompatibilityChecking() {
    val hierarchy = CParserFacade().ruleHierarchy
    val primaryRule = hierarchy.getRuleHierarchyEntryWithNameOrThrow("primaryExpression")
    assertThat(primaryRule.ruleName).isEqualTo("primaryExpression")
    assertThat(hierarchy.getRuleHierarchyEntryWithNameOrThrow("primaryExpression"))
      .isEqualTo(primaryRule)
    val expressionRule = hierarchy.getRuleHierarchyEntryWithNameOrThrow("expression")
    assertThat(expressionRule.isSuperOf(primaryRule)).isTrue()
    assertThat(primaryRule.isSuperOf(expressionRule)).isFalse()
    val genericSelection = hierarchy.getRuleHierarchyEntryWithNameOrThrow("genericSelection")
    assertThat(primaryRule.isSuperOf(genericSelection)).isTrue()
    assertThat(expressionRule.isSuperOf(genericSelection)).isTrue()
    assertThat(genericSelection.isSuperOf(expressionRule)).isFalse()
    val declaration = hierarchy.getRuleHierarchyEntryWithNameOrThrow("declaration")
    assertThat(declaration.isSuperOf(primaryRule)).isFalse()
    assertThat(primaryRule.isSuperOf(declaration)).isFalse()

    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  @Test
  fun testSubruleExtractionForStar() {
    val hierarchy = createFromFile("subrule_star.g4")
    val start = hierarchy.getRuleHierarchyEntryWithNameOrThrow("start")
    val a = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
    val b = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
    assertThat(start.transitiveSubRules).containsExactly(a, b)
    assertThat(a.transitiveSubRules).containsExactly(b)
    assertThat(b.transitiveSubRules).isEmpty()

    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  @Test
  fun testSubruleExtractionForPlus() {
    val hierarchy = createFromFile("subrule_plus.g4")
    val start = hierarchy.getRuleHierarchyEntryWithNameOrThrow("start")
    val a = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
    val b = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
    assertThat(start.transitiveSubRules).containsExactly(a)
    assertThat(a.transitiveSubRules).isEmpty()
    assertThat(b.transitiveSubRules).isEmpty()

    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  @Test
  fun testSubruleExtractionForOptional() {
    val hierarchy = createFromFile("subrule_optional.g4")
    val start = hierarchy.getRuleHierarchyEntryWithNameOrThrow("start")
    val a = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
    val b = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
    assertThat(start.transitiveSubRules).containsExactly(a, b)
    assertThat(a.transitiveSubRules).containsExactly(b)
    assertThat(b.transitiveSubRules).isEmpty()

    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  @Test
  fun testSubruleExtractionForSequence() {
    val hierarchy = createFromFile("subrule_sequence.g4")
    val start = hierarchy.getRuleHierarchyEntryWithNameOrThrow("start")
    val a = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
    val b = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
    val c = hierarchy.getRuleHierarchyEntryWithNameOrThrow("c")
    val d = hierarchy.getRuleHierarchyEntryWithNameOrThrow("d")
    assertThat(start.transitiveSubRules).containsExactly(a, b, c, d)
    assertThat(a.transitiveSubRules).containsExactly(b)
    assertThat(b.transitiveSubRules).isEmpty()
    assertThat(c.transitiveSubRules).containsExactly(d)
    assertThat(d.transitiveSubRules).isEmpty()

    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  @Test
  fun testSubruleExtractionForAlternative() {
    val hierarchy = createFromFile("subrule_alternative.g4")
    val start = hierarchy.getRuleHierarchyEntryWithNameOrThrow("start")
    val a = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
    val b = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
    val c = hierarchy.getRuleHierarchyEntryWithNameOrThrow("c")
    val d = hierarchy.getRuleHierarchyEntryWithNameOrThrow("d")
    val id = hierarchy.getRuleHierarchyEntryWithNameOrThrow("ID")
    assertThat(start.transitiveSubRules).containsExactly(a, b, c, d, id)
    assertThat(a.transitiveSubRules).containsExactly(c, d, id)
    assertThat(b.transitiveSubRules).isEmpty()
    assertThat(c.transitiveSubRules).containsExactly(d, id)
    assertThat(d.transitiveSubRules).containsExactly(id)
    assertThat(id.transitiveSubRules).isEmpty()

    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  @Test
  fun testGrammarHierarchyProtoMessage() {
    val hierarchy = createFromFile("subrule_alternative.g4")
    testProtoMessageIsCreatedCorrectly(hierarchy)
  }

  private fun testProtoMessageIsCreatedCorrectly(hierarchy: GrammarHierarchy) {
    val message = hierarchy.toProtoMessage()
    assertThat(message.isInitialized).isTrue()
    val entries = message.entriesList
    assertThat(entries).hasSize(hierarchy.ruleList.size)

    entries.forEach {
      assertThat(it.isInitialized).isTrue()
      val entry = hierarchy.getRuleHierarchyEntryWithNameOrThrow(it.ruleName)
      assertThat(entry.canRuleBeEpsilon()).isEqualTo(it.canBeEpsilon)
      assertThat(it.immediateSubRuleNamesList).containsExactlyElementsIn(
        entry.immediateSubRuleNames,
      )
      assertThat(it.transitiveSubRuleNamesList).containsExactlyElementsIn(
        entry.transitiveSubRules.map { it.ruleName },
      )
    }
  }

  companion object {
    private val RULE_NAMES_IN_ORIGINAL_C_PARSER = ImmutableList.builder<String>()
      .add("primaryExpression")
      .add("genericSelection")
      .add("genericAssocList")
      .add("genericAssociation")
      .add("postfixExpression")
      .add("argumentExpressionList")
      .add("unaryExpression")
      .add("unaryOperator")
      .add("castExpression")
      .add("multiplicativeExpression")
      .add("additiveExpression")
      .add("shiftExpression")
      .add("relationalExpression")
      .add("equalityExpression")
      .add("andExpression")
      .add("exclusiveOrExpression")
      .add("inclusiveOrExpression")
      .add("logicalAndExpression")
      .add("logicalOrExpression")
      .add("conditionalExpression")
      .add("assignmentExpression")
      .add("assignmentOperator")
      .add("expression")
      .add("constantExpression")
      .add("declaration")
      .add("declarationSpecifiers")
      .add("declarationSpecifiers2")
      .add("declarationSpecifier")
      .add("initDeclaratorList")
      .add("initDeclarator")
      .add("storageClassSpecifier")
      .add("typeSpecifier")
      .add("structOrUnionSpecifier")
      .add("structOrUnion")
      .add("structDeclarationList")
      .add("structDeclaration")
      .add("specifierQualifierList")
      .add("structDeclaratorList")
      .add("structDeclarator")
      .add("enumSpecifier")
      .add("enumeratorList")
      .add("enumerator")
      .add("enumerationConstant")
      .add("atomicTypeSpecifier")
      .add("typeQualifier")
      .add("functionSpecifier")
      .add("alignmentSpecifier")
      .add("declarator")
      .add("directDeclarator")
      .add("gccDeclaratorExtension")
      .add("gccAttributeSpecifier")
      .add("gccAttributeList")
      .add("gccAttribute")
      .add("nestedParenthesesBlock")
      .add("pointer")
      .add("typeQualifierList")
      .add("parameterTypeList")
      .add("parameterList")
      .add("parameterDeclaration")
      .add("identifierList")
      .add("typeName")
      .add("abstractDeclarator")
      .add("directAbstractDeclarator")
      .add("typedefName")
      .add("initializer")
      .add("initializerList")
      .add("designation")
      .add("designatorList")
      .add("designator")
      .add("staticAssertDeclaration")
      .add("statement")
      .add("labeledStatement")
      .add("compoundStatement")
      .add("blockItemList")
      .add("blockItem")
      .add("expressionStatement")
      .add("selectionStatement")
      .add("iterationStatement")
      .add("jumpStatement")
      .add("compilationUnit")
      .add("translationUnit")
      .add("externalDeclaration")
      .add("functionDefinition")
      .add("declarationList")
      .build()

    private fun <T> dumpRuleWithSubrules(
      rules: ImmutableList<RuleHierarchyEntry>,
      listConverter: Function<RuleHierarchyEntry, Collection<T>>,
      toStringer: Function<T, String>,
    ): String {
      val builder = StringBuilder()
      for (rule in rules) {
        val subrules = listConverter.apply(rule)
        if (subrules.isEmpty()) {
          continue
        }
        builder.append(rule.ruleName).append("\n")
        for (subrule in TreeSet(subrules)) {
          builder.append("    ").append(toStringer.apply(subrule)).append("\n")
        }
        builder.append("\n")
      }
      return builder.toString().trim { it <= ' ' }
    }

    private fun createFromFile(filename: String): GrammarHierarchy {
      return try {
        val file = Paths.get("test_data/antlr_grammars/", filename)
        val content = Files.asCharSource(file.toFile(), StandardCharsets.UTF_8).read()
        createFromString(content)
      } catch (e: Exception) {
        throw RuntimeException(e)
      }
    } // TODO: test token type retrieval.
  }

  @Test
  fun testDotInParserRule() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      """
      grammar T;
      start: . ;
      """.trimIndent(),
    )
    val hierarchy = GrammarHierarchyBuilder(
      AbstractAntlrGrammar.CombinedAntlrGrammar(grammar),
    ).build()
    assertThat(hierarchy.ruleList).hasSize(1)
    val entry = hierarchy.getRuleHierarchyEntryWithNameOrThrow("start")
    assertThat(entry.immediateSubRuleNames).isEmpty()
    assertThat(entry.transitiveSubRules).isEmpty()
  }
}

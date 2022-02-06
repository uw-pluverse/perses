/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.antlr;

import static com.google.common.truth.Truth.assertThat;

import com.google.common.base.Function;
import com.google.common.collect.ImmutableList;
import com.google.common.io.Files;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Collection;
import java.util.TreeSet;
import java.util.stream.Collectors;
import org.antlr.v4.tool.Grammar;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.grammar.c.CParserFacade;

/** Test for {@link AntlrGrammarParser} */
@RunWith(JUnit4.class)
public class GrammarHierarchyTest {

  private static final ImmutableList<String> RULE_NAMES_IN_ORIGINAL_C_PARSER =
      ImmutableList.<String>builder()
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
          .build();

  private static <T> String dumpRuleWithSubrules(
      ImmutableList<RuleHierarchyInfo> rules,
      Function<RuleHierarchyInfo, Collection<T>> listConverter,
      Function<T, String> toStringer) {
    final StringBuilder builder = new StringBuilder();
    for (RuleHierarchyInfo rule : rules) {
      Collection<T> subrules = listConverter.apply(rule);
      if (subrules.isEmpty()) {
        continue;
      }
      builder.append(rule.getRuleName()).append("\n");
      for (T subrule : new TreeSet<>(subrules)) {
        builder.append("    ").append(toStringer.apply(subrule)).append("\n");
      }
      builder.append("\n");
    }
    return builder.toString().trim();
  }

  private static String readResourceFileToString(String goldenFileName) throws IOException {
    final String resourceName =
        TestUtility.getBazelPathForTestingResource(GrammarHierarchyTest.class, goldenFileName);
    return Files.asCharSource(Paths.get(resourceName).toFile(), StandardCharsets.UTF_8).read();
  }

  @Test
  public void testParsingCGrammar() throws IOException {
    final String grammarFileContent = GrammarTestingUtility.readAntlrFileToString("C.g4");
    Grammar grammar =
        AntlrGrammarParser.loadAntlrGrammarFromInputStream(
            new ByteArrayInputStream(grammarFileContent.getBytes(StandardCharsets.UTF_8)));
    assertThat(grammar.rules.keySet())
        .containsExactlyElementsIn(RULE_NAMES_IN_ORIGINAL_C_PARSER)
        .inOrder();
    assertThat(grammar.rules.values().stream().map(r -> r.name).collect(Collectors.toList()))
        .containsExactlyElementsIn(RULE_NAMES_IN_ORIGINAL_C_PARSER)
        .inOrder();
  }

  @Test
  public void testSubruleCompatibilityChecking() {
    final GrammarHierarchy hierarchy = new CParserFacade().getRuleHierarchy();
    final RuleHierarchyInfo primaryRule =
        hierarchy.getRuleHierarchyInfoWithName("primaryExpression");
    assertThat(primaryRule.getRuleName()).isEqualTo("primaryExpression");
    assertThat(hierarchy.getRuleHierarchyInfoWithName("primaryExpression")).isEqualTo(primaryRule);
    final RuleHierarchyInfo expressionRule = hierarchy.getRuleHierarchyInfoWithName("expression");
    assertThat(expressionRule.isSuperOf(primaryRule)).isTrue();
    assertThat(primaryRule.isSuperOf(expressionRule)).isFalse();

    final RuleHierarchyInfo genericSelection =
        hierarchy.getRuleHierarchyInfoWithName("genericSelection");
    assertThat(primaryRule.isSuperOf(genericSelection)).isTrue();
    assertThat(expressionRule.isSuperOf(genericSelection)).isTrue();
    assertThat(genericSelection.isSuperOf(expressionRule)).isFalse();

    final RuleHierarchyInfo declaration = hierarchy.getRuleHierarchyInfoWithName("declaration");
    assertThat(declaration.isSuperOf(primaryRule)).isFalse();
    assertThat(primaryRule.isSuperOf(declaration)).isFalse();
  }

  @Test
  public void testSubruleExtractionForStar() {
    GrammarHierarchy hierarchy = createFromFile("subrule_star.g4");
    RuleHierarchyInfo start = hierarchy.getRuleHierarchyInfoWithName("start");
    RuleHierarchyInfo a = hierarchy.getRuleHierarchyInfoWithName("a");
    RuleHierarchyInfo b = hierarchy.getRuleHierarchyInfoWithName("b");

    assertThat(start.getTransitiveSubRules()).containsExactly(a, b);
    assertThat(a.getTransitiveSubRules()).containsExactly(b);
    assertThat(b.getTransitiveSubRules()).isEmpty();
  }

  @Test
  public void testSubruleExtractionForPlus() {
    GrammarHierarchy hierarchy = createFromFile("subrule_plus.g4");
    RuleHierarchyInfo start = hierarchy.getRuleHierarchyInfoWithName("start");
    RuleHierarchyInfo a = hierarchy.getRuleHierarchyInfoWithName("a");
    RuleHierarchyInfo b = hierarchy.getRuleHierarchyInfoWithName("b");

    assertThat(start.getTransitiveSubRules()).containsExactly(a);
    assertThat(a.getTransitiveSubRules()).isEmpty();
    assertThat(b.getTransitiveSubRules()).isEmpty();
  }

  @Test
  public void testSubruleExtractionForOptional() {
    GrammarHierarchy hierarchy = createFromFile("subrule_optional.g4");
    RuleHierarchyInfo start = hierarchy.getRuleHierarchyInfoWithName("start");
    RuleHierarchyInfo a = hierarchy.getRuleHierarchyInfoWithName("a");
    RuleHierarchyInfo b = hierarchy.getRuleHierarchyInfoWithName("b");

    assertThat(start.getTransitiveSubRules()).containsExactly(a, b);
    assertThat(a.getTransitiveSubRules()).containsExactly(b);
    assertThat(b.getTransitiveSubRules()).isEmpty();
  }

  @Test
  public void testSubruleExtractionForSequence() {
    GrammarHierarchy hierarchy = createFromFile("subrule_sequence.g4");
    RuleHierarchyInfo start = hierarchy.getRuleHierarchyInfoWithName("start");
    RuleHierarchyInfo a = hierarchy.getRuleHierarchyInfoWithName("a");
    RuleHierarchyInfo b = hierarchy.getRuleHierarchyInfoWithName("b");
    RuleHierarchyInfo c = hierarchy.getRuleHierarchyInfoWithName("c");
    RuleHierarchyInfo d = hierarchy.getRuleHierarchyInfoWithName("d");

    assertThat(start.getTransitiveSubRules()).containsExactly(a, b, c, d);
    assertThat(a.getTransitiveSubRules()).containsExactly(b);
    assertThat(b.getTransitiveSubRules()).isEmpty();
    assertThat(c.getTransitiveSubRules()).containsExactly(d);
    assertThat(d.getTransitiveSubRules()).isEmpty();
  }

  @Test
  public void testSubruleExtractionForAlternative() {
    GrammarHierarchy hierarchy = createFromFile("subrule_alternative.g4");
    RuleHierarchyInfo start = hierarchy.getRuleHierarchyInfoWithName("start");
    RuleHierarchyInfo a = hierarchy.getRuleHierarchyInfoWithName("a");
    RuleHierarchyInfo b = hierarchy.getRuleHierarchyInfoWithName("b");
    RuleHierarchyInfo c = hierarchy.getRuleHierarchyInfoWithName("c");
    RuleHierarchyInfo d = hierarchy.getRuleHierarchyInfoWithName("d");
    RuleHierarchyInfo id = hierarchy.getRuleHierarchyInfoWithName("ID");

    assertThat(start.getTransitiveSubRules()).containsExactly(a, b, c, d, id);
    assertThat(a.getTransitiveSubRules()).containsExactly(c, d, id);
    assertThat(b.getTransitiveSubRules()).isEmpty();
    assertThat(c.getTransitiveSubRules()).containsExactly(d, id);
    assertThat(d.getTransitiveSubRules()).containsExactly(id);
    assertThat(id.getTransitiveSubRules()).isEmpty();
  }

  private static GrammarHierarchy createFromFile(String filename) {
    try {
      Path file = Paths.get("test_data/antlr_grammars/", filename);
      String content = Files.asCharSource(file.toFile(), StandardCharsets.UTF_8).read();
      return GrammarHierarchy.createFromString(content);
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  // TODO: test token type retrieval.
}

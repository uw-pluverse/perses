/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.grammar.java;

import com.google.common.collect.ImmutableList;
import com.google.common.flogger.FluentLogger;
import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Assert;
import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicInteger;

import static com.google.common.truth.Truth.assertThat;

/** Test for {@link OptJava8Parser} */
@RunWith(JUnit4.class)
@Ignore
// TODO: enable this test in the future.
public class OptJavaParserTest {
  public static final ImmutableList<String> OPT_JAVA_PARSER_RULE_NAMES =
      ImmutableList.<String>builder()
          .add("literal")
          .add("type")
          .add("kleene_star__annotation")
          .add("primitiveType")
          .add("numericType")
          .add("integralType")
          .add("floatingPointType")
          .add("referenceType")
          .add("classOrInterfaceType_part")
          .add("kleene_star__classOrInterfaceType_part")
          .add("classOrInterfaceType")
          .add("optional__typeArguments")
          .add("classType")
          .add("classType_lf_classOrInterfaceType")
          .add("classType_lfno_classOrInterfaceType")
          .add("interfaceType")
          .add("interfaceType_lf_classOrInterfaceType")
          .add("interfaceType_lfno_classOrInterfaceType")
          .add("typeVariable")
          .add("arrayType")
          .add("dims_part")
          .add("kleene_plus__dims_part")
          .add("kleene_star__dims_part")
          .add("typeParameter")
          .add("optional__typeBound")
          .add("typeBound")
          .add("kleene_star__additionalBound")
          .add("additionalBound")
          .add("typeArguments")
          .add("typeArgumentList_part")
          .add("kleene_star__typeArgumentList_part")
          .add("typeArgumentList")
          .add("typeArgument")
          .add("wildcard")
          .add("optional__wildcardBounds")
          .add("wildcardBounds")
          .add("packageName")
          .add("typeName")
          .add("packageOrTypeName")
          .add("expressionName")
          .add("methodName")
          .add("ambiguousName")
          .add("optional__packageDeclaration")
          .add("kleene_star__importDeclaration")
          .add("kleene_star__typeDeclaration")
          .add("compilationUnit")
          .add("packageDeclaration")
          .add("importDeclaration")
          .add("singleTypeImportDeclaration")
          .add("typeImportOnDemandDeclaration")
          .add("singleStaticImportDeclaration")
          .add("staticImportOnDemandDeclaration")
          .add("typeDeclaration")
          .add("classDeclaration")
          .add("normalClassDeclaration")
          .add("kleene_star__classModifier")
          .add("classModifier")
          .add("optional__typeParameters")
          .add("typeParameters")
          .add("typeParameterList_part")
          .add("kleene_star__typeParameterList_part")
          .add("typeParameterList")
          .add("optional__superclass")
          .add("superclass")
          .add("optional__superinterfaces")
          .add("superinterfaces")
          .add("interfaceTypeList_part")
          .add("kleene_star__interfaceTypeList_part")
          .add("interfaceTypeList")
          .add("kleene_star__classBodyDeclaration")
          .add("classBody")
          .add("classBodyDeclaration")
          .add("classMemberDeclaration")
          .add("fieldDeclaration")
          .add("kleene_star__fieldModifier")
          .add("fieldModifier")
          .add("variableDeclaratorList_part")
          .add("kleene_star__variableDeclaratorList_part")
          .add("variableDeclaratorList")
          .add("variableDeclarator_part")
          .add("optional__variableDeclarator_part")
          .add("variableDeclarator")
          .add("variableDeclaratorId")
          .add("variableInitializer")
          .add("unannType")
          .add("unannPrimitiveType")
          .add("unannReferenceType")
          .add("unannClassOrInterfaceType_part")
          .add("kleene_star__unannClassOrInterfaceType_part")
          .add("unannClassOrInterfaceType")
          .add("unannClassType")
          .add("unannClassType_lf_unannClassOrInterfaceType")
          .add("unannClassType_lfno_unannClassOrInterfaceType")
          .add("unannInterfaceType")
          .add("unannInterfaceType_lf_unannClassOrInterfaceType")
          .add("unannInterfaceType_lfno_unannClassOrInterfaceType")
          .add("unannTypeVariable")
          .add("unannArrayType")
          .add("methodDeclaration")
          .add("kleene_star__methodModifier")
          .add("methodModifier")
          .add("methodHeader")
          .add("result")
          .add("methodDeclarator")
          .add("formalParameterList")
          .add("formalParameters_part")
          .add("kleene_star__formalParameters_part")
          .add("formalParameters")
          .add("formalParameter")
          .add("kleene_star__variableModifier")
          .add("variableModifier")
          .add("lastFormalParameter")
          .add("identifier_and_dot")
          .add("optional__identifier_and_dot")
          .add("receiverParameter")
          .add("optional__throws_")
          .add("throws_")
          .add("exceptionTypeList_part")
          .add("kleene_star__exceptionTypeList_part")
          .add("exceptionTypeList")
          .add("exceptionType")
          .add("methodBody")
          .add("instanceInitializer")
          .add("staticInitializer")
          .add("constructorDeclaration")
          .add("kleene_star__constructorModifier")
          .add("constructorModifier")
          .add("constructorDeclarator")
          .add("simpleTypeName")
          .add("optional__explicitConstructorInvocation")
          .add("constructorBody")
          .add("explicitConstructorInvocation")
          .add("enumDeclaration")
          .add("optional__enumConstantList")
          .add("enumBody")
          .add("optional__enumBodyDeclarations")
          .add("enumConstantList_part")
          .add("kleene_star__enumConstantList_part")
          .add("enumConstantList")
          .add("paren_with_argument_list")
          .add("optional__paren_with_argument_list")
          .add("enumConstant")
          .add("enumBodyDeclarations")
          .add("interfaceDeclaration")
          .add("normalInterfaceDeclaration")
          .add("kleene_star__interfaceModifier")
          .add("interfaceModifier")
          .add("optional__extendsInterfaces")
          .add("extendsInterfaces")
          .add("interfaceBody")
          .add("kleene_star__interfaceMemberDeclaration")
          .add("interfaceMemberDeclaration")
          .add("constantDeclaration")
          .add("kleene_star__constantModifier")
          .add("constantModifier")
          .add("interfaceMethodDeclaration")
          .add("kleene_star__interfaceMethodModifier")
          .add("interfaceMethodModifier")
          .add("annotationTypeDeclaration")
          .add("annotationTypeBody")
          .add("kleene_star__annotationTypeMemberDeclaration")
          .add("annotationTypeMemberDeclaration")
          .add("annotationTypeElementDeclaration")
          .add("kleene_star__annotationTypeElementModifier")
          .add("annotationTypeElementModifier")
          .add("optional__defaultValue")
          .add("defaultValue")
          .add("annotation")
          .add("normalAnnotation")
          .add("optional__elementValuePairList")
          .add("elementValuePairList_part")
          .add("kleene_star__elementValuePairList_part")
          .add("elementValuePairList")
          .add("elementValuePair")
          .add("elementValue")
          .add("elementValueArrayInitializer")
          .add("elementValueList_part")
          .add("kleene_star__elementValueList_part")
          .add("optional__elementValueList")
          .add("elementValueList")
          .add("markerAnnotation")
          .add("singleElementAnnotation")
          .add("optional__comma")
          .add("arrayInitializer")
          .add("optional__variableInitializerList")
          .add("variableInitializerList_part")
          .add("kleene_star__variableInitializerList_part")
          .add("variableInitializerList")
          .add("block")
          .add("kleene_star__blockStatements")
          .add("kleene_plus__blockStatements")
          .add("blockStatement")
          .add("localVariableDeclarationStatement")
          .add("localVariableDeclaration")
          .add("statement")
          .add("statementNoShortIf")
          .add("statementWithoutTrailingSubstatement")
          .add("emptyStatement")
          .add("labeledStatement")
          .add("labeledStatementNoShortIf")
          .add("expressionStatement")
          .add("statementExpression")
          .add("ifThenStatement")
          .add("ifThenElseStatement")
          .add("ifThenElseStatementNoShortIf")
          .add("expression_in_assertion")
          .add("optional__expression_in_assertion")
          .add("assertStatement")
          .add("switchStatement")
          .add("switchBlock")
          .add("kleene_star__switchBlockStatementGroup")
          .add("kleene_star__switchLabel")
          .add("switchBlockStatementGroup")
          .add("kleene_plus__switchLabe")
          .add("switchLabel")
          .add("enumConstantName")
          .add("whileStatement")
          .add("whileStatementNoShortIf")
          .add("doStatement")
          .add("forStatement")
          .add("forStatementNoShortIf")
          .add("basicForStatement")
          .add("basicForStatementNoShortIf")
          .add("optional__forInit")
          .add("forInit")
          .add("optional__forUpdate")
          .add("forUpdate")
          .add("statementExpressionList__part")
          .add("kleene_star__statementExpressionList__part")
          .add("statementExpressionList")
          .add("enhancedForStatement")
          .add("enhancedForStatementNoShortIf")
          .add("optional__Identifier")
          .add("breakStatement")
          .add("continueStatement")
          .add("optional__expression")
          .add("returnStatement")
          .add("throwStatement")
          .add("synchronizedStatement")
          .add("tryStatement")
          .add("kleene_star__catches")
          .add("kleene_plus__catches")
          .add("catchClause")
          .add("catchFormalParameter")
          .add("catchTypePart")
          .add("kleene_star__catchTypePart")
          .add("catchType")
          .add("finally_")
          .add("tryWithResourcesStatement")
          .add("optional__finally_")
          .add("optional__semicolon")
          .add("resourceSpecification")
          .add("resourceListPart")
          .add("kleene_star__resourceListPart")
          .add("resourceList")
          .add("resource")
          .add("kleene_star__primaryNoNewArray_lf_primary")
          .add("primary")
          .add("bracket_pair")
          .add("kleene_star__bracket_pair")
          .add("primaryNoNewArray")
          .add("primaryNoNewArray_lf_arrayAccess")
          .add("primaryNoNewArray_lfno_arrayAccess")
          .add("primaryNoNewArray_lf_primary")
          .add("primaryNoNewArray_lf_primary_lf_arrayAccess_lf_primary")
          .add("primaryNoNewArray_lf_primary_lfno_arrayAccess_lf_primary")
          .add("primaryNoNewArray_lfno_primary")
          .add("primaryNoNewArray_lfno_primary_lf_arrayAccess_lfno_primary")
          .add("primaryNoNewArray_lfno_primary_lfno_arrayAccess_lfno_primary")
          .add("classInstanceCreationExpression")
          .add("classInstanceCreationExpression_lf_primary")
          .add("classInstanceCreationExpression_lfno_primary")
          .add("annotation_and_identifier")
          .add("kleene_star__annotation_and_identifier")
          .add("optional__classBody")
          .add("optional__typeArgumentsOrDiamond")
          .add("typeArgumentsOrDiamond")
          .add("fieldAccess")
          .add("fieldAccess_lf_primary")
          .add("fieldAccess_lfno_primary")
          .add("arrayAccess_part")
          .add("kleene_star__arrayAccess_part")
          .add("arrayAccess")
          .add("arrayAccess_lf_primary_part")
          .add("kleene_star__arrayAccess_lf_primary_part")
          .add("arrayAccess_lf_primary")
          .add("arrayAccess_lfno_primary_part")
          .add("kleene_star__arrayAccess_lfno_primary_part")
          .add("arrayAccess_lfno_primary")
          .add("methodInvocation")
          .add("methodInvocation_lf_primary")
          .add("methodInvocation_lfno_primary")
          .add("optional__argumentList")
          .add("argumentList_part")
          .add("kleene_star__argumentList_part")
          .add("argumentList")
          .add("methodReference")
          .add("methodReference_lf_primary")
          .add("methodReference_lfno_primary")
          .add("arrayCreationExpression")
          .add("kleene_plus__dimExpr")
          .add("dimExpr")
          .add("constantExpression")
          .add("expression")
          .add("lambdaExpression")
          .add("lambdaParameters")
          .add("optional__formalParameterList")
          .add("inferredFormalParameterList_part")
          .add("kleene_star__inferredFormalParameterList_part")
          .add("inferredFormalParameterList")
          .add("lambdaBody")
          .add("assignmentExpression")
          .add("assignment")
          .add("leftHandSide")
          .add("assignmentOperator")
          .add("conditionalExpressionPart")
          .add("optional__conditionalExpressionPart")
          .add("conditionalExpression")
          .add("conditionalOrExpression")
          .add("conditionalAndExpression")
          .add("inclusiveOrExpression")
          .add("exclusiveOrExpression")
          .add("andExpression")
          .add("equalityExpression")
          .add("relationalExpression")
          .add("shiftExpression")
          .add("additiveExpression")
          .add("multiplicativeExpression")
          .add("unaryExpression")
          .add("preIncrementExpression")
          .add("preDecrementExpression")
          .add("unaryExpressionNotPlusMinus")
          .add("postfixExpression")
          .add("kleene_star__plusplus_or_minusminus")
          .add("plus_plus_or_minus_minus")
          .add("postIncrementExpression")
          .add("postDecrementExpression")
          .add("castExpression")
          .build();
  private static final FluentLogger logger = FluentLogger.forEnclosingClass();
  /** This test is too slow, so here we manually shard it. */
  private static final ArrayList<File> shard1 = new ArrayList<>();

  private static final ArrayList<File> shard2 = new ArrayList<>();
  private static final ArrayList<File> shard3 = new ArrayList<>();
  private static final ArrayList<File> shard4 = new ArrayList<>();
  private static final ArrayList<File> shard5 = new ArrayList<>();
  private static final ArrayList<File> shard6 = new ArrayList<>();
  private static final JavaParserFacade JAVA_PARSER_FACADE = new JavaParserFacade();

  static {
    final AtomicInteger counter = new AtomicInteger();
    final ImmutableList<ArrayList<File>> shards =
        ImmutableList.of(shard1, shard2, shard3, shard4, shard5, shard6);
    TestUtility.getOpenJdkJavaFiles()
        .forEach(
            file -> {
              shards.get(counter.getAndIncrement() % shards.size()).add(file);
            });
  }

  private static void testOptimizedJavaParserWithOriginalJavaParser(ArrayList<File> shard) {
    shard.stream().forEach(OptJavaParserTest::testOneJavaFile);
  }

  private static void testOneJavaFile(File testFile) {
    try {
      logger.atInfo().log("Testing %s", testFile);
      final ParseTree treeByOrig =
          JAVA_PARSER_FACADE.parseFileWithOrigJavaParser(testFile).getTree();
      final ParseTree treeByOpt = JAVA_PARSER_FACADE.parseFile(testFile).getTree();
      assertThat(TestUtility.extractTokens(treeByOrig))
          .containsExactlyElementsIn(TestUtility.extractTokens(treeByOpt))
          .inOrder();
    } catch (IOException e) {
      e.printStackTrace();
      Assert.fail();
    }
  }

  @Test
  public void testOptimizedJavaParserWithOriginalJavaParser_Shard1() {
    testOptimizedJavaParserWithOriginalJavaParser(shard1);
  }

  @Test
  public void testOptimizedJavaParserWithOriginalJavaParser_Shard2() {
    testOptimizedJavaParserWithOriginalJavaParser(shard2);
  }

  @Test
  public void testOptimizedJavaParserWithOriginalJavaParser_Shard3() {
    testOptimizedJavaParserWithOriginalJavaParser(shard3);
  }

  @Test
  public void testOptimizedJavaParserWithOriginalJavaParser_Shard4() {
    testOptimizedJavaParserWithOriginalJavaParser(shard4);
  }

  @Test
  public void testOptimizedJavaParserWithOriginalJavaParser_Shard5() {
    testOptimizedJavaParserWithOriginalJavaParser(shard5);
  }

  @Test
  public void testOptimizedJavaParserWithOriginalJavaParser_Shard6() {
    testOptimizedJavaParserWithOriginalJavaParser(shard6);
  }

  @Test
  public void testIntegrityOfOptimizedJava8Parser() {
    final PersesGrammar persesGrammar =
        JAVA_PARSER_FACADE.getAntlrGrammar().asCombined().getGrammar();
    ImmutableList<String> ruleNames =
        persesGrammar.getRules().stream()
            .map(AbstractPersesRuleDefAst::getRuleNameHandle)
            .map(RuleNameRegistry.RuleNameHandle::get)
            .collect(ImmutableList.toImmutableList());
    assertThat(ruleNames).containsExactlyElementsIn(OPT_JAVA_PARSER_RULE_NAMES);
  }
}

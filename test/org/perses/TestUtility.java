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
package org.perses;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractParserFacade;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.java.JavaParserFacade;
import org.perses.grammar.scala.PnfScalaParserFacade;
import org.perses.program.LanguageKind;
import org.perses.program.SourceFile;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.SparTree;
import org.perses.tree.spar.SparTreeBuilder;

import java.io.File;
import java.io.IOError;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Stream;

import static com.google.common.truth.Truth.assertThat;

/** Utility class for testing. */
public final class TestUtility {

  public static final ImmutableList<String> OPT_C_PARSER_RULE_NAMES =
      ImmutableList.<String>builder()
          .add("primaryExpression")
          .add("optional__extension")
          .add("kleene_plus__StringLiteral")
          .add("genericSelection")
          .add("genericAssocList")
          .add("genericAssocListPart")
          .add("kleene_star__genericAssociationPart")
          .add("genericAssociation")
          .add("postfixExpression")
          .add("optional__comma")
          .add("optional__argumentExpressionList")
          .add("argumentExpressionListPart")
          .add("kleene_star__argumentExpressionListPart")
          .add("argumentExpressionList")
          .add("unaryExpression")
          .add("unaryOperator")
          .add("castExpression")
          .add("binaryOperator")
          .add("nonAssignmentBinaryExpressionPart")
          .add("kleene_star__nonAssignmentBinaryExpressionPart")
          .add("nonAssignmentBinaryExpression")
          .add("conditionalExpressionPart")
          .add("optional__conditionalExpressionPart")
          .add("conditionalExpression")
          .add("assignmentExpression")
          .add("assignmentOperator")
          .add("expressionPart")
          .add("kleene_star__expressionPart")
          .add("optional__expression")
          .add("expression")
          .add("constantExpression")
          .add("declaration")
          .add("kleene_star__declarationSpecifiers")
          .add("kleene_plus__declarationSpecifiers")
          .add("declarationSpecifier")
          .add("initDeclaratorListPart")
          .add("kleene_star__initDeclaratorListPart")
          .add("optional__initDeclaratorList")
          .add("initDeclaratorList")
          .add("initDeclaratorPart")
          .add("optional__initDeclaratorPart")
          .add("initDeclarator")
          .add("storageClassSpecifier")
          .add("typeSpecifier")
          .add("optional__identifier")
          .add("structOrUnionSpecifier")
          .add("structOrUnion")
          .add("kleene_plus__structDeclarationList")
          .add("structDeclaration")
          .add("specifierQualifierListPart")
          .add("kleene_plus__specifierQualifierList")
          .add("structDeclaratorListPart")
          .add("kleene_star__structDeclaratorList")
          .add("structDeclaratorList")
          .add("optional__structDeclaratorList")
          .add("structDeclarator")
          .add("optional__declarator")
          .add("enumSpecifier")
          .add("enumeratorListPart")
          .add("kleene_star__enumeratorListPart")
          .add("enumeratorList")
          .add("enumeratorPart")
          .add("optional__enumeratorPart")
          .add("enumerator")
          .add("atomicTypeSpecifier")
          .add("typeQualifier")
          .add("functionSpecifier")
          .add("alignmentSpecifier")
          .add("kleene_star__gccDeclaratorExtension")
          .add("declarator")
          .add("optional__assignmentExpression")
          .add("directDeclaratorPart")
          .add("kleene_star__directDeclaratorPart")
          .add("directDeclarator")
          .add("gccDeclaratorExtension")
          .add("asmKeyword")
          .add("gccAttributeSpecifier")
          .add("gccAttributeListPart")
          .add("kleene_star__gccAttributeListPart")
          .add("optional__gccAttributeList")
          .add("gccAttributeList")
          .add("gccAttributePart")
          .add("optional__gccAttributePart")
          .add("gccAttribute")
          .add("nestedParenthesesBlockPart")
          .add("kleene_star__nestedParenthesesBlockPart")
          .add("nestedParenthesesBlock")
          .add("pointerPart")
          .add("kleene_plus__pointerPart")
          .add("kleene_star__pointerPart")
          .add("kleene_star__typeQualifierList")
          .add("kleene_plus__typeQualifierList")
          .add("parameterTypeListPart")
          .add("optional__parameterTypeListPart")
          .add("optional__parameterTypeList")
          .add("parameterTypeList")
          .add("parameterListPart")
          .add("kleene_star__parameterListPart")
          .add("parameterList")
          .add("parameterDeclaration")
          .add("identifierListPart")
          .add("kleene_star__identifierListPart")
          .add("identifierList")
          .add("optional__identifierList")
          .add("typeName")
          .add("optional__abstractDeclarator")
          .add("abstractDeclarator")
          .add("directAbstractDeclarator")
          .add("typedefName")
          .add("initializer")
          .add("initializerListPart")
          .add("kleene_star__initializerListPart")
          .add("initializerList")
          .add("optional__designation")
          .add("designation")
          .add("kleene_plus__designatorList")
          .add("designator")
          .add("staticAssertDeclaration")
          .add("statementPartOne")
          .add("kleene_star__statementPartOne")
          .add("statementPartTwo")
          .add("optional__statementPartTwo")
          .add("statementPartThree")
          .add("kleene_star__statementPartThree")
          .add("statement")
          .add("asmStatement")
          .add("labeledStatement")
          .add("compoundStatement")
          .add("kleene_star__blockItem")
          .add("blockItem")
          .add("expressionStatement")
          .add("selectionStatementPart")
          .add("optional__selectionStatementPart")
          .add("selectionStatement")
          .add("iterationStatement")
          .add("jumpStatement")
          .add("compilationUnit")
          .add("optional__translationUnit")
          .add("kleene_plus__externalDeclaration")
          .add("translationUnit")
          .add("externalDeclaration")
          .add("functionDefinition")
          .add("kleene_star__declaration")
          .build();
  private static final File THIRD_PARTY_TEST_PROGRAMS_ROOT = new File("test_data/");
  private static final File GCC_C_PROGRAM_FOLDER =
      new File(THIRD_PARTY_TEST_PROGRAMS_ROOT, "c_programs/gcc_testsuite");
  private static final File CLANG_C_PROGRAM_FOLDER =
      new File(THIRD_PARTY_TEST_PROGRAMS_ROOT, "c_programs/clang_testsuite");
  private static final File GO_PROGRAM_FOLDER =
      new File(THIRD_PARTY_TEST_PROGRAMS_ROOT, "go_programs/go_testsuite");
  private static final File RUST_PROGRAM_FOLDER =
      new File(THIRD_PARTY_TEST_PROGRAMS_ROOT, "rust_programs/rust_testsuite");

  private TestUtility() {}

  public static ImmutableList<File> getGccTestFiles() {
    return getCFiles(GCC_C_PROGRAM_FOLDER);
  }

  public static ImmutableList<File> partitionAndGet(
      ImmutableList<File> list, int numOfPartitions, int ith) {
    final AtomicInteger counter = new AtomicInteger();
    return list.stream()
        .filter(n -> counter.getAndIncrement() % numOfPartitions == ith)
        .collect(ImmutableList.toImmutableList());
  }

  public static ImmutableList<File> getGolangTestFiles() {
    return getGolangFiles(GO_PROGRAM_FOLDER);
  }

  public static ImmutableList<File> getRustTestFiles() {
    return getGolangFiles(RUST_PROGRAM_FOLDER);
  }

  public static File getOneGccTestFile(String fileName) {
    return new File(GCC_C_PROGRAM_FOLDER, fileName);
  }

  public static ImmutableList<File> getClangTestFiles() {
    return getCFiles(CLANG_C_PROGRAM_FOLDER);
  }

  public static final ImmutableList<File> getOpenJdkJavaFiles() {
    return getJavaFiles(
        new File(THIRD_PARTY_TEST_PROGRAMS_ROOT, "java_programs/openjdk_testsuite"));
  }

  public static AbstractParserFacade getFacade(LanguageKind languageKind) {
    switch (languageKind) {
      case C:
        // Use the existing, stable parser for test stability.
        return new CParserFacade();
      case JAVA:
        return new JavaParserFacade();
      case SCALA:
        return new PnfScalaParserFacade();
    }
    throw new RuntimeException("Cannot reach here. " + languageKind);
  }

  public static ParseTreeWithParser parseFile(String file) throws IOException {
    return parseFile(new File(file));
  }

  public static ParseTreeWithParser parseFile(File file) throws IOException {
    final SourceFile sourceFile = new SourceFile(file);
    final AbstractParserFacade facade = getFacade(sourceFile.getLanguageKind());
    return facade.parseFile(file);
  }

  public static ParseTreeWithParser parseString(String sourceCode, LanguageKind languageKind)
      throws IOException {
    final AbstractParserFacade facade = getFacade(languageKind);
    return facade.parseString(sourceCode);
  }

  public static TokenizedProgram createTokenizedProgramFromFile(String filepath)
      throws IOException {
    File file = new File(filepath);
    TokenizedProgram program = TestUtility.createSparTreeFromFile(file).getProgramSnapshot();
    return program;
  }

  public static TokenizedProgram createTokenizedProgramFromString(
      String sourceCode, LanguageKind languageKind) throws IOException {
    return TestUtility.createSparTreeFromString(sourceCode, languageKind).getProgramSnapshot();
  }

  public static SparTree createSparTreeFromFile(String file) throws IOException {
    return createSparTreeFromFile(new File(file));
  }

  public static SparTree createSparTreeFromString(String sourceCode, LanguageKind languageKind)
      throws IOException {
    final AbstractParserFacade facade = getFacade(languageKind);
    final ParseTreeWithParser parseTreeWithParser = parseString(sourceCode, languageKind);
    final TokenizedProgramFactory factory =
        TokenizedProgramFactory.createFactory(
            AbstractParserFacade.getTokens(parseTreeWithParser.getTree()));
    return new SparTreeBuilder(facade.getRuleHierarchy(), factory)
        .build(parseTreeWithParser.getTree());
  }

  public static SparTree createSparTreeFromFile(File file) throws IOException {
    final ParseTreeWithParser parseTreeWithParser = parseFile(file);
    final TokenizedProgramFactory factory =
        TokenizedProgramFactory.createFactory(
            AbstractParserFacade.getTokens(parseTreeWithParser.getTree()));
    return createSparTreeFromFile(file, factory);
  }

  public static SparTree createSparTreeFromFile(File file, TokenizedProgramFactory factory)
      throws IOException {
    final SourceFile sourceFile = new SourceFile(file);
    final AbstractParserFacade facade = getFacade(sourceFile.getLanguageKind());
    final ParseTree parseTree = facade.parseFile(file).getTree();
    final SparTree tree = new SparTreeBuilder(facade.getRuleHierarchy(), factory).build(parseTree);
    return tree;
  }

  private static final ImmutableList<File> getCFiles(File folder) {
    return getFilesWithExtension(folder, ".c");
  }

  private static final ImmutableList<File> getJavaFiles(File folder) {
    return getFilesWithExtension(folder, ".java");
  }

  private static final ImmutableList<File> getGolangFiles(File folder) {
    return getFilesWithExtension(folder, ".go");
  }

  private static final ImmutableList<File> getRustFiles(File folder) {
    return getFilesWithExtension(folder, ".rs");
  }

  private static final ImmutableList<File> getFilesWithExtension(
      File folder, final String fileExtension) {
    try {
      return Files.walk(folder.toPath())
          .filter(Files::isRegularFile)
          .filter(path -> path.toString().endsWith(fileExtension))
          .map(Path::toFile)
          .sorted()
          .collect(ImmutableList.toImmutableList());
    } catch (IOException e) {
      throw new UncheckedIOException(e);
    }
  }

  public static ArrayList<String> extractTokens(ParseTree tree) {
    final ArrayList<String> result = new ArrayList<>();
    preOrderTraverse(tree, result);
    return result;
  }

  public static String getBazelPathForTestingResource(Class<?> klass, String resourceName) {
    final String pkgName = klass.getPackage().getName().replace('.', '/');
    return "test/" + pkgName + "/" + resourceName;
  }

  public static File createCleanWorkingDirectory(Class<?> klass) throws IOException {
    final File workingDirectory =
        Files.createTempDirectory(klass.getSimpleName() + "_temp").toFile();
    workingDirectory.mkdirs();
    Stream.of(workingDirectory.listFiles())
        .forEach(
            file -> {
              try {
                MoreFiles.deleteRecursively(file.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
              } catch (IOException e) {
                throw new IOError(e);
              }
            });
    assertThat(workingDirectory.isDirectory()).isTrue();
    assertThat(workingDirectory.list()).hasLength(0);
    return workingDirectory;
  }

  public static final class NodeToTokensMap {
    private final ImmutableMap<AbstractSparTreeNode, ImmutableList<String>> map;

    private NodeToTokensMap(ImmutableMap<AbstractSparTreeNode, ImmutableList<String>> map) {
      this.map = map;
    }

    public ImmutableList<String> getTokens(AbstractSparTreeNode node) {
      return map.get(node);
    }

    public AbstractSparTreeNode getNode(ImmutableList<String> tokens, String ruleName) {
      AbstractSparTreeNode result = null;
      for (Map.Entry<AbstractSparTreeNode, ImmutableList<String>> entry : map.entrySet()) {
        if (entry.getValue().equals(tokens) && entry.getKey().getRuleName().equals(ruleName)) {
          Preconditions.checkState(
              result == null, "duplicates: %s, \n%s", result, entry.getKey().printTreeStructure());
          result = entry.getKey();
        }
      }
      return result;
    }

    public String constructTokenListCode(AbstractSparTreeNode node) {
      StringBuilder builder = new StringBuilder();
      builder.append("ImmutableList.of(");
      ImmutableList<String> tokens = map.get(node);
      for (int i = 0; i < tokens.size(); ++i) {
        if (i != 0) {
          builder.append(", ");
        }
        builder.append('"').append(tokens.get(i)).append('"');
      }
      builder.append(")");
      return builder.toString();
    }
  }

  public static AbstractSparTreeNode getNodeWithTokens(
      SparTree tree, ImmutableList<String> tokens, String ruleName) {
    NodeToTokensMap map = createNodeToTokensMap(tree);
    return map.getNode(tokens, ruleName);
  }

  public static String constructNodeRetrievalCode(SparTree tree, AbstractSparTreeNode node) {
    NodeToTokensMap map = createNodeToTokensMap(tree);
    return "TestUtility.getNodeWithTokens(tree, "
        + map.constructTokenListCode(node)
        + ", \""
        + node.getRuleName()
        + "\");";
  }

  public static NodeToTokensMap createNodeToTokensMap(SparTree tree) {
    HashMap<AbstractSparTreeNode, ImmutableList<String>> builder = new HashMap<>();
    recursiveCreateNodeToTokensMap(builder, tree.getRoot());
    return new NodeToTokensMap(ImmutableMap.copyOf(builder));
  }

  private static void recursiveCreateNodeToTokensMap(
      HashMap<AbstractSparTreeNode, ImmutableList<String>> builder, AbstractSparTreeNode node) {
    if (node.isTokenNode()) {
      ImmutableList<String> tokens = ImmutableList.of(node.asLexerRule().getToken().getText());
      builder.put(node, tokens);
      return;
    }

    ImmutableList.Builder<String> value = ImmutableList.builder();
    final int childCount = node.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      AbstractSparTreeNode child = node.getChild(i);
      recursiveCreateNodeToTokensMap(builder, child);
      value.addAll(builder.get(child));
    }
    builder.put(node, value.build());
  }

  private static void preOrderTraverse(ParseTree tree, ArrayList<String> result) {
    if (tree instanceof TerminalNode) {
      final TerminalNode terminal = (TerminalNode) tree;
      result.add(terminal.getSymbol().getText());
      return;
    }
    for (int i = 0, size = tree.getChildCount(); i < size; ++i) {
      preOrderTraverse(tree.getChild(i), result);
    }
  }
}

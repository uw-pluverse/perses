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
package org.perses

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.adhoc.AdhocGrammarInstaller
import org.perses.grammar.adhoc.CommandOptions
import org.perses.grammar.adhoc.LanguageAdhoc
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.grammar.java.JavaParserFacade
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.php.LanguagePhp
import org.perses.grammar.php.PhpParserFacade
import org.perses.grammar.python3.LanguagePython3
import org.perses.grammar.python3.Python3ParserFacade
import org.perses.grammar.rust.LanguageRust
import org.perses.grammar.rust.PnfRustParserFacade
import org.perses.grammar.scala.LanguageScala
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.grammar.smtlibv2.LanguageSmtLibV2
import org.perses.grammar.smtlibv2.SmtLibV2ParserFacade
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.program.TokenizedProgramFactory.Companion.createFactory
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.toImmutableList
import java.io.IOException
import java.io.UncheckedIOException
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import java.util.Arrays
import java.util.concurrent.atomic.AtomicInteger
import kotlin.io.path.writeText

/** Utility class for testing.  */
object TestUtility {

  @JvmField
  val OPT_C_PARSER_RULE_NAMES = ImmutableList.builder<String>()
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
    .build()

  private val THIRD_PARTY_TEST_PROGRAMS_ROOT = Paths.get("test_data/")
  private val GCC_C_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("c_programs/gcc_testsuite")
  private val CLANG_C_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("c_programs/clang_testsuite")
  private val GO_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("go_programs/go_testsuite")
  private val SOLIDITY_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("solidity_programs/solidity")
  private val RUST_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("rust_programs/rust_testsuite")
  private val SMT_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("smtlibv2_programs/smtlibv2_testsuite")
  private val JAVA_PROGRAM_FOLDER =
    THIRD_PARTY_TEST_PROGRAMS_ROOT.resolve("java_programs/openjdk_testsuite")
  private val parserFacadeFactory = SingleParserFacadeFactory.Builder().apply {
    add(LanguageC, CParserFacade::class)
    add(LanguageScala, PnfScalaParserFacade::class)
    add(LanguageJava, JavaParserFacade::class)
    add(LanguagePhp, PhpParserFacade::class)
    add(LanguagePython3, Python3ParserFacade::class)
    add(LanguageSmtLibV2, SmtLibV2ParserFacade::class)
    add(LanguageRust, PnfRustParserFacade::class)
  }.build()

  fun partitionAndGet(
    list: ImmutableList<Path>,
    numOfPartitions: Int,
    ith: Int,
  ): ImmutableList<Path> {
    val counter = AtomicInteger()
    return list.stream()
      .filter { counter.getAndIncrement() % numOfPartitions == ith }
      .collect(ImmutableList.toImmutableList())
  }

  @JvmStatic
  fun createAntlrTokens(vararg lexemes: String): ImmutableList<Token> {
    return Arrays.stream(lexemes)
      .map { createAntlrToken(it) }
      .collect(ImmutableList.toImmutableList())
  }

  fun createAntlrToknesFromList(lexemes: List<String>): ImmutableList<Token> {
    return lexemes.stream()
      .map { createAntlrToken(it) }
      .collect(ImmutableList.toImmutableList())
  }

  fun getOneGccTestFile(fileName: String): Path {
    return GCC_C_PROGRAM_FOLDER.resolve(fileName)
  }

  @JvmStatic
  val gccTestFiles: ImmutableList<Path>
    get() = getCFiles(GCC_C_PROGRAM_FOLDER)

  val golangTestFiles: ImmutableList<Path>
    get() = getGolangFiles(GO_PROGRAM_FOLDER)

  @JvmStatic
  val rustTestFiles: ImmutableList<Path>
    get() = getRustFiles(RUST_PROGRAM_FOLDER)

  val smtTestFiles: ImmutableList<Path>
    get() = getSmtFiles(SMT_PROGRAM_FOLDER)

  val solidityFiles: ImmutableList<Path>
    get() = getSolidityFiles(SOLIDITY_PROGRAM_FOLDER)

  @JvmStatic
  val clangTestFiles: ImmutableList<Path>
    get() = getCFiles(CLANG_C_PROGRAM_FOLDER)

  @JvmStatic
  val openJdkJavaFiles: ImmutableList<Path>
    get() = getJavaFiles(JAVA_PROGRAM_FOLDER)

  fun getFacade(languageKind: LanguageKind): AbstractParserFacade {
    return parserFacadeFactory.createParserFacade(languageKind)
  }

  fun generateAdhocFacade(
    combinedGrammerPath: Path,
    startRule: String,
    tokenNamesOfIdentifiers: List<String>,
    workingDir: Path,
    enablePnfNormalization: Boolean,
  ): AbstractParserFacade {
    val testPersesConstants = PersesConstants.createCustomizedConstants(workingDir)
    val testOptions = CommandOptions()
    testOptions.compulsoryFlags.parserGrammar = combinedGrammerPath
    testOptions.compulsoryFlags.lexerGrammar = null
    testOptions.compulsoryFlags.startRuleName = startRule
    testOptions.compulsoryFlags.existingLanguageKindClassFullName =
      LanguageAdhoc::class.java.canonicalName
    testOptions.compulsoryFlags.tokenNamesOfIdentifiers = tokenNamesOfIdentifiers

    testOptions.validate()
    val installer = AdhocGrammarInstaller(
      testOptions.computeAdhocGrammarConfiguration(),
      testPersesConstants,
      testOptions.outputFlags.output,
      enablePnfNormalization = enablePnfNormalization,
    )
    val generatedJar = installer.run()
    return generatedJar.loadMainClass().getConstructor().newInstance() as AbstractParserFacade
  }

  fun generateAdhocFacade(
    combinedGrammarName: String,
    combinedGrammarContent: String,
    startRule: String,
    tokenNamesOfIdentifiers: List<String>,
    workingDir: Path,
    enablePnfNormalization: Boolean,
  ): AbstractParserFacade {
    val grammarFile = workingDir.resolve("$combinedGrammarName.g4")
    grammarFile.writeText(
      """
      grammar $combinedGrammarName;
      
      $combinedGrammarContent
      """.trimIndent(),
    )
    return generateAdhocFacade(
      grammarFile,
      startRule,
      tokenNamesOfIdentifiers,
      workingDir,
      enablePnfNormalization = enablePnfNormalization,
    )
  }

  fun createAntlrToken(lexeme: String) = CommonToken(
    0, // dummy token type,
    lexeme,
  )

  fun parseFile(file: String): ParseTreeWithParser {
    return parseFile(Paths.get(file))
  }

  fun parseFile(file: Path): ParseTreeWithParser {
    val sourceFile = SourceFile(file, parserFacadeFactory.computeLanguageKindWithFileName(file)!!)
    val facade = getFacade(sourceFile.dataKind)
    return facade.parseFile(file)
  }

  fun parseString(sourceCode: String, languageKind: LanguageKind): ParseTreeWithParser {
    val facade = getFacade(languageKind)
    return facade.parseString(sourceCode)
  }

  @JvmStatic
  fun createTokenizedProgramFromFile(filepath: String): TokenizedProgram {
    val file = Paths.get(filepath)
    return createSparTreeFromFile(file).programSnapshot
  }

  fun createTokenizedProgramFromString(
    sourceCode: String,
    languageKind: LanguageKind,
  ): TokenizedProgram {
    return createSparTreeFromString(sourceCode, languageKind).programSnapshot
  }

  @JvmStatic
  fun createSparTreeFromFile(file: String): SparTree {
    return createSparTreeFromFile(Paths.get(file))
  }

  fun createSparTreeFromString(
    sourceCode: String,
    languageKind: LanguageKind,
    simplifyTree: Boolean = true,
  ): SparTree {
    val facade = getFacade(languageKind)
    return createSparTreeFromString(sourceCode, facade, simplifyTree)
  }

  fun createSparTreeFromString(
    sourceCode: String,
    facade: AbstractParserFacade,
    simplifyTree: Boolean,
  ): SparTree {
    val languageKind = facade.language
    val parseTreeWithParser = facade.parseString(sourceCode)
    val factory = createFactory(
      AbstractParserFacade.getTokens(parseTreeWithParser.tree),
      languageKind,
    )
    val sparTreeNodeFactory = SparTreeNodeFactory(
      facade.metaTokenInfoDb,
      factory,
      facade.ruleHierarchy,
    )
    return SparTreeBuilder(
      sparTreeNodeFactory,
      parseTreeWithParser,
      simplifyTree = simplifyTree,
    ).result
  }

  @JvmStatic
  fun createSparTreeFromFile(file: Path): SparTree {
    val (parseTree) = parseFile(file)
    val factory = createFactory(
      AbstractParserFacade.getTokens(parseTree),
      parserFacadeFactory.computeLanguageKindWithFileName(file)!!,
    )
    return createSparTreeFromFile(file, factory)
  }

  fun createSparTreeFromFile(file: Path, factory: TokenizedProgramFactory): SparTree {
    val sourceFile = SourceFile(file, parserFacadeFactory.computeLanguageKindWithFileName(file)!!)
    val facade = getFacade(sourceFile.dataKind)
    val parseTree = facade.parseFile(file)
    return SparTreeBuilder(
      SparTreeNodeFactory(facade.metaTokenInfoDb, factory, facade.ruleHierarchy),
      parseTree,
    ).result
  }

  private fun getCFiles(folder: Path): ImmutableList<Path> {
    return getFilesWithExtension(folder, ".c")
  }

  private fun getJavaFiles(folder: Path): ImmutableList<Path> {
    return getFilesWithExtension(folder, ".java")
  }

  private fun getGolangFiles(folder: Path): ImmutableList<Path> {
    return getFilesWithExtension(folder, ".go")
  }

  private fun getSolidityFiles(folder: Path): ImmutableList<Path> {
    return getFilesWithExtension(folder, ".sol")
  }

  private fun getRustFiles(folder: Path): ImmutableList<Path> {
    return getFilesWithExtension(folder, ".rs")
  }

  private fun getSmtFiles(folder: Path): ImmutableList<Path> {
    return getFilesWithExtension(folder, ".smt")
  }

  private fun getFilesWithExtension(
    folder: Path,
    fileExtension: String,
  ): ImmutableList<Path> {
    return try {
      Files.walk(folder)
        .filter { path: Path -> Files.isRegularFile(path) }
        .filter { path: Path ->
          path.toString().endsWith(
            fileExtension,
          )
        }
        .sorted()
        .collect(ImmutableList.toImmutableList())
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }

  fun extractTokens(tree: ParseTree): ArrayList<Token> {
    val result = ArrayList<Token>()
    preOrderTraverse(tree) { e: Token -> result.add(e) }
    return result
  }

  @JvmStatic
  fun extractTokenTexts(tree: ParseTree): ImmutableList<String> {
    return extractTokens(tree)
      .filter { it.type != Token.EOF }
      .map { it.text }
      .toImmutableList()
  }

  @JvmStatic
  fun getBazelPathForTestingResource(klass: Class<*>, resourceName: String): String {
    val pkgName = klass.getPackage().name.replace('.', '/')
    return "test/$pkgName/$resourceName"
  }

  fun createCleanWorkingDirectory(klass: Class<*>): Path {
    return Files.createTempDirectory(klass.simpleName + "_temp_")
  }

  fun getNodeWithTokens(
    tree: SparTree,
    tokens: ImmutableList<String>,
    ruleName: String,
  ): AbstractSparTreeNode {
    val map = createNodeToTokensMap(tree)
    return map.getNode(tokens, ruleName)
  }

  fun constructNodeRetrievalCode(tree: SparTree, node: AbstractSparTreeNode): String {
    val map = createNodeToTokensMap(tree)
    return (
      "TestUtility.getNodeWithTokens(tree, " +
        map.constructTokenListCode(node) +
        ", \"" +
        node.ruleName +
        "\");"
      )
  }

  fun createNodeToTokensMap(tree: SparTree): NodeToTokensMap {
    val builder = HashMap<AbstractSparTreeNode, ImmutableList<String>>()
    recursiveCreateNodeToTokensMap(builder, tree.root)
    return NodeToTokensMap(ImmutableMap.copyOf(builder))
  }

  private fun recursiveCreateNodeToTokensMap(
    builder: HashMap<AbstractSparTreeNode, ImmutableList<String>>,
    node: AbstractSparTreeNode,
  ) {
    if (node.isTokenNode) {
      val tokens = ImmutableList.of(node.asLexerRule().token.text)
      builder[node] = tokens
      return
    }
    val value = ImmutableList.builder<String>()
    val childCount = node.childCount
    for (i in 0 until childCount) {
      val child = node.getChild(i)
      recursiveCreateNodeToTokensMap(builder, child)
      value.addAll(builder[child]!!)
    }
    builder[node] = value.build()
  }

  private fun preOrderTraverse(tree: ParseTree, consumer: (Token) -> Unit) {
    if (tree is TerminalNode) {
      consumer.invoke(tree.symbol)
      return
    }
    var i = 0
    val size = tree.childCount
    while (i < size) {
      preOrderTraverse(tree.getChild(i), consumer)
      ++i
    }
  }

  class NodeToTokensMap(
    private val map: ImmutableMap<AbstractSparTreeNode, ImmutableList<String>>,
  ) {
    fun getTokens(node: AbstractSparTreeNode): ImmutableList<String> {
      return map[node]!!
    }

    fun getNode(tokens: ImmutableList<String>, ruleName: String): AbstractSparTreeNode {
      var result: AbstractSparTreeNode? = null
      for ((key, value) in map) {
        if (value == tokens && key.ruleName == ruleName) {
          check(result == null) { "duplicates: $result, \n${key.printTreeStructure()}" }
          result = key
        }
      }
      return result!!
    }

    fun constructTokenListCode(node: AbstractSparTreeNode): String {
      val builder = StringBuilder()
      builder.append("ImmutableList.of(")
      val tokens = map[node]!!
      for (i in tokens.indices) {
        if (i != 0) {
          builder.append(", ")
        }
        builder.append('"').append(tokens[i]).append('"')
      }
      builder.append(")")
      return builder.toString()
    }
  }
}

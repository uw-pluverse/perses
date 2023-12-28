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
package org.perses.antlr.atn

import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.atn.BasicState
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.misc.IntervalSet
import org.junit.Assert
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.TokenType
import org.perses.antlr.atn.LexerAtnWrapper.TokenTypePair
import org.perses.antlr.atn.LexerAtnWrapper.TokenTypePair.Companion.toTokenTypePair
import org.perses.antlr.atn.nfa.MutableNFA
import org.perses.antlr.atn.simulator.ast.AbstractASTSimulator
import org.perses.antlr.atn.simulator.transition.PrintableCharacters
import org.perses.antlr.atn.tdtree.AbstractTDTreeNode
import org.perses.antlr.atn.tdtree.AlternativeBlockTDTreeNode
import org.perses.antlr.atn.tdtree.CharTDTreeNode
import org.perses.antlr.atn.tdtree.OptionalTDTreeNode
import org.perses.antlr.atn.tdtree.StarTDTreeNode
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.antlr.toTokenType
import org.perses.util.SimpleStack

@RunWith(JUnit4::class)
class AtnTest {

  val testLexerClass = TestLexer::class.java

  private val emptyRandom = DecisionMakerMock.createEmpty()
  private val defaultRandom = AbstractDecisionMaker.DefaultDecisionMaker(seed = 1L)

  val testAtn = LexerAtnWrapper(testLexerClass)
  val atnC = LexerAtnWrapper(OrigCLexer::class.java)

  @Test
  fun testIdentifierNFAShouldRejectInvalidIdentiers() {
    val exception = Assert.assertThrows(java.lang.Exception::class.java) {
      atnC.findATNPathForLexeme(
        ruleType = OrigCLexer.Identifier.toTokenType(),
        lexeme = "A0\"\\x00\\u0p0",
      )
    }
    assertThat(exception).hasMessageThat().contains("#paths=0")
  }

  @Test
  fun testStringLiteralNFAShouldAcceptUnicode() {
    val path = atnC.findATNPathForLexeme(
      ruleType = OrigCLexer.StringLiteral.toTokenType(),
      lexeme = "\"\u00a5\"",
    )
    assertThat(path.stateSequence.first()).isInstanceOf(RuleStartState::class.java)
    assertThat(path.stateSequence.last()).isInstanceOf(RuleStopState::class.java)
  }

  @Test
  fun testSimulatingRegexTreeForIdentifier() {
    val regex = atnC.getNormalizedAtn(OrigCLexer.Identifier.toTokenType()).second
    val simulator = AbstractASTSimulator.create(regex)
    val tdtree = simulator.simulate(AbstractDecisionMaker.DefaultDecisionMaker(seed = 1L))
    // FIXME: need a better test here.
    assertThat(tdtree.toLexeme()).isNotEmpty()
  }

  @Test
  fun testParsingIdentifierSingleChar() {
    atnC.createTDTree("a", OrigCLexer.Identifier.toTokenType()).let { tree ->
      assertThat(tree.toLexeme()).isEqualTo("a")
    }
  }

  @Test
  fun testParsingIdentifierTwoChars() {
    atnC.createTDTree("a9", OrigCLexer.Identifier.toTokenType()).let { tree ->
      assertThat(tree.toLexeme()).isEqualTo("a9")
    }
  }

  @Test
  fun testRuleIndicesAreCorrect() {
    val info = testAtn.metaTokenInfoDB.getTokenInfoWithName("Long")!!
    assertThat(info.tokenType).isEqualTo(TestLexer.Long.toTokenType())
  }

  @Test
  fun testRuleNamesAndTypes() {
    val tokenTypeSingleChar = TestLexer.SingleChar.toTokenType()
    val tokenTypeCharSet = TestLexer.CharSet.toTokenType()
    val ruleNameCharSet = "CharSet"
    val ruleNameSingleChar = "SingleChar"

    val info = testAtn.metaTokenInfoDB
    assertThat(info.getTokenInfoWithName(ruleNameSingleChar)!!.tokenType).isEqualTo(
      tokenTypeSingleChar,
    )
    assertThat(info.getTokenInfoWithName(ruleNameCharSet)!!.tokenType).isEqualTo(tokenTypeCharSet)
  }

  @Test
  fun testSimulatingSingleChar() {
    val result = testAtn.simulateRule(TestLexer.SingleChar.toTokenType(), emptyRandom).toLexeme()
    assertThat(result).isEqualTo("A")
  }

  @Test
  fun testSimulatingCharSet() {
    val random = DecisionMakerMock(
      listOf(),
      listOf(0, 1),
    )
    val generator: () -> String = {
      testAtn.simulateRule(TestLexer.CharSet.toTokenType(), random).toLexeme()
    }
    generator().let { result ->
      assertThat(result).isEqualTo("a")
    }
    generator().let { result ->
      assertThat(result).isEqualTo("b")
    }
  }

  @Test
  fun testSimulatingTwoChars() {
    val result = testAtn.simulateRule(TestLexer.TwoChars.toTokenType(), emptyRandom).toLexeme()
    assertThat(result).isEqualTo("AB")
  }

  @Test
  fun testSimulatingNotADigit() {
    val random = DecisionMakerMock(
      listOf(),
      listOf(0, ' '.code),
    )
    val generator: () -> String = {
      testAtn.simulateRule(TestLexer.NotADigit.toTokenType(), random).toLexeme()
    }
    generator().let {
      assertThat(it).isEqualTo(' '.toString())
    }
    generator().let {
      assertThat(it).isEqualTo("J")
    }
  }

  @Test
  fun testSimulatingKleenePlusSingleChar() {
    // TODO: need to support loops.
    val random = DecisionMakerMock(
      listOf(true, true, false, false, true, false),
      listOf(),
    )
    val result = testAtn.simulateRule(TestLexer.KleenePlusOnSingleChar.toTokenType(), random)
    assertThat(result.toLexeme()).matches("a+")
  }

  @Test
  fun testSimulatingWildcard() {
    val result = testAtn.simulateRule(
      TestLexer.Wildcard.toTokenType(),
      DecisionMakerMock(
        listOf(),
        listOf(1),
      ),
    ).toLexeme()
    assertThat(result).hasLength(2)
    assertThat(result.first()).isEqualTo('a')
    val last = result.last()
    assertThat(last).isIn(PrintableCharacters.ALL_PRINTABLE_CHARS_LIST)
  }

  @Test
  fun testKleeneStar() {
    val random = DecisionMakerMock(
      listOf(true, false, true, true, true, false, false, false, true, false),
      listOf(),
    )
    val generator: () -> TDTree = {
      testAtn.simulateRule(
        TestLexer.KleeneStar.toTokenType(),
        random,
      )
    }
    val result = ArrayList<TDTree>()
    result.add(generator())
    result.add(generator())
    result.add(generator())
    result.add(generator())

    result.filter { it.toLexeme().length >= "ab".length }.forEach { tree ->
      val root = tree.root
      assertThat(root.childCount).isEqualTo(2)
      assertThat(root.getChild(0)).isInstanceOf(CharTDTreeNode::class.java)
      assertThat(root.getChild(1)).isInstanceOf(StarTDTreeNode::class.java)

      val star = root.getChild(1) as StarTDTreeNode
      if (star.childCount > 0) {
        star.forEachChild { child ->
          assertThat(child).isInstanceOf(AlternativeBlockTDTreeNode::class.java)
        }
      }
    }
    assertThat(result.distinct()).hasSize(result.size)

    result.map { it.toLexeme() }.forEach {
      assertThat(it).matches("ab*")
    }
  }

  @Test
  fun testAlternative() {
    // Alternative in lexer rules is handled as CharSet.
    val random = DecisionMakerMock(
      listOf(),
      listOf(0, 1),
    )
    val ruleType = TestLexer.Alt.toTokenType()
    val generator: () -> String = {
      testAtn.simulateRule(ruleType, random).toLexeme()
    }

    generator().let {
      assertThat(it).isEqualTo("A")
    }
    generator().let {
      assertThat(it).isEqualTo("a")
    }
  }

  @Test
  fun testOptionalChar() {
    val random = DecisionMakerMock(
      listOf(true, false),
      listOf(),
    )
    val generator: () -> TDTree = {
      testAtn.simulateRule(
        TestLexer.OptionalChar.toTokenType(),
        random,
      )
    }
    val result = ArrayList<TDTree>()
    result.add(generator())
    result.add(generator())
    assertThat(result.map { it.toLexeme() }).containsExactly("a", "ab")
    result.single { it.toLexeme() == "ab" }.let { tree ->
      val root = tree.root
      assertThat(root.childCount).isEqualTo(2)
      assertThat(root.getChild(0)).isInstanceOf(CharTDTreeNode::class.java)
      assertThat(root.getChild(0).toLexeme()).isEqualTo("a")
      assertThat(root.getChild(1)).isInstanceOf(OptionalTDTreeNode::class.java)
      assertThat(root.getChild(1).toLexeme()).isAnyOf("", "b")
    }
  }

  @Test
  fun testOptionalSequence() {
    val random = DecisionMakerMock(
      listOf(true, false),
      listOf(),
    )
    val generator: () -> TDTree = {
      testAtn.simulateRule(TestLexer.OptionalSequence.toTokenType(), random)
    }
    val result = ArrayList<TDTree>()
    result.add(generator())
    result.add(generator())
    assertThat(result.map { it.toLexeme() }).containsExactly("abcde", "e")
    result.single { it.toLexeme() == "abcde" }.let { tree ->
      val root = tree.root
      assertThat(root.childCount).isEqualTo(2)
      assertThat(root.getChild(0)).isInstanceOf(OptionalTDTreeNode::class.java)
      assertThat(root.getChild(1)).isInstanceOf(CharTDTreeNode::class.java)
    }
  }

  @Test
  fun testGetPathForSingleChar() {
    val path = testAtn.findATNPathForLexeme("A", TestLexer.SingleChar.toTokenType())
    assertThat(path.stateSequence.first()).isInstanceOf(RuleStartState::class.java)
    assertThat(path.stateSequence.last()).isInstanceOf(RuleStopState::class.java)
  }

  @Test
  fun testConstructTreeForSingleChar() {
    val tree = testAtn.createTDTree("A", TestLexer.SingleChar.toTokenType())
    assertThat(tree.toLexeme()).isEqualTo("A")
  }

  @Test
  fun testConstructTreeForKleenePlusOnSingleChar() {
    val lexeme = "aaaaaaa"
    val tree = testAtn.createTDTree(lexeme, TestLexer.KleenePlusOnSingleChar.toTokenType())
    assertThat(tree.toLexeme()).isEqualTo(lexeme)
  }

  @Test
  fun testFragmentOfNatualNumber() {
    val lexeme = testAtn.simulateRule(
      TestLexer.NaturalNumber.toTokenType(),
      DecisionMakerMock(listOf(false), listOf(0)),
    ).toLexeme()
    assertThat(lexeme).isEqualTo("0")
  }

  @Test
  fun testFragmentOfLong() {
    val lexeme = testAtn.simulateRule(
      TestLexer.Long.toTokenType(),
      DecisionMakerMock(listOf(true, true, true, false), listOf(1, 2, 3, 4)),
    ).toLexeme()
    assertThat(lexeme).isEqualTo("1234L")
  }

  @Ignore("cannot pass now")
  @Test
  fun testSimulatingConstant() {
    val regex = atnC.getNormalizedAtn(OrigCLexer.Constant.toTokenType()).second
    println(regex.sourceCode)
    val lexeme = atnC.simulateRule(
      OrigCLexer.Constant.toTokenType(),
      AbstractDecisionMaker.DefaultDecisionMaker(seed = 1L),
    ).toLexeme()
    assertThat(lexeme).isEqualTo("")
  }

  @Test
  fun testAllRulesOfTestLexer() {
    testAtnWithAllItsLexerRules(testAtn)
  }

  @Ignore("cannot pass now")
  @Test
  fun testAllRulesOfOrigCLexer() {
    val atn = atnC
    testAtnWithAllItsLexerRules(atn, setOf("Identifier"))
  }

  private fun <T : Lexer> testAtnWithAllItsLexerRules(
    atn: LexerAtnWrapper<T>,
    excluded: Set<String> = setOf(),
  ) {
    val tokens = atn.metaTokenInfoDB.asSequence().toList()
    assertThat(tokens).isNotEmpty()
    val random = defaultRandom
    tokens.forEach { tokenInfo ->
      if (excluded.contains(tokenInfo.symbolicName)) {
        return@forEach
      }
      System.err.println("Testing $tokenInfo")
      try {
        testSimulationAndTDTreeReconstruction(atn, tokenInfo.tokenType, random)
      } catch (e: Exception) {
        throw Exception("Exception when testing $tokenInfo", e)
      }
    }
  }

  private fun testSimulationAndTDTreeReconstruction(
    atnWrapper: LexerAtnWrapper<*>,
    ruleType: TokenType,
    decisionMaker: AbstractDecisionMaker.DefaultDecisionMaker,
  ) {
    val origTree = atnWrapper.simulateRule(ruleType, decisionMaker)
    val lexeme = origTree.toLexeme()
    val reconstructedTree = atnWrapper.createTDTree(lexeme, ruleType)
    assertIsomorphic(ruleType, origTree, reconstructedTree)
    assertWithMessage(ruleType.toString()).that(lexeme).isEqualTo(reconstructedTree.toLexeme())
  }

  private fun assertIsomorphic(ruleType: TokenType, t1: TDTree, t2: TDTree) {
    val stack = SimpleStack<Pair<AbstractTDTreeNode, AbstractTDTreeNode>>()
    assertWithMessage(ruleType.toString()).that(t1.root::class.java).isEqualTo(t2.root::class.java)
    stack.add(Pair(t1.root, t2.root))
    while (stack.isNotEmpty()) {
      val pair = stack.remove()
      val n1 = pair.first
      val n2 = pair.second
      assertWithMessage(ruleType.toString()).that(n1::class.java).isEqualTo(n2::class.java)
      assertWithMessage(ruleType.toString()).that(n1.childCount).isEqualTo(n2.childCount)
      if (n1 is CharTDTreeNode) {
        check(n2 is CharTDTreeNode)
        assertWithMessage(ruleType.toString()).that(n1.char.code).isEqualTo(n2.char.code)
      }
      val childCount = n1.childCount
      for (i in 0 until childCount) {
        stack.add(Pair(n1.getChild(i), n2.getChild(i)))
      }
    }
  }

  @Test
  fun testNfasCanBeConcatWithoutSpace() {
    listOf(
      Pair("Identifier", "PlusPlus"),
      Pair("LessEqual", "Less"),
    ).forEach {
      assertWithMessage(it.toString()).that(
        atnC.canBeConcatWithoutSpace(it.first, it.second),
      ).isTrue()
    }
  }

  @Test
  fun testCanBeConcatWithoutSpaceWithTokenType() {
    listOf(
      Pair(OrigCLexer.Identifier, OrigCLexer.PlusPlus),
      Pair(OrigCLexer.LessEqual, OrigCLexer.Less),
    ).map { it.first.toTokenType() to it.second.toTokenType() }
      .forEach {
        assertWithMessage(it.toString()).that(
          atnC.canBeConcatWithoutSpace(it.first, it.second),
        )
      }
  }

  @Test
  fun testNfasConcatSpaceRequired() {
    listOf(
      Pair("Int", "Identifier"), // 'Int' is the keyword 'int'
      Pair("Identifier", "Identifier"),
    ).forEach {
      assertWithMessage(it.toString()).that(
        atnC.canBeConcatWithoutSpace(it.first, it.second),
      ).isFalse()
    }
  }

  @Test
  fun testCacheForCanBeConcat() {
    var entryCounter = 0
    val newAtnC = LexerAtnWrapper(OrigCLexer::class.java)
    listOf(
      Pair(OrigCLexer.Int, OrigCLexer.Identifier), // 'Int' is the keyword 'int'
      Pair(OrigCLexer.Identifier, OrigCLexer.PlusPlus),
    ).map { it.first.toTokenType() to it.second.toTokenType() }
      .forEach {
        entryCounter += 1
        val firstResult = newAtnC.canBeConcatWithoutSpace(it.first, it.second)
        assertThat(
          newAtnC.tokenTypePairToNecessityOfWhiteSpaceForConcat.containsKey(it.toTokenTypePair()),
        ).isTrue()
        assertThat(newAtnC.tokenTypePairToNecessityOfWhiteSpaceForConcat.size)
          .isEqualTo(entryCounter)

        val secondResult = newAtnC.canBeConcatWithoutSpace(it.first, it.second)
        assertThat(
          newAtnC.tokenTypePairToNecessityOfWhiteSpaceForConcat.containsKey(it.toTokenTypePair()),
        ).isTrue()
        assertThat(newAtnC.tokenTypePairToNecessityOfWhiteSpaceForConcat.size)
          .isEqualTo(entryCounter)

        assertThat(firstResult).isEqualTo(secondResult)
      }
  }

  @Test
  fun testConcatSpaceRequiredWithTokenType() {
    listOf(
      Pair(OrigCLexer.Int, OrigCLexer.Identifier), // 'Int' is the keyword 'int'
      Pair(OrigCLexer.Identifier, OrigCLexer.Identifier),
    ).map { it.first.toTokenType() to it.second.toTokenType() }
      .forEach {
        assertWithMessage(it.toString()).that(
          atnC.canBeConcatWithoutSpace(it.first, it.second),
        ).isFalse()
      }
  }

  @Test
  fun testNfaCanBeSubsumed() {
    listOf(
      Triple(
        OrigCLexer.LessEqual.toTokenType(),
        OrigCLexer.Less.toTokenType(),
        OrigCLexer.Assign.toTokenType(),
      ),
    ).forEach {
      assertWithMessage(it.toString()).that(
        atnC.canBeSubsumed(it.first, it.second, it.third),
      ).isTrue()
    }
  }

  @Test
  fun testNfaCanNotBeSubsumed() {
    assertThat(
      atnC.canBeSubsumed(
        OrigCLexer.StringLiteral.toTokenType(),
        OrigCLexer.Identifier.toTokenType(),
        OrigCLexer.PlusPlus.toTokenType(),
      ),
    ).isFalse()
  }

  @Test
  fun testGetReachableStatesWithNonEpsilonTransition() {
    var id = 0
    val start = RuleStartState().apply { stateNumber = id++ }
    val state1 = BasicState().apply { stateNumber = id++ }
    val state2 = BasicState().apply { stateNumber = id++ }
    val end = RuleStopState().apply { stateNumber = id++ }
    start.stopState = end

    val epsilonToState1 = EpsilonTransition(state1)
    start.addTransition(epsilonToState1)

    val nonEpsilonToState2 = SetTransition(state2, IntervalSet.of(97))
    state1.addTransition(nonEpsilonToState2)

    val epsilonToEnd = EpsilonTransition(end)
    state1.addTransition(epsilonToEnd)

    val nfa = MutableNFA.copyOf(start)

    val result = LexerAtnWrapper.getReachableStatesWithNonEpsilonOutgoingTransition(
      nfa.createNFAState { it.startState },
    ).map {
      it.state.stateNumber
    }
    assertThat(result).containsExactly(state1.stateNumber, end.stateNumber)
  }

  @Test
  fun testApproximateOf() {
    val regex = testAtn.getNormalizedAtn(TestLexer.NonRegexToken.toTokenType()).second.sourceCode
    val readableRegex = regex.replace(Regex("\\d+")) { match ->
      val number = match.value.toInt()
      if (number in 32..126) {
        val character = number.toChar()
        character.toString()
      } else {
        match.value
      }
    }
    assertThat(readableRegex).isEqualTo(
      """
        # (# (# a # # # | a # #) | a #)
        | a
      """.trimIndent(),
    )
  }

  @Test
  fun testEqualityAndHashCodeOfTokenTypePair() {
    val first = TokenTypePair(TokenType(1), TokenType(2))
    val second = TokenTypePair(TokenType(1), TokenType(2))
    assertThat(first).isEqualTo(second)
    assertThat(first.hashCode()).isEqualTo(second.hashCode())
  }
}

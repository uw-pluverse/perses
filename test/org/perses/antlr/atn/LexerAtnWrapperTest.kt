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
package org.perses.antlr.atn

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import objectexplorer.MemoryMeasurer
import org.antlr.v4.runtime.BaseErrorListener
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.AtomTransition
import org.antlr.v4.runtime.atn.BasicState
import org.antlr.v4.runtime.atn.EpsilonTransition
import org.junit.Assert
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.TokenType
import org.perses.antlr.toTokenType
import org.perses.grammar.jackson.JacksonParserFacade
import org.perses.grammar.python3.Python3Lexer
import org.perses.grammar.rust.PnfRustLexer
import org.perses.util.SpaceSize

@RunWith(JUnit4::class)
class LexerAtnWrapperTest {
  val c = LexerAtnWrapper.createLexerWrapperFromLexerClass(OrigCLexer::class.java)
  val rust = LexerAtnWrapper.createLexerWrapperFromLexerClass(PnfRustLexer::class.java)
  val test = LexerAtnWrapper.createLexerWrapperFromLexerClass(TestLexer::class.java)
  val javascript = LexerAtnWrapper.createLexerWrapperFromLexerClass(TestJavaScriptLexer::class.java)
  val python = LexerAtnWrapper.createLexerWrapperFromLexerClass(Python3Lexer::class.java)

  @Test
  fun testGetAcyclicPathsToGenerateGivenTokenType() {
    val result =
      python.getAcyclicPathsToGenerateGivenTokenType(Python3Lexer.NEWLINE.toTokenType())
    assertThat(result).isNotEmpty()
  }

  @Test
  fun testGenerateCandidateCanonicalTokenTestsGivenTokenType() {
    val result =
      python.generateCandidateCanonicalTokenTextsGivenTokenType(
        ruleType = TokenType(Python3Lexer.NEWLINE),
        countLimit = 2,
      )
    assertThat(result).containsExactly("\n", " ")
  }

  @Test
  fun testHasInformationForTokenFalse() {
    val wrapper = JacksonParserFacade().lexerAtnWrapper
    val tokens = wrapper.metaTokenInfoDB.tokens
    tokens.forEach { token ->
      assertThat(wrapper.hasInformationForToken(token.tokenType)).isFalse()
    }
    assertThat(wrapper.hasInformationForToken(100000.toTokenType())).isFalse()
    assertThat(wrapper.hasInformationForToken(999999.toTokenType())).isFalse()
  }

  @Test
  fun testHasInformationForTokenTrue() {
    val wrapper = python
    listOf(Python3Lexer.FOR, Python3Lexer.IF, Python3Lexer.WHILE)
      .map { it.toTokenType() }
      .forEach {
        assertThat(wrapper.hasInformationForToken(it)).isTrue()
      }
    assertThat(wrapper.hasInformationForToken(Python3Lexer.INDENT.toTokenType())).isFalse()
    assertThat(wrapper.hasInformationForToken(Python3Lexer.DEDENT.toTokenType())).isFalse()
  }

  @Test
  fun test() {
    c.metaTokenInfoDB
      .asSequence()
      .zip(c.metaTokenInfoDB.asSequence())
      .forEach { (first, second) ->
        println("$first, $second")
        try {
          c.canBeConcatWithoutSpace(first.tokenType, second.tokenType)
        } catch (e: Throwable) {
          Assert.fail(
            buildString {
              appendLine("processing $first, $second")
              appendLine("Exception message: ${e.message}")
              appendLine("Stack trace:")
              appendLine(e.stackTraceToString())
            },
          )
        }
      }
    val klasses = HashSet<Class<*>>()
    val bytes =
      MemoryMeasurer
        .measureBytes(c) {
          val klass = it::class.java
          klasses.add(klass)
          true
        }
    klasses.sortedBy { it.canonicalName }.forEach { println(it) }
    assertThat(bytes).isLessThan(SpaceSize.megaBytes(11L).bytes)
  }

  @Ignore("The current algorithm does not handle non-greedy matching.")
  @Test
  fun testBlockCommentWithBlockComment() {
    val tokenType = OrigCLexer.BlockComment.toTokenType()
    assertThat(c.canBeConcatWithoutSpace(tokenType, tokenType)).isTrue()
  }

  @Ignore
  @Test
  fun testCanBeSubsumedForNonGreedyMatching() {
    val nfa = test.copyTokenNfa(TestLexer.GreedyWildcard.toTokenType())
    println(nfa.printTopology())
    val nfa2 = test.copyTokenNfa(TestLexer.NonGreedyWildcard.toTokenType())
    println(nfa2.printTopology())
    Assert.fail()
  }

  @Test
  fun testJavaScriptStringLiteral() {
    val atnPath =
      javascript.findATNPathForLexeme(
        lexeme = "''",
        ruleType = javascript.metaTokenInfoDB.getTokenInfoWithName("StringLiteral")!!.tokenType,
      )!!
    assertThat(atnPath.stateSequence).isNotEmpty()
  }

  /**
   * Regression guard for the primary ATN-extraction bug. The traversal used to
   * walk the original (non-inlined) ATN and treat ANTLR's call/return epsilon
   * edges as ordinary epsilons. `DoubleFragRef : 'a' FX 'b' FX 'c'` references
   * fragment `FX` twice, so `FX`'s single `RuleStopState` has two synthesized
   * return edges; returning from the first `FX` call via the *second* call
   * site's return edge short-circuited the middle and yielded the invalid "axc".
   * The fix runs the traversal on the normalized (inlined) ATN, which has no
   * rule transitions, so the only generated lexeme is the correct "axbxc".
   * See internal_doc/lexer_atn_wrapper_extraction_bugs.md.
   */
  @Test
  fun testBugDoubleFragRefGeneratesInvalidCanonicalText() {
    val tokenType = test.metaTokenInfoDB.getTokenInfoWithName("DoubleFragRef")!!.tokenType
    val texts = test.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 10)
    assertThat(texts).containsExactly("axbxc")
  }

  /**
   * Same bug, guarded semantically: every canonical text the generator emits for
   * a token type must actually lex back to that same token type via the real
   * ANTLR lexer. The pre-fix "axc" violated this; "axbxc" satisfies it.
   * `DoubleFragRef` is declared first in the grammar so it wins the maximal-munch
   * tie against `NegationAndPlus` (~[\n]+), which also matches "axbxc".
   */
  @Test
  fun testBugGeneratedCanonicalTextsMustLexBackToSameToken() {
    val tokenInfo = test.metaTokenInfoDB.getTokenInfoWithName("DoubleFragRef")!!
    val tokenType = tokenInfo.tokenType
    val expectedAntlrType = tokenInfo.tokenType.antlrTokenType
    val texts = test.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 10)
    assertThat(texts).isNotEmpty()
    texts.forEach { lexeme ->
      assertThat(lexesAsSingleToken(lexeme, expectedAntlrType)).isTrue()
    }
  }

  /**
   * The inlined-NFA path API handles the call/return network correctly, because
   * `MutableNfa.copyAndInlineOf` clones each `FX` call site separately and
   * connects each clone's stop to that call's own follow state. It accepts the
   * real lexeme "axbxc" and rejects the short-circuited "axc". Pre-fix this held
   * even while `getAcyclicPathsToGenerateGivenTokenType` was wrong, which is what
   * pointed the fix at reusing the inlined ATN for the traversal too.
   */
  @Test
  fun testInlinedPathApiHandlesDoubleFragRefCorrectly() {
    val tokenType = test.metaTokenInfoDB.getTokenInfoWithName("DoubleFragRef")!!.tokenType
    assertThat(test.findATNPathForLexeme("axbxc", tokenType)).isNotNull()
    assertThat(test.findATNPathForLexeme("axc", tokenType)).isNull()
  }

  /**
   * Regression guard for Bug 2. `getAllReachablePathsRecursive` used to share a
   * single `visitedTransitions` set across the whole traversal and never clear it
   * on backtrack, so any non-epsilon transition reachable through *more than one*
   * epsilon route was recorded for only the first route. The fix tracks visited
   * states per traversal path instead.
   *
   * Hand-built diamond (epsilons unless noted):
   * ```
   *        start
   *        /   \        (both epsilon)
   *       A     B
   *        \   /        (both epsilon)
   *          C --x--> D (atom)
   * ```
   * Two distinct paths reach the atom transition C--x-->D: [A, C, D] and
   * [B, C, D], and both must be returned. The pre-fix global visited set marked
   * C-->D after the [A, C, D] route and dropped [B, C, D].
   * See internal_doc/lexer_atn_wrapper_extraction_bugs.md.
   */
  @Test
  fun testBugGetAllReachablePathsDropsConvergingPath() {
    // Distinct stateNumbers are required because ANTLR's ATNState hashes/compares
    // by stateNumber; states sharing the default -1 would collide.
    fun basicState(number: Int) = BasicState().apply { stateNumber = number }
    val d = basicState(1)
    val c = basicState(2).apply { addTransition(AtomTransition(d, 'x'.code)) }
    val a = basicState(3).apply { addTransition(EpsilonTransition(c)) }
    val b = basicState(4).apply { addTransition(EpsilonTransition(c)) }
    val start =
      basicState(5).apply {
        addTransition(EpsilonTransition(a))
        addTransition(EpsilonTransition(b))
      }

    val paths = test.getAllReachablePaths(start)

    // Correct behavior: both routes to the atom transition are reported.
    assertThat(paths.map { it.stateSequence })
      .containsExactly(
        ImmutableList.of(a, c, d),
        ImmutableList.of(b, c, d),
      )
  }

  /**
   * Regression guard for the overlapping-char-class ambiguity bug, using the
   * dedicated `OverlappingChar : 'a'..'z' | WiderLower` rule (`WiderLower :
   * [a-zµ]` is a superset of a-z), which mirrors the shape of Scala's `Lower :
   * 'a'..'z' | UnicodeClass_LL`.
   *
   * Before the fix, the two overlapping alternatives compiled to two transitions
   * accepting the same character, so the character 'a' had two accepting paths
   * and [findATNPathForLexeme] threw "There should be exactly 1 path" on a string
   * it had just confirmed is accepted -- which is why identifier detection
   * probing this API scored such rules as 0.
   *
   * `ATNConstructorFromRegex` now merges single-character alternatives into one
   * set transition (union of intervals), so the rule is deterministic and the
   * lexeme has a unique path. See `testOverlappingAlternativesMergedIntoOneSet`.
   */
  @Test
  fun testFindATNPathUniqueForOverlappingCharClassRule() {
    val overlapping = test.metaTokenInfoDB.getTokenInfoWithName("OverlappingChar")!!.tokenType

    // 'a' is accepted by both overlapping alternatives; the merge collapses them
    // so the lexeme resolves to a unique path instead of throwing.
    assertThat(test.findATNPathForLexeme("a", overlapping)).isNotNull()

    // A flat identifier rule (Python's NAME) was always fine -- still is.
    assertThat(python.findATNPathForLexeme("foo", Python3Lexer.NAME.toTokenType())).isNotNull()

    // A genuine non-member is still rejected with null ('0' is outside both
    // alternatives).
    assertThat(test.findATNPathForLexeme("0", overlapping)).isNull()
  }

  /**
   * Guards the source-level fix: `ATNConstructorFromRegex` merges the overlapping
   * `OverlappingChar : 'a'..'z' | WiderLower` alternatives into a single set
   * transition, so 'a' has exactly ONE accepting path (it had two before the
   * merge), consumed by one atom whose label is the union of the alternatives.
   */
  @Test
  fun testOverlappingAlternativesMergedIntoOneSet() {
    val overlapping = test.metaTokenInfoDB.getTokenInfoWithName("OverlappingChar")!!.tokenType
    val start = test.getNormalizedAtn(overlapping).first
    val stop: ATNState = start.stopState

    // Same path enumeration as findATNPathForLexeme, but without the uniqueness check.
    var paths = listOf(LexerAtnWrapper.ATNPath.create(start as ATNState))
    for (ch in "a") {
      val next = ArrayList<LexerAtnWrapper.ATNPath>()
      for (p in paths) {
        for (seg in test.getAllReachablePaths(p.lastState, ch)) {
          next.add(p.append(seg))
        }
      }
      paths = next
    }
    val surviving = paths.filter { reachesStopViaEpsilons(it.lastState, stop) }

    // Exactly one accepting path now, consuming the single char as one atom.
    assertThat(surviving).hasSize(1)
    val labels = atomLabels(surviving.single())
    assertThat(labels).hasSize(1)
    // The merged label is the union of 'a'..'z' and [a-zµ] (µ = U+00B5 = 181).
    assertThat(labels.single()).contains("97..122") // 'a'..'z'
    assertThat(labels.single()).contains("181") // the extra 'µ' from WiderLower
  }

  /**
   * Fix #1 regression: a star/plus over an overlapping alternation
   * (`OverlappingId : OverlappingChar+`) has 2^n epsilon-routing path
   * representations for an n-char lexeme, but they are vacuous duplicates (same
   * atom transitions). findATNPathForLexeme must collapse them into one unique
   * path instead of throwing on the old uniqueness check.
   */
  @Test
  fun testStarredOverlappingRuleCollapsesToUniquePath() {
    val overlappingId = test.metaTokenInfoDB.getTokenInfoWithName("OverlappingId")!!.tokenType
    // Several lengths: each had 2^n path representations before the collapse.
    assertThat(test.findATNPathForLexeme("a", overlappingId)).isNotNull()
    assertThat(test.findATNPathForLexeme("aaa", overlappingId)).isNotNull()
    assertThat(test.findATNPathForLexeme("abcde", overlappingId)).isNotNull()
    // A non-member is still rejected.
    assertThat(test.findATNPathForLexeme("a0", overlappingId)).isNull()
  }

  /**
   * Even genuine structural ambiguity resolves to a single path. `AmbiguousSplit
   * : 'a'+ 'a'+` tokenizes "aaa" as either (1,2) or (2,1) across the two
   * plus-blocks; both yield the token text "aaa", so findATNPathForLexeme returns
   * one deterministic representative rather than rejecting the lexeme. (Telling
   * such genuine ambiguity apart from the far more common vacuous overlap is not
   * possible once simplifyToRegex has flattened the grammar structure, and any
   * valid decomposition is fine for TD-tree construction.)
   */
  @Test
  fun testGenuinelyAmbiguousRuleResolvesToUniquePath() {
    val ambiguous = test.metaTokenInfoDB.getTokenInfoWithName("AmbiguousSplit")!!.tokenType
    assertThat(test.findATNPathForLexeme("aa", ambiguous)).isNotNull()
    assertThat(test.findATNPathForLexeme("aaa", ambiguous)).isNotNull()
    // A non-member (needs at least two 'a's) is still rejected.
    assertThat(test.findATNPathForLexeme("a", ambiguous)).isNull()
  }

  private fun reachesStopViaEpsilons(
    from: ATNState,
    stop: ATNState,
  ): Boolean {
    val visited = HashSet<ATNState>()
    val stack = ArrayDeque<ATNState>()
    stack.addLast(from)
    while (stack.isNotEmpty()) {
      val s = stack.removeLast()
      if (s === stop) return true
      if (!visited.add(s)) continue
      for (i in 0 until s.numberOfTransitions) {
        val tr = s.transition(i)
        if (tr.isEpsilon) stack.addLast(tr.target)
      }
    }
    return false
  }

  /** The label of each atom (character-consuming) transition along the path, in order. */
  private fun atomLabels(path: LexerAtnWrapper.ATNPath): List<String> {
    val states = path.stateSequence
    val result = ArrayList<String>()
    for (i in 0 until states.size - 1) {
      val s = states[i]
      val t = states[i + 1]
      val atom =
        (0 until s.numberOfTransitions)
          .map { s.transition(it) }
          .firstOrNull { it.target === t && !it.isEpsilon }
      if (atom != null) {
        result.add(atom.label().toString())
      }
    }
    return result
  }

  private fun lexesAsSingleToken(
    lexeme: String,
    expectedAntlrTokenType: Int,
  ): Boolean {
    val lexer = TestLexer(CharStreams.fromString(lexeme))
    var hasError = false
    lexer.removeErrorListeners()
    lexer.addErrorListener(
      object : BaseErrorListener() {
        override fun syntaxError(
          recognizer: org.antlr.v4.runtime.Recognizer<*, *>?,
          offendingSymbol: Any?,
          line: Int,
          charPositionInLine: Int,
          msg: String?,
          e: org.antlr.v4.runtime.RecognitionException?,
        ) {
          hasError = true
        }
      },
    )
    val tokens = lexer.allTokens
    return !hasError && tokens.size == 1 && tokens.single().type == expectedAntlrTokenType
  }

  private fun LexerAtnWrapper.isIdentifier(tokenName: String): Boolean =
    isIdentifierTokenType(metaTokenInfoDB.getTokenInfoWithName(tokenName)!!.tokenType)

  private fun LexerAtnWrapper.detectedIdentifierNames(): List<String> =
    identifierTokens.map { it.symbolicName }

  /**
   * The default identifier-token detector ([LexerAtnWrapper.isIdentifierTokenType])
   * recovers the primary identifier token of C and Python -- matching what those
   * facades list explicitly -- and rejects their string, number and keyword
   * tokens. The detector is a deliberate under-approximation (the facade
   * aggregation can only add to it, never subtract), so it also rejects tokens
   * whose alphabet strays outside the identifier allowlist even when they are
   * morally identifiers: JavaScript `Identifier` (admits `\u{...}` escapes, whose
   * `{`/`}` are not identifier characters) and Rust `Ident` (encodes astral
   * characters with UTF-16 surrogate pairs) are both casualties. All four
   * languages list their identifier token explicitly, so the aggregate is
   * unaffected.
   */
  @Test
  fun testIsIdentifierTokenTypeDetection() {
    assertThat(c.detectedIdentifierNames()).containsExactly("Identifier")
    assertThat(c.isIdentifier("Identifier")).isTrue()
    assertThat(c.isIdentifier("Constant")).isFalse()
    assertThat(c.isIdentifier("StringLiteral")).isFalse()

    assertThat(python.detectedIdentifierNames()).containsExactly("NAME")
    assertThat(python.isIdentifier("STRING_LITERAL")).isFalse()
    assertThat(python.isIdentifier("NUMBER")).isFalse()

    // Documented limitation: JavaScript's `\u{...}` escape puts `{`/`}` in the
    // identifier alphabet, which the allowlist forbids.
    assertThat(javascript.detectedIdentifierNames()).isEmpty()
    assertThat(javascript.isIdentifier("StringLiteral")).isFalse()
    assertThat(javascript.isIdentifier("DecimalLiteral")).isFalse()

    // Documented limitation: Rust's surrogate-pair identifier encoding is missed.
    assertThat(rust.isIdentifier("Ident")).isFalse()
    assertThat(rust.isIdentifier("ByteStringLit")).isFalse()
    assertThat(rust.isIdentifier("BareIntLit")).isFalse()

    assertThat(test.detectedIdentifierNames())
      .containsExactly("AmbiguousSplit", "KleenePlusOnSingleChar", "KleeneStar", "OverlappingId")
    assertThat(test.isIdentifier("NaturalNumber")).isFalse() // digit-leading
    assertThat(test.isIdentifier("DoubleFragRef")).isFalse() // finite (no cycle)
    assertThat(test.isIdentifier("SingleChar")).isFalse() // finite
    assertThat(test.isIdentifier("NegationAndPlus")).isFalse() // ~[\n] admits quote/space
  }

  @Test
  fun testIdWithId() {
    val tokenType = OrigCLexer.Identifier.toTokenType()
    assertThat(c.canBeConcatWithoutSpace(tokenType, tokenType)).isFalse()
  }

  @Test
  fun testGenerateCandidateCanonicalTokenTextsGivenTokenType() {
    var tokenType = c.metaTokenInfoDB.getTokenInfoWithName("Constant")!!.tokenType
    var lexemes = c.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("0", "1")
    lexemes = c.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 5)
    assertThat(lexemes).containsExactly("0", "1", "2", "3", "4")
    tokenType = rust.metaTokenInfoDB.getTokenInfoWithName("FullIntLit")!!.tokenType
    lexemes = rust.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("0", "1")
    tokenType = rust.metaTokenInfoDB.getTokenInfoWithName("FloatLit")!!.tokenType
    lexemes = rust.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("0.", "1.")
    tokenType = rust.metaTokenInfoDB.getTokenInfoWithName("StringLit")!!.tokenType
    lexemes = rust.generateCandidateCanonicalTokenTextsGivenTokenType(tokenType, countLimit = 2)
    assertThat(lexemes).containsExactly("\"\"")
  }
}

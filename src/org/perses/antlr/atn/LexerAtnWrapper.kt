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
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.atn.ATN
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.AtomTransition
import org.antlr.v4.runtime.atn.NotSetTransition
import org.antlr.v4.runtime.atn.RangeTransition
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.SetTransition
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.atn.WildcardTransition
import org.antlr.v4.runtime.misc.IntervalSet
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.TokenType
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.atn.nfa.ATNConstructorFromRegex
import org.perses.antlr.atn.nfa.AbstractNfa
import org.perses.antlr.atn.nfa.AbstractNfa.NfaEdge
import org.perses.antlr.atn.nfa.AbstractNfa.NfaState
import org.perses.antlr.atn.nfa.ConcatenatedNfaView
import org.perses.antlr.atn.nfa.MutableNfa
import org.perses.antlr.atn.nfa.NonRegexException
import org.perses.antlr.atn.nfa.PersesATNState
import org.perses.antlr.atn.nfa.PersesTransitionAst
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.util.SimpleStack
import org.perses.util.Util.lazyAssert
import org.perses.util.ktWarning
import org.perses.util.toImmutableList
import java.util.concurrent.ConcurrentHashMap
import kotlin.math.min

class LexerAtnWrapper(
  val atn: ATN,
  val metaTokenInfoDB: MetaTokenInfoDB,
) {
  private val simulatorMap = ConcurrentHashMap<TokenType, ATNSimulator>()

  private val normalizedATNs =
    ConcurrentHashMap<TokenType, Pair<RuleStartState, AbstractPersesRuleElement>>()

  internal val tokenTypePairToNecessityOfWhiteSpaceForConcat =
    ConcurrentHashMap<TokenTypePair, Boolean>()

  fun isATNEmpty(): Boolean =
    atn.ruleToStopState.let {
      it == null || it.isEmpty()
    }

  private fun normalizeAtn(tokenType: TokenType): Pair<RuleStartState, AbstractPersesRuleElement> {
    var originalStartState: RuleStartState? = null
    var regex: AbstractPersesRuleElement? = null
    return try {
      originalStartState = getOriginalStartState(tokenType)
      regex = MutableNfa.copyAndInlineOf(originalStartState).simplifyToRegex()
      Pair(ATNConstructorFromRegex().construct(regex), regex)
    } catch (e: NonRegexException) {
      val ruleInfo = metaTokenInfoDB.getTokenInfoWithRuleIndex(e.ruleIndex)
      logger.ktWarning {
        "Lexer rule $ruleInfo is not a regex, " +
          "an approximate NFA will be constructed for it"
      }
      regex = MutableNfa.approximateOf(originalStartState!!).simplifyToRegex()
      return Pair(ATNConstructorFromRegex().construct(regex), regex)
    } catch (e: Throwable) {
      throw RuntimeException(
        """"Exception occurred when processing tokenType=[$tokenType]
          |----tokenName=${metaTokenInfoDB.getTokenInfoWithType(tokenType)?.symbolicName}
          |----originalStartState=$originalStartState
          |----regex=${regex?.sourceCode}
        """.trimMargin(),
        e,
      )
    }
  }

  private fun getNormalizedStartState(ruleType: TokenType): RuleStartState =
    getNormalizedAtn(ruleType).first

  fun hasInformationForToken(tokenType: TokenType): Boolean {
    val ruleToStartState = atn.ruleToStartState ?: return false
    val tokenInfo =
      metaTokenInfoDB.getTokenInfoWithType(tokenType)
        ?: return false
    val ruleIndex = tokenInfo.ruleIndex.antlrRuleIndex
    return ruleIndex >= 0 &&
      ruleIndex < ruleToStartState.size &&
      ruleToStartState[ruleIndex] != null
  }

  fun getNormalizedAtn(tokenType: TokenType): Pair<RuleStartState, AbstractPersesRuleElement> =
    normalizedATNs.computeIfAbsent(tokenType) {
      normalizeAtn(it)
    }

  fun getOriginalStartState(ruleType: TokenType): RuleStartState {
    val tokenInfo =
      metaTokenInfoDB.getTokenInfoWithType(ruleType)
        ?: error("No information for the token type $ruleType")
    return atn.ruleToStartState[tokenInfo.ruleIndex.antlrRuleIndex]
  }

  private fun getOriginalEndState(ruleType: TokenType): RuleStopState {
    val tokenInfo = metaTokenInfoDB.getTokenInfoWithType(ruleType)!!
    return atn.ruleToStopState[tokenInfo.ruleIndex.antlrRuleIndex]
  }

  /**
   * Traverses the *normalized* ATN (see [getNormalizedAtn]) rather than the
   * original one. The original ATN is a network of per-rule NFAs joined by
   * ANTLR's call edges (RuleTransition) and per-call-site return edges
   * synthesized out of each RuleStopState; treating those as ordinary epsilon
   * edges lets a traversal "return" to the wrong call site. The normalized ATN
   * is reconstructed from a regex and contains no rule transitions, so plain
   * epsilon traversal is sound.
   */
  fun getAcyclicPathsToGenerateGivenTokenType(ruleType: TokenType): List<ATNPath> {
    if (metaTokenInfoDB.getTokenInfoWithType(ruleType) == null) {
      // For example, INDENT and DEDENT are not defined in the lexer.
      return emptyList()
    }
    val startState = getNormalizedStartState(ruleType)
    val stopState = startState.stopState
    // BFS by number of consumed characters: expand a whole layer, then return as
    // soon as some path can reach the stop state through epsilons, i.e. the
    // shortest token texts.
    var frontier = listOf(ATNPath.create(startState))
    while (true) {
      val completePaths = frontier.filter { isReachableViaEpsilons(it.lastState, stopState) }
      if (completePaths.isNotEmpty()) {
        return completePaths
      }
      val nextFrontier = ArrayList<ATNPath>()
      frontier.forEach { path ->
        getAllReachablePaths(startState = path.lastState).forEach {
          nextFrontier.add(path.append(it))
        }
      }
      if (nextFrontier.isEmpty()) {
        // No path can consume another character and none reached the stop state.
        return emptyList()
      }
      frontier = nextFrontier
    }
  }

  fun generateCandidateCanonicalTokenTextsGivenTokenType(
    ruleType: TokenType,
    countLimit: Int,
  ): ImmutableList<String> {
    val completePaths = getAcyclicPathsToGenerateGivenTokenType(ruleType)
    val candidates =
      completePaths
        .flatMap { path ->
          getCandidateCanonicalTokenTextsFromPath(path, countLimit)
        }.distinct()
        .sorted()
    return candidates.subList(0, min(countLimit, candidates.size)).toImmutableList()
  }

  fun findATNPathForLexeme(
    lexeme: String,
    ruleType: TokenType,
  ): ATNPath? {
    var paths = ArrayList<ATNPath>()
    val startState = getNormalizedStartState(ruleType)
    paths.add(ATNPath.create(startState))
    try {
      lexeme.forEach { char ->
        val newPaths = ArrayList<ATNPath>()
        paths.forEach { path ->
          val result = getAllReachablePaths(path.lastState, char)
          result.forEach {
            newPaths.add(path.append(it))
          }
        }
        // Keep one representative path per reached state. Two paths that arrive
        // at the same state have identical futures, so for finding *a* path to
        // the end one of them suffices. Without this collapse, a rule with
        // epsilon "diamonds" or overlapping char classes (e.g. an alternation
        // inside a star, or simplifyToRegex's `(A|B)+` -> `A* (B A*)+` rewrite)
        // would fan out to 2^n paths for an n-char lexeme. This is the standard
        // NFA simulation: the working set is bounded by the number of states.
        paths = dedupePathsByLastState(newPaths)
      }
    } catch (e: Throwable) {
      val message = "Failed to find an ATN path for lexeme $lexeme, ruleType=$ruleType"
      throw RuntimeException(message, e)
    }
    val endState = startState.stopState
    paths.removeAll {
      !isReachableViaEpsilons(it.lastState, endState)
    }
    if (paths.isEmpty()) {
      return null
    }
    // A lexeme can have several accepting derivations: distinct epsilon routings,
    // overlapping char classes that match the same character, or -- rarely for a
    // lexer rule -- genuine structural ambiguity. They all yield the same token
    // text, and any one is a valid decomposition for TD-tree construction, so we
    // return a single deterministic (lowest-[canonicalStateKey]) representative
    // rather than rejecting the lexeme.
    val partialResult = paths.minByOrNull { it.canonicalStateKey() }!!
    val lastStateInPath = partialResult.stateSequence.last()
    if (lastStateInPath is RuleStopState) {
      return partialResult
    }
    val pathToEnd = getPathToEndState(lastStateInPath, ArrayList(), HashSet())!!
    return partialResult.append(pathToEnd)
  }

  /**
   * Keeps one representative path per reached state, so the working set stays
   * bounded by the state count instead of growing with the number of distinct
   * epsilon routings. The deterministic (lowest-[canonicalStateKey])
   * representative is kept so the chosen path does not depend on the unordered
   * traversal in [getAllReachablePaths].
   */
  private fun dedupePathsByLastState(paths: List<ATNPath>): ArrayList<ATNPath> {
    val best = LinkedHashMap<ATNState, ATNPath>()
    paths.forEach { path ->
      val existing = best[path.lastState]
      if (existing == null || path.canonicalStateKey() < existing.canonicalStateKey()) {
        best[path.lastState] = path
      }
    }
    return ArrayList(best.values)
  }

  /**
   * A stable, lexicographically-comparable key over the path's state numbers.
   * State numbers are zero-padded so string ordering matches numeric ordering.
   */
  private fun ATNPath.canonicalStateKey(): String =
    stateSequence.joinToString(",") { "%010d".format(it.stateNumber) }

  internal fun getAllReachablePaths(
    startState: ATNState,
    char: Char? = null,
  ): Set<ATNPath> {
    val result = mutableSetOf<ATNPath>()
    getAllReachablePathsRecursive(
      currentState = startState,
      currentPath = mutableListOf(),
      result = result,
      visitedStates = hashSetOf(startState),
      char = char,
    )
    return result
  }

  private fun getAllReachablePathsRecursive(
    currentState: ATNState,
    currentPath: MutableList<ATNState>,
    result: MutableSet<ATNPath>,
    visitedStates: MutableSet<ATNState>,
    char: Char? = null,
  ) {
    currentState.transitionSequence().forEach { transition ->
      val targetState = transition.target
      if (transition.isEpsilon) {
        // Guard cycles per traversal path, not globally: a state already on the
        // current path would loop forever (star/plus create epsilon cycles), but
        // a state reachable via a different epsilon route must still be explored,
        // otherwise convergent ("diamond") paths to a shared non-epsilon
        // transition are silently dropped.
        if (!visitedStates.add(targetState)) {
          return@forEach
        }
        currentPath.add(targetState)
        getAllReachablePathsRecursive(targetState, currentPath, result, visitedStates, char)
        check(targetState === currentPath.removeLast())
        check(visitedStates.remove(targetState))
      } else if (char == null ||
        transition.matches(char.code, Char.MIN_VALUE.code, Char.MAX_VALUE.code)
      ) {
        currentPath.add(targetState)
        result.add(ATNPath.create(currentPath))
        check(targetState === currentPath.removeLast())
      }
    }
  }

  private fun isReachableViaEpsilons(
    source: ATNState,
    target: ATNState,
    visited: HashSet<ATNState> = HashSet(),
  ): Boolean {
    if (source === target) {
      return true
    }
    if (!visited.add(source)) {
      return false
    }
    source.transitionSequence().forEach {
      if (it.isEpsilon) {
        if (isReachableViaEpsilons(it.target, target, visited)) {
          return true
        }
      }
    }
    return false
  }

  private fun getPathToEndState(
    state: ATNState,
    currentPath: ArrayList<ATNState>,
    visited: HashSet<Transition>,
  ): ATNPath? {
    assert(state !is RuleStopState)
    state.transitionSequence().forEach { transition ->
      if (!visited.add(transition)) {
        return@forEach
      }
      if (!transition.isEpsilon) {
        return@forEach
      }
      val target = transition.target
      currentPath.add(target)
      if (target is RuleStopState) {
        return ATNPath.create(currentPath)
      } else {
        val result = getPathToEndState(target, currentPath, visited)
        if (result != null) {
          return result
        }
      }
      currentPath.removeLast()
    }
    return null
  }

  fun createTDTree(
    lexeme: String,
    ruleType: TokenType,
  ): TDTree? {
    val path = findATNPathForLexeme(lexeme, ruleType) ?: return null
    // simulateRule already prunes empty structural nodes via
    // removeNodesWithNoCharLeaves(); no need to repeat it here.
    return simulateRule(ruleType, ReplayDecisionMaker(path, lexeme))
  }

  fun simulateRule(
    ruleType: TokenType,
    decisionMaker: AbstractDecisionMaker,
  ): TDTree {
    val startState = getNormalizedStartState(ruleType)
    val simulator =
      simulatorMap.computeIfAbsent(ruleType) {
        ATNSimulator(startState)
      }
    return simulator.simulate(decisionMaker).removeNodesWithNoCharLeaves()
  }

  fun canBeConcatWithoutSpace(
    tokenNameFormer: String,
    tokenNameLatter: String,
  ) = canBeConcatWithoutSpace(
    metaTokenInfoDB.getTokenInfoWithName(tokenNameFormer)!!.tokenType,
    metaTokenInfoDB.getTokenInfoWithName(tokenNameLatter)!!.tokenType,
  )

  fun canBeConcatWithoutSpace(
    tokenTypeFormer: TokenType,
    tokenTypeLatter: TokenType,
  ): Boolean {
    val key = TokenTypePair(tokenTypeFormer, tokenTypeLatter)
    return tokenTypePairToNecessityOfWhiteSpaceForConcat.computeIfAbsent(key) {
      calculateNecessityOfSpaceBetweenTwoToken(
        it.formerTokenType,
        it.latterTokenType,
      )
    }
  }

  private fun calculateNecessityOfSpaceBetweenTwoToken(
    tokenTypeFormer: TokenType,
    tokenTypeLatter: TokenType,
  ): Boolean {
    metaTokenInfoDB.asSequence().forEach { token ->
      if (canBeSubsumed(token.tokenType, tokenTypeFormer, tokenTypeLatter)) {
        return false
      }
    }
    return true
  }

  // TODO: this should be named to 'intersect' or something similar.
  fun canBeSubsumed(
    subsumer: TokenType,
    subsumeeFormer: TokenType,
    subsumeeLatter: TokenType,
  ): Boolean {
    // Does some string of L(subsumer) split into an L(former) prefix and an
    // L(latter) suffix? That is exactly the emptiness of the intersection of
    // L(subsumer) with L(former).L(latter), which we decide by searching the
    // product of the subsumer NFA with the concatenation NFA `former . latter`.
    val nfa = copyTokenNfa(subsumer)
    val subsumee = concatenatedTokenNfa(subsumeeFormer, subsumeeLatter)

    // The non-epsilon-boundary states reachable from a state depend only on that
    // state, but the product search revisits the same source state once per state
    // it is paired with. Memoize so each closure is computed at most once.
    val closureCache = HashMap<NfaState, ImmutableList<NfaState>>()

    fun closureOf(state: NfaState): ImmutableList<NfaState> =
      closureCache.getOrPut(state) {
        getReachableStatesWithNonEpsilonOutgoingTransition(state)
      }

    val stack = SimpleStack<Pair<NfaState, NfaState>>()
    val visited = HashSet<Pair<NfaState, NfaState>>()
    Pair(nfa.createNfaState { it.startState }, subsumee.createNfaState { it.startState }).let {
      stack.add(it)
      visited.add(it)
    }

    while (stack.isNotEmpty()) {
      val (subsumerSource, subsumeeSource) = stack.remove()
      val states1 = closureOf(subsumerSource)
      val states2 = closureOf(subsumeeSource)
      states1.forEach { nfaState1 ->
        states2.forEach { nfaState2 ->
          if (nfaState1.state === nfa.acceptingState &&
            nfaState2.state === subsumee.acceptingState
          ) {
            return true
          }
          nfaState1.outgoingEdges().forEach { t1 ->
            nfaState2.outgoingEdges().forEach { t2 ->
              Pair(t1.target, t2.target).let {
                if (!visited.contains(it) && doEdgesIntersect(t1, t2)) {
                  visited.add(it)
                  stack.add(it)
                }
              }
            }
          }
        }
      }
    }
    return false
  }

  private fun concatenatedTokenNfa(
    former: TokenType,
    latter: TokenType,
  ): AbstractNfa = ConcatenatedNfaView(copyTokenNfa(former), copyTokenNfa(latter))

  private fun doEdgesIntersect(
    t1: NfaEdge,
    t2: NfaEdge,
  ): Boolean {
    val atnTransition1 = (t1.edge.label as PersesTransitionAst).atnTransition
    if (atnTransition1 is WildcardTransition) {
      return true
    }
    val label1 =
      checkNotNull(atnTransition1.label()) {
        "The label for the edge is null: ${t1.edge}"
      }
    val atnTransition2 = (t2.edge.label as PersesTransitionAst).atnTransition
    if (atnTransition2 is WildcardTransition) {
      return true
    }
    val label2 =
      checkNotNull(atnTransition2.label()) {
        "The label for the edge is null: ${t2.edge}"
      }
    return label1.and(label2).size() > 0
  }

  fun copyTokenNfa(tokenType: TokenType): AbstractNfa {
    val startState = getNormalizedAtn(tokenType).first
    return MutableNfa.copyOf(startState)
  }

  /**
   * The token types that the default heuristic classifies as identifiers. See
   * [isIdentifierTokenType] for the definition. This is the "default" detection;
   * callers may still supply their own identifier token types explicitly.
   */
  val identifierTokens: ImmutableList<MetaTokenInfoDB.TokenInfoEntry> by lazy {
    metaTokenInfoDB
      .asSequence()
      .filter { isIdentifierTokenType(it.tokenType) }
      .toImmutableList()
  }

  /**
   * Conservative, language-agnostic heuristic for "is this token an identifier".
   * A token qualifies iff its language is:
   *  1. unbounded in length (the lexeme can be arbitrarily long), AND
   *  2. every accepted lexeme starts with an identifier-start character, AND
   *  3. every accepted lexeme consists only of identifier characters (an
   *     allowlist: ASCII letters/digits, the connector/sigil/escape characters
   *     in [IDENTIFIER_PUNCTUATION], and non-ASCII non-whitespace).
   *
   * (1) excludes keywords, operators and punctuation (all finite). (2) excludes
   * numbers (digit-leading), string/char literals (quote-leading) and
   * comments/regex (which start with `/`, `#`, ...); it constrains only ASCII —
   * any non-ASCII first character is accepted, so the test does not depend on
   * the JVM's Unicode version matching the grammar's identifier ranges. (3) is
   * an allowlist, not a blocklist: it rejects any token whose body can contain
   * an operator or separator character, so letter-prefixed string literals
   * (`r"..."`/`b"..."`), here-documents, quoted/multi-word identifiers, and
   * keyword=value tokens such as WAT `offset=0` are all excluded.
   *
   * This deliberately under-approximates, by design: the aggregation in
   * [org.perses.grammar.AbstractParserFacade.aggregatedIdentifierTokenTypes] is a
   * union of this result with the caller's explicit list, so a caller can only
   * *add* identifier tokens, never remove a false positive. The detector must
   * therefore err toward precision and let callers supply the recall. Tokens it
   * misses by design include operator identifiers (Scala `<=`), quoted
   * identifiers (Scala `` `a b` ``, SMT-LIB `|a b|`), permissively symbolic
   * identifiers (WAT `$a=b`), and tokens whose grammar models astral characters
   * with UTF-16 surrogate-pair sequences (e.g. Rust `Ident`). Missing a token is
   * safe (callers list it explicitly); misclassifying a literal is not.
   */
  fun isIdentifierTokenType(tokenType: TokenType): Boolean {
    if (!hasInformationForToken(tokenType)) {
      return false
    }
    val nfa =
      try {
        MutableNfa.copyAndInlineOf(getOriginalStartState(tokenType))
      } catch (e: NonRegexException) {
        // A recursive (context-free) lexer rule cannot be a regular identifier.
        return false
      }
    nfa.removeStatesUnreachableFromAcceptingState()

    if (!nfa.hasInputConsumingCycle()) {
      return false
    }
    val firstCharSet = IntervalSet()
    for (state in nfa.epsilonClosureOf(nfa.startState)) {
      for (edge in nfa.getOutgoingEdgesOf(state)) {
        if (edge.isEpsilon) {
          continue
        }
        val chars = boundedCharSetOrNull(edge) ?: return false
        firstCharSet.addAll(chars)
      }
    }
    if (firstCharSet.isNil || !firstCharSet.and(forbiddenStartChars).isNil) {
      return false
    }
    val allCharSet = IntervalSet()
    for (edge in nfa.edgeSequence()) {
      if (edge.isEpsilon) {
        continue
      }
      val chars = boundedCharSetOrNull(edge) ?: return false
      allCharSet.addAll(chars)
    }
    return allCharSet.and(forbiddenAnywhereChars).isNil
  }

  /**
   * The exact set of characters a non-epsilon edge matches, when that set is
   * explicitly bounded (an atom, set, or range). Returns null when the edge
   * matches an unbounded / complement set -- a wildcard `.` or a negated set
   * `~[...]` -- whose members cannot be enumerated and always include forbidden
   * characters, so such an edge can never belong to an identifier.
   */
  private fun boundedCharSetOrNull(edge: AbstractNfa.Edge): IntervalSet? =
    when (val transition = (edge.label as PersesTransitionAst).atnTransition) {
      is WildcardTransition -> null
      is NotSetTransition -> null
      is AtomTransition -> IntervalSet.of(transition.label)
      is SetTransition -> transition.label()
      is RangeTransition -> transition.label()
      else -> null
    }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    private const val MAX_ASCII = 0x7F

    private val IDENTIFIER_PUNCTUATION =
      setOf('_'.code, '$'.code, '@'.code, '\\'.code)

    /**
     * ASCII characters that may not begin an identifier. Only ASCII is
     * constrained, so that grammars whose identifier ranges follow a newer
     * Unicode version than the JVM are not rejected: a non-ASCII first character
     * is always accepted. Allowed ASCII starts are letters and the connector /
     * sigil / escape characters in [IDENTIFIER_PUNCTUATION] (`@` for Ruby
     * `@x` and PHP `$x`, `\` for C/JavaScript `\uXXXX` escapes); everything else
     * in ASCII -- digits, quotes, whitespace, operators, comment/regex starters
     * -- is forbidden.
     */
    private val forbiddenStartChars: IntervalSet by lazy {
      buildCodePointSet { cp ->
        cp <= MAX_ASCII &&
          !(Character.isLetter(cp) || cp in IDENTIFIER_PUNCTUATION)
      }
    }

    /**
     * Characters that may not appear anywhere in an identifier. This is an
     * allowlist complement: an identifier body may contain only ASCII letters,
     * ASCII digits, the connector / sigil / escape characters in
     * [IDENTIFIER_PUNCTUATION], and non-ASCII non-whitespace characters; every
     * other code point is forbidden. Constraining the body to an allowlist
     * (rather than only banning whitespace and quotes) is what keeps the
     * heuristic an under-approximation: operator-bearing tokens such as WAT
     * `offset=0` or Scala `<=` are rejected because `=`/`<` are not identifier
     * characters, instead of slipping through as false positives. Non-ASCII is
     * left unconstrained (apart from whitespace) so that grammars tracking a
     * newer Unicode version than the JVM are not rejected.
     */
    private val forbiddenAnywhereChars: IntervalSet by lazy {
      buildCodePointSet { cp ->
        Character.isWhitespace(cp) ||
          Character.isSpaceChar(cp) ||
          (cp <= MAX_ASCII && !(Character.isLetterOrDigit(cp) || cp in IDENTIFIER_PUNCTUATION))
      }
    }

    private inline fun buildCodePointSet(predicate: (Int) -> Boolean): IntervalSet {
      val set = IntervalSet()
      var codePoint = 0
      while (codePoint <= Character.MAX_CODE_POINT) {
        if (predicate(codePoint)) {
          val rangeStart = codePoint
          while (codePoint <= Character.MAX_CODE_POINT && predicate(codePoint)) {
            ++codePoint
          }
          set.add(rangeStart, codePoint - 1)
        } else {
          ++codePoint
        }
      }
      return set
    }

    fun createLexerWrapperFromLexerClass(lexerClass: Class<out Lexer>): LexerAtnWrapper {
      val pair = MetaTokenInfoDB.createForLexerClass(lexerClass)
      return LexerAtnWrapper(
        atn = pair.second,
        metaTokenInfoDB = pair.first,
      )
    }

    fun getReachableStatesWithNonEpsilonOutgoingTransition(
      nfaState: NfaState,
    ): ImmutableList<NfaState> {
      val nfa = nfaState.nfa
      val start = nfaState.state
      val seen = HashSet<PersesATNState>()
      val stack = SimpleStack<PersesATNState>()
      val result = ImmutableList.Builder<NfaState>()
      seen.add(start)
      stack.add(start)
      while (stack.isNotEmpty()) {
        val state = stack.remove()
        var hasNonEpsilonOutgoingTransition = false
        nfa.getOutgoingEdgesOf(state).forEach { t ->
          if (t.isEpsilon) {
            val target = nfa.getTargetState(t)
            if (seen.add(target)) {
              stack.add(target)
            }
          } else {
            hasNonEpsilonOutgoingTransition = true
          }
        }
        // include states with no transition
        if (hasNonEpsilonOutgoingTransition || nfa.outDegreeOf(state) == 0) {
          result.add(nfa.createNfaState { state })
        }
      }
      return result.build().also { list ->
        lazyAssert { HashSet(list).size == list.size }
      }
    }

    private fun getCandidateCanonicalTokenTextsFromPath(
      path: ATNPath,
      countLimit: Int,
    ): ImmutableList<String> {
      val builder = ImmutableList.builder<Transition>()
      path.stateSequence.zipWithNext().forEach { pair ->
        val currState = pair.first
        val nextState = pair.second
        val transition = currState.transitionSequence().single { it.target === nextState }
        if (transition.isEpsilon) {
          return@forEach
        }
        builder.add(transition)
      }
      val transitions = builder.build()
      val results = ImmutableList.builder<String>()
      outerLoop@for (index in 0 until countLimit) {
        val stringBuilder = StringBuilder()
        var currIndex = index
        for (t in transitions.reverse()) {
          val charset = t.getAllowedAsciiChars()
          if (charset.isEmpty()) {
            break@outerLoop
          }
          check(charset.isNotEmpty()) {
            "The charset is empty on the transition $t"
          }
          val i = currIndex % charset.size
          currIndex /= charset.size
          stringBuilder.append(charset[i])
        }
        if (currIndex > 0) {
          break
        }
        results.add(stringBuilder.reverse().toString())
      }
      return results.build()
    }
  }

  data class ATNPath(
    val stateSequence: ImmutableList<ATNState>,
  ) {
    val lastState: ATNState
      get() = stateSequence.last()

    fun append(other: ATNPath): ATNPath =
      ATNPath(
        ImmutableList
          .builderWithExpectedSize<ATNState>(stateSequence.size + other.stateSequence.size)
          .addAll(stateSequence)
          .addAll(other.stateSequence)
          .build(),
      )

    operator fun get(index: Int): ATNState = stateSequence[index]

    companion object {
      fun create(singleState: ATNState) = ATNPath(ImmutableList.of(singleState))

      fun create(path: Iterable<ATNState>) = ATNPath(ImmutableList.copyOf(path))
    }
  }

  class ReplayDecisionMaker(
    private val atnStatePath: ATNPath,
    private val lexeme: String,
  ) : AbstractDecisionMaker() {
    override fun nextBoolean(): Boolean {
      TODO("Not yet implemented")
    }

    override fun nextInt(bound: Int): Int {
      TODO("Not yet implemented")
    }

    private var currentCharIndex = 0

    override fun sampleChar(list: List<Char>): Char {
      val currentChar = lexeme[currentCharIndex]
      ++currentCharIndex
      lazyAssert { currentChar in list }
      return currentChar
    }

    override fun sampleChar(char: Char): Char {
      val currentChar = lexeme[currentCharIndex]
      ++currentCharIndex
      lazyAssert { char == currentChar }
      return currentChar
    }

    private var currentStateIndex = 0

    override fun sampleTransition(state: ATNState): Transition {
      lazyAssert({ state == atnStatePath[currentStateIndex] }) {
        "$state, ${atnStatePath[currentStateIndex]}"
      }
      ++currentStateIndex
      val nextState = atnStatePath[currentStateIndex]
      return state.transitionSequence().single { it.target === nextState }
    }
  }

  data class TokenTypePair(
    val formerTokenType: TokenType,
    val latterTokenType: TokenType,
  ) {
    companion object {
      fun Pair<TokenType, TokenType>.toTokenTypePair() =
        TokenTypePair(
          formerTokenType = first,
          latterTokenType = second,
        )
    }
  }
}

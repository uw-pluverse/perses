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

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.Transition
import org.antlr.v4.runtime.atn.WildcardTransition
import org.perses.antlr.AntlrGrammarUtil
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.TokenType
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.atn.nfa.ATNConstructorFromRegex
import org.perses.antlr.atn.nfa.AbstractNFA
import org.perses.antlr.atn.nfa.AbstractNFA.NFAEdge
import org.perses.antlr.atn.nfa.AbstractNFA.NFAState
import org.perses.antlr.atn.nfa.MutableNFA
import org.perses.antlr.atn.nfa.NonRegexException
import org.perses.antlr.atn.nfa.PersesATNState
import org.perses.antlr.atn.nfa.PersesTransitionAst
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.util.SimpleStack
import org.perses.util.Util.lazyAssert
import org.perses.util.ktWarning
import org.perses.util.toImmutableList
import java.util.concurrent.ConcurrentHashMap

class LexerAtnWrapper<T : Lexer>(lexerClass: Class<T>) {

  val atn = AntlrGrammarUtil.getAtnFromLexer(lexerClass)

  val metaTokenInfoDB = MetaTokenInfoDB.createFor(lexerClass)

  private val simulatorMap = ConcurrentHashMap<TokenType, ATNSimulator>()

  private val normalizedATNs =
    ConcurrentHashMap<TokenType, Pair<RuleStartState, AbstractPersesRuleElement>>()

  internal val tokenTypePairToNecessityOfWhiteSpaceForConcat =
    ConcurrentHashMap<TokenTypePair, Boolean>()

  private fun normalizeAtn(
    tokenType: TokenType,
  ): Pair<RuleStartState, AbstractPersesRuleElement> {
    var originalStartState: RuleStartState? = null
    var regex: AbstractPersesRuleElement? = null
    return try {
      originalStartState = getOriginalStartState(tokenType)
      regex = MutableNFA.copyAndInlineOf(originalStartState).simplifyToRegex()
      Pair(ATNConstructorFromRegex().construct(regex), regex)
    } catch (e: NonRegexException) {
      val ruleInfo = metaTokenInfoDB.getTokenInfoWithRuleIndex(e.ruleIndex)
      logger.ktWarning {
        "Lexer rule $ruleInfo is not a regex, " +
          "an approximate NFA will be constructed for it"
      }
      regex = MutableNFA.approximateOf(originalStartState!!).simplifyToRegex()
      return Pair(ATNConstructorFromRegex().construct(regex), regex)
    } catch (e: Throwable) {
      throw RuntimeException(
        """"Exception occurred when processing $
        | originalStartState=$originalStartState
        | regex=${regex?.sourceCode}
        """.trimMargin(),
        e,
      )
    }
  }

  private fun getNormalizedStartState(ruleType: TokenType): RuleStartState {
    return getNormalizedAtn(ruleType).first
  }

  fun getNormalizedAtn(tokenType: TokenType): Pair<RuleStartState, AbstractPersesRuleElement> {
    return normalizedATNs.computeIfAbsent(tokenType) {
      normalizeAtn(it)
    }
  }

  fun getOriginalStartState(ruleType: TokenType): RuleStartState {
    val tokenInfo = metaTokenInfoDB.getTokenInfoWithType(ruleType)!!
    return atn.ruleToStartState[tokenInfo.ruleIndex.antlrRuleIndex]
  }

  private fun getOriginalEndState(ruleType: TokenType): RuleStopState {
    val tokenInfo = metaTokenInfoDB.getTokenInfoWithType(ruleType)!!
    return atn.ruleToStopState[tokenInfo.ruleIndex.antlrRuleIndex]
  }

  fun findATNPathForLexeme(lexeme: String, ruleType: TokenType): ATNPath {
    var paths = ArrayList<ATNPath>()
    val startState = getNormalizedStartState(ruleType)
    paths.add(ATNPath.create(startState))
    lexeme.asSequence().forEach { char ->
      val newPaths = ArrayList<ATNPath>()
      paths.forEach { path ->
        val endingState = path.endingState
        val currentPath = ArrayList<ATNState>()
        val result = HashSet<ATNPath>()
        val visited = HashSet<Transition>()
        getAllReachablePaths(endingState, char, currentPath, result, visited)
        result.forEach {
          newPaths.add(path.append(it))
        }
      }
      paths = newPaths
    }
    val endState = startState.stopState
    paths.removeAll {
      !isReachableViaEpsilons(it.endingState, endState)
    }
    check(paths.size == 1) {
      "There should be exactly 1 path. #paths=${paths.size}, ruleType=$ruleType, lexeme=$lexeme"
    }
    val partialResult = paths.single()
    val lastStateInPath = partialResult.stateSequence.last()
    if (lastStateInPath is RuleStopState) {
      return partialResult
    }
    val pathToEnd = getPathToEndState(lastStateInPath, ArrayList(), HashSet())!!
    return partialResult.append(pathToEnd)
  }

  private fun getAllReachablePaths(
    state: ATNState,
    char: Char,
    currentPath: ArrayList<ATNState>,
    result: HashSet<ATNPath>,
    visited: HashSet<Transition>,
  ) {
    state.transitionSequence().forEach { transition ->
      if (!visited.add(transition)) {
        return@forEach
      }
      val targetState = transition.target
      currentPath.add(targetState)
      if (transition.isEpsilon) {
        getAllReachablePaths(targetState, char, currentPath, result, visited)
      } else {
        if (transition.matches(char.code, Char.MIN_VALUE.code, Char.MAX_VALUE.code)) {
          result.add(ATNPath.create(currentPath))
        } else {
          // Do nothing.
        }
      }
      check(targetState === currentPath.removeLast())
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

  fun createTDTree(lexeme: String, ruleType: TokenType): TDTree {
    val path = findATNPathForLexeme(lexeme, ruleType)
    return simulateRule(ruleType, ReplayDecisionMaker(path, lexeme)).apply {
      removeNodesWithNoCharLeaves()
    }
  }

  fun simulateRule(ruleType: TokenType, decisionMaker: AbstractDecisionMaker): TDTree {
    val startState = getNormalizedStartState(ruleType)
    val simulator = simulatorMap.computeIfAbsent(ruleType) {
      ATNSimulator(startState)
    }
    return simulator.simulate(decisionMaker).removeNodesWithNoCharLeaves()
  }

  fun canBeConcatWithoutSpace(tokenNameFormer: String, tokenNameLatter: String) =
    canBeConcatWithoutSpace(
      metaTokenInfoDB.getTokenInfoWithName(tokenNameFormer)!!.tokenType,
      metaTokenInfoDB.getTokenInfoWithName(tokenNameLatter)!!.tokenType,
    )

  fun canBeConcatWithoutSpace(tokenTypeFormer: TokenType, tokenTypeLatter: TokenType): Boolean {
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
    // check if nfa can be subsumed by nfaFormer + nfaLatter
    val nfa = copyTokenNfa(subsumer)
    val nfaFormer = copyTokenNfa(subsumeeFormer)
    val nfaLatter = copyTokenNfa(subsumeeLatter)

    val stackFormer = SimpleStack<Pair<NFAState, NFAState>>()
    val stackLatter = SimpleStack<Pair<NFAState, NFAState>>()
    val visitedFormer = HashSet<Pair<NFAState, NFAState>>()
    val visitedLatter = HashSet<Pair<NFAState, NFAState>>()
    Pair(nfa.createNFAState { it.startState }, nfaFormer.createNFAState { it.startState }).let {
      stackFormer.add(it)
      visitedFormer.add(it)
    }

    while (stackFormer.isNotEmpty() || stackLatter.isNotEmpty()) {
      var stack = stackFormer
      var visited = visitedFormer
      if (stackFormer.isEmpty()) {
        stack = stackLatter
        visited = visitedLatter
      }
      val (subsumerSource, subsumeeSource) = stack.remove()
      // find all the nodes with non-epsilon edges that can be reached by epsilon transition
      val states1 = getReachableStatesWithNonEpsilonOutgoingTransition(subsumerSource)
      val states2 = getReachableStatesWithNonEpsilonOutgoingTransition(subsumeeSource)
      states1.forEach { nfaState1 ->
        states2.forEach { nfaState2 ->
          val s1 = nfaState1.state
          val s2 = nfaState2.state
          if (s1 === nfa.acceptingState && s2 === nfaLatter.acceptingState) {
            return true
          }
          // connect nfaFormer and nfaLatter
          Pair(nfaState1, nfaLatter.createNFAState { it.startState }).let {
            if (s2 === nfaFormer.acceptingState &&
              !visited.contains(it)
            ) {
              visitedLatter.add(it)
              stackLatter.add(it)
            }
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

  private fun doEdgesIntersect(t1: NFAEdge, t2: NFAEdge): Boolean {
    val atnTransition1 = (t1.edge.label as PersesTransitionAst).atnTransition
    if (atnTransition1 is WildcardTransition) {
      return true
    }
    val label1 = checkNotNull(atnTransition1.label()) {
      "The label for the edge is null: ${t1.edge}"
    }
    val atnTransition2 = (t2.edge.label as PersesTransitionAst).atnTransition
    if (atnTransition2 is WildcardTransition) {
      return true
    }
    val label2 = checkNotNull(atnTransition2.label()) {
      "The label for the edge is null: ${t2.edge}"
    }
    return label1.and(label2).size() > 0
  }

  // WIP.
  fun canBeSubsumed(subsumer: AbstractNFA, toBeSubsumed: AbstractNFA): Boolean {
    val stack = SimpleStack<Pair<NFAState, Set<NFAState>>>()
    val visited = HashSet<Pair<NFAState, Set<NFAState>>>()
    Pair(
      subsumer.createNFAState {
        it.startState
      },
      setOf(toBeSubsumed.createNFAState { it.startState }),
    ).let {
      stack.add(it)
      visited.add(it)
    }
    while (stack.isNotEmpty()) {
      val (subsumerSource, toBeSubsumedSource) = stack.remove()
      val stateListSubsumer =
        getReachableStatesWithNonEpsilonOutgoingTransition(subsumerSource)
      val stateListToBeSubsumed = toBeSubsumedSource.flatMap {
        getReachableStatesWithNonEpsilonOutgoingTransition(it)
      }
      stateListSubsumer.zip(stateListToBeSubsumed).forEach { pair ->
        val (sSubsumer, sToBeSubsumed) = pair
        if (sSubsumer.state === subsumer.acceptingState &&
          sToBeSubsumed.state == toBeSubsumed.acceptingState
        ) {
          return@forEach
        }
      }
    }
    return true
  }

  fun copyTokenNfa(tokenType: TokenType): AbstractNFA {
    val startState = getNormalizedAtn(tokenType).first
    return MutableNFA.copyOf(startState)
  }

  val identifierTokens: ImmutableList<MetaTokenInfoDB.TokenInfoEntry> by lazy {
    val nfaForClassicalIdentifier = getNfaForClassicalIdentifier()
    metaTokenInfoDB
      .asSequence()
      .filter { token ->
        val nfa = copyTokenNfa(token.tokenType)
        canBeSubsumed(nfa, nfaForClassicalIdentifier)
      }.toImmutableList()
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    private val wrapperForIdentifierOnlyLexer = LexerAtnWrapper(IdentifierOnlyLexer::class.java)
    private fun getNfaForClassicalIdentifier() = wrapperForIdentifierOnlyLexer.copyTokenNfa(
      TokenType(IdentifierOnlyLexer.Identifier),
    )

    fun getReachableStatesWithNonEpsilonOutgoingTransition(
      nfaState: NFAState,
    ): ImmutableList<NFAState> {
      val nfa = nfaState.nfa
      val start = nfaState.state
      val seen = HashSet<PersesATNState>()
      val stack = SimpleStack<PersesATNState>()
      val result = ImmutableList.Builder<NFAState>()
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
          result.add(nfa.createNFAState { state })
        }
      }
      return result.build().also { list ->
        lazyAssert { HashSet(list).size == list.size }
      }
    }
  }

  data class ATNPath(val stateSequence: ImmutableList<ATNState>) {

    val endingState: ATNState
      get() = stateSequence.last()

    fun append(other: ATNPath): ATNPath {
      return ATNPath(
        ImmutableList
          .builderWithExpectedSize<ATNState>(stateSequence.size + other.stateSequence.size)
          .addAll(stateSequence)
          .addAll(other.stateSequence)
          .build(),
      )
    }

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

  data class TokenTypePair(val formerTokenType: TokenType, val latterTokenType: TokenType) {
    companion object {
      fun Pair<TokenType, TokenType>.toTokenTypePair() = TokenTypePair(
        formerTokenType = first,
        latterTokenType = second,
      )
    }
  }
}

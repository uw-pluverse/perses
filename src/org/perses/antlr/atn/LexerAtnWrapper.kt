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
package org.perses.antlr.atn

import com.google.common.collect.HashBasedTable
import com.google.common.collect.ImmutableBiMap
import com.google.common.collect.ImmutableList
import com.google.common.collect.Sets
import com.google.common.collect.Table
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.atn.ATN
import org.antlr.v4.runtime.atn.ATNState
import org.antlr.v4.runtime.atn.RuleStartState
import org.antlr.v4.runtime.atn.RuleStopState
import org.antlr.v4.runtime.atn.Transition
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.atn.nfa.ATNConstructorFromRegex
import org.perses.antlr.atn.nfa.NFA
import org.perses.antlr.atn.tdtree.TDTree
import org.perses.util.SimpleStack
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap
import java.util.concurrent.locks.ReentrantReadWriteLock
import kotlin.concurrent.read
import kotlin.concurrent.write

class LexerAtnWrapper<T : Lexer>(lexerClass: Class<T>) {

  val atn = getAtnFromLexer(lexerClass)

  val tokenInformation = TokenInformation.create(atn, lexerClass)

  private val simulatorMap = HashMap<Int, ATNSimulator>()

  private val normalizedATNs = HashMap<Int, Pair<RuleStartState, AbstractPersesRuleElement>>()

  internal val tokenTypePairToNecessityOfWhiteSpaceForConcat: Table<Int, Int, Boolean> =
    HashBasedTable.create()

  private val readWriteLock = ReentrantReadWriteLock()

  private fun normalizeAtn(
    tokenType: Int,
  ): Pair<RuleStartState, AbstractPersesRuleElement> {
    var originalStartState: RuleStartState? = null
    var regex: AbstractPersesRuleElement? = null
    return try {
      originalStartState = getOriginalStartState(tokenType)
      regex = NFA.copyAndInlineOf(originalStartState).simplifyToRegex()
      Pair(ATNConstructorFromRegex().construct(regex), regex)
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

  private fun getNormalizedStartState(ruleType: Int): RuleStartState {
    return getNormalizedAtn(ruleType).first
  }

  fun getNormalizedAtn(tokenType: Int): Pair<RuleStartState, AbstractPersesRuleElement> {
    return normalizedATNs.computeIfAbsent(tokenType) {
      normalizeAtn(it)
    }
  }

  fun getOriginalStartState(ruleType: Int): RuleStartState {
    val tokenInfo = tokenInformation.getTokenInfoWithType(ruleType)
    return atn.ruleToStartState[tokenInfo.ruleIndex]
  }

  private fun getOriginalEndState(ruleType: Int): RuleStopState {
    val tokenInfo = tokenInformation.getTokenInfoWithType(ruleType)
    return atn.ruleToStopState[tokenInfo.ruleIndex]
  }

  fun findATNPathForLexeme(lexeme: String, ruleType: Int): ATNPath {
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

  fun createTDTree(lexeme: String, ruleType: Int): TDTree {
    val path = findATNPathForLexeme(lexeme, ruleType)
    return simulateRule(ruleType, ReplayDecisionMaker(path, lexeme)).apply {
      removeNodesWithNoCharLeaves()
    }
  }

  fun simulateRule(ruleType: Int, decisionMaker: AbstractDecisionMaker): TDTree {
    val startState = getNormalizedStartState(ruleType)
    val simulator = simulatorMap.computeIfAbsent(ruleType) {
      ATNSimulator(startState)
    }
    return simulator.simulate(decisionMaker).removeNodesWithNoCharLeaves()
  }

  fun canBeConcatWithoutSpace(tokenNameFormer: String, tokenNameLatter: String) =
    canBeConcatWithoutSpace(
      tokenInformation.getTokenInfoWithName(tokenNameFormer).tokenType,
      tokenInformation.getTokenInfoWithName(tokenNameLatter).tokenType,
    )

  fun canBeConcatWithoutSpace(tokenTypeFormer: Int, tokenTypeLatter: Int): Boolean {
    val result = readWriteLock.read {
      tokenTypePairToNecessityOfWhiteSpaceForConcat.get(tokenTypeFormer, tokenTypeLatter)
    } ?: let {
      readWriteLock.write {
        // in case another thread might have acquired the writeLock and update the cache.
        tokenTypePairToNecessityOfWhiteSpaceForConcat.get(tokenTypeFormer, tokenTypeLatter)
          ?: let {
            val calculatedResult = calculateNecessityOfSpaceBetweenTwoToken(
              tokenTypeFormer,
              tokenTypeLatter,
            )
            tokenTypePairToNecessityOfWhiteSpaceForConcat
              .put(tokenTypeFormer, tokenTypeLatter, calculatedResult)
            calculatedResult
          }
      }
    }
    return result
  }

  private fun calculateNecessityOfSpaceBetweenTwoToken(
    tokenTypeFormer: Int,
    tokenTypeLatter: Int,
  ): Boolean {
    tokenInformation.asSequence().forEach { token ->
      if (canBeSubsumed(token.tokenType, tokenTypeFormer, tokenTypeLatter)) {
        return false
      }
    }
    return true
  }

  fun canBeSubsumed(subsumer: Int, subsumeeFormer: Int, subsumeeLatter: Int): Boolean {
    // check if nfa can be subsumed by nfaFormer + nfaLatter
    val nfa = copyTokenNfa(subsumer)
    val nfaFormer = copyTokenNfa(subsumeeFormer)
    val nfaLatter = copyTokenNfa(subsumeeLatter)

    val stackFormer = SimpleStack<Pair<ATNState, ATNState>>()
    val stackLatter = SimpleStack<Pair<ATNState, ATNState>>()
    val visitedFormer = HashSet<Pair<ATNState, ATNState>>()
    val visitedLatter = HashSet<Pair<ATNState, ATNState>>()
    stackFormer.add(Pair(nfa.startState, nfaFormer.startState))
    visitedFormer.add(Pair(nfa.startState, nfaFormer.startState))

    while (stackFormer.isNotEmpty() || stackLatter.isNotEmpty()) {
      var stack = stackFormer
      var visited = visitedFormer
      if (stackFormer.isEmpty()) {
        stack = stackLatter
        visited = visitedLatter
      }
      val (subsumerSource, subsumeeSource) = stack.remove()
      // find all the nodes with non-epsilon edges that can be reached by epsilon transition
      val states1 = getReachableStatesWithNonEpsilonTransition(subsumerSource)
      val states2 = getReachableStatesWithNonEpsilonTransition(subsumeeSource)
      states1.forEach { s1 ->
        states2.forEach { s2 ->
          if (s1 === nfa.acceptingState && s2 === nfaLatter.acceptingState) {
            return true
          }
          // connect nfaFormer and nfaLatter
          if (s2 === nfaFormer.acceptingState &&
            !visited.contains(Pair(s1, nfaLatter.startState))
          ) {
            visitedLatter.add(Pair(s1, nfaLatter.startState))
            stackLatter.add(Pair(s1, nfaLatter.startState))
          }
          s1.transitionSequence().forEach { t1 ->
            s2.transitionSequence().forEach { t2 ->
              if (!visited.contains(Pair(t1.target, t2.target))) {
                if (t1.label().and(t2.label()).size() > 0) {
                  visited.add(Pair(t1.target, t2.target))
                  stack.add(Pair(t1.target, t2.target))
                }
              }
            }
          }
        }
      }
    }
    return false
  }

  fun getReachableStatesWithNonEpsilonTransition(start: ATNState): List<ATNState> {
    val seen = HashSet<ATNState>()
    val stack = SimpleStack<ATNState>()
    val result = ArrayList<ATNState>()
    seen.add(start)
    stack.add(start)
    while (stack.isNotEmpty()) {
      val state = stack.remove()
      var hasNonEpsilonTransition = false
      state.transitionSequence().forEach { t ->
        if (t.isEpsilon) {
          val target = t.target
          if (seen.add(target)) {
            stack.add(t.target)
          }
        } else {
          hasNonEpsilonTransition = true
        }
      }
      // include states with no transition
      if (hasNonEpsilonTransition || state.getNumberOfTransitions() == 0) {
        result.add(state)
      }
    }

    assert(Sets.newIdentityHashSet<ATNState>().also { it.addAll(result) }.size == result.size)
    return result
  }

  fun copyTokenNfa(tokenType: Int): NFA {
    val startState = getNormalizedAtn(tokenType).first
    return NFA.copyOf(startState)
  }

  companion object {

    @JvmStatic
    fun <T : Lexer> getTokenNameTypePairs(lexerClass: Class<T>): ImmutableBiMap<String, Int> {
      @Suppress("UNCHECKED_CAST")
      val names = lexerClass.getField("ruleNames").get(null) as Array<String>
      return names.asSequence()
        .map {
          try {
            val index = lexerClass.getField(it).get(null) as Int
            it to index
          } catch (e: NoSuchFieldException) {
            null // This might be a fragment.
          }
        }.filter { it != null }
        .map { it!! }
        .fold(ImmutableBiMap.builder<String, Int>()) { acc, ele ->
          acc.put(ele.first, ele.second)
          acc
        }.build()
    }

    @JvmStatic
    fun <T : Lexer> getAtnFromLexer(lexerClass: Class<T>): ATN {
      return lexerClass.getField("_ATN").get(null) as ATN
    }
  }

  class TokenInformation(
    tokens: ImmutableList<Info>,
  ) {

    private val nameToTokenMapping = tokens
      .asSequence()
      .map { it.tokenName to it }
      .toImmutableMap()

    private val typeToTokenMapping = tokens
      .asSequence()
      .map { it.tokenType to it }
      .toImmutableMap()

    fun getTokenInfoWithName(tokenName: String) =
      nameToTokenMapping[tokenName] ?: error("No info for token $tokenName")

    fun getTokenInfoWithType(tokenType: Int) =
      typeToTokenMapping[tokenType] ?: error("No info for type $tokenType")

    fun asSequence(): Sequence<Info> = nameToTokenMapping.values.asSequence()

    data class Info(
      val tokenName: String,
      val tokenType: Int,
      val ruleIndex: Int,
    )

    companion object {
      fun <T : Lexer> create(atn: ATN, lexerClass: Class<T>): TokenInformation {
        val tokenNameTypePairs = getTokenNameTypePairs(lexerClass)
        return TokenInformation(
          atn.ruleToTokenType
            .withIndex()
            .asSequence()
            .filter { it.value != 0 /*0 means nothing.*/ }
            .map { (ruleIndex, tokenType) ->
              val tokenName = tokenNameTypePairs.inverse()[tokenType]!!
              Info(tokenName, tokenType, ruleIndex)
            }.toImmutableList(),
        )
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
}

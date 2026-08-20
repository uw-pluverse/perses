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
package org.perses.reduction.reducer.latra.language

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CommonToken
import org.perses.grammar.AbstractParserFacade
import org.perses.program.TokenPosition
import org.perses.reduction.reducer.latra.language.AbstractLatraPattern.Companion.findAllHolesIn
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.ConcreteToken
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole.HoleName
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Trivia

class PatternElementParser(
  private val patternContent: String,
  private val parserFacade: AbstractParserFacade,
  private val tolerateLexingException: Boolean,
) {
  private var currentLineNo = 1
  private var currentCharPositionInLine = 1
  private val patternElementsBuilder = ImmutableList.Builder<AbstractPatternElement>()

  // TODO(cnsun): needs tests.
  fun parse(): ImmutableList<AbstractPatternElement> {
    var patternIndex = 0
    val holes = findAllHolesIn(patternContent)

    for (hole in holes) {
      val range = hole.range

      // Handle non-hole elements first
      processNonHoleElementsForSubPatternContent(
        fromIndexInclusive = patternIndex,
        endIndexExclusive = range.first,
      )
      patternIndex = range.last + 1

      // If the hole name is empty it would not be matched
      val greedyKleenePlusMatching = hole.groups[2]?.value == "+"
      patternElementsBuilder.add(
        createHole(
          wholeContent = patternContent.substring(range),
          holeName = hole.groups[1]!!.value,
          greedy = greedyKleenePlusMatching,
        ),
      )
    }

    // Trailing non-hole elements
    processNonHoleElementsForSubPatternContent(
      fromIndexInclusive = patternIndex,
      endIndexExclusive = patternContent.length,
    )
    return patternElementsBuilder.build()
  }

  private fun processNonHoleElementsForSubPatternContent(
    fromIndexInclusive: Int,
    endIndexExclusive: Int,
  ) {
    if (fromIndexInclusive >= endIndexExclusive) {
      return
    }
    val substring = patternContent.substring(fromIndexInclusive, endIndexExclusive)
    val processedNonHoleElements =
      kotlin.runCatching {
        tokenizeNonHoleElements(string = substring)
      }
    if (processedNonHoleElements.isSuccess) {
      patternElementsBuilder.addAll(processedNonHoleElements.getOrThrow())
    } else {
      if (tolerateLexingException) {
        patternElementsBuilder.add(createTrivia(substring))
      } else {
        throw processedNonHoleElements.exceptionOrNull()!!
      }
    }
  }

  private fun getPositionAndUpdate(consumedString: String): TokenPosition {
    val current = TokenPosition(currentLineNo, currentCharPositionInLine)
    consumedString.forEach { char ->
      if (char == '\n') {
        ++currentLineNo
        currentCharPositionInLine = 1
      } else {
        ++currentCharPositionInLine
      }
    }
    return current
  }

  private fun createHole(
    wholeContent: String,
    holeName: String,
    greedy: Boolean,
  ): Hole {
    val position = getPositionAndUpdate(wholeContent)
    return Hole(HoleName(holeName), greedy, position)
  }

  private fun createTrivia(content: String): Trivia {
    val position = getPositionAndUpdate(content)
    return Trivia(content, position)
  }

  private fun createConcreteToken(token: CommonToken): ConcreteToken {
    val position = getPositionAndUpdate(token.text)
    token.line = position.line
    token.charPositionInLine = position.charPositionInLine
    return ConcreteToken(token)
  }

  private fun tokenizeNonHoleElements(string: String): List<AbstractPatternElement> {
    val tokens =
      parserFacade.tokenizeString(
        string,
        fileName = "<in memory for parsing latra patterns>",
      )
    var tokenIndex = 0
    var codeSnippetIndex = 0

    val result = mutableListOf<AbstractPatternElement>()
    while (codeSnippetIndex < string.length) {
      if (tokenIndex >= tokens.size) {
        val trivia = string.substring(codeSnippetIndex)
        result.add(createTrivia(trivia))
        break
      }

      val token = tokens[tokenIndex]
      val tokenIndexInCodeSnippet = token.startIndex

      // Trivia
      if (tokenIndexInCodeSnippet > codeSnippetIndex) {
        result.add(createTrivia(string.substring(codeSnippetIndex, tokenIndexInCodeSnippet)))
      }

      result.add(createConcreteToken(token as CommonToken))
      codeSnippetIndex = token.stopIndex + 1
      ++tokenIndex
    }
    return result
  }
}

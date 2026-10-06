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
package org.perses.listminimizer.microbenchmark

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.flattokenlist.FlatTokenListParserFacade
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeParserUtility
import org.perses.util.Interval
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

/**
 * Tokenizes a recorded program with its own real lexer under the `FlatTokenList` grammar
 * (`start : TOKEN* EOF`), and maps recorded character ranges back to the resulting token nodes.
 *
 * The grammar is what makes this safe on a recorded program: it accepts whatever the lexer emits, so
 * a mid-reduction program that no longer parses under its real grammar is a non-issue. Characters
 * the real lexer cannot tokenize survive as dropped-character tokens rather than vanishing, which
 * matters for inputs like a `\`-newline splice.
 *
 * Producing a [SparTree] rather than a bare token list is deliberate: it lets the evaluation reuse
 * the production deletion path (`NodeDeletionActionSet` -> `SparTree.createNodeDeletionEdit`)
 * instead of a parallel implementation. The tree is returned to the caller rather than wrapped,
 * because the caller needs it for exactly that.
 */
object RecordedProgramTokenizer {
  /**
   * The tree the text-based evaluation runs on, cut from [sourceCode] at the recorded ranges with
   * no lexer involved. A range of n tokens becomes n leaves -- its two ends plus n - 1 cuts inside
   * it, placed arbitrarily since the element is only ever deleted whole -- and each gap between
   * ranges one leaf. So every range begins and ends at a leaf boundary by construction, which makes
   * [resolveElements] infallible here whatever the language, and an element's leaf count is its
   * recorded token count, which makes every consumer that sums leaf counts -- the containers, the
   * weights, the metrics -- right without knowing about recordings.
   *
   * Ranges must not overlap: an element's leaves are its weight, and a token under two elements
   * would be weighed twice. No recorded corpus has an overlap.
   */
  fun buildRecordedRangeTree(
    sourceCode: String,
    elements: List<RecordedElement>,
  ): SparTree =
    SparTreeParserUtility.buildSparTree(
      sourceCode = sourceCode,
      parserFacade = RecordedRangeParserFacade(cutOffsetsOf(sourceCode, elements)),
      specifiedSparTreeNodeFactory = null,
      simplifyTree = true,
      canonicalTokenCountComputer = { null },
      errorMode = ParseErrorHandling.TOLERANT,
    )

  internal fun cutOffsetsOf(
    sourceCode: String,
    elements: List<RecordedElement>,
  ): IntArray {
    val length = sourceCode.codePointCount(0, sourceCode.length)
    val ranges = elements.flatMap { it.ranges }.sortedBy { it.leftInclusive }
    ranges.zipWithNext().forEach { (previous, next) ->
      require(previous.rightExclusive <= next.leftInclusive) {
        "The ranges $previous and $next overlap; an element's leaves are its weight."
      }
    }
    val cuts = sortedSetOf(0, length)
    ranges.forEach { range ->
      require(range.rightExclusive <= length) {
        "The range $range is outside the text, which has $length code point(s)."
      }
      val tokenCount =
        requireNotNull(range.tokenCount) {
          "The range $range has no token count; the recording predates them."
        }
      // One leaf per token: the first tokenCount - 1 pieces are one code point each and the last
      // takes the rest of the range, which is always possible because a range holds at least as
      // many code points as tokens. Where the cuts fall does not matter -- the element is only
      // ever deleted whole -- but how many there are does, since the leaf count is the weight.
      for (cut in range.leftInclusive..range.leftInclusive + tokenCount - 1) {
        cuts.add(cut)
      }
      cuts.add(range.rightExclusive)
    }
    return cuts.toIntArray()
  }

  fun buildFlatTokenListTree(
    sourceCode: String,
    underlyingLexerClass: Class<out Lexer>,
  ): SparTree =
    SparTreeParserUtility.buildSparTree(
      sourceCode = sourceCode,
      parserFacade = FlatTokenListParserFacade(underlyingLexerClass),
      specifiedSparTreeNodeFactory = null,
      simplifyTree = true,
      canonicalTokenCountComputer = { null },
      // TOKEN* EOF cannot reject anything the lexer emits, so this should be unreachable; it is
      // TOLERANT anyway because robustness on a mid-reduction program is the whole point.
      errorMode = ParseErrorHandling.TOLERANT,
    )

  /** The offset of the token's first character, matching [Interval.leftInclusive]. */
  fun inclusiveStartOffsetOf(node: LexerRuleSparTreeNode): Int =
    node.token.asAntlrToken().startIndex

  /**
   * One past the offset of the token's last character, matching [Interval.rightExclusive]. The `+ 1`
   * is not an off-by-one: ANTLR's own `stopIndex` is inclusive, so the two conventions differ.
   */
  fun exclusiveEndOffsetOf(node: LexerRuleSparTreeNode): Int =
    node.token.asAntlrToken().stopIndex + 1

  /**
   * The token nodes of each element, in the element order given, each list in source order and
   * without duplicates. Overlapping ranges are therefore a union rather than an error, matching how
   * a candidate is defined.
   *
   * Every element is resolved in one pass: the tree's tokens are read once and indexed once, rather
   * than per element. Reading them from [tree] on each call rather than caching a snapshot means
   * there is nothing to go stale against a later edit -- the tree stays the single source of truth.
   *
   * Every range must begin exactly at a token's first character and end exactly one past a token's
   * last. That check is the integrity gate on the whole recording: a range that starts mid-token or
   * inside inter-token whitespace means this tokenization disagrees with the one that produced the
   * recording -- a wrong language, a stale problem, or a lexer that splits differently -- and it is
   * far sharper than comparing token counts, which can agree by coincidence.
   */
  fun resolveElements(
    tree: SparTree,
    rangesPerElement: List<Iterable<Interval>>,
  ): ImmutableList<ImmutableList<LexerRuleSparTreeNode>> {
    val index = TokenIndex(tree.remainingLexerRuleNodes)
    return rangesPerElement.transformToImmutableList { index.resolve(it) }
  }

  private const val NEIGHBORHOOD_CHARACTERS = 20

  private const val NEIGHBORHOOD_TOKENS = 8

  /** The tokens indexed by start offset, for one resolution pass. */
  private class TokenIndex(
    private val tokenNodes: ImmutableList<LexerRuleSparTreeNode>,
  ) {
    private val startOffsets: IntArray =
      IntArray(tokenNodes.size) { inclusiveStartOffsetOf(tokenNodes[it]) }

    fun resolve(ranges: Iterable<Interval>): ImmutableList<LexerRuleSparTreeNode> {
      val resolved = sortedSetOf<Int>()
      ranges.forEach { range ->
        resolved.addAll(resolveSingleRange(range))
      }
      return resolved.map { tokenNodes[it] }.toImmutableList()
    }

    private fun resolveSingleRange(range: Interval): List<Int> {
      require(range.length > 0) { "An element range must not be empty: $range" }
      val first = indexOfFirstTokenStartingAtOrAfter(range.leftInclusive)
      require(first < tokenNodes.size && startOffsets[first] == range.leftInclusive) {
        "The range $range does not begin at a token boundary. ${describeNeighborhood(range)}"
      }
      var last = first
      while (last + 1 < tokenNodes.size &&
        exclusiveEndOffsetOf(tokenNodes[last + 1]) <= range.rightExclusive
      ) {
        ++last
      }
      require(exclusiveEndOffsetOf(tokenNodes[last]) == range.rightExclusive) {
        "The range $range does not end at a token boundary. ${describeNeighborhood(range)}"
      }
      return (first..last).toList()
    }

    private fun indexOfFirstTokenStartingAtOrAfter(offset: Int): Int {
      var low = 0
      var high = tokenNodes.size
      while (low < high) {
        val middle = (low + high) ushr 1
        if (startOffsets[middle] < offset) {
          low = middle + 1
        } else {
          high = middle
        }
      }
      return low
    }

    private fun describeNeighborhood(range: Interval): String {
      val nearby =
        tokenNodes
          .asSequence()
          .filter {
            exclusiveEndOffsetOf(it) > range.leftInclusive - NEIGHBORHOOD_CHARACTERS &&
              inclusiveStartOffsetOf(it) < range.rightExclusive + NEIGHBORHOOD_CHARACTERS
          }.take(NEIGHBORHOOD_TOKENS)
          .joinToString(separator = ", ") {
            "[${inclusiveStartOffsetOf(it)},${exclusiveEndOffsetOf(it)})='${it.token.lexemeText}'"
          }
      return "Nearby tokens: $nearby"
    }
  }
}

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
package org.perses.antlr.pnf

import com.google.common.annotations.VisibleForTesting
import org.perses.antlr.ast.PersesSequenceAst

class AltBlockExtractionPass : AbstractAltBlockExtractionPass() {

  override fun searchForCandidate(sequences: List<PersesSequenceAst>): AbstractCandidate? {
    val size = sequences.size
    for (i in 0 until size - 1) {
      val first = sequences[i]
      for (j in i + 1 until size) {
        val second = sequences[j]
        val candidate = searchForCandidate(first, second)
        if (candidate != null) {
          return candidate
        }
      }
    }
    return null
  }

  companion object {

    @VisibleForTesting
    fun searchForCandidate(s1: PersesSequenceAst, s2: PersesSequenceAst): AbstractCandidate? {
      val originalSequences = listOf(s1, s2)
      val left = searchAssumingCommonPrefix(s1, s2)
      val candidates = ArrayList<AbstractCandidate>()
      if (left != null) {
        candidates.add(left)
      }
      val right = searchAssumingCommonPostfix(s1, s2)
      if (right != null) {
        candidates.add(right)
      }
      val infix = searchAssummingCommonPrefixAndPostfix(left, right, originalSequences)
      if (infix != null) {
        candidates.add(infix)
      }
      return selectBestCandidate(candidates, originalSequences)
    }

    @VisibleForTesting
    fun searchAssumingCommonPrefix(
      s1: PersesSequenceAst,
      s2: PersesSequenceAst,
    ): CommonPrefixCandidate? {
      val originalSequences = listOf(s1, s2)
      return selectBestCandidate(
        computeCandidatesClosedPrefix(originalSequences),
        originalSequences,
      )
    }

    @VisibleForTesting
    fun searchAssumingCommonPostfix(
      s1: PersesSequenceAst,
      s2: PersesSequenceAst,
    ): CommonPostfixCandidate? {
      val originalSequences = listOf(s1, s2)
      return selectBestCandidate(
        computeCandidatesClosedPostfix(originalSequences),
        originalSequences,
      )
    }

    @VisibleForTesting
    fun searchAssummingCommonPrefixAndPostfix(
      left: CommonPrefixCandidate?,
      right: CommonPostfixCandidate?,
      originalSequences: List<PersesSequenceAst>,
    ): InfixCandidate? {
      if (left == null) {
        return null
      }
      if (right == null) {
        return null
      }
      assert(left.sequences == right.sequences)
      return computeCandidateInfix(listOf(left), listOf(right), originalSequences)
    }
  }
}

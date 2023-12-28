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

import org.perses.antlr.ast.PersesSequenceAst

/**
 * Different from [AltBlockExtractionPass], this pass supports extraction of
 * multiple alternatives (>=2), while [AltBlockExtractionPass] each time only
 * extracts a block of two alternatives.
 */
class MultiAltBlockExtractionPass : AbstractAltBlockExtractionPass() {

  override fun searchForCandidate(sequences: List<PersesSequenceAst>): AbstractCandidate? {
    val prefixCandidates = computeCandidatesClosedPrefix(sequences)
    val postfixCandidates = computeCandidatesClosedPostfix(sequences)
    val infixCandidate = computeCandidateInfix(prefixCandidates, postfixCandidates, sequences)
    val allCandidates = ArrayList<AbstractCandidate>().apply {
      addAll(prefixCandidates)
      addAll(postfixCandidates)
      if (infixCandidate != null) {
        add(infixCandidate)
      }
    }
    return selectBestCandidate(allCandidates, sequences)
  }
}

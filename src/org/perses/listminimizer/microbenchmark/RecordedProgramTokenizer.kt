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

import org.perses.grammar.ParseErrorHandling
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeParserUtility
import org.perses.util.Interval

/**
 * Rebuilds a recorded program's tree from the program and its recorded token offsets, for the
 * evaluation to run on.
 *
 * Producing a [SparTree] rather than a bare token list is deliberate: it lets the evaluation reuse
 * the production deletion path (`NodeDeletionActionSet` -> `SparTree.createNodeDeletionEdit`)
 * instead of a parallel implementation. The tree is returned to the caller rather than wrapped,
 * because the caller needs it for exactly that.
 */
object RecordedProgramTokenizer {
  /**
   * The tree the evaluation runs on: [sourceCode] re-tokenized at the recorded token offsets with
   * no lexer involved (see [RecordedRangeParserFacade]), so leaf i is the recorded program's token
   * i and a recorded element is a run of leaves. Every consumer that counts leaves -- the
   * containers, the weights, the metrics, Perses's own size bookkeeping -- is right without knowing
   * about recordings.
   */
  fun buildRecordedRangeTree(
    sourceCode: String,
    tokenOffsets: List<Interval>,
  ): SparTree =
    SparTreeParserUtility.buildSparTree(
      sourceCode = sourceCode,
      parserFacade = RecordedRangeParserFacade(tokenOffsets),
      specifiedSparTreeNodeFactory = null,
      simplifyTree = true,
      canonicalTokenCountComputer = { null },
      errorMode = ParseErrorHandling.TOLERANT,
    )
}

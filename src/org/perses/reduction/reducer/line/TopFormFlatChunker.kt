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
package org.perses.reduction.reducer.line

import com.google.common.collect.ImmutableList
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.util.ImmutableListBuilderExt

/**
 * Partitions a token sequence the way Berkeley delta's `topformflat` partitions a source file,
 * i.e. the port of `benchmark_v2/binaries/delta_src/topformflat.lex` to Perses's token world.
 *
 * `topformflat` tracks brace nesting and re-lineates the source, emitting a newline after `;`, `{`
 * and `}` only where the nesting is at most a given threshold, so that `delta` can then delete
 * whole lines: at threshold 0 a line is an entire top-level form, and higher thresholds expose
 * progressively finer inner statements. The re-lineation is only a way to hand a line-based tool
 * the set of cut points; the cut points themselves are what matters, and Perses deletes tokens
 * rather than lines. This class therefore computes the same cut points over the token sequence and
 * leaves the text alone. (Modern c-vise does the same: its `topformflat_hints` emits the cut points
 * as byte ranges and never re-flows the source.)
 *
 * The original's other lexer rules -- the string and character literal start conditions, the `//`
 * comment rule, the `#` directive rule, and newline-to-space rewriting -- exist only to keep a
 * character scanner from miscounting braces and to preserve layout. Neither concern survives the
 * move to tokens: the language's own lexer has already resolved quoting and comments, so a `}`
 * inside a string literal is not a `}` token, and there is no layout to preserve. That makes this
 * port strictly more robust than the original, which `internal_doc/topformflat_vs_dyck.md` notes
 * "can be fooled by a `}` hidden in a macro".
 */
object TopFormFlatChunker {
  fun computeChunks(
    tokens: ImmutableList<LexerRuleSparTreeNode>,
    nestingThreshold: Int,
  ): ImmutableList<ImmutableList<LexerRuleSparTreeNode>> {
    require(nestingThreshold >= 0) {
      "Invalid nesting threshold $nestingThreshold. Must be non-negative."
    }
    val result = ImmutableList.Builder<ImmutableList<LexerRuleSparTreeNode>>()
    var chunkBuilder = ImmutableListBuilderExt<LexerRuleSparTreeNode>()
    var nesting = 0
    var index = 0
    while (index < tokens.size) {
      val token = tokens[index]
      chunkBuilder.add(token)
      ++index
      val cut =
        when (token.token.lexemeText) {
          OPEN_BRACE -> {
            ++nesting
            nesting <= nestingThreshold
          }
          CLOSE_BRACE -> {
            // The original matches "}" and an immediately following ";" as the single lexeme
            // `"}"(";"?)`, so the pair yields one cut, not two. Absorb the ";" to match.
            --nesting
            if (index < tokens.size && tokens[index].token.lexemeText == SEMICOLON) {
              chunkBuilder.add(tokens[index])
              ++index
            }
            nesting <= nestingThreshold
          }
          SEMICOLON -> nesting <= nestingThreshold
          else -> false
        }
      if (cut) {
        result.add(chunkBuilder.build())
        chunkBuilder = ImmutableListBuilderExt()
      }
    }
    if (chunkBuilder.isNotEmpty()) {
      result.add(chunkBuilder.build())
    }
    return result.build()
  }

  private const val OPEN_BRACE = "{"
  private const val CLOSE_BRACE = "}"
  private const val SEMICOLON = ";"
}

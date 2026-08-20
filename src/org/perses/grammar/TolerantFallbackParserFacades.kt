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
package org.perses.grammar

import org.perses.grammar.dyck.AdaptiveDyckParserFacade
import org.perses.grammar.line.LineParserFacade
import org.perses.grammar.onetoken.OneTokenParserFacade

/**
 * The tolerant-grammar fallback ladder used to keep reducing a program that does not parse under its
 * real grammar. See internal_doc/tolerant_grammar_fallback_design.md.
 *
 * The ladder is two rungs, ordered most-specific to most-general:
 *
 *   real grammar  ->  adaptive Dyck
 *
 * It is defined here as a *successor* relation ([nextTolerantFallbackOrNull]) rather than a
 * materialized list: each step is computed from the current facade, and the chain terminates at
 * [AdaptiveDyckParserFacade], the guaranteed floor.
 *
 * The Dyck rung tokenizes with the *real* grammar's lexer and groups those tokens by balanced
 * delimiters, i.e. a tolerant version of the real grammar. Being adaptive is what makes one rung
 * enough: it enables per file only the delimiter kinds that actually nest, so it cannot fail, and
 * when no kind nests it degrades to a list of lines -- a finer tree than [LineParserFacade] gives,
 * whose `LINE` token is one indivisible lexeme per line. The fixed-delimiter Dyck rungs this ladder
 * used to descend, and the Line rung below them, are therefore all subsumed by this single rung.
 *
 * [LineParserFacade] and [OneTokenParserFacade] remain terminal: neither is reachable as a fallback
 * any more, but either can be the *starting* facade (`--lang line`, `--lang one-token`), and neither
 * has anything more general to fall back to.
 */
object TolerantFallbackParserFacades {
  /**
   * The next, more-general, tolerant grammar to try after [facade] cannot parse the input, or null
   * when [facade] is already terminal. Every non-terminal facade -- a real grammar, or one of the
   * fixed-delimiter Dyck facades a user can select explicitly -- falls back to the adaptive Dyck
   * grammar over [AbstractParserFacade.realLexerClass], so the rung stays a tolerant version of the
   * same real grammar rather than re-tokenizing with an adaptor's own lexer.
   */
  fun nextTolerantFallbackOrNull(facade: AbstractParserFacade): AbstractParserFacade? =
    when (facade) {
      is AdaptiveDyckParserFacade, is LineParserFacade, is OneTokenParserFacade -> null
      else -> AdaptiveDyckParserFacade(facade.realLexerClass)
    }
}

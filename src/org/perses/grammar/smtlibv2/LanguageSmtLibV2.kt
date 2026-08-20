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
package org.perses.grammar.smtlibv2

import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind

object LanguageSmtLibV2 : LanguageKind(
  name = "smtlibv2",
  // "sy" is SyGuS. Its parser (synth-fun/constraint/check-synth) is not in SMTLIBv2.g4, so a
  // .sy file does not structurally parse -- but SyGuS shares SMT-LIB's lexical grammar exactly,
  // so the SMTLIBv2 lexer tokenizes it faithfully. That is enough for the lexer-based reducers
  // (the Dyck node reducers wrap this language's real lexer; see DyckLexer) and token-chunking
  // topformflat to operate on the SyGuS benchmarks in benchmark_smt.
  extensions = ImmutableSet.of("smt2", "sy"),
  defaultCodeFormatControl = EnumFormatControl.COMPACT_ORIG_FORMAT,
  origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  allowedCodeFormatControl =
    ImmutableSet.of(
      EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      EnumFormatControl.COMPACT_ORIG_FORMAT,
      EnumFormatControl.ORIG_FORMAT,
    ),
)

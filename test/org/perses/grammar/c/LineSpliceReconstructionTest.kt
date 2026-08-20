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
package org.perses.grammar.c

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.dyck.BraceParenthesisDyckParserFacade
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.SparTreeParserUtility

/**
 * Round-trips line splices through the tolerant C and Dyck facades and prints the result in
 * ORIG_FORMAT, building the spar-tree exactly as the reducer does. Guards that a `\`-newline splice
 * survives reconstruction (its failure made topformflat score 0% on the six unparseable splice
 * benchmarks). Two independent mechanisms keep it faithful, one per kind of splice:
 *
 *  - A DIRECTIVE splice (`#def\`+newline+`ine X 0`, the benchmark mutation) is handled by the
 *    grammar: OrigC.g4's IncludeDirective token absorbs the backslash-newline continuation, so the
 *    whole directive is ONE token and is never dropped. Both facades share this C lexer, so both
 *    round-trip it.
 *  - A NON-directive splice (a bare `\` between statements) has no grammar token, so it goes through
 *    the tolerant DroppedCharacterCollector: only the `\` is dropped and the newline is re-lexed as
 *    line structure, so `\` is followed by exactly one newline. Before that fix the dropped run was
 *    `"\\\n"` and the printer added a second newline, breaking the splice.
 *  - A `@` at end of line is the control for the dropped-char path: its run is just `"@"` and it
 *    round-trips cleanly.
 */
@RunWith(JUnit4::class)
class LineSpliceReconstructionTest {
  private val tolerantC = PnfCParserFacade()
  private val dyckWithCLexer =
    BraceParenthesisDyckParserFacade(underlyingLexerClass = PnfCLexer::class.java)

  private fun program(
    code: String,
    facade: AbstractParserFacade,
    mode: ParseErrorHandling,
  ): TokenizedProgram =
    SparTreeParserUtility
      .buildSparTree(
        sourceCode = code,
        parserFacade = facade,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = true,
        canonicalTokenCountComputer = { null },
        errorMode = mode,
      ).programSnapshot.payload

  private fun tolerantCReconstruction(code: String) =
    PrinterRegistry.printToStringInOrigFormat(program(code, tolerantC, ParseErrorHandling.TOLERANT))

  // The reducer reparses with a Dyck facade in TOLERANT mode (see
  // AbstractProgramReductionDriver.inputRepresentationCreator: the Dyck reparse is the one tolerant
  // case, so an unbalanced program still yields a tree). Match that here, not STRICT.
  private fun dyckReconstruction(code: String) =
    PrinterRegistry.printToStringInOrigFormat(
      program(code, dyckWithCLexer, ParseErrorHandling.TOLERANT),
    )

  private fun lexemes(
    code: String,
    facade: AbstractParserFacade,
    mode: ParseErrorHandling,
  ) = program(code, facade, mode).tokens.map { it.lexemeText }

  // A DIRECTIVE splice -- the mutation in the six unparseable splice benchmarks. `#def\`+newline+
  // `ine X 0` is one preprocessing directive spliced across two physical lines; the preprocessor
  // rejoins it into `# define X 0`. The C grammar's IncludeDirective token absorbs the
  // backslash-newline continuation, so the whole thing is ONE token -- never dropped.
  private val directiveSplice = "#def\\\nine X 0\nint keep(void) { return 1; }\n"

  // A NON-directive splice: a bare `\` line continuation between two statements. The grammar has no
  // token starting with `\`, so this is what exercises the tolerant DroppedCharacterCollector path.
  private val plainSplice = "int a;\\\nint b;\n"

  @Test
  fun aDirectiveSpliceIsLexedAsOneTokenAndRoundTrips() {
    // The grammar recognizes the spliced directive as a single token, so the `\`-newline survives
    // verbatim and reconstruction is faithful -- no dropping, no doubled newline.
    val lexemes = lexemes(directiveSplice, tolerantC, ParseErrorHandling.TOLERANT)
    assertThat(lexemes).contains("#def\\\nine X 0")
    val out = tolerantCReconstruction(directiveSplice)
    assertThat(out).contains("#def\\\nine X 0") // `\` then exactly one newline: splice intact
    assertThat(out).doesNotContain("\\\n\n") // no spurious blank line
  }

  @Test
  fun aPlainBackslashSpliceRoundTripsViaTheDroppedCharPath() {
    // The bare `\` is dropped alone (DroppedCharacterCollector marks only startIndex) and the newline
    // is re-lexed as line structure, so `\` is followed by exactly one newline: the splice survives.
    // Regression guard -- before the fix the dropped run was "\\\n" and the printer added a second
    // newline, breaking the splice.
    val out = tolerantCReconstruction(plainSplice)
    assertThat(out).contains("int a;\\\nint b;") // `\` then exactly one newline
    assertThat(out).doesNotContain("\\\n\n") // no spurious blank line
    val lexemes = lexemes(plainSplice, tolerantC, ParseErrorHandling.TOLERANT)
    assertThat(lexemes).contains("\\") // the dropped run is exactly the backslash
    assertThat(lexemes).doesNotContain("\\\n") // it never carries the newline
  }

  @Test
  fun aStrayCharacterAtEndOfLineDoesNotSwallowTheNewline() {
    // Control: `@` begins no lexer rule, so its dropped run is just `@`, and the line round-trips.
    val code = "int a;@\nint b;\n"
    val out = tolerantCReconstruction(code)
    assertThat(out).contains("int a;@\nint b;")
    assertThat(out).doesNotContain("@\n\n")
    val strays = lexemes(code, tolerantC, ParseErrorHandling.TOLERANT).filter { it.contains("@") }
    assertThat(strays).containsExactly("@")
  }

  @Test
  fun dyckWithTheSameCLexerPreservesTheDirectiveSplice() {
    // The Dyck facade lexes with the same C lexer underneath, so it too now sees the directive as one
    // token and round-trips the splice faithfully.
    val out = dyckReconstruction(directiveSplice)
    assertThat(out).contains("#def\\\nine X 0")
    assertThat(out).doesNotContain("\\\n\n")
  }
}

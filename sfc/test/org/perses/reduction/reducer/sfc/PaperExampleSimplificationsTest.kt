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
package org.perses.reduction.reducer.sfc

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.PnfCParserFacade
import org.perses.reduction.reducer.sfc.SfcTestUtility.findNodeSpelling

/**
 * The twelve simplifications listed in Section 4.1 of `doc/publication/2025_sfc_oopsla.pdf`, as
 * the paper's own examples of what Structure Form Conversion enables, reproduced on the real C
 * grammar.
 *
 * In the paper's notation, `ei` is an expression, `si` a statement, and `a` and `b` identifiers.
 * They are written here as C programs, and every declaration a program needs is in [PREAMBLE].
 * The paper writes example twelve as `for(s1;;s2)`, which C spells with a body, so the candidate
 * is `for ( a ; ; b ) ;`.
 */
@RunWith(JUnit4::class)
class PaperExampleSimplificationsTest {
  private val facade = PnfCParserFacade()

  /** What the examples need in order to be C: a function, a struct with two fields, variables. */
  private val preamble = "int f(int, int); struct S { int b; int c; } a, b, c;"

  private fun assertConverts(
    sourceCode: String,
    subtree: String,
    expected: String,
  ) {
    val tree = TestUtility.createSparTreeFromString(sourceCode, facade, simplifyTree = true)
    val candidates =
      StructureFormConverter(facade, tree.sparTreeNodeFactory)
        .convert(tree.findNodeSpelling(subtree))
        .map { it.lexemes.joinToString(separator = " ") }
        .toList()
    assertThat(candidates).contains(expected)
  }

  @Test
  fun anAndExpressionBecomesTheNegationOfItsLeftOperand() {
    assertConverts("$preamble int g() { return a && b; }", "a && b", "! a")
  }

  @Test
  fun aComparisonBecomesTheNegationOfItsLeftOperand() {
    assertConverts("$preamble int g() { return a < b; }", "a < b", "! a")
  }

  @Test
  fun aFieldAccessBecomesTheAddressOfTheObject() {
    assertConverts("$preamble int g() { return a.b; }", "a . b", "& a")
  }

  @Test
  fun aFieldAccessBecomesTheSizeOfTheObject() {
    assertConverts("$preamble int g() { return a.b; }", "a . b", "sizeof a")
  }

  @Test
  fun anArrayAccessBecomesTheDereferenceOfTheArray() {
    assertConverts("$preamble int g() { return a[b]; }", "a [ b ]", "* a")
  }

  @Test
  fun anArrayAccessFollowedByAFieldBecomesAnArrowAccess() {
    assertConverts("$preamble int g() { return a[b].c; }", "a [ b ] . c", "a -> c")
  }

  @Test
  fun anAssignmentToAFieldBecomesAnIncrementOfIt() {
    assertConverts("$preamble int g() { a.b = c; }", "a . b = c", "++ a . b")
  }

  @Test
  fun aCallBecomesTheDecrementOfItsFirstArgument() {
    assertConverts("$preamble int g() { return f(a, b); }", "f ( a , b )", "-- a")
  }

  @Test
  fun aStatementBecomesTheEmptyStatement() {
    assertConverts("$preamble int g() { a = b; }", "a = b ;", ";")
  }

  @Test
  fun anIfStatementBecomesItsCondition() {
    assertConverts("$preamble int g() { if (a = b); }", "if ( a = b ) ;", "a = b ;")
  }

  @Test
  fun aForLoopBecomesAWhileLoopOverItsUpdate() {
    assertConverts(
      "$preamble int g() { for (;a;a++); }",
      "for ( ; a ; a ++ ) ;",
      "while ( a ++ ) ;",
    )
  }

  @Test
  fun theStatementsOfAForLoopBodyBecomeItsHeader() {
    assertConverts(
      "$preamble int g() { for (;;) { a; b; } }",
      "for ( ; ; ) { a ; b ; }",
      "for ( a ; ; b ) ;",
    )
  }
}

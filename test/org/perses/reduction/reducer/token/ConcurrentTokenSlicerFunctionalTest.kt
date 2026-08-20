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
package org.perses.reduction.reducer.token

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFunctionalTestUtility

@RunWith(JUnit4::class)
class ConcurrentTokenSlicerFunctionalTest {
  @Test
  fun test_delta_1_grep_based() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/benchmark_toys/delta_1",
      testScript = "grep_based_r.sh",
      sourceFile = "t.c",
      reducerAnnotation = ConcurrentTokenSlicer.CompositeReducerAnnotation,
      cmdCustomizer = {},
    ).use {
      // The token slicer delegates to the list-minimizer bridge, which does not check canonical
      // parsability before each property test, so it deletes every token but the single string
      // literal needed to satisfy the grep property, even though that literal is not valid C alone.
      it.runReducerAndTest(expected = """ "world\n" """.trim())
    }
  }

  @Test
  fun test_delta_1_grep_based_line_based() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/benchmark_toys/delta_1",
      testScript = "grep_based_r.sh",
      sourceFile = "t.c",
      reducerAnnotation = LineBasedConcurrentTokenSlicer.CompositeReducerAnnotation,
      cmdCustomizer = {},
    ).use {
      // The line slicer parses with the line grammar and does not require the result to be parsable
      // by the canonical (C) facade, so it deletes the surrounding function and keeps only the
      // single line needed to satisfy the property, even though that line is not valid C on its own.
      it.runReducerAndTest(expected = """printf("world\n");""".trim())
    }
  }
}

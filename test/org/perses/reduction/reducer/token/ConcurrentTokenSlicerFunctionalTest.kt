/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
      // It is not possible to get only the string literal, because our token slicer
      // checks syntactical validity before each property test.
      it.runReducerAndTest(expected = """printf { ("world\n");}""".trim())
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
      // It is not possible to get only the string literal, because our token slicer
      // checks syntactical validity before each property test.
      it.runReducerAndTest(expected = """main{("world\n");}""".trim())
    }
  }
}

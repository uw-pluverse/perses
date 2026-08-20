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
package org.perses.reduction.reducer.trec

import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFunctionalTestUtility

@RunWith(JUnit4::class)
class TokenCanonicalizerFunctionalTest {
  @Ignore("TODO(cnsun): need to enable this.")
  @Test
  fun test() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/benchmark_toys/python3_print",
      testScript = "r_for_TRec.sh",
      sourceFile = "hello_for_TRec.py",
      reducerAnnotation = TokenCanonicalizer.META,
      cmdCustomizer = {},
    ).use {
      it.runReducerAndTest(expected = "")
    }
  }
}

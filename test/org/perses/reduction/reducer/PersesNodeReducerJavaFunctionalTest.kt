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
package org.perses.reduction.reducer

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFunctionalTestUtility

/** Test for the Java version of perses node reducer.  */
@RunWith(JUnit4::class)
class PersesNodeReducerJavaFunctionalTest {
  @Test
  fun testFunctionalTest() {
    ReducerFunctionalTestUtility.runJavaTestSubject(
      reductionFolder = "test_data/java_helloworld",
      reducerAnnotation = PersesNodeReducerAnnotations.PrioritizedDfs,
      cmdCustomizer = {},
      // The interestingness test now only requires the marker string to remain
      // (see test_data/java_helloworld/r.sh), so the reducer strips the program
      // down to the minimal structure that still contains it.
      expected =
        """
        |class t {
        |  {
        |    out.println("hello world");
        |  }
        |}
        """.trimMargin(),
    )
  }
}

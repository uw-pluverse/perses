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
package org.perses.reduction.reducer.hdd

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFunctionalTestUtility

/** Functional test for [HDDReducerAnnotations]  */
@RunWith(JUnit4::class)
class HddReducerFunctionalTest {
  val expectedForDelta1 =
    """
      |int printf();
      |int main(){
      |  printf("world\n");
      |}
    """.trimMargin()

  // Note that, since we remove --ensureAntlrValidity, we no longer check whether the reduced
  // program conforms to the grammar. Therefore, it is possible to reduce some invalid programs,
  // accepted by the compiler, but not the grammar used by Perses.
  @Test
  fun testReduceDelta1_hdd() {
    ReducerFunctionalTestUtility.runCTestSubject(
      reductionFolder = "test_data/delta_1",
      reducerAnnotation = HDDReducerAnnotations.Hdd,
      cmdCustomizer = {},
      expected = expectedForDelta1,
    )
  }

  @Test
  fun testReduceDelta1_pristine_hdd() {
    ReducerFunctionalTestUtility.runCTestSubject(
      reductionFolder = "test_data/delta_1",
      reducerAnnotation = PristineHDDReducer.META,
      cmdCustomizer = {},
      expected = expectedForDelta1,
    )
  }

  // The interestingness test now only requires the marker string to remain
  // (see test_data/java_helloworld/r.sh), so HDD reduces the program down to
  // that string literal.
  private val expectedForJavaHelloWorld = "\"hello world\""

  @Test
  fun testJavaFunctionalTest_hdd() {
    ReducerFunctionalTestUtility.runJavaTestSubject(
      reductionFolder = "test_data/java_helloworld",
      reducerAnnotation = HDDReducerAnnotations.Hdd,
      cmdCustomizer = {},
      expected = expectedForJavaHelloWorld,
    )
  }

  @Test
  fun testJavaFunctionalTest_pristine_hdd() {
    ReducerFunctionalTestUtility.runJavaTestSubject(
      reductionFolder = "test_data/java_helloworld",
      reducerAnnotation = PristineHDDReducer.META,
      cmdCustomizer = {},
      expected = expectedForJavaHelloWorld,
    )
  }
}

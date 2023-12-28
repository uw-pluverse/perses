/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
import org.perses.reduction.AbstractReducerFunctionalTest

/** Functional test for [HDDReducer]  */
@RunWith(JUnit4::class)
class HddReducerFunctionalTest : AbstractReducerFunctionalTest() {

  val expectedForDelta1 = """
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
    runCTestSubject(
      "test_data/delta_1",
      HDDReducer.META,
      expectedForDelta1,
    )
  }

  @Test
  fun testReduceDelta1_pristine_hdd() {
    runCTestSubject(
      "test_data/delta_1",
      PristineHDDReducer.META,
      expectedForDelta1,
    )
  }

  private val expectedForJavaHelloWorld = """
        |class t {
        |  static int counter() {
        |    return 100;
        |  }
        |  public static void main(String[] args) {
        |    for(int i = 0; i < counter(); ++i) {
        |      System.out.println("hello world");
        |    }
        |  }
        |}
  """.trimMargin()

  @Test
  fun testJavaFunctionalTest_hdd() {
    runJavaTestSubject(
      "test_data/java_helloworld",
      HDDReducer.META,
      expectedForJavaHelloWorld,
    )
  }

  @Test
  fun testJavaFunctionalTest_pristine_hdd() {
    runJavaTestSubject(
      "test_data/java_helloworld",
      PristineHDDReducer.META,
      expectedForJavaHelloWorld,
    )
  }
}

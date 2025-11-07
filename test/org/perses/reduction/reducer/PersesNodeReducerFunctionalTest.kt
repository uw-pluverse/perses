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
package org.perses.reduction.reducer

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFunctionalTestUtility
import java.nio.file.Paths

@RunWith(JUnit4::class)
class PersesNodeReducerFunctionalTest {
  @Test
  fun testFunctionalTest() {
    test(
      "delta_1",
      """
        |int printf();
        |int main() {
        |    printf("world\n"); 
        |}
      """.trimMargin(),
    )
  }

  @Test
  fun testFunctionalTestOnCreduceExample() {
    ReducerFunctionalTestUtility.runCTestSubject(
      reductionFolder = "test_data/creduce_example",
      reducerAnnotation = PersesNodePrioritizedDfsReducer.META,
      cmdCustomizer = { cmd ->
        cmd.outputRefiningFlags.callCReduce = true
        cmd.outputRefiningFlags.creduceCmd =
          Paths
            .get("test/org/perses/reduction/reducer/dummy-creduce.sh")
            .toAbsolutePath()
            .toString()
      },
      expected =
        """
              | int printf(const char*, ...);
              | int main() {
              |     printf("world\n");
              | }
        """.trimMargin(),
    )
  }

  fun debug() {
    ReducerFunctionalTestUtility.runBenchmarkSubject(
      reductionFolder = "benchmark/gcc-71626",
      reducerAnnotation = PersesNodePrioritizedDfsReducer.META,
      cmdCustomizer = {},
      expected =
        "typedeflongllong;test1char8(c){}" +
          "typedefllongvllong1__attribute__((__vector_size__(sizeof(llong))));" +
          "vllong1test2llong1(p){llongc=test1char8;vllong1v={c};returnv;}main(){}",
    )
  }

  private fun test(
    folder: String,
    expected: String,
  ) {
    ReducerFunctionalTestUtility.runCTestSubject(
      reductionFolder = "test_data/$folder",
      reducerAnnotation = PersesNodeDfsReducer.META,
      expected = expected,
    )
  }
}

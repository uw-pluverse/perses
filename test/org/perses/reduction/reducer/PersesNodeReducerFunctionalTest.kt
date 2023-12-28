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
package org.perses.reduction.reducer

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.AbstractReducerFunctionalTest
import java.nio.file.Paths

@RunWith(JUnit4::class)
class PersesNodeReducerFunctionalTest : AbstractReducerFunctionalTest() {

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
    runCTestSubject(
      "test_data/creduce_example",
      PersesNodePrioritizedDfsReducer.META,
      { cmd ->
        cmd.outputRefiningFlags.callCReduce = true
        cmd.outputRefiningFlags.creduceCmd =
          Paths.get("test/org/perses/reduction/reducer/dummy-creduce.sh")
            .toAbsolutePath().toString()
      },
      """
        | int printf(const char*, ...);
        | int main() {
        |     printf("world\n");
        | }
      """.trimMargin(),
    )
  }

  fun debug() {
    runBenchmarkSubject(
      "benchmark/gcc-71626",
      PersesNodePrioritizedDfsReducer.META,
      {},
      "typedeflongllong;test1char8(c){}" +
        "typedefllongvllong1__attribute__((__vector_size__(sizeof(llong))));" +
        "vllong1test2llong1(p){llongc=test1char8;vllong1v={c};returnv;}main(){}",
    )
  }

  private fun test(folder: String, expected: String) {
    runCTestSubject("test_data/$folder", PersesNodeDfsReducer.META, expected)
  }
}

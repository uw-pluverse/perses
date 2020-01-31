/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction.reducer;

import org.antlr.runtime.RecognitionException;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.AbstractReducerFunctionalTest;

import java.io.IOException;
import java.util.concurrent.ExecutionException;

/** The functional test for {@link AbstractPersesNodeReducer} */
@RunWith(JUnit4.class)
public class PersesNodeReducerFunctionalTest extends AbstractReducerFunctionalTest {

  @Test
  public void testFunctionalTest() {
    test("delta_1", "int main(){printf(\"world\\n\");}");
  }

  public void debug()
      throws InterruptedException, ExecutionException, RecognitionException, IOException {
    runBenchmarkSubject(
        "benchmark/gcc-71626",
        PersesNodePrioritizedDfsReducer.META,
        "typedeflongllong;test1char8(c){}"
            + "typedefllongvllong1__attribute__((__vector_size__(sizeof(llong))));"
            + "vllong1test2llong1(p){llongc=test1char8;vllong1v={c};returnv;}main(){}");
  }

  private void test(String folder, String expected) {
    runCTestSubject("test_data/" + folder, PersesNodeDfsReducer.META, expected);
  }
}

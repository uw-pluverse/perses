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

import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.AbstractReducerFunctionalTest;

/** Functional test for {@link HDDReducer} */
@RunWith(JUnit4.class)
public class HddReducerFunctionalTest extends AbstractReducerFunctionalTest {

  // Note that, since we remove --ensureAntlrValidity, we no longer check whether the reduced
  // program conforms to the grammar. Therefore, it is possible to reduce some invalid programs,
  // accepted by the compiler, but not the grammar used by Perses.
  @Ignore
  @Test
  public void testReduceDelta1() {
    runCTestSubject("test_data/delta_1", HDDReducer.META, "int main(){printf(\"world\\n\");}");
  }

  @Ignore
  @Test
  public void testFunctionalTest() {
    runJavaTestSubject(
        "test_data/java_helloworld",
        HDDReducer.META,
        "classt{staticintcounter(){return100;}publicstaticvoidmain(String[]args)"
            + "{for(inti=0;i<counter();++i){System.out.println(\"helloworld\");}}}");
  }
}

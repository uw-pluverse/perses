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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableList
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.rust.OrigRustParserFacade
import org.perses.grammar.rust.PnfRustParserFacade
import org.perses.reduction.reducer.latra.rust.RustTransformationList

@RunWith(JUnit4::class)
class RustLatraTransformationTest :
  AbstractTransformationTest<RustTransformationList>(
    facadeList = ImmutableList.of(PnfRustParserFacade(), OrigRustParserFacade()),
    transformationList = RustTransformationList,
  ) {
  @Test
  fun testClearStruct() {
    testTransformation(
      transformation = transformationList.clearStruct,
      source = """
        struct Person {
          name: String,
          age: u32,
        }
      """,
      expectOutput1 = "struct Person ;",
    )
  }

  @Test
  fun testClearBlock() {
    testTransformation(
      transformation = transformationList.clearBlock,
      source = "fn g (f: impl c<e, j>) -> impl c<e, e::b> { f }",
      expectOutput1 = "fn g (f : impl c <e , j>) -> impl c < e , e :: b > { unimplemented ! () }",
    )
  }

  @Test
  fun testNoneDefaulting() {
    testTransformation(
      transformation = transformationList.noneDefaulting,
      source =
        """
        fn main (){
          let x = (20 * 5) + (8 / 2) - (4 % 3);
        }
        """.trimIndent(),
      expectOutput1 = "fn main ( ) { let x = None . unwrap ( ) ; }",
    )
  }
}

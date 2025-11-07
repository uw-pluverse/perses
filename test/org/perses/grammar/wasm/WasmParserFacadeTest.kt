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
package org.perses.grammar.wasm

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ParseTreeUtil
import org.perses.grammar.AbstractParserFacade
import java.nio.file.Paths

@RunWith(JUnit4::class)
class WasmParserFacadeTest {
  val facade: AbstractParserFacade = WebAssemblyParserFacade()

  @Test
  fun testParseFile() {
    facade.parseFile(Paths.get("test_data/wat_programs/small.wat"))
    facade.parseFile(Paths.get("test_data/wat_programs/conversions.wat"))
  }

  @Test
  fun testParseFileThatIsAcceptedByWabtButNotSyntacticallyValid() {
    val program =
      """
        (module
        (type       (func                                             ))
        (type       (func             ))
        (type       (func            ))
        (type       (func                                         ))
        (type       (func                             ))
        (type       (func                             ))
        (type       (func                             ))
        (type       (func             ))
        (type       (func                                 ))
        (type       (func                             ))
        (type        (func (param i32 i32 i32 i32)))
        (func)
        (func)
        (func)
        (func)
        (func)
        (func)
        (func)
        (func)
        (func)
        (func       (type 10)
      )
        (func                 (param f64 i32) (result f64)
          local.get 1
          local.get 1
          local.get 1
          local.get 1
          i32.const 1
          call_indirect (type 10)
          f32.const 0
          local.get 0
          local.get 1
          f32.load offset=0
          drop
          drop
          drop
          local.get 0)
        (func
          f64.const 0
          i32.const +0
          call 10
          return)
        (table       10      funcref)
        (memory       0          )
        (export "main" (func 11))
        (elem       (i32.const 1)      9)
        ) 
      """.trimIndent()
    // The following should not throw an exception
    val result = facade.parseString(program)
    Truth.assertThat(ParseTreeUtil.getTokens(result.tree)).isNotEmpty()
  }
}

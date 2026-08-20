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
import org.perses.grammar.wasm.WebAssemblyParserFacade
import org.perses.reduction.reducer.latra.wat.WatFineGritTransformationList

@RunWith(JUnit4::class)
class WatFineGritTransformationListTest :
  AbstractTransformationTest<WatFineGritTransformationList>(
    facadeList = ImmutableList.of(WebAssemblyParserFacade()),
    transformationList = WatFineGritTransformationList,
  ) {
  @Test
  fun testRemovePairedIfEndTokens() {
    testTransformation(
      transformation = transformationList.removePairedIfEndTokens,
      source =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          if
            i32.const 0
            drop
          end
        )
        )
        """.trimIndent(),
      expectOutput1 =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          drop
            i32.const 0
            drop
        )
        )
        """.trimIndent(),
    )
  }

  private val watWithIfElse =
    """
    (module
    (func (export "_start")
      i32.const 1
      i32.eq
      if
        i32.const 0
        drop
      else
        drop
      end
    )
    )
    """.trimIndent()

  @Test
  fun testReplaceIfBlockWithTrueBranch() {
    testTransformation(
      transformation = transformationList.replaceIfBlockWithTrueBranch,
      source = watWithIfElse,
      expectOutput1 =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          drop
            i32.const 0
            drop
        )
        )
        """.trimIndent(),
    )
  }

  @Test
  fun testReplaceIfBlockWithTrueBranch2() {
    testTransformation(
      transformation = transformationList.replaceIfBlockWithTrueBranch2,
      source =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          if
            i32.const 0
            drop
          else
          end
        )
        )
        """.trimIndent(),
      expectOutput1 =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          drop
            i32.const 0
            drop
        )
        )
        """.trimIndent(),
    )
  }

  @Test
  fun testReplaceIfBlockWithFalseBranch() {
    testTransformation(
      transformation = transformationList.replaceIfBlockWithFalseBranch,
      source = watWithIfElse,
      expectOutput1 =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          drop
            drop
        )
        )
        """.trimIndent(),
    )
  }

  @Test
  fun testReplaceIfBlockWithFalseBranch2() {
    testTransformation(
      transformation = transformationList.replaceIfBlockWithFalseBranch2,
      source =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          if
          else
            drop
          end
        )
        )
        """.trimIndent(),
      expectOutput1 =
        """
        (module
        (func (export "_start")
          i32.const 1
          i32.eq
          drop
            drop
        )
        )
        """.trimIndent(),
    )
  }

  val sourceWithBlockEnd =
    """
    (module
    (func (export "_start")
      block
        local.get 0
        i32.const 0
        i32.le_s
        br_if 0       ;; Branch to end
        local.get 0
        local.set 0
        local.get 0
        local.set 0
        br 0          ;; Branch to end
      end
    )
    )
    """.trimIndent()

  @Test
  fun testDropPairedBlockEndTokens() {
    testTransformation(
      transformation = transformationList.dropPairedBlockEndTokens,
      source = sourceWithBlockEnd,
      expectOutput1 =
        """
        (module
        (func (export "_start")
            local.get 0
            i32.const 0
            i32.le_s
            br_if 0 
            local.get 0
            local.set 0
            local.get 0
            local.set 0
        )
        )
        """.trimIndent(),
    )
  }

  @Test
  fun testReplaceBrifWithDrop() {
    testTransformation(
      transformation = transformationList.replaceBranchIfWithDrop,
      source =
      sourceWithBlockEnd,
      expectOutput1 =
        """
        (module
        (func (export "_start")
          block
            local.get 0
            i32.const 0
            i32.le_s
            drop
            local.get 0
            local.set 0
            local.get 0
            local.set 0
            br 0          ;; Branch to end
          end
        )
        )
        """.trimIndent(),
    )
  }
}

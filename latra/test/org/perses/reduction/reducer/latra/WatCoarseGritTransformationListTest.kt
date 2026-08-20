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
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList.clearBodyForNamedFuncsWithTypeReference
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList.clearBodyForNamedFuncsWithTypeReferenceAndExport
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList.clearBodyForNonVoidFuncWithArgs
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList.clearBodyForUnnamedFuncsWithTypeReference
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList.clearBodyForVoidFuncWoArgs
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList.simplifyDataSegment

@RunWith(JUnit4::class)
class WatCoarseGritTransformationListTest :
  AbstractTransformationTest<WatCoarseGritTransformationList>(
    facadeList = ImmutableList.of(WebAssemblyParserFacade()),
    transformationList = WatCoarseGritTransformationList,
  ) {
  val nonVoidFuncWith2Args = """
          (module
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32) (result i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          )
        """

  val funcWithTypeReferenceAndExport = """
          (module
            (type ${'$'}add_type (func (param i32 i32) (result i32)))
            (func ${'$'}add (export "add_nums") (type ${'$'}add_type)
              (i32.add (local.get 0) (local.get 1))
            )
          )  
        """

  val funcWithNameAndTypeReference = """
          (module
            (type ${'$'}add_type (func (param i32 i32) (result i32)))
            (func ${'$'}add (type ${'$'}add_type) (param i32 i32)
              (i32.add (local.get 0) (local.get 1))
            )
          )  
        """
  val unnamedFuncWithTypeReference = """
          (module
            (type ${'$'}add_type (func (param i32 i32) (result i32)))
            (func (type ${'$'}add_type) (param i32 i32)
              (i32.add (local.get 0) (local.get 1))
            )
          )  
        """

  @Test
  fun testClearBodyForFuncsWithTypeReferenceAndExport() {
    testTransformation(
      transformation = clearBodyForNamedFuncsWithTypeReferenceAndExport,
      source = funcWithTypeReferenceAndExport,
      expectOutput1 =
        """
        (module
          (type ${'$'}add_type (func (param i32 i32) (result i32)))
          (func ${'$'}add (export "add_nums") (type ${'$'}add_type)
              unreachable
          )
        )  
        """.trimIndent(),
    )
  }

  @Test
  fun testClearBodyForFuncsWithTypeReference() {
    testTransformation(
      transformation = clearBodyForNamedFuncsWithTypeReference,
      source = funcWithNameAndTypeReference,
      expectOutput1 =
        """
        (module
          (type ${'$'}add_type (func (param i32 i32) (result i32)))
          (func ${'$'}add (type ${'$'}add_type)
              unreachable
          )
        )  
        """.trimIndent(),
    )
  }

  @Test
  fun testClearBodyForUnnamedFuncsWithTypeReference() {
    testTransformation(
      transformation = clearBodyForUnnamedFuncsWithTypeReference,
      source = unnamedFuncWithTypeReference,
      expectOutput1 =
        """
        (module
          (type ${'$'}add_type (func (param i32 i32) (result i32)))
          (func (type ${'$'}add_type)
              unreachable
          )
        )  
        """.trimIndent(),
    )
  }

  @Test
  fun testClearBodyForNonVoidFuncWith2Args() {
    testTransformation(
      transformation =
        clearBodyForNonVoidFuncWithArgs
          .single { it.first == 2 }
          .second,
      source = nonVoidFuncWith2Args,
      expectOutput1 = """
          (module
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32) (result i32)
              (i32.const 0)
            )
          )
        """,
    )
  }

  @Test
  fun testClearBodyForVoidFuncWith2Args() {
    testTransformation(
      transformation =
        clearBodyForVoidFuncWoArgs
          .single { it.first == 2 }
          .second,
      source = nonVoidFuncWith2Args,
      expectOutput1 = """
          (module
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32)
            )
          )
        """,
    )
  }

  @Test
  fun testSimplifyDataSegment() {
    testTransformation(
      transformation = simplifyDataSegment,
      source =
        """
        (module
          (data (i32.const 100) "hello, world!")
        )
        """.trimIndent(),
      expectOutput1 =
        """
        (module
          (data (i32.const 100) "")
        )
        """.trimIndent(),
    )
  }

//  @Test
//  fun testClearBodyForVoidFuncWith2Args() {
//    testTransformation(
//      transformation = WebAssemblyTransformationList.clearBodyForVoidFuncWithAtLeastTwoArgs,
//      source = nonVoidFuncWith2Args,
//      expectOutput1 = """
//            (module
//              (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32)
//              )
//            )
//        """.trimIndent()
//    )
//  }
}

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
package org.perses.reduction.reducer.latra.wat

import org.perses.reduction.reducer.latra.AbstractLatraTransformationList
import org.perses.util.transformToImmutableList

object WatCoarseGritTransformationList : AbstractLatraTransformationList() {
  val clearBodyForNamedFuncsWithTypeReferenceAndExport =
    registerTransformation(
      name = "ClearBodyForNamedFuncsWithTypeReferenceAndExport",
      from =
        """
        (func :[funcName] (export :[export]) (type :[reference+]) 
            :[body+]
        )
        """.trimIndent(),
      such_as =
        """
        (module
          {g:
            (func ${'$'}f (type 1) (param i32 i32) (result i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          :}
        ) 
        """.trimIndent(),
      to =
        """
        (func :[funcName] (export :[export]) (type :[reference])
            unreachable
        )
        """.trimIndent(),
    )

  val clearBodyForNamedFuncsWithTypeReference =
    registerTransformation(
      name = "ClearBodyForNamedFuncsWithTypeReference",
      from =
        """
        (func :[funcName] (type :[reference+]) 
            :[body+]
        )
        """.trimIndent(),
      such_as =
        """
        (module
          {g:
            (func ${'$'}f (type 1) (param i32 i32) (result i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          :}
        ) 
        """.trimIndent(),
      to =
        """
        (func :[funcName] (type :[reference])
            unreachable
        )
        """.trimIndent(),
    )

  val clearBodyForUnnamedFuncsWithTypeReference =
    registerTransformation(
      name = "ClearBodyForUnnamedFuncsWithTypeReference",
      from =
        """
        (func (type :[reference+]) 
            :[body+]
        )
        """.trimIndent(),
      such_as =
        """
        (module
          {g:
            (func ${'$'}f (type 1) (param i32 i32) (result i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          :}
        ) 
        """.trimIndent(),
      to =
        """
        (func (type :[reference])
            unreachable
        )
        """.trimIndent(),
    )

  val clearBodyForNonVoidFuncWithArgs =
    (0..10).transformToImmutableList {
      it to createClearBodyForNonVoidFuncWithNArgs(numOfParams = it)
    }

  val clearBodyForVoidFuncWoArgs =
    (0..10).transformToImmutableList {
      it to createClearBodyForVoidFuncWithNArgs(numOfParams = it)
    }

  val simplifyDataSegment =
    registerTransformation(
      name = "SimplifyDataSegment",
      from = "(data :[offset+] :[actual_data])",
      to = """(data :[offset] "")""",
    )

  private fun createClearBodyForVoidFuncWithNArgs(numOfParams: Int): Transformation {
    require(numOfParams >= 0) { numOfParams }
    val paramList =
      buildString {
        for (i in 1..numOfParams) {
          append(" (param ${getParamName(i)} ${getParamType(i)}) ")
        }
      }
    return registerTransformation(
      name = "ClearBodyForVoidFuncWith${numOfParams}Args",
      from = """
        ( func :[funcName] $paramList
          :[body+]
        )
      """,
      such_as =
        """
        (module
          {g:
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          :}
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          ) 
        """,
      to = """
        ( func :[funcName] $paramList
        )
      """,
    )
  }

  private fun createClearBodyForNonVoidFuncWithNArgs(numOfParams: Int): Transformation {
    require(numOfParams >= 0) { numOfParams }
    val paramList =
      buildString {
        for (i in 1..numOfParams) {
          append(" (param ${getParamName(i)} ${getParamType(i)}) ")
        }
      }
    return registerTransformation(
      name = "ClearBodyForNonVoidFuncWith${numOfParams}Args",
      from = """
        ( func :[funcName] $paramList ( result :[return_type])
          :[body+]
        )
      """,
      such_as =
        """
        (module
          {g:
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32) (result i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          :}
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          ) 
        """,
      to = """
        ( func :[funcName] $paramList (result :[return_type])
          (:[return_type].const 0)
        )
      """,
    )
  }

  private fun getParamName(paramIndex: Int): String = ":[param_name_$paramIndex]"

  private fun getParamType(paramIndex: Int): String = ":[param_type_$paramIndex]"
}

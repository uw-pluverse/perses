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
package org.perses.reduction.reducer.latra.language.io

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class RawDefinitionTest {
  @Test
  fun testSerializingSimpleCase() {
    val def =
      RawDefinition(
        name = "test",
        from = "from clause",
        such_as = "",
        where = "",
        to = "",
        insert = ImmutableList.of(),
        global_replace = ImmutableList.of(),
      )
    val yaml = def.toYamlString()
    println(yaml)
    val copy = RawDefinition.fromYamlString(yaml)
    assertThat(copy).isEqualTo(def)
  }

  @Test
  fun testTheSimplestCase() {
    val def =
      RawDefinition(
        name = "LetSubstitute",
        from =
          """(let 
               |    ((:[sym] :[tem+])) :[body]+
               |)
          """.trimMargin(),
        such_as = "(let ((a (+ x 5)) (* a 2 ))",
        to = ":[body]",
        global_replace =
          ImmutableList.of(
            RawGlobalReplaceClause(
              pattern = ":[sym]",
              inside = ":[body]",
              with = ":[tem]",
            ),
          ),
      )
    val yaml = def.toYamlString()
    val copy = RawDefinition.fromYamlString(yaml)
    assertThat(copy).isEqualTo(def)
  }

  @Test
  fun testParsingSimpleCase() {
    val name = "LetSubstitute"
    val fromPattern = "(let ((:[sym] :[tem+])) :[body]+)"
    val string =
      """
        |---
        |name: "$name"
        |from: "$fromPattern"
        |such_as: "(let ((a (+ x 5)) (* a 2 ))"
        |to: ":[body]"
        |global_replace:
        |- pattern: ":[sym]"
        |  inside: ":[body]"
        |  with: ":[tem]"

      """.trimMargin()
    val copy = RawDefinition.fromYamlString(string)
    assertThat(copy.name).isEqualTo(name)
    assertThat(copy.from).isEqualTo(fromPattern)
    assertThat(copy.where).isEmpty()
    assertThat(copy.insert).isEmpty()
  }
}

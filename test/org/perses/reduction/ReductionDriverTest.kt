/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.CommandOptions
import org.perses.grammar.ParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.program.EnumFormatControl
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import org.perses.reduction.ReductionDriver.Companion.computeWhetherToEnableQueryCaching
import org.perses.reduction.ReductionDriver.Companion.createConfiguration

@RunWith(JUnit4::class)
class ReductionDriverTest {
  @Test
  fun test_computeWhetherToEnableQueryCaching() {
    for (format in EnumFormatControl.values()) {
      assertThat(
        computeWhetherToEnableQueryCaching(
          EnumQueryCachingControl.FALSE, format
        )
      )
        .isFalse()
    }
    for (format in EnumFormatControl.values()) {
      assertThat(
        computeWhetherToEnableQueryCaching(
          EnumQueryCachingControl.TRUE, format
        )
      ).isTrue()
    }
    assertThat(
      computeWhetherToEnableQueryCaching(
        EnumQueryCachingControl.AUTO, EnumFormatControl.ORIG_FORMAT
      )
    ).isFalse()
    assertThat(
      computeWhetherToEnableQueryCaching(
        EnumQueryCachingControl.AUTO, EnumFormatControl.COMPACT_ORIG_FORMAT
      )
    ).isFalse()
    assertThat(
      computeWhetherToEnableQueryCaching(
        EnumQueryCachingControl.AUTO, EnumFormatControl.SINGLE_TOKEN_PER_LINE
      )
    ).isTrue()
  }

  @Test
  fun testCreateConfiguration() {
    val cmd = CommandOptions(defaultReductionAlgName)
    cmd.compulsoryFlags.inputFile = "t.c"
    cmd.compulsoryFlags.testScript = "r.sh"
    try {
      createConfiguration(
        cmd, builderWithBuiltinLanguages().build()
      )
    } catch (e: RuntimeException) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      assertThat(e.message).contains("The file should be a regular file")
    }
  }
}

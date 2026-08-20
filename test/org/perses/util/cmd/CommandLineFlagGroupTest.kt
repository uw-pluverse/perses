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
package org.perses.util.cmd

import com.beust.jcommander.Parameter
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.cmd.AbstractCommandLineFlagGroup

@RunWith(JUnit4::class)
class CommandLineFlagGroupTest {
  class TestFlagGroup(
    name: String,
  ) : AbstractCommandLineFlagGroup(groupName = name) {
    @Parameter(names = ["--param1"])
    var param1: String = ""

    @Parameter(names = ["--param2"])
    var param2: Int = 0

    var nonParam: String = ""

    override fun validate() {}
  }

  class IncompleteFlagGroup(
    name: String,
  ) : AbstractCommandLineFlagGroup(groupName = name) {
    @Parameter(names = ["--param1"])
    var param1: String = ""

    override fun validate() {}
  }

  @Test
  fun testCopyParameterValuesFromSuccess() {
    val group1 = TestFlagGroup("Group1")
    val group2 = TestFlagGroup("Group2")

    group2.param1 = "newValue"
    group2.param2 = 42
    group2.nonParam = "shouldNotCopy"

    group1.copyParameterValuesFrom(group2)

    assertThat(group1.param1).isEqualTo("newValue")
    assertThat(group1.param2).isEqualTo(42)
    assertThat(group1.nonParam).isEqualTo("")
  }

  @Test
  fun testCopyParameterValuesFromMissingField() {
    val group1 = TestFlagGroup("Group1")
    val group2 = IncompleteFlagGroup("Group2")

    val exception =
      assertThrows(IllegalStateException::class.java) {
        group1.copyParameterValuesFrom(group2)
      }
    assertThat(exception.message).contains("Corresponding parameter field 'param2' not found")
  }
}

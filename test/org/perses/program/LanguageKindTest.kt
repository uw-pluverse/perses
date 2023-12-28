/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.program

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.shell.ShellCommandOnPath.IShellCommandOnPathCreator

@RunWith(JUnit4::class)
class LanguageKindTest {

  val language = object : LanguageKind(
    name = "fake",
    extensions = ImmutableSet.of("fake"),
    defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
    origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
    allowedCodeFormatControl = ImmutableSet.of(EnumFormatControl.ORIG_FORMAT),
    defaultFormatterCommandCreators = ImmutableList.of(
      IShellCommandOnPathCreator { ShellCommandOnPath("fake-formatter-that-should-not-exit") },
    ),
  ) {}

  @Test
  fun testShouldNotCrash() {
    language.defaultFormatterCommandCreators.let {
      Truth.assertThat(it).hasSize(1)
    }
  }
}

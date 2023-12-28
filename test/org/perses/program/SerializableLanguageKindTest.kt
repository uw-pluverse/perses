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
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class SerializableLanguageKindTest {

  @Test
  fun test() {
    val data = SerializableLanguageKind.LanguageKindData(
      name = "test",
      extensions = ImmutableSet.of("cp", "c"),
      defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      allowedCodeFormatControl = ImmutableSet.of(
        EnumFormatControl.ORIG_FORMAT,
        EnumFormatControl.COMPACT_ORIG_FORMAT,
      ),
      defaultFormatterCommands = ImmutableList.of(
        SerializableLanguageKind.ShellCommandData("ls", ImmutableList.of("-a")),
        SerializableLanguageKind.ShellCommandData("wc", ImmutableList.of("-l")),
      ),
    )

    val language = SerializableLanguageKind.fromYamlString(data.toYamlString())
    val yamlString = language.toYamlString()
    val copy = SerializableLanguageKind.fromYamlString(yamlString)
    assertThat(language.toYamlString()).isEqualTo(copy.toYamlString())
    assertThat(data).isEqualTo(SerializableLanguageKind.LanguageKindData.from(copy))
  }

  @Test
  fun testNullFormatterCommand() {
    val data = SerializableLanguageKind.LanguageKindData(
      name = "test",
      extensions = ImmutableSet.of("cp", "c"),
      defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      allowedCodeFormatControl = ImmutableSet.of(
        EnumFormatControl.ORIG_FORMAT,
        EnumFormatControl.COMPACT_ORIG_FORMAT,
      ),
    )

    val result = SerializableLanguageKind.LanguageKindData(
      name = "test",
      extensions = ImmutableSet.of("cp", "c"),
      defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      allowedCodeFormatControl = ImmutableSet.of(
        EnumFormatControl.ORIG_FORMAT,
        EnumFormatControl.COMPACT_ORIG_FORMAT,
      ),
      defaultFormatterCommands = ImmutableList.of(),
    )

    val language = SerializableLanguageKind.fromYamlString(data.toYamlString())

    val yamlString = language.toYamlString()
    val copy = SerializableLanguageKind.fromYamlString(yamlString)
    assertThat(language.toYamlString()).isEqualTo(copy.toYamlString())
    assertThat(result).isEqualTo(SerializableLanguageKind.LanguageKindData.from(copy))
  }
}

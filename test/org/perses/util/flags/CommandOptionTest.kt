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
package org.perses.util.flags

import com.beust.jcommander.Parameter
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.cmd.AbstractCommandOptions

@RunWith(JUnit4::class)
class CommandOptionTest {

  val cmd = object : AbstractCommandOptions() {
    @Parameter(names = ["--a"])
    var value = ""
  }

  val commander = cmd.parseArguments(
    "program_name",
    arrayOf("--a", "value", "--verbosity", "ERROR"),
  )

  @Test
  fun testFlagNameValueMap() {
    val map = commander.getFlagNameValueMap().asSequence()
      .map { it.key to it.value }
      .toList()
    assertThat(map).isEqualTo(
      listOf(
        "--a" to "value",
        "--help, -h" to "false",
        "--list-verbosity-levels" to "false",
        "--verbosity" to "ERROR",
        "--version" to "false",
      ),
    )
  }

  @Test
  fun testPrinter() {
    val message = commander.printUsage().trim()
    assertThat(message).isEqualTo(
      """
      |Usage: program_name [options]
      |  Options:
      |    --help, -h
      |      print help message
      |    --a
      |      Default: <empty string>
      |
      |[Verbosity]  Options:
      |    --verbosity
      |      verbosity of logging
      |      Default: INFO
      |    --list-verbosity-levels
      |      list all verbosity levels
      |
      |[Version]  Options:
      |    --version
      |      print the version
      """.trimMargin(),
    )
  }
}

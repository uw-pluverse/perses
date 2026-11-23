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
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.cmd.AbstractCommandOptions
import java.util.concurrent.TimeUnit

@RunWith(JUnit4::class)
class CommandOptionTest {
  val cmd =
    object : AbstractCommandOptions() {
      @Parameter(names = ["--a"])
      var value = ""
    }

  val commander =
    cmd.parseArguments(
      "program_name",
      arrayOf("--a", "value", "--verbosity", "ERROR"),
    )

  @Test
  fun testFlagNameValueMap() {
    val map =
      commander
        .getLongestFlagNameToValueMap()
        .asSequence()
        .map { it.key to it.value }
        .toList()
    assertThat(map).containsExactly(
      "--a" to "value",
      "--help" to "false",
      "--help-completion" to "false",
      "--list-verbosity-levels" to "false",
      "--verbosity" to "ERROR",
      "--version" to "false",
      "--hide-timestamps" to "false",
      "--fully-deterministic-mode" to "false",
    )
  }

  @Test
  fun testPrinter() {
    val message = commander.printUsage().trim()
    assertThat(message).isEqualTo(
      """
      |Usage: program_name [options]
      |  Options:
      |    --a
      |      Default: <empty string>
      |
      |[Verbosity]  Options:
      |    --verbosity
      |      verbosity of logging
      |      Default: INFO
      |    --list-verbosity-levels
      |      list all verbosity levels
      |    --hide-timestamps
      |      hide the timestamps in the log messages
      |      Default: false
      |
      |[Version]  Options:
      |    --version
      |      print the version
      |
      |[Help]  Options:
      |    -h, --help
      |      print help message
      """.trimMargin(),
    )
  }

  @Test
  fun testMarkdownUsage() {
    val options =
      object : AbstractCommandOptions() {
        @Parameter(
          names = ["--mode", "-m"],
          required = true,
          description = "a|b <path> *x* snake_case",
        )
        var mode = TimeUnit.SECONDS

        @Parameter(names = ["--name"])
        var name = ""
      }
    val markdown = options.parseArguments("program_name", arrayOf("--help")).renderMarkdownUsage()
    assertThat(markdown).startsWith(
      """
      |# Command Line Arguments
      |
      |```
      |Usage: program_name [options]
      |```
      |
      |## Options
      |
      || Flag | Description | Default |
      || --- | --- | --- |
      |
      """.trimMargin(),
    )
    assertThat(markdown).contains(
      "| `--mode`, `-m` | **Required.** a\\|b \\<path\\> \\*x\\* snake\\_case" +
        "<br>Possible values: " +
        TimeUnit.values().joinToString(", ") { "`$it`" } +
        " | `SECONDS` |\n",
    )
    assertThat(markdown).contains("| `--name` |  | *empty string* |\n")
    assertThat(markdown).contains("\n## Verbosity\n\n| Flag | Description | Default |\n")
    assertThat(markdown).contains("| `-h`, `--help` | print help message |  |\n")
  }
}

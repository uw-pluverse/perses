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

import com.beust.jcommander.JCommander
import com.beust.jcommander.Parameter
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Path

@RunWith(JUnit4::class)
class BashCompletionScriptPrinterTest {
  enum class Color { RED, GREEN }

  class VisibleFlags : AbstractCommandLineFlagGroup(groupName = "Visible") {
    @Parameter(names = ["--switch", "-s"])
    var switch = false

    @Parameter(names = ["--explicit-bool"], arity = 1)
    var explicitBool = true

    @Parameter(names = ["--color"])
    var color = Color.RED

    @Parameter(names = ["--colors"])
    var colors: List<Color> = listOf()

    @Parameter(names = ["--file"])
    var file: Path? = null

    @Parameter(names = ["--files"])
    var files: List<Path> = listOf()

    @Parameter(names = ["--count"])
    var count = 0

    @Parameter(names = ["--secret"], hidden = true)
    var secret = ""

    override fun validate() = Unit
  }

  class HiddenFlags : AbstractCommandLineFlagGroup(groupName = "Hidden", hidden = true) {
    @Parameter(names = ["--in-hidden-group"])
    var inHiddenGroup = ""

    override fun validate() = Unit
  }

  private fun createPrinter(
    vararg groups: AbstractCommandLineFlagGroup,
  ): BashCompletionScriptPrinter {
    // JCommander creates its parameter descriptions only when it parses.
    val commander = JCommander.newBuilder().addObject(groups.toList()).build()
    commander.parse()
    return BashCompletionScriptPrinter(commander)
  }

  private fun printFlagList(vararg groups: AbstractCommandLineFlagGroup) =
    createPrinter(*groups).printFlagList()

  @Test
  fun testValueSuffixPerFlagType() {
    assertThat(printFlagList(VisibleFlags())).isEqualTo(
      """
      |PERSES_COMPLETION_FLAGS="
      |--color={RED,GREEN}
      |--colors={RED,GREEN}
      |--count=
      |--explicit-bool={true,false}
      |--file=path
      |--files=path
      |--switch
      |-s
      |"
      |
      """.trimMargin(),
    )
  }

  @Test
  fun testHiddenFlagsAndHiddenGroupsAreOmitted() {
    val output = printFlagList(VisibleFlags(), HiddenFlags())
    assertThat(output).doesNotContain("--secret")
    assertThat(output).doesNotContain("--in-hidden-group")
    assertThat(output).contains("--switch")
  }

  @Test
  fun testScriptIsTemplateFollowedByFlagList() {
    val printer = createPrinter(VisibleFlags())
    val script = printer.print()
    assertThat(script).startsWith("# Bash completion for the perses command.")
    assertThat(script).contains("complete -F _perses__complete perses\n")
    assertThat(script).endsWith(printer.printFlagList())
  }

  @Test
  fun testHelpCompletionFlagIsParsedButNotListed() {
    val options = object : AbstractCommandOptions() {}
    val printer = options.parseArguments("test", arrayOf("--help-completion"))
    assertThat(options.helpFlags.helpCompletion).isTrue()
    val flagList =
      printer
        .printBashCompletionScript()
        .substringAfter(BashCompletionScriptPrinter.FLAG_LIST_VARIABLE)
    assertThat(flagList).contains("--help\n")
    assertThat(flagList).doesNotContain("--help-completion")
  }
}

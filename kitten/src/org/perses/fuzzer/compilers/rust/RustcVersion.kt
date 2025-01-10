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
package org.perses.fuzzer.compilers.rust

import com.google.common.collect.ImmutableList
import org.perses.grammar.rust.LanguageRust
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.shell.Shells
import org.perses.util.toImmutableList

data class RustcVersion private constructor(
  val rustc: ShellCommandOnPath,
  val versionString: String,
) {

  init {
    if (versionString != VERSION_NAME_NIGHTLY) {
      for (component in versionString.split('.')) {
        Integer.parseInt(component) // check if it is an integer.
      }
    }
  }

  val versionFlag = "+$versionString"

  val commandWithVersion = "${rustc.normalizedCommand} $versionFlag"

  companion object {

    const val VERSION_NAME_NIGHTLY = "nightly"

    fun parse(compilerCmd: String): RustcVersion {
      val trimmedCmd = compilerCmd.trim()
      check(trimmedCmd.matches(Regex("\\w+\\s+\\+\\S+"))) {
        "The compiler cmd should follow: " +
          "/path/to/rustc +<rustc version string>, e.g., rustc +nightly. " +
          "The real one is $trimmedCmd"
      }
      val elements = compilerCmd.split(Regex("\\s+"))
      check(elements.size == 2) {
        "The format should be '<rustc> +<version string>'"
      }
      val compiler = elements[0].trim()
      val versionFlag = elements[1].trim()
      check(versionFlag[0] == '+')

      val rustc = ShellCommandOnPath(compiler)
      val versionString = versionFlag.substring(1)
      val cmd = "${rustc.normalizedCommand} $versionFlag --version --verbose"
      val cmdOutput = Shells.singleton.run(
        cmd,
        captureOutput = true,
        environment = Shells.CURRENT_ENV,
      )
      check(cmdOutput.exitCode.isZero()) {
        "Fail to run cmd '$cmd'. $cmdOutput"
      }
      check(
        cmdOutput.stderr.anyLineContains(versionString) ||
          cmdOutput.stdout.anyLineContains(versionString),
      )
      return RustcVersion(rustc, versionString)
    }

    val VERSION_STRINGS = ImmutableList.of(VERSION_NAME_NIGHTLY) + LanguageRust.stableVersionStrings

    val VERSIONS = VERSION_STRINGS.asSequence().map {
      RustcVersion(ShellCommandOnPath("rustc"), it)
    }.toImmutableList()

    fun getFirstStable(): RustcVersion = getAllStables().first()

    fun getAllStables() = VERSIONS
      .filter { it.versionString != VERSION_NAME_NIGHTLY }
  }
}

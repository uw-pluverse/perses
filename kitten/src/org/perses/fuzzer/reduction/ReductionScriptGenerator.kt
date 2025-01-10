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
package org.perses.fuzzer.reduction

import com.google.common.escape.Escapers
import org.perses.fuzzer.compilers.ICompilerCrashDetector

class ReductionScriptGenerator(
  val cmd: String,
  val crashSignature: ICompilerCrashDetector.AbstractResult.CrashResult,
) {

  private var builder: StringBuilder? = StringBuilder()

  fun generate(): String {
    check(builder != null) {
      "This generator can only be used once."
    }
    builder!!.append(
      """#!/usr/bin/env bash
      |set -o nounset
      |set -o pipefail
      |set -o xtrace
      |
      |readonly OUTPUT="temp_compilation_output.tmp.txt"
      |readonly CRASH_EXIT_CODE=${crashSignature.exitCode}
      |
      |$cmd &> "${"$"}{OUTPUT}"
      |
      |[[ "${"$"}?" == "${"$"}{CRASH_EXIT_CODE}" ]] || exit 1
      |
      """.trimMargin(),
    )

    for (signature in crashSignature.signature.elements) {
      builder!!.append(
        """
        |
        |if ! grep --quiet --fixed-strings "${escapeString(signature)}" "${"$"}{OUTPUT}" ; then
        |  exit 1
        |fi
        |
        """.trimMargin(),
      )
    }

    builder!!.append("exit 0")

    return builder.toString().also {
      builder = null
    }
  }

  companion object {

    private val escaper = Escapers.builder()
      .addEscape('\n', "\\n")
      .addEscape('\r', "\\r")
      .addEscape('"', "\\\"")
      .addEscape('`', "\\`")
      .addEscape('$', "\\$")
      .build()

    fun escapeString(string: String) = escaper.escape(string)
  }
}

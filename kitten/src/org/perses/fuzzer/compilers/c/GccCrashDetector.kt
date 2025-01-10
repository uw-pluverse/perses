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
package org.perses.fuzzer.compilers.c

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector

class GccCrashDetector : AbstractCompilerCrashDetector() {

  override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val lines = stderr
      .asSequence()
      .map { it.trimEnd() }
      .filter { it.isNotBlank() }
      .filter {
        isSegfault(it) || isICE(it) || isStacktrace(it) || isCompareDebugFailure(it)
      }
      .map { it.trim() }
      .map {
        when {
          isICE(it) -> {
            val iceIndex = it.indexOf(KW_ICE)
            check(iceIndex > 0)

            val startIndex = iceIndex

            val colonLastIndex = it.lastIndexOf(':')
            check(colonLastIndex > 0)
            val endIndex = if (isInt(it.substring(colonLastIndex + 1))) {
              colonLastIndex
            } else {
              it.length
            }
            CrashMessageLine(it.substring(startIndex, endIndex))
          }
          isStacktrace(it) -> {
            val indexFirstSpace = it.indexOf(' ')
            check(indexFirstSpace > 0)
            StackTraceLine(it.substring(indexFirstSpace + 1).trim())
          }
          isSegfault(it) -> {
            val firstSpaceIndex = it.indexOf(' ')
            check(firstSpaceIndex > 0)
            CrashMessageLine(it.substring(firstSpaceIndex + 1).trim())
          }
          isCompareDebugFailure(it) -> {
            CrashMessageLine(KW_COMPARE_DEBUG)
          }
          else -> {
            CrashMessageLine(it)
          }
        }
      }.toList()
    return limitStackTraceLines(lines, limit = 3).map { it.value.trim() }.toList()
  }

  companion object {
    const val KW_SEGFAULT = "Segmentation fault"
    const val KW_ICE = "internal compiler error"

    fun isInt(string: String) = string.toIntOrNull() != null

    fun isStacktrace(string: String) =
      string.matches(Regex("^0x[a-fA-F0-9]+ [a-zA-Z0-9_:.->]+(\\(.*\\))?"))

    fun isSegfault(string: String) =
      string.contains(KW_SEGFAULT) && !isICE(string)

    fun isICE(string: String) =
      string.contains(KW_ICE)

    private val KW_COMPARE_DEBUG_FAILURE = "failure"

    private val KW_COMPARE_DEBUG = "-fcompare-debug"

    fun isCompareDebugFailure(string: String) =
      string.contains(KW_COMPARE_DEBUG) && string.contains(KW_COMPARE_DEBUG_FAILURE)
  }
}

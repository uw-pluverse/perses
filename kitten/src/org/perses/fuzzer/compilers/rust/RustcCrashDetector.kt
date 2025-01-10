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

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector

class RustcCrashDetector : AbstractCompilerCrashDetector() {

  override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val nonBlankLines = stderr.filter { it.isNotBlank() }
    val rawSignatures = ArrayList<String>()
    val length = nonBlankLines.size

    var i = 0
    while (i < length) {
      val line = nonBlankLines[i].trimEnd()
      when {
        line.contains("the compiler unexpectedly panicked. this is a bug") ||
          line.contains("Segmentation fault") -> {
          rawSignatures.add(line)
        }
        line.contains(KEYWORD_SEGMENTATION_FAULT) -> {
          rawSignatures.add(KEYWORD_SEGMENTATION_FAULT)
        }
        line.contains(KEYWORD_FATAL_RUNTIME_ERROR) -> {
          rawSignatures.add(line)
        }
        line.contains(KEYWORD_INTERNAL_COMPILER_ERROR) -> {
          val startIndex = line.indexOf(KEYWORD_INTERNAL_COMPILER_ERROR).also { check(it >= 0) } +
            KEYWORD_INTERNAL_COMPILER_ERROR.length
          val nextColon = line.indexOf(':', startIndex)
          if (nextColon < 0) {
            rawSignatures.add(line)
          } else {
            rawSignatures.add(line.substring(0, nextColon))
          }
        }
        LEFT_RIGHT_ASSERTION_FAILURE_PATTERN.matches(line) -> {
          rawSignatures.add(line)
          if (i + 2 < length &&
            nonBlankLines[i + 1].contains("left:") &&
            nonBlankLines[i + 2].contains("right:")
          ) {
            extractSignatureFromLeftOrRight(nonBlankLines[++i], rawSignatures)
            extractSignatureFromLeftOrRight(nonBlankLines[++i], rawSignatures)
          }
        }
        line.matches(GENERAL_PANIC_PATTERN) -> {
          val indexOf = line.indexOf(',')
          if (indexOf < 0) {
            rawSignatures.add(line)
          } else {
            rawSignatures.add(line.substring(0, indexOf))
          }
        }
      }
      ++i
    }
    return rawSignatures
  }

  private fun extractSignatureFromLeftOrRight(
    line: String,
    signatureBuilder: ArrayList<String>,
  ) {
    val commaIndex = line.indexOf(',')
    if (commaIndex >= 0) {
      signatureBuilder.add(line.substring(0, commaIndex))
    } else {
      signatureBuilder.add(line)
    }
  }

  companion object {
    const val KEYWORD_INTERNAL_COMPILER_ERROR = "internal compiler error:"
    const val KEYWORD_SEGMENTATION_FAULT = "Segmentation fault"
    const val KEYWORD_FATAL_RUNTIME_ERROR = "fatal runtime error:"
    val LEFT_RIGHT_ASSERTION_FAILURE_PATTERN =
      Regex(".*panicked at.*left.*==.*right.*")

    val GENERAL_PANIC_PATTERN =
      Regex("^thread.*\\W+panicked(\\W+.*)?${'$'}")
  }
}

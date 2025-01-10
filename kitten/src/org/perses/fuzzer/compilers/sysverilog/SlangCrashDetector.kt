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
package org.perses.fuzzer.compilers.sysverilog

import com.google.common.collect.ImmutableList
import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class SlangCrashDetector : AbstractCompilerCrashDetector() {

  // TODO: to be refined.
  override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val builder = ImmutableList.builder<String>()
    val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
    builder.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
    stderr.asSequence()
      .map { it.trim() }
      .filter { it.isNotBlank() }
      .forEach { origLine ->
        val lowercase = origLine.lowercase()
        when {
          lowercase.contains("internal compiler error") ||
            lowercase.contains("segmentation fault") ||
            origLine.contains("Dynamic exception type") ||
            origLine.contains("std::exception") -> {
            builder.add(origLine)
          }
          isLineLocation(origLine) -> {
            val matchResult = REGEXP_FILE.find(origLine) ?: return@forEach
            val fileNames = matchResult.groupValues
            if (fileNames.size == 2) {
              builder.add(fileNames.last())
            }
          }
          isFunctionLine(origLine) -> builder.add(origLine)
        }
      }
    return builder.build()
  }

  companion object {
    const val KEYWORD_INTERNAL_COMPILER_ERROR = "internal compiler error"
    const val KEYWORD_SEGMENTATION_FAULT = "Segmentation fault"

    val REGEXP_FILE = Regex("in file \\S+/([^/]+),\\s+line\\s+\\d+${"$"}")
    fun isLineLocation(line: String): Boolean {
      return line.matches(REGEXP_FILE)
    }

    private val FUNCTION_LINE = Regex("^function: .+\\([^()]*\\)[^()]*$")
    fun isFunctionLine(line: String) = line.matches(FUNCTION_LINE)
  }
}

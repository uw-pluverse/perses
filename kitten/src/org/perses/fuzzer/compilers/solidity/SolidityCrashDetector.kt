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
package org.perses.fuzzer.compilers.solidity

import com.google.common.collect.ImmutableList
import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class SolidityCrashDetector : AbstractCompilerCrashDetector() {

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
            origLine.contains("std::exception") ||
            origLine.contains("solidity::util::tag_comment") -> {
            builder.add(origLine)
          }
          isExceptionThrowLine(origLine) -> {
            val colonIndex = origLine.indexOf(':')
            if (colonIndex < 0) {
              return@forEach
            }
            check(colonIndex > 0)
            val filePath = origLine.substring(0, colonIndex).trim()
            val indexLeftParen = filePath.indexOf('(')
            val indexRightParen = filePath.indexOf(')')
            if (indexLeftParen in 1 until indexRightParen) {
              val path = filePath.substring(0, indexLeftParen).trim()
              builder.add(path)
            }
            val exceptionMessage = origLine.substring(colonIndex + 1).trim()
            builder.add(exceptionMessage)
          }
        }
      }
    return builder.build()
  }

  companion object {
    const val KEYWORD_INTERNAL_COMPILER_ERROR = "internal compiler error"
    const val KEYWORD_SEGMENTATION_FAULT = "Segmentation fault"

    val REGEXP_FILE = Regex("^(\\S+)\\/([^\\/]+)\\.\\S+")
    fun isFilePath(line: String): Boolean {
      return line.matches(REGEXP_FILE)
    }

    fun isExceptionThrowLine(line: String): Boolean {
      return line.contains(REGEXP_FILE) && line.lowercase().contains(Regex("\\sthrow\\s"))
    }
  }
}

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

class ClangCrashDetector : AbstractCompilerCrashDetector() {

  override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val result = ArrayList<AbstractSignatureElement>()
    for (element in stderr) {
      val line = element.trim()
      if (line.isBlank()) {
        continue
      }
      if (line.startsWith("PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT") ||
        line.lowercase().contains("segmentation fault") ||
        line.startsWith("fatal error: error in backend:")
      ) {
        result.add(CrashMessageLine(line.trim()))
        continue
      }
      val bugSignaturePrefix = "PLEASE submit a bug report to"
      if (line.startsWith(bugSignaturePrefix)) {
        result.add(CrashMessageLine(bugSignaturePrefix))
        continue
      }
      val matchResult = STACK_TRACE_PATTERN.matchEntire(line.trim())
      if (matchResult != null && matchResult.groupValues.size > 1) {
        result.add(StackTraceLine(matchResult.groupValues[1]))
        continue
      }
      val unreachablePrefix = "UNREACHABLE executed at"
      if (line.startsWith(unreachablePrefix)) {
        result.add(CrashMessageLine(unreachablePrefix))
        val indexLlvmProject = line.lastIndexOf("llvm-project")
        val indexColon = line.lastIndexOf(":")
        if (indexLlvmProject > 0 && indexColon > 0 && indexLlvmProject < indexColon) {
          result.add(CrashMessageLine(line.substring(indexLlvmProject, indexColon)))
        }
        continue
      }
    }
    return limitStackTraceLines(result, limit = 3).map { it.value.trim() }.toList()
  }

  companion object {
    val STACK_TRACE_PATTERN = Regex("\\S*clang\\S+:\\s*\\S+llvm-project\\S+:\\d+:(.+)")
  }
}

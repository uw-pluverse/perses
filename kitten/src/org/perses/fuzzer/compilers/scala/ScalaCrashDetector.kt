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
package org.perses.fuzzer.compilers.scala

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector

class ScalaCrashDetector : AbstractCompilerCrashDetector() {

  override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val containsStackOverflowError = stderr.any {
      it.contains("StackOverflowError")
    }
    val lines = stderr
      .asSequence()
      .filter { it.isNotBlank() }
      .map { it.trim() }
      .filter {
        isException(it) ||
          isError(it) ||
          (isStacktraceLine(it) && !containsStackOverflowError)
        // The stacktrace of StackOverflowError is unstable. Discard the stacktrace.
      }
      .flatMap {
        if (isError(it) || isException(it)) {
          splitOnSystemHashCode(it)
        } else if (isStacktraceLine(it) && it.last() == ')') {
          // Remove line numbers.
          val left = it.lastIndexOf('(')
          val result = if (left > 0) {
            it.substring(0, left)
          } else {
            it
          }
          sequenceOf(result)
        } else {
          sequenceOf(it)
        }
      }
      .toList()

    var i = 0
    val size = lines.size
    val result = ArrayList<String>()
    while (i < size) {
      val line = lines[i++]
      result.add(line)
      if (!isStacktraceLine(line)) {
        continue
      }

      var counter = STACKTRACE_CONTEXT_SIZE
      while (i < size && isStacktraceLine(lines[i])) {
        if (--counter > 0) {
          result.add(lines[i])
        }
        ++i
      }
    }
    return result
  }

  companion object {

    const val STACKTRACE_CONTEXT_SIZE = 3

    fun splitOnSystemHashCode(string: String): Sequence<String> {
      return string.split(Regex("@[a-fA-F0-9]+"))
        .asSequence()
        .filter { it.isNotBlank() }
    }

    fun isStacktraceLine(line: String): Boolean {
      return line.startsWith("at ")
    }

    fun isException(line: String): Boolean {
      return isErrorOrException(line, "Exception")
    }

    fun isError(line: String): Boolean {
      return isErrorOrException(line, "Error")
    }

    private fun isErrorOrException(line: String, type: String): Boolean {
      return line.contains(Regex("(\\w+\\.)+([A-Z]\\w*)?$type[^a-zA-Z0-9_]")) ||
        line.contains(Regex("(\\w+\\.)+([A-Z]\\w*)?$type$"))
    }
  }
}

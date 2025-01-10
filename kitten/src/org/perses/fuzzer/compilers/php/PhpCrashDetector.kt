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
package org.perses.fuzzer.compilers.php

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class PhpCrashDetector : AbstractCompilerCrashDetector() {

  override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val result = ArrayList<String>()
    val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
    stderr.asSequence()
      .filter {
        it.isNotBlank() && it.contains(KEYWORD_BUG)
      }
      .forEach {
        result.add(it)
      }
    result.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
    return result.asSequence().filter { it.isNotBlank() }.map {
      it.trim()
      it.substring(
        it.indexOf("PHP"),
      )
    }.toList()
  }

  companion object {
    const val KEYWORD_BUG = "PHP Fatal error"
  }
}

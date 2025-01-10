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
package org.perses.fuzzer.compilers

class SanitizerCrashSignatureExtractor {

  fun extractCrashSignatureFromStderr(stderr: List<String>): List<String> {
    val result = ArrayList<String>()
    stderr.asSequence()
      .filter {
        it.isNotBlank() && (
          it.contains(KEYWORD_UBSAN_OUTPUT) || it.contains(
            KEYWORD_ASAN_OUTPUT,
          )
          )
      }
      .forEach {
        when {
          it.contains(KEYWORD_UBSAN_OUTPUT) -> {
            val matchResult = UBSAN_PATTERN.matchEntire(it.trim())
            if (matchResult != null && matchResult.groupValues.size > 2) {
              val pathMessage = matchResult.groupValues[1]
              result.addAll(pathMessage.split(TEMP_PATH))
              val ubMessage = matchResult.groupValues[2]
              result.addAll(ubMessage.split(NUMBER_REGEX))
            }
          }
          it.contains(ASAN_ERROR) -> {
            val matchResult = ASAN_ERROR_PATTERN.matchEntire(it.trim())
            if (matchResult != null && matchResult.groupValues.size > 1) {
              result.add(matchResult.groupValues[1].split(HEX_REGEX)[0])
            }
          }
          it.contains(ASAN_SUMMARY) -> {
            val summary = it.split(LINE_NUMBER)
            for (item in summary) {
              result.addAll(item.split(TEMP_PATH))
            }
          }
          else -> {
            result.add(it)
          }
        }
      }
    return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
  }

  companion object {
    const val KEYWORD_ASAN_OUTPUT = "AddressSanitizer"
    const val ASAN_ERROR = "ERROR: AddressSanitizer:"
    const val ASAN_SUMMARY = "SUMMARY: AddressSanitizer:"
    const val KEYWORD_UBSAN_OUTPUT = "runtime error:"
    val NUMBER_REGEX = Regex("[\\d]+")
    val HEX_REGEX = Regex("0[xX][0-9a-fA-F]+")
    val TEMP_PATH = Regex("/tmp/tmp.*?/")
    val LINE_NUMBER = Regex(":[\\d]+")
    val UBSAN_PATTERN = Regex("([^\\s]+):[\\d]+:[\\d]+: (.+)")
    val ASAN_ERROR_PATTERN =
      Regex("[^\\s]*(ERROR: AddressSanitizer:.+)")
  }
}

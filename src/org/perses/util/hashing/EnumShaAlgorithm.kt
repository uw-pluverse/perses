/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.util.hashing

import com.google.common.hash.HashFunction
import com.google.common.hash.Hashing
import com.google.common.primitives.ImmutableIntArray
import java.nio.charset.StandardCharsets

// TODO(cnsun): need tests.
enum class EnumShaAlgorithm(
  val function: HashFunction,
) {
  SHA512(Hashing.sha512()),
  SHA256(Hashing.sha256()), ;

  fun hashString(content: String) = function.hashString(content, StandardCharsets.UTF_8)

  fun hashListOfStrings(list: List<String>) =
    function.hashObject(
      list,
      ListToByteFunnel.StringListToByteFunnel,
    )

  fun hashBytes(bytes: ByteArray) = function.hashBytes(bytes)

  fun createFromString(string: String): ShaHashCode =
    ShaHashCode.ForSingleString(
      stringLength = string.length,
      digest = hashString(string),
    )

  fun createFromListOfStrings(strings: List<String>): ShaHashCode {
    require(strings.isNotEmpty()) { "The list of strings cannot be empty." }
    return when (strings.size) {
      0 -> {
        error("The list of strings cannot be empty.")
      }

      1 -> {
        createFromString(strings.single())
      }

      else -> {
        ShaHashCode.ForMultiStrings(
          stringLengths =
            ImmutableIntArray
              .builder(strings.size)
              .apply {
                strings.forEach { s -> add(s.length) }
              }.build(),
          digest = hashListOfStrings(list = strings),
        )
      }
    }
  }
}

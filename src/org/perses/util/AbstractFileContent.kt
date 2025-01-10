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
package org.perses.util

import com.google.common.hash.HashCode
import com.google.common.hash.Hashing
import com.google.common.hash.PrimitiveSink
import java.nio.file.Path
import kotlin.io.path.readBytes
import kotlin.io.path.writeBytes

open class AbstractFileContent(protected val bytes: ByteArray) {

  open val printableContentIfPossible: String by lazy {
    "SHA-512: $sha512"
  }

  fun writeToFile(filePath: Path) {
    filePath.writeBytes(bytes)
  }

  val length: Int
    get() = bytes.size

  val sha512: HashCode by lazy {
    Hashing.sha512().hashBytes(bytes)
  }

  fun hash(sink: PrimitiveSink) {
    sink.putBytes(bytes)
  }

  override fun toString(): String {
    return printableContentIfPossible
  }

  class TextFileContent(
    val text: String,
  ) : AbstractFileContent(bytes = text.toByteArray(Charsets.UTF_8)) {

    override val printableContentIfPossible: String
      get() = text
  }

  class BinaryFileContent private constructor(
    bytes: ByteArray,
  ) : AbstractFileContent(bytes) {

    val asTextFileContent by lazy {
      TextFileContent(String(bytes, Charsets.UTF_8))
    }

    companion object {
      fun fromFile(filePath: Path): BinaryFileContent {
        return BinaryFileContent(filePath.readBytes())
      }
    }
  }
}

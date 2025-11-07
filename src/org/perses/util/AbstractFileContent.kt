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
import com.google.common.hash.PrimitiveSink
import com.google.common.primitives.ImmutableIntArray
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.hashing.ListToByteFunnel
import org.perses.util.hashing.ShaHashCode
import java.io.InputStream
import java.nio.charset.StandardCharsets
import java.nio.file.Path
import kotlin.io.path.readBytes
import kotlin.io.path.writeBytes

sealed class AbstractFileContent(
  protected val bytes: ByteArray,
) {
  open val printableContentIfPossible: String by lazy {
    "SHA-512: <BINARY FILE>"
  }

  fun writeToFile(filePath: Path) {
    filePath.writeBytes(bytes)
  }

  abstract val asTextFileContent: TextFileContent

  val length: Int
    get() = bytes.size

  fun hashToPrimitiveSink(sink: PrimitiveSink) {
    sink.putBytes(bytes)
  }

  fun hashWithSha(sha: EnumShaAlgorithm): HashCode = sha.hashBytes(bytes)

  override fun toString(): String = printableContentIfPossible

  class TextFileContent(
    val text: String,
  ) : AbstractFileContent(bytes = text.toByteArray(StandardCharsets.UTF_8)) {
    override val printableContentIfPossible: String
      get() = text

    override val asTextFileContent: TextFileContent
      get() = this
  }

  class BinaryFileContent private constructor(
    bytes: ByteArray,
  ) : AbstractFileContent(bytes) {
    override val asTextFileContent by lazy {
      TextFileContent(String(bytes, StandardCharsets.UTF_8))
    }

    companion object {
      fun fromFile(filePath: Path): BinaryFileContent = BinaryFileContent(filePath.readBytes())

      fun fromInputStream(inputStream: InputStream): BinaryFileContent =
        BinaryFileContent(bytes = inputStream.readBytes())
    }
  }

  companion object {
    // TODO(cnsun): need tests.
    fun createFromListOfFileContents(
      shaHash: EnumShaAlgorithm,
      fileContents: List<AbstractFileContent>,
    ): ShaHashCode =
      when (fileContents.size) {
        0 -> error("The list cannot be empty.")
        1 -> {
          val fileContent = fileContents.single()
          ShaHashCode.ShaHashCodeForSingleString(
            stringLength = fileContent.length,
            digest = fileContent.hashWithSha(shaHash),
          )
        }

        else -> {
          ShaHashCode.ShaHashCodeForMultiStrings(
            stringLengths =
              ImmutableIntArray
                .builder(fileContents.size)
                .apply {
                  fileContents.forEach { fileContent -> add(fileContent.length) }
                }.build(),
            digest =
              shaHash.function.hashObject(
                fileContents,
                ListToByteFunnel { element, sink ->
                  element.hashToPrimitiveSink(sink)
                },
              ),
          )
        }
      }
  }
}

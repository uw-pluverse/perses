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
package org.perses.util

import com.google.common.collect.ImmutableMap
import java.io.ByteArrayOutputStream
import java.io.Closeable
import java.io.InputStream
import java.io.OutputStream
import java.io.PrintStream
import java.nio.charset.Charset
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardOpenOption
import java.util.zip.Deflater
import java.util.zip.DeflaterOutputStream
import java.util.zip.InflaterOutputStream
import java.util.zip.ZipFile
import kotlin.io.path.outputStream

object IoUtil {
  data class UseResourcesResultTuple<A, B, R>(
    val resourceA: A,
    val resourceB: B,
    val result: R,
  )

  /**
   * Note that the two resources are passed in as lambdas, because
   * we want to make sure that if the second resource is failed to create,
   * the first resource is still managed to be closed.
   *
   * If you pass in the two resources directly, if the creation of the second resource
   * fails, the first resource will need to be closed manually.
   */
  inline fun <A : Closeable, B : Closeable, R> useResources(
    creatorA: () -> A,
    creatorB: (A) -> B,
    block: (A, B) -> R,
  ): UseResourcesResultTuple<A, B, R> {
    creatorA().use { a ->
      creatorB(a).use { b ->
        return UseResourcesResultTuple(a, b, block(a, b))
      }
    }
  }

  inline fun <A : Closeable, B : Closeable, C : Closeable, R> useResources(
    creatorA: () -> A,
    creatorB: (A) -> B,
    creatorC: (A, B) -> C,
    block: (A, B, C) -> R,
  ): R {
    creatorA().use { a ->
      creatorB(a).use { b ->
        creatorC(a, b).use { c ->
          return block(a, b, c)
        }
      }
    }
  }

  object ExceptionOutputStream : OutputStream() {
    override fun write(p0: Int) {
      error("This output stream should not be used.")
    }
  }

  object ExceptionPrintStream : PrintStream(ExceptionOutputStream)

  fun createAppendablePrintStream(
    path: Path,
    autoFlush: Boolean = false,
    charset: Charset = StandardCharsets.UTF_8,
  ): PrintStream {
    val outputStream = path.outputStream(StandardOpenOption.CREATE, StandardOpenOption.APPEND)
    return PrintStream(outputStream, autoFlush, charset.name())
  }

  fun createNonAppendablePrintStream(
    path: Path,
    autoFlush: Boolean = false,
    charset: Charset = StandardCharsets.UTF_8,
  ): PrintStream = PrintStream(path.outputStream(), autoFlush, charset.name())

  // TODO(cnsun): needs tests.
  fun readZipFileContents(zipFilePath: Path): ImmutableMap<String, String> =
    ZipFile(zipFilePath.toFile()).use { zipFile ->
      zipFile
        .entries()
        .asSequence()
        .map { entry ->
          if (entry.isDirectory) {
            null
          } else {
            val content = zipFile.getInputStream(entry).use { it.readAllBytes().decodeToString() }
            entry.name to content
          }
        }.filterNotNull()
        .toImmutableMap()
    }

  @JvmStatic
  fun compressStringToZipByteArray(text: String): ByteArray {
    val bArray = text.toByteArray(StandardCharsets.UTF_8)
    val compressor = Deflater(Deflater.BEST_COMPRESSION)
    val output =
      ByteArrayOutputStream().use { output ->
        DeflaterOutputStream(output, compressor).use { dos ->
          dos.write(bArray)
          dos.finish()
        }
        output.toByteArray()
      }
    return output
  }

  @JvmStatic
  fun decompressZipByteArray(bArray: ByteArray): ByteArray =
    useResources(
      { ByteArrayOutputStream() },
      { bos -> InflaterOutputStream(bos) },
    ) { bos, ios ->
      ios.write(bArray)
      ios.finish()
      bos.toByteArray()
    }.result

  @JvmStatic
  fun openResourceAsStream(
    resourceName: String,
    klassUnderSamePkg: Class<*>,
  ): InputStream {
    val result = klassUnderSamePkg.getResourceAsStream(resourceName)
    return requireNotNull(result) {
      "Failed to open stream $resourceName with class ${klassUnderSamePkg.canonicalName}"
    }
  }

  @JvmStatic
  fun copyResource(
    resourceName: String,
    klassUnderSamePkg: Class<*>,
    destination: Path,
  ) {
    useResources(
      { openResourceAsStream(resourceName, klassUnderSamePkg) },
      { Files.newOutputStream(destination) },
    ) { resource, output ->
      resource.copyTo(output)
    }
  }
}

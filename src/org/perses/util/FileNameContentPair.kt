/*
 * Copyright (C) 2018-2024 University of Waterloo.
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

import com.google.common.collect.ImmutableList
import com.google.common.collect.Interner
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.readLines
import kotlin.io.path.writeText

// TODO(cnsun): replace the content with 'lines', to reduce memory footprint.
data class FileNameContentPair @PublishedApi internal constructor(
  val fileName: String,
  val lines: ImmutableList<String>,
) {

  fun writeToDirectory(dir: Path): Path {
    check(Files.isDirectory(dir))
    val path = dir.resolve(fileName)
    path.writeText(computeFileContent())
    return path
  }

  fun computeFileContent() = lines.joinToString(separator = "\n")

  fun createInternedCopy(interner: Interner<String>) = FileNameContentPair(
    fileName = interner.intern(fileName),
    lines = ImmutableList.builderWithExpectedSize<String>(lines.size).apply {
      lines.forEach { line -> add(interner.intern(line)) }
    }.build(),
  )

  companion object {

    fun locateFirstNonBlankLine(lines: List<String>): Int {
      var start = 0
      while (start < lines.size) {
        if (lines[start].isNotBlank()) {
          return start
        }
        ++start
      }
      return start
    }

    fun locateLastNonBlankLine(lines: List<String>): Int {
      var end = lines.size - 1
      while (end >= 0) {
        if (lines[end].isNotBlank()) {
          return end
        }
        --end
      }
      return end
    }

    @JvmStatic
    fun trimWhitespaces(lines: List<String>): ImmutableList<String> {
      val start = locateFirstNonBlankLine(lines)
      val end = locateLastNonBlankLine(lines)
      if (start == end) {
        return ImmutableList.of(lines[start].trim())
      }
      if (start > end) {
        return ImmutableList.of()
      }
      val result = ImmutableList.builder<String>()
      result.add(lines[start].trimStart())
      (start + 1 until end).forEach { result.add(lines[it]) }
      if (end >= 0) {
        result.add(lines[end].trimEnd())
      }
      return result.build()
    }

    @JvmStatic
    inline fun createFromFile(
      file: Path,
      fileContentProcessor: (List<String>) -> ImmutableList<String> = ::trimWhitespaces,
    ) = FileNameContentPair(
      fileName = file.fileName.toString(),
      lines = fileContentProcessor(file.readLines()),
    )

    @JvmStatic
    inline fun createFromString(
      fileName: String,
      content: String,
      fileContentProcessor: (List<String>) -> ImmutableList<String> = ::trimWhitespaces,
    ) = FileNameContentPair(
      fileName,
      lines = fileContentProcessor(content.lines()),
    )
  }
}

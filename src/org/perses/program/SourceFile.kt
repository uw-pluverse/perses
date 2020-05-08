/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.program

import com.google.common.base.MoreObjects
import com.google.common.io.MoreFiles
import java.io.File
import java.io.IOException
import java.nio.charset.StandardCharsets

/**
 * Abstraction for a source file. It encapsulates the details of a source file. Note that this class
 * loads the content of the passed-in file. So when you create an object of this class, the file
 * must already exist.
 */
class SourceFile(val file: File) {
  val fileContent: String
  val languageKind: LanguageKind

  val baseName: String
    get() = file.name

  val parentFile: File
    get() = file.parentFile

  @Throws(IOException::class)
  fun writeTo(path: File) =
    MoreFiles.asCharSink(path.toPath(), StandardCharsets.UTF_8).write(fileContent)


  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("file", file).add("lang", languageKind).toString()
  }

  init {
    require(file.isFile) {
      "The file should be a regular file $file"
    }
    languageKind = LanguageKind.computeLanguageKind(file)
    fileContent = MoreFiles.asCharSource(file.toPath(), StandardCharsets.UTF_8).read()
  }
}

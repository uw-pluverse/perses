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
package org.perses.program

import com.google.common.base.MoreObjects
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractReductionFile<K : AbstractDataKind, Self : AbstractReductionFile<K, Self>>(
  val dataKind: K,
  file: Path,
) {

  val fileWithContent = FileWithContent(file)

  val file by fileWithContent::file

  val baseName by fileWithContent::baseName

  val parentFile by fileWithContent::parentFile

  fun writeTo(path: Path) = fileWithContent.writeTo(path)

  fun writeToDirectory(directory: Path): Path {
    check(Files.isDirectory(directory))
    val path = directory.resolve(baseName)
    writeTo(path)
    return path
  }

  final override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("file", fileWithContent)
      .add("lang", dataKind)
      .toString()
  }
}

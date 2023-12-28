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

import java.io.Closeable
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.createDirectory
import kotlin.io.path.exists
import kotlin.io.path.isDirectory

class AutoDeletableFolder(val file: Path) : Closeable {

  private var open = true

  override fun close() {
    if (open) {
      file.toFile().deleteRecursively()
      open = false
    }
  }

  init {
    if (!file.exists()) {
      file.createDirectory()
      check(file.exists()) {
        "fail to create folder $file"
      }
    }
    check(file.isDirectory())
    check(open)
  }

  companion object {

    fun createTempDir(prefix: String) =
      AutoDeletableFolder(Files.createTempDirectory(prefix))

    fun createTempDirWithClassNameAsPrefix(any: Any) =
      createTempDir(prefix = any::class.java.name)
  }
}

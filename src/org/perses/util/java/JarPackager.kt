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
package org.perses.util.java

import java.nio.file.Files
import java.nio.file.Path
import java.util.zip.ZipEntry
import java.util.zip.ZipOutputStream

class JarPackager(
  val dir: Path,
  val packageName: String,
  val fileAcceptor: (fileName: String) -> Boolean,
  val customizer: (ZipOutputStream) -> Unit,
) {

  fun createJarFile(destination: Path) {
    val packageDir = packageName.replace('.', '/')
    ZipOutputStream(Files.newOutputStream(destination)).use { zipStream ->
      Files
        .newDirectoryStream(dir) { Files.isRegularFile(it) && fileAcceptor(it.toString()) }
        .use { stream ->
          stream
            .asSequence()
            .sorted()
            .forEach { file ->
              val zipEntry = ZipEntry("$packageDir/${file.fileName}")
              zipStream.putNextEntry(zipEntry)
              zipStream.write(Files.readAllBytes(file))
              zipStream.closeEntry()
            }
        }
      customizer(zipStream)
    }
  }
}

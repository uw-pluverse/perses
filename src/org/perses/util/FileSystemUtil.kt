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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import java.io.IOException
import java.nio.file.CopyOption
import java.nio.file.FileVisitResult
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import java.nio.file.SimpleFileVisitor
import java.nio.file.StandardCopyOption
import java.nio.file.attribute.BasicFileAttributes
import java.nio.file.attribute.PosixFilePermission
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteIfExists
import kotlin.io.path.deleteRecursively
import kotlin.io.path.isDirectory
import kotlin.io.path.writeText

object FileSystemUtil {
  @JvmStatic
  fun isEmptyDirectory(path: Path): Boolean {
    Files.newDirectoryStream(path).use { stream -> return !stream.iterator().hasNext() }
  }

  @JvmStatic
  fun ensureDirExists(dir: Path): Path {
    if (!Files.isDirectory(dir)) {
      /*
       * Multiple instances of Perses might be creating the same folder at the same time.
       * Despite data races, better to only check the folder is created successfully.
       * In case of a file with same name, a `java.nio.file.FileAlreadyExistsException` will be
       * caught and ignored, because the following check raises `IllegalStateException`.
       */
      try {
        Files.createDirectories(dir)
      } catch (e: IOException) {
        // Ignore the exception intentionally.
      }
      check(Files.isDirectory(dir)) { "Failed to create a directory named $dir" }
    }
    return dir
  }

  @JvmStatic
  fun setExecutable(path: Path) {
    val permissions = Files.getPosixFilePermissions(path)
    permissions.add(PosixFilePermission.OWNER_EXECUTE)
    Files.setPosixFilePermissions(path, permissions)
  }

  @JvmStatic
  fun createDirsAndWriteText(
    file: Path,
    text: String,
  ): Path {
    var parent = file.parent
    if (parent == null) {
      parent = file.toAbsolutePath().parent
    }
    check(parent != null) { "Cannot find the parent dir of $file" }
    if (!Files.exists(parent)) {
      Files.createDirectories(parent)
    }
    file.writeText(text)
    return file
  }

  @JvmStatic
  fun replaceFileExtension(
    path: String,
    newExt: String,
  ): String {
    require(newExt.isNotBlank())
    require(newExt.trim().length == newExt.length)
    require(newExt[0] != '.')

    newExt.forEach {
      check(it.isLetterOrDigit())
    }
    val dotIndex = path.lastIndexOf('.')
    check(dotIndex > 0)
    return path.substring(0, dotIndex + 1) + newExt
  }

  // TODO: test
  @OptIn(ExperimentalPathApi::class)
  @JvmStatic
  fun clearDirectory(directory: Path) {
    require(Files.isDirectory(directory))
    directory.deleteRecursively()
    Files.createDirectory(directory)
  }

  @OptIn(ExperimentalPathApi::class)
  @JvmStatic
  fun deleteRecursively(path: Path) {
    path.deleteRecursively()
  }

  // TODO: test
  @JvmStatic
  fun copyDirectory(
    source: Path,
    target: Path,
    vararg options: CopyOption,
  ) {
    require(Files.isDirectory(source))
    if (!Files.exists(target)) {
      Files.createDirectories(target)
    }
    check(Files.isDirectory(target))
    Files.walkFileTree(
      source,
      object : SimpleFileVisitor<Path>() {
        override fun preVisitDirectory(
          dir: Path,
          attrs: BasicFileAttributes,
        ): FileVisitResult {
          Files.createDirectories(target.resolve(source.relativize(dir)))
          return FileVisitResult.CONTINUE
        }

        override fun visitFile(
          file: Path,
          attrs: BasicFileAttributes,
        ): FileVisitResult {
          Files.copy(file, target.resolve(source.relativize(file)), *options)
          return FileVisitResult.CONTINUE
        }
      },
    )
  }

  @JvmStatic
  fun copyFileToDirectory(
    srcFilePath: Path,
    destDir: Path,
  ): Path {
    val destFilePath = destDir.resolve(srcFilePath.fileName)
    require(!srcFilePath.toAbsolutePath().equals(destFilePath.toAbsolutePath())) {
      "Destination path cannot be the same as the original path."
    }
    Files.copy(srcFilePath, destFilePath, StandardCopyOption.REPLACE_EXISTING)
    return destFilePath
  }

  @JvmStatic
  fun listFilesInFolder(folder: Path): ImmutableSet<Path> {
    val filesList = ImmutableSet.builder<Path>()

    Files.newDirectoryStream(folder).use { stream ->
      for (path in stream) {
        filesList.add(path)
      }
    }

    return filesList.build()
  }

  @OptIn(ExperimentalPathApi::class)
  @JvmStatic
  fun deleteFilesConditionally(
    dir: Path,
    deletePredicate: (Path) -> Boolean,
  ) {
    Files.newDirectoryStream(dir).use { stream ->
      for (path in stream) {
        if (deletePredicate(path)) {
          if (path.isDirectory()) {
            path.deleteRecursively()
          } else {
            path.deleteIfExists()
          }
        }
      }
    }
  }

  @JvmStatic
  fun globWithRegex(
    dir: Path,
    pattern: Regex,
  ): ImmutableList<Path> =
    globWithFilter(dir) {
      pattern.matches(it.fileName.toString())
    }

  @JvmStatic
  fun globWithFileNameExts(
    dir: Path,
    ext: String,
  ): ImmutableList<Path> {
    require(ext.trim().length == ext.length)
    require(ext.isNotBlank())
    return globWithFilter(dir) {
      it.fileName.toString().endsWith(ext)
    }
  }

  /**
   * Recursively lists the regular files under [dir] that satisfy [regularFileFilter]. The result is
   * sorted by normalized absolute path so the order is deterministic across runs and platforms
   * (`Files.walk` itself makes no ordering guarantee). Pass `{ true }` to list every regular file.
   */
  @JvmStatic
  fun globWithFilter(
    dir: Path,
    regularFileFilter: (Path) -> Boolean,
  ): ImmutableList<Path> {
    val matches =
      Files
        .walk(dir)
        .use { stream ->
          stream
            .filter { file ->
              Files.isRegularFile(file) && regularFileFilter(file)
            }.collect(ImmutableList.toImmutableList())
        }
    // Sort by normalized absolute path, computing each key once (decorate-sort-undecorate);
    // sorting with a comparator would re-run the key selector on every comparison.
    return matches
      .map { it.toAbsolutePath().normalize().toString() to it }
      .sortedBy { it.first }
      .map { it.second }
      .let { ImmutableList.copyOf(it) }
  }

  @JvmStatic
  fun getUserHomeDirectory(): Path {
    val userHomeSystemPropertyName = "user.home"
    val home = System.getProperty(userHomeSystemPropertyName)
    check(home != null) {
      "The system property $userHomeSystemPropertyName is null."
    }
    val directory = Paths.get(home)
    check(Files.isDirectory(directory)) {
      "The home folder $directory is not a directory."
    }
    return directory
  }

  @JvmStatic
  fun getSystemTemporaryDirectory(): Path {
    val key = "java.io.tmpdir"
    val tempDir = System.getProperty(key)
    check(tempDir != null) {
      "The temporary directory $tempDir is null."
    }
    return Paths.get(tempDir)
  }

  fun createTempDirForObject(ownerObject: Any): Path =
    Files.createTempDirectory(ownerObject::class.java.canonicalName)
}

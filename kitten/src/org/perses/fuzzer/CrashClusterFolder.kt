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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import org.perses.fuzzer.compilers.ICompilerCrashDetector
import java.io.File
import java.nio.file.Files
import java.util.Arrays

class CrashClusterFolder(val folder: File) {

  fun getCrashInstances(): ImmutableList<CrashInstanceFolder> {
    val builder = ImmutableList.builder<CrashInstanceFolder>()
    val children = folder.listFiles()
    Arrays.sort(children)
    val crashSignatures = HashSet<ICompilerCrashDetector.CrashSignature>()
    for (subFolder in children) {
      check(subFolder.isDirectory)
      val crashInstanceFolder = CrashInstanceFolder(subFolder)
      crashSignatures.add(crashInstanceFolder.readCrashSignature())
      builder.add(crashInstanceFolder)
    }
    return builder.build()
  }

  fun reduceAll() = getCrashInstances().forEach { it.reduce() }

  fun isEmpty() = getCrashInstances().isEmpty()

  init {
    require(getCrashInstances().size > 0)
  }

  val crashSignature = getCrashInstances()[0].readCrashSignature()

  fun moveCrashInstanceToThisCluster(newCrash: CrashInstanceFolder) {
    require(newCrash.readCrashSignature() == crashSignature)
    require(!containsCrashInstance(newCrash))
    Files.move(
      newCrash.folder.toPath(),
      File(folder, newCrash.folder.name).toPath(),
    )
  }

  fun containsCrashInstance(crash: CrashInstanceFolder) =
    getCrashInstances()
      .asSequence()
      .map { it.folder.name }
      .contains(crash.folder.name)

  fun delete() {
    check(folder.delete()) {
      "fail to delete folder $folder"
    }
  }

  companion object {
    fun createByMovingCrashInstance(
      folder: File,
      crashInstanceFolder: CrashInstanceFolder,
    ): CrashClusterFolder {
      if (!folder.exists()) {
        check(folder.mkdirs())
      }
      check(folder.isDirectory)
      Files.move(
        crashInstanceFolder.folder.toPath(),
        File(folder, crashInstanceFolder.folder.name).toPath(),
      )
      return CrashClusterFolder(folder)
    }
  }
}

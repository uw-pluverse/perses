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
import java.io.File

abstract class AbstractFlatCrashFolder(val root: File) {

  init {
    if (!root.exists()) {
      check(root.mkdir())
    }
    check(root.isDirectory)
  }

  fun getChildren(): ImmutableList<File> {
    val children = root.listFiles()
    if (children == null || children.isEmpty()) {
      return ImmutableList.of()
    }
    return ImmutableList.sortedCopyOf(children.asIterable())
  }

  fun getInstanceWithLargestMutantFile(): CrashInstanceFolder? {
    return getAllCrashInstances().maxByOrNull { it.getMutantFile().length() }
  }

  fun getInstanceWithSmallestMutantFile(): CrashInstanceFolder? {
    return getAllCrashInstances().minByOrNull { it.getMutantFile().length() }
  }

  fun getAllCrashInstances(): ImmutableList<CrashInstanceFolder> {
    val builder = ImmutableList.builder<CrashInstanceFolder>()
    for (folder in getChildren()) {
      if (CrashInstanceFolder.isCrashInstanceFolder(folder)) {
        builder.add(CrashInstanceFolder(folder))
      }
    }
    return builder.build()
  }

  fun isEmpty() = getChildren().isEmpty()

  fun isNotEmpty() = !isEmpty()

  fun getReportedCrashInstances(): ImmutableList<CrashInstanceFolder> =
    getAllCrashInstances()
      .asSequence()
      .filter { it.isReported() }
      .fold(
        ImmutableList.builder<CrashInstanceFolder>(),
        { builder, crash -> builder.add(crash) },
      )
      .build()
}

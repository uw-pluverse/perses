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
import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.compilers.ICompilerCrashDetector.CrashSignature
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.util.ktInfo
import java.io.File

/**
 * TODO:
 *     1. delete folders that are already copied to processing-folder from finding-folder
 *     2. generate bug reports
 *     3. handle duplicate
 */
@Deprecated("not being used any more")
class ProcessingFolder(val folder: File) {

  init {
    if (!folder.exists()) {
      folder.mkdirs()
    }
    check(folder.isDirectory)
  }

  fun moveNewCrashInstanceToThisFolder(newInstance: CrashInstanceFolder) {
    val signature = newInstance.readCrashSignature()
    val cluster = locateCrashClusterWithSignature(signature)
    if (cluster != null) {
      if (cluster.containsCrashInstance(newInstance)) {
        logger.ktInfo {
          "The crash ${newInstance.folder} has already been moved to the processing folder. " +
            "Deleting it."
        }
        newInstance.delete()
      } else {
        logger.ktInfo {
          "Moving ${newInstance.folder} to the processing folder"
        }
        cluster.moveCrashInstanceToThisCluster(newInstance)
      }
    } else {
      createClusterForCrashInstanceAndUpdateIndex(newInstance)
    }
  }

  private fun locateCrashClusterWithSignature(crashSignature: CrashSignature): CrashClusterFolder? {
    val filter = getAllClustersAndDeleteEmptyOnes().filter {
      it.crashSignature == crashSignature
    }
    return if (filter.isEmpty()) {
      null
    } else if (filter.size == 1) {
      filter[0]
    } else {
      throw RuntimeException("Multiple crash cluster folds are found. $filter")
    }
  }

  fun getAllClustersAndDeleteEmptyOnes(): ImmutableList<CrashClusterFolder> {
    val builder = ImmutableList.builder<CrashClusterFolder>()
    val visitedSignatures = HashSet<CrashSignature>()
    for (
    clusterFolder in folder.listFiles { file ->
      file.name.matches(Regex("$CLUSTER_FOLDER_PREFIX\\d+"))
    }
    ) {
      val children = clusterFolder.listFiles()
      if (children == null || children.isEmpty()) {
        clusterFolder.delete()
        continue
      }
      val cluster = CrashClusterFolder(clusterFolder)
      check(visitedSignatures.add(cluster.crashSignature)) {
        "Duplicate signature: ${cluster.crashSignature}"
      }
      builder.add(cluster)
    }
    return builder.build()
  }

  fun getAllCrashInstances(): ImmutableList<CrashInstanceFolder> {
    return getAllClustersAndDeleteEmptyOnes().flatMap {
      it.getCrashInstances()
    }.fold(
      ImmutableList.builder<CrashInstanceFolder>(),
      { builder, crash -> builder.add(crash) },
    ).build()
  }

  fun reduceAll() = getAllCrashInstances().forEach { it.reduce() }

  private fun removeNonCrashes() {
    val crashDetector = RustcCrashDetector()
    getAllCrashInstances().forEach {
      if (!crashDetector.detectCrash(it.readCrashSignature().elements).isCrashDetected()) {
        logger.ktInfo { "The crash instance is not a crash: ${it.folder}" }
        it.delete()
      }
    }
  }

  fun cleanup() {
    removeNonCrashes()
    removeEmptyClusters()
  }

  private fun removeEmptyClusters() {
    getAllClustersAndDeleteEmptyOnes().filter { it.isEmpty() }.forEach { it.delete() }
  }

  private fun createClusterForCrashInstanceAndUpdateIndex(crashInstance: CrashInstanceFolder) {
    val clusterFolder = nextClusterFolder()
    CrashClusterFolder.createByMovingCrashInstance(clusterFolder, crashInstance)
  }

  private fun nextClusterFolder() = File(folder, nextClusterFolderName()).apply {
    check(mkdir())
  }

  private fun nextClusterFolderName() =
    constructClusterFolderName(getCurrentMaxClusterId() + 1)

  fun getCurrentMaxClusterId(): Int {
    return getAllClustersAndDeleteEmptyOnes()
      .map { it.folder.name }
      .map { getClusterFolderIdFromName(it) }
      .maxOrNull() ?: 0
  }

  companion object {

    fun constructClusterFolderName(clusterId: Int) = CLUSTER_FOLDER_PREFIX + clusterId

    fun getClusterFolderIdFromName(clusterFolderName: String) =
      Integer.parseInt(clusterFolderName.substring(CLUSTER_FOLDER_PREFIX.length))

    val CLUSTER_FOLDER_PREFIX = "cluster-"

    private val logger = FluentLogger.forEnclosingClass()
  }
}

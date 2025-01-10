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
package org.perses.fuzzer.organizer

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.CrashClusterIndex
import org.perses.fuzzer.CrashInstanceFolder
import org.perses.fuzzer.CrashInstanceFolder.ReproductionResult.NO_CRASH
import org.perses.fuzzer.DuplicateBugFolder
import org.perses.fuzzer.FindingFolder
import org.perses.fuzzer.ReportedBugFolder
import org.perses.util.TimeUtil
import org.perses.util.ktInfo
import java.io.File

@Suppress("DEPRECATION")
class OrganizerDriver(private val cmdOptions: CommandOptions) {

  val findingFolder = FindingFolder(cmdOptions.findingFolder)
  val processingFolder = org.perses.fuzzer.ProcessingFolder(cmdOptions.processingFolder)
  val reportedBugFolder = ReportedBugFolder(cmdOptions.reportedFolder)
  val duplicateBugFolder = DuplicateBugFolder(
    cmdOptions.duplicateBugFolder,
    reportedBugFolder,
  )

  var clusters = buildClusters()

  private val textUI = createTextUI()

  fun run() {
    logger.ktInfo { "Finding folder: ${findingFolder.root}" }
    logger.ktInfo {
      "Processing folder: ${processingFolder.folder}"
    }
    logger.ktInfo { "" }
    textUI.run()
  }

  private fun foreach(
    folders: Collection<CrashInstanceFolder>,
    action: (CrashInstanceFolder) -> Unit,
  ) {
    val size = folders.size
    folders.withIndex().forEach { (index, folder) ->
      println("Processing ($index/$size) ${folder.folder.name}")
      action(folder)
    }
  }

  fun createTextUI(): TextUI {
    val builder = TextUI.Builder()

    builder.addCommand("rebuild-clusters") {
      rebuildClusters()
    }

    builder.addCommand("show-cluster-count") {
      printClustersSize()
    }

    builder.addCommand("show-cluster", ImmutableList.of("cluster-index")) {
      check(it.size == 1) {
        "You need to provide the cluster index, which is an integer."
      }
      val index = Integer.parseInt(it.first())
      clusters.getCluster(index).print(System.out)
    }

    builder.addCommand("delete-cluster", ImmutableList.of("cluster-index")) {
      check(it.size == 1) {
        "You need to provide the cluster index, which is an integer."
      }
      val index = Integer.parseInt(it.first())
      val cluster = clusters.getCluster(index)
      println("deleting cluster $index")
      cluster.delete()
    }

    builder.addCommand("update-crash-signatures") {
      foreach(findingFolder.getAllCrashInstances()) {
        try {
          it.updateCrashSignatureAndReductionScript(
            it.createCrashDetector(),
            updateReductionScript = true,
          )
        } catch (e: CrashInstanceFolder.NotCrashAnyMoreException) {
          check(it.delete()) { it }
        }
      }
      foreach(reportedBugFolder.getAllCrashInstances()) {
        try {
          it.updateCrashSignatureAndReductionScript(
            it.createCrashDetector(),
            updateReductionScript = false,
          )
        } catch (e: CrashInstanceFolder.NotCrashAnyMoreException) {
          println("Problem with ${it.folder}")
          throw e
        }
      }
      rebuildClusters()
    }

    builder.addCommand("remove-irreproducibles") {
      println("Removing irreproducible instances.")
      printClustersSize()
      foreach(findingFolder.getAllCrashInstances()) {
        if (it.isReproducible() == NO_CRASH) {
          it.delete()
        }
      }
      rebuildClusters()
    }

    builder.addCommand("archive-reported-bugs") {
      println("Move reported bugs to ${reportedBugFolder.root}")
      moveReportedBugReport()
      if (cmdOptions.deleteDuplicates) {
        println("Delete duplicate bugs to ${duplicateBugFolder.root}")
        deleteDuplicateBugReports()
      } else {
        println("Move duplicate bugs to ${duplicateBugFolder.root}")
        moveDuplicateBugReports()
      }
      rebuildClusters()
    }

    builder.addCommand("find-largest-mutant") {
      val max = getInstanceWithLargestMutantFile()

      if (max != null) {
        println(
          "The max mutant file is in ${max.folder}, size=${max.getMutantFile().length()} bytes",
        )
      } else {
        println("Empty.")
      }
    }

    builder.addCommand("find-smallest-mutant") {
      val min = getInstanceWithSmallestMutantFile()

      if (min != null) {
        println(
          "The min mutant file is in ${min.folder}, size=${min.getMutantFile().length()} bytes",
        )
      } else {
        println("Empty.")
      }
    }

    builder.addCommand("save-clusters") {
      val formatDateForFile = TimeUtil.formatDateForFileName(System.currentTimeMillis())
      val file = File(processingFolder.folder, "clusters_$formatDateForFile.txt")
      clusters.saveTo(file)
      println(clusters.saveToString())
      println("The cluster information is saved to $file")
    }

    return builder.build()
  }

  private fun rebuildClusters() {
    println("rebuilding clusters.")
    printClustersSize()
    clusters = buildClusters()
    printClustersSize()
  }

  private fun buildClusters() = findingFolder.clusterCrashesOnCrashSignatures()

  private fun printClustersSize() {
    println("#clusters=${clusters.numberOfClusters}, #instances=${clusters.numberOfInstances}")
  }

  private fun getInstanceWithLargestMutantFile(): CrashInstanceFolder? {
    return findingFolder.getInstanceWithLargestMutantFile()
  }

  private fun getInstanceWithSmallestMutantFile(): CrashInstanceFolder? {
    return findingFolder.getInstanceWithSmallestMutantFile()
  }

  fun moveDuplicateBugReports() {
    foreach(findingFolder.getAllCrashInstances()) {
      duplicateBugFolder.moveToThisFolderIfDuplicate(it)
    }
  }

  private fun deleteDuplicateBugReports() {
    findingFolder.getAllCrashInstances().forEach {
      if (reportedBugFolder.getMasterIfDuplicate(it) != null) {
        it.delete()
      }
    }
  }

  fun moveReportedBugReport() {
    foreach(findingFolder.getReportedCrashInstances()) {
      reportedBugFolder.moveReportedCrashToThis(it)
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }

  class CrashClusterBox(var clusters: CrashClusterIndex)
}

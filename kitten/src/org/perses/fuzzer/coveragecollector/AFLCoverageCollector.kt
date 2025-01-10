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
package org.perses.fuzzer.coveragecollector

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.compilers.ActionResult
import org.perses.fuzzer.compilers.ICompilationAction
import org.perses.fuzzer.coveragecollector.ICoverageCollector.CoverageReport
import org.perses.util.Util
import org.perses.util.ktInfo
import java.io.File
import java.nio.Buffer
import java.nio.ByteBuffer
import java.nio.file.Files
import java.nio.file.Path
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit
import kotlin.experimental.or
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

class AFLCoverageCollector(
  val monitorInterval: Long,
  val resultFile: Path,
) : ICoverageCollector {

  private val globalBitMap = ByteArray(MAP_SIZE)

  private val sharedMemoryLocal = ThreadLocal<SharedMemory>()

  override fun registerForThread() {
    val sharedMemory = createSharedMemory()
    sharedMemoryLocal.set(sharedMemory)
  }

  override fun closeForThread() {
    sharedMemoryLocal.get().close()
  }

  override fun executeActionWithCoverageCollection(
    action: ICompilationAction,
    file: File,
    threadId: Long,
  ): ActionResult {
    val sharedMemory = sharedMemoryLocal.get()
    sharedMemory.clean()
    val result = action.compileWithExtraEnvironment(
      file,
      getEnvironmentVariableForAFLSharedMemory(sharedMemory.id),
    )
    triggerNewEdge(sharedMemory.buffer)
    return result
  }

  fun getSharedMemoryIdWithThreadId(): SharedMemory? {
    return sharedMemoryLocal.get()
  }

  data class SharedMemory(
    val id: Int,
    val buffer: ByteBuffer,
  ) {
    fun clean() {
      // Have to do the cast before call clear and flip due to the problem described in the following webpage:
      // https://stackoverflow.com/questions/48693695/java-nio-buffer-not-loading-clear-method-on-runtime
      (buffer as Buffer).clear()
      for (i in 0 until buffer.capacity()) {
        buffer.put(0)
      }
      (buffer as Buffer).flip()
    }

    fun getHitCount(): Int {
      (buffer as Buffer).clear()
      var res = 0
      for (i in 0 until buffer.limit()) {
        if (buffer.get().toInt() != 0) {
          res++
        }
      }
      (buffer as Buffer).clear()
      return res
    }

    fun close() {
      closeSharedMemory(id)
    }
  }

  override fun launch(): ExecutorService? {
    val scheduledExecutor = Executors.newScheduledThreadPool(1)
    // Clean the content in the file first
    resultFile.writeText(java.util.Date(System.currentTimeMillis()).toString())
    resultFile.writeText("\n")
    scheduledExecutor.scheduleAtFixedRate(
      {
        val coverageReport = getCoverageReport()
        logger.ktInfo { "Current map density: %s".format(coverageReport.aflMapDensity) }
        logger.ktInfo { "Current hit count: %s".format(coverageReport.aflHitCount) }
        resultFile.writeText(
          "map density: %s\nhit count: %s\n\n"
            .format(coverageReport.aflMapDensity, coverageReport.aflHitCount),
        )
      },
      0,
      monitorInterval,
      TimeUnit.SECONDS,
    )
    return scheduledExecutor
  }

  @VisibleForTesting
  override fun getCoverageReport(): CoverageReport {
    var hitCount = 0
    globalBitMap.iterator().forEach {
      if (it.toInt() != 0) {
        hitCount++
      }
    }
    val mapDensity = hitCount.toDouble() / MAP_SIZE
    return CoverageReport(
      branch_covered = 0,
      branch_total = 1,
      line_covered = 0,
      line_total = 1,
      mapDensity,
      hitCount,
    )
  }

  @Synchronized
  fun triggerNewEdge(buffer: ByteBuffer): Boolean {
    assert(buffer.limit() == globalBitMap.size)
    var res = false
    for (i in 0 until buffer.limit()) {
      if (buffer[i].toInt() != 0 && globalBitMap[i].toInt() == 0) {
        res = true
      }
      globalBitMap[i] = globalBitMap[i].or(buffer[i])
    }
    return res
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
    private const val MAP_SIZE_POW2 = 20
    private const val MAP_SIZE = 1 shl MAP_SIZE_POW2
    const val AFL_LIB_NAME = "afl_coverage_jni"
    const val AFL_LIB_SO_FILE_NAME = "lib$AFL_LIB_NAME.so"
    val ALF_JAVA_LIB_DIR_PREFIX = "perses_fuzzer_system_lib_" +
      AFLCoverageCollector::class.simpleName
    val SYSTEM_LIBRARY_PATH = loadSystemLibrary()

    private fun loadSystemLibrary(): Path {
      val dir = createAFLSysLibraryDirectory()
      val libFile = dir.resolve(AFL_LIB_SO_FILE_NAME)
      Util.copyResource(
        AFL_LIB_SO_FILE_NAME,
        AFLCoverageCollector::class.java,
        libFile,
      )
      System.load(libFile.toString())
      return dir
    }

    @OptIn(ExperimentalPathApi::class)
    private fun createAFLSysLibraryDirectory(): Path {
      val path = Files.createTempDirectory(ALF_JAVA_LIB_DIR_PREFIX)
      Runtime.getRuntime().addShutdownHook(
        Thread {
          path.deleteRecursively()
        },
      )
      return path
    }

    fun createSharedMemory(): SharedMemory {
      val id = setupSharedMemory(MAP_SIZE)
      val buffer = getSharedMemory(id, MAP_SIZE)
      assert(buffer.limit() == MAP_SIZE)
      return SharedMemory(id, buffer)
    }

    fun getEnvironmentVariableForAFLSharedMemory(
      sharedMemoryId: Int,
    ): ImmutableMap<String, String> {
      return ImmutableMap.of("__AFL_SHM_ID", sharedMemoryId.toString())
    }

    private external fun setupSharedMemory(mapSize: Int): Int

    private external fun getSharedMemory(id: Int, mapSize: Int): ByteBuffer

    external fun closeSharedMemory(id: Int)
  }
}

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
import com.google.common.flogger.FluentLogger
import com.sun.management.GarbageCollectionNotificationInfo
import java.lang.management.ManagementFactory
import java.lang.management.MemoryPoolMXBean
import java.lang.management.MemoryType
import java.util.concurrent.atomic.AtomicLong
import java.util.concurrent.atomic.AtomicReference
import java.util.regex.Pattern
import javax.management.Notification
import javax.management.NotificationEmitter
import javax.management.NotificationListener
import javax.management.openmbean.CompositeData

class GCMonitoring : NotificationListener {
  // --- Internal State ---
  private val judgements = AtomicReference(CompositeJudgement())
  private val consecutiveHighHeapUsageCount = AtomicLong(0)
  private val lastGcEndTimeMillis = AtomicLong(System.currentTimeMillis())

  private val allHeapMemoryPoolsOfInterest: ImmutableList<MemoryPoolMXBean> =
    ManagementFactory
      .getMemoryPoolMXBeans()
      .filterToImmutableList {
        it.type == MemoryType.HEAP &&
          !it.name.contains("Metaspace", ignoreCase = true) &&
          !it.name.contains("Code Cache", ignoreCase = true)
      }

  // Attempt to find the Old Generation pool. Naming is GC-dependent.
  private val oldGenMemoryPool: MemoryPoolMXBean =
    allHeapMemoryPoolsOfInterest.single {
      it.name.contains("Old Gen", ignoreCase = true) ||
        // For Parallel, CMS, G1
        it.name.contains("Tenured Gen", ignoreCase = true) // Less common, but just in case
    } // Specific reference to the Old Gen pool

  init {
    require(allHeapMemoryPoolsOfInterest.isNotEmpty()) {
      "Fail to find HEAP MemoryPoolMXBeans."
    }

    var registered = false
    // --- 2. Register GC Notification Listener ---
    ManagementFactory.getGarbageCollectorMXBeans().forEach { gcBean ->
      if (gcBean is NotificationEmitter) {
        registered = true
        gcBean.addNotificationListener(this, null, null)
      } else {
        System.err.println(
          "Warning: GC MXBean ${gcBean.name} does not implement NotificationEmitter. " +
            "Detailed GC notifications might not be received for this collector.",
        )
      }
    }
    check(registered) {
      "Failed to register GC notification listener."
    }
  }

  override fun handleNotification(
    notification: Notification,
    handback: Any?,
  ) {
    internalHandleGCNotification(notification)
    println("Memory pressure: " + isMemoryPressureHigh())
  }

  private fun internalHandleGCNotification(notification: Notification) {
    if (notification.type != GarbageCollectionNotificationInfo.GARBAGE_COLLECTION_NOTIFICATION) {
      return
    }

    try {
      val cd = notification.userData as? CompositeData
      if (cd == null) {
        System.err.println("Warning: GC notification userData is not CompositeData. Skipping.")
        return
      }

      val info = GarbageCollectionNotificationInfo.from(cd)

      val gcName = info.gcName
      val gcAction = info.gcAction
      val gcCause = info.gcCause
      val gcInfo = info.gcInfo

      val duration = gcInfo.duration
      val currentGcEndTime = System.currentTimeMillis()

      println(
        "GC Event: Name=$gcName, Action=$gcAction, Cause=$gcCause, Duration=${duration}ms",
      )

      // --- 1. Analyze Total Heap Usage ---
      val configuredMaxHeap = Runtime.getRuntime().maxMemory()
      var totalCurrentHeapUsed = 0L

      if (allHeapMemoryPoolsOfInterest.isNotEmpty()) {
        allHeapMemoryPoolsOfInterest.forEach { pool ->
          println("pool ${pool.name}: used=${pool.usage.used}, max=${pool.usage.max}")
          totalCurrentHeapUsed += pool.usage.used
        }
        val gcInfoHeapUsage = gcInfo.memoryUsageAfterGc["heap"]
        if (gcInfoHeapUsage != null) {
          println(
            "  (GcInfo snapshot) Overall heap after GC: Used=${gcInfoHeapUsage.used}, Max=${gcInfoHeapUsage.max}",
          )
        }
      } else {
        System.err.println(
          "Error: No HEAP MemoryPoolMXBeans found. Overall heap usage will not be reported.",
        )
      }

      var overallHeapUsageHigh = false
      if (configuredMaxHeap > 0 && totalCurrentHeapUsed > 0L) {
        val usagePercentage = totalCurrentHeapUsed.toDouble() / configuredMaxHeap
        println(
          String.format(
            "  Total Heap Usage: %.2f%% (Current Used: %d, Configured Max: %d (from -Xmx))",
            usagePercentage * 100,
            totalCurrentHeapUsed,
            configuredMaxHeap,
          ),
        )
        if (usagePercentage > TOTAL_HEAP_USAGE_AFTER_GC_THRESHOLD) {
          overallHeapUsageHigh = true
        }
      }

      // --- 2. Analyze Old Generation Heap Usage ---
      var oldGenUsageHigh = false
      val oldGenUsed = oldGenMemoryPool.usage.used
      val oldGenMax = oldGenMemoryPool.usage.max // Max for Old Gen pool, can be -1 if not fixed
      oldGenMemoryPool.usage
      // If oldGenMax is not fixed (-1), use configuredMaxHeap for percentage, otherwise use oldGenMax.
      // It's generally more robust to compare against configuredMaxHeap for a consistent base.
      val oldGenPercentageBase = if (oldGenMax > 0) oldGenMax else configuredMaxHeap

      if (oldGenPercentageBase > 0) {
        val oldGenUsagePercentage = oldGenUsed.toDouble() / oldGenPercentageBase
        println(
          String.format(
            "  Old Gen Usage: %.2f%% (Used: %d, Max: %d)",
            oldGenUsagePercentage * 100,
            oldGenUsed,
            oldGenMax,
          ),
        )
        if (oldGenUsagePercentage > OLD_GEN_USAGE_AFTER_GC_THRESHOLD) {
          oldGenUsageHigh = true
        }
      } else {
        println(
          "  Warning: Old Gen max capacity not available or zero for percentage calculation.",
        )
      }

      // --- Other Pressure Indicators (unchanged) ---
      var longPauseDetected = false
      if (duration > LONG_GC_PAUSE_THRESHOLD_MS) {
        println("  WARNING: Long GC pause detected (${duration}ms)!")
        longPauseDetected = true
      }

      var highFrequencyDetected = false
      val timeSinceLastGc = currentGcEndTime - lastGcEndTimeMillis.get()
      if (timeSinceLastGc < GC_FREQUENCY_WARNING_THRESHOLD_MS) {
        println("  WARNING: High GC frequency detected (${timeSinceLastGc}ms since last GC)!")
        highFrequencyDetected = true
      }
      lastGcEndTimeMillis.set(currentGcEndTime)

      var causeIndicatesPressure: EnumGcCause? = null
      when {
        ALLOCATION_FAILURE_PATTERN.matcher(gcCause).find() -> {
          println("  WARNING: GC triggered by problematic cause: $gcCause (Allocation Failure)")
          causeIndicatesPressure = EnumGcCause.ALLOCATION_FAILURE
        }

        SYSTEM_GC_PATTERN.matcher(gcCause).find() -> {
          println("  WARNING: GC triggered by problematic cause: $gcCause (System.gc())")
          causeIndicatesPressure = EnumGcCause.SYSTEM_GC
        }

        CAPACITY_LIMIT_EXCEEDED_PATTERN.matcher(gcCause).find() -> {
          println(
            "  WARNING: GC triggered by problematic cause: $gcCause (Capacity Limit Exceeded)",
          )
          causeIndicatesPressure = EnumGcCause.CAPACITY_LIMIT_EXCEEDED
        }

        CONCURRENT_MODE_FAILURE_PATTERN.matcher(gcCause).find() -> {
          println(
            "  WARNING: GC triggered by problematic cause: $gcCause (Concurrent Mode Failure)",
          )
          causeIndicatesPressure = EnumGcCause.CONCURRENT_MODE_FAILURE
        }

        G1_EVACUATION_PAUSE_PATTERN.matcher(gcCause).find() -> {
          causeIndicatesPressure = null
        }

        else -> {
          println("  INFO: Unhandled GC cause: $gcCause")
        }
      }

      // --- Final Determination of Memory Pressure ---
      // Memory pressure is high if:
      // 1. Overall heap usage is consistently high OR
      // 2. Old Gen usage is high (stronger signal of retained data) OR
      // 3. Any single long pause is detected OR
      // 4. GC frequency is too high OR
      // 5. A problematic cause is identified.

      val currentPressureState =
        (
          (overallHeapUsageHigh || oldGenUsageHigh) &&
            consecutiveHighHeapUsageCount.incrementAndGet() >= SUSTAINED_HIGH_USAGE_COUNT
        ) ||
          // Sustained high usage
          duration > LONG_GC_PAUSE_THRESHOLD_MS ||
          // Any single long pause
          timeSinceLastGc < GC_FREQUENCY_WARNING_THRESHOLD_MS ||
          // High frequency of GCs
          causeIndicatesPressure != null // If any specific cause explicitly indicated pressure

      // Reset consecutive counter if neither overall nor old gen usage is high.
      if (!(overallHeapUsageHigh || oldGenUsageHigh)) {
        consecutiveHighHeapUsageCount.set(0)
      }

      // TODO(cnsun): this needs to be done.
      judgements.set(CompositeJudgement())
    } catch (e: Exception) {
      System.err.println("Error processing GC notification: ${e.message}")
      e.printStackTrace()
    }
  }

  fun isMemoryPressureHigh(): CompositeJudgement = judgements.get()

  enum class EnumGcCause {
    ALLOCATION_FAILURE,
    SYSTEM_GC,
    CAPACITY_LIMIT_EXCEEDED,
    CONCURRENT_MODE_FAILURE,
  }

  data class Judgement(
    val isUnderMemoryPressure: Boolean,
    val explanation: String,
  )

  data class CompositeJudgement(
    val overallHeapUsage: Judgement? = null,
    val oldGenUsage: Judgement? = null,
    val longPause: Judgement? = null,
    val gcFrequency: Judgement? = null,
    val problematicCause: Judgement? = null,
  )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    // --- Configuration Thresholds ---
    private const val TOTAL_HEAP_USAGE_AFTER_GC_THRESHOLD = 0.85 // Overall heap usage
    private const val OLD_GEN_USAGE_AFTER_GC_THRESHOLD = 0.85 // Specific to the Old Generation

    private const val LONG_GC_PAUSE_THRESHOLD_MS = 500L
    private const val SUSTAINED_HIGH_USAGE_COUNT = 3L
    private const val GC_FREQUENCY_WARNING_THRESHOLD_MS = 5000L

    // --- Regular Expressions for problematic GC causes ---
    private val ALLOCATION_FAILURE_PATTERN =
      Pattern.compile(
        "allocation failure",
        Pattern.CASE_INSENSITIVE,
      )
    private val SYSTEM_GC_PATTERN = Pattern.compile("system\\.gc\\(\\)", Pattern.CASE_INSENSITIVE)
    private val CAPACITY_LIMIT_EXCEEDED_PATTERN =
      Pattern.compile(
        "capacity limit exceeded",
        Pattern.CASE_INSENSITIVE,
      )
    private val CONCURRENT_MODE_FAILURE_PATTERN =
      Pattern.compile(
        "concurrent mode failure",
        Pattern.CASE_INSENSITIVE,
      )
    private val G1_EVACUATION_PAUSE_PATTERN =
      Pattern.compile(
        "G1 Evacuation Pause",
        Pattern.CASE_INSENSITIVE,
      )
  }
}

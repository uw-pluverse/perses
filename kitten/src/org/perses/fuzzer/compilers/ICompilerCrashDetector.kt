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
package org.perses.fuzzer.compilers

import com.google.common.collect.ImmutableList
import org.perses.util.shell.CmdOutput
import java.io.File

interface ICompilerCrashDetector {

  fun detectCrash(cmdOutput: CmdOutput): AbstractResult

  fun detectCrash(stderr: String, exitCodeForCrash: Int = 101): AbstractResult

  fun detectCrash(stderr: List<String>, exitCodeForCrash: Int = 101): AbstractResult

  data class CrashSignature(val elements: ImmutableList<String>) {

    fun isNotEmpty() = elements.isNotEmpty()

    fun isEmpty() = elements.isEmpty()

    fun writeTo(file: File) {
      file.writeText(toString())
    }

    override fun toString() =
      elements.joinToString(separator = "\n")

    companion object {

      fun build(strings: Iterable<String>) =
        CrashSignature(ImmutableList.copyOf(strings))

      fun readFrom(file: File) = CrashSignature(
        file
          .readLines()
          .asSequence()
          .map { it.trim() }
          .filter { it.isNotBlank() }
          .fold(
            ImmutableList.builder<String>(),
            { builder, line ->
              builder.add(line)
            },
          ).build(),
      )
    }
  }

  abstract class AbstractResult(val crashDetectorClass: Class<in ICompilerCrashDetector>) {

    init {
      assert(
        Class.forName(crashDetectorClass.canonicalName).getConstructor().newInstance() != null,
      )
    }

    abstract fun isCrashDetected(): Boolean

    fun asCrash() = this as CrashResult

    class CrashResult private constructor(
      crashDetectorClass: Class<in ICompilerCrashDetector>,
      val exitCode: Int,
      val signature: CrashSignature,
    ) : AbstractResult(crashDetectorClass) {

      override fun isCrashDetected() = true

      init {
        check(exitCode > 0)
      }

      companion object {
        fun create(
          crashDetectorClass: Class<in ICompilerCrashDetector>,
          exitCode: Int,
          rawSignature: Iterable<String>,
        ): CrashResult {
          val set = LinkedHashSet<String>()
          for (sig in rawSignature) {
            val processed = sig.trim()
            if (set.contains(processed)) {
              continue
            }
            set.add(processed)
          }
          return CrashResult(crashDetectorClass, exitCode, CrashSignature.build(set))
        }
      }
    }

    class NonCrashResult(crashDetectorClass: Class<in ICompilerCrashDetector>) :
      AbstractResult(crashDetectorClass) {
      override fun isCrashDetected() = false
    }
  }
}

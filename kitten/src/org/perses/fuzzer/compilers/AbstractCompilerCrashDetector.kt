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

import com.google.common.primitives.ImmutableIntArray
import org.perses.util.shell.CmdOutput
import java.util.concurrent.atomic.AtomicInteger

abstract class AbstractCompilerCrashDetector : ICompilerCrashDetector {

  enum class CommonCrashExitCodes(val exitCode: Int) {
    SIGILL(132),
    SIGTRAP(133),
    SIGABRT(134),
    SIGFPE(136),
    OOM(137),
    SIGBUG(138),
    SEGFAULT(139),
    SIGXCPU_1(158),
    SIGXCPU_2(152),
    SIGXFSZ_1(159),
    SIGXFSZ_2(153),
    ;

    companion object {
      private val EXIT_CODES = ImmutableIntArray.copyOf(
        values()
          .asSequence()
          .map { it.exitCode }
          .distinct()
          .asIterable(),
      )

      fun isCrashExitCode(exitCode: Int): Boolean {
        return EXIT_CODES.contains(exitCode)
      }
    }
  }

  final override fun detectCrash(cmdOutput: CmdOutput): ICompilerCrashDetector.AbstractResult {
    if (cmdOutput.exitCode.isZero()) {
      return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
    }
    return detectCrash(cmdOutput.stderr.lines, cmdOutput.exitCode.intValue)
  }

  final override fun detectCrash(stderr: String, exitCodeForCrash: Int):
    ICompilerCrashDetector.AbstractResult {
    require(exitCodeForCrash > 0) {
      "The exit code should be greater than 0."
    }
    return detectCrash(stderr.split('\n'), exitCodeForCrash)
  }

  final override fun detectCrash(stderr: List<String>, exitCodeForCrash: Int):
    ICompilerCrashDetector.AbstractResult {
    require(exitCodeForCrash > 0) {
      "The exit code should be non-zero."
    }
    val rawSignature = detectCrashSignatureFromStderr(stderr)
    checkRawSignaturesAreInStdErr(rawSignature, stderr)
    val isCommonCrashExitCode = CommonCrashExitCodes.isCrashExitCode(exitCodeForCrash)
    if (rawSignature.isEmpty() && !isCommonCrashExitCode) {
      return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
    } else {
      return ICompilerCrashDetector.AbstractResult.CrashResult.create(
        javaClass,
        exitCodeForCrash,
        rawSignature,
      )
    }
  }

  private fun checkRawSignaturesAreInStdErr(rawSignature: List<String>, stderr: List<String>) {
    for (signature in rawSignature) {
      check(stderr.asSequence().filter { it.contains(signature) }.count() > 0) {
        /*
         * We use signatures to create reduction scripts, in which grep is used to
         * check whether the stderr has the raw signatures.
         */
        "The raw signature must be a substring of the stderr. sig=$signature, stderr=$stderr"
      }
    }
  }

  abstract fun detectCrashSignatureFromStderr(stderr: List<String>): List<String>

  abstract class AbstractSignatureElement(val value: String)

  protected class CrashMessageLine(value: String) : AbstractSignatureElement(value)

  protected class StackTraceLine(value: String) : AbstractSignatureElement(value)

  companion object {
    @JvmStatic
    fun limitStackTraceLines(signature: List<AbstractSignatureElement>, limit: Int):
      Sequence<AbstractSignatureElement> {
      require(limit > 0)
      val counter = AtomicInteger(0)
      return signature.asSequence().filter {
        when (it) {
          is CrashMessageLine -> {
            counter.set(0)
            true
          }
          is StackTraceLine -> {
            val currentCount = counter.incrementAndGet()
            currentCount <= limit
          }
          else -> TODO(it.toString())
        }
      }
    }
  }
}

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
package org.perses.listminimizer

import org.perses.util.Util
import java.nio.file.Path
import kotlin.reflect.KClass

class ListMinimizerProgressListener(
  file: Path,
) : AbstractListMinimizerListener() {
  private val stream =
    Util.createNonAppendablePrintStream(
      path = file,
    )

  override fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  ) {
    val size = originalInput.size
    stream.println("Reduction starts: algorithm=${listMinimizerClass.simpleName}")
    stream.println("The original input has $size element(s).")
    for (i in 0 until size) {
      val element = originalInput[i]
      stream.println("--Element $i")
      stream.println("  index=${element.index}, payload=$element.elementPayload}")
      stream.println("  element=${element.element}")
    }
  }

  override fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    sizeOfOriginalInput: Int,
  ) {
    stream.append("Reduction ").append(listMinimizerClass.simpleName).append(" ends. ")
    stream.append("Result=[")
    minimizationResult.joinTo(stream, separator = ",") { it.index.toString() }
    stream.append("]\n\n")
  }

  override fun onBestUpdate(newBest: List<ElementWrapper<*>>) {
    newBest.map { it.index }.let {
      stream.println("New best is found: $it")
    }
  }

  override fun onPropertyTest(
    configuration: Candidate<*>,
    result: LMPropertyTestResult<*, *>,
    sizeOfOriginalList: Int,
    sizeOfCurrentMinimizationResult: Int,
  ) {
    val idList = configuration.deletedWrappers.map { it.index }
    val resultString = result.toShortString()
    val localReductionRate =
      Util.computePercentage(
        numerator = sizeOfCurrentMinimizationResult,
        denominator = sizeOfOriginalList,
      )
    stream.println("Try deleting: $idList: $resultString. Local rate: $localReductionRate")
  }

  override fun log(msg: () -> String) {
    stream.println(msg())
  }

  override fun close() {
    stream.close()
  }
}

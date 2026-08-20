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
package org.perses.reduction.io.token

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.io.AbstractOriginalReductionInputs
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.util.hashing.EnumShaAlgorithm

abstract class AbstractTokenOutputManagerFactory(
  override val originalReductionInputs: AbstractOriginalReductionInputs,
  val defaultCodeFormatControl: EnumFormatControl,
  val lexerAtnWrapper: LexerAtnWrapper,
  shaAlgorithm: EnumShaAlgorithm,
) : AbstractOutputManagerFactory<TokenizedProgram>(originalReductionInputs, shaAlgorithm) {
  protected val defaultProgramPrinter =
    PrinterRegistry.getPrinter(defaultCodeFormatControl, lexerAtnWrapper)

  /**
   * Returns an immutable sibling factory identical to this one but printing in [codeFormat], or
   * null if this factory does not offer format siblings.
   *
   * This is the decoupling seam for adaptive code-format selection: a code format is carried by the
   * *factory*, not the IO manager, so "switch format" = use a different (sibling) factory while
   * reusing the same IO manager (file management). Nothing is mutated; each factory stays immutable.
   */
  open fun cloneWithCodeFormat(codeFormat: EnumFormatControl): AbstractTokenOutputManagerFactory? =
    null
}

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
package org.perses.reduction.io

import com.google.common.collect.ImmutableMap
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.SourceFile
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager

/**
 * The single-file, token-reduction flavor of [AbstractReductionTestData]: one `t.c` source and a
 * [TokenReductionIOManager]. Test classes extend it to inherit a ready-to-use IO manager, executor,
 * inputs, and result folder.
 */
open class CommonReductionIOManagerData(
  testClass: Class<*>,
) : AbstractReductionTestData(
    testClass,
    scriptBody = "test",
    sources = listOf(SourceSpec("t.c", "int a;", LanguageC)),
  ) {
  val sourceFile: SourceFile = mutableFile("t.c")
  val outputManagerFactory =
    RegularOutputManagerFactory(
      inputs,
      EnumFormatControl.ORIG_FORMAT,
      LexerAtnWrapper.createLexerWrapperFromLexerClass(PnfCLexer::class.java),
      shaAlgorithm = shaAlgorithm,
      fileRepresentedByProgram = sourceFile,
      // Single-file reduction has no siblings.
      otherMutableFileContents = ImmutableMap.of<AbstractReductionFile<*, *>, String>(),
    )
  override val ioManager =
    TokenReductionIOManager(
      workingFolder = workingDir,
      originalReductionInputs = inputs,
      resultFolder = createPopulatedResultFolder(),
    )
}

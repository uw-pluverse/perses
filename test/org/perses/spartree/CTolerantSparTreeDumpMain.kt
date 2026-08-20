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
package org.perses.spartree

import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.PnfCParserFacade
import org.perses.util.Util
import java.nio.file.Paths
import kotlin.io.path.absolute
import kotlin.io.path.bufferedWriter
import kotlin.io.path.readText

/**
 * Dumps the [SparTree.printTreeStructure] of one C program, built via the TOLERANT path, to a file.
 * Reads the source from the first argument and writes the dump to the second. Uses [PnfCParserFacade]
 * (the OrigC.g4 grammar) so grammar changes there are exercised. Backs the per-input
 * `golden_test_tolerant_spartree_*` golden tests; regenerate a golden with its `..._update` target.
 */
object CTolerantSparTreeDumpMain {
  @JvmStatic
  fun main(args: Array<String>) {
    require(args.size == 2) {
      "Expected two arguments (input source file, output dump file), got: ${args.toList()}"
    }
    val sourceCode = Paths.get(args[0]).readText()
    val outputFile = Paths.get(args[1]).absolute()
    Util.ensureDirExists(outputFile.parent)
    val tree =
      SparTreeParserUtility.buildSparTree(
        sourceCode = sourceCode,
        parserFacade = PnfCParserFacade(),
        specifiedSparTreeNodeFactory = null,
        simplifyTree = true,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.TOLERANT,
      )
    outputFile.bufferedWriter().use { it.append(tree.printTreeStructure().trimEnd()).append('\n') }
  }
}

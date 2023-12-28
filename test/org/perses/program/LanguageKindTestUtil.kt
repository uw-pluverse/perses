/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.program

import com.google.common.truth.Truth.assertThat
import org.perses.grammar.AbstractParserFacade
import org.perses.program.TokenizedProgramFactory.Companion.createFactory
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import java.nio.file.Files
import java.nio.file.Path

class LanguageKindTestUtil {

  companion object {
    fun assertCodeFormatsDoNotProduceSyntacticallyInvalidPrograms(
      facade: AbstractParserFacade,
      program: Path,
    ) {
      val language = facade.language
      val parseTree = facade.parseFile(program)
      val tokenizedProgramFactory = createFactory(
        AbstractParserFacade.getTokens(parseTree.tree),
        language,
      )
      val sparTreeNodeFactory = SparTreeNodeFactory(
        facade.metaTokenInfoDb,
        tokenizedProgramFactory,
        facade.ruleHierarchy,
      )
      val sparTreeBuilder = SparTreeBuilder(
        sparTreeNodeFactory,
        parseTree,
      )
      val sparTree = sparTreeBuilder.result
      val tokenizedProgram = sparTree.programSnapshot

      val allowedCodeFormatControl = language.allowedCodeFormatControl
      for (formatControl in allowedCodeFormatControl) {
        val tempFile = Files.createTempFile(
          LanguageKindTestUtil::class.java.simpleName,
          ".test_file",
        )
        try {
          val printer = PrinterRegistry.getPrinter(formatControl)
          printer.print(tokenizedProgram).writeTo(tempFile)
          val reconstructedParseTree = facade.parseFile(tempFile)
          val reconstructedSparTree = SparTreeBuilder(
            sparTree.sparTreeNodeFactory,
            reconstructedParseTree,
          ).result
          val reconstructedTokens = reconstructedSparTree.programSnapshot.tokens.map {
            it.text
          }
          assertThat(reconstructedTokens).containsExactlyElementsIn(
            tokenizedProgram.tokens.map { it.text },
          )
        } finally {
          Files.delete(tempFile)
        }
      }
    }
  }
}

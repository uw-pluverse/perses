/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
import org.perses.tree.spar.SparTreeBuilder
import java.io.File

class LanguageKindTestUtil {

  companion object {
    fun assertCodeFormatsDoNotProduceSyntaxticallyInvalidPrograms(
      facade: AbstractParserFacade,
      program: File
    ) {
      val language = facade.language
      val parseTree = facade.parseFile(program).tree
      val tokenizedProgramFactory = createFactory(
        AbstractParserFacade.getTokens(parseTree)
      )
      val sparTreeBuilder = SparTreeBuilder(facade.ruleHierarchy, tokenizedProgramFactory)
      val sparTree = sparTreeBuilder.build(parseTree)
      val tokenizedProgram = sparTree.programSnapshot

      val allowedCodeFormatControl = language.allowedCodeFormatControl
      for (formatControl in allowedCodeFormatControl) {
        val tempFile = File.createTempFile(
          LanguageKindTestUtil::class.java.simpleName, ".test_file"
        )
        try {
          tokenizedProgram.writeToFile(tempFile, formatControl)
          val reconstructedParseTree = facade.parseFile(tempFile).tree
          val reconstructedSparTree = sparTreeBuilder.build(reconstructedParseTree)
          val reconstructedTokens = reconstructedSparTree.programSnapshot.tokens.map {
            it.text
          }
          assertThat(reconstructedTokens).containsExactlyElementsIn(
            tokenizedProgram.tokens.map { it.text }
          )
        } finally {
          tempFile.delete()
        }
      }
    }
  }
}

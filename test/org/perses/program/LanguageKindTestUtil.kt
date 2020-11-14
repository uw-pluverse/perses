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

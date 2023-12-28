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
package org.perses.antlr.pnf

import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.util.AntlrToolWrapper.Companion.doesAntlrAcceptGrammar

class PnfGrammarChecker {

  companion object {

    @JvmStatic
    fun validateIntermediateGrammar(
      grammarAfter: GrammarPair,
      passClass: Class<out AbstractPnfPass>,
      grammarBefore: GrammarPair,
    ) {
      try {
        checkNoDuplicateDefs(grammarAfter)
        // call the antlr tool to validate the grammar.
        checkAntlrAcceptsTheGrammar(grammarAfter)
      } catch (e: Exception) {
        val builder = StringBuilder()
        builder.append("Validation fails after pass ").append(passClass).append("\n")
        builder.append("\n\n")
        builder.append("Grammar Before: \n")
        builder.append(grammarBefore.combinedSourceCode)
        builder.append("\n\n\n")
        builder.append("Grammar After: \n")
        builder.append(grammarAfter.combinedSourceCode)
        builder.append("\n\n")
        throw RuntimeException(builder.toString(), e)
      }
    }

    fun checkAntlrAcceptsTheGrammar(
      grammar: GrammarPair,
    ) {
      val parserGrammar = grammar.convertParserToFileContentPair()
        ?: // if the parser file is empty, then it is not possible to check its validity.
        return
      val lexerGrammar = grammar.convertLexerToFileContentPair()
      val antlrCheckingResult = doesAntlrAcceptGrammar(
        parserGrammar,
        lexerGrammar,
      )

      check(antlrCheckingResult.accpeted) {
        val message = """
          ====Antlr tool failed==== 
          ${antlrCheckingResult.message}
          
          ====parserGrammar=====
          ${parserGrammar.fileName}
          
          ====parserGrammar====
          ${parserGrammar.computeFileContent()}
          
          ====lexerGrammar====
          ${lexerGrammar?.fileName}
          
          ====lexerGrammar====
          ${lexerGrammar?.computeFileContent()}
        """.trimIndent()

        System.err.println(message)
        message
      }
    }

    @JvmStatic
    fun checkNoDuplicateDefs(grammar: GrammarPair) {
      grammar.grammarSequence().flatMap { it.flattenedAllRules }.forEach { rule ->
        val body = rule.body
        if (body is PersesAlternativeBlockAst) {
          PersesAlternativeBlockAst.checkNoDuplicatesAmongAlternatives(
            body.alternatives,
          )
        }
      }
    }
  }
}

/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.util.AntlrToolWrapper.Companion.doesAntlrAcceptGrammar
import org.perses.util.FileNameContentPair

class PnfGrammarChecker {

  companion object {

    @JvmStatic
    fun validateIntermediateGrammar(
      grammarAfter: PersesGrammar,
      passClass: Class<out AbstractPnfPass>,
      grammarBefore: PersesGrammar,
      lexerGrammar: FileNameContentPair?
    ) {
      try {
        checkNoDuplicateDefs(grammarAfter)
        // call the antlr tool to validate the grammar.
        checkAntlrAcceptsTheGrammar(grammarAfter, lexerGrammar)
      } catch (e: Exception) {
        val builder = StringBuilder()
        builder.append("Validation fails after pass ").append(passClass).append("\n")
        builder.append("\n\n")
        builder.append("Grammar Before: \n")
        builder.append(grammarBefore.sourceCode)
        builder.append("\n\n\n")
        builder.append("Grammar After: \n")
        builder.append(grammarAfter.sourceCode)
        builder.append("\n\n")
        throw RuntimeException(builder.toString(), e)
      }
    }

    private fun checkAntlrAcceptsTheGrammar(
      grammar: PersesGrammar,
      lexerGrammar: FileNameContentPair?
    ) {
      val antlrCheckingResult = doesAntlrAcceptGrammar(
        FileNameContentPair(grammar.grammarName + ".g4", grammar.sourceCode),
        lexerGrammar
      )
      check(antlrCheckingResult.accpeted) { "Antlr tool failed: ${antlrCheckingResult.message}" }
    }

    @JvmStatic
    fun checkNoDuplicateDefs(grammar: PersesGrammar) {
      grammar.parserRules.forEach { rule ->
        val body = rule.body
        if (body is PersesAlternativeBlockAst) {
          PersesAlternativeBlockAst.checkNoDuplicatesAmongAlternatives(
            body.alternatives
          )
        }
      }
    }
  }
}

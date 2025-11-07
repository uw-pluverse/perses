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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.atn.ATN
import org.perses.antlr.atn.LexerAtnWrapper
import java.lang.reflect.Modifier

abstract class AbstractLexerAdaptor(
  inputStream: CharStream,
) : Lexer(inputStream) {
  private val allTokens by lazy {
    computeAllTokens()
  }

  protected abstract fun computeAllTokens(): ImmutableList<Token>

  private var iterator: Iterator<Token>? = null

  override fun nextToken(): Token {
    if (iterator == null) {
      reset()
    }
    val iterator = iterator!!
    val token =
      if (iterator.hasNext()) {
        iterator.next()
      } else {
        EOF_TOKEN
      }
    emit(token)
    return token
  }

  override fun getATN(): ATN {
    error("not implemented")
  }

  override fun reset() {
    iterator = allTokens.iterator()
  }

  override fun getRuleNames(): Array<String> {
    error("not implemented")
  }

  override fun getGrammarFileName(): String = this::class.java.name

  init {
    val lexerWrapperField =
      this::class.java.declaredFields.singleOrNull {
        it.name == LEXER_WRAPPER_FIELD_NAME
      }
    require(lexerWrapperField != null) {
      "The class ${this::class} should have a static field named $LEXER_WRAPPER_FIELD_NAME"
    }
    require(Modifier.isStatic(lexerWrapperField.modifiers)) {
      "The field $LEXER_WRAPPER_FIELD_NAME modifiers must be static."
    }
    require(lexerWrapperField.type == LexerAtnWrapper::class.java) {
      "The field $LEXER_WRAPPER_FIELD_NAME type must be ${LexerAtnWrapper::class}."
    }
  }

  companion object {
    const val LEXER_WRAPPER_FIELD_NAME = "LEXER_WRAPPER"

    private val EOF_TOKEN = CommonToken(Token.EOF)
  }
}

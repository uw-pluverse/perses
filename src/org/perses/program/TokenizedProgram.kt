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

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.TokenFactory
import org.antlr.v4.runtime.TokenSource
import org.perses.util.FastStringBuilder
import java.io.File
import java.nio.charset.StandardCharsets
import java.nio.file.Files

/** A program represented by a list of tokens.  */
class TokenizedProgram(val tokens: ImmutableList<PersesToken>) {

  private val sourceCodeSingleLine = object : AbstractLazySourceCode() {
    override fun computeStringBuilder() = tokens.asSequence().fold(
      FastStringBuilder(tokenCount() * 5),
      { builder, token -> builder.append(token.text).append('\n') }
    )
  }
  private val sourceCodeInOrigFormat = object : AbstractLazySourceCode() {
    override fun computeStringBuilder() = computeSourceCodeInOrigFormat(
      tokens, keepBlankLines = true
    )
  }

  private val compactSourceCodeInOrigFormat = object : AbstractLazySourceCode() {
    override fun computeStringBuilder() = computeSourceCodeInOrigFormat(
      tokens, keepBlankLines = false
    )
  }

  fun toCompactSourceCode() = compactSourceCodeInOrigFormat.sourceCode

  fun toSourceCodeInOrigFormatWithBlankLines() = sourceCodeInOrigFormat.sourceCode

  fun tokenCount() = tokens.size

  override fun toString() =
    MoreObjects.toStringHelper(this).add("tokens", tokens).toString()

  fun writeToFile(file: File, formatControl: EnumFormatControl) {
    Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8).use { writer ->
      when (formatControl) {
        EnumFormatControl.ORIG_FORMAT -> sourceCodeInOrigFormat.writeTo(writer)
        EnumFormatControl.SINGLE_TOKEN_PER_LINE -> sourceCodeSingleLine.writeTo(writer)
        EnumFormatControl.COMPACT_ORIG_FORMAT -> compactSourceCodeInOrigFormat.writeTo(writer)
        else -> throw RuntimeException("Unhandled format control: $formatControl")
      }
    }
  }

  fun createTokenSource() = object : TokenSource {

    private val iterator = tokens.iterator()

    override fun nextToken(): Token {
      return if (iterator.hasNext()) {
        iterator.next()
      } else {
        EOF_TOKEN
      }
    }

    override fun getLine(): Int {
      throw UnsupportedOperationException()
    }

    override fun getCharPositionInLine(): Int {
      throw UnsupportedOperationException()
    }

    override fun getInputStream(): CharStream {
      throw UnsupportedOperationException()
    }

    override fun getSourceName() = "<from TokenizedProgram>"

    override fun setTokenFactory(tokenFactory: TokenFactory<*>?) {
      throw UnsupportedOperationException()
    }

    override fun getTokenFactory(): TokenFactory<*> {
      throw UnsupportedOperationException()
    }
  }

  companion object {
    private fun computeSourceCodeInOrigFormat(
      tokens: ImmutableList<PersesToken>,
      keepBlankLines: Boolean
    ): FastStringBuilder {
      val tokenCount = tokens.size
      val builder = FastStringBuilder(tokenCount * 5)
      var lineNoCurrent = 1
      var positionInLineCurrent = 0
      for (i in 0 until tokenCount) {
        val token = tokens[i]
        val lineNo = token.line
        val tokenPositionInLine = token.charPositionInLine
        val text = token.text
        assert(lineNo > 0)
        assert(tokenPositionInLine >= 0)
        while (lineNoCurrent < lineNo) {
          ++lineNoCurrent
          if (keepBlankLines) {
            builder.append('\n')
          } else if (builder.isNotEmpty() && builder.lastChar() != '\n') {
            builder.append('\n')
          }
          positionInLineCurrent = 0
        }
        check(positionInLineCurrent <= tokenPositionInLine) {
          "This printing algorithm is designed for program reduction only. index: $i, token: $text"
        }
        while (positionInLineCurrent < tokenPositionInLine) {
          ++positionInLineCurrent
          builder.append(' ')
        }
        builder.append(text)
        positionInLineCurrent += text.length
      }
      builder.append('\n')
      return builder
    }

    private val EOF_TOKEN: Token = CommonToken(Token.EOF)
  }
}

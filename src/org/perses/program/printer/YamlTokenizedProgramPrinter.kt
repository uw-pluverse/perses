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
package org.perses.program.printer

import com.fasterxml.jackson.databind.JsonNode
import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.databind.util.TokenBuffer
import com.fasterxml.jackson.dataformat.yaml.YAMLFactory
import org.perses.grammar.jackson.PnfJacksonParser
import org.perses.program.AbstractLazySourceCode
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

class YamlTokenizedProgramPrinter : AbstractTokenizedProgramPrinter() {
  private val objectMapper = ObjectMapper(YAMLFactory())

  override fun print(
    program: TokenizedProgram,
    tokenPlacementListener: AbstractTokenPlacementListener?,
  ): AbstractLazySourceCode {
    return object : AbstractLazySourceCode() {
      override fun computeStringBuilder(): FastStringBuilder {
        val builder = FastStringBuilder(0)
        val tokenBuffer = transformToTokenBuffer(program, objectMapper)
        val jsonTree = objectMapper.readTree<JsonNode>(tokenBuffer.asParser())
        builder.append(objectMapper.writeValueAsString(jsonTree))
        return builder
      }
    }
  }

  override fun extraEquals(other: Any): Boolean = true

  override fun extraHashCode(): Int = 0

  companion object {
    fun transformToTokenBuffer(
      program: TokenizedProgram,
      objectMapper: ObjectMapper,
    ): TokenBuffer =
      TokenBuffer(objectMapper, false).use { buffer ->
        program.tokens.forEach { token ->
          when (token.asAntlrToken().tokenType.antlrTokenType) {
            PnfJacksonParser.START_OBJECT -> buffer.writeStartObject()
            PnfJacksonParser.END_OBJECT -> buffer.writeEndObject()
            PnfJacksonParser.START_ARRAY -> buffer.writeStartArray()
            PnfJacksonParser.END_ARRAY -> buffer.writeEndArray()
            PnfJacksonParser.FIELD_NAME -> buffer.writeFieldName(token.lexemeText)
            PnfJacksonParser.VALUE_STRING -> buffer.writeString(token.lexemeText)
            PnfJacksonParser.VALUE_NUMBER_INT -> buffer.writeNumber(token.lexemeText.toInt())
            PnfJacksonParser.VALUE_NUMBER_FLOAT -> buffer.writeNumber(token.lexemeText.toFloat())
            PnfJacksonParser.VALUE_TRUE -> buffer.writeBoolean(true)
            PnfJacksonParser.VALUE_FALSE -> buffer.writeBoolean(false)
            PnfJacksonParser.VALUE_NULL -> buffer.writeNull()
          }
        }
        buffer
      }
  }
}

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
package org.perses.grammar.jackson

import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.dataformat.yaml.YAMLFactory
import com.google.common.truth.Truth.assertThat
import org.antlr.runtime.Token
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ParseTreeUtil
import org.perses.program.TokenizedProgramFactory
import org.perses.program.printer.YamlTokenizedProgramPrinter
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.ReflectionUtil

@RunWith(JUnit4::class)
class JacksonParserFacadeTest {
  private val facade = JacksonParserFacade()

  private val yamlString =
    """|# This is a simple YAML example
      |name: Alice
      |age: 30
      |isStudent: false
      |hobbies:
      |  - reading
      |  - hiking
      |  - coding
      |address:
      |  street: 123 Main St
      |  city: Anytown
      |  zip: "12345" # Zip codes
      |
    """.trimMargin()

  private val sparTreeNodeFactory =
    SparTreeNodeFactory(
      metaTokenInfoDb = facade.metaTokenInfoDb,
      tokenizedProgramFactory = TokenizedProgramFactory.createEmptyFactory(facade.language),
      grammarHierarchy = facade.ruleHierarchy,
    )

  @Test
  fun testSingleString() {
    val yaml = """--- "reading" """
    val objectMapper = ObjectMapper(YAMLFactory())
    val tree = objectMapper.readTree(yaml)
    assertThat(objectMapper.writeValueAsString(tree).trim()).isEqualTo(yaml.trim())
    val result = facade.tokenizeString(yaml)
    assertThat(result.map { it.text }).containsExactly("reading").inOrder()
  }

  @Test
  fun testAntlrBridge() {
    val tokenInfoList =
      JacksonAntlrBridge
        .lexerAtnWrapper.metaTokenInfoDB.tokens
    val lexerClass = JacksonLexer::class.java
    val parserClass = PnfJacksonParser::class.java

    tokenInfoList.forEach { token ->
      val tokenTypeInParser = ReflectionUtil.readStaticField<Int>(parserClass, token.symbolicName)
      assertThat(tokenTypeInParser).isEqualTo(token.tokenType.antlrTokenType)
    }
  }

  @Test
  fun testTokenTypes() {
    assertThat(PnfJacksonParser.START_OBJECT).isEqualTo(1)
    assertThat(PnfJacksonParser.END_OBJECT).isEqualTo(2)
    assertThat(PnfJacksonParser.START_ARRAY).isEqualTo(3)
    assertThat(PnfJacksonParser.END_ARRAY).isEqualTo(4)
    assertThat(PnfJacksonParser.FIELD_NAME).isEqualTo(5)
    assertThat(PnfJacksonParser.VALUE_EMBEDDED_OBJECT).isEqualTo(6)
    assertThat(PnfJacksonParser.VALUE_STRING).isEqualTo(7)
    assertThat(PnfJacksonParser.VALUE_NUMBER_INT).isEqualTo(8)
    assertThat(PnfJacksonParser.VALUE_NUMBER_FLOAT).isEqualTo(9)
    assertThat(PnfJacksonParser.VALUE_TRUE).isEqualTo(10)
    assertThat(PnfJacksonParser.VALUE_FALSE).isEqualTo(11)
    assertThat(PnfJacksonParser.VALUE_NULL).isEqualTo(12)
  }

  @Test
  fun testParse() {
    val tree = facade.parseString(yamlString)
    val tokensFromTree = ParseTreeUtil.getTokens(tree.tree)
    assertThat(tokensFromTree.last().type).isEqualTo(Token.EOF)
    val tokensFromTreeWithoutEOF =
      tokensFromTree
        .subList(
          0,
          tokensFromTree.size - 1,
        ).map { it.text }
    val tokenizedTokens = facade.tokenizeString(yamlString).map { it.text }
    assertThat(tokensFromTreeWithoutEOF).isEqualTo(tokenizedTokens)

    val sparTree =
      SparTreeBuilder(sparTreeNodeFactory = sparTreeNodeFactory, tree, simplifyTree = true)
        .result
    val tokenizedProgram = sparTree.programSnapshot
    tokenizedProgram.tokens.map { it.lexemeText }.let { tokens ->
      assertThat(tokens).isEqualTo(tokensFromTreeWithoutEOF)
    }
    val printer = YamlTokenizedProgramPrinter()
    val yamlOutputFromPrinter = printer.print(tokenizedProgram).sourceCode
    val anotherTokenizedTokens =
      facade
        .tokenizeString(yamlOutputFromPrinter)
        .map { it.text }
    assertThat(anotherTokenizedTokens).isEqualTo(tokenizedTokens)
  }

  @Test
  fun testTokenize() {
    val tokens = facade.tokenizeString(yamlString)
    tokens[0].let {
      assertThat(it.type).isEqualTo(PnfJacksonParser.START_OBJECT)
      assertThat(it.text).isEqualTo("{")
    }
    tokens[1].let {
      assertThat(it.type).isEqualTo(PnfJacksonParser.FIELD_NAME)
      assertThat(it.text).isEqualTo("name")
    }
    tokens[2].let {
      assertThat(it.type).isEqualTo(PnfJacksonParser.VALUE_STRING)
      assertThat(it.text).isEqualTo("Alice")
    }
    tokens[3].let {
      assertThat(it.type).isEqualTo(PnfJacksonParser.FIELD_NAME)
      assertThat(it.text).isEqualTo("age")
    }
    tokens.last().let {
      assertThat(it.type).isEqualTo(PnfJacksonParser.END_OBJECT)
      assertThat(it.text).isEqualTo("}")
    }
  }
}

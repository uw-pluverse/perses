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
package org.perses.grammar.adhoc

import org.perses.antlr.AbstractGrammarStub
import java.nio.file.Path

abstract class AbstractParserFacadeStubTemplate(
  packageName: String,
  parserClassSimpleName: String,
  lexerClassSimpleName: String,
  startRuleName: String,
  val grammarName: String,
  val parserFile: Path,
  val lexerFile: Path?,
  val parserFacadeClassSimpleName: String,
  tokenNamesOfIdentifiers: List<String>,
) : AbstractGrammarStub(
  packageName,
  parserClassSimpleName,
  lexerClassSimpleName,
  startRuleName,
) {

  override fun classSimpleName() = parserFacadeClassSimpleName
  override fun classFullName() = "$packageName.${classSimpleName()}"

  private val createAntlrGrammar = if (lexerFile == null) {
    """createCombinedAntlrGrammar("${parserFile.fileName}", ${classSimpleName()}.class)"""
  } else {
    """createSeparateAntlrGrammar(
        "${parserFile.fileName}", 
        "${lexerFile.fileName}", 
        ${classSimpleName()}.class)"""
  }

  private val identifierTokens = tokenNamesOfIdentifiers
    .asSequence()
    .map { "$lexerClassSimpleName.$it" }
    .joinToString(separator = ", ")
    .let { "com.google.common.primitives.ImmutableIntArray.of($it)" }

  protected val fieldNameLanguage =
    AdhocGrammarConfiguration.ParserFacadeJarFile.FIELD_NAME_LANGUAGE

  override fun generateCode(): String {
    return """
package $packageName;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import com.google.common.io.BaseEncoding;
import org.perses.program.LanguageKind;
import org.perses.program.SerializableLanguageKind;
import org.perses.grammar.AbstractDefaultParserFacade;
  
  
public final class ${classSimpleName()}
  extends AbstractDefaultParserFacade<$lexerClassSimpleName, $parserClassSimpleName> {
  public ${classSimpleName()}() {
    super(
        LANGUAGE,
        $createAntlrGrammar,
        CLASS_LEXER,
        CLASS_PARSER,
        $identifierTokens);
  }

  @Override
  protected $lexerClassSimpleName createLexer(CharStream inputStream) {
    return new $lexerClassSimpleName(inputStream);
  }

  @Override
  protected $parserClassSimpleName createParser(CommonTokenStream tokens) {
    return new $parserClassSimpleName(tokens);
  }

  @Override
  protected ParseTree startParsing($parserClassSimpleName parser) {
    return parser.$startRuleName();
  }
 
  public static LanguageKind $fieldNameLanguage;
  
  ${createLanguageKind()}
  
  public static final Class<$lexerClassSimpleName> CLASS_LEXER = $lexerClassSimpleName.class;
  
  public static final Class<$parserClassSimpleName> CLASS_PARSER = $parserClassSimpleName.class;
}
    """
  }

  protected abstract fun createLanguageKind(): String
}

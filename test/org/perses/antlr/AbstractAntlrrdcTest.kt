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
package org.perses.antlr

import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.deleteRecursively

abstract class AbstractAntlrrdcTest {

  val tempDir: Path = Files.createTempDirectory(javaClass.simpleName)

  val parserGrammarPath = createFile(
    "TestParser.g4",
    """
      parser grammar TestParser;
      options {
          tokenVocab=TestLexer;
      }
      start : ID ID ID + EOF;
    """.trimIndent(),
  )

  val parserWithActions = createFile(
    "TestParserWithActions.g4",
    """
    parser grammar TestParserWithAction;
    options {
      tokenVocab=TestLexer;
    }
    start : ID 
            (ID |{System.out.println("");}) 
            (ID {System.out.println("");}) + {System.out.println("action");} EOF ; 
    """.trimIndent(),
  )

  val parserWithSemanticPredicate: Path = createFile(
    "TestParserWithSemanticPredicate.g4",
    """
    parser grammar TestParserWithSemanticPredicate;
    options {
      tokenVocab=TestLexer;
    }
    start : {true}? ID ID ID + EOF ; 
    """.trimIndent(),
  )

  val parserWithReturns = createFile(
    "TestParserWithReturns.g4",
    """
    parser grammar TestParserWithReturns;
    options {
      tokenVocab=TestLexer;
    }
    start returns [int result] :  ID ID ID + {${'$'}result = 0;} EOF ;       
    """.trimIndent(),
  )

  val parserWithArguments = createFile(
    "TestParserWithArguments.g4",
    """
    parser grammar TestParserWithArguments;
    options {
      tokenVocab=TestLexer;
    }
    start :  sub[1] EOF ; 
    sub[int i]: ID ID ID +; 
    """.trimIndent(),
  )

  val parserWithLabels = createFile(
    "TestParserWithLabels.g4",
    """
    parser grammar TestParserWithLabels;
    options {
      tokenVocab=TestLexer;
    }
    start :  sub[1] EOF ; 
    sub[int i]: arguments=ID (second+=ID)? (name=ID) +; 
    """.trimIndent(),
  )

  val parserWithLocals = createFile(
    "TestParserWithLocals.g4",
    """
    parser grammar TestParserWithLocals;
    options {
      tokenVocab=TestLexer;
    }
    start locals[boolean a = false, boolean b = false]: ID ID ID + EOF ; 
    """.trimIndent(),
  )

  val lexerGrammarPath = createFile(
    "TestLexer.g4",
    """
      lexer grammar TestLexer;
      ID : 'a';
      
      Whitespace : [ \t]+ -> skip;
      
    """.trimIndent(),
  )

  val combinedGrammarPath = createFile(
    "TestCombined.g4",
    """
      grammar TestCombined;
      start : ID;
      ID : 'a';
      Whitespace : [ \t]+ -> skip;
    """.trimIndent(),
  )

  val valid1 = createFile("valid_1.input", "a a a")
  val valid2 = createFile("valid_2.input", "a a a a")
  val invalid1 = createFile("invalid_1.input", "b")
  val invalid2 = createFile("invalid_2.input", "b c ")

  open fun close() {
    tempDir.deleteRecursively()
  }

  fun createFile(fileName: String, fileContent: String): Path {
    val path = tempDir.resolve(fileName)
    check(!Files.exists(path))
    Files.write(path, fileContent.toByteArray(StandardCharsets.UTF_8))
    return path
  }
}

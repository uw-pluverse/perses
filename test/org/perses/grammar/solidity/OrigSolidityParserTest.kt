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
package org.perses.grammar.solidity

import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ExceptionErrorStrategy
import org.perses.grammar.FailOnErrorAntlrErrorListener
import org.perses.grammar.solidity.preprocessed.SolidityLexer
import org.perses.grammar.solidity.preprocessed.SolidityParser
import java.nio.charset.StandardCharsets
import java.nio.file.Path
import java.nio.file.Paths

@RunWith(JUnit4::class)
class OrigSolidityParserTest {

  @Test
  fun test_helloworld() {
    testProgram(
      Paths.get("test/org/perses/benchmark_toys/solidity/hello.sol"),
      enableException = true,
    )
  }

  @Test
  fun test() {
    val parsableFiles = Files.readLines(
      Paths.get("test/org/perses/grammar/solidity/parsable_solidity_programs.txt").toFile(),
      StandardCharsets.UTF_8,
    )
    for (program in parsableFiles) {
      assertThat(testProgram(Paths.get(program), enableException = true)).isTrue()
    }
  }

  fun testProgram(program: Path, enableException: Boolean): Boolean {
    try {
      val lexer = SolidityLexer(CharStreams.fromPath(program, StandardCharsets.UTF_8))
      val tokens = CommonTokenStream(lexer)
      val parser = SolidityParser(tokens)
      parser.removeErrorListeners()
      parser.errorHandler = ExceptionErrorStrategy()
      parser.addErrorListener(FailOnErrorAntlrErrorListener(program.toString()))
      parser.sourceUnit()
      return true
    } catch (e: Throwable) {
      if (enableException) {
        System.err.println("Fail to parse program $program")
        e.printStackTrace()
        throw e
      }
      return false
    }
  }
}

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
package org.perses.antlr.reducer.codegen

import com.google.common.collect.ImmutableList
import com.google.common.collect.Lists
import org.perses.antlr.AbstractGrammarStub
import java.nio.file.Path

class GrammarMainStubTemplate(
  packageName: String,
  parserClassSimpleName: String,
  lexerClassSimpleName: String,
  startRuleName: String,
  val testPrograms: ImmutableList<Path>,
) : AbstractGrammarStub(
  packageName,
  parserClassSimpleName,
  lexerClassSimpleName,
  startRuleName,
) {

  private val partitionedTestPrograms = partitionTestPrograms(testPrograms)

  private val listPopulationCode = StringBuilder().apply {
    for (partition in partitionedTestPrograms) {
      append(
        """
        ${partition.methodName}(result); 
      """,
      )
    }
  }

  override fun classSimpleName() = parserClassSimpleName + "Main"

  override fun classFullName() = "$packageName.${classSimpleName()}"

  override fun generateCode() = """
package $packageName;

import java.nio.file.*;
import java.io.*;
import org.antlr.v4.runtime.*;
import org.perses.grammar.*;
import java.util.*;
import java.nio.charset.*;
import java.nio.file.*;

public class ${classSimpleName()} {
  
  public static void main(String[] args) throws IOException {
    if (args.length != 0) {
      throw new RuntimeException("This program does not accept command-line arguments.");
    }
    final ArrayList<Path> testPrograms = createTestPrograms();
    for (Path testProgram: testPrograms) {
      tryToParse(testProgram);
    }
  }
  
  public static void tryToParse(Path testProgram) throws IOException {
      final $lexerClassSimpleName lexer = new $lexerClassSimpleName(
          CharStreams.fromPath(testProgram, StandardCharsets.UTF_8));
      CommonTokenStream tokens = new CommonTokenStream(lexer);
      final $parserClassSimpleName parser = new $parserClassSimpleName(tokens);
      parser.removeErrorListeners();
      parser.setErrorHandler(new ExceptionErrorStrategy());
      parser.addErrorListener(new FailOnErrorAntlrErrorListener(testProgram.toString()));
      parser.$startRuleName();
  }
  
  private static ArrayList<Path> createTestPrograms() {
    final ArrayList<Path> result = new ArrayList<>();
    $listPopulationCode
    return result;
  }
  ${
    partitionedTestPrograms.asSequence().map {
      it.generateCode()
    }.joinToString("\n")
  }
}
  """

  internal class Partition(
    id: Int,
    val programs: ImmutableList<Path>,
  ) {

    val methodName = "fillTestProgramList_$id"

    fun generateCode(): String {
      return StringBuilder().apply {
        append("private static void $methodName(final ArrayList<Path> list) {\n")
        for (p in programs) {
          append(
            """
            list.add(Paths.get("${p.toAbsolutePath()}"));
           """,
          )
        }
        append("}")
        append("\n")
      }.toString()
    }
  }

  companion object {
    const val MAX_PARTITION_SIZE = 200

    internal fun partitionTestPrograms(list: ImmutableList<Path>): ImmutableList<Partition> {
      val partitions = Lists.partition(list, MAX_PARTITION_SIZE)
      return partitions.withIndex().map {
        Partition(it.index, ImmutableList.copyOf(it.value))
      }.fold(
        ImmutableList.builder<Partition>(),
        { acc, e -> acc.add(e) },
      ).build()
    }
  }
}

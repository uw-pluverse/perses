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
package org.perses.ppr.seed

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.EnumFormatControl
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.io.ReductionFolder
import org.perses.util.ListAlignment
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import kotlin.io.path.deleteRecursively
import kotlin.io.path.exists
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class SeedOutputManagerFactoryTest {

  val tempDir = Files.createTempDirectory(this::class.java.canonicalName)

  // these files are used to initialize reduction folder
  val origSeedFile = SourceFile(
    Files.createFile(tempDir.resolve("seed.c")),
    LanguageC,
  )
  val origVariantFile = SourceFile(
    Files.createFile(tempDir.resolve("variant.c")),
    LanguageC,
  )
  val testScript = ScriptFile(
    Files.createFile(tempDir.resolve("r.sh")).apply {
      this.writeText("#!/usr/bin/env bash")
    },
  )

  val lexerAtnWrapper = LexerAtnWrapper(PnfCLexer::class.java)

  // initialize a reduction folder
  val reductionInputs = SeedReductionInputs(testScript, origSeedFile, origVariantFile)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testWrite() {
    val seedTokens = listOf("static", "int", "a", "=", "1", ";")
    val variantTokens = listOf("static", "int", "a", "=", "2", ";")
    val seedProgram = TestUtility.createTokenizedProgramFromString(
      seedTokens.joinToString(separator = " "),
      LanguageC,
    )
    val variantProgram = TestUtility.createTokenizedProgramFromString(
      variantTokens.joinToString(separator = " "),
      LanguageC,
    )
    val alignment = ListAlignment.create(
      seedProgram.tokens,
      variantProgram.tokens,
      PPRDiffUtils.EQUALIZER_TOKEN,
    )
    val outputManagerFactory = SeedOutputManagerFactory(
      reductionInputs,
      EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      alignment,
      lexerAtnWrapper,
    )

    val seedProgramReduced = TokenizedProgram(
      seedProgram.tokens.subList(1, seedProgram.tokens.size),
      seedProgram.factory,
    )

    val folder = Files.createDirectories(tempDir.resolve("reduction-folder"))
    val reductionFolder = ReductionFolder(
      reductionInputs = reductionInputs,
      folder = folder,
    )

    outputManagerFactory.OutputManager(
      seedProgramReduced,
      PrinterRegistry.getPrinter(EnumFormatControl.SINGLE_TOKEN_PER_LINE),
      alignment,
    ).write(reductionFolder)

    val seedFile = folder.resolve(origSeedFile.baseName)
    assertThat(seedFile.exists()).isTrue()
    assertThat(seedFile.readText(StandardCharsets.UTF_8).trim())
      .isEqualTo(
        """int
        |a
        |=
        |1
        |;
        """.trimMargin(),
      )
    val variantFile = folder.resolve(origVariantFile.baseName)
    assertThat(variantFile.exists()).isTrue()
    assertThat(variantFile.readText(StandardCharsets.UTF_8).trim())
      .isEqualTo(
        """int
        |a
        |=
        |2
        |;
        """.trimMargin(),
      )
  }
}

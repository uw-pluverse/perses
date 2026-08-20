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
package org.perses.grammar

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.makefile.LanguageMakefile
import org.perses.util.transformToImmutableList
import java.nio.file.Path

@RunWith(JUnit4::class)
class ParserFacadeFactoryTest {
  val pnfc = PnfCParserFacade::class
  val optc = CParserFacade::class

  val pnfFactory =
    SingleParserFacadeFactory
      .Builder()
      .add(LanguageC, pnfc)
      .build()

  val optFactory =
    SingleParserFacadeFactory
      .Builder()
      .add(LanguageC, optc)
      .build()

  val pnfBuilintFactory =
    CompositeParserFacadeFactory(
      builtinFactory = pnfFactory,
      extFactory = optFactory,
    )

  val optBuiltinFactory =
    CompositeParserFacadeFactory(
      builtinFactory = optFactory,
      extFactory = pnfFactory,
    )

  @Test
  fun testCompositeFactoryForCreatingFacade() {
    assertThat(
      pnfBuilintFactory.getParserFacadeListForOrNull(LanguageC)!!.defaultParserFacade.create(),
    ).isInstanceOf(
      CParserFacade::class.java,
    )
    assertThat(
      optBuiltinFactory.getParserFacadeListForOrNull(LanguageC)!!.defaultParserFacade.create(),
    ).isInstanceOf(
      PnfCParserFacade::class.java,
    )
  }

  @Test
  fun testComputeLanguageKindWithLanguageNameIgnoreCases() {
    for (name in listOf("c", "C")) {
      assertThat(
        optFactory.computeLanguageKindWithLanguageNameIgnoreCase(name),
      ).isSameInstanceAs(LanguageC)
    }
  }

  @Test
  fun testComputeLanguageKindWithLanguageNameIgnoreCasesForBuiltin() {
    val factory =
      SingleParserFacadeFactory
        .builderWithBuiltinLanguages()
        .build()
    assertThat(factory.computeLanguageKindWithLanguageNameIgnoreCase("java"))
      .isSameInstanceAs(LanguageJava)
    assertThat(factory.computeLanguageKindWithLanguageNameIgnoreCase("JAva"))
      .isSameInstanceAs(LanguageJava)
  }

  @Test
  fun testDetectMakefileByExtensionlessFileName() {
    val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
    // Case-insensitive: a test script may load any casing via `make -f <file>`.
    for (name in listOf("Makefile", "makefile", "GNUmakefile", "MAKEFILE", "MakeFile", "gnumakefile")) {
      assertThat(factory.computeLanguageKindWithFileName(Path.of(name)))
        .isSameInstanceAs(LanguageMakefile)
    }
    assertThat(factory.computeLanguageKindWithFileName(Path.of("build.mk")))
      .isSameInstanceAs(LanguageMakefile)
    assertThat(factory.computeLanguageKindWithLanguageNameIgnoreCase("makefile"))
      .isSameInstanceAs(LanguageMakefile)
  }

  @Test
  fun testExtensionDetectionUnaffectedByFileNameMatching() {
    val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
    // A file with a real extension must still resolve by extension, not be shadowed by file names.
    assertThat(factory.computeLanguageKindWithFileName(Path.of("foo.c")))
      .isSameInstanceAs(LanguageC)
  }

  @Test
  fun testParserFacadeList() {
    val list =
      AbstractParserFacadeFactory.ParserFacadeList.create(
        defaultParserFacade = pnfc,
        otherParserFacades = listOf(optc),
      )
    assertThat(list.numberOfParserFacades()).isEqualTo(2)
    assertThat(list.defaultParserFacade.klass).isEqualTo(pnfc)
    assertThat(list.otherParserFacades.transformToImmutableList { it.klass }).containsExactly(optc)
    assertThat(list.sequenceOfCreators().transformToImmutableList { it.klass })
      .containsExactly(
        pnfc,
        optc,
      ).inOrder()
  }
}

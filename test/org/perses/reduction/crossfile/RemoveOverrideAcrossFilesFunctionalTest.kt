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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.astra.java.RemoveOverrideAcrossFilesTransformation
import org.perses.grammar.java.LanguageJava
import org.perses.program.SourceFile
import org.perses.reduction.io.SourceSpec

/**
 * End-to-end functional test of the cross-file override-removal pass: the real
 * [CrossFileReductionDriver] driving the real [RemoveOverrideAcrossFilesTransformation] over real
 * Java files, gated by a real bash interestingness script. The property keeps both classes but is
 * indifferent to the override family, so the only reduction available is the joint removal of
 * `foo()` from the base and its subclass together -- which no single-file pass can do (deleting the
 * base alone leaves a dangling `@Override`).
 */
@RunWith(JUnit4::class)
class RemoveOverrideAcrossFilesFunctionalTest {
  // The property keeps both classes present but says nothing about foo(), so removing the override
  // family preserves it. The seed already passes, so the driver's sanity check succeeds.
  private val fixture =
    CrossFileReductionTestData(
      javaClass,
      scriptBody = "grep -q 'class Base' Base.java && grep -q 'class Derived' Derived.java",
      SourceSpec(
        "Base.java",
        """
        public class Base {
          void foo() {}
        }
        """.trimIndent(),
        LanguageJava,
      ),
      SourceSpec(
        "Derived.java",
        """
        public class Derived extends Base {
          @Override
          void foo() {}
        }
        """.trimIndent(),
        LanguageJava,
      ),
    )
  private val base: SourceFile = fixture.mutableFile("Base.java")
  private val derived: SourceFile = fixture.mutableFile("Derived.java")
  private val driver =
    fixture.createDriver(ImmutableList.of(RemoveOverrideAcrossFilesTransformation()))

  @After
  fun teardown() {
    fixture.close()
  }

  @Test
  fun testRemovesTheOverrideFamilyAcrossFiles() {
    driver.reduce()

    val reducedBase = fixture.ioManager.resultFolder.readFileContent(base)
    val reducedDerived = fixture.ioManager.resultFolder.readFileContent(derived)

    // The override family `foo()` is gone from both files in a single joint edit...
    assertThat(reducedBase).doesNotContain("foo")
    assertThat(reducedDerived).doesNotContain("foo")
    // ...while the property -- both classes still present -- is preserved.
    assertThat(reducedBase).contains("class Base")
    assertThat(reducedDerived).contains("class Derived")
  }
}

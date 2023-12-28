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
package org.perses.util

import com.google.common.collect.Interners
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.FileNameContentPair.Companion.locateFirstNonBlankLine
import org.perses.util.FileNameContentPair.Companion.locateLastNonBlankLine
import org.perses.util.FileNameContentPair.Companion.trimWhitespaces
import java.nio.file.Files
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class FileNameContentPairTest {

  val tempDir = Files.createTempDirectory(javaClass.simpleName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testLocateFirstNonBlankLine() {
    assertThat(locateFirstNonBlankLine(listOf())).isEqualTo(0)
    assertThat(locateFirstNonBlankLine(listOf("   ", "a"))).isEqualTo(1)
    assertThat(locateFirstNonBlankLine(listOf(" ", "", "", "a"))).isEqualTo(3)
    assertThat(locateFirstNonBlankLine(listOf("", " a"))).isEqualTo(1)
  }

  @Test
  fun testLocateLastNonBlankLineFromRear() {
    assertThat(locateLastNonBlankLine(listOf())).isEqualTo(-1)
    assertThat(locateLastNonBlankLine(listOf(""))).isEqualTo(-1)
    assertThat(locateLastNonBlankLine(listOf("a", ""))).isEqualTo(0)
    assertThat(locateLastNonBlankLine(listOf("", "a", ""))).isEqualTo(1)
  }

  @Test
  fun testTrimWhitespaces() {
    assertThat(trimWhitespaces(listOf())).isEmpty()
    assertThat(trimWhitespaces(listOf(" a "))).containsExactly("a").inOrder()
    assertThat(trimWhitespaces(listOf("", " a ", ""))).containsExactly("a").inOrder()
    assertThat(
      trimWhitespaces(listOf("", " a", "", "b ", "")),
    ).containsExactly("a", "", "b").inOrder()
  }

  @Test
  fun testEquality() {
    val p1 = FileNameContentPair.createFromString(fileName = "a.txt", content = "a")
    val p2 = FileNameContentPair.createFromString(fileName = "a.txt", content = "a")
    assertThat(p1).isEqualTo(p2)

    val map = HashSet<FileNameContentPair>()
    map.add(p1)
    map.add(p2)
    assertThat(map).containsExactly(p1)
    assertThat(map).containsExactly(p2)
    assertThat(map).hasSize(1)
  }

  @Test
  fun testIntern() {
    val interner = Interners.newWeakInterner<String>()
    val orig = FileNameContentPair.createFromString(fileName = "a", content = "b")
    val copy1 = orig.createInternedCopy(interner)
    val copy2 = orig.createInternedCopy(interner)
    assertThat(orig).isEqualTo(copy1)
    assertThat(orig).isEqualTo(copy2)
    assertThat(copy1.fileName).isSameInstanceAs(copy2.fileName)
    assertThat(copy1.lines.first()).isSameInstanceAs(copy2.lines.first())
  }

  @Test
  fun testInequality() {
    val p1 = FileNameContentPair.createFromString("a.txt", content = "a")
    val p2 = FileNameContentPair.createFromString("a.txt", "b")
    assertThat(p1).isNotEqualTo(p2)
    val p3 = FileNameContentPair.createFromString("b.txt", "a")
    assertThat(p1).isNotEqualTo(p3)
  }

  @Test
  fun testWrite() {
    val pair = FileNameContentPair.createFromString("a.txt", "b")
    val path = tempDir.resolve("subdir")
    Files.createDirectories(path)
    pair.writeToDirectory(path)
    val file = path.resolve("a.txt")
    val actualContent = file.readText()
    assertThat(actualContent).isEqualTo("b")
  }

  @Test
  fun testRead() {
    val file = tempDir.resolve("a.txt")
    file.writeText("b")
    val pair = FileNameContentPair.createFromFile(file)
    assertThat(pair.fileName).isEqualTo("a.txt")
    assertThat(pair.lines).containsExactly("b").inOrder()
  }
}

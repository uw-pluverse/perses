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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util.NonEmptyInternal
import org.perses.util.Util.SpaceSize
import org.perses.util.Util.computeDifference
import org.perses.util.Util.computePercentage
import org.perses.util.Util.createAppendablePrintStream
import org.perses.util.Util.createNonAppendablePrintStream
import org.perses.util.Util.ensureDirExists
import org.perses.util.Util.globWithFileNameExts
import org.perses.util.Util.hashListOfStrings
import org.perses.util.Util.isEmptyDirectory
import org.perses.util.Util.lazyAssert
import org.perses.util.Util.mergeContinuousElementsIntoRegions
import org.perses.util.Util.removeElementBySwappingLastElement
import org.perses.util.Util.removeElementsFromLinkedList
import org.perses.util.Util.removeElementsFromList
import org.perses.util.Util.removeNullFromList
import org.perses.util.Util.setExecutable
import org.perses.util.Util.slideResverseIfSlidable
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.util.LinkedList
import java.util.function.Predicate
import kotlin.io.path.deleteRecursively
import kotlin.io.path.exists
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class UtilTest {

  private var tempDir: Path = Files.createTempDirectory("UtilTest_")

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testExceptionOutputStream() {
    assertThrows(Throwable::class.java) {
      Util.ExceptionOutputStream.write(1)
    }
    assertThrows(Throwable::class.java) {
      Util.ExceptionPrintStream.println()
    }
  }

  @Test
  fun testCreateAppendablePrintStream() {
    val file = tempDir.resolve("a.txt")
    createAppendablePrintStream(file).use { it.print("a") }
    createAppendablePrintStream(file).use { it.print("b") }
    assertThat(file.readText()).isEqualTo("ab")
  }

  @Test
  fun testCreateNonAppendablePrintStream() {
    val file = tempDir.resolve("a.txt")
    createNonAppendablePrintStream(file).use { it.print("a") }
    createNonAppendablePrintStream(file).use { it.print("b") }
    assertThat(file.readText()).isEqualTo("b")
  }

  @Test
  fun testRemoveNullFromList() {
    run {
      val list = ArrayList<Int?>()
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(0)
      list.add(1)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(1)
      list.add(null)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(1)
      list.add(null)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(1)
      list[0] = null
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(0)
    }
    run {
      val list = ArrayList<Int?>()
      list.add(1)
      list.add(2)
      list.add(3)
      list.add(4)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(4)
      list[1] = null
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(3)
    }
  }

  @Test
  fun testRemoveElementBySwappingLastElement() {
    val list = ArrayList<Int>()
    run {
      list.clear()
      list.add(1)
      removeElementBySwappingLastElement(list, 0)
      assertThat(list.size).isEqualTo(0)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementBySwappingLastElement(list, 0)
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementBySwappingLastElement(list, 1)
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(1)
    }
  }

  @Test
  fun testRemoveElementsFromLinkedList() {
    val list = LinkedList<Int>()
    run {
      list.clear()
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(0)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(2)
      assertThat(list[0]).isEqualTo(2)
      assertThat(list[1]).isEqualTo(2)
    }
  }

  @Test
  fun testRemoveElementsFromList() {
    val list = ArrayList<Int>()
    run {
      list.clear()
      list.add(1)
      removeElementsFromList(list) { _, element -> element == 1 }
      assertThat(list.size).isEqualTo(0)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(2)
      assertThat(list[0]).isEqualTo(2)
      assertThat(list[1]).isEqualTo(2)
    }
  }

  @Test
  fun testComputePercentage() {
    assertThat(computePercentage(100, 100)).isEqualTo("100.00%")
    assertThat(computePercentage(50, 100)).isEqualTo("50.00%")
    assertThat(computePercentage(2525, 10000)).isEqualTo("25.25%")
  }

  @Test
  fun testIsEmptyDirectory() {
    assertThat(isEmptyDirectory(tempDir)).isTrue()
    Files.createFile(tempDir.resolve("temp.txt"))
    assertThat(isEmptyDirectory(tempDir)).isFalse()
  }

  @Test
  fun testEnsureDirExistsForNewFile() {
    val folder = tempDir.resolve("temp")
    assertThat(Files.isDirectory(folder)).isFalse()
    assertThat(Files.isDirectory(ensureDirExists(folder))).isTrue()
    assertThat(Files.isDirectory(ensureDirExists(folder))).isTrue()
  }

  @Test
  fun testEnsureDirExistsExceptionCase() {
    Files.createFile(tempDir.resolve("a"))
    val folder = tempDir.resolve("a")
    val exception = assertThrows(Exception::class.java) {
      ensureDirExists(folder)
    }
    assertThat(exception.message).startsWith("Fail")
  }

  @Test
  fun testSetExecutable() {
    val tempFile = Files.createFile(tempDir.resolve("temp.sh"))
    assertThat(Files.isExecutable(tempFile)).isFalse()
    setExecutable(tempFile)
    assertThat(Files.isExecutable(tempFile)).isTrue()
  }

  @Test
  fun testGlobFiles() {
    Files.createFile(tempDir.resolve("a.c"))
    Files.createFile(tempDir.resolve("b.c"))
    Files.createFile(tempDir.resolve("a.java"))

    val dir1 = Files.createDirectories(tempDir.resolve("dir1"))
    Files.createFile(dir1.resolve("dir1.java"))
    Files.createFile(dir1.resolve("dir1.c"))

    val dir2 = Files.createDirectories(tempDir.resolve("dir2"))
    Files.createFile(dir2.resolve("dir2.java"))
    Files.createFile(dir2.resolve("dir2.c"))

    globWithFileNameExts(tempDir, ".c")
      .map { it.fileName.toString() }
      .let {
        assertThat(it).containsExactly("a.c", "b.c", "dir1.c", "dir2.c")
      }

    globWithFileNameExts(tempDir, ".java")
      .map { it.fileName.toString() }
      .toList()
      .let {
        assertThat(it).containsExactly("a.java", "dir1.java", "dir2.java")
      }

    globWithFileNameExts(tempDir, ".rs").let {
      assertThat(it).isEmpty()
    }

    Util.globWithRegex(tempDir, Regex("^.*\\.java${"$"}")).let {
      assertThat(it.map { it.fileName.toString() }).containsExactly(
        "a.java",
        "dir1.java",
        "dir2.java",
      )
    }
  }

  @Test
  fun testReplaceFileExtSingleFileName() {
    val orig = "a.txt"
    val new = Util.replaceFileExtension(orig, "exe")
    assertThat(new).isEqualTo("a.exe")
  }

  @Test
  fun testReplaceFileExtLongFileName() {
    val orig = "a/b/c.txt"
    val new = Util.replaceFileExtension(orig, "exec")
    assertThat(new).isEqualTo("a/b/c.exec")
  }

  @Test
  fun testComputeSha512ForString() {
    val string = "hello"
    val sha512 = Util.SHA512HashCode.createFromString(string)
    assertThat(sha512.numOfStrings).isEqualTo(1)
    assertThat(sha512.getLengthOfString(0)).isEqualTo(string.length)
    assertThat(sha512.digest.toString()).isEqualTo(
      "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caa" +
        "dae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043",
    )
  }

  @Test
  fun testComputeShaForListOfStrings() {
    val list = listOf(
      hashListOfStrings(emptyList()),
      hashListOfStrings(listOf("")),
      hashListOfStrings(listOf("", "")),
      hashListOfStrings(listOf("ab", "")),
      hashListOfStrings(listOf("", "ab")),
      hashListOfStrings(listOf("", "", "")),
      hashListOfStrings(listOf("a", "")),
      hashListOfStrings(listOf("", "a")),
    )
    assertThat(list.toSet()).containsExactlyElementsIn(list)
    assertThat(list.toSet().size).isEqualTo(list.size)
  }

  @Test
  fun testComputeZIP() {
    val input = "int\n".repeat(100000) // mimic large input
    val zipBArray = Util.zipCompress(input)
    assertThat(String(Util.zipDecompress(zipBArray), Charsets.UTF_8)).isEqualTo(input)
  }

  @Test
  fun testVisitDifference() {
    // TODO: test it here.
    val superList = listOf("a", "b", "c", "d")
    val a = superList[0]
    val b = superList[1]
    val c = superList[2]
    val d = superList[3]

    assertThat(computeDifference(superList, listOf(a))).containsExactly(b, c, d).inOrder()
    assertThat(computeDifference(superList, listOf())).containsExactly(a, b, c, d).inOrder()
    assertThat(computeDifference(superList, listOf(b))).containsExactly(a, c, d).inOrder()
    assertThat(computeDifference(superList, listOf(c))).containsExactly(a, b, d).inOrder()
    assertThat(computeDifference(superList, listOf(b, d))).containsExactly(a, c).inOrder()
  }

  private val euqalizer = { a: Int, b: Int -> a == b }

  @Test
  fun testMergeContinuousElementsIntoRegionsEmpty() {
    val list = mergeContinuousElementsIntoRegions(listOf(), euqalizer)
    assertThat(list).isEmpty()
  }

  private fun testmergeContinuousElementsIntoRegions(
    list: List<Int>,
    vararg expected: ImmutableList<Int>,
  ) {
    assertThat(mergeContinuousElementsIntoRegions(list, euqalizer))
      .containsExactly(*expected).inOrder()
  }

  @Test
  fun test_mergeContinuousElementsIntoRegions_distinct() {
    testmergeContinuousElementsIntoRegions(listOf(1), ImmutableList.of(1))
    testmergeContinuousElementsIntoRegions(listOf(1, 2), ImmutableList.of(1), ImmutableList.of(2))
    testmergeContinuousElementsIntoRegions(
      listOf(1, 2, 3),
      ImmutableList.of(1),
      ImmutableList.of(2),
      ImmutableList.of(3),
    )
  }

  @Test
  fun test_mergeContinuousElementsIntoRegions_duplicate() {
    testmergeContinuousElementsIntoRegions(listOf(1, 1), ImmutableList.of(1, 1))
    testmergeContinuousElementsIntoRegions(
      listOf(1, 1, 2),
      ImmutableList.of(1, 1),
      ImmutableList.of(2),
    )
    testmergeContinuousElementsIntoRegions(
      listOf(1, 1, 2, 2, 1, 1),
      ImmutableList.of(1, 1),
      ImmutableList.of(2, 2),
      ImmutableList.of(1, 1),
    )
    testmergeContinuousElementsIntoRegions(
      listOf(1, 2, 2),
      ImmutableList.of(1),
      ImmutableList.of(2, 2),
    )
  }

  private fun testSlideReverse(
    list: List<Int>,
    slidingWindowSize: Int,
    vararg expected: NonEmptyInternal,
  ) {
    val copy = ArrayList<NonEmptyInternal>()
    slideResverseIfSlidable(list, slidingWindowSize) {
      copy.add(it)
    }
    assertThat(copy).containsExactly(*expected)
  }

  @Test
  fun test_slideReverse_invalid() {
    assertThrows(Throwable::class.java) {
      slideResverseIfSlidable(listOf<Int>(), 0) { }
    }
  }

  @Test
  fun test_slideReverse_size_1() {
    val list = listOf(1)
    testSlideReverse(list, slidingWindowSize = 1, NonEmptyInternal(0, 1))
    testSlideReverse(list, slidingWindowSize = 2)
  }

  @Test
  fun test_slideReverse_size_2() {
    val list = listOf(1, 2)
    testSlideReverse(list, 1, NonEmptyInternal(1, 2), NonEmptyInternal(0, 1))
    testSlideReverse(list, 2, NonEmptyInternal(0, 2))
    testSlideReverse(list, 3)
  }

  @Test
  fun test_slideReverse_size_3() {
    val list = listOf(1, 2, 3)
    testSlideReverse(
      list,
      1,
      NonEmptyInternal(2, 3),
      NonEmptyInternal(1, 2),
      NonEmptyInternal(0, 1),
    )
    testSlideReverse(
      list,
      2,
      NonEmptyInternal(1, 3),
      NonEmptyInternal(0, 2),
    )
    testSlideReverse(
      list,
      3,
      NonEmptyInternal(0, 3),
    )
    testSlideReverse(list, 4)
  }

  @Test
  fun testCreateDirsAndWriteText() {
    val file = tempDir.resolve("a/b/c/d/e.txt")
    Util.createDirsAndWriteText(file, "hello")
    assertThat(file.readText()).isEqualTo("hello")
  }

  @Test
  fun testCopyResource() {
    val text = DummyClassWithResource.read()
    assertThat(text).isEqualTo("test")
    val dest = tempDir.resolve("dest.txt")
    Util.copyResource("test_data.txt", DummyClassWithResource::class.java, dest)
    assertThat(Files.isRegularFile(dest)).isTrue()
    assertThat(dest.readText()).isEqualTo("test")
  }

  @Test
  fun lazyAssertionShouldThrow() {
    assertThrows(Throwable::class.java) {
      lazyAssert { false }
    }
    val goldenMessage = "this is the golden message"
    val exception = assertThrows(Throwable::class.java) {
      lazyAssert({ false }) { goldenMessage }
    }
    assertThat(exception.message).contains(goldenMessage)
  }

  @Test
  fun test_copyFileToDirectory() {
    val srcFilePath = Files.createTempFile(tempDir, "test_copy_file", ".txt").also {
      it.writeText("test content", StandardCharsets.UTF_8)
    }
    val destDir = Files.createTempDirectory(tempDir, "test_copy_file")
    val destFilePath = Util.copyFileToDirectory(srcFilePath, destDir)

    // Verify the new file exists in the working directory,
    // and its content is same as the original file
    assertThat(destFilePath.exists()).isTrue()
    assertThat(srcFilePath.readText(StandardCharsets.UTF_8)).isEqualTo(
      destFilePath.readText(StandardCharsets.UTF_8),
    )
  }

  @Test
  fun testCopyFileToDirectoryThrow() {
    val originalFile = Files.createTempFile(tempDir, "test_copy_file", ".txt").also {
      it.writeText("test content", StandardCharsets.UTF_8)
    }
    val exception = assertThrows(IllegalArgumentException::class.java) {
      Util.copyFileToDirectory(originalFile, tempDir)
    }
    assertThat(exception.message)
      .contains("Destination path cannot be the same as the original path.")
  }

  @Test
  fun testAtomicSequenceGenerator() {
    val g = Util.AtomicSequenceGenerator(minLengthForPadding = 2)
    (1..9).forEach {
      assertThat(g.next()).isEqualTo("0$it")
    }
    assertThat(g.next()).isEqualTo("10")
    assertThat(g.next()).isEqualTo("11")
  }

  @Test
  fun testSpaceSize() {
    SpaceSize(bytes = 1000).let {
      assertThat(it.bytes).isEqualTo(1000)
    }
    SpaceSize.kiloBytes(kb = 1).let {
      assertThat(it.bytes).isEqualTo(1000)
    }
    SpaceSize.megaBytes(mb = 1).let {
      assertThat(it.bytes).isEqualTo(1000 * 1000)
    }
  }
}

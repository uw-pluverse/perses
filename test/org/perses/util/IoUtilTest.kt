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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.IoUtil.createAppendablePrintStream
import org.perses.util.IoUtil.createNonAppendablePrintStream
import java.io.Closeable
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class IoUtilTest {
  private var tempDir: Path = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testExceptionOutputStream() {
    assertThrows(Throwable::class.java) {
      IoUtil.ExceptionOutputStream.write(1)
    }
    assertThrows(Throwable::class.java) {
      IoUtil.ExceptionPrintStream.println()
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
  fun testComputeZIP() {
    val input = "int\n".repeat(100000) // mimic large input
    val zipBArray = IoUtil.compressStringToZipByteArray(input)
    assertThat(
      String(IoUtil.decompressZipByteArray(zipBArray), StandardCharsets.UTF_8),
    ).isEqualTo(input)
  }

  @Test
  fun testCopyResource() {
    val text = DummyClassWithResource.read()
    assertThat(text).isEqualTo("test")
    val dest = tempDir.resolve("dest.txt")
    // Load from the JAR root; see DummyClassWithResource for the reasoning.
    IoUtil.copyResource("/test_data.txt", DummyClassWithResource::class.java, dest)
    assertThat(Files.isRegularFile(dest)).isTrue()
    assertThat(dest.readText()).isEqualTo("test")
  }

  class FakeCloseable(
    var closed: Boolean = false,
  ) : Closeable {
    override fun close() {
      closed = true
    }
  }

  @Test
  fun testUseBoth() {
    val a = FakeCloseable()
    val b = FakeCloseable()

    IoUtil.useResources({ a }, { b }) { localA, localB ->
      assertThat(localA.closed).isFalse()
      assertThat(localB.closed).isFalse()
    }
    assertThat(a.closed).isTrue()
    assertThat(b.closed).isTrue()
  }

  @Test
  fun testUseThree() {
    val a = FakeCloseable()
    val b = FakeCloseable()
    val c = FakeCloseable()
    IoUtil.useResources(
      { a },
      { b },
      { _, _ -> c },
    ) { localA, localB, localC ->
      assertThat(localA.closed).isFalse()
      assertThat(localB.closed).isFalse()
      assertThat(localC.closed).isFalse()
    }
    assertThat(a.closed).isTrue()
    assertThat(b.closed).isTrue()
    assertThat(c.closed).isTrue()
  }
}

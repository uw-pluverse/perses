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
package org.perses.reduction.cache

import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.objectweb.asm.ClassReader
import org.objectweb.asm.ClassVisitor
import org.objectweb.asm.util.Textifier
import org.objectweb.asm.util.TraceClassVisitor
import java.io.PrintWriter
import java.io.StringWriter

@RunWith(JUnit4::class)
class LogicalSizedArrayTest {

  @Test
  fun testEmptyLogicalSizedArray() {
    val empty = LogicalSizedArray.createWithSize(0)
    assertThat(empty.maxLogicalSize).isEqualTo(0)
    assertThat(empty.logicalSize).isEqualTo(empty.maxLogicalSize)
    assertThrows(Throwable::class.java) {
      empty.logicalSize = 1
    }
    assertThrows(Throwable::class.java) {
      empty[0] = 1
    }
    assertThrows(Throwable::class.java) {
      empty[0].let {
        print(it)
      }
    }
  }

  @Test
  fun testOneElementLogicalSizedArray() {
    val one = LogicalSizedArray.createWithSize(1)
    assertThat(one.logicalSize).isEqualTo(1)
    assertThat(one.logicalSize).isEqualTo(one.maxLogicalSize)

    assertThat(one[0]).isEqualTo(0)
    one[0] = 1
    assertThat(one[0]).isEqualTo(1)
    assertThrows(Throwable::class.java) {
      one[1] = 0
    }

    one.logicalSize = 0
    assertThrows(Throwable::class.java) {
      one[0] = 1
    }
  }

  @Test
  fun testTwoElementsLogicalSizedArray() {
    val two = LogicalSizedArray.createWithSize(2)
    assertThat(two.logicalSize).isEqualTo(2)
    assertThat(two.logicalSize).isEqualTo(two.maxLogicalSize)
    assertThat(two[0]).isEqualTo(0)
    assertThat(two[0]).isEqualTo(0)
    two[0] = 1
    two[1] = 2
    assertThat(two[0]).isEqualTo(1)
    assertThat(two[1]).isEqualTo(2)

    two.logicalSize = 1
    assertThat(two.logicalSize).isEqualTo(1)
    assertThat(two[0]).isEqualTo(1)
    assertThrows(Throwable::class.java) {
      two[1]
    }
  }

  @Test
  fun testAllMethodsAreInlined() {
    val stringWriter = StringWriter()
    val flags = 0
    val nullClassVisitor: ClassVisitor? = null
    PrintWriter(stringWriter).use {
      ClassReader(this::class.java.canonicalName).accept(
        TraceClassVisitor(nullClassVisitor, Textifier(), it),
        flags,
      )
    }
    val classContent = stringWriter.toString()
    val assembly = classContent.lines().filter {
      it.trim().lowercase().startsWith("invoke")
    }.filter {
      // make sure no calls to any methods in LogicalSizedArray.
      it.contains(Regex("\\b" + LogicalSizedArray::class.java.simpleName + "\\b"))
    }.distinct()
    assertWithMessage(classContent).that(assembly).hasSize(1)
    assertWithMessage(classContent).that(assembly.single()).contains(".constructor")
  }
}

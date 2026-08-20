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
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.ReflectionUtil.readStaticField

@RunWith(JUnit4::class)
class ReflectionUtilTest {
  class NormalClass {
    companion object {
      @JvmField
      val primitiveInt = 1

      @JvmField
      val string = "string"
    }
  }

  enum class EnumClass {
    A,
    B,
    C,
  }

  @Test
  fun testReadStaticField() {
    NormalClass::class.java.let {
      assertThat(readStaticField<Int>(it, "primitiveInt")).isEqualTo(1)
      assertThat(readStaticField<String>(it, "string")).isEqualTo("string")
    }
    EnumClass::class.java.let {
      assertThat(readStaticField<EnumClass>(it, "A")).isEqualTo(EnumClass.A)
      assertThat(readStaticField<EnumClass>(it, "B")).isEqualTo(EnumClass.B)
    }
  }

  @Test
  fun testIsInitialized() {
    class TestClass {
      val nonLazyProp = "hello"
      var initialized = false
      val lazyProp by lazy {
        initialized = true
        "world"
      }
    }

    val testObj = TestClass()

    assertThat(ReflectionUtil.isInitialized(testObj::nonLazyProp)).isTrue()

    val propRef = testObj::lazyProp
    assertThat(ReflectionUtil.isInitialized(propRef)).isFalse()
    assertThat(testObj.initialized).isFalse()

    assertThat(testObj.lazyProp).isEqualTo("world")
    assertThat(ReflectionUtil.isInitialized(propRef)).isTrue()
    assertThat(testObj.initialized).isTrue()
  }
}

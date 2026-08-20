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

import java.lang.reflect.Modifier
import kotlin.reflect.KProperty0
import kotlin.reflect.jvm.isAccessible

object ReflectionUtil {
  @Suppress("UNCHECKED_CAST")
  fun <T : Any> readStaticField(
    klass: Class<*>,
    fieldName: String,
  ): T = klass.getField(fieldName).get(null) as T

  fun hasStaticFiled(
    klass: Class<*>,
    fieldName: String,
  ): Boolean {
    val field = klass.fields.find { it.name == fieldName }
    return field != null && Modifier.isStatic(field.modifiers)
  }

  @JvmStatic
  fun isInitialized(property: KProperty0<*>): Boolean {
    val originalState = property.isAccessible
    property.isAccessible = true
    val delegate = property.getDelegate()
    val result =
      if (delegate is Lazy<*>) {
        delegate.isInitialized()
      } else {
        true
      }
    property.isAccessible = originalState
    return result
  }
}

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
package org.perses.util.cmd

import com.beust.jcommander.Parameter
import com.fasterxml.jackson.annotation.JsonIgnore

abstract class AbstractCommandLineFlagGroup(
  val groupName: String,
  @JsonIgnore
  val hidden: Boolean = false,
) {
  abstract fun validate()

  fun copyParameterValuesFrom(other: AbstractCommandLineFlagGroup) {
    // We walk up the class hierarchy and use `declaredFields` instead of `getFields()`
    // because `getFields()` only returns public fields. In Kotlin, many fields
    // are private at the bytecode level unless annotated with `@JvmField`.
    fun getAllParameterFields(clazz: Class<*>): List<java.lang.reflect.Field> {
      val fields = mutableListOf<java.lang.reflect.Field>()
      var current: Class<*>? = clazz
      while (current != null && current != AbstractCommandLineFlagGroup::class.java) {
        fields.addAll(
          current.declaredFields.filter {
            it.isAnnotationPresent(Parameter::class.java)
          },
        )
        current = current.superclass
      }
      return fields
    }

    val myFields = getAllParameterFields(this.javaClass)
    val otherFields = getAllParameterFields(other.javaClass)

    myFields.forEach { field ->
      val otherField =
        otherFields.find { it.name == field.name }
          ?: error(
            "Corresponding parameter field '${field.name}' not found in the other flag group '${other.groupName}'.",
          )

      @Suppress("DEPRECATION")
      val originalAccessible = field.isAccessible

      @Suppress("DEPRECATION")
      val originalOtherAccessible = otherField.isAccessible
      try {
        field.isAccessible = true
        otherField.isAccessible = true
        field.set(this, otherField.get(other))
      } finally {
        @Suppress("DEPRECATION")
        field.isAccessible = originalAccessible
        @Suppress("DEPRECATION")
        otherField.isAccessible = originalOtherAccessible
      }
    }
  }
}

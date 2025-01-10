/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import com.fasterxml.jackson.core.JsonGenerator
import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.databind.SerializerProvider
import com.fasterxml.jackson.databind.module.SimpleModule
import com.fasterxml.jackson.databind.ser.std.StdSerializer
import com.fasterxml.jackson.dataformat.yaml.YAMLFactory
import com.fasterxml.jackson.module.kotlin.registerKotlinModule
import java.nio.file.Path
import kotlin.io.path.readText
import kotlin.io.path.writeText

object YamlUtil {

  @JvmStatic
  fun toYamlString(value: Any, objectMapperCustomizer: (ObjectMapper) -> Unit = {}): String {
    val mapper = ObjectMapper(YAMLFactory())
    objectMapperCustomizer(mapper)
    return mapper.writeValueAsString(value)
  }

  @JvmStatic
  fun customizeObjectMapperByUsingBasenameForPath(it: ObjectMapper) {
    val module = SimpleModule()
    module.addSerializer(
      Path::class.java,
      object : StdSerializer<Path>(Path::class.java) {
        override fun serialize(path: Path?, generator: JsonGenerator, p2: SerializerProvider) {
          // Only write the basename for a path object.
          generator.writeString(path?.fileName.toString())
        }
      },
    )
    it.registerModule(module)
  }

  @JvmStatic
  fun toYamlFile(value: Any, destination: Path) {
    destination.writeText(toYamlString(value))
  }

  @JvmStatic
  fun <T> fromYamlString(yaml: String, klass: Class<T>): T {
    val mapper = ObjectMapper(YAMLFactory()).registerKotlinModule()
    mapper.findAndRegisterModules()
    return mapper.readValue(yaml, klass)
  }

  @JvmStatic
  fun <T> fromYamlFile(yaml: Path, klass: Class<T>): T {
    return fromYamlString(yaml.readText(), klass)
  }

  fun <T> deepCopy(value: T, klass: Class<T>): T {
    val mapper = ObjectMapper().registerKotlinModule()
    val jsonString = mapper.writeValueAsString(value)
    return mapper.readValue(jsonString, klass)
  }
}

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

import com.fasterxml.jackson.core.JsonGenerator
import com.fasterxml.jackson.core.StreamReadConstraints
import com.fasterxml.jackson.core.type.TypeReference
import com.fasterxml.jackson.databind.ObjectMapper
import com.fasterxml.jackson.databind.SerializerProvider
import com.fasterxml.jackson.databind.module.SimpleModule
import com.fasterxml.jackson.databind.ser.std.StdSerializer
import com.fasterxml.jackson.dataformat.yaml.YAMLFactory
import com.fasterxml.jackson.datatype.guava.GuavaModule
import com.fasterxml.jackson.module.kotlin.registerKotlinModule
import com.google.common.collect.ImmutableList
import org.yaml.snakeyaml.LoaderOptions
import java.nio.file.Path
import kotlin.io.path.readText
import kotlin.io.path.writeText

object Serialization {
  val TYPE_REFERENCE_LIST_OF_STRINGS = object : TypeReference<ImmutableList<String>>() {}

  @JvmStatic
  fun toYamlString(
    value: Any,
    yamlFactoryCustomizer: (YAMLFactory) -> Unit = {},
    objectMapperCustomizer: (ObjectMapper) -> Unit = {},
  ): String {
    val yamlFactory = createYamlFactory()
    yamlFactoryCustomizer.invoke(yamlFactory)
    val mapper = ObjectMapper(yamlFactory)
    mapper.registerKotlinModule()
    mapper.registerModule(GuavaModule())
    objectMapperCustomizer(mapper)
    return mapper.writeValueAsString(value)
  }

  @JvmStatic
  fun customizeObjectMapperByUsingBasenameForPath(it: ObjectMapper) {
    val module = SimpleModule()
    module.addSerializer(
      Path::class.java,
      object : StdSerializer<Path>(Path::class.java) {
        override fun serialize(
          path: Path?,
          generator: JsonGenerator,
          p2: SerializerProvider,
        ) {
          // Only write the basename for a path object.
          generator.writeString(path?.fileName.toString())
        }
      },
    )
    it.registerModule(module)
  }

  @JvmStatic
  fun toYamlFile(
    value: Any,
    destination: Path,
  ) {
    destination.writeText(toYamlString(value))
  }

  @JvmStatic
  fun <T> fromYamlString(
    yaml: String,
    typeReference: TypeReference<T>,
  ): T {
    val mapper = ObjectMapper(createYamlFactory()).registerKotlinModule()
    mapper.findAndRegisterModules()
    return mapper.readValue(yaml, typeReference)
  }

  @JvmStatic
  fun <T> fromYamlFile(
    yaml: Path,
    typeReference: TypeReference<T>,
  ): T = fromYamlString(yaml.readText(), typeReference)

  @JvmStatic
  fun toJsonString(
    value: Any,
    objectMapperCustomizer: (ObjectMapper) -> Unit = {},
  ): String {
    val mapper = ObjectMapper()
    objectMapperCustomizer(mapper)
    return mapper.writeValueAsString(value)
  }

  @JvmStatic
  fun toJsonFile(
    value: Any,
    destination: Path,
  ) {
    destination.writeText(toJsonString(value))
  }

  @JvmStatic
  fun <T> fromJsonFile(
    json: Path,
    typeReference: TypeReference<T>,
  ): T = fromJsonString(json.readText(), typeReference)

  @JvmStatic
  fun <T> fromJsonString(
    json: String,
    typeReference: TypeReference<T>,
  ): T {
    val mapper = ObjectMapper().registerKotlinModule()
    mapper.findAndRegisterModules()
    return mapper.readValue(json, typeReference)
  }

  fun <T> deepCopy(
    value: T,
    klass: Class<T>,
  ): T {
    val mapper = ObjectMapper().registerKotlinModule()
    val jsonString = mapper.writeValueAsString(value)
    return mapper.readValue(jsonString, klass)
  }

  private fun createYamlFactory(): YAMLFactory {
    val loaderOptions = LoaderOptions()
    loaderOptions.codePointLimit = 100_000_000

    return YAMLFactory
      .builder()
      .loaderOptions(loaderOptions)
      .streamReadConstraints(
        StreamReadConstraints
          .builder()
          .maxStringLength(100_000_000)
          .build(),
      ).build()
  }
}

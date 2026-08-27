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
package org.perses.version

import com.google.common.collect.ImmutableMultimap
import java.nio.charset.StandardCharsets
import java.nio.file.Path
import java.nio.file.Paths
import java.time.ZonedDateTime
import java.time.format.DateTimeFormatter
import kotlin.io.path.readLines
import kotlin.io.path.writeText

object VersionClassGenerator {
  private val VERSION_PATTERN = Regex("""^(\d+)\.(\d)$""")

  // The VERSION file is bundled as a resource, so the version flows into the
  // generated class without any extra genrule wiring; bazel reruns the
  // generation because editing VERSION rebuilds this generator.
  private const val VERSION_RESOURCE = "version/org/perses/version/VERSION"

  @JvmStatic
  fun loadVersion(): String {
    val stream =
      checkNotNull(javaClass.classLoader.getResourceAsStream(VERSION_RESOURCE)) {
        "The resource $VERSION_RESOURCE is missing."
      }
    return stream.bufferedReader(StandardCharsets.UTF_8).use { it.readText() }.trim()
  }

  @JvmStatic
  fun generate(args: Array<String>) {
    require(args.size == 2)
    val lines = Paths.get(args[0]).readLines(StandardCharsets.UTF_8)
    val map = parse(lines)
    val outputFile = Paths.get(args[1])
    writeVersionClass(map, loadVersion(), outputFile)
  }

  private fun writeVersionClass(
    map: ImmutableMultimap<String, String>,
    version: String,
    outputFile: Path,
  ) {
    val (majorVersion, minorVersion) =
      requireNotNull(VERSION_PATTERN.find(version)) {
        "The version must be MAJOR.MINOR with a single-digit minor, but is '$version'."
      }.destructured
    val branch: String = map.get("PERSES_GIT_BRANCH").single()
    val hash: String = map.get("PERSES_GIT_COMMIT_HASH").single()
    val status: String = map.get("PERSES_GIT_STATUS").single()
    val timestamp = ZonedDateTime.now().format(DateTimeFormatter.ISO_ZONED_DATE_TIME)

    outputFile.writeText(
      """
      |package org.perses.version
      |object Version {
      |  @JvmStatic
      |  val BRANCH = "$branch"
      |  
      |  @JvmStatic
      |  val COMMIT_HASH = "$hash"
      |  
      |  @JvmStatic
      |  val STATUS = "$status"
      |  
      |  @JvmStatic
      |  val MAJOR_VERSION = "$majorVersion"
      |
      |  @JvmStatic
      |  val MINOR_VERSION = "$minorVersion"
      |  
      |  @JvmStatic
      |  val BUILD_TIME = "$timestamp"
      |}
      """.trimMargin(),
      StandardCharsets.UTF_8,
    )
  }

  fun parse(lines: List<String>): ImmutableMultimap<String, String> {
    val builder = ImmutableMultimap.builder<String, String>()
    for (line in lines) {
      val trimmed = line.trim()
      if (trimmed.isBlank()) {
        continue
      }
      val index = trimmed.indexOfFirst { it.isWhitespace() }
      val key: String
      val value: String
      if (index < 0) {
        key = trimmed
        value = ""
      } else {
        check(index > 0) { "Invalid line: \"$line\"" }
        key = trimmed.substring(startIndex = 0, endIndex = index).trim()
        value = trimmed.substring(startIndex = index).trim()
      }
      builder.put(key, value)
    }
    return builder.build()
  }
}

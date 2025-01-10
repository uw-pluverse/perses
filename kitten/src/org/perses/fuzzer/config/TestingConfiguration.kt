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
package org.perses.fuzzer.config

import com.google.common.collect.ImmutableList
import org.perses.util.YamlUtil
import org.perses.util.containsNoWhitespace
import java.lang.RuntimeException
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

interface Validateable {
  fun validate()
}

data class SeedFolder(
  val path: String,
  val fileExtentions: List<String>,
) : Validateable {

  override fun validate() {
    check(path.isNotBlank())
    check(Files.isDirectory(Paths.get(path)))
    check(fileExtentions.isNotEmpty())
    fileExtentions.forEach {
      check(it.containsNoWhitespace())
    }
  }

  init {
    validate()
  }
}

data class ProgramUnderTest(
  val command: String,
  val flagsToTest: List<CmdFlags>,
  val versionFlags: CmdFlags,
  val crashDetectorClassName: String,
) : Validateable {

  override fun validate() {
    check(command.containsNoWhitespace())
    check(command.isNotBlank())

    check(flagsToTest.isNotEmpty())
    flagsToTest.forEach {
      it.validate()
    }

    versionFlags.validate()
    check(crashDetectorClassName.containsNoWhitespace())
    try {
      Class.forName(crashDetectorClassName) // does not crash
    } catch (e: Throwable) {
      throw RuntimeException("the crashDetectorClassName is invalid.", e)
    }
  }

  init {
    validate()
  }
}

data class CmdFlags(
  val flags: List<String>,
) : Validateable {

  override fun validate() {
    flags.forEach {
      check(it.containsNoWhitespace())
    }
  }

  init {
    validate()
  }

  companion object {
    val EMPTY = CmdFlags(ImmutableList.of())
  }
}

data class TestingConfiguration(
  val language: String,
  val seedFolders: List<SeedFolder>,
  val programsUnderTest: List<ProgramUnderTest>,
) : Validateable {

//  private val languageKind = checkNotNull(
//    SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
//      .computeLanguageKindWithLanguageNameIgnoreCase(language)
//  ) {
//    "the given language is not supported."
//  }

//  fun computeLanguageKind(): LanguageKind = languageKind

  fun writeToYamlFile(file: Path) {
    YamlUtil.toYamlFile(this, file)
  }

  override fun validate() {
    seedFolders.forEach {
      it.validate()
    }
    programsUnderTest.forEach {
      it.validate()
    }
  }

  init {
    validate()
  }

  companion object {

    fun readFrom(file: Path): TestingConfiguration {
      return YamlUtil.fromYamlFile(file, TestingConfiguration::class.java)
    }
  }
}

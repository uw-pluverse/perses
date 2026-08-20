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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import org.perses.program.AbstractDataKind
import org.perses.program.AbstractReductionFile
import org.perses.program.BinaryReductionFile
import org.perses.program.ScriptFile
import org.perses.reduction.TestScript
import org.perses.util.toImmutableMap
import java.nio.file.Files
import java.nio.file.Path

/**
 * The immutable, *original* input set of a reduction: the test script, the mutable files being
 * reduced and their immutable dependency files, plus the structure over them -- relative paths
 * ([orig2relativePath]), stable per-file slot identity ([indexOfMutableFile]), and access to the
 * original file content. It is the fixed universe a reduction starts from and never shrinks.
 *
 * Contrast with [ReductionFolder], which is a *materialized snapshot* of this set on disk and may
 * hold a subset of it (multi-file reduction can delete whole files). The current/reduced state lives
 * in the folder; this type holds the original.
 */
abstract class AbstractOriginalReductionInputs(
  val testScript: ScriptFile,
  val mutableFiles: ImmutableList<out AbstractReductionFile<*, *>>,
  val immutableDependencyFiles: ImmutableList<BinaryReductionFile>,
) {
  /**
   * The data kind of the file being reduced (the first mutable file). Subclasses for a specific
   * language narrow this to [org.perses.program.LanguageKind] via an override.
   */
  open val initiallyDeterminedMainDataKind: AbstractDataKind
    get() = mutableFiles.first().dataKind

  val rootDirectory: Path = testScript.parentFile
  val absoluteRootDirectory: Path = rootDirectory.toAbsolutePath()

  /**
   * Every reduction file (mutable files first, then dependency files) mapped to its path relative to
   * [absoluteRootDirectory], in that order. Guava's [ImmutableMap] preserves insertion order, so the
   * sequence-style consumers keep their ordering, while the per-file path lookups
   * ([computeAbsPathWrt], [getRelativePathForOrigFile]) get O(1) access instead of a linear scan that
   * grows with the number of files in a multi-file reduction. Keyed by file identity, as the
   * reduction files have no value-based equality.
   */
  val orig2relativePath: ImmutableMap<AbstractReductionFile<*, *>, Path>
  val allFiles: ImmutableList<AbstractReductionFile<*, *>> =
    ImmutableList
      .builder<AbstractReductionFile<*, *>>()
      .addAll(mutableFiles)
      .addAll(immutableDependencyFiles)
      .build()

  init {
    require(mutableFiles.isNotEmpty()) {
      "A reduction requires at least one mutable file; the first one is the file being reduced."
    }
    check(mutableFiles.any { it.dataKind == initiallyDeterminedMainDataKind }) { mutableFiles }
    mutableFiles
      .zip(immutableDependencyFiles)
      .filter {
        Files.isSameFile(it.first.file, it.second.file)
      }.let { overlappedFiles ->
        check(overlappedFiles.isEmpty()) {
          "The mutable and immutable file lists should not overlap: $overlappedFiles"
        }
      }
    orig2relativePath =
      allFiles
        .asSequence()
        .map { it to it.file.toAbsolutePath() }
        .onEach { check(it.second.startsWith(absoluteRootDirectory)) }
        .associate { it.first to absoluteRootDirectory.relativize(it.second) }
        .toImmutableMap()
    check(orig2relativePath.size == allFiles.size) {
      """
      |Size: ${orig2relativePath.size}
      |Relative paths: ${orig2relativePath.values.joinToString(separator = "\n")}
      |All paths: ${orig2relativePath.keys.map { it.file }}
      """.trimIndent()
    }
  }

  /**
   * The *original* content of every mutable file except [fileExcluded], keyed by the file, read
   * verbatim from the input file on disk. This is the original input, not any folder's current best,
   * so it is correct only for a sibling that stays fixed for the whole reduction -- e.g. grammar
   * reduction, which reduces only the parser grammar and supplies the never-reduced lexer's original
   * content to every output manager. A reduction whose siblings change must instead read the current
   * best from the result folder ([ReductionFolder.readLiveMutableFileContents]).
   */
  fun mutableFileContentsExcluding(
    fileExcluded: AbstractReductionFile<*, *>,
  ): ImmutableMap<AbstractReductionFile<*, *>, String> {
    val builder = ImmutableMap.builder<AbstractReductionFile<*, *>, String>()
    mutableFiles.forEach { file ->
      if (file !== fileExcluded) {
        builder.put(file, file.fileWithContent.textualFileContent)
      }
    }
    return builder.build()
  }

  fun writeTestScriptTo(folder: Path): TestScript {
    require(Files.isDirectory(folder)) {
      "$folder is not a directory"
    }
    val script = testScript
    return TestScript(
      scriptFile = folder.resolve(script.baseName),
      scriptTemplate = script,
    )
  }

  inline fun computeAbsPathListWrt(
    newFolder: Path,
    crossinline reductionFileSelectionPredicate: (AbstractReductionFile<*, *>) -> Boolean,
  ): Sequence<Path> =
    orig2relativePath
      .asSequence()
      .filter { reductionFileSelectionPredicate(it.key) }
      .map { newFolder.resolve(it.value) }

  private fun isMutableFile(origFile: AbstractReductionFile<*, *>): Boolean =
    if (mutableFiles.contains(origFile)) {
      check(!immutableDependencyFiles.contains(origFile))
      true
    } else {
      check(!mutableFiles.contains(origFile))
      false
    }

  /**
   * The index of [file] (by identity) in [mutableFiles]. This index is the canonical slot of the
   * file in per-file vectors such as [PerFileSizeMetrics] and the query cache's token-count
   * vectors, so all of them agree on which slot belongs to which file.
   */
  fun indexOfMutableFile(file: AbstractReductionFile<*, *>): Int {
    val index = mutableFiles.indexOfFirst { it === file }
    check(index >= 0) {
      "Not a mutable file of this reduction: $file. mutableFiles=$mutableFiles"
    }
    return index
  }

  /**
   * The immutable *universe* of mutable files, each paired with its relative path, in stable slot
   * order (the order [indexOfMutableFile] keys against). This is the full input set and never
   * shrinks. For the currently-live on-disk subset of a particular folder -- which may be smaller,
   * because multi-file reduction can delete whole files -- use
   * [ReductionFolder.sequenceOfLiveMutableFiles] instead.
   */
  fun sequenceOfMutableFiles(): Sequence<Map.Entry<AbstractReductionFile<*, *>, Path>> =
    orig2relativePath.asSequence().filter {
      isMutableFile(it.key)
    }

  fun computeAbsPathWrt(
    origFile: AbstractReductionFile<*, *>,
    newFolder: Path,
  ): Path = newFolder.resolve(getRelativePathForOrigFile(origFile))

  /**
   * Rejects an output directory that would map any mutable file's slot onto the input file itself --
   * i.e. in-place reduction. Perses reduces out of place: the result folder is populated from these
   * inputs and then overwritten with reduced content (and whole files removed by the terminal
   * file-deletion phase), and the originals are no longer backed up. Overwriting them in place would
   * therefore destroy the user's only copy with no way to recover it.
   */
  fun checkOutputDirectoryIsNotInPlace(outputDirectory: Path) {
    mutableFiles.forEach { file ->
      val slot = computeAbsPathWrt(file, outputDirectory).toAbsolutePath().normalize()
      val original = file.file.toAbsolutePath().normalize()
      check(slot != original) {
        "Refusing in-place reduction: output directory $outputDirectory would overwrite the " +
          "input file $original. Perses reduces out of place and does not back up inputs; " +
          "choose an output directory that does not contain the input files."
      }
    }
  }

  fun relativePathSequence(): Sequence<Path> = orig2relativePath.values.asSequence()

  fun getRelativePathForOrigFile(origFile: AbstractReductionFile<*, *>): Path =
    checkNotNull(orig2relativePath[origFile]) {
      "Not an input file of this reduction: $origFile"
    }

  // Everything resolved up front about parsing each mutable file, keyed by file identity (the
  // reduction files have no value-based equality). One entry holds the file's canonical parser
  // facade -- permanent, because a file's language does not change -- and, until the first spar-tree
  // build consumes it, the original source text and its parse from the resolution probe. Populated
  // and read on the single reduction thread, so it needs no synchronization.
  private val parseInfoByFile = HashMap<AbstractReductionFile<*, *>, FileParseInfo>()

  /** Recorded once per [file]; [parseTree] is the probe's parse for the first build to reuse, or
   * null to cache none (no parse produced, or not worth retaining). */
  fun recordCanonicalParserFacade(
    file: AbstractReductionFile<*, *>,
    parserFacade: AbstractParserFacade,
    sourceCode: String,
    parseTree: ParseTreeWithParser?,
  ) {
    check(isMutableFile(file)) {
      "Not a mutable file of this reduction: $file"
    }
    check(!parseInfoByFile.containsKey(file)) {
      "Parser facade already recorded for $file"
    }
    parseInfoByFile[file] = FileParseInfo(parserFacade, sourceCode, parseTree)
  }

  fun hasCanonicalParserFacade(file: AbstractReductionFile<*, *>): Boolean =
    parseInfoByFile.containsKey(file)

  fun getCanonicalParserFacade(file: AbstractReductionFile<*, *>): AbstractParserFacade =
    checkNotNull(parseInfoByFile[file]) {
      "No canonical parser facade recorded for $file. Recorded: ${parseInfoByFile.keys}"
    }.canonicalParserFacade

  fun retrieveCachedOriginalParseTreeOrNull(
    file: AbstractReductionFile<*, *>,
    sourceCode: String,
    parserFacade: AbstractParserFacade,
  ): ParseTreeWithParser? = parseInfoByFile[file]?.takeParseTreeIfMatches(sourceCode, parserFacade)

  private class FileParseInfo(
    val canonicalParserFacade: AbstractParserFacade,
    // The original source text and its parse, retained only until the first spar-tree build of that
    // exact text takes them; afterward the text shrinks and the parse would be stale, so they are
    // cleared and later builds parse fresh. Null when probing produced no reusable parse.
    private var originalSourceText: String?,
    private var originalParseTree: ParseTreeWithParser?,
  ) {
    fun takeParseTreeIfMatches(
      sourceCode: String,
      parserFacade: AbstractParserFacade,
    ): ParseTreeWithParser? {
      val parseTree = originalParseTree ?: return null
      if (originalSourceText != sourceCode ||
        canonicalParserFacade::class != parserFacade::class
      ) {
        return null
      }
      originalSourceText = null
      originalParseTree = null
      return parseTree
    }
  }
}

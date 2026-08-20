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

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile
import org.perses.reduction.PropertyTestResult
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import java.io.IOException
import java.lang.RuntimeException
import java.nio.file.FileVisitResult
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.SimpleFileVisitor
import java.nio.file.StandardCopyOption
import java.nio.file.attribute.BasicFileAttributes
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText

// TODO: save the test result in the folder.
class ReductionFolder(
  private val originalReductionInputs: AbstractOriginalReductionInputs,
  folder: Path,
) {
  private var inUse = true

  val path: Path =
    if (folder.isAbsolute) {
      folder
    } else {
      folder.toAbsolutePath()
    }

  init {
    lazyAssert(test = {
      this.path.isAbsolute
    }, message = { "The folder ${folder.fileName} must be absolute" })
    lazyAssert(test = {
      Files.isDirectory(this.path)
    }, message = { "The folder ${folder.fileName} must be a directory" })
  }

  @VisibleForTesting
  val testScript = originalReductionInputs.writeTestScriptTo(folder)

  fun runTestScript(): PropertyTestResult {
    checkThisFolderIsStillInUse()
    return testScript.test()
  }

  fun checkFileExistence(baseName: String): Boolean {
    checkThisFolderIsStillInUse()
    return Files.exists(path.resolve(baseName))
  }

  fun computeAbsPathForOrigFile(origFile: AbstractReductionFile<*, *>): Path =
    originalReductionInputs.computeAbsPathWrt(origFile, path)

  fun readFileContent(origFile: AbstractReductionFile<*, *>): String =
    computeAbsPathForOrigFile(origFile).readText()

  /**
   * The current-best content of every *live* mutable file in this folder, keyed by the file, except
   * [excluding]. A mutable file deleted from the set ([deleteMutableFile]) is absent rather than
   * read, so this never throws on a removed file.
   */
  fun readLiveMutableFileContents(
    excluding: AbstractReductionFile<*, *>? = null,
  ): ImmutableMap<AbstractReductionFile<*, *>, String> {
    val builder = ImmutableMap.builder<AbstractReductionFile<*, *>, String>()
    sequenceOfLiveMutableFiles().forEach { (origFile, absPath) ->
      if (origFile !== excluding) {
        builder.put(origFile, Files.readString(absPath))
      }
    }
    return builder.build()
  }

  /**
   * Each *live* mutable file paired with its absolute path in this folder, in stable mutable-file
   * slot order. The folder may hold a subset of the input universe -- multi-file reduction can delete
   * whole files ([deleteMutableFile]) -- so this filters [AbstractOriginalReductionInputs.mutableFiles] by
   * on-disk existence. It only filters, never renumbers, so callers that align with
   * [indexOfMutableFile] stay correct.
   *
   * A sequence keeps whole-set per-file work (e.g. sizing, which needs a parser facade this IO layer
   * deliberately does not depend on) in the caller's layer: the folder supplies the files and paths
   * and the caller picks the terminal operation, so nothing is materialized when unused.
   */
  fun sequenceOfLiveMutableFiles(): Sequence<Pair<AbstractReductionFile<*, *>, Path>> {
    checkThisFolderIsStillInUse()
    return originalReductionInputs.mutableFiles
      .asSequence()
      .map { file -> file to computeAbsPathForOrigFile(file) }
      .filter { (_, absPath) -> Files.exists(absPath) }
  }

  /**
   * Pre-reduction precondition: the folder has just been populated with the *original* input set, so
   * every reduction file -- both mutable and dependency files -- is present at its relative path.
   * Enforces the precondition of components that read their inputs from a fully-populated folder
   * (e.g. the token IO manager). The test script is not checked here: it is written and asserted by
   * this class's constructor, which locates it by base name rather than by a root-relative path. The
   * mutable files are written by a separate populate step (e.g.
   * [AbstractReductionIOManager.createPopulatedResultFolder]), which is why this check is needed.
   *
   * Valid ONLY before any file deletion has run. Once the live set may have shrunk, the folder is a
   * subset of the universe and this check no longer holds; use [checkLiveFilesAreSubsetOfInputs] for
   * an always-valid structural invariant.
   */
  fun checkAllInputFilesPopulated() {
    checkThisFolderIsStillInUse()
    originalReductionInputs.orig2relativePath.forEach { (_, relativePath) ->
      val file = path.resolve(relativePath)
      check(Files.exists(file)) {
        "The folder $path is not populated: missing $relativePath"
      }
    }
  }

  /**
   * Always-valid structural invariant (the folder is a *subset* of the input universe): the test
   * script and every immutable dependency file -- none ever deleted -- must be present. The
   * live-mutable subset relation holds by construction ([sequenceOfLiveMutableFiles] derives it from
   * the universe), so the only thing left to check is that the never-deleted files survive. Cheap;
   * suitable for [lazyAssert].
   */
  fun checkLiveFilesAreSubsetOfInputs() {
    checkThisFolderIsStillInUse()
    check(Files.exists(testScript.scriptFile)) {
      "The folder $path is missing its test script: ${testScript.scriptFile}"
    }
    originalReductionInputs.immutableDependencyFiles.forEach { depFile ->
      val absPath = computeAbsPathForOrigFile(depFile)
      check(Files.exists(absPath)) {
        "The folder $path is missing a dependency file: $absPath"
      }
    }
  }

  /**
   * Physically removes [origFile]'s slot from this folder, then prunes any parent directories left
   * empty by the removal (up to, but not including, the folder root). Used to commit an empty-file
   * deletion to the result folder: `saveBestProgram` re-renders only the live files but copies them
   * *over* the existing folder (it never removes a stale file), so the dropped file must be deleted
   * here for the folder -- the single source of truth -- to mirror the shrunken live set. The file
   * must end up truly absent, not left as an empty file, so a `find`-based test script no longer
   * picks it up.
   */
  fun deleteMutableFile(origFile: AbstractReductionFile<*, *>) {
    checkThisFolderIsStillInUse()
    val absPath = computeAbsPathForOrigFile(origFile)
    Files.deleteIfExists(absPath)
    var parent = absPath.parent
    while (parent != null &&
      parent != path &&
      Files.isDirectory(parent) &&
      Util.isEmptyDirectory(parent)
    ) {
      Files.delete(parent)
      parent = parent.parent
    }
  }

  fun deleteAllOtherFiles() {
    checkThisFolderIsStillInUse()
    val filesToKeep: Set<Path> =
      (
        sequenceOf(testScript.scriptFile) +
          originalReductionInputs.computeAbsPathListWrt(
            newFolder = path,
            reductionFileSelectionPredicate = { true },
          )
      ).filter { Files.exists(it) }
        .map { it.toRealPath() }
        .toSet()
    Files.walkFileTree(
      path,
      object : SimpleFileVisitor<Path>() {
        override fun visitFile(
          file: Path,
          attrs: BasicFileAttributes?,
        ): FileVisitResult {
          if (file.toRealPath() !in filesToKeep) {
            Files.delete(file)
          }
          return super.visitFile(file, attrs)
        }

        override fun postVisitDirectory(
          dir: Path,
          exc: IOException?,
        ): FileVisitResult {
          if (Util.isEmptyDirectory(dir)) {
            Files.delete(dir)
          }
          return super.postVisitDirectory(dir, exc)
        }
      },
    )
  }

  @OptIn(ExperimentalPathApi::class)
  fun deleteThisDirectoryRecursively() {
    checkThisFolderIsStillInUse()
    inUse = false
    val result = runCatching { path.deleteRecursively() }
    if (result.isSuccess) {
      return
    }
    try {
      /* Try to delete this again.
       *
       * There is a bug. There is another thread trying to write something to this directory,
       * but we are trying to delete the folder. So as a workaround, let's try to delete the
       * folder again. If there is another exception, then the caller will handle it.
       */
      path.deleteRecursively()
    } catch (e: Exception) {
      throw RuntimeException(
        """There are still files in this folder.
        |folder: ${this.path.fileName}
        |
        |The following are the files in this folder.
        |${Util.listFilesInFolder(path).joinToString(separator = "\n") {it.toString()}}
        |----------------------------------------------------------
        |
        |There was an exception previously.
        |${result.exceptionOrNull()!!.stackTraceToString()}
        |
        """.trimMargin(),
        e,
      )
    }
  }

  private fun checkThisFolderIsStillInUse() {
    check(inUse) { "This reduction folder is deleted permanently. $this" }
  }

  fun copyTo(destFolder: ReductionFolder) {
    Util.copyDirectory(path, destFolder.path, StandardCopyOption.REPLACE_EXISTING)
  }

  override fun toString(): String =
    MoreObjects.toStringHelper(this).add("working directory", path).toString()

  init {
    lazyAssert({ Files.isRegularFile(testScript.scriptFile) }) {
      "The test script file ${testScript.scriptFile} does not exist"
    }
    lazyAssert({ Files.isExecutable(testScript.scriptFile) }) {
      "The test script file $testScript"
    }
    originalReductionInputs.immutableDependencyFiles.forEach { file ->
      val absPath = computeAbsPathForOrigFile(file)
      Util.ensureDirExists(absPath.parent)
      file.writeTo(absPath)
    }
  }
}

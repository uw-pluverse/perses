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
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.AbstractDataKind
import org.perses.program.BinaryReductionFile
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.Util
import org.perses.util.shell.Shells
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList
import java.lang.Exception
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.name
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ReductionFolderTest {
  val tempDir = Files.createTempDirectory(this::class.java.canonicalName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testMultilevelInputs() {
    val root = Files.createDirectories(tempDir.resolve("root"))

    val fileA = Files.createFile(root.resolve("a.txt"))

    val dir1 = Files.createDirectories(root.resolve("dir-1"))
    val file1 = Files.createFile(dir1.resolve("z.txt"))

    val dir2 = Files.createDirectories(root.resolve("dir-2"))
    val file2 = Files.createFile(dir2.resolve("b.txt"))

    val depDir1 = Files.createDirectories(root.resolve("dep_dir_1"))
    val depFile1 = Files.createFile(depDir1.resolve("dep1.txt"))

    val depDir2 = Files.createDirectories(root.resolve("dep_dir_2"))
    val depFile2 = Files.createFile(depDir2.resolve("dep2.txt"))

    val testScript = createTestScript(root.resolve("r.sh"))

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript,
        mutableFiles =
          sequenceOf(
            fileA,
            file1,
            file2,
          ).map { SourceFile(it, LanguageC) }.toImmutableList(),
        immutableDependencyFiles =
          ImmutableList.of(
            BinaryReductionFile(file = depFile1, dataKind = AbstractDataKind.UnknownDataKind),
            BinaryReductionFile(file = depFile2, dataKind = AbstractDataKind.UnknownDataKind),
          ),
      )

    val originalReductionInputs = OriginalReductionInputs()

    val reductionFolder =
      ReductionFolder(
        originalReductionInputs = originalReductionInputs,
        folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
      )
    assertThat(
      reductionFolder.path
        .toFile()
        .listFiles()
        ?.map { it.name },
    ).containsExactly(
      testScript.baseName,
      depDir1.name,
      depDir2.name,
    )
    originalReductionInputs
      .computeAbsPathListWrt(
        reductionFolder.path,
        reductionFileSelectionPredicate = {
          originalReductionInputs.mutableFiles.contains(it)
        },
      ).forEach {
        Files.createDirectories(it.parent)
        Files.createFile(it)
      }
    assertThat(
      originalReductionInputs.sequenceOfMutableFiles().transformToImmutableList {
        it.key.file.name
      },
    ).containsExactly(
      fileA.name,
      file1.name,
      file2.name,
    )
    val extraFileName = "extra.txt"
    Files.createFile(reductionFolder.path.resolve(extraFileName))
    assertThat(
      reductionFolder.path
        .toFile()
        .listFiles()
        ?.map { it.name },
    ).containsExactly(
      testScript.baseName,
      dir1.name,
      dir2.name,
      depDir1.name,
      depDir2.name,
      fileA.name,
      extraFileName,
    )
    reductionFolder.deleteAllOtherFiles()
    assertThat(
      reductionFolder.path
        .toFile()
        .listFiles()
        ?.map { it.name },
    ).containsExactly(
      dir1.name,
      dir2.name,
      testScript.baseName,
      depDir1.name,
      depDir2.name,
      fileA.name,
    )

    assertThat(Files.isRegularFile(reductionFolder.path.resolve("a.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.path.resolve("${dir1.name}/z.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.path.resolve("${dir2.name}/b.txt"))).isTrue()

    assertThat(Files.isRegularFile(reductionFolder.path.resolve(testScript.baseName))).isTrue()

    assertThat(
      Files.isRegularFile(reductionFolder.path.resolve("dep_dir_1/dep1.txt")),
    ).isTrue()
    assertThat(
      Files.isRegularFile(reductionFolder.path.resolve("dep_dir_2/dep2.txt")),
    ).isTrue()
  }

  @Test
  fun testSequenceOfMutableFiles() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val fileA = Files.createFile(root.resolve("a.txt"))
    val fileB = Files.createFile(root.resolve("b.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript = scriptFile,
        mutableFiles =
          ImmutableList.of(
            SourceFile(fileA, LanguageC),
            SourceFile(fileB, LanguageC),
          ),
        immutableDependencyFiles = ImmutableList.of(),
      )

    val originalReductionInputs = OriginalReductionInputs()
    val reductionFolder =
      ReductionFolder(
        originalReductionInputs = originalReductionInputs,
        folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
      )
    // Seed each mutable file's current best in the folder with known content.
    reductionFolder
      .computeAbsPathForOrigFile(
        originalReductionInputs.mutableFiles[0],
      ).writeText("aaa")
    reductionFolder
      .computeAbsPathForOrigFile(
        originalReductionInputs.mutableFiles[1],
      ).writeText("bbbbb")

    // sequenceOfLiveMutableFiles yields each live file's identity paired with its absolute path in
    // the folder, in mutable-file order; the caller picks the terminal operation.
    val results =
      reductionFolder
        .sequenceOfLiveMutableFiles()
        .map { (origFile, absPath) -> origFile.baseName to absPath.readText().length }
        .toList()
    assertThat(results).containsExactly("a.txt" to 3, "b.txt" to 5).inOrder()
  }

  @Test
  fun testDeleteThisDirectoryRecursively() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val file = Files.createFile(root.resolve("a.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript = scriptFile,
        mutableFiles = ImmutableList.of(SourceFile(file, LanguageC)),
        immutableDependencyFiles = ImmutableList.of(),
      )

    val folderPath = Files.createDirectories(tempDir.resolve("reduction-folder"))
    val reductionFolder =
      ReductionFolder(
        OriginalReductionInputs(),
        folder = folderPath,
      )

    assertThat(Files.exists(folderPath)).isTrue()
    reductionFolder.deleteThisDirectoryRecursively()
    assertThat(Files.exists(folderPath)).isFalse()
    assertThrows(Exception::class.java) { reductionFolder.deleteThisDirectoryRecursively() }
    assertThrows(Exception::class.java) { reductionFolder.deleteAllOtherFiles() }
    assertThrows(Exception::class.java) { reductionFolder.runTestScript() }
  }

  @Test
  fun testCopyTo() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val file = Files.createFile(root.resolve("a.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))
    val dir1 = Files.createDirectories(root.resolve("1"))
    val dir2 = Files.createDirectories(root.resolve("2"))
    val file1 = Files.createFile(dir1.resolve("a.txt"))
    file1.writeText("file1")
    val file2 = Files.createFile(dir1.resolve("b.txt"))
    file2.writeText("file2")

    val subdir = Files.createDirectories(dir1.resolve("subdir"))
    val file3 = Files.createFile(subdir.resolve("c.txt"))
    file3.writeText("file3")

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript = scriptFile,
        mutableFiles = ImmutableList.of(SourceFile(file, LanguageC)),
        immutableDependencyFiles = ImmutableList.of(),
      )

    val reductionFolder1 =
      ReductionFolder(
        OriginalReductionInputs(),
        folder = dir1,
      )
    val reductionFolder2 =
      ReductionFolder(
        OriginalReductionInputs(),
        folder = dir2,
      )

    reductionFolder1.copyTo(reductionFolder2)

    val copyedFile1 = dir2.resolve(file1.fileName)
    val copyedFile2 = dir2.resolve(file2.fileName)
    val copyedSubdir = dir2.resolve(subdir.fileName)
    val copyedFile3 = copyedSubdir.resolve(file3.fileName)
    assertThat(Files.exists(copyedFile1)).isTrue()
    assertThat(Files.exists(copyedFile2)).isTrue()
    assertThat(Files.exists(copyedSubdir)).isTrue()
    assertThat(copyedFile1.readText()).isEqualTo(file1.readText())
    assertThat(copyedFile2.readText()).isEqualTo(file2.readText())
    assertThat(copyedFile3.readText()).isEqualTo(file3.readText())
  }

  @Test
  fun testDeleteMutableFilePrunesEmptyParentDirs() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    // A deeply-nested mutable file (the cf-3020 shape) alongside a top-level one.
    val nested =
      Files.createFile(
        Files
          .createDirectories(root.resolve("com/google/common/annotations"))
          .resolve("GwtCompatible.java"),
      )
    val topLevel = Files.createFile(root.resolve("Bug.java"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript = scriptFile,
        mutableFiles =
          ImmutableList.of(
            SourceFile(topLevel, LanguageC),
            SourceFile(nested, LanguageC),
          ),
        immutableDependencyFiles = ImmutableList.of(),
      )

    val originalReductionInputs = OriginalReductionInputs()
    val reductionFolder =
      ReductionFolder(
        originalReductionInputs,
        folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
      )
    // The constructor writes only the script + dependency files, so populate the mutable files.
    originalReductionInputs.mutableFiles.forEach { file ->
      val absPath = reductionFolder.computeAbsPathForOrigFile(file)
      Util.ensureDirExists(absPath.parent)
      absPath.writeText("content")
    }
    val nestedInFolder =
      reductionFolder.computeAbsPathForOrigFile(
        originalReductionInputs.mutableFiles[1],
      )
    assertThat(Files.exists(nestedInFolder)).isTrue()

    reductionFolder.deleteMutableFile(originalReductionInputs.mutableFiles[1])

    // The file is gone, and every parent directory it left empty is pruned, all the way up to (but
    // not including) the folder root.
    assertThat(Files.exists(nestedInFolder)).isFalse()
    assertThat(
      Files.exists(reductionFolder.path.resolve("com/google/common/annotations")),
    ).isFalse()
    assertThat(Files.exists(reductionFolder.path.resolve("com/google/common"))).isFalse()
    assertThat(Files.exists(reductionFolder.path.resolve("com"))).isFalse()
    // The folder root, the test script, and the other (still-live) file survive.
    assertThat(Files.isDirectory(reductionFolder.path)).isTrue()
    assertThat(Files.exists(reductionFolder.path.resolve(scriptFile.baseName))).isTrue()
    assertThat(
      Files.exists(
        reductionFolder.computeAbsPathForOrigFile(originalReductionInputs.mutableFiles[0]),
      ),
    ).isTrue()
  }

  @Test
  fun testDeleteMutableFileKeepsAParentThatStillHasOtherFiles() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val pkgDir = Files.createDirectories(root.resolve("pkg"))
    val fileX = Files.createFile(pkgDir.resolve("X.java"))
    val fileY = Files.createFile(pkgDir.resolve("Y.java"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript = scriptFile,
        mutableFiles =
          ImmutableList.of(
            SourceFile(fileX, LanguageC),
            SourceFile(fileY, LanguageC),
          ),
        immutableDependencyFiles = ImmutableList.of(),
      )

    val originalReductionInputs = OriginalReductionInputs()
    val reductionFolder =
      ReductionFolder(
        originalReductionInputs,
        folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
      )
    originalReductionInputs.mutableFiles.forEach { file ->
      val absPath = reductionFolder.computeAbsPathForOrigFile(file)
      Util.ensureDirExists(absPath.parent)
      absPath.writeText("content")
    }

    reductionFolder.deleteMutableFile(originalReductionInputs.mutableFiles[0])

    // X is gone, but pkg/ stays because its sibling Y is still there.
    assertThat(Files.exists(reductionFolder.path.resolve("pkg/X.java"))).isFalse()
    assertThat(Files.exists(reductionFolder.path.resolve("pkg/Y.java"))).isTrue()
    assertThat(Files.isDirectory(reductionFolder.path.resolve("pkg"))).isTrue()
  }

  @Test
  fun testDeleteMutableFileIsNoOpWhenFileAbsent() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val file = Files.createFile(root.resolve("a.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class OriginalReductionInputs :
      AbstractOriginalReductionInputs(
        testScript = scriptFile,
        mutableFiles = ImmutableList.of(SourceFile(file, LanguageC)),
        immutableDependencyFiles = ImmutableList.of(),
      )

    val originalReductionInputs = OriginalReductionInputs()
    val reductionFolder =
      ReductionFolder(
        originalReductionInputs,
        folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
      )
    // The constructor never writes mutable files, so this slot is already absent; deleting it must
    // be a no-op rather than throwing, and must not touch the folder root.
    reductionFolder.deleteMutableFile(originalReductionInputs.mutableFiles[0])

    assertThat(
      Files.exists(
        reductionFolder.computeAbsPathForOrigFile(originalReductionInputs.mutableFiles[0]),
      ),
    ).isFalse()
    assertThat(Files.isDirectory(reductionFolder.path)).isTrue()
  }

  @Test
  fun testSequenceOfLiveMutableFilesExcludesDeletedSlotAndPreservesOrder() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val fileA = Files.createFile(root.resolve("a.txt"))
    val fileB = Files.createFile(root.resolve("b.txt"))
    val fileC = Files.createFile(root.resolve("c.txt"))
    val inputs =
      createInputs(
        createTestScript(root.resolve("r.sh")),
        ImmutableList.of(
          SourceFile(fileA, LanguageC),
          SourceFile(fileB, LanguageC),
          SourceFile(fileC, LanguageC),
        ),
      )
    val folder = createPopulatedFolder(inputs)

    folder.deleteMutableFile(inputs.mutableFiles[1])

    // The live view filters out the dropped slot but never renumbers, so survivors keep their order.
    val live = folder.sequenceOfLiveMutableFiles().toList()
    assertThat(live.map { it.first })
      .containsExactly(inputs.mutableFiles[0], inputs.mutableFiles[2])
      .inOrder()
    assertThat(live.map { it.second })
      .containsExactly(
        folder.computeAbsPathForOrigFile(inputs.mutableFiles[0]),
        folder.computeAbsPathForOrigFile(inputs.mutableFiles[2]),
      ).inOrder()
  }

  @Test
  fun testReadLiveMutableFileContentsAfterDeletion() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val fileA = Files.createFile(root.resolve("a.txt"))
    val fileB = Files.createFile(root.resolve("b.txt"))
    val inputs =
      createInputs(
        createTestScript(root.resolve("r.sh")),
        ImmutableList.of(SourceFile(fileA, LanguageC), SourceFile(fileB, LanguageC)),
      )
    val folder = createPopulatedFolder(inputs)
    folder.computeAbsPathForOrigFile(inputs.mutableFiles[0]).writeText("aaa")
    folder.computeAbsPathForOrigFile(inputs.mutableFiles[1]).writeText("bbbbb")

    folder.deleteMutableFile(inputs.mutableFiles[0])

    // The deleted slot is absent (no NoSuchFileException), and the survivor's content is returned.
    val contents = folder.readLiveMutableFileContents()
    assertThat(contents.keys).containsExactly(inputs.mutableFiles[1])
    assertThat(contents[inputs.mutableFiles[1]]).isEqualTo("bbbbb")
  }

  @Test
  fun testLiveViewsAreEmptyWhenAllMutableFilesDeleted() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val fileA = Files.createFile(root.resolve("a.txt"))
    val fileB = Files.createFile(root.resolve("b.txt"))
    val inputs =
      createInputs(
        createTestScript(root.resolve("r.sh")),
        ImmutableList.of(SourceFile(fileA, LanguageC), SourceFile(fileB, LanguageC)),
      )
    val folder = createPopulatedFolder(inputs)

    // A test may legitimately need no input files, so the live set can shrink all the way to empty.
    inputs.mutableFiles.forEach { folder.deleteMutableFile(it) }

    assertThat(folder.sequenceOfLiveMutableFiles().toList()).isEmpty()
    assertThat(folder.readLiveMutableFileContents()).isEmpty()
  }

  @Test
  fun testCheckAllInputFilesPopulatedThrowsAfterDeletion() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val fileA = Files.createFile(root.resolve("a.txt"))
    val fileB = Files.createFile(root.resolve("b.txt"))
    val inputs =
      createInputs(
        createTestScript(root.resolve("r.sh")),
        ImmutableList.of(SourceFile(fileA, LanguageC), SourceFile(fileB, LanguageC)),
      )
    val folder = createPopulatedFolder(inputs)

    folder.checkAllInputFilesPopulated()

    // Once a file is dropped, the folder is a strict subset, so the precondition must fail.
    folder.deleteMutableFile(inputs.mutableFiles[0])
    assertThrows(Exception::class.java) { folder.checkAllInputFilesPopulated() }
  }

  @Test
  fun testCheckLiveFilesAreSubsetOfInputsHoldsAfterMutableDeletionButNotDependencyLoss() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val fileA = Files.createFile(root.resolve("a.txt"))
    val fileB = Files.createFile(root.resolve("b.txt"))
    val depFile = Files.createFile(root.resolve("dep.txt"))
    val inputs =
      createInputs(
        createTestScript(root.resolve("r.sh")),
        ImmutableList.of(SourceFile(fileA, LanguageC), SourceFile(fileB, LanguageC)),
        ImmutableList.of(
          BinaryReductionFile(file = depFile, dataKind = AbstractDataKind.UnknownDataKind),
        ),
      )
    val folder = createPopulatedFolder(inputs)

    // A mutable-file deletion keeps the subset invariant: the never-deleted script and dependency
    // files are still on disk.
    folder.deleteMutableFile(inputs.mutableFiles[0])
    folder.checkLiveFilesAreSubsetOfInputs()

    // Losing a dependency file (which is never supposed to be deleted) breaks the invariant.
    Files.delete(folder.computeAbsPathForOrigFile(inputs.immutableDependencyFiles[0]))
    assertThrows(Exception::class.java) { folder.checkLiveFilesAreSubsetOfInputs() }
  }

  private fun createInputs(
    script: ScriptFile,
    mutableFiles: ImmutableList<out org.perses.program.AbstractReductionFile<*, *>>,
    immutableDependencyFiles: ImmutableList<BinaryReductionFile> = ImmutableList.of(),
  ): AbstractOriginalReductionInputs =
    object : AbstractOriginalReductionInputs(script, mutableFiles, immutableDependencyFiles) {}

  // Builds the folder (constructor writes the script + dependency files) and seeds each mutable
  // file's slot, so the folder starts as the full input universe.
  private fun createPopulatedFolder(inputs: AbstractOriginalReductionInputs): ReductionFolder {
    val folder =
      ReductionFolder(
        inputs,
        folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
      )
    inputs.mutableFiles.forEach { file ->
      val absPath = folder.computeAbsPathForOrigFile(file)
      Util.ensureDirExists(absPath.parent)
      absPath.writeText("content")
    }
    return folder
  }

  private fun createTestScript(path: Path): ScriptFile =
    ScriptFile(
      Files.createFile(path).apply {
        this.writeText(Shells.SHEBANG_BASH)
        Util.setExecutable(this)
      },
    )
}

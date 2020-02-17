package org.perses.reduction

import com.google.common.base.Strings
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import java.io.File
import java.io.IOException
import java.util.concurrent.atomic.AtomicInteger
import org.perses.program.SourceFile
import org.perses.util.Util

class ReductionFolderManager(
  private val rootFolder: File,
  val testScript: SourceFile,
  private val sourceFileName: String
) {
  private val sequenceGenerator = AtomicInteger()

  @Throws(IOException::class)
  fun createNextFolder(): ReductionFolder {
    val folderId = sequenceGenerator.getAndIncrement()
    val folderName = Strings.padStart(folderId.toString(), FOLDER_NAME_MIN_LENGTH, '0')
    val folder = File(rootFolder, folderName)
    assert(!folder.exists()) { "The folder already exists. $folder" }
    check(folder.mkdir()) { "Failed to create folder $folder" }
    val scriptFileName = testScript.baseName
    testScript.writeTo(File(folder, scriptFileName))
    return ReductionFolder(folder, scriptFileName, sourceFileName)
  }

  @Throws(IOException::class)
  fun deleteRootFolder() {
    MoreFiles.deleteRecursively(rootFolder.toPath(), RecursiveDeleteOption.ALLOW_INSECURE)
  }

  companion object {
    const val FOLDER_NAME_MIN_LENGTH = 6
  }

  init {
    require(rootFolder.exists()) {
      "The root folder does not exist: $rootFolder"
    }
    require(rootFolder.isDirectory) {
      "The root folder is not a directory: $rootFolder"
    }
    require(Util.isEmptyDirectory(rootFolder.toPath())) {
      "The root folder should be empty: $rootFolder"
    }
  }
}

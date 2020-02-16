package org.perses.reduction

import com.google.common.base.Preconditions
import com.google.common.base.Strings
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.program.SourceFile
import org.perses.util.Util
import java.io.File
import java.io.IOException
import java.util.concurrent.atomic.AtomicInteger

class ReductionFolderManager(
    val rootFolder: File,
    val testScript: SourceFile,
    val sourceFileName: String) {
  private val sequenceGenerator = AtomicInteger()

  @Throws(IOException::class)
  fun createNextFolder(): ReductionFolder {
    val folderId = sequenceGenerator.getAndIncrement()
    val folderName = Strings.padStart(Integer.toString(folderId), FOLDER_NAME_MIN_LENGTH, '0')
    val folder = File(rootFolder, folderName)
    assert(!folder.exists()) { "The folder already exists. $folder" }
    Preconditions.checkState(folder.mkdir(), "Failed to create folder %s", folder)
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
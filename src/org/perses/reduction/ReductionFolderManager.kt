package org.perses.reduction

import com.google.common.base.Strings
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.program.ScriptFile
import org.perses.util.Util
import java.io.File
import java.util.concurrent.atomic.AtomicInteger

class ReductionFolderManager(
  private val rootFolder: File,
  val testScriptTemplate: ScriptFile,
  private val sourceFileName: String
) {
  private val sequenceGenerator = AtomicInteger()

  fun createNextFolder(): ReductionFolder {
    check(!isRootFolderDeleted()) { "The root folder has been deleted." }
    val folderId = sequenceGenerator.getAndIncrement()
    val folderName = Strings.padStart(folderId.toString(), FOLDER_NAME_MIN_LENGTH, '0')
    val folder = File(rootFolder, folderName)
    check(!folder.exists()) { "The folder already exists. $folder" }
    check(folder.mkdir()) { "Failed to create folder $folder" }
    return ReductionFolder(folder, testScriptTemplate, sourceFileName)
  }

  private fun isRootFolderDeleted() = !rootFolder.exists()

  fun deleteRootFolder() {
    if (isRootFolderDeleted()) {
      return
    }
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

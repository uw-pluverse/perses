package org.perses.reduction

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.program.ScriptFile
import java.io.File
import java.io.IOException

// TODO: save the test result in the folder.
class ReductionFolder internal constructor(
  val folder: File,
  testScriptTemplate: ScriptFile,
  sourceFileName: String
) {
  val testScript: TestScript = TestScript(
    File(folder, testScriptTemplate.baseName),
    testScriptTemplate
  )
  val sourceFilePath: File = File(folder, sourceFileName)

  @Throws(IOException::class)
  fun deleteAllOtherFiles() {
    val fileNamesToKeep = ImmutableList.of(testScript.scriptFile.name, sourceFilePath.name)
    val filesToDelete = folder.listFiles { _, name -> !fileNamesToKeep.contains(name) }
    for (fileToDelete in filesToDelete) {
      if (fileToDelete.isDirectory) {
        MoreFiles.deleteRecursively(fileToDelete.toPath(), RecursiveDeleteOption.ALLOW_INSECURE)
      } else {
        fileToDelete.delete()
      }
    }
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("working directory", folder).toString()
  }

  init {
    assert(testScript.scriptFile.isFile) {
      "The test script file ${testScript.scriptFile} does not exist"
    }
    assert(testScript.scriptFile.canExecute()) {
      "The test script file $testScript"
    }
  }
}

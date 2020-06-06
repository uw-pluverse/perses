package org.perses.program

import java.io.File

class ScriptFile(file: File) : AbstractSourceFile(file) {
  val shebang = extractShebang(fileContent).trim()

  init {
    check(shebang.isNotBlank()) { "Empty shebang in file $file" }
  }

  private fun extractShebang(fileContent: String): String {
    val length = fileContent.length
    if (length <= 2) {
      return ""
    }
    if (fileContent[0] != '#' || fileContent[1] != '!') {
      return ""
    }
    val result = StringBuilder()
    for (i in 2 until length) {
      if (fileContent[i] == '\n') {
        break
      } else {
        result.append(fileContent[i])
      }
    }
    return result.toString()
  }
}

package org.perses.program

import com.google.common.io.MoreFiles
import java.io.File
import java.nio.charset.StandardCharsets

abstract class AbstractSourceFile(val file: File) {
  val fileContent: String

  val baseName: String
    get() = file.name

  val parentFile: File
    get() = file.parentFile

  fun writeTo(path: File) =
    MoreFiles.asCharSink(path.toPath(), StandardCharsets.UTF_8).write(fileContent)

  init {
    require(file.isFile) {
      "The file should be a regular file $file"
    }
    fileContent = MoreFiles.asCharSource(file.toPath(), StandardCharsets.UTF_8).read()
  }
}

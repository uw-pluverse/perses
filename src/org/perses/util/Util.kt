/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.util

import com.google.common.base.Strings
import com.google.common.collect.ImmutableList
import com.google.common.hash.HashCode
import com.google.common.hash.Hashing
import com.google.common.primitives.ImmutableIntArray
import java.io.ByteArrayOutputStream
import java.io.IOException
import java.io.InputStream
import java.io.OutputStream
import java.io.PrintStream
import java.nio.charset.Charset
import java.nio.charset.StandardCharsets
import java.nio.file.CopyOption
import java.nio.file.FileVisitResult
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import java.nio.file.SimpleFileVisitor
import java.nio.file.StandardCopyOption
import java.nio.file.StandardOpenOption
import java.nio.file.attribute.BasicFileAttributes
import java.nio.file.attribute.PosixFilePermission
import java.util.IdentityHashMap
import java.util.LinkedList
import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.atomic.AtomicInteger
import java.util.function.Predicate
import java.util.zip.Deflater
import java.util.zip.DeflaterOutputStream
import java.util.zip.InflaterOutputStream
import kotlin.io.path.deleteRecursively
import kotlin.io.path.outputStream
import kotlin.io.path.writeText

object Util {

  object ExceptionOutputStream : OutputStream() {
    override fun write(p0: Int) {
      error("This output stream should not be used.")
    }
  }

  object ExceptionPrintStream : PrintStream(ExceptionOutputStream)

  fun createAppendablePrintStream(
    path: Path,
    autoFlush: Boolean = false,
    charset: Charset = StandardCharsets.UTF_8,
  ): PrintStream {
    val outputStream = path.outputStream(StandardOpenOption.CREATE, StandardOpenOption.APPEND)
    return PrintStream(outputStream, autoFlush, charset.name())
  }

  fun createNonAppendablePrintStream(
    path: Path,
    autoFlush: Boolean = false,
    charset: Charset = StandardCharsets.UTF_8,
  ): PrintStream {
    return PrintStream(path.outputStream(), autoFlush, charset.name())
  }

  @JvmStatic
  fun computePercentage(numerator: Int, denominator: Int): String {
    return String.format("%.2f%%", numerator * 100.0 / denominator)
  }

  @JvmStatic
  fun <T> removeElementsFromLinkedList(
    list: LinkedList<T>?,
    removalCondition: Predicate<T>,
  ) {
    if (list.isNullOrEmpty()) {
      return
    }
    val iterator = list.iterator()
    while (iterator.hasNext()) {
      val t = iterator.next()
      if (removalCondition.test(t)) {
        iterator.remove()
      }
    }
  }

  fun <T> swap(list: ArrayList<T>, i: Int, j: Int) {
    val temp = list[i]
    list[i] = list[j]
    list[j] = temp
  }

  @JvmStatic
  fun <T> createConcurrentSet(): MutableSet<T> = ConcurrentHashMap.newKeySet()

  @JvmStatic
  fun <T> removeElementBySwappingLastElement(list: ArrayList<T>, index: Int) {
    require(list.size > 0)
    val last = list.size - 1
    if (index != last) {
      swap(list, index, last)
    }
    list.removeAt(last)
  }

  @JvmStatic
  inline fun <T> removeElementsFromList(
    list: ArrayList<T>,
    criterion: (index: Int, value: T) -> Boolean,
  ) {
    if (list.isEmpty()) {
      return
    }
    var start = 0
    val size = list.size
    for (i in 0 until size) {
      val element = list[i]
      if (criterion(i, element)) {
        continue
      }
      if (start != i) list[start] = element
      ++start
    }
    for (i in size - 1 downTo start) {
      list.removeAt(i)
    }
  }

  @JvmStatic
  fun <T> mergeContinuousElementsIntoRegions(
    list: List<T>,
    equalizer: (T, T) -> Boolean,
  ): ImmutableList<ImmutableList<T>> {
    if (list.isEmpty()) {
      return ImmutableList.of()
    }
    val result = ImmutableList.builder<ImmutableList<T>>()
    var currentRegion = ImmutableList.builder<T>()
    var prev = list.first()
    currentRegion.add(prev)
    for (i in 1..list.size) {
      if (i == list.size) {
        result.add(currentRegion.build())
        break
      }
      val current = list[i]
      if (equalizer(prev, current)) {
        currentRegion.add(current)
      } else {
        result.add(currentRegion.build())
        currentRegion = ImmutableList.builder()
        currentRegion.add(current)
      }
      prev = current
    }
    return result.build()
  }

  data class NonEmptyInternal(
    val inclusiveStart: Int,
    val exclusiveEnd: Int,
  ) {
    init {
      lazyAssert({ inclusiveStart < exclusiveEnd }) {
        "$inclusiveStart, $exclusiveEnd"
      }
    }

    fun size() = exclusiveEnd - inclusiveStart

    fun isInRange(value: Int) = value in inclusiveStart until exclusiveEnd
  }

  @JvmStatic
  inline fun <T> slideResverseIfSlidable(
    list: List<T>,
    slidingWindowSize: Int,
    visitor: (NonEmptyInternal) -> Unit,
  ) {
    require(slidingWindowSize > 0) { slidingWindowSize }
    for (exclusiveEndIndex in list.size downTo slidingWindowSize) {
      val inclusiveStartIndex = exclusiveEndIndex - slidingWindowSize
      lazyAssert({ exclusiveEndIndex > inclusiveStartIndex })
      visitor(NonEmptyInternal(inclusiveStartIndex, exclusiveEndIndex))
    }
  }

  @JvmStatic
  fun <T> removeNullFromList(list: ArrayList<T?>) {
    removeElementsFromList(list) { _, element -> element == null }
  }

  @JvmStatic
  fun isEmptyDirectory(path: Path): Boolean {
    Files.newDirectoryStream(path).use { stream -> return !stream.iterator().hasNext() }
  }

  @JvmStatic
  fun ensureDirExists(dir: Path): Path {
    if (!Files.isDirectory(dir)) {
      /**
       * Multiple instances of Perses might be creating the same folder at the same time.
       * Despite of data races, better to only check the folder is created successfully.
       * In case of a file with same name, a `java.nio.file.FileAlreadyExistsException` will be
       * caught and ignored, because the following check raises `IllegalStateException`.
       */
      try {
        Files.createDirectories(dir)
      } catch (e: IOException) {
        // Ignore the exception intentionally.
      }
      check(Files.isDirectory(dir)) { "Failed to create a directory named $dir" }
    }
    return dir
  }

  @JvmStatic
  fun setExecutable(path: Path) {
    val permissions = Files.getPosixFilePermissions(path)
    permissions.add(PosixFilePermission.OWNER_EXECUTE)
    Files.setPosixFilePermissions(path, permissions)
  }

  @JvmStatic
  fun createDirsAndWriteText(file: Path, text: String): Path {
    var parent = file.parent
    if (parent == null) {
      parent = file.toAbsolutePath().parent
    }
    check(parent != null) { "Cannot find the parent dir of $file" }
    if (!Files.exists(parent)) {
      Files.createDirectories(parent)
    }
    file.writeText(text)
    return file
  }

  @JvmStatic
  fun replaceFileExtension(path: String, newExt: String): String {
    require(newExt.isNotBlank())
    require(newExt.trim().length == newExt.length)
    require(newExt[0] != '.')

    newExt.forEach {
      check(it.isLetterOrDigit())
    }
    val dotIndex = path.lastIndexOf('.')
    check(dotIndex > 0)
    return path.substring(0, dotIndex + 1) + newExt
  }

  // TODO: test
  @JvmStatic
  fun clearDirectory(directory: Path) {
    require(Files.isDirectory(directory))
    directory.deleteRecursively()
    Files.createDirectory(directory)
  }

  // TODO: test
  @JvmStatic
  fun copyDirectory(source: Path, target: Path, vararg options: CopyOption) {
    require(Files.isDirectory(source))
    if (!Files.exists(target)) {
      Files.createDirectories(target)
    }
    check(Files.isDirectory(target))
    Files.walkFileTree(
      source,
      object : SimpleFileVisitor<Path>() {
        override fun preVisitDirectory(
          dir: Path,
          attrs: BasicFileAttributes,
        ): FileVisitResult {
          Files.createDirectories(target.resolve(source.relativize(dir)))
          return FileVisitResult.CONTINUE
        }

        override fun visitFile(file: Path, attrs: BasicFileAttributes): FileVisitResult {
          Files.copy(file, target.resolve(source.relativize(file)), *options)
          return FileVisitResult.CONTINUE
        }
      },
    )
  }

  @JvmStatic
  fun copyFileToDirectory(srcFilePath: Path, destDir: Path): Path {
    val destFilePath = destDir.resolve(srcFilePath.fileName)
    require(!srcFilePath.toAbsolutePath().equals(destFilePath.toAbsolutePath())) {
      "Destination path cannot be the same as the original path."
    }
    Files.copy(srcFilePath, destFilePath, StandardCopyOption.REPLACE_EXISTING)
    return destFilePath
  }

  @JvmStatic
  fun globWithRegex(dir: Path, pattern: Regex): ImmutableList<Path> {
    return globWithFilter(dir) {
      pattern.matches(it.fileName.toString())
    }
  }

  @JvmStatic
  fun globWithFileNameExts(dir: Path, ext: String): ImmutableList<Path> {
    require(ext.trim().length == ext.length)
    require(ext.isNotBlank())
    return globWithFilter(dir) {
      it.fileName.toString().endsWith(ext)
    }
  }

  private fun globWithFilter(
    dir: Path,
    regualrFileFilter: (Path) -> Boolean,
  ): ImmutableList<Path> {
    return Files
      .walk(dir)
      .use { stream ->
        stream.filter { file ->
          Files.isRegularFile(file) && regualrFileFilter(file)
        }.collect(ImmutableList.toImmutableList())
      }
  }

  @JvmStatic
  fun <T> computeDifference(superList: List<T>, subList: List<T>): ImmutableList<T> {
    val builder = ImmutableList.builder<T>()
    visitDifference(superList, subList) { builder.add(it) }
    return builder.build()
  }

  @JvmStatic
  inline fun <T> visitDifference(superList: List<T>, subList: List<T>, visitor: (T) -> Unit) {
    lazyAssert { countDistinctObjects(superList) == superList.size }
    lazyAssert { countDistinctObjects(subList) == subList.size }
    var subIndex = 0
    val subSize = subList.size
    for (element in superList) {
      if (subIndex >= subSize) {
        visitor.invoke(element)
        continue
      }
      if (element === subList[subIndex]) {
        ++subIndex
      } else {
        visitor.invoke(element)
      }
    }
    check(subIndex == subSize) {
      "$subIndex, $subSize"
    }
  }

  @JvmStatic
  fun <T> countDistinctObjects(collection: Collection<T>): Int {
    val map = IdentityHashMap<T, T>(collection.size)
    for (t in collection) {
      map.put(t, t)
    }
    return map.size
  }

  data class SHA512HashCode private constructor(
    private val stringLengths: ImmutableIntArray,
    val digest: HashCode,
  ) {

    val numOfStrings: Int
      get() = stringLengths.length()

    fun getLengthOfString(index: Int) = stringLengths[index]

    companion object {
      fun createFromString(string: String) = SHA512HashCode(
        stringLengths = ImmutableIntArray.of(string.length),
        digest = Hashing.sha512().hashString(string, StandardCharsets.UTF_8),
      )

      fun createFromListOfStrings(strings: List<String>) = SHA512HashCode(
        stringLengths = ImmutableIntArray.builder(strings.size).apply {
          strings.forEach { s -> add(s.length) }
        }.build(),
        digest = hashListOfStrings(strings),
      )
    }
  }

  @JvmStatic
  fun hashListOfStrings(list: List<String>) = Hashing.sha512().hashObject(
    list,
    StringListToByteFunnel,
  )

  @JvmStatic
  fun zipCompress(text: String): ByteArray {
    val bArray = text.toByteArray(Charsets.UTF_8)
    val compressor = Deflater(Deflater.BEST_COMPRESSION)
    val output = ByteArrayOutputStream().use { output ->
      DeflaterOutputStream(output, compressor).use { dos ->
        dos.write(bArray)
        dos.finish()
      }
      output.toByteArray()
    }
    return output
  }

  @JvmStatic
  fun zipDecompress(bArray: ByteArray): ByteArray {
    return ByteArrayOutputStream().use { output ->
      InflaterOutputStream(output).use { ios ->
        ios.write(bArray)
        ios.finish()
      }
      output.toByteArray()
    }
  }

  @JvmStatic
  fun getUserHomeDirectory(): Path {
    val userHomeSystemPropertyName = "user.home"
    val home = System.getProperty(userHomeSystemPropertyName)
    check(home != null) {
      "The system property $userHomeSystemPropertyName is null."
    }
    val directory = Paths.get(home)
    check(Files.isDirectory(directory)) {
      "The home folder $directory is not a directory."
    }
    return directory
  }

  @JvmStatic
  fun getSystemTemporaryDirectory(): Path {
    val key = "java.io.tmpdir"
    val tempDir = System.getProperty(key)
    check(tempDir != null) {
      "The temporary directory $tempDir is null."
    }
    return Paths.get(tempDir)
  }

  @JvmStatic
  fun openResourceAsStream(
    resourceName: String,
    klassUnderSamePkg: Class<*>,
  ): InputStream {
    val result = klassUnderSamePkg.getResourceAsStream(resourceName)
    return requireNotNull(result) {
      "Failed to open stream $resourceName with class ${klassUnderSamePkg.canonicalName}"
    }
  }

  @JvmStatic
  fun copyResource(
    resourceName: String,
    klassUnderSamePkg: Class<*>,
    destination: Path,
  ) {
    openResourceAsStream(resourceName, klassUnderSamePkg).use { resource ->
      Files.newOutputStream(destination).use { output ->
        resource.copyTo(output)
      }
    }
  }

  @JvmField
  val ASSERTION_ENABLED = Util::class.java.desiredAssertionStatus()

  inline fun lazyAssert(test: () -> Boolean) {
    lazyAssert(test) { "" }
  }

  inline fun lazyAssert(test: () -> Boolean, message: () -> Any) {
    if (ASSERTION_ENABLED) {
      check(test()) { message() }
    }
  }

  class AtomicSequenceGenerator(start: Int = 1, private val minLengthForPadding: Int) {
    init {
      require(minLengthForPadding > 0)
    }
    private val generator = AtomicInteger(start)

    fun next(): String {
      return Strings.padStart(generator.getAndIncrement().toString(), minLengthForPadding, '0')
    }
  }
  data class SpaceSize(val bytes: Int) {

    companion object {
      fun megaBytes(mb: Int): SpaceSize = kiloBytes(kb = mb * 1000)

      fun kiloBytes(kb: Int) = SpaceSize(bytes = kb * 1000)
    }
  }
}

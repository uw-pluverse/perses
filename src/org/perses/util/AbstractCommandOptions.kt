package org.perses.util

import com.beust.jcommander.JCommander
import java.util.function.Consumer

abstract class AbstractCommandOptions {

  private val allFlags = LinkedHashSet<ICommandLineFlags>()

  fun validate() {
    allFlags.forEach { it.validate() }
  }

  protected fun <T : ICommandLineFlags> registerFlags(flags: T): T {
    check(!allFlags.contains(flags))
    allFlags.add(flags)
    return flags
  }

  fun createJCommander(mainClass: Class<*>): JCommander {
    val builder = JCommander.newBuilder().programName(mainClass.canonicalName).addObject(this)
    allFlags.forEach(Consumer { o: ICommandLineFlags? -> builder.addObject(o) })
    return builder.build()
  }
}

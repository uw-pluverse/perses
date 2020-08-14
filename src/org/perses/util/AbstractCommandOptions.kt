package org.perses.util

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
}

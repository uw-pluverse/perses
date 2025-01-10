/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.collect.Iterables
import org.perses.fuzzer.compilers.ICompilerCrashDetector.CrashSignature
import java.io.File
import java.io.OutputStreamWriter
import java.io.PrintStream
import java.io.StringWriter
import java.io.Writer

class CrashClusterIndex private constructor(
  val clusters: ImmutableMap<CrashSignature, Cluster>,
) {

  init {
    clusters.entries.forEach { check(it.key == it.value.signature) }
  }

  val numberOfClusters: Int
    get() = clusters.size

  fun getCluster(index: Int) = Iterables.get(clusters.values, index)

  val numberOfInstances = clusters.values.asSequence().map { it.instances }.map { it.size }.sum()

  val crashSignatures
    get() = clusters.keys

  fun saveTo(file: File) {
    file.bufferedWriter().use { saveTo(it) }
  }

  fun saveTo(writer: Writer) {
    var isFirst = true
    for (clusterWithIndex in clusters.entries.withIndex()) {
      if (isFirst) {
        isFirst = false
      } else {
        writer.append("\n\n\n")
      }
      writer.append("==================================================\n")
      writer.append("| Cluster ${clusterWithIndex.index}\n")
      writer.append("==================================================\n")
      clusterWithIndex.value.value.saveTo(writer)
    }
  }

  fun saveToString(): String {
    val writer = StringWriter()
    saveTo(writer)
    return writer.toString()
  }

  class Builder {
    val index = LinkedHashMap<CrashSignature, Cluster.Builder>()

    fun add(instanceFolder: CrashInstanceFolder): Builder {
      val signature = instanceFolder.readCrashSignature()
      if (!index.containsKey(signature)) {
        check(index.put(signature, Cluster.Builder(signature)) == null)
      }
      index[signature]!!.add(instanceFolder)
      return this
    }

    fun build() = CrashClusterIndex(
      index.entries
        .asSequence()
        .fold(
          ImmutableMap.builder<CrashSignature, Cluster>(),
          { builder, entry -> builder.put(entry.key, entry.value.build()) },
        )
        .build(),
    )
  }

  class CrashInstanceList(val instances: ImmutableList<CrashInstanceFolder>) {

    val size
      get() = instances.size

    fun get(index: Int) = instances[index]

    class Builder {
      private val builder = ImmutableList.builder<CrashInstanceFolder>()
      private val visited = HashSet<CrashInstanceFolder>()

      fun add(instance: CrashInstanceFolder): Builder {
        require(visited.add(instance))
        builder.add(instance)
        return this
      }

      fun build() = CrashInstanceList(builder.build())
    }
  }

  class Cluster(
    val signature: CrashSignature,
    val instances: CrashInstanceList,
  ) {

    fun saveTo(writer: Writer) {
      writer.append("---Crash Signature---\n")
      writer.append(signature.toString()).append('\n')
      writer.append("\n")
      writer.append("---Instances---\n")
      for (instanceWithIndex in instances.instances.withIndex()) {
        writer.append("${instanceWithIndex.index}:")
        writer.append(" \t")
        writer.append("${instanceWithIndex.value.folder}")
        writer.append(" \t")
        writer.append("${instanceWithIndex.value.getMutantFile().length()} bytes")
        writer.append("\n")
      }
    }

    fun print(stream: PrintStream) {
      with(OutputStreamWriter(stream)) {
        saveTo(this)
        this.flush()
      }
    }

    fun delete() {
      instances.instances.forEach {
        it.delete()
      }
    }

    class Builder(val signature: CrashSignature) {
      private val listBuilder = CrashInstanceList.Builder()

      fun add(instance: CrashInstanceFolder): Builder {
        listBuilder.add(instance)
        return this
      }

      fun build() = Cluster(signature, listBuilder.build())
    }
  }
}

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
package org.perses.dotgraph

import org.apache.commons.text.StringEscapeUtils
import org.perses.util.shell.Shells
import org.perses.util.shell.Shells.Companion.singleton
import java.nio.file.Path
import java.util.function.Consumer
import kotlin.io.path.absolute
import kotlin.io.path.name
import kotlin.io.path.writeText

class DotGraph<T> {
  private val edges: LinkedHashSet<Edge<T>>

  init {
    edges = LinkedHashSet()
  }

  fun addEdge(source: T, target: T) {
    edges.add(Edge(source, target))
  }

  fun dotify(outputFile: Path, labelProvider: NodeLabelProvider<T>) {
    val dotContent = dotifyToString(labelProvider)
    val dotFile = outputFile.parent.resolve(outputFile.name + ".dot")
    dotFile.writeText(dotContent)
    val (_, _, stderr) = singleton
      .run(
        "dot -Tpdf " + dotFile.absolute() + " -o " + outputFile.absolute(),
        true,
        Shells.CURRENT_ENV,
      )
    println(stderr)
  }

  fun dotifyToString(labelProvider: NodeLabelProvider<T>): String {
    val builder = StringBuilder()
    builder.append("digraph G {").append('\n')
    val nodes = LinkedHashSet<T>()
    edges.forEach(
      Consumer { e: Edge<T> ->
        nodes.add(e.source)
        nodes.add(e.target)
      },
    )
    nodes.forEach(
      Consumer { n: T ->
        builder
          .append(labelProvider.getID(n))
          .append(" [label=")
          .append("\"")
          .append(StringEscapeUtils.escapeJava(labelProvider.getLabel(n)))
          .append("\"")
          .append("];" + "")
          .append("\n")
      },
    )
    edges.forEach(
      Consumer { e: Edge<T> ->
        builder
          .append(labelProvider.getID(e.source))
          .append(" -> ")
          .append(labelProvider.getID(e.target))
          .append("\n")
      },
    )
    builder.append('}').append('\n')
    return builder.toString()
  }

  abstract class NodeLabelProvider<T> {
    private val ids: MutableMap<T, String>
    private val labels: MutableMap<T, String?>

    init {
      labels = HashMap()
      ids = HashMap()
    }

    fun getID(node: T): String {
      var id = ids[node]
      if (id == null) {
        id = "n" + NODE_ID_SEQ++
        ids[node] = id
      }
      return id
    }

    fun getLabel(node: T): String? {
      var label = labels[node]
      if (label == null) {
        label = computeNodeLabel(node)
        labels[node] = label
      }
      return label
    }

    protected abstract fun computeNodeLabel(node: T): String?

    companion object {
      private var NODE_ID_SEQ = 0
    }
  }

  private class Edge<T>(val source: T, val target: T) {

    override fun equals(other: Any?): Boolean {
      if (this === other) return true
      if (other == null || javaClass != other.javaClass) return false
      val edge = other as Edge<*>
      if (if (source != null) source != edge.source else edge.source != null) return false
      return if (target != null) target == edge.target else edge.target == null
    }

    override fun hashCode(): Int {
      var result = source?.hashCode() ?: 0
      result = 31 * result + (target?.hashCode() ?: 0)
      return result
    }
  }

  companion object {
    private const val NODE_SEQUENCE = 0
  }
}

/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.util.markdown

import org.commonmark.node.BulletList
import org.commonmark.node.FencedCodeBlock
import org.commonmark.node.ListItem
import org.commonmark.node.Node
import org.commonmark.node.Paragraph
import org.commonmark.node.Text
import org.commonmark.parser.Parser
import org.commonmark.renderer.html.HtmlRenderer
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.readText
import kotlin.io.path.writeText

object MarkdownToHTMLConverter {
  fun Node.singleChild(): Node = childSequence().single()

  fun Node.childSequence(): Sequence<Node> =
    sequence {
      var child: Node? = this@childSequence.firstChild
      while (child != null) {
        yield(child)
        child = child.next
      }
    }

  fun ListItem.computeStringRepresentation(): String {
    val child = this.firstChild
    check(child is Paragraph) { child }
    val childChild = child.firstChild
    check(childChild is Text) { childChild }
    return childChild.literal
  }

  fun BulletList.listItemSequence(): Sequence<ListItem> = childSequence().map { it as ListItem }

  fun findAllText(node: Node): List<Text> {
    val result = mutableListOf<Text>()
    findAllNodes(
      node,
      acceptancePredicate = { n -> n is Text },
      collector = { n -> result.add(n as Text) },
    )
    return result
  }

  fun findAllBulletLists(node: Node): List<BulletList> {
    val result = mutableListOf<BulletList>()
    findAllNodes(
      node,
      acceptancePredicate = { n -> n is BulletList },
      collector = { n -> result.add(n as BulletList) },
    )
    return result
  }

  fun findAllFencedCodeBlocks(node: Node): List<FencedCodeBlock> {
    val result = mutableListOf<FencedCodeBlock>()
    findAllNodes(
      node,
      acceptancePredicate = { n -> n is FencedCodeBlock },
      collector = { n -> result.add(n as FencedCodeBlock) },
    )
    return result
  }

  fun findAllNodes(
    node: Node,
    acceptancePredicate: (Node) -> Boolean,
    collector: (Node) -> Unit,
  ) {
    if (acceptancePredicate.invoke(node)) {
      collector.invoke(node)
    }
    node.childSequence().forEach { findAllNodes(it, acceptancePredicate, collector) }
  }

  fun parseMarkdownDocument(markdownContent: String): Node =
    Parser.builder().build().parse(markdownContent)

  fun convertMarkdownToHTML(
    markdownFile: Path,
    htmlResultFile: Path,
  ) {
    val document = parseMarkdownDocument(markdownFile.readText())
    val html = HtmlRenderer.builder().build().render(document)
    htmlResultFile.writeText(html)
  }

  @JvmStatic
  fun main(args: Array<String>) {
    if (args.size != 2) {
      println(
        "Usage: MarkdownToHTMLConverter <markdown file path> <HTML result file path>",
      )
      return
    }
    val markdownPath = Paths.get(args[0])
    val htmlPath = Paths.get(args[1])

    convertMarkdownToHTML(markdownPath, htmlPath)
    println("Conversion complete. HTML file created at: ${htmlPath.toAbsolutePath()}")
  }
}

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
package org.perses.util.markdown

import org.commonmark.parser.Parser
import org.commonmark.renderer.html.HtmlRenderer
import java.nio.file.Files
import java.nio.file.Path

class MarkdownToHTMLConverter {

  companion object {
    fun convertMarkdownToHTML(markdownFile: Path, htmlResultFile: Path) {
      val parser = Parser.builder().build()
      val renderer = HtmlRenderer.builder().build()

      val markdown = Files.readString(markdownFile)
      val document = parser.parse(markdown)
      val html = renderer.render(document)

      Files.writeString(htmlResultFile, html)
    }

    @JvmStatic
    fun main(args: Array<String>) {
      if (args.size != 2) {
        println(
          "Usage: MarkdownToHTMLConverter <markdown file path> <HTML result file path>",
        )
        return
      }
      val markdownPath = Path.of(args[0])
      val htmlPath = Path.of(args[1])

      MarkdownToHTMLConverter.convertMarkdownToHTML(markdownPath, htmlPath)
      println("Conversion complete. HTML file created at: ${htmlPath.toAbsolutePath()}")
    }
  }
}

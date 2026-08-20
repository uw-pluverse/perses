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
package org.perses

import com.beust.jcommander.Parameter
import com.beust.jcommander.converters.PathConverter
import org.antlr.v4.runtime.Token
import org.perses.ParseabilityMain.CommandOptions
import org.perses.cmd.LanguageControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil.createParserFacadeFactory
import org.perses.grammar.dyck.AdaptiveDyckParserFacade
import org.perses.grammar.dyck.DyckTokens
import org.perses.program.LanguageKind
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import java.io.PrintStream
import java.nio.file.Files
import java.nio.file.Path

/**
 * Batch parseability check: for each file in `--file-list`, report whether it parses under its
 * language's real grammar with a STRICT parse (the deployed grammar accepts it with no error
 * recovery -- the precondition stock Perses requires).
 *
 * The language and its parser facade are determined **automatically** per file (from the file name,
 * unless overridden by `--lang`/`--parser-facade-class-name`), and one facade per language is built
 * and reused, so a single JVM handles the whole (sharded) list instead of paying startup per file.
 *
 * Paths in the list are resolved against `--base-dir` (if given) and echoed verbatim to `--output`
 * for the subset that parses, so downstream joins keep the original relative paths.
 */
class ParseabilityMain(
  cmd: CommandOptions,
  private val printStream: PrintStream,
) : AbstractMain<CommandOptions>(cmd) {
  private val factory =
    CompositeParserFacadeFactory(
      builderWithBuiltinLanguages().build(),
      createParserFacadeFactory(cmd.extFlags.languageJarFiles),
    )
  private val facadeByLanguage = HashMap<LanguageKind, AbstractParserFacade>()

  // With --dyck, each file is parsed by the adaptive line-aware Dyck grammar over its language's real
  // lexer -- the grammar-agnostic fallback Taotie uses, which picks per file the delimiter kinds that
  // nest and demotes the rest to text -- so the tool measures Taotie's Dyck coverage instead of
  // real-grammar coverage.
  private val dyckByLanguage = HashMap<LanguageKind, AbstractParserFacade>()

  /** Resolves (and caches) the facade for [file]'s language, auto-detecting the language when unset;
   *  with --dyck, the Dyck facade over that language's lexer instead of the real grammar. */
  private fun facadeFor(file: Path): AbstractParserFacade {
    val language =
      factory.computeLanguage(
        specifiedLanguageName = cmd.extFlags.languageName,
        designatedParserFacadeClassName = cmd.extFlags.designatedParserFacadeClassName,
        sourceFileAbsPath = file,
      )
    val real =
      facadeByLanguage.getOrPut(language) {
        factory.getParserFacadeListForOrNull(language)!!.defaultParserFacade.create()
      }
    return if (cmd.flags.useDyck) {
      dyckByLanguage.getOrPut(language) { AdaptiveDyckParserFacade(real.realLexerClass) }
    } else {
      real
    }
  }

  override fun internalRun() {
    if (cmd.flags.dyckConfigCensus) {
      runDyckConfigCensus()
      return
    }
    val baseDir = cmd.flags.baseDir
    val lines = Files.readAllLines(cmd.flags.fileList!!).filter { it.isNotBlank() }
    val ok = ArrayList<String>(lines.size)
    for (line in lines) {
      val file = baseDir?.resolve(line) ?: Path.of(line)
      // A STRICT parse throws on the first lex/parse error (also on an unknown language or an
      // unreadable/undecodable file); any failure means the grammar does not accept the file as-is.
      val success =
        try {
          facadeFor(file).parseFile(file)
          true
        } catch (
          @Suppress("detekt:TooGenericExceptionCaught") t: Throwable,
        ) {
          false
        }
      if (success) {
        ok.add(line)
      }
    }
    Files.write(cmd.flags.output!!, ok)
    printStream.println("parseable: ${ok.size} / ${lines.size}")
  }

  /**
   * Instead of the parse-ok list, write one `<category>\t<path>` line per file, recording how the
   * adaptive Dyck grammar structured it: `full` when every delimiter kind the file contains nests
   * and is kept, `partial` when some kinds nest but at least one is demoted to text, and `lines` when
   * no delimiter structure remains (the file has none, or all of its delimiters were demoted, so it
   * parses as a flat list of lines). The three categories partition the files the Dyck grammar
   * parses, which is all of them.
   */
  private fun runDyckConfigCensus() {
    require(cmd.flags.useDyck) { "--dyck-config-census requires --dyck" }
    val baseDir = cmd.flags.baseDir
    val lines = Files.readAllLines(cmd.flags.fileList!!).filter { it.isNotBlank() }
    val out = ArrayList<String>(lines.size)
    val histogram = HashMap<String, Int>()
    for (line in lines) {
      val file = baseDir?.resolve(line) ?: Path.of(line)
      val category =
        try {
          classifyDyckConfiguration(facadeFor(file).tokenizeString(file.toFile().readText()))
        } catch (
          @Suppress("detekt:TooGenericExceptionCaught") t: Throwable,
        ) {
          "unlexable"
        }
      out.add("$category\t$line")
      histogram.merge(category, 1, Int::plus)
    }
    Files.write(cmd.flags.output!!, out)
    printStream.println("dyck-config census: ${histogram.toSortedMap()} / ${lines.size}")
  }

  /**
   * Reads the adaptive Dyck configuration off the relabeled token stream: a delimiter kind the
   * selector kept carries its `OPEN_BRACE`-style type, while a demoted one keeps its `{`/`(`/`[` text
   * but is typed `OTHER`. A kind is thus *present* if its character appears at all and *kept* if any
   * of its delimiter types appears. (A delimiter buried in a string or comment is part of a longer
   * token, so its text is not a bare `{`/`(`/`[` and it does not count as present -- exactly the
   * lexer-adaptation guarantee.)
   */
  private fun classifyDyckConfiguration(tokens: List<Token>): String {
    var presentBrace = false
    var keptBrace = false
    var presentParen = false
    var keptParen = false
    var presentBracket = false
    var keptBracket = false
    for (token in tokens) {
      when (token.text) {
        "{", "}" -> {
          presentBrace = true
          if (token.type == DyckTokens.OPEN_BRACE || token.type == DyckTokens.CLOSE_BRACE) {
            keptBrace = true
          }
        }
        "(", ")" -> {
          presentParen = true
          if (token.type == DyckTokens.OPEN_PARENTHESIS || token.type == DyckTokens.CLOSE_PARENTHESIS) {
            keptParen = true
          }
        }
        "[", "]" -> {
          presentBracket = true
          if (token.type == DyckTokens.OPEN_BRACKET || token.type == DyckTokens.CLOSE_BRACKET) {
            keptBracket = true
          }
        }
      }
    }
    val present = listOf(presentBrace, presentParen, presentBracket).count { it }
    val kept = listOf(keptBrace, keptParen, keptBracket).count { it }
    return when {
      kept == 0 -> "lines"
      kept == present -> "full"
      else -> "partial"
    }
  }

  class CommandOptions : AbstractCommandOptions() {
    val flags = registerFlags(RequiredFlagGroup())
    val extFlags = registerFlags(LanguageControlFlagGroup())

    class RequiredFlagGroup : AbstractCommandLineFlagGroup(groupName = "Compulsory") {
      @Parameter(
        names = ["--file-list"],
        description = "file with newline-separated source paths to check",
        required = true,
        converter = PathConverter::class,
      )
      var fileList: Path? = null

      @Parameter(
        names = ["--base-dir"],
        description = "directory the listed paths are resolved against",
        converter = PathConverter::class,
      )
      var baseDir: Path? = null

      @Parameter(
        names = ["--output"],
        description = "file to write the subset that parses (verbatim input lines)",
        required = true,
        converter = PathConverter::class,
      )
      var output: Path? = null

      @Parameter(
        names = ["--dyck"],
        description =
          "parse with the adaptive line-aware Dyck grammar over the file's real lexer " +
            "(Taotie's grammar-agnostic fallback) instead of the real grammar",
      )
      var useDyck: Boolean = false

      @Parameter(
        names = ["--dyck-config-census"],
        description =
          "with --dyck, write one '<category>\\t<path>' line per file instead of the parse-ok " +
            "list; category is full|partial|lines by how the adaptive Dyck configured its delimiters",
      )
      var dyckConfigCensus: Boolean = false

      override fun validate() {
        require(Files.isRegularFile(fileList!!)) { "--file-list is not a file: $fileList" }
        baseDir?.let { require(Files.isDirectory(it)) { "--base-dir is not a directory: $it" } }
      }
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { CommandOptions() },
          programName = ParseabilityMain::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      ParseabilityMain(processor.cmd, System.out).run()
    }
  }
}

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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.dyck.AbstractDyckParserFacade
import org.perses.program.LanguageKind
import org.perses.util.transformToImmutableList
import java.nio.file.Path
import kotlin.reflect.KClass
import kotlin.reflect.full.createInstance
import kotlin.reflect.full.primaryConstructor

abstract class AbstractParserFacadeFactory {
  fun containsLanguage(languageKind: LanguageKind): Boolean =
    languageSequence().any { it == languageKind }

  // TODO: this returns only the first matching language, but a file name can match several languages
  //  (e.g. shared/ambiguous extensions), and we cannot know which parser actually parses the file
  //  until we try. This should return all candidate languages so the caller can probe each one's
  //  parser (as resolveParserFacadeByProbing already does across facades within a single language).
  fun computeLanguageKindWithFileName(file: Path): LanguageKind? =
    languageSequence().firstOrNull {
      it.isOfThisLanguageKind(file)
    }

  fun computeLanguageKindWithLanguageNameIgnoreCase(languageName: String): LanguageKind? {
    val lowerCase = languageName.lowercase()
    return languageSequence().firstOrNull {
      it.name.lowercase() == lowerCase
    }
  }

  fun computeLanguageKindOrThrow(file: Path): LanguageKind {
    val language = computeLanguageKindWithFileName(file)
    if (language != null) {
      return language
    }
    reportError("Failed to detect the language kind for file $file\n")
  }

  fun computeLanguage(
    specifiedLanguageName: String,
    designatedParserFacadeClassName: String,
    sourceFileAbsPath: Path,
  ): LanguageKind =
    when {
      designatedParserFacadeClassName.isNotBlank() -> {
        getParserFacadeClassForClassNameOrNull(designatedParserFacadeClassName).let { result ->
          if (result == null) {
            error(
              "Cannot find the parser facade with the given parser facade class" +
                designatedParserFacadeClassName,
            )
          }
          result.first
        }
      }

      specifiedLanguageName.isNotBlank() -> {
        computeLanguageKindWithLanguageNameIgnoreCase(specifiedLanguageName)!!
      }

      else -> {
        computeLanguageKindOrThrow(sourceFileAbsPath)
      }
    }

  abstract fun languageSequence(): Sequence<LanguageKind>

  abstract fun getParserFacadeListForOrNull(languageKind: LanguageKind): ParserFacadeList?

  abstract fun getParserFacadeClassForClassNameOrNull(
    className: String,
  ): Pair<LanguageKind, ParserFacadeCreator>?

  internal fun reportError(prefix: String): Nothing {
    val errorMessage =
      buildString {
        append(prefix).append('\n')
        append("The available languages are listed below:\n")
        languageSequence().forEach { language ->
          append("  ${language.name}: exts=${language.extensions}\n")
        }
      }
    error(errorMessage)
  }

  open class ParserFacadeCreator(
    val klass: KClass<out AbstractParserFacade>,
  ) {
    open fun create(): AbstractParserFacade = klass.createInstance()
  }

  class DyckParserFacadeCreator(
    klass: KClass<out AbstractDyckParserFacade>,
    private val underlyingLexerClass: Class<out Lexer>,
  ) : ParserFacadeCreator(klass) {
    override fun create(): AbstractDyckParserFacade =
      klass.primaryConstructor!!.call(underlyingLexerClass) as AbstractDyckParserFacade
  }

  data class ParserFacadeList(
    val defaultParserFacade: ParserFacadeCreator,
    val otherParserFacades: ImmutableList<ParserFacadeCreator> = ImmutableList.of(),
  ) {
    init {
      require(!otherParserFacades.contains(defaultParserFacade)) {
        """
          | default parser facade: $defaultParserFacade
          | other parser facades: $otherParserFacades
        """.trimMargin()
      }
    }

    fun sequenceOfCreators(): Sequence<ParserFacadeCreator> =
      sequence {
        yield(defaultParserFacade)
        yieldAll(otherParserFacades)
      }

    fun resolveParserFacadeByProbing(
      probeSourceCode: String,
      probeFileName: String,
    ): AbstractParserFacade =
      resolveParserFacadeByProbingWithParseTree(probeSourceCode, probeFileName).facade

    /**
     * Like [resolveParserFacadeByProbing], but also returns the parse tree produced while probing so
     * the caller can reuse it for the first spar-tree build instead of re-parsing the same input.
     * [ResolvedParserFacade.parseTree] is null in the single-candidate fast path, where no probe
     * parse happens.
     */
    fun resolveParserFacadeByProbingWithParseTree(
      probeSourceCode: String,
      probeFileName: String,
    ): ResolvedParserFacade {
      if (otherParserFacades.isEmpty()) {
        return ResolvedParserFacade(defaultParserFacade.create(), parseTree = null)
      }
      for (creator in sequenceOfCreators()) {
        val facade = creator.create()
        val parseTree =
          try {
            facade.parseString(probeSourceCode, errorMode = ParseErrorHandling.STRICT)
          } catch (e: Exception) {
            null
          }
        if (parseTree != null) {
          return ResolvedParserFacade(facade, parseTree)
        }
      }
      throw AntlrFailureException(
        cause = null,
        file = probeFileName,
        details =
          "None of the candidate parser facades can parse the input: " +
            sequenceOfCreators().joinToString { it.klass.qualifiedName ?: it.klass.toString() },
      )
    }

    fun numberOfParserFacades() = 1 + otherParserFacades.size

    companion object {
      fun create(
        defaultParserFacade: KClass<out AbstractParserFacade>,
        otherParserFacades: Iterable<KClass<out AbstractParserFacade>>,
      ): ParserFacadeList =
        ParserFacadeList(
          defaultParserFacade = ParserFacadeCreator(defaultParserFacade),
          otherParserFacades =
            otherParserFacades.transformToImmutableList {
              ParserFacadeCreator(it)
            },
        )
    }
  }

  data class ResolvedParserFacade(
    val facade: AbstractParserFacade,
    val parseTree: ParseTreeWithParser?,
  )
}

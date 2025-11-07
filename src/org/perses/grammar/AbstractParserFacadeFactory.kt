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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.io.Files
import org.perses.grammar.c.PnfCLexer
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

  fun computeLanguageKindWithFileName(file: Path): LanguageKind? {
    val ext = Files.getFileExtension(file.fileName.toString())
    return languageSequence().firstOrNull {
      ext in it.extensions
    }
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
      designatedParserFacadeClassName.isNotBlank() ->
        getParserFacadeClassForClassNameOrNull(designatedParserFacadeClassName).let { result ->
          if (result == null) {
            error(
              "Cannot find the parser facade with the given parser facade class" +
                designatedParserFacadeClassName,
            )
          }
          result.first
        }
      specifiedLanguageName.isNotBlank() ->
        computeLanguageKindWithLanguageNameIgnoreCase(specifiedLanguageName)!!
      else -> computeLanguageKindOrThrow(sourceFileAbsPath)
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
  ) : ParserFacadeCreator(klass) {
    override fun create(): AbstractDyckParserFacade =
      klass.primaryConstructor!!.call(
        // TODO(cnsun): need to figure out a way to let users specify the lexer class.
        PnfCLexer::class.java,
      ) as AbstractDyckParserFacade
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
}

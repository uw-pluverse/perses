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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import com.google.common.primitives.ImmutableIntArray
import org.perses.program.AbstractPersesToken
import org.perses.spartree.AbstractSparTreeNode
import java.io.File
import java.nio.charset.StandardCharsets

class MutatedProgram private constructor(
  val program: String,
) {
  fun writeToFile(file: File) = file.writeText(program, StandardCharsets.UTF_8)

  companion object {
    fun deleteTokens(
      origin: ImmutableList<out AbstractPersesToken>,
      indicesToDelete: ImmutableIntArray,
    ): MutatedProgram {
      val builder = StringBuilder()
      var currentLineNumber = 1
      for ((index, token) in origin.withIndex()) {
        if (!indicesToDelete.contains(index)) {
          currentLineNumber = addTokenText(builder, currentLineNumber, token)
        }
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    fun insertTokens(
      origin: ImmutableList<out AbstractPersesToken>,
      indicesToInsert: ImmutableIntArray,
      tokensToInsert: ImmutableList<out AbstractPersesToken>,
    ): MutatedProgram {
      assert(indicesToInsert.length() == tokensToInsert.size)
      val builder = StringBuilder()
      var currentLineNumber = 1
      var counter = 0
      for ((index, token) in origin.withIndex()) {
        for (i in indicesToInsert.stream()) {
          if (i == index) {
            val tokenToAdd = tokensToInsert[counter++]
            addTokenText(builder, currentLineNumber, tokenToAdd)
          }
        }
        currentLineNumber = addTokenText(builder, currentLineNumber, token)
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    fun replaceTokens(
      origin: ImmutableList<out AbstractPersesToken>,
      indicesToReplace: ImmutableIntArray,
      tokensToReplace: ImmutableList<out AbstractPersesToken>,
    ): MutatedProgram {
      val builder = StringBuilder()
      val currentLineNumber = 1
      var counter = 0
      for ((index, token) in origin.withIndex()) {
        var tokenToReplace = token
        for (i in indicesToReplace.stream()) {
          if (i == index) {
            tokenToReplace = tokensToReplace[counter++]
            break
          }
        }
        addTokenText(builder, currentLineNumber, tokenToReplace)
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    // TODO: test.
    fun replaceToken(
      origin: ImmutableList<out AbstractPersesToken>,
      indexToReplace: Int,
      newToken: AbstractPersesToken,
    ): MutatedProgram {
      val builder = StringBuilder()
      var currentLineNumber = 1
      for ((index, token) in origin.withIndex()) {
        val tokenToAdd = if (index == indexToReplace) newToken else token
        currentLineNumber = addTokenText(builder, currentLineNumber, tokenToAdd)
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    fun repeatRecursion(
      origin: ImmutableList<out AbstractPersesToken>,
      recursiveNode: AbstractSparTreeNode,
      recursiveChild: AbstractSparTreeNode,
      repeatTimes: Int,
    ): MutatedProgram {
      val builder = StringBuilder()
      val recursionStart = recursiveNode.beginToken!!.token
      val recursionEnd = recursiveNode.endToken!!.token
      val childStart = recursiveChild.beginToken!!.token
      val childEnd = recursiveChild.endToken!!.token
      var isRecursivePart = false
      var currentLineNumber = 1
      var lineNumberBeforeRepeat = 1
      val recursiveList = mutableListOf<AbstractPersesToken>()
      for (token in origin) {
        if (token == recursionStart) {
          isRecursivePart = true
          lineNumberBeforeRepeat = currentLineNumber
        }
        when {
          isRecursivePart && token != recursionEnd -> {
            if (token == childStart) {
              isRecursivePart = false
              val tempLineNumber = lineNumberBeforeRepeat
              for (i in 1..repeatTimes) {
                lineNumberBeforeRepeat = tempLineNumber
                for (recursiveToken in recursiveList) {
                  lineNumberBeforeRepeat =
                    addTokenText(
                      builder,
                      lineNumberBeforeRepeat,
                      recursiveToken,
                    )
                }
              }
              currentLineNumber = addTokenText(builder, currentLineNumber, token)
              if (token == childEnd) {
                isRecursivePart = true
                lineNumberBeforeRepeat = currentLineNumber
                recursiveList.clear()
              }
            } else {
              recursiveList.add(token)
              currentLineNumber = addTokenText(builder, currentLineNumber, token)
            }
          }

          token == childEnd -> {
            isRecursivePart = true
            currentLineNumber = addTokenText(builder, currentLineNumber, token)
            lineNumberBeforeRepeat = currentLineNumber
            recursiveList.clear()
          }

          token == recursionEnd -> {
            isRecursivePart = false
            recursiveList.add(token)
            currentLineNumber = addTokenText(builder, currentLineNumber, token)
            val tempLineNumber = lineNumberBeforeRepeat
            for (i in 1..repeatTimes) {
              lineNumberBeforeRepeat = tempLineNumber
              for (recursiveToken in recursiveList) {
                lineNumberBeforeRepeat =
                  addTokenText(
                    builder,
                    lineNumberBeforeRepeat,
                    recursiveToken,
                  )
              }
            }
          }

          else -> {
            currentLineNumber = addTokenText(builder, currentLineNumber, token)
          }
        }
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    fun replaceNode(
      origin: ImmutableList<out AbstractPersesToken>,
      nodeToBeReplaced: AbstractSparTreeNode,
      replacement: ImmutableList<out AbstractPersesToken>,
    ): MutatedProgram {
      val builder = StringBuilder()
      var currentLineNumber = 1
      var isUnderReplacedNode = false
      for (token in origin) {
        if (token == nodeToBeReplaced.beginToken!!.token) {
          isUnderReplacedNode = true
          currentLineNumber = replacement[0].asAntlrToken().position.line
          for (newToken in replacement) {
            currentLineNumber = addTokenText(builder, currentLineNumber, newToken)
          }
          currentLineNumber =
            nodeToBeReplaced.endToken!!
              .token
              .asAntlrToken()
              .position.line
        }
        if (!isUnderReplacedNode) {
          currentLineNumber = addTokenText(builder, currentLineNumber, token)
        }
        if (token == nodeToBeReplaced.endToken!!.token) {
          isUnderReplacedNode = false
        }
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    fun insertNodes(
      origin: ImmutableList<out AbstractPersesToken>,
      tokenListsToInsert: ImmutableList<ImmutableList<AbstractPersesToken>>,
      insertPositions: ImmutableList<out AbstractPersesToken>,
    ): MutatedProgram {
      val builder = StringBuilder()
      var currentLineNumber = 1
      for (token in origin) {
        currentLineNumber = addTokenText(builder, currentLineNumber, token)
        for (i in 0 until insertPositions.size) {
          if (insertPositions[i] == token) {
            for (tokenToInsert in tokenListsToInsert[i]) {
              addTokenText(builder, currentLineNumber, tokenToInsert)
            }
          }
        }
      }
      builder.append('\n')
      return MutatedProgram(builder.toString())
    }

    private fun addTokenText(
      builder: StringBuilder,
      currentLineNumber: Int,
      token: AbstractPersesToken,
    ): Int {
      var lineNumber = currentLineNumber
      while (lineNumber < token.asAntlrToken().position.line) {
        if (builder.isNotEmpty() && builder[builder.length - 1] != '\n') {
          builder.append('\n')
        }
        ++lineNumber
      }
      if (builder.isEmpty() || builder[builder.length - 1] == '\n') {
        builder.append(token.lexemeText)
      } else {
        builder.append(' ').append((token.lexemeText))
      }
      return lineNumber
    }
  }
}

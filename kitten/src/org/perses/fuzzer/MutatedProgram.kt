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
import com.google.common.primitives.ImmutableIntArray
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.spartree.AbstractSparTreeNode
import java.io.File

class MutatedProgram private constructor(
  val program: String,
) {

  fun writeToFile(file: File) = file.writeText(program, Charsets.UTF_8)

  companion object {

    fun deleteTokens(
      origin: ImmutableList<PersesToken>,
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
      origin: ImmutableList<PersesToken>,
      indicesToInsert: ImmutableIntArray,
      tokensToInsert: ImmutableList<PersesToken>,
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
      origin: ImmutableList<PersesToken>,
      indicesToReplace: ImmutableIntArray,
      tokensToReplace: ImmutableList<PersesToken>,
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
      origin: ImmutableList<PersesToken>,
      indexToReplace: Int,
      newToken: PersesToken,
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
      origin: ImmutableList<PersesToken>,
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
      val recursiveList = mutableListOf<PersesToken>()
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
                  lineNumberBeforeRepeat = addTokenText(
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
                lineNumberBeforeRepeat = addTokenText(
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
      origin: ImmutableList<PersesToken>,
      nodeToBeReplaced: AbstractSparTreeNode,
      replacement: ImmutableList<PersesToken>,
    ): MutatedProgram {
      val builder = StringBuilder()
      var currentLineNumber = 1
      var isUnderReplacedNode = false
      for (token in origin) {
        if (token == nodeToBeReplaced.beginToken!!.token) {
          isUnderReplacedNode = true
          currentLineNumber = replacement[0].position.line
          for (newToken in replacement) {
            currentLineNumber = addTokenText(builder, currentLineNumber, newToken)
          }
          currentLineNumber = nodeToBeReplaced.endToken!!.token.position.line
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
      origin: ImmutableList<PersesToken>,
      tokenListsToInsert: ImmutableList<ImmutableList<PersesToken>>,
      insertPositions: ImmutableList<PersesToken>,
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
      token: PersesToken,
    ): Int {
      var lineNumber = currentLineNumber
      while (lineNumber < token.position.line) {
        if (builder.isNotEmpty() && builder[builder.length - 1] != '\n') {
          builder.append('\n')
        }
        ++lineNumber
      }
      if (builder.isEmpty() || builder[builder.length - 1] == '\n') {
        builder.append(token.text)
      } else {
        builder.append(' ').append((token.text))
      }
      return lineNumber
    }
  }
}

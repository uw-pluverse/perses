/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.util

import com.google.common.collect.ImmutableList
import java.lang.RuntimeException
import java.util.IdentityHashMap

class ListAlignment<T>(val alignment: ImmutableList<AbstractEditOperation<T>>) {

  init {
    checkElementsShouldBeDistinct(
      alignment
        .asSequence()
        .map { it.base }
        .filter { it != null }
        .map { it!! }
        .asIterable(),
    )
  }

  fun toPairList(): ImmutableList<Pair<T?, T?>> {
    return alignment.asSequence().map { it.toPair() }.toImmutableList()
  }

  fun computeRevision(original: Iterable<T>): ImmutableList<T> {
    val builder = ImmutableList.builder<T>()
    var index = 0
    val size = alignment.size
    for (t in original) {
      while (index < size) {
        val pair = alignment[index]
        if (pair.base === t) {
          break
        }
        ++index
        when (pair) {
          is AbstractEditOperation.Keep -> continue
          is AbstractEditOperation.Delete -> continue
          is AbstractEditOperation.Insert -> builder.add(pair.revision!!)
          else -> throw RuntimeException("Unhandled pair $pair")
        }.exhaustive
      }
      check(index < size) {
        "The given 'original' is not a sub-sequence of this alignment."
      }
      val pair = alignment[index]
      ++index
      pair.revision?.let {
        builder.add(it)
      }
    }
    while (index < size) {
      val pair = alignment[index]
      if (pair is AbstractEditOperation.Insert) {
        builder.add(pair.revision!!)
      }
      ++index
    }
    return builder.build()
  }

  private fun checkElementsShouldBeDistinct(list: Iterable<T>) {
    val empty = ""
    val visited = IdentityHashMap<T, String>()
    for (base in list) {
      check(visited.put(base, empty) == null) {
        "The object $base occurs more than once."
      }
    }
  }

  val onlyDiffs by lazy {
    alignment.filter { it !is AbstractEditOperation.Keep }
  }

  val onlyInserts by lazy {
    alignment.filter { it is AbstractEditOperation.Insert }
  }

  val onlyDeletes by lazy {
    alignment.filter { it is AbstractEditOperation.Delete }
  }

  val onlyKeeps by lazy {
    alignment.filter { it is AbstractEditOperation.Keep }
  }

  val onlyReplaces by lazy {
    alignment.filter { it is AbstractEditOperation.Replace }
  }

  abstract class Edit {
    abstract override fun equals(other: Any?): Boolean
    abstract override fun hashCode(): Int
  }

  class Delete : Edit() {
    override fun equals(other: Any?): Boolean {
      TODO("Not yet implemented")
    }

    override fun hashCode(): Int {
      TODO("Not yet implemented")
    }
  }

  class Insert : Edit() {
    override fun equals(other: Any?): Boolean {
      TODO("Not yet implemented")
    }

    override fun hashCode(): Int {
      TODO("Not yet implemented")
    }
  }

  class Keep : Edit() {
    override fun equals(other: Any?): Boolean {
      TODO("Not yet implemented")
    }

    override fun hashCode(): Int {
      TODO("Not yet implemented")
    }
  }

  companion object {

    fun <T> create(
      baseList: List<T>,
      revisionList: List<T>,
      equalizer: (T, T) -> Boolean,
    ): ListAlignment<T> {
      val patch = PersesDiffUtil.diff(baseList, revisionList, equalizer)
      val deltas = patch.deltas
        .asSequence()
        .sortedBy { it.original.position }
        .toList()

      val result = ImmutableList.builder<AbstractEditOperation<T>>()
      var index = 0

      for (delta in deltas) {
        val original = delta.original!!

        val originalIndex = original.position
        while (index < originalIndex) {
          val remainingToken = baseList[index]!!
          result.add(AbstractEditOperation.Keep(remainingToken))
          ++index
        }
        val revised = delta.revised!!

        original.lines.forEach {
          result.add(AbstractEditOperation.Delete(it))
        }
        revised.lines.forEach {
          result.add(AbstractEditOperation.Insert(it))
        }
        index += original.lines.size
      }
      while (index < baseList.size) {
        val original = baseList[index]
        ++index
        result.add(AbstractEditOperation.Keep(original))
      }
      return ListAlignment(result.build())
    }

    // Use a sliding window to convert every pairs of INSERT and DELETE surrounded by KEEP
    // to a REPLACE.
    // For example, (KEEP, DELETE, INSERT, KEEP) -> (KEEP, REPLACE, KEEP)
    // (KEEP, INSERT, DELETE, KEEP) -> (KEEP, REPLACE, KEEP)
    fun <T> mergeIntoReplace(
      listAlignment: ListAlignment<T>,
    ): ListAlignment<T> {
      val alignment = listAlignment.alignment
      var index = 0
      val alignmentWithReplace = ImmutableList.builder<AbstractEditOperation<T>>()

      while (index < alignment.size) {
        val firstOp = alignment[index]
        if (index < alignment.size - 3) {
          val secondOp = alignment[index + 1]
          val thirdOp = alignment[index + 2]
          val fourthOp = alignment[index + 3]

          if (firstOp is AbstractEditOperation.Keep &&
            secondOp is AbstractEditOperation.Delete &&
            thirdOp is AbstractEditOperation.Insert &&
            fourthOp is AbstractEditOperation.Keep
          ) {
            alignmentWithReplace.add(firstOp)
            alignmentWithReplace.add(
              AbstractEditOperation.Replace(secondOp.base, thirdOp.revision),
            )
            alignmentWithReplace.add(fourthOp)
            index += 4
          } else if (firstOp is AbstractEditOperation.Keep &&
            secondOp is AbstractEditOperation.Insert &&
            thirdOp is AbstractEditOperation.Delete &&
            fourthOp is AbstractEditOperation.Keep
          ) {
            alignmentWithReplace.add(firstOp)
            alignmentWithReplace.add(
              AbstractEditOperation.Replace(thirdOp.base, secondOp.revision),
            )
            alignmentWithReplace.add(fourthOp)
            index += 4
          } else {
            alignmentWithReplace.add(firstOp)
            index += 1
          }
        }
        // sliding window exceeds the list
        else {
          alignmentWithReplace.add(firstOp)
          index += 1
        }
      }
      return ListAlignment(alignmentWithReplace.build())
    }

    fun <T> splitReplace(
      listAlignmentWithReplace: ListAlignment<T>,
    ): ListAlignment<T> {
      val alignmentWithReplace = listAlignmentWithReplace.alignment
      val alignmentWithoutReplace = ImmutableList.builder<AbstractEditOperation<T>>()

      for (op in alignmentWithReplace) {
        if (op is AbstractEditOperation.Replace) {
          alignmentWithoutReplace.add(AbstractEditOperation.Delete(op.base))
          alignmentWithoutReplace.add(AbstractEditOperation.Insert(op.revision))
        } else {
          alignmentWithoutReplace.add(op)
        }
      }
      return ListAlignment(alignmentWithoutReplace.build())
    }
  }
}

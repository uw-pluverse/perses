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
package org.perses.util

/**
 * An immutable array of [Int]s with no encapsulation overhead: this is a Kotlin inline value
 * class, so an [ImmutableIntArray] *is* its backing [IntArray] at the bytecode level. Accessors
 * such as [size] and [get] compile down to direct array operations with no boxing and no wrapper
 * allocation.
 *
 * The class is modeled on Guava's `com.google.common.primitives.ImmutableIntArray`, but it is
 * allocation-free and additionally implements [Comparable] using lexicographical order.
 *
 * Immutability is guaranteed by construction: the backing array is owned by exactly one instance
 * and never escapes. Build instances with the copying factories ([of], [copyOf]) or, to avoid the
 * defensive copy when appending many values, with a [Builder] that owns its backing array.
 *
 * Equality note: Kotlin (as of language version 2.1) does not allow a value class to override
 * `equals`/`hashCode`, so `==` and `hashCode` keep the inherited *identity* semantics of the
 * backing array — two distinct instances with equal contents are not `==`, and they hash
 * differently. For content comparison use [contentEquals]/[contentHashCode], or [compareTo]
 * (which is content-based, so ordered containers such as `TreeSet` and `sortedSet`/`sorted`
 * behave by content).
 *
 * Note that the entire class will be inlined. If you need to add new methods, mark them 'inline'
 * too whenever they should stay allocation-free.
 */
@JvmInline
value class ImmutableIntArray
  @PublishedApi
  internal constructor(
    // The array is never mutated after construction and never escapes this class, so the value
    // class can be treated as deeply immutable.
    @PublishedApi internal val array: IntArray,
  ) : Comparable<ImmutableIntArray> {
    inline val size: Int
      get() = array.size

    inline val lastIndex: Int
      get() = array.size - 1

    @Suppress("NOTHING_TO_INLINE")
    inline fun isEmpty(): Boolean = array.isEmpty()

    @Suppress("NOTHING_TO_INLINE")
    inline fun isNotEmpty(): Boolean = array.isNotEmpty()

    @Suppress("NOTHING_TO_INLINE")
    inline operator fun get(index: Int): Int = array[index]

    /** Kotlin idiom for Guava's `forEach(IntConsumer)`; the [action] lambda is inlined. */
    inline fun forEach(action: (Int) -> Unit) {
      for (element in array) {
        action(element)
      }
    }

    /** Returns the index of the first appearance of [target], or `-1` if it is absent. */
    fun indexOf(target: Int): Int {
      for (i in array.indices) {
        if (array[i] == target) {
          return i
        }
      }
      return -1
    }

    /** Returns the index of the last appearance of [target], or `-1` if it is absent. */
    fun lastIndexOf(target: Int): Int {
      for (i in array.indices.reversed()) {
        if (array[i] == target) {
          return i
        }
      }
      return -1
    }

    fun contains(target: Int): Boolean = indexOf(target) >= 0

    /**
     * Returns a new [ImmutableIntArray] holding the values from [fromIndex] (inclusive) to
     * [toIndex] (exclusive). The values are copied, since a value class cannot hold a windowed view.
     */
    fun subArray(
      fromIndex: Int,
      toIndex: Int,
    ): ImmutableIntArray {
      if (fromIndex == toIndex) {
        return EMPTY
      }
      return ImmutableIntArray(array.copyOfRange(fromIndex, toIndex))
    }

    /** Returns a fresh mutable copy of the contents; mutating it does not affect this instance. */
    fun toIntArray(): IntArray = array.copyOf()

    /** Compares lexicographically; a shorter array that is a prefix of the other sorts first. */
    override fun compareTo(other: ImmutableIntArray): Int {
      val a = array
      val b = other.array
      val commonLength = minOf(a.size, b.size)
      var i = 0
      while (i < commonLength) {
        if (a[i] != b[i]) {
          return a[i].compareTo(b[i])
        }
        i += 1
      }
      return a.size - b.size
    }

    /**
     * Returns `true` if this array is component-wise greater than or equal to [other]: every
     * element is `>=` the element at the same index. Unlike [compareTo] (a total, lexicographical
     * order), this is a partial order — two arrays can be mutually non-dominating (e.g. `[2, 1]`
     * and `[1, 2]`). Both arrays must have the same [size].
     */
    fun isComponentwiseGreaterThanOrEqualTo(other: ImmutableIntArray): Boolean {
      val a = array
      val b = other.array
      require(a.size == b.size) {
        "Component-wise comparison requires equal lengths: ${a.size} vs ${b.size}"
      }
      for (i in a.indices) {
        if (a[i] < b[i]) {
          return false
        }
      }
      return true
    }

    /** Returns `true` if [other] holds the same values in the same order. */
    fun contentEquals(other: ImmutableIntArray): Boolean = array.contentEquals(other.array)

    /** A content-based hash, consistent with [contentEquals] (unlike [hashCode]). */
    fun contentHashCode(): Int = array.contentHashCode()

    /** Returns a representation in the form `[1, 2, 3]`, like `Arrays.toString(int[])`. */
    override fun toString(): String = array.contentToString()

    companion object {
      val EMPTY = ImmutableIntArray(IntArray(0))

      /** Returns an array containing [values]; the input is defensively copied. */
      fun of(vararg values: Int): ImmutableIntArray =
        if (values.isEmpty()) EMPTY else ImmutableIntArray(values.copyOf())

      /** Returns an array containing the values of [values]; the input is defensively copied. */
      fun copyOf(values: IntArray): ImmutableIntArray =
        if (values.isEmpty()) EMPTY else ImmutableIntArray(values.copyOf())

      fun copyOf(values: Collection<Int>): ImmutableIntArray =
        if (values.isEmpty()) EMPTY else builder(values.size).addAll(values).build()

      fun builder(initialCapacity: Int = DEFAULT_INITIAL_CAPACITY): Builder =
        Builder(initialCapacity)

      private const val DEFAULT_INITIAL_CAPACITY = 10
    }

    /**
     * A builder for [ImmutableIntArray] instances. The builder owns its backing array, so the
     * built instance is guaranteed to be the sole owner of its contents. The builder may continue
     * to be used after [build]; any further append reallocates rather than mutating an array that a
     * built instance may share.
     */
    class Builder
      @PublishedApi
      internal constructor(
        initialCapacity: Int,
      ) {
        private var array = IntArray(initialCapacity)

        // Invariant: count <= array.size.
        private var count = 0

        fun add(value: Int): Builder {
          ensureRoomFor(1)
          array[count] = value
          count += 1
          return this
        }

        fun addAll(values: IntArray): Builder {
          ensureRoomFor(values.size)
          System.arraycopy(values, 0, array, count, values.size)
          count += values.size
          return this
        }

        fun addAll(values: ImmutableIntArray): Builder = addAll(values.array)

        fun addAll(values: Iterable<Int>): Builder {
          if (values is Collection<Int>) {
            ensureRoomFor(values.size)
          }
          for (value in values) {
            add(value)
          }
          return this
        }

        /** Returns a new immutable array; the builder can keep being used afterward. */
        fun build(): ImmutableIntArray =
          when (count) {
            0 -> EMPTY
            // Exact fit: hand off the array. Any later append reallocates (see ensureRoomFor), so the
            // built instance never observes a mutation.
            array.size -> ImmutableIntArray(array)
            // Trim to a right-sized array that only the built instance owns.
            else -> ImmutableIntArray(array.copyOf(count))
          }

        private fun ensureRoomFor(numberToAdd: Int) {
          val newCount = count + numberToAdd
          if (newCount > array.size) {
            // Grow by 1.5x, mirroring Guava's expandedCapacity.
            array = array.copyOf(maxOf(newCount, array.size + (array.size shr 1) + 1))
          }
        }
      }
  }

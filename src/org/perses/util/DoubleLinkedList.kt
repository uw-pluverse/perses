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

class DoubleLinkedList<T> {
  class Node<T>(val value: T?, internal var list: DoubleLinkedList<T>?) {
    internal var prev: Node<T>? = null
    internal var next: Node<T>? = null
  }

  private val head = Node(value = null, list = this)
  private val tail = Node(value = null, list = this)

  init {
    head.next = tail
    tail.prev = head
  }

  fun getPrev(node: Node<T>): Node<T>? {
    val prev = node.prev ?: return null
    if (prev === head) {
      return null
    }
    return prev
  }

  fun getNext(node: Node<T>): Node<T>? {
    val next = node.next ?: return null
    if (next === tail) {
      return null
    }
    return next
  }

  fun addFirst(value: T): Node<T> {
    val newFirst = Node(value, list = this)
    val oldFirst = head.next

    oldFirst!!.prev = newFirst
    newFirst.next = oldFirst

    head.next = newFirst
    newFirst.prev = head
    return newFirst
  }

  fun addLast(value: T): Node<T> {
    val newLast = Node(value, list = this)
    val oldLast = tail.prev

    oldLast!!.next = newLast
    newLast.prev = oldLast

    newLast.next = tail
    tail.prev = newLast
    return newLast
  }

  fun remove(node: Node<T>): Node<T> {
    val prev = node.prev
    val next = node.next

    check(prev != null)
    check(next != null)
    check(node.list == this)

    node.list = null
    node.prev = null
    node.next = null

    prev.next = next
    next.prev = prev
    return node
  }

  fun isEmpty() = head.next === tail
}

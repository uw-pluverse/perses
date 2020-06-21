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

    prev!!.next = next
    next!!.prev = prev
    return node
  }

  fun isEmpty() = head.next === tail
}
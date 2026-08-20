package com.github.benmanes.caffeine.cache;

import java.util.AbstractCollection;
import javax.annotation.concurrent.NotThreadSafe;

@NotThreadSafe
abstract class AbstractLinkedDeque<E> extends AbstractCollection<E> implements LinkedDeque<E> {

    public int size() {
        throw new java.lang.Error();
    }

    public E peek() {
        throw new java.lang.Error();
    }

    public E peekFirst() {
        throw new java.lang.Error();
    }

    public E peekLast() {
        throw new java.lang.Error();
    }

    public E getFirst() {
        throw new java.lang.Error();
    }

    public E getLast() {
        throw new java.lang.Error();
    }

    public E element() {
        throw new java.lang.Error();
    }

    public boolean offer(E e) {
        throw new java.lang.Error();
    }

    public boolean offerFirst(E e) {
        throw new java.lang.Error();
    }

    public boolean offerLast(E e) {
        throw new java.lang.Error();
    }

    public void addFirst(E e) {
        throw new java.lang.Error();
    }

    public void addLast(E e) {
        throw new java.lang.Error();
    }

    public E poll() {
        throw new java.lang.Error();
    }

    public E pollFirst() {
        throw new java.lang.Error();
    }

    public E pollLast() {
        throw new java.lang.Error();
    }

    public E remove() {
        throw new java.lang.Error();
    }

    public E removeFirst() {
        throw new java.lang.Error();
    }

    public boolean removeFirstOccurrence(Object o) {
        throw new java.lang.Error();
    }

    public E removeLast() {
        throw new java.lang.Error();
    }

    public boolean removeLastOccurrence(Object o) {
        throw new java.lang.Error();
    }

    public void push(E e) {
        throw new java.lang.Error();
    }

    public E pop() {
        throw new java.lang.Error();
    }

    public PeekingIterator<E> iterator() {
        throw new java.lang.Error();
    }

    public PeekingIterator<E> descendingIterator() {
        throw new java.lang.Error();
    }
}

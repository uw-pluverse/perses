package org.apache.calcite.runtime;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

abstract class AbstractImmutableList<E> implements List<E> {

    public Iterator<E> iterator() {
        throw new java.lang.Error();
    }

    public ListIterator<E> listIterator() {
        throw new java.lang.Error();
    }

    public boolean isEmpty() {
        throw new java.lang.Error();
    }

    public boolean add(E t) {
        throw new java.lang.Error();
    }

    public boolean addAll(Collection<? extends E> c) {
        throw new java.lang.Error();
    }

    public boolean addAll(int index, Collection<? extends E> c) {
        throw new java.lang.Error();
    }

    public boolean removeAll(Collection<?> c) {
        throw new java.lang.Error();
    }

    public boolean retainAll(Collection<?> c) {
        throw new java.lang.Error();
    }

    public void clear() {
        throw new java.lang.Error();
    }

    public E set(int index, E element) {
        throw new java.lang.Error();
    }

    public void add(int index, E element) {
        throw new java.lang.Error();
    }

    public E remove(int index) {
        throw new java.lang.Error();
    }

    public ListIterator<E> listIterator(int index) {
        throw new java.lang.Error();
    }

    public List<E> subList(int fromIndex, int toIndex) {
        throw new java.lang.Error();
    }

    public boolean contains(Object o) {
        throw new java.lang.Error();
    }

    public boolean containsAll(Collection<?> c) {
        throw new java.lang.Error();
    }

    public boolean remove(Object o) {
        throw new java.lang.Error();
    }
}

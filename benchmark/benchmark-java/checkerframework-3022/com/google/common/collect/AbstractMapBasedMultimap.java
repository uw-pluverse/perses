package com.google.common.collect;

import com.google.common.annotations.GwtCompatible;
import com.google.j2objc.annotations.WeakOuter;
import java.util.AbstractCollection;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.NavigableSet;
import java.util.Set;
import java.util.SortedSet;
import org.checkerframework.checker.nullness.qual.Nullable;

@GwtCompatible
abstract class AbstractMapBasedMultimap<K, V> extends AbstractMultimap<K, V> {

    Collection<V> wrapCollection(K key, Collection<V> collection) {
        throw new java.lang.Error();
    }

    final List<V> wrapList(K key, List<V> list, @Nullable WrappedCollection ancestor) {
        throw new java.lang.Error();
    }

    @WeakOuter
    class WrappedCollection extends AbstractCollection<V> {

        WrappedCollection(K key, Collection<V> delegate, @Nullable WrappedCollection ancestor) {
            throw new java.lang.Error();
        }

        public int size() {
            throw new java.lang.Error();
        }

        public Iterator<V> iterator() {
            throw new java.lang.Error();
        }
    }

    @WeakOuter
    class WrappedSet extends WrappedCollection implements Set<V> {

        WrappedSet(K key, Set<V> delegate) {
            super(key, delegate, null);
        }
    }

    @WeakOuter
    class WrappedSortedSet extends WrappedCollection implements SortedSet<V> {

        WrappedSortedSet(K key, SortedSet<V> delegate, @Nullable WrappedCollection ancestor) {
            super(key, delegate, ancestor);
        }

        @Nullable
        public Comparator<? super V> comparator() {
            throw new java.lang.Error();
        }

        public V first() {
            throw new java.lang.Error();
        }

        public V last() {
            throw new java.lang.Error();
        }

        public SortedSet<V> headSet(V toElement) {
            throw new java.lang.Error();
        }

        public SortedSet<V> subSet(V fromElement, V toElement) {
            throw new java.lang.Error();
        }

        public SortedSet<V> tailSet(V fromElement) {
            throw new java.lang.Error();
        }
    }

    @WeakOuter
    class WrappedNavigableSet extends WrappedSortedSet implements NavigableSet<V> {

        WrappedNavigableSet(K key, NavigableSet<V> delegate, @Nullable WrappedCollection ancestor) {
            super(key, delegate, ancestor);
        }

        @Nullable
        public V lower(V v) {
            throw new java.lang.Error();
        }

        @Nullable
        public V floor(V v) {
            throw new java.lang.Error();
        }

        @Nullable
        public V ceiling(V v) {
            throw new java.lang.Error();
        }

        @Nullable
        public V higher(V v) {
            throw new java.lang.Error();
        }

        @Nullable
        public V pollFirst() {
            throw new java.lang.Error();
        }

        @Nullable
        public V pollLast() {
            throw new java.lang.Error();
        }

        public NavigableSet<V> descendingSet() {
            throw new java.lang.Error();
        }

        public Iterator<V> descendingIterator() {
            throw new java.lang.Error();
        }

        public NavigableSet<V> subSet(V fromElement, boolean fromInclusive, V toElement, boolean toInclusive) {
            throw new java.lang.Error();
        }

        public NavigableSet<V> headSet(V toElement, boolean inclusive) {
            throw new java.lang.Error();
        }

        public NavigableSet<V> tailSet(V fromElement, boolean inclusive) {
            throw new java.lang.Error();
        }
    }
}

package com.google.common.collect;

import com.google.common.annotations.GwtCompatible;
import java.util.Collection;
import java.util.List;
import java.util.NavigableSet;
import java.util.Set;
import java.util.SortedSet;

@GwtCompatible(emulated = true)
public final class Multimaps {

    private static class CustomMultimap<K, V> extends AbstractMapBasedMultimap<K, V> {

        Collection<V> wrapCollection(K key, Collection<V> collection) {
            if (collection instanceof List) {
                return wrapList(key, (List<V>) collection, null);
            } else if (collection instanceof NavigableSet) {
                return new WrappedNavigableSet(key, (NavigableSet<V>) collection, null);
            } else if (collection instanceof SortedSet) {
                return new WrappedSortedSet(key, (SortedSet<V>) collection, null);
            } else if (collection instanceof Set) {
                return new WrappedSet(key, (Set<V>) collection);
            } else {
                return new WrappedCollection(key, collection, null);
            }
        }
    }
}

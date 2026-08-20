package org.apache.cassandra.utils;

import java.util.Iterator;
import com.google.common.collect.PeekingIterator;

public abstract class AbstractIterator<V> implements Iterator<V>, PeekingIterator<V>, CloseableIterator<V> {

    public boolean hasNext() {
        throw new java.lang.Error();
    }

    public V next() {
        throw new java.lang.Error();
    }

    public void close() {
        throw new java.lang.Error();
    }
}

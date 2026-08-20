package com.github.benmanes.caffeine.cache;

import java.util.Deque;
import java.util.Iterator;
import javax.annotation.concurrent.NotThreadSafe;

@NotThreadSafe
interface LinkedDeque<E> extends Deque<E> {

    default PeekingIterator<E> iterator() {
        throw new java.lang.Error();
    }

    default PeekingIterator<E> descendingIterator() {
        throw new java.lang.Error();
    }

    interface PeekingIterator<E> extends Iterator<E> {
    }
}

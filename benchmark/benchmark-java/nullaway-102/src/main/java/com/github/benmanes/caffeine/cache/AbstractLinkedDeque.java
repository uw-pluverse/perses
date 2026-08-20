package com.github.benmanes.caffeine.cache;

import java.util.AbstractCollection;
import javax.annotation.Nullable;
import javax.annotation.concurrent.NotThreadSafe;

@NotThreadSafe
abstract class AbstractLinkedDeque<E> extends AbstractCollection<E> implements LinkedDeque<E> {

    @Nullable
    E first;

    public int size() {
        throw new java.lang.Error();
    }

    public PeekingIterator<E> iterator() {
        return new AbstractLinkedIterator(first) {

            @Nullable
            E computeNext() {
                return getNext(cursor);
            }
        };
    }

    abstract class AbstractLinkedIterator implements PeekingIterator<E> {

        @Nullable
        E cursor;

        AbstractLinkedIterator(@Nullable E start) {
            throw new java.lang.Error();
        }

        public boolean hasNext() {
            throw new java.lang.Error();
        }

        @SuppressWarnings("NullAway")
        public E next() {
            throw new java.lang.Error();
        }

        @Nullable
        abstract E computeNext();
    }
}

package com.github.benmanes.caffeine.cache;

import javax.annotation.concurrent.NotThreadSafe;
import com.github.benmanes.caffeine.cache.WriteOrderDeque.WriteOrder;

@NotThreadSafe
final class WriteOrderDeque<E extends WriteOrder<E>> extends AbstractLinkedDeque<E> {

    interface WriteOrder<T extends WriteOrder<T>> {
    }
}

package com.github.benmanes.caffeine.cache;

import javax.annotation.concurrent.NotThreadSafe;
import com.github.benmanes.caffeine.cache.AccessOrderDeque.AccessOrder;

@NotThreadSafe
final class AccessOrderDeque<E extends AccessOrder<E>> extends AbstractLinkedDeque<E> {

    interface AccessOrder<T extends AccessOrder<T>> {
    }
}

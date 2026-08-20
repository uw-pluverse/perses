package com.github.benmanes.caffeine.cache;

import javax.annotation.Nonnegative;
import javax.annotation.Nullable;
import javax.annotation.concurrent.GuardedBy;
import com.github.benmanes.caffeine.cache.AccessOrderDeque.AccessOrder;
import com.github.benmanes.caffeine.cache.WriteOrderDeque.WriteOrder;

@SuppressWarnings({ "GuardedByChecker", "GuardedByValidator" })
abstract class Node<K, V> implements AccessOrder<Node<K, V>>, WriteOrder<Node<K, V>> {

    @Nullable
    public abstract K getKey();

    @Nonnegative
    @GuardedBy("evictionLock")
    public int getPolicyWeight() {
        throw new java.lang.Error();
    }

    public static final int EDEN = 0;

    public static final int PROBATION = 0;

    public static final int PROTECTED = 0;

    @GuardedBy("evictionLock")
    @Nullable
    public Node<K, V> getPreviousInAccessOrder() {
        throw new java.lang.Error();
    }

    @GuardedBy("evictionLock")
    @Nullable
    public Node<K, V> getNextInAccessOrder() {
        throw new java.lang.Error();
    }
}

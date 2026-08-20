package com.google.common.collect;

import com.google.common.annotations.GwtCompatible;
import com.google.errorprone.annotations.CanIgnoreReturnValue;
import java.util.Collection;
import java.util.Map;
import java.util.Set;
import org.checkerframework.checker.nullness.qual.Nullable;

@GwtCompatible
public abstract class ForwardingMap<K, V> extends ForwardingObject implements Map<K, V> {

    public int size() {
        throw new java.lang.Error();
    }

    public boolean isEmpty() {
        throw new java.lang.Error();
    }

    @CanIgnoreReturnValue
    @Nullable
    public V remove(@Nullable Object object) {
        throw new java.lang.Error();
    }

    public void clear() {
        throw new java.lang.Error();
    }

    public boolean containsKey(@Nullable Object key) {
        throw new java.lang.Error();
    }

    public boolean containsValue(@Nullable Object value) {
        throw new java.lang.Error();
    }

    @Nullable
    public V get(@Nullable Object key) {
        throw new java.lang.Error();
    }

    @CanIgnoreReturnValue
    @Nullable
    public V put(K key, V value) {
        throw new java.lang.Error();
    }

    public void putAll(Map<? extends K, ? extends V> map) {
        throw new java.lang.Error();
    }

    public Set<K> keySet() {
        throw new java.lang.Error();
    }

    public Collection<V> values() {
        throw new java.lang.Error();
    }

    public Set<Entry<K, V>> entrySet() {
        throw new java.lang.Error();
    }
}

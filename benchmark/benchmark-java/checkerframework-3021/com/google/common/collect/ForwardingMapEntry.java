package com.google.common.collect;

import com.google.common.annotations.GwtCompatible;
import java.util.Map;
import java.util.Map.Entry;

@GwtCompatible
public abstract class ForwardingMapEntry<K, V> extends ForwardingObject implements Map.Entry<K, V> {

    protected ForwardingMapEntry() {
        throw new java.lang.Error();
    }

    protected abstract Entry<K, V> delegate();

    public K getKey() {
        throw new java.lang.Error();
    }

    public V getValue() {
        throw new java.lang.Error();
    }

    public V setValue(V value) {
        throw new java.lang.Error();
    }
}

package com.github.benmanes.caffeine.cache;

import org.checkerframework.checker.nullness.qual.Nullable;
import com.github.benmanes.caffeine.cache.Async.AsyncEvictionListener;

public final class Caffeine<K, V> {

    @Nullable
    RemovalListener<? super K, ? super V> evictionListener;

    @SuppressWarnings({ "rawtypes", "unchecked" })
    @Nullable
    <K1 extends K, V1 extends V> RemovalListener<K1, V1> getEvictionListener(boolean async) {
        var castedListener = (RemovalListener<K1, V1>) evictionListener;
        return async && (castedListener != null) ? new AsyncEvictionListener(castedListener) : castedListener;
    }
}

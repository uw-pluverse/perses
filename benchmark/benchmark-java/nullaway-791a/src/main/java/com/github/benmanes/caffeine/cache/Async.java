package com.github.benmanes.caffeine.cache;

import java.util.concurrent.CompletableFuture;

@SuppressWarnings("serial")
final class Async {

    static final class AsyncEvictionListener<K, V> implements RemovalListener<K, CompletableFuture<V>> {

        AsyncEvictionListener(RemovalListener<K, V> delegate) {
            throw new java.lang.Error();
        }
    }
}

package com.github.benmanes.caffeine.cache;

import java.util.concurrent.ConcurrentMap;

interface LocalCache<K, V> extends ConcurrentMap<K, V> {
}

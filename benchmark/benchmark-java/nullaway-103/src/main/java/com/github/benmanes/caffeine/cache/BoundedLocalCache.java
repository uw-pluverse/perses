package com.github.benmanes.caffeine.cache;

import static com.github.benmanes.caffeine.cache.Node.EDEN;
import static com.github.benmanes.caffeine.cache.Node.PROBATION;
import static com.github.benmanes.caffeine.cache.Node.PROTECTED;
import java.util.AbstractMap;
import java.util.Map;
import java.util.Set;
import javax.annotation.concurrent.GuardedBy;
import javax.annotation.concurrent.ThreadSafe;

@ThreadSafe
abstract class BoundedLocalCache<K, V> extends BLCHeader.DrainStatusRef<K, V> implements LocalCache<K, V> {

    @GuardedBy("evictionLock")
    protected AccessOrderDeque<Node<K, V>> accessOrderEdenDeque() {
        throw new java.lang.Error();
    }

    @GuardedBy("evictionLock")
    protected AccessOrderDeque<Node<K, V>> accessOrderProbationDeque() {
        throw new java.lang.Error();
    }

    @GuardedBy("evictionLock")
    protected AccessOrderDeque<Node<K, V>> accessOrderProtectedDeque() {
        throw new java.lang.Error();
    }

    protected long maximum() {
        throw new java.lang.Error();
    }

    protected long weightedSize() {
        throw new java.lang.Error();
    }

    @GuardedBy("evictionLock")
    void evictFromMain(int candidates) {
        int victimQueue = PROBATION;
        Node<K, V> victim = accessOrderProbationDeque().peekFirst();
        Node<K, V> candidate = accessOrderProbationDeque().peekLast();
        while (weightedSize() > maximum()) {
            if (candidates == 0) {
                candidate = null;
            }
            if ((candidate == null) && (victim == null)) {
                if (victimQueue == PROBATION) {
                    victim = accessOrderProtectedDeque().peekFirst();
                    victimQueue = PROTECTED;
                    continue;
                } else if (victimQueue == PROTECTED) {
                    victim = accessOrderEdenDeque().peekFirst();
                    victimQueue = EDEN;
                    continue;
                }
                break;
            }
            if ((victim != null) && (victim.getPolicyWeight() == 0)) {
                victim = victim.getNextInAccessOrder();
                continue;
            } else if ((candidate != null) && (candidate.getPolicyWeight() == 0)) {
                candidate = candidate.getPreviousInAccessOrder();
                candidates--;
                continue;
            }
            if (victim == null) {
                candidates--;
                Node<K, V> evict = candidate;
                candidate = candidate.getPreviousInAccessOrder();
                evictEntry(evict, RemovalCause.SIZE, 0L);
                continue;
            } else if (candidate == null) {
                Node<K, V> evict = victim;
                victim = victim.getNextInAccessOrder();
                evictEntry(evict, RemovalCause.SIZE, 0L);
                continue;
            }
            K victimKey = victim.getKey();
            K candidateKey = candidate.getKey();
            if (victimKey == null) {
                Node<K, V> evict = victim;
                victim = victim.getNextInAccessOrder();
                evictEntry(evict, RemovalCause.COLLECTED, 0L);
                continue;
            } else if (candidateKey == null) {
                candidates--;
                Node<K, V> evict = candidate;
                candidate = candidate.getPreviousInAccessOrder();
                evictEntry(evict, RemovalCause.COLLECTED, 0L);
                continue;
            }
            if (candidate.getPolicyWeight() > maximum()) {
                candidates--;
                Node<K, V> evict = candidate;
                candidate = candidate.getPreviousInAccessOrder();
                evictEntry(evict, RemovalCause.SIZE, 0L);
                continue;
            }
            candidates--;
            if (admit(candidateKey, victimKey)) {
                Node<K, V> evict = victim;
                victim = victim.getNextInAccessOrder();
                evictEntry(evict, RemovalCause.SIZE, 0L);
                candidate = candidate.getPreviousInAccessOrder();
            } else {
                Node<K, V> evict = candidate;
                candidate = candidate.getPreviousInAccessOrder();
                evictEntry(evict, RemovalCause.SIZE, 0L);
            }
        }
    }

    @GuardedBy("evictionLock")
    boolean admit(K candidateKey, K victimKey) {
        throw new java.lang.Error();
    }

    @GuardedBy("evictionLock")
    @SuppressWarnings({ "PMD.CollapsibleIfStatements", "GuardedByChecker" })
    boolean evictEntry(Node<K, V> node, RemovalCause cause, long now) {
        throw new java.lang.Error();
    }

    public Set<Entry<K, V>> entrySet() {
        throw new java.lang.Error();
    }
}

final class BLCHeader {

    abstract static class PadDrainStatus<K, V> extends AbstractMap<K, V> {
    }

    abstract static class DrainStatusRef<K, V> extends PadDrainStatus<K, V> {
    }
}

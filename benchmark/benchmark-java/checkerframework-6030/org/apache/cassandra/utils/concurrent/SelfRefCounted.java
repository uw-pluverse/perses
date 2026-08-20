package org.apache.cassandra.utils.concurrent;

public interface SelfRefCounted<T extends SelfRefCounted<T>> extends RefCounted<T> {
}

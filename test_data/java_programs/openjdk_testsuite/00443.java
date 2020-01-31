



package InnerInterface1;

interface Iterator<E> {
}

class Set<E> {
    Iterator<E> iterator() { return null; }
}

interface Map<K,V> {
    public interface Entry<K,V> {
    }
    public Set<Entry<K,V>> entrySet();
}

class Hashtable<K,V> implements Map<K,V> {
    public Set<Entry<K,V>> entrySet() { return null; }

    public void foo() {
        Iterator<Map.Entry<K,V>> it = entrySet().iterator();
    }
}

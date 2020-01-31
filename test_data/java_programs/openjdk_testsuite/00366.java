



import java.lang.ref.*;

class Test<K, V> extends WeakReference<V> {
    static ReferenceQueue<Integer> queue = new ReferenceQueue<Integer>();

    public Test(K key, V value, ReferenceQueue<V> queue) {
        super(value, queue);
    }

    public static void main(String[] arg) throws Exception {
        Test<String, Integer> fromQueue = (Test<String, Integer>) queue.remove();
    }
}

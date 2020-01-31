

class T6315770<V> {
    <T extends Integer & Runnable> T6315770<T> m() {
        return null;
    }
    void test() {
        T6315770<?> c1 = m();
        T6315770<? extends String> c2 = m();
        T6315770<? super String> c3 = m();
    }
}




class T8130304 {

    void test() {
        outer(
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner(),
            inner());
    }

    <T> void outer(T... ts) { }

    <T,V,W extends V> T inner() {
        return null;
    }
}

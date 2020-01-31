

class T7034511b {
    static class MyList<E> {
        E toArray(E[] e) { return null; }
    }

    void test(MyList<?> ml, Object o[]) {
        ml.toArray(o);
    }
}

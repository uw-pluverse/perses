



class VarargsAndWildcardParameterizedTypeTest2 {
    interface I {
        <T> void m(Box<? extends T> iter, T... t);
    }

    interface Box<T> {}

    void m(I i, Box<? extends Number> b) {
        i.m(b);
    }
}

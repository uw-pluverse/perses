



class VarargsAndWildcardParameterizedTypeTest2 {
    interface I {
        <T> void m(T... t);
    }

    interface Box<T> {
        T get();
    }

    void m(I i, Box<? extends Number> b) {
        i.m(b.get());
    }
}

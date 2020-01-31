





class IncompatibleArgTypesInMethodRef {
    interface SAM<X> {
        void m(X x);
    }

    void g(String s, Integer i) { }
    void g(Integer i, String s) { }

    <Z> void m(SAM<Z> s) { }

    void test() {
        m(this::g);
    }
}

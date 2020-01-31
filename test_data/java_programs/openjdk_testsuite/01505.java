





class RefAmbiguousFragment {

    interface SAM {
        void m(Integer i1, Integer i2);
    }

    void f(Number n, Integer i) { }
    void f(Integer i, Number n) { }

    void test() {
        SAM s = RefAmbiguousFragment::f;
    }
}

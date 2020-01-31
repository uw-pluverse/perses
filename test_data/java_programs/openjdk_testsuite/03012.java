

class TargetType33 {

    interface A<X> {
        X m();
    }

    void m(A<Integer> a) { }
    <Z> void m2(A<Z> a) { }

    int intRes(Object o) { return 42; }

    void testMethodRef(boolean flag) {
        A<Integer> c = flag ? this::intRes : this::intRes;
        m(flag ? this::intRes : this::intRes);
        m2(flag ? this::intRes : this::intRes);
    }
}

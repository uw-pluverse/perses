


class TargetType64 {
    interface SAM<X extends Number> {
        void m(X x);
    }

    void g(Object o) { }

    void test() {
        SAM<?> s1 = (x)->{};
        SAM<?> s2 = this::g;
    }
}

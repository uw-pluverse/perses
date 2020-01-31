


class TargetType75 {
    interface P<X> {
        void m(X x);
    }

    <Z> void m(P<Z> r, Z z) { }

    void test() {
        m(x->{ return; }, "");
        m(x->System.out.println(""), "");
    }
}

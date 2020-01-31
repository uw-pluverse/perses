


class MethodReference55<X> {

    interface V {
        void m(Object o);
    }

    V v = new MethodReference55<String>()::m;

    void test() {
        g(new MethodReference55<String>()::m);
    }

    void g(V v) { }

    static void m(Object o) { };
}

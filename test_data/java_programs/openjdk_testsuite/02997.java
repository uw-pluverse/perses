


class MethodReference56<X> {

    interface V {
        void m(Object o);
    }

    V v = MethodReference56<String>::m;

    void test() {
        g(MethodReference56<String>::m);
    }

    void g(V v) { }

    static void m(Object o) { };
}

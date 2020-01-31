
class T8020147 {
    interface Function<X, Y> {
        Y apply(X x);
    }

    <T> void g(Function<String, T> f) { }
    <U> String m(U u, Function<U, U> fuu) { return null; }

    void test() {
        g(x->m("", i->(String)i));
        g(x->m("", i->(String)x));
    }
}

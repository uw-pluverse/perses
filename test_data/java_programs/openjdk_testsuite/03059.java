
class MethodReference69 {
    interface F<X> {
        String m(Integer x1, X x2);
    }

    static class Foo {
        String getNameAt(Integer i) { return ""; }
    }

    <Z> void g(F<Z> fz) { }

    void test() {
         g(Foo::getName);
    }
}

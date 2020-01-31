
class MethodReference68 {
    interface F<X> {
       String m(X x);
    }

    static class Foo {
        String getName() { return ""; }
    }

    @SuppressWarnings("unchecked")
    <Z> void g(F<Z> fz, Z... zs) { }

    void test() {
         g(Foo::getName);
         g(Foo::getName, 1); 
    }
}

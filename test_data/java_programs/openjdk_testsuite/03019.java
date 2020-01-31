
class MethodReference72 {
    interface F<X> {
        @SuppressWarnings("unchecked")
        void m(X... x);
    }

    void m1(Integer i) { }

    <Z> void g(F<Z> f) { }

    void test() {
        g(this::m1); 
    }
}

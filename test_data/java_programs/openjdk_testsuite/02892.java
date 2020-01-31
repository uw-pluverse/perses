
class MethodReference71 {
    interface F<X> {
        void m(X x);
    }

    interface G<X> {
        Integer m(X x);
    }

    void m1(Integer i) { }
    void m2(Integer... i) { }

    <Z> void g(F<Z> f) { }
    <Z> void g(G<Z> g) { }

    void test() {
         g(this::m1); 
         g(this::m2); 
    }
}

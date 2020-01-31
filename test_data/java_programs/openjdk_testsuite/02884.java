
class MethodReference70 {
    interface F<X> {
        void m(X x);
    }

    interface G<X> {
        Integer m(X x);
    }

    void m1(Integer i) { }

    void m2(Integer i) { }
    void m2(String i) { }

    <Z> void g(F<Z> fz) { }
    <Z> void g(G<Z> gz) { }

    void test() {
         g(this::m1); 
         g(this::m2); 
    }
}

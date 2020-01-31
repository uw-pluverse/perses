
class TargetType60 {

    interface Sam0 {
        void m();
    }

    interface Sam1<X> {
        void m(X x);
    }

    interface Sam2<X,Y> {
        void m(X x, Y y);
    }

    void m0() { }
    void m1(String s) { }
    void m2(String s1, String s2) { }

    void m01() { }
    void m01(String s) { }

    void m012() { }
    void m012(String s) { }
    void m012(String s1, String s2) { }

    void n0() { }
    void n1(String s) { }
    void n2(TargetType60 rec, String s2) { }

    void n01() { }
    void n01(String s) { }

    void n012() { }
    void n012(String s) { }
    void n012(TargetType60 rec, String s2) { }

    static String g(Sam0 s) { return null; }
    static <U> U g(Sam1<U> s) { return null; }
    static <U> U g(Sam2<U,String> s) { return null; }

    static <U> U u(Sam1<U> s) { return null; }
    static <U> U u(Sam2<U,String> s) { return null; }

    void testBound() {
        String s1 = g(this::m0); 
        String s2 = g(this::m1); 
        String s3 = g(this::m2); 
        String s4 = g(this::m01);
        String s5 = g(this::m012);
    }

    static void testUnbound() {
        TargetType60 s1 = u(TargetType60::n0); 
        TargetType60 s2 = u(TargetType60::n1); 
        TargetType60 s3 = u(TargetType60::n2); 
        TargetType60 s4 = u(TargetType60::n01);
        TargetType60 s5 = u(TargetType60::n012);
    }
}

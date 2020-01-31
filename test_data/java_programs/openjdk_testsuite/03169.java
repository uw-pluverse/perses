
class TargetType63 {

    interface F<T extends Throwable> {
        void m() throws T;
    }

    void g1() { }
    void g2() throws ClassNotFoundException { }
    void g3() throws Exception { }

    <Z extends Throwable> void m1(F<Z> fz) throws Z { }
    <Z extends ClassNotFoundException> void m2(F<Z> fz) throws Z { }

    void test1() {
        m1(()->{ }); 
        m1(this::g1); 
    }

    void test2() {
        m2(()->{ }); 
        m2(this::g1); 
    }

    void test3() {
        m1(()->{ throw new ClassNotFoundException(); }); 
        m1(this::g2); 
        m2(()->{ throw new ClassNotFoundException(); }); 
        m2(this::g2); 
    }

    void test4() {
        m1(()->{ throw new Exception(); }); 
        m1(this::g3); 
    }
}

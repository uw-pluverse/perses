



interface I {
    void m(J x);
}

interface J extends I {
    void m(I x);
}

abstract class A1 implements J {
    void test(J x) {
        this.m(x); 
    }
}

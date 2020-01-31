



abstract class I {
    abstract void m(J x);
}

abstract class J extends I {
    abstract void m(I x);
}

abstract class A2 extends J {
    void test(J x) {
        this.m(x); 
    }
}

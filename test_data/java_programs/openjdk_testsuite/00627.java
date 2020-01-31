



abstract class I {
    abstract void m(J x);
}

abstract class J extends I {
    abstract void m(I x);
}

class T {
    void test(J x) {
        x.m(x); 
    }
}

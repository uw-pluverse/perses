



interface I {
    void m(J x);
}

interface J extends I {
    void m(I x);
}

class T {
    void test(J x) {
        x.m(x); 
    }
}

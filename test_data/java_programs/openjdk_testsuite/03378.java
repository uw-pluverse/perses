

class T8012003c {

    interface I {
        void m(P p);
    }

    void m(I i) { }

    void test() {
        m(p->p.m());
    }
}

class P {
    private void m() { }
}

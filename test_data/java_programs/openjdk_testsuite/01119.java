










class ProbFoundReqFragment {

    interface I {
        void g(int i);
    }

    void m(String s) { }

    void test() {
        I i = this::m;
    }
}

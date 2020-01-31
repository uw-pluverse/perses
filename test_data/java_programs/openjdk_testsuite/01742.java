



class Pos16 {
    interface I {
        default String m(Integer i) { return ""; }
    }

    class C implements I {
        Integer m(Object o) { return 1; }
    }

    void test(C c) {
        c.m(1).length();
    }
}



public class T4880220 {
    void m1() {
        int good_1 = C.m();
        int good_2 = C.f;
        int good_3 = C.x;

        C c = new C();
        int bad_inst_1 = c.m();
        int bad_inst_2 = c.f;
        int bad_inst_3 = c.x;

        int bad_expr_1 = c().m();
        int bad_expr_2 = c().f;
        int bad_expr_3 = c().x;
    }

    void m2() {
        Class<?> good_1 = C.class;
        Class<?> good_2 = C[].class;
    }

    C c() {
        return new C();
    }

    static class C {
        static int m() { return 0; }
        static int f;
        static final int x = 3;
    }
}





class Pos04 {
    interface A { default int m() { return Pos04.m(this); } }
    static abstract class B { public int m() { return 0; } }

    static class C extends B implements A {
        void test() {
            C.this.m();
            A.super.m();
        }
    }

    static int m(A a) { return 0; }
}

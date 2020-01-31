

class Neg06 {

    interface A {
        default String m() { C.m(); }
    }

    static class C {
        static String m() { return ""; }
    }
}

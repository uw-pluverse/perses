



class Pos08 {
    interface A {
        default void m() { Pos08.a(this); }
    }

    interface B {
        default void m() { Pos08.b(this); }
    }

    interface C extends A, B {
        default void m() { Pos08.b(this); }
    }

    static void a(A o) { }
    static void b(B o) { }
}





class Pos11 {
    interface A {
        default void get() { Pos11.one(this); }
    }

    interface B {
        default void get() { Pos11.two(this); }
    }

    interface C extends A {
        default void get() { Pos11.two(this); }
    }

    interface D extends A, B {
        default void get() { Pos11.two(this); }
    }

    static class X implements C { }

    static class Y implements C, A { }

    static class Z implements D, A, B { }

    static void one(Object a) {  }
    static void two(Object a) {  }
}

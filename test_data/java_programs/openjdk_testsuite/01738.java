



class Pos07 {
    interface A {
         default void foo() { Pos07.impl(this); }
         default void bar() { Pos07.impl(this); }
    }

    static class C implements B, A {}

    interface B extends A {
        default void foo() { Pos07.impl(this); }
    }

    static void impl(A a) {}
}

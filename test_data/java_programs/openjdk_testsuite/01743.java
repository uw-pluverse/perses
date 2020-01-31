
class Neg16 {
    interface I { default void m() {  } }
    interface J extends I { default void m() {  } }

    static class C implements I, J {
        void foo() { I.super.m(); }
    }
}

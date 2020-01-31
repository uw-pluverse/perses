
class Neg15 {
    interface I { default void m() {  } }
    interface J extends I { default void m() {  } }
    interface K extends I {}

    static class C implements J, K {
        void foo() { K.super.m(); }
    }
}


class Neg08 {
    interface I {
        default void m() { }
    }

    static class C1 {
        void m() { } 
    }

    static class C2 extends C1 implements I { }

    static class C3 implements I {
        void m() { } 
    }
}

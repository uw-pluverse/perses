

class Neg03 {
    interface A {
        default void m() { Neg03.one(this); }
    }

    interface B {
        default void m() { Neg03.two(this); }
    }

    interface C extends A, B {
        default void m() { Neg03.one(this); }
    }

    static class X implements C, A { } 

    interface D extends A, B {
      void m();  
    }

    static class Y implements D, A { } 

    interface E extends A {
        void m();  
    }

    static class W implements D, E { } 

    static class Z implements D, A, B { } 

    static void one(Object a) {  }
    static void two(Object a) {  }
}

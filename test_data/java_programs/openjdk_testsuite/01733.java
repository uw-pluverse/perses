



class Pos06 {
     interface A {
         default void m() { Pos06.impl(this); }
     }

     interface B extends A {
         default void m() { Pos06.impl(this); }
     }

     static class X implements A, B { }

     void test(X x) {
         x.m();
         ((A)x).m();
         ((B)x).m();
     }

     static void impl(Object a) { }
}

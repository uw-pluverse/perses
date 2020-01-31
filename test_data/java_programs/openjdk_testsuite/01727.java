

class Neg02 {
     interface A {
         default void m() { Neg02.impl(this); }
     }

     interface B {
         default void m() { Neg02.impl(this); }
     }

     static class X implements A, B { } 

     void test(X x) {
         x.m();
         ((A)x).m();
         ((B)x).m();
     }

     static void impl(A a) { }
     static void impl(B b) { }
}

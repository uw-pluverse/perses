



class Pos05  {
     interface A {
         default void m() { Pos05.impl(this); }
     }

     interface B extends A { }

     static class E implements B { }

     void test(E e) {
         e.m();
     }

     static void impl(A a) { }
}

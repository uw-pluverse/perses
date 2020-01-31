



class Conditional03 {

   void m1(Object o) { }
   void m2(int i) { }

   void test(boolean cond) {
       m1((cond ? 1 : 1));
       m1((cond ? box(1) : box(1)));
   }

   Integer box(int i) { return i; }
}



class T8020286 {
   void m(String s) { }
   void m(Integer i, String s) { }
   void test() {
       m(1, 1);
       m(1);
   }
}

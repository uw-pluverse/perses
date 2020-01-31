

class DiagnosticRewriterTest {
   void test() {
      new Object() {
         void g() {
            m(2L);
         }
      };
   }

   void m(int i) { }
}

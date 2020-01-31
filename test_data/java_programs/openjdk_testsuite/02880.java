


public class LambdaExpr16 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface A { void m(); }

    static class Sup {
       void m() {
          assertTrue(true);
       }
    }

    static class Sub extends Sup {
        void testLambda1() {
            A a = ()->{ super.m(); };
            a.m();
        }
        void testLambda2() {
            A a = () -> { A a1 = () -> { super.m(); }; a1.m(); };
            a.m();
        }
        void testRef1() {
            A a = () -> { A a1 = super::m; a1.m(); };
            a.m();
        }
        void testRef2() {
            A a = () -> { A a1 = () -> { A a2 = super::m; a2.m(); }; a1.m(); };
            a.m();
        }
    }

   public static void main(String[] args) {
      Sub s = new Sub();
      s.testLambda1();
      s.testLambda2();
      s.testRef1();
      s.testRef2();
      assertTrue(assertionCount == 4);
   }
}

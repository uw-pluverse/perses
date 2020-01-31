


public class LambdaExpr17 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        void m();
    }

    static class Sup {
        protected String m() {
            assertTrue(true);
            return "Hello!";
        }
    }

    static class Sub extends Sup {
        void test() {
            SAM s = () -> { System.out.println(super.m()); };
            s.m();
        }
    }

    public static void main(String[] args) {
        new Sub().test();
        assertTrue(assertionCount == 1);
    }
}

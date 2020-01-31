


public class LambdaConv23 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM { void m(Integer a, Integer b); }

    static class Super {
        void m(Object... vi) { assertTrue(true); }
    }


    static class Sub extends Super {

        void m(Object... vi) { assertTrue(false); }

        public void test() {
            SAM q = super::m;
            q.m(1, 2);
        }
    }

    public static void main(String[] args) {
        new Sub().test();
        assertTrue(assertionCount == 1);
    }
}

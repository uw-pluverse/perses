


public class Static01 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface I {
        public static void test() {
            assertTrue(true);
        }
    }

    public static void main(String[] args) {
        I.test();
        assertTrue(assertionCount == 1);
    }
}

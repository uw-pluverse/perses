



public class MethodReference17 {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    MethodReference17() {
        assertTrue(true);
    }

    interface SAM {
        MethodReference17 m();
    }

    static void test(SAM s) {
        s.m();
    }

    public static void main(String[] args) {
        SAM s = MethodReference17::new;
        s.m();
        test(MethodReference17::new);
        assertTrue(assertionCount == 2);
    }
}

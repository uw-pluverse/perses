



public class MethodReference18 {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    MethodReference18(Object o) {
        assertTrue(true);
    }

    MethodReference18(Number n) {
        assertTrue(false);
    }

    interface SAM {
        MethodReference18 m(Object o);
    }

    static void test(SAM s, Object arg) {
        s.m(arg);
    }

    public static void main(String[] args) {
        SAM s = MethodReference18::new;
        s.m("");
        test(MethodReference18::new, "");
        assertTrue(assertionCount == 2);
    }
}

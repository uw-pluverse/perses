



public class MethodReference19<X> {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    MethodReference19(X x) {
        assertTrue(true);
    }

    interface SAM<Z> {
        MethodReference19<Z> m(Z z);
    }

    static <Y> void test(SAM<Y> s, Y arg) {
        s.m(arg);
    }

    public static void main(String[] args) {
        SAM<String> s = MethodReference19<String>::new;
        s.m("");
        test(MethodReference19<String>::new, "");
        assertTrue(assertionCount == 2);
    }
}

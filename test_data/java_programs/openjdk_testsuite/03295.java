


public class MethodReference66 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        void m(int i);
    }

    interface I {
        static void f(int i) { assertTrue(i == 42); }
    }
    public static void main(String[] args) {
        SAM s = I::f;
        s.m(42);
        assertTrue(assertionCount == 1);
    }
}

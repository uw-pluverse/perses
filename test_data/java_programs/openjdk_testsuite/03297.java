


public class LambdaCapture06 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        void m(int n);
    }

    public static void main(String[] args) {
        int n = 5;
        SAM s = k -> {
            new Object() {
                void test() { int j = n; assertTrue(j == 5); }
            }.test();
        };
        s.m(42);
        assertTrue(assertionCount == 1);
    }
}



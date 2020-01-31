



public class MethodReference27 {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    interface SAM {
        void m(int i1, int i2);
    }

    static void m1(int i1, int i2) { assertTrue(true); }
    static void m1(Integer i1, int i2) { assertTrue(false); }
    static void m1(int i1, Integer i2) { assertTrue(false); }
    static void m1(Integer i1, Integer i2) { assertTrue(false); }
    static void m1(Integer... is) { assertTrue(false); }

    static void m2(int... is) { assertTrue(true); }
    static void m2(double... ds) { assertTrue(false); }

    public static void main(String[] args) {
        SAM s1 = MethodReference27::m1;
        s1.m(42,42);
        SAM s2 = MethodReference27::m2;
        s2.m(42,42);
        assertTrue(assertionCount == 2);
    }
}

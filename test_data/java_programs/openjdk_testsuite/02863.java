



public class MethodReference03 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
       void m(Integer i);
    }

    static void m(Number i) {}
    static void m(Integer d) { assertTrue(true); }

    public static void main(String[] args) {
        SAM s = MethodReference03::m;
        s.m(1);
        assertTrue(assertionCount == 1);
    }
}

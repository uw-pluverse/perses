



public class MethodReference14 {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    interface SAM {
        void m();
    }

    static void m() { assertTrue(true); }

    public static void main(String[] args) {
        SAM s = (SAM)MethodReference14::m;
        s.m();
        assertTrue(assertionCount == 1);
    }
}

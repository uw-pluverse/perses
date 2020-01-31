



public class MethodReference24 {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    static void m(int i) { assertTrue(true); }
    static void m(Integer i) { assertTrue(false); }

    interface SAM {
        void m(int x);
    }

    static void call(SAM s) { s.m(42); }

    public static void main(String[] args) {
        SAM s = MethodReference24::m; 
        s.m(42);
        call(MethodReference24::m); 
        assertTrue(assertionCount == 2);
    }
}

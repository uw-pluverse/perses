



public class MethodReference05 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
       void m(MethodReference05 receiver, Integer i);
    }

    void m(Integer i) { assertTrue(this != null); }

    public static void main(String[] args) {
        SAM s = MethodReference05::m;
        s.m(new MethodReference05(), 1);
        assertTrue(assertionCount == 1);
    }
}

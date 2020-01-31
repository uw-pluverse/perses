



public class MethodReference16 {

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    static int assertionCount = 0;

    interface SAM {
        void m(MethodReference16 receiver);
    }

    void m() { assertTrue(true); }

    void test() {
        SAM s = (SAM)MethodReference16::m;
        s.m(this);
    }

    public static void main(String[] args) {
        MethodReference16 rec = new MethodReference16();
        SAM s = (SAM)MethodReference16::m;
        s.m(rec);
        rec.test();
        assertTrue(assertionCount == 2);
    }
}

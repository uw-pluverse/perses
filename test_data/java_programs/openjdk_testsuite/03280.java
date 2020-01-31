


public class LambdaCapture07 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        void m();
    }

    void test(int i) {
        class Local { Local() { assertTrue(i == 42); } }
        class LocalSub extends Local { }
        SAM s_sup = ()->new Local();
        s_sup.m();
        SAM s_sub = ()->new LocalSub();
        s_sub.m();
        SAM s_sup_nested = ()->{ SAM s = ()->new Local(); s.m(); };
        s_sup_nested.m();
        SAM s_sub_nested = ()->{ SAM s = ()->new LocalSub(); s.m(); };
        s_sub_nested.m();
    }

    public static void main(String[] args) {
        new LambdaCapture07().test(42);
        assertTrue(assertionCount == 4);
    }
}

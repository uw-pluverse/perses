


public class LambdaExpr11 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    class Inner {
        Inner() { assertTrue(true); }
    }

    void test() {
        Runnable r1 = ()-> { new Inner(); };
        r1.run();
        Runnable r2 = ()-> { new Inner() {}; };
        r2.run();
        Runnable r3 = ()-> { class SubInner extends Inner {}; new SubInner(); };
        r3.run();
        Runnable r4 = ()-> { class SubInner extends Inner {}; new SubInner() {}; };
        r4.run();
        new Inner2().test();
    }

    class Inner2 {
        void test() {
            Runnable r1 = ()-> { new Inner(); };
            r1.run();
            Runnable r2 = ()-> { new Inner() {}; };
            r2.run();
            Runnable r3 = ()-> { class SubInner extends Inner {}; new SubInner(); };
            r3.run();
            Runnable r4 = ()-> { class SubInner extends Inner {}; new SubInner() {}; };
            r4.run();
            new Inner3().test();
        }

        class Inner3 {
            void test() {
                Runnable r1 = ()-> { new Inner(); };
                r1.run();
                Runnable r2 = ()-> { new Inner() {}; };
                r2.run();
                Runnable r3 = ()-> { class SubInner extends Inner {}; new SubInner(); };
                r3.run();
                Runnable r4 = ()-> { class SubInner extends Inner {}; new SubInner() {}; };
                r4.run();
            }
        }
    }

    public static void main(String[] args) {
        new LambdaExpr11().test();
        assertTrue(assertionCount == 12);
    }
}


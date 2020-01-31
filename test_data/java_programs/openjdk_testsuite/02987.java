



public class LambdaCapture02 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface Tester {
        void test();
    }

    interface TU<T, U> {
        public T foo(U u);
    }

    public static <T, U> T exec(TU<T, U> lambda, U x) {
        return lambda.foo(x);
    }

    public Integer n = 5;

    
    void test1() {
        final Integer N = 1;
        int res = LambdaCapture02.<Integer,Integer>exec((Integer x) -> x + N, 3);
        assertTrue(4 == res);
    }

    
    void test2() {
        final Integer N = 1;
        new Tester() {
            public void test() {
                final Integer M = 2;
                int res = LambdaCapture02.<Integer,Integer>exec((Integer x) -> x + N + M, 3);
                assertTrue(6 == res);
            }
        }.test();
    }

    
    void test3() {
        final Integer N = 1;
        class MyTester implements Tester {
            public void test() {
                final Integer M = 2;
                int res = LambdaCapture02.<Integer,Integer>exec((Integer x) -> x + N + M, 3);
                assertTrue(6 == res);
            }
        }
        new MyTester().test();
    }

    
    void test4() {
        final Integer N = 4;
        int res1 = LambdaCapture02.<Integer,Integer>exec((Integer x) -> x + n + N, 3);
        assertTrue(12 == res1);
        int res2 = LambdaCapture02.<Integer,Integer>exec((Integer x) -> x + LambdaCapture02.this.n + N, 3);
        assertTrue(12 == res2);
    }

    public static void main(String[] args) {
        LambdaCapture02 t = new LambdaCapture02();
        t.test1();
        t.test2();
        t.test3();
        t.test4();
        assertTrue(assertionCount == 5);
    }
}

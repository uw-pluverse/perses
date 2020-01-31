



public class LambdaCapture05 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface TU<T, U> {
        public T foo(U u);
    }

    public static <T, U> T exec(TU<T, U> lambda, U x) {
        return lambda.foo(x);
    }

    int i = 40;

    void test1(final int a0) {
        exec((final Integer a1) -> {
            final Integer x2 = 10; exec((final Integer a2) -> {
                final Integer x3 = 20;
                exec((final Integer a3) -> { assertTrue(106 == (a0 + a1 + a2 + a3 + x2 + x3 + i)); return null; }, 3);
                return null;
            },2);
            return null;
        },1);
    }

    static void test2(final int a0) {
        exec((final Integer a1) -> {
            final Integer x2 = 10; exec((final Integer a2) -> {
                final Integer x3 = 20;
                exec((final Integer a3) -> { assertTrue(66 == (a0 + a1 + a2 + a3 + x2 + x3)); return null; }, 3);
                return null;
            }, 2);
            return null;
        }, 1);
    }

    public static void main(String[] args) {
        LambdaCapture05 t = new LambdaCapture05();
        t.test1(30);
        test2(30);
        assertTrue(assertionCount == 2);
    }
}





public class LambdaCapture03 {

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

    Integer n1 = 10;

    void test1() {
        final Integer N1 = 1;
        class A {
            Integer n2 = 20;
            void test() {
                  final Integer N2 = 2;
                  class B {
                       void test() {
                           final Integer N3 = 3;
                           int res = LambdaCapture03.exec((Integer x) -> x + n1 + n2 + N1 + N2 + N3, 30);
                           assertTrue(res == 66);
                       }
                  }
                  new B().test();
            }
        }
        new A().test();
    }

    void test2() {
        final Integer N1 = 1;
        new Tester() {
            Integer n2 = 20;
            public void test() {
                final Integer N2 = 2;
                new Tester() {
                    public void test() {
                        final Integer N3 = 3;
                        int res = LambdaCapture03.exec((Integer x) -> x + n1 + n2 + N1 + N2 + N3, 30);
                        assertTrue(res == 66);
                    }
                }.test();
            }
        }.test();
    }

    public static void main(String[] args) {
        LambdaCapture03 t = new LambdaCapture03();
        t.test1();
        t.test2();
        assertTrue(assertionCount == 2);
    }
}
